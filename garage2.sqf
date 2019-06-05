private ["_vehInGarage","_chequeo"];

pool = !(_this select 0);
if (pool and (not([player] call A3A_fnc_isMember))) exitWith {hint "你不能以游客身份访问车库"};
if (player != player getVariable "owner") exitWith {hint "你不能在控制AI的同时访问车库"};

if ([player,300] call A3A_fnc_enemyNearCheck) exitWith {Hint "当敌人在附近时你无法打开车库"};
vehInGarageShow = [];
_hayAire = false;
_aeropuertos = aeropuertos select {(lados getVariable [_x,sideUnknown] == buenos) and (player inArea _x)};
if (count _aeropuertos > 0) then {_hayAire = true};
{
if ((_x in vehPlanes)) then
	{
	if (_hayAire) then {vehInGarageShow pushBack _x};
	}
else
	{
	vehInGarageShow pushBack _x;
	};
} forEach (if (pool) then {vehInGarage} else {personalGarage});
if (count vehInGarageShow == 0) exitWith {hintC "车库是空的，或你拥有的载具不适合在此处放置.\n\n空中载具需要在机场旗杆处取出."};
_cercano = [marcadores select {lados getVariable [_x,sideUnknown] == buenos},player] call BIS_fnc_nearestPosition;
if !(player inArea _cercano) exitWith {hint "你需要靠近你的驻军点才能从车库中取出车辆."};
cuentaGarage = 0;
_tipo = vehInGarageShow select cuentaGarage;
garageVeh = _tipo createVehicleLocal [0,0,1000];
garageVeh allowDamage false;
garageVeh enableSimulationGlobal false;
comprado = 0;
[format ["<t size='0.7'>%1<br/><br/><t size='0.6'>车库控制键.<t size='0.5'><br/>使用 上下光标键 浏览车辆<br/>使用 左右光标键 旋转车辆<br/>使用 空格键 放置车辆<br/>使用 回车键 退出",getText (configFile >> "CfgVehicles" >> typeOf garageVeh >> "displayName")],0,0,5,0,0,4] spawn bis_fnc_dynamicText;
hint "移动你的鼠标到你想要取出车辆的理想位置. 如果位置合适，车辆将显示出来.";
garageKeys = (findDisplay 46) displayAddEventHandler ["KeyDown",
		{
		_handled = false;
		_salir = false;
		_cambio = false;
		_comprado = false;
		if (_this select 1 == 57) then
			{
			_salir = true;
			_comprado = true;
			};
		if (_this select 1 == 28) then
			{
			_salir = true;
			deleteVehicle garageVeh;
			};
		if (_this select 1 == 200) then
			{
			if (cuentaGarage + 1 > (count vehInGarageShow) - 1) then {cuentaGarage = 0} else {cuentaGarage = cuentaGarage + 1};
			_cambio = true;
			_handled = true;
			//["",0,0,0.34,0,0,4] spawn bis_fnc_dynamicText;
			};
		if (_this select 1 == 208) then
			{
			if (cuentaGarage - 1 < 0) then {cuentaGarage = (count vehInGarageShow) - 1} else {cuentaGarage = cuentaGarage - 1};
			_cambio = true;
			_handled = true;
			//["",0,0,0.34,0,0,4] spawn bis_fnc_dynamicText;
			};
		if (_this select 1 == 205) then
			{
			garageVeh setDir (getDir garageVeh + 1);
			_handled = true;
			};
		if (_this select 1 == 203) then
			{
			garageVeh setDir (getDir garageVeh - 1);
			_handled = true;
			};
		if (_cambio) then
			{
			deleteVehicle garageVeh;
			_tipo = vehInGarageShow select cuentaGarage;
			if (isNil "_tipo") then {_salir = true};
			if (typeName _tipo != typeName "") then {_salir = true};
			if (!_salir) then
				{
				garageVeh = _tipo createVehicleLocal [0,0,1000];
				garageVeh allowDamage false;
				garageVeh enableSimulationGlobal false;
				[format ["<t size='0.7'>%1<br/><br/><t size='0.6'>车库控制键.<t size='0.5'><br/>使用 上下光标键 浏览车辆<br/>使用 左右光标键 旋转车辆<br/>使用 空格键 放置车辆<br/>使用 回车键 退出",getText (configFile >> "CfgVehicles" >> typeOf garageVeh >> "displayName")],0,0,5,0,0,4] spawn bis_fnc_dynamicText;
				};
			};
		if (_salir) then
			{
			if (!_comprado) then
				{
				["",0,0,5,0,0,4] spawn bis_fnc_dynamicText;
				comprado = 1;
				}
			else
				{
				if (garageVeh distance [0,0,1000] <= 1500) then
					{
					["<t size='0.6'>当前放置位置不适合你的车辆，请尝试其他位置.",0,0,3,0,0,4] spawn bis_fnc_dynamicText;
					}
				else
					{
					comprado = 2;
					["<t size='0.6'>车辆已从车库中取出.",0,0,3,0,0,4] spawn bis_fnc_dynamicText;
					};
				};
			};
		_handled;
		}];
