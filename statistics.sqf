if (!hasInterface) exitWith {};
private ["_texto","_display","_setText"];
//sleep 3;
disableSerialization;
//waitUntil {!isNull (uiNameSpace getVariable "H8erHUD")};
if (isNull (uiNameSpace getVariable "H8erHUD")) exitWith {};
_display = uiNameSpace getVariable "H8erHUD";
if (isNil "_display") exitWith {};
waitUntil {sleep 0.5;!(isNil "theBoss")};
_setText = _display displayCtrl 1001;
_setText ctrlSetBackgroundColor [0,0,0,0];
_nombreC = "None";
if (!isMultiplayer) then
	{
	_texto = format ["<t size='0.60'>" + "军衔: %1 | %9 资金: %2 € | 空袭: %5 | %7 侵略性: %3 | %8 侵略性: %4 | 战争等级: %6 | 伪装模式: %10", server getVariable "hr", server getVariable "resourcesFIA",floor prestigeNATO,floor prestigeCSAT,floor bombRuns,tierWar,nameMalos,nameMuyMalos,nameBuenos,["Off", "<t color='#1DA81D'>On</t>"] select ((captive player) and !(player getVariable ["INCAPACITATED",false]))];
	}
else
	{
	if (player != theBoss) then
		{
		if (isPlayer theBoss) then {_nombreC = name theBoss} else {_nombreC = "None"};
		_texto = format ["<t size='0.560'>" + "指挥官: %3 | 军衔: %2 | 人力: %1 | 个人账户: %4 € | %8 侵略性: %5 | %9 侵略性: %6 | 战争等级: %7 | 伪装模式: %10", server getVariable "hr", rank player, _nombreC, player getVariable "dinero",floor prestigeNATO, floor prestigeCSAT,tierWar,nameMalos,nameMuyMalos,["Off", "<t color='#1DA81D'>On</t>"] select ((captive player) and !(player getVariable ["INCAPACITATED",false]))];
		}
	else
		{
		if ([(player getVariable ["owner",player])] call A3A_fnc_isMember) then
			{
			_texto = format ["<t size='0.60'>" + "军衔: %5 | 人力: %1 | 个人账户: %6 € | %11 账户: %2 € | 空袭点数: %7 | %9 侵略性: %3 | %10 侵略性: %4 | 战争等级: %8 | 伪装模式: %12", server getVariable "hr", server getVariable "resourcesFIA", floor prestigeNATO, floor prestigeCSAT,rank player, player getVariable "dinero",floor bombRuns,tierWar,nameMalos,nameMuyMalos,nameBuenos,["Off", "<t color='#1DA81D'>On</t>"] select ((captive player) and !(player getVariable ["INCAPACITATED",false]))];
			}
		else
			{
			_texto = format ["<t size='0.60'>" + "军衔: %1 | 个人账户: %2 € | %3 账户: %4 € | %5 侵略性: %6 | %7 侵略性: %8 | 战争等级: %9 | 伪装模式: %10",rank player,player getVariable "dinero",nameBuenos,server getVariable "resourcesFIA", nameMalos, floor prestigeNATO, nameMuyMalos,floor prestigeCSAT,tierWar,["Off", "<t color='#1DA81D'>On</t>"] select ((captive player) and !(player getVariable ["INCAPACITATED",false]))];
			};
		};
	};

//if (captive player) then {_texto = format ["%1 ON",_texto]} else {_texto = format ["%1 OFF",_texto]};
_setText ctrlSetStructuredText (parseText format ["%1", _texto]);
_setText ctrlCommit 0;