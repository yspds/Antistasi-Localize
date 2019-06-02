_jugador = player getVariable ["owner",player];

if (_jugador getVariable ["elegible",true]) then
	{
	_jugador setVariable ["elegible",false,true];
	if (_jugador == theBoss) then
		{
		hint "你辞退了指挥官. 其他人将接替指挥，如果有其他的候选人.";
		sleep 3;
		[] remoteExec ["A3A_fnc_assigntheBoss",2];
		}
	else
		{
		hint "你决定不再成为指挥官候选人.";
		};
	}
else
	{
	hint "你现在已是指挥官候选人.";
	_jugador setVariable ["elegible",true,true];
	};