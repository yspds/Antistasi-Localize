private ["_resourcesPlayer","_puntosJ","_target"];
_resourcesPlayer = player getVariable "dinero";
if (_resourcesPlayer < 100) exitWith {hint "你的资金少于100 €不能捐赠"};

if (count _this == 0) exitWith
	{
	[-100] call A3A_fnc_resourcesPlayer;
	[0,100] remoteExec ["A3A_fnc_resourcesFIA",2];
	_puntosJ = (player getVariable "score") + 1;
	player setVariable ["score",_puntosJ,true];
	hint "你捐赠了100 €. 这会提高你在阵营内的声望";
	[] spawn A3A_fnc_statistics;
	["dinero",player getVariable ["dinero",0]] call fn_SaveStat;
	};
_target = cursortarget;

if (!isPlayer _target) exitWith {hint "你必须面对一个玩家才能才能把钱给他"};

[-100] call A3A_fnc_resourcesPlayer;
_money = player getVariable "dinero";
["dinero",_money] call fn_SaveStat;
_dinero = _target getVariable "dinero";
_target setVariable ["dinero",_dinero + 100, true];
hint format ["你捐赠了 100 € 给 %1", name _target];
[] remoteExec ["A3A_fnc_statistics",_target];
[] spawn A3A_fnc_statistics;