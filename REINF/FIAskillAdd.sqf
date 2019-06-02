if (player != theBoss) exitWith {hint "只有指挥官才能使用此功能"};

if (skillFIA > 19) exitWith {hint "你的军队已经达到最高级别"};
if ((skillFIA + 1) > (tierWar*2)) exitWith {hint "在当前的战争等级下无法继续升级"};
_resourcesFIA = server getVariable "resourcesFIA";
_coste = 1000 + (1.5*(skillFIA *750));
if (_resourcesFIA < _coste) exitWith {hint format ["你没有足够的几千年提供升级. %1 € needed",_coste]};

_resourcesFIA = _resourcesFIA - _coste;
skillFIA = skillFIA + 1;
hint format ["%2 等级已提升\当前等级 %1",skillFIA,nameBuenos];
publicVariable "skillFIA";
server setVariable ["resourcesFIA",_resourcesFIA,true];
[] spawn A3A_fnc_statistics;
{
_coste = server getVariable _x;
_coste = round (_coste + (_coste * (skillFIA/280)));
server setVariable [_x,_coste,true];
} forEach soldadosSDK;
