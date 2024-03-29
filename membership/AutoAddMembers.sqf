/**
	File name: AutoAddMembers.sqf
	Author: [GADD]Monkeynutz
	Description: Script to auto-add members to the members list.
	
	If you need help, contact me on discord at http://discord.gamingatdeathsdoor.com
**/

#include "GADDMembersList.sqf"

private ["_uid", "_GADDMembersList", "_logs", "_isGADDMember", "_areTheyMember"];

_logs = "Members List: Auto Adding Members if needed.";
_isGADDMember = "No";
_areTheyMember = "No";
_uid = getPlayerUID player;

diag_log _logs;

uiSleep 20;

waitUntil{!isNull findDisplay 46 && getPlayerUID player != ''};  

if !(membershipEnabled) exitWith {hint "服务器会员功能已关闭"};

if ((getPlayerUID player) in _GADDMembersList) then
{
	if  ((getPlayerUID player) in miembros) then
	{
		hint "欢迎回来，亲爱的会员...";
		_areTheyMember = "Yes";
	} else {
		miembros pushBackUnique _uid;
		hint "Welcome Player... You have been automatically added to the Members List because the admin added you to a secret list!";
		_areTheyMember = "No, but they have been added to the Members List.";
	};
	_isGADDMember = "Yes";
}else
{
	if  ((getPlayerUID player) in miembros) then
	{
		hint "Welcome Player, you are still a Member.";
		_areTheyMember = "Yes";
	} else {
		hint "欢迎游客, 如果想成为此服务器的会员并使用会员的所有功能，你需要提出申请.";
	};
};

diag_log format ["AutoAddMembers list Complete for: %1 (%2) GADD Member? %3. Are they in the Members List? %4.", name player, _uid, _isGADDMember, _areTheyMember];

publicVariable "miembros";
