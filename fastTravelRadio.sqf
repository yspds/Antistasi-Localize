private ["_roads","_pos","_posicion","_grupo"];

_marcadores = marcadores + [respawnBuenos];

_esHC = false;

if (count hcSelected player > 1) exitWith {hint "You can select one group only to Fast Travel"};
if (count hcSelected player == 1) then {_grupo = hcSelected player select 0; _esHC = true} else {_grupo = group player};
_checkForPlayer = false;
if ((!_esHC) and limitedFT) then {_checkForPlayer = true};
_jefe = leader _grupo;

if ((_jefe != player) and (!_esHC)) then {_grupo = player};

if (({isPlayer _x} count units _grupo > 1) and (_esHC)) exitWith {hint "You cannot Fast Travel groups commanded by players"};

if (player != player getVariable ["owner",player]) exitWith {hint "You cannot Fast Travel while you are controlling AI"};

_chequeo = false;
//_distancia = 500 - (([_jefe,false] call A3A_fnc_fogCheck) * 450);
_distancia = 500;

{if ([_x,_distancia] call A3A_fnc_enemyNearCheck) exitWith {_chequeo = true}} forEach units _grupo;

if (_chequeo) exitWith {Hint "你无法快速旅行，当你的小队附近有敌人时"};

{if ((vehicle _x!= _x) and ((isNull (driver vehicle _x)) or (!canMove vehicle _x) or (vehicle _x isKindOf "Boat"))) then
	{
	if (not(vehicle _x isKindOf "StaticWeapon")) then {_chequeo = true};
	}
} forEach units _grupo;

if (_chequeo) exitWith {Hint "你无法快速旅行，当你不在驾驶位，或你的车辆有损伤，或你在船上时"};

posicionTel = [];

if (_esHC) then {hcShowBar false};
hint "点击你想去的地方";
if (!visibleMap) then {openMap true};
onMapSingleClick "posicionTel = _pos;";

waitUntil {sleep 1; (count posicionTel > 0) or (not visiblemap)};
onMapSingleClick "";

_posicionTel = posicionTel;

if (count _posicionTel > 0) then
	{
	_base = [_marcadores, _posicionTel] call BIS_Fnc_nearestPosition;
	if (_checkForPlayer and ((_base != "SYND_HQ") and !(_base in aeropuertos))) exitWith {hint "玩家小队只允许快速旅行至HQ和机场"};
	if ((lados getVariable [_base,sideUnknown] == malos) or (lados getVariable [_base,sideUnknown] == muyMalos)) exitWith {hint "你不能在敌占区快速旅行"; openMap [false,false]};

	//if (_base in puestosFIA) exitWith {hint "You cannot Fast Travel to roadblocks and watchposts"; openMap [false,false]};

	if ([getMarkerPos _base,500] call A3A_fnc_enemyNearCheck) exitWith {Hint "你无法快速旅行至被攻击的区域或附近有敌人的区域"; openMap [false,false]};

	if (_posicionTel distance getMarkerPos _base < 50) then
		{
		_posicion = [getMarkerPos _base, 10, random 360] call BIS_Fnc_relPos;
		_distancia = round (((position _jefe) distance _posicion)/200);
		//if (!_esHC) then {disableUserInput true; cutText ["Fast traveling, please wait","BLACK",2]; sleep 2;} else {hcShowBar false;hcShowBar true;hint format ["Moving group %1 to destination",groupID _grupo]; sleep _distancia;};
		_forzado = false;
		if (!isMultiplayer) then {if (not(_base in forcedSpawn)) then {_forzado = true; forcedSpawn = forcedSpawn + [_base]}};
		if (!_esHC) then {disableUserInput true; cutText [format ["Fast traveling, travel time: %1s , please wait", _distancia],"BLACK",1]; sleep 1;} else {hcShowBar false;hcShowBar true;hint format ["Moving group %1 to destination",groupID _grupo]; sleep _distancia;};
 		if (!_esHC) then
 			{
 			_timePassed = 0;
 			while {_timePassed < _distancia} do
 				{
 				cutText [format ["Fast traveling, travel time: %1s , please wait", (_distancia - _timePassed)],"BLACK",0.0001];
 				sleep 1;
 				_timePassed = _timePassed + 1;
 				}
 			};
		_exit = false;
		if (limitedFT) then
			{
			_vehicles = [];
			{if (vehicle _x != _x) then {_vehicles pushBackUnique (vehicle _x)}} forEach units _grupo;
			{if ((vehicle _x) in _vehicles) exitWith {_checkForPlayer = true}} forEach playableUnits;
			};
		if (_checkForPlayer and ((_base != "SYND_HQ") and !(_base in aeropuertos))) exitWith {hint format ["%1 快速旅行被取消，因为某些玩家离开了车辆或者目的不是HQ或机场",groupID _grupo]};
		{
		_unit = _x;
		if ((!isPlayer _unit) or (_unit == player)) then
			{
			//_unit hideObject true;
			_unit allowDamage false;
			if (_unit != vehicle _unit) then
				{
				if (driver vehicle _unit == _unit) then
					{
					sleep 3;
					_tam = 10;
					while {true} do
						{
						_roads = _posicion nearRoads _tam;
						if (count _roads > 0) exitWith {};
						_tam = _tam + 10;
						};
					_road = _roads select 0;
					_pos = position _road findEmptyPosition [10,100,typeOf (vehicle _unit)];
					vehicle _unit setPos _pos;
					};
				if ((vehicle _unit isKindOf "StaticWeapon") and (!isPlayer (leader _unit))) then
					{
					_pos = _posicion findEmptyPosition [10,100,typeOf (vehicle _unit)];
					vehicle _unit setPosATL _pos;
					};
				}
			else
				{
				if (!(_unit getVariable ["INCAPACITATED",false])) then
					{
					_posicion = _posicion findEmptyPosition [1,50,typeOf _unit];
					_unit setPosATL _posicion;
					if (isPlayer leader _unit) then {_unit setVariable ["rearming",false]};
					_unit doWatch objNull;
					_unit doFollow leader _unit;
					}
				else
					{
					_posicion = _posicion findEmptyPosition [1,50,typeOf _unit];
					_unit setPosATL _posicion;
					};
				};
			};
			//_unit hideObject false;
		} forEach units _grupo;
		//if (!_esHC) then {sleep _distancia};
		if (!_esHC) then {disableUserInput false;cutText ["你已经到达目的地","BLACK IN",1]} else {hint format ["班组 %1 已到达目的地",groupID _grupo]};
		if (_forzado) then {forcedSpawn = forcedSpawn - [_base]};
		sleep 5;
		{_x allowDamage true} forEach units _grupo;
		}
	else
		{
		Hint "你必须点击友军占领区域";
		};
	};
openMap false;