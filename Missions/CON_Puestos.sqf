if (!isServer and hasInterface) exitWith{};

private ["_marcador"];

_marcador = _this select 0;

_dificil = if (random 10 < tierWar) then {true} else {false};
_salir = false;
_contacto = objNull;
_grpContacto = grpNull;
_tsk = "";
_posicion = getMarkerPos _marcador;
_tiempolim = if (_dificil) then {30} else {90};//120
if (hayIFA) then {_tiempolim = _tiempolim * 2};
_fechalim = [date select 0, date select 1, date select 2, date select 3, (date select 4) + _tiempolim];
_fechalimnum = dateToNumber _fechalim;

_nombredest = [_marcador] call A3A_fnc_localizar;
_texto = "";
_taskName = "";
if (_marcador in recursos) then
	{
	_texto = format ["一个 %1 对实现我们的目标来说是个不错的补充. 前去占领该点，在 %2:%3 以前.",_nombredest,numberToDate [2035,_fechalimnum] select 3,numberToDate [2035,_fechalimnum] select 4];
	_taskName = "取得资源点";
	}
else
	{
	_texto = format ["一个 %1 正在干扰我们在此区域的行动. 前去夺取该点，在 %2:%3 以前.",_nombredest,numberToDate [2035,_fechalimnum] select 3,numberToDate [2035,_fechalimnum] select 4];
	_taskName = "夺取前哨站";
	};


[[buenos,civilian],"CON",[_texto,_taskName,_marcador],_posicion,false,0,true,"Target",true] call BIS_fnc_taskCreate;
misiones pushBack ["CON","CREATED"]; publicVariable "misiones";
waitUntil {sleep 1; (dateToNumber date > _fechalimnum) or (lados getVariable [_marcador,sideUnknown] == buenos)};

if (dateToNumber date > _fechalimnum) then
	{
	["CON",[_texto,_taskName,_marcador],_posicion,"FAILED"] call A3A_fnc_taskUpdate;
	if (_dificil) then
		{
		[10,0,_posicion] remoteExec ["A3A_fnc_citySupportChange",2];
		[-1200] remoteExec ["A3A_fnc_timingCA",2];
		[-20,theBoss] call A3A_fnc_playerScoreAdd;
		}
	else
		{
		[5,0,_posicion] remoteExec ["A3A_fnc_citySupportChange",2];
		[-600] remoteExec ["A3A_fnc_timingCA",2];
		[-10,theBoss] call A3A_fnc_playerScoreAdd;
		};
	}
else
	{
	sleep 10;
	["CON",[_texto,_taskName,_marcador],_posicion,"SUCCEEDED"] call A3A_fnc_taskUpdate;
	if (_dificil) then
		{
		[0,400] remoteExec ["A3A_fnc_resourcesFIA",2];
		[-10,0,_posicion] remoteExec ["A3A_fnc_citySupportChange",2];
		[1200] remoteExec ["A3A_fnc_timingCA",2];
		{if (isPlayer _x) then {[20,_x] call A3A_fnc_playerScoreAdd}} forEach ([500,0,_posicion,buenos] call A3A_fnc_distanceUnits);
		[20,theBoss] call A3A_fnc_playerScoreAdd;
		}
	else
		{
		[0,200] remoteExec ["A3A_fnc_resourcesFIA",2];
		[-5,0,_posicion] remoteExec ["A3A_fnc_citySupportChange",2];
		[600] remoteExec ["A3A_fnc_timingCA",2];
		{if (isPlayer _x) then {[10,_x] call A3A_fnc_playerScoreAdd}} forEach ([500,0,_posicion,buenos] call A3A_fnc_distanceUnits);
		[10,theBoss] call A3A_fnc_playerScoreAdd;
		};
	};

_nul = [1200,"CON"] spawn A3A_fnc_borrarTask;