if !(membershipEnabled) exitWith {hint "服务器会员功能已关闭"};
private ["_cuenta"];
_texto = "当前游戏中会员数量\n\n";
_cuentaN = 0;

{
_jugador = _x getVariable ["owner",objNull];
if (!isNull _jugador) then
	{
	//_uid = getPlayerUID _jugador;
	if ([_jugador] call A3A_fnc_isMember) then {_texto = format ["%1%2\n",_texto,name _jugador]} else {_cuentaN = _cuentaN + 1};
	};
} forEach playableUnits;

_texto = format ["%1\n非会员数量:\n%2",_texto,_cuentaN];

hint format ["%1",_texto];