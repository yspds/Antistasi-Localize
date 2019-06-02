private ["_pool","_veh","_tipoVeh"];

_veh = cursorTarget;

if (isNull _veh) exitWith {hint "你不在看车辆"};

if (!alive _veh) exitWith {hint "你不能解锁已摧毁的车辆"};

if (_veh isKindOf "Man") exitWith {hint "你在开玩笑呢？"};
if (not(_veh isKindOf "AllVehicles")) exitWith {hint "你看着的车不能被解锁"};
_duenyo = _veh getVariable "duenyo";

if (isNil "_duenyo") exitWith {hint "您正在查看的车辆已经解锁"};

if (_duenyo != getPlayerUID player) exitWith {hint "你无法解锁你不拥有的车辆"};

_veh setVariable ["duenyo",nil,true];

hint "车辆已解锁";