posicionSel = [0,0,0];
onEachFrame
 {
 if !(isNull garageVeh) then
  {
  _ins = lineIntersectsSurfaces [
    AGLToASL positionCameraToWorld [0,0,0],
    AGLToASL positionCameraToWorld [0,0,1000],
    player,garageVeh
   ];
   if (_ins isEqualTo []) exitWith {};
   _pos = (_ins select 0 select 0);
   if (_pos distance posicionSel < 0.1) exitWith {};
   posicionSel = _pos;
   _barco = false;
   if (garageVeh isKindOf "Ship") then {_pos set [2,0]; _barco = true};
   if (count (_pos findEmptyPosition [0, 0, typeOf garageVeh])== 0) exitWith {garageVeh setPosASL [0,0,0]};
   if (_pos distance2d player > 100)exitWith {garageVeh setPosASL [0,0,0]};
   _agua = surfaceIsWater _pos;
   if (_barco and {!_agua}) exitWith {garageVeh setPosASL [0,0,0]};
   if (!_barco and {_agua}) exitWith {garageVeh setPosASL [0,0,0]};
   garageVeh setPosASL _pos;
   garageVeh setVectorUp (_ins select 0 select 1);
   };
 };
waitUntil {(comprado > 0) or !(player inArea _cercano)};
onEachFrame {};
(findDisplay 46) displayRemoveEventHandler ["KeyDown", garageKeys];
posicionSel = nil;
_pos = getPosASL garageVeh;
_dir = getDir garageVeh;
_tipo = typeOf garageVeh;
deleteVehicle garageVeh;
if !(player inArea _cercano) then {hint "你需要靠近你的驻军点才能从车库中取出车辆";["",0,0,5,0,0,4] spawn bis_fnc_dynamicText; comprado = nil; garageVeh = nil; cuentaGarage = nil};
if ([player,300] call A3A_fnc_enemyNearCheck) then
	{
	hint "你不能在周围有敌人的情况下使用车库.";
	comprado = 0;
	};
if (comprado != 2) exitWith {comprado = nil; garageVeh = nil; cuentaGarage = nil};
comprado = nil;
//if (player distance2D _pos > 100) exitWith {hint "You have to select a closer position from you"};
waitUntil {isNull garageVeh};
garageVeh = nil;
_garageVeh = createVehicle [_tipo, [0,0,1000], [], 0, "NONE"];
_garageVeh setDir _dir;
_garageVeh setPosASL _pos;
[_garageVeh] call A3A_fnc_AIVEHinit;
if (_garageVeh isKindOf "Car") then {_garageVeh setPlateNumber format ["%1",name player]};
//_pool = false;
//if (vehInGarageShow isEqualTo vehInGarage) then {_pool = true};
_newArr = [];
_found = false;
if (pool) then
	{
	{
	if ((_x != (vehInGarageShow select cuentaGarage)) or (_found)) then {_newArr pushBack _x} else {_found = true};
	} forEach vehInGarage;
	vehInGarage = _newArr;
	publicVariable "vehInGarage";
	}
else
	{
	{
	if ((_x != (vehInGarageShow select cuentaGarage)) or (_found)) then {_newArr pushBack _x} else {_found = true};
	} forEach personalGarage;
	personalGarage = _newArr;
	["personalGarage",_newArr] call fn_SaveStat;
	_garageVeh setVariable ["duenyo",getPlayerUID player,true];
	};
cuentaGarage = nil;
if (_garageVeh isKindOf "StaticWeapon") then {staticsToSave pushBack _garageVeh; publicVariable "staticsToSave"};
clearMagazineCargoGlobal _garageVeh;
clearWeaponCargoGlobal _garageVeh;
clearItemCargoGlobal _garageVeh;
clearBackpackCargoGlobal _garageVeh;
_garageVeh allowDamage true;
_garageVeh enableSimulationGlobal true;
