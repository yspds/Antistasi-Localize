
_resourcesFIA = server getVariable "resourcesFIA";

if (_resourcesFIA < 5000) exitWith {hint "您没有足够的资金来重建任何资产。 你需要5000€"};

_destroyedCities = destroyedCities - ciudades;

if (!visibleMap) then {openMap true};
posicionTel = [];
hint "选择你想重建的区域.";

onMapSingleClick "posicionTel = _pos;";

waitUntil {sleep 1; (count posicionTel > 0) or (not visiblemap)};
onMapSingleClick "";

if (!visibleMap) exitWith {};

_posicionTel = posicionTel;

_sitio = [marcadores,_posicionTel] call BIS_fnc_nearestPosition;

if (getMarkerPos _sitio distance _posicionTel > 50) exitWith {hint "您必须在地图标记附近单击"};

if ((not(_sitio in _destroyedCities)) and (!(_sitio in puestos))) exitWith {hint "你不能重建那个"};

_salir = false;
_antenaMuerta = [];
_texto = "Outpost没有被毁的无线电塔";
if (_sitio in puestos) then
	{
	_antenasMuertas = antenasMuertas select {_x inArea _sitio};
	if (count _antenasMuertas > 0) then
		{
		if (lados getVariable [_sitio, sideUnknown] != buenos) then
			{
			_salir = true;
			_texto = format ["您不能在不属于 %1 的前哨站中重建无线电塔",nameBuenos];
			}
		else
			{
			_antenaMuerta = _antenasMuertas select 0;
			};
		}
	else
		{
		_salir = true
		};
	};

if (_salir) exitWith {hint format ["%1",_texto]};

if (count _antenaMuerta == 0) then
	{
	_nombre = [_sitio] call A3A_fnc_localizar;

	hint format ["%1 Rebuilt"];

	[0,10,_posicionTel] remoteExec ["A3A_fnc_citySupportChange",2];
	[5,0] remoteExec ["A3A_fnc_prestige",2];
	destroyedCities = destroyedCities - [_sitio];
	publicVariable "destroyedCities";
	}
else
	{
	hint "Radio Tower rebuilt";
	antenasMuertas = antenasMuertas - [_antenaMuerta]; publicVariable "antenasMuertas";
	_antena = nearestBuilding _antenaMuerta;
	if (isMultiplayer) then {[_antena,true] remoteExec ["hideObjectGlobal",2]} else {_antena hideObject true};
	_antena = createVehicle ["Land_Communication_F", _antenaMuerta, [], 0, "NONE"];
	antenas pushBack _antena; publicVariable "antenas";
	{if ([antenas,_x] call BIS_fnc_nearestPosition == _antena) then {[_x,true] spawn A3A_fnc_apagon}} forEach ciudades;
	_mrkfin = createMarker [format ["Ant%1", count antenas], _antenaMuerta];
	_mrkfin setMarkerShape "ICON";
	_mrkfin setMarkerType "loc_Transmitter";
	_mrkfin setMarkerColor "ColorBlack";
	_mrkfin setMarkerText "Radio Tower";
	mrkAntenas pushBack _mrkfin;
	publicVariable "mrkAntenas";
	_antena addEventHandler ["Killed",
		{
		_antena = _this select 0;
		{if ([antenas,_x] call BIS_fnc_nearestPosition == _antena) then {[_x,false] spawn A3A_fnc_apagon}} forEach ciudades;
		_mrk = [mrkAntenas, _antena] call BIS_fnc_nearestPosition;
		antenas = antenas - [_antena]; antenasmuertas = antenasmuertas + [getPos _antena]; deleteMarker _mrk;
		["TaskSucceeded",["", "Radio Tower Destroyed"]] remoteExec ["BIS_fnc_showNotification",buenos];
		["TaskFailed",["", "Radio Tower Destroyed"]] remoteExec ["BIS_fnc_showNotification",malos];
		publicVariable "antenas"; publicVariable "antenasMuertas";
		}
		];
	};
[0,-5000] remoteExec ["A3A_fnc_resourcesFIA",2];