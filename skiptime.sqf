if (player!= theBoss) exitWith {hint "只有指挥官才能命令休息"};
_presente = false;

{
if ((side _x == malos) or (side _x == muyMalos)) then
	{
	if ([500,1,_x,buenos] call A3A_fnc_distanceUnits) then {_presente = true};
	};
} forEach allUnits;
if (_presente) exitWith {hint "当敌人在我们附近时不能使用休息"};
if (["AtaqueAAF"] call BIS_fnc_taskExists) exitWith {hint "当敌人正在反击时不能使用休息"};
if (["DEF_HQ"] call BIS_fnc_taskExists) exitWith {hint "当HQ被攻击时不能使用休息"};

_chequeo = false;
_posHQ = getMarkerPos respawnBuenos;
{
if ((_x distance _posHQ > 100) and (side _x == buenos)) then {_chequeo = true};
} forEach (allPlayers - (entities "HeadlessClient_F"));

if (_chequeo) exitWith {hint "所有玩家必须在HQ 100米范围你才能使用休息"};

[[],"A3A_fnc_resourcecheckSkipTime"] call BIS_fnc_MP;


