if (player != theBoss) exitWith {hint "Only Player Commander has access to this function"};

if (!(serverCommandAvailable "#logout") and (!isServer)) exitWith {hint "只有管理员和服主才能添加会员"};

if !(membershipEnabled) exitWith {hint "服务器会员机制已关闭"};

if (isNil "miembros") exitWith {hint "Membership feature not yet initialised. Please try again later"};

_target = cursortarget;

if (!isPlayer _target) exitWith {hint "你没有指向任何玩家"};
_uid = getPlayerUID _target;
if ((_this select 0 == "add") and ([_target] call A3A_fnc_isMember)) exitWith {hint "该玩家已经是会员"};
if ((_this select 0 == "remove") and  !([_target] call A3A_fnc_isMember)) exitWith {hint "该玩家不是会员"};

if (_this select 0 == "add") then
	{
	miembros pushBackUnique _uid;
	hint format ["%1 已被添加至会员列表",name _target];
	}
else
	{
	miembros = miembros - [_uid];
	hint format ["%1 已被移出会员列表",name _target];
	};
publicVariable "miembros";