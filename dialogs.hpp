//Game start
class first_load 		{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "载入最近存档？"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "YES"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Loads the pervious personal session";
			action = "closeDialog 0;nul = [true] execVM ""statSave\loadAccount.sqf"";";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "NO"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Starts a new game";
			//action = "closeDialog 0;if ((player == theBoss) and (isNil ""placementDone"") and !(isMultiplayer)) then {_nul = [] spawn A3A_fnc_placementselection};";
			action = "closeDialog 0;if ((player == theBoss) and (isNil ""placementDone"") and !(isMultiplayer)) then {closeDialog 0;[] execVM ""dialogs\difficultyMenu.sqf""};";
		};
	};
};

//FLAG
class HQ_menu 			{
	idd=100;
	movingenable=false;

	class controls {
		//Structure
		class HQ_box: BOX
		{
			idc = 101;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = 102;
			text = "HQ选项 - 仅指挥官"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = 103;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		//Buttons L and R
		class HQ_button_load: RscButton
		{
			idc = 104; 	//L1
			text = "从阵营中取出100€"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "从阵营账户中取出100到个人账户中。It will damage your position among the faction in the commander career";
			action = "if (isMultiPlayer) then {if (player == theBoss) then {nul=call A3A_fnc_theBossSteal} else {hint ""只有指挥官才能使用此功能""}} else {hint ""This function is MP only""};";
		};
		class HQ_button_savegame: RscButton
		{
			idc = 105; 	//L2
			text = "驻军管理"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "增加或移除驻军单位";
			action = "closeDialog 0;if (player == theBoss) then {nul=CreateDialog ""build_menu""} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_moveHQ: RscButton
		{
			idc = 106;	//L3
			text = "转移HQ到其他区域"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Maru will join your group. Ammobox must be empty. To rebuild, select the Build action near Maru";
			action = "closeDialog 0;if (player == theBoss) then {nul = [] spawn A3A_fnc_moveHQ;} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_recruitUnit: RscButton
		{
			idc = 107;	//R1
			text = "当前会员列表"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Displays which server members are currently playing";
			action = "if (player == theBoss) then {if (isMultiplayer) then {nul = [] call A3A_fnc_membersList} else {hint ""This function is MP only""}} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_recruitSquad: RscButton
		{
			idc = 108;	//R2
			text = "重建资产"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "花费 5000€";
			action = "closeDialog 0;if (player == theBoss) then {nul=[] spawn A3A_fnc_rebuildAssets} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_vehicle: RscButton
		{
			idc = 109;	//R3
			text = "训练友军AI"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "";
			action = "closeDialog 0;if (player == theBoss) then {nul = [] call A3A_fnc_FIAskillAdd} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_skill: RscButton
		{
			idc = 110;	//M4
			text = "打开车库"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "查看阵营车库";
			action = "closeDialog 0;nul = [false] spawn A3A_fnc_garage";
		};
	};
}; 										//slots: 6+1
class build_menu  			{
	idd=-1;
	movingenable=false;

	class controls {
		//Structure
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "建造和驻军选项 Building & Garrison Options"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""HQ_menu"";";
		};
		//Action Buttons
		class 4slots_L1: RscButton
		{
			idc = -1;
			text = "地雷选项"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "AI will deploy or remove mines on desired objectives, using current arsenal mine count";
			action = "closeDialog 0;_nul = createDialog ""minebuild_menu"";";
		};
		class 4slots_R1: RscButton
		{
			idc = -1;
			text = "观察哨 - 检查站"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Establish a new watchpost or roadblock depending on the type of terrain you select";
			action = "closeDialog 0; [""create""] spawn A3A_fnc_puestoDialog";
		};
		class 4slots_L2: RscButton
		{
			idc = -1;
			text = "添加驻军"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Add units to an existing garrison";
			action = "closeDialog 0; [""add""] spawn A3A_fnc_garrisonDialog";
		};
		class 4slots_R2: RscButton
		{
			idc = -1;
			text = "移除驻军"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			//action = "closeDialog 0; [""delete""] spawn A3A_fnc_puestoDialog";
			tooltip = "Remove whole garrisons or posts";
			action = "closeDialog 0; [""rem""] spawn A3A_fnc_garrisonDialog";
		};
	};
}; 										//slots: 4
class garrison_recruit 			{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = 101;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = 102;
			text = "驻军招募选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = 103;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""build_menu"";";
		};
		class HQ_button_rifleman: RscButton
		{
			idc = 104;
			text = "招募民兵"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKMil] spawn A3A_fnc_garrisonAdd";
		};
		class HQ_button_autorifleman: RscButton
		{
			idc = 105;
			text = "招募机枪兵"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKMG] spawn A3A_fnc_garrisonAdd";
		};
		class HQ_button_medic: RscButton
		{
			idc = 126;
			text = "招募医疗兵"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKMedic] spawn A3A_fnc_garrisonAdd";
		};
		class HQ_button_engineer: RscButton
		{
			idc = 107;
			text = "招募班长"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKSL] spawn A3A_fnc_garrisonAdd";
		};
		class HQ_button_explosive: RscButton
		{
			idc = 108;
			text = "招募迫击炮"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [staticCrewBuenos] spawn A3A_fnc_garrisonAdd";
		};
		class HQ_button_grenadier: RscButton
		{
			idc = 109;
			text = "招募榴弹兵"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKGL] spawn A3A_fnc_garrisonAdd";
		};
		class HQ_button_marksman: RscButton
		{
			idc = 110;
			text = "招募精确射手"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKSniper] spawn A3A_fnc_garrisonAdd";
		};

		class HQ_button_AT: RscButton
		{
			idc = 111;
			text = "招募反坦克兵"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKATman] spawn A3A_fnc_garrisonAdd";
		};
	};
};										//slots: 8
class minebuild_menu 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "布置雷区"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""build_menu"";";
		};
		class HQ_button_mortar: RscButton
		{
			idc = -1;
			text = "APERS反步兵雷"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;[""APERSMine""] spawn A3A_fnc_mineDialog";
		};
		class HQ_button_MG: RscButton
		{
			idc = -1;
			text = "排除雷区"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Spawn an AI Engineer which will clear any mine in it's surroundings";
			action = "closeDialog 0; [""delete""] spawn A3A_fnc_mineDialog;";
		};
		class HQ_button_AT: RscButton
		{
			idc = -1;
			text = "AT反坦克雷"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [""ATMine""] spawn A3A_fnc_mineDialog";
		};
	};
};
class unit_recruit 		{
	idd= 100;
	movingenable=false;
	class controls {
		class HQ_box: BOX
		{
			idc = 101;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = 102;
			text = "招募选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = 103;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_rifleman: RscButton
		{
			idc = 104;
			text = "招募民兵"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKMil] spawn A3A_fnc_reinfPlayer";
		};
		class HQ_button_autorifleman: RscButton
		{
			idc = 105;
			text = "招募机枪兵"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKMG] spawn A3A_fnc_reinfPlayer";
		};
		class HQ_button_medic: RscButton
		{
			idc = 126;
			text = "招募医疗兵"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKMedic] spawn A3A_fnc_reinfPlayer";
		};
		class HQ_button_engineer: RscButton
		{
			idc = 107;
			text = "招募工程兵"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKEng] spawn A3A_fnc_reinfPlayer";
		};
		class HQ_button_explosive: RscButton
		{
			idc = 108;
			text = "招募炸药专家"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKExp] spawn A3A_fnc_reinfPlayer";
		};
		class HQ_button_grenadier: RscButton
		{
			idc = 109;
			text = "招募榴弹兵"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKGL] spawn A3A_fnc_reinfPlayer";
		};
		class HQ_button_marksman: RscButton
		{
			idc = 110;
			text = "招募精确射手"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKSniper] spawn A3A_fnc_reinfPlayer";
		};

		class HQ_button_AT: RscButton
		{
			idc = 111;
			text = "招募反坦克兵"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [SDKATman] spawn A3A_fnc_reinfPlayer";
		};
	};
};
class vehicle_option 	{
	idd=-1;
	movingenable=false;

	class controls {

		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "购买车辆"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "民用车辆"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "民用车辆可以让你进入伪装状态，保持道路行驶不会被敌人发现，进入敌军基地，前哨站和检查站除外";
			action = "closeDialog 0;nul=[] execVM ""Dialogs\buy_vehicle_civ.sqf"";";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "军用车辆"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Wide variety of available faction vehicles";
			action = "closeDialog 0; nul=[] execVM ""Dialogs\buy_vehicle.sqf"";";
		};
	};
};
class buy_vehicle 			{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = 101;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = 102;
			text = "购买军用车辆"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = 103;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; nul = createDialog ""vehicle_option"";";
		};
		class HQ_button_quad: RscButton
		{
			idc = 104;
			text = "四轮全地形车"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closedialog 0; nul = [vehSDKBike] spawn A3A_fnc_addFIAveh";
		};
		class HQ_button_offroad: RscButton
		{
			idc = 105;
			text = "皮卡"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [vehSDKLightUnarmed] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_truck: RscButton
		{
			idc = 106;
			text = "卡车"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [vehSDKTruck] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_Aoffroad: RscButton
		{
			idc = 107;
			text = "武装皮卡"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [vehSDKLightArmed] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_MG: RscButton
		{
			idc = 108;
			text = "重机枪"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [SDKMGStatic] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_mortar: RscButton
		{
			idc = 109;
			text = "迫击炮"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [SDKMortar] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_AT: RscButton
		{
			idc = 110;
			text = "固定AT发射器"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [staticATBuenos] spawn A3A_fnc_addFIAveh;";
		};

		class HQ_button_AA: RscButton
		{
			idc = 111;
			text = "固定AA发射器"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [staticAABuenos] spawn A3A_fnc_addFIAveh;";
		};
	};
};
class civ_vehicle 			{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "购买平民车辆"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; nul = createDialog ""vehicle_option"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = 104;
			text = "皮卡"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [civCar] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = 105;
			text = "卡车"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [civTruck] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_Gremove: RscButton
		{
			idc = 106;
			text = "直升机"; //--- ToDo: Localize;
			//x = 0.37749 * safezoneW + safezoneX;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [civHeli] spawn A3A_fnc_addFIAveh;";
		};
		class HQ_button_offroad: RscButton
		{
			idc = 107;
		 	text = "船"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
		 	y = 0.415981 * safezoneH + safezoneY;
		 	w = 0.175015 * safezoneW;
		 	h = 0.0560125 * safezoneH;
		 	action = "closeDialog 0;[civBoat] spawn A3A_fnc_addFIAveh;";
		 };
	};
};

//Map
class game_options 		{
		idd=-1;
	movingenable=false;
	class controls {
		//Menu Structure
		class 8slots_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class 8slots_frame: RscFrame
		{
			idc = -1;
			text = "游戏选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class 8slots_Back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		//Action Buttons
		class 8slots_L1: RscButton
		{
			idc = -1;
			text = "平民数量"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "设置平民最大刷新数量，影响游戏性能";
			action = "if (player == theBoss) then {closeDialog 0; nul = createDialog ""civ_config""} else {hint ""只有指挥官才能使用此功能""};";
		};
		class 8slots_R1: RscButton
		{
			idc = -1;
			text = "刷新距离"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "非常影响心梗，请慎重使用";
			action = "if (player == theBoss) then {closeDialog 0; nul = createDialog ""spawn_config""} else {hint ""只有指挥官才能使用此功能""};";
		};
		class 8slots_L2: RscButton
		{
			idc = -1;
			text = "AI总数量限制"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Sets how much local and simulated AI can spawn in the map. Affects performance and AI ""intelligence"". Use with caution. This is not an exact number as vehicles and squad leaders will allways spawn";
			action = "if (player == theBoss) then {closeDialog 0; nul = createDialog ""fps_limiter""} else {hint ""只有指挥官才能使用此功能""};";
		};
		class 8slots_R2: RscButton
		{
			idc = -1;
			text = "背景音乐开关"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Disables/Enable situational music";
			action = "closedialog 0; if (musicON) then {musicON = false; hint ""Music turned OFF""} else {musicON = true; hint ""Music turned ON""}; nul = execVM ""musica.sqf"";";
		};
		/*
		class 8slots_L3: RscButton
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "";
			action = "";
		};
		class 8slots_R3: RscButton
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "";
			action = "";
		};

		class 8slots_L4: RscButton
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "";
			action = "";
		};
		class 8slots_R4: RscButton
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "";
			action = "";
		};
		*/
		class 8slots_M4: RscButton
		{
			idc = -1;
			text = "进度保存"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "使用此选项保存当前游戏进度，它以GTA的方式保存最重要的数据. This opnion allows good MP save and independent saves of any version update. Vanilla saves are disabled because of lack of several features";
			action = "closeDialog 0;if (player == theBoss) then {[""statSave\saveLoop.sqf"",""BIS_fnc_execVM""] call BIS_fnc_MP} else {_nul = [] execVM ""statSave\saveLoop.sqf""; hintC ""个人进度已保存""};";
		};
	};
};										//slots 6+1
class fps_limiter 			{
	idd=-1;
	movingenable=false;

	class controls {

		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "AI总数量限制"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""game_options"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "+10 AI总数量"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (player == theBoss) then {if (maxUnits < 200) then {maxUnits = maxUnits + 10; publicVariable ""maxUnits""; hint format [""AI Limit has been set at %1"",maxUnits]} else {hint ""AI Limit cannot be raised from 200""}} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "-10 AI总数量"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (player == theBoss) then {if (maxUnits > 80) then {maxUnits = maxUnits - 10; publicVariable ""maxUnits""; hint format [""AI Limit has been set at %1"",maxUnits]} else {hint ""AI Limit cannot be less than 80""}} else {hint ""只有指挥官才能使用此功能""};";
		};
	};
};
class spawn_config 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "刷新距离设置"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""game_options"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "+100m 刷新距离."; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (player == theBoss) then {if (distanciaSPWN < 2000) then {distanciaSPWN = distanciaSPWN + 100; distanciaSPWN1 = distanciaSPwN * 1.3; distanciaSPWN2 = distanciaSPWN /2; publicVariable ""distanciaSPWN"";publicVariable ""distanciaSPWN1"";publicVariable ""distanciaSPWN2""}; hint format [""Spawn Distance Set to %1 meters. Be careful, this may affect game performance"",distanciaSPWN]} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "-100m 刷新距离."; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (player == theBoss) then {if (distanciaSPWN > 600) then {distanciaSPWN = distanciaSPWN - 100; if (distanciaSPWN < 600) then {distanciaSPWN = 600}; distanciaSPWN1 = distanciaSPwN * 1.3; distanciaSPWN2 = distanciaSPWN /2; if (distanciaSPWN < 600) then {distanciaSPWN = 600};publicVariable ""distanciaSPWN"";publicVariable ""distanciaSPWN1"";publicVariable ""distanciaSPWN2"";}; hint format [""Spawn Distance Set to %1 meters"",distanciaSPWN]} else {hint ""只有指挥官才能使用此功能""};";
		};
	};
};
class civ_config 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "平民数量设置"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""game_options"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "+1 最大平民数量"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (player == theBoss) then {if (civPerc < 150) then {civPerc = civPerc + 1; if (civPerc > 150) then {civPerc = 150}; publicVariable ""civPerc"";}; hint format [""Maximum Number of Civilians Set to %1"",civPerc]} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "-1 最大平民数量"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (player == theBoss) then {if (civPerc > 0) then {civPerc = civPerc - 1; if (civPerc < 0) then {civPerc = 0};publicVariable ""civPerc"";}; hint format [""Maximum Number of Civilians Set to %1"",civPerc]} else {hint ""只有指挥官才能使用此功能""};";
		};
	};
};

//Solomon Maru
class mission_menu 		{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "可用任务"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_AS: RscButton
		{
			idc = -1;
			text = "暗杀任务"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;if ((player == theBoss) or (not(isPlayer theBoss))) then {[[""AS""],""A3A_fnc_missionRequest""] call BIS_fnc_MP} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_CONV: RscButton
		{
			idc = -1;
			text = "伏击任务"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;if ((player == theBoss) or (not(isPlayer theBoss))) then {[[""CONVOY""],""A3A_fnc_missionRequest""] call BIS_fnc_MP} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_DES: RscButton
		{
			idc = -1;
			text = "摧毁任务"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;if ((player == theBoss) or (not(isPlayer theBoss))) then {[[""DES""],""A3A_fnc_missionRequest""] call BIS_fnc_MP} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_LOG: RscButton
		{
			idc = -1;
			text = "后勤任务"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;if ((player == theBoss) or (not(isPlayer theBoss))) then {[[""LOG""],""A3A_fnc_missionRequest""] call BIS_fnc_MP} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_RES: RscButton
		{
			idc = -1;
			text = "营救任务"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;if ((player == theBoss) or (not(isPlayer theBoss))) then {[[""RES""],""A3A_fnc_missionRequest""] call BIS_fnc_MP} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_vehicle: RscButton
		{
			idc = -1;
			text = "征服任务"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;if ((player == theBoss) or (not(isPlayer theBoss))) then {[[""CON""],""A3A_fnc_missionRequest""] call BIS_fnc_MP} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_exit: RscButton
		{
			idc = -1;
			text = "EXIT"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;";
		};
	};
};


//Y menu
class radio_comm 		{
	idd=-1;
	movingenable=false;
	class controls {
		//Menu Structure
		class 8slots_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class 8slots_frame: RscFrame
		{
			idc = -1;
			text = "战斗选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class 8slots_Back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		//Action Buttons
		class 8slots_L1: RscButton
		{
			idc = -1;
			text = "快速旅行"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "转送你或你的小队到友军控制区域";
			action = "closeDialog 0;nul = [] execVM ""fastTravelRadio.sqf"";";
		};
		class 8slots_R1: RscButton
		{
			idc = -1;
			text = "玩家与金钱"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "正对着某个玩家进行互动";
			action = "closeDialog 0;if (isMultiPlayer) then {nul = createDialog ""player_money""} else {hint ""MP Only Menu""};";
		};
		class 8slots_L2: RscButton
		{
			idc = -1;
			text = "开启伪装模式"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "成功进入伪装模式后，敌人在识破你之前不会攻击你";
			action = "closeDialog 0;nul = [] spawn A3A_fnc_undercover";
		};
		class 8slots_R2: RscButton
		{
			idc = -1;
			text = "建造工事"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Construct in the spot where you are a selected building facing this direction";
			action = "closeDialog 0;_nul = createDialog ""construction_menu"";";
		};
		class 8slots_L3: RscButton
		{
			idc = -1;
			text = "保存车辆"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "正对着的车辆或固定武器将被保存至个人车库，若要取出，与基地旗杆交互";
			action = "closeDialog 0;if (player != theBoss) then {nul = [false] call A3A_fnc_garageVehicle} else {if (isMultiplayer) then {_nul = createDialog ""garage_check""} else {nul = [true] call A3A_fnc_garageVehicle}};";
		};
		class 8slots_R3: RscButton
		{
			idc = -1;
			text = "解锁车辆"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "允许非同小队玩家进入你的车辆";
			action = "closeDialog 0;[] call A3A_fnc_unlockVehicle";
		};
		class 8slots_L4: RscButton
		{
			idc = -1;
			text = "AI管理"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Several AI options";
			action = "if (player == leader group player) then {closeDialog 0;nul = createDialog ""AI_management""} else {hint ""Only group leaders may access to this option""};";
		};
		class 8slots_R4: RscButton
		{
			idc = -1;
			text = "指挥官"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Open commander options";
			action = "closeDialog 0; nul = createDialog ""commander_comm"";";
		};
	};
}; 										// slots: 8
class vehicle_manager 		{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "车辆管理"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""radio_comm"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "保存\卖出 车辆"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Add to garage / sell the vehicle you are currently looking at";
			action = "closeDialog 0;nul = createDialog ""garage_sell"";";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "车辆和班组"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Options related to vehicle management in HC controlled squads";
			action = "closeDialog 0; if (player == theBoss) then {nul = createDialog ""squad_manager""} else {hint ""只有指挥官才能使用此功能""};";
		};

		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Add to Air Support"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Gain Airstrike points giving this vehicle to the faction Air pool";
			action = "closeDialog 0;nul = [] call A3A_fnc_addBombRun";
		};
		class HQ_button_unlock: RscButton
		{
			idc = -1;
			text = "解锁车辆"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Allow other groups to mount this vehicle";
			action = "closeDialog 0;[] call A3A_fnc_unlockVehicle";
		};
	};
};
class veh_query 				{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = 101;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = 102;
			text = "Add Vehicle to Squad?"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = 103;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;vehQuery = nil; if (player == theBoss) then {nul= [] execVM ""Dialogs\squad_recruit.sqf""} else {hint ""只有指挥官才能使用此功能""};";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = 104;
			text = "YES"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; vehQuery = true";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = 105;
			text = "NO"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; vehQuery = nil";
		};
	};
};
class squad_manager 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "HC Squad Otions"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""radio_comm"";";
		};
		class HQ_button_mortar: RscButton
		{
			idc = -1;
			text = "Squad Add Vehicle"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at some vehicle and assign it to the selected squad for it's use";
			action = "closeDialog 0;[] call A3A_fnc_addSquadVeh;";
		};
		class HQ_button_MG: RscButton
		{
			idc = -1;
			text = "Squad SITREP"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "If the selected squad is using some vehicle, know remotely it's status";
			action = "[""stats""] call A3A_fnc_vehStats;";
		};
		class HQ_button_AT: RscButton
		{
			idc = -1;
			text = "Mount / Dismount"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Force squad to mount or dismount their assigned vehicle";
			action = "[""mount""] call A3A_fnc_vehStats";
		};
		class HQ_button_AA: RscButton
		{
			idc = -1;
			text = "Static Autotarget"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Use this option on AT / AA mounted squads. The truck driver will try to point his truck's back to any detected enemy";
			action = "closeDialog 0; [] spawn A3A_fnc_staticAutoT";
		};
	};
};
class AI_management 		{
	idd=-1;
	movingenable=false;
	class controls {
		//Menu Structure
		class 8slots_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class 8slots_frame: RscFrame
		{
			idc = -1;
			text = "Battle Options"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class 8slots_Back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;
			h = 0.05 * safezoneH;
			action = "closeDialog 0;nul = createDialog ""radio_comm"";";
		};
		//Action Buttons
		class 8slots_L1: RscButton
		{
			idc = -1;
			text = "Temp. AI Control"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Take personal control of the selected squad member or HC squad leader and be able to perform any kind of actions for 60 seconds. Control state will be cancelled if the player or the controlled unit receives any kind of damage";
		action = "closeDialog 0; if ((count groupselectedUnits player > 0) and (count hcSelected player > 0)) exitWith {hint ""You must select from HC or Squad Bars, not both""}; if (count groupselectedUnits player == 1) then {nul = [groupselectedUnits player] execVM ""REINF\controlunit.sqf""}; if (count hcSelected player == 1) then {nul = [hcSelected player] execVM ""REINF\controlHCsquad.sqf"";};";
		};
		class 8slots_R1: RscButton
		{
			idc = -1;
			text = "Auto Rearm \ Loot"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "AI will search for better weapons, vests, helmets etc. If they are in a vehicle, they will just store what they scavenge in the vehicle. If not, they will equip them";
			action = "closeDialog 0; if (count groupselectedUnits player == 0) then {nul = (units group player) spawn A3A_fnc_rearmCall} else {nul = (groupselectedUnits player) spawn A3A_fnc_rearmCall};";
		};
		class 8slots_L2: RscButton
		{
			idc = -1;
			text = "Auto Heal"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "AI squad mates will heal proactively each other";
			action = "if (autoHeal) then {autoHeal = false; hint ""Auto Healing disabled"";} else {autoHeal = true; hint ""Auto Heal enabled""; nul = [] spawn A3A_fnc_autoHealFnc}";
		};
		class 8slots_R2: RscButton
		{
			idc = -1;
			text = "Squad SITREP"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Recover info about a HC squad status";
			action = "[""stats""] call A3A_fnc_vehStats;";
		};
		class 8slots_L3: RscButton
		{
			idc = -1;
			text = "Garrison Units / Squads"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Adds selected units or squads to a map selected garrison";
			action = "closeDialog 0;if (count groupselectedUnits player > 0) then {nul = [groupselectedUnits player] execVM ""REINF\addToGarrison.sqf""} else {if (count (hcSelected player) > 0) then {nul = [hcSelected player] execVM ""REINF\addToGarrison.sqf""}}; if ((count groupselectedUnits player == 0) and (count hcSelected player == 0)) then {hint ""No units or squads selected""}";
		};
		class 8slots_R3: RscButton
		{
			idc = -1;
			text = "Squad Add Vehicle"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at some vehicle and assign it to the selected squad for it's use";
			action = "closeDialog 0;[] call A3A_fnc_addSquadVeh;";
		};
		class 8slots_L4: RscButton
		{
			idc = -1;
			text = "Dismiss Units / Squad"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Dimiss selected units or squads, recovering it's cost to the proper resource pool";
			action = "closeDialog 0;if (count groupselectedUnits player > 0) then {nul = [groupselectedUnits player] execVM ""REINF\dismissPlayerGroup.sqf""} else {if (count (hcSelected player) > 0) then {nul = [hcSelected player] execVM ""REINF\dismissSquad.sqf""}}; if ((count groupselectedUnits player == 0) and (count hcSelected player == 0)) then {hint ""No units or squads selected""}";
		};
		class 8slots_R4: RscButton
		{
			idc = -1;
			text = "Mount / Dismount"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Force squad to mount or dismount their assigned vehicle";
			action = "[""mount""] call A3A_fnc_vehStats";
		};
	};
};
class commander_comm 		{
	idd=-1;
	movingenable=false;
	class controls {
		//Menu Structure
		class 8slots_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class 8slots_frame: RscFrame
		{
			idc = -1;
			text = "指挥官战斗选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class 8slots_Back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;
			h = 0.05 * safezoneH;
			action = "closeDialog 0;nul = createDialog ""radio_comm"";";
		};
		//Action Buttons
		class 8slots_L1: RscButton
		{
			idc = -1;
			text = "招募班组"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Recruit new squads and manage them with the HC Module (CTRL + SPACE)";
			action = "closeDialog 0;if (player == theBoss) then {nul= [] execVM ""Dialogs\squad_recruit.sqf""} else {hint ""只有指挥官才能使用此功能""};";
		};
		class 8slots_R1: RscButton
		{
			idc = -1;
			text = "空中支援"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Ask for Air Support (uses Airstrike points)";
			action = "closeDialog 0;if (player == theBoss) then {_nul = createDialog ""carpet_bombing""} else {hint ""只有指挥官才能使用此功能""};";
		};
		class 8slots_L2: RscButton
		{
			idc = -1;
			text = "观察哨 - 检查站"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Establish a new watchpost or roadblock depending on the type of terrain you select";
			action = "if (player == theBoss) then {closeDialog 0;[""create""] spawn A3A_fnc_puestoDialog} else {hint ""你不是指挥官!""};";
		};
		class 8slots_R2: RscButton
		{
			idc = -1;
			text = "清理垃圾"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cleans several things in game. Use with caution as it freezes the mission";
			action = "if (player == theBoss) then {closedialog 0;[] remoteExec [""A3A_fnc_garbageCleaner"",2]} else {hint ""只有指挥官才能使用此功能""};";
		};
		class 8slots_L3: RscButton
		{
			idc = -1;
			text = "删除 观察哨-检查站"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Remove selected observation post or roadblock, money will be refunded";
			action = "if (player == theBoss) then {closeDialog 0; [""delete""] spawn A3A_fnc_puestoDialog} else {hint ""你不是指挥官!""};";
		};
		class 8slots_R3: RscButton
		{
			idc = -1;
			text = "阵营车库"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at a vehicle and garage it into faction garage (shared among commanders)";
			action = "if (player == theBoss) then {closeDialog 0;nul = [true] call A3A_fnc_garageVehicle;} else {hint ""你不是指挥官!""};";
		};
		class 8slots_L4: RscButton
		{
			idc = -1;
			text = "辞退/担任 指挥官"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Step down from commander or toggle eligibility";
			action = "if (isMultiplayer) then {closedialog 0;execVM ""orgPlayers\commResign.sqf""} else {hint ""This feature is MP Only""};";
		};
		class 8slots_R4: RscButton
		{
			idc = -1;
			text = "卖出车辆"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at a vehicle and sell it for money";
			action = "if (player == theBoss) then {closeDialog 0; nul = [] call A3A_fnc_sellVehicle} else {hint ""只有指挥官才能卖车""};";
		};
	};
};
class carpet_bombing 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Carpet Bombing Strike"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; nul = createDialog ""radio_comm"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "HE Bombs"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 1 point";
			action = "closeDialog 0;[""HE""] spawn A3A_fnc_NATObomb;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "Carpet Bombing"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 1 point";
			action = "closeDialog 0;[""CARPET""] spawn A3A_fnc_NATObomb;";
		};
		class 4slots_L2: RscButton
		{
			idc = -1;
			text = "NAPALM Bomb"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 1 point";
			action = "closeDialog 0;[""NAPALM""] spawn A3A_fnc_NATObomb;";
		};
		class 4slots_R2: RscButton
		{
			idc = -1;
			text = "Add to Air Support"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Gain Airstrike points giving this aircraft to the faction Air pool";
			action = "closeDialog 0;nul = [] call A3A_fnc_addBombRun";
		};
	};
};


class dismiss_menu 				{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "解散选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "解散 单位 / 班组"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Dimiss selected units or squads, recovering it's cost to the proper resource pool";
			action = "closeDialog 0;if (count groupselectedUnits player > 0) then {nul = [groupselectedUnits player] execVM ""REINF\dismissPlayerGroup.sqf""} else {if (count (hcSelected player) > 0) then {nul = [hcSelected player] execVM ""REINF\dismissSquad.sqf""}}; if ((count groupselectedUnits player == 0) and (count hcSelected player == 0)) then {hint ""No units or squads selected""}";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "Garrison Units / Squads"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Adds selected units or squads to a map selected garrison";
			action = "closeDialog 0;if (count groupselectedUnits player > 0) then {nul = [groupselectedUnits player] execVM ""REINF\addToGarrison.sqf""} else {if (count (hcSelected player) > 0) then {nul = [hcSelected player] execVM ""REINF\addToGarrison.sqf""}}; if ((count groupselectedUnits player == 0) and (count hcSelected player == 0)) then {hint ""No units or squads selected""}";
		};
		/*
		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Remove Garrison Squads"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [] call removeGarrison";
		};
		*/
	};
};
class construction_menu 	{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "建造工事菜单"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""radio_comm"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "小掩体"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Make a quick small trench for one man";
			action = "closeDialog 0;nul = [""ST""] spawn A3A_fnc_construir;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "中掩体"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "A mid sized trench with capabilities for more than one soldier";
			action = "closeDialog 0; nul = [""MT""] spawn A3A_fnc_construir;";
		};

		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "路障"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Build some obstacles for vehicles";
			action = "closeDialog 0;nul = [""RB""] spawn A3A_fnc_construir;";
		};
		class HQ_button_unlock: RscButton
		{
			idc = -1;
			text = "碉堡选项"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Need to be built in garrison controlled zones and cost money";
			action = "closeDialog 0;nul = createDialog ""bunker_menu""";
		};
	};
};
class bunker_menu 				{
	idd=-1;
	movingenable=false;

	class controls {

		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "选择碉堡类型"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "沙袋掩体"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Requires to be in a garrisoned zone. It will be permanent";
			action = "closeDialog 0;nul = [""SB""] spawn A3A_fnc_construir;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "混凝土碉堡"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Requires to be in a garrisoned zone. It will be permanent";
			action = "closeDialog 0;nul = [""CB""] spawn A3A_fnc_construir;";
		};
		/*
		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Remove Garrison Squads"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [] call removeGarrison";
		};
		*/
	};
};
class squad_recruit 			{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = 101;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = 102;
			text = "招募班组选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = 103;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; _nul = createDialog ""radio_comm"";";
		};
		class HQ_button_infsquad: RscButton
		{
			idc = 104;
			text = "招募步兵班"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;[] execVM ""Dialogs\squadOptions.sqf"";";
		};
		class HQ_button_infteam: RscButton
		{
			idc = 105;
			text = "招募步兵组"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [gruposSDKmid] spawn A3A_fnc_addFIAsquadHC";
		};
		class HQ_button_ATteam: RscButton
		{
			idc = 106;
			text = "招募反坦克组"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [gruposSDKAT] spawn A3A_fnc_addFIAsquadHC";
		};
		class HQ_button_sniperTeam: RscButton
		{
			idc = 107;
			text = "招募狙击组"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [gruposSDKSniper] spawn A3A_fnc_addFIAsquadHC";
		};
		class HQ_button_infsquadM: RscButton
		{
			idc = 108;
			text = "招募机枪组"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [SDKMGStatic] spawn A3A_fnc_addFIAsquadHC";
		};
		class HQ_button_infteamM: RscButton
		{
			idc = 109;
			text = "招募反坦克皮卡"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [vehSDKAT] spawn A3A_fnc_addFIAsquadHC";
		};
		class HQ_button_ATteamM: RscButton
		{
			idc = 110;
			text = "招募防空卡车"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [staticAABuenos] spawn A3A_fnc_addFIAsquadHC";
		};

		class HQ_button_mortar: RscButton
		{
			idc = 111;
			text = "招募迫击炮组"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [SDKMortar] spawn A3A_fnc_addFIAsquadHC";
		};
	};
};
class player_money 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "玩家和金钱 交互"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""radio_comm"";";
		};
		class HQ_button_mortar: RscButton
		{
			idc = -1;
			text = "添加为服务器会员"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Use this option to add the player which you are currently looking to the member's list";
			action = "if (isMultiplayer) then {closeDialog 0;nul = [""add""] call A3A_fnc_memberAdd;} else {hint ""This function is MP only""};";
		};
		class HQ_button_MG: RscButton
		{
			idc = -1;
			text = "移除服务器会员"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Use this option to remove the player which you are currently looking to the member's list";
			action = "if (isMultiplayer) then {closeDialog 0;nul = [""remove""] call A3A_fnc_memberAdd;} else {hint ""This function is MP only""};";
		};
		class HQ_button_AT: RscButton
		{
			idc = -1;
			text = "捐赠100 €给玩家"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[true] call A3A_fnc_donateMoney;";
		};
		class HQ_button_AA: RscButton
		{
			idc = -1;
			text = "捐赠100 €给阵营"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "It will increase your prestige among your faction";
			action = "[] call A3A_fnc_donateMoney;";
		};
	};
};
class garage_sell 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "卖出或保存 车辆"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""vehicle_manager"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "保存车辆"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;if (player != theBoss) then {nul = [false] call A3A_fnc_garageVehicle} else {if (isMultiplayer) then {_nul = createDialog ""garage_check""} else {nul = [true] call A3A_fnc_garageVehicle}};";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "卖出车辆"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; if (player == theBoss) then {nul = [] call A3A_fnc_sellVehicle} else {hint ""只有指挥官才能卖车""};";
		};
		/*
		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Remove Garrison Squads"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [] call removeGarrison";
		};
		*/
	};
};
class garage_check 				{
	idd=-1;
	movingenable=false;

	class controls {

		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "个人或阵营车库?"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""garage_sell"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "个人车库"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [false] call A3A_fnc_garageVehicle;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "阵营车库"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; nul = [true] call A3A_fnc_garageVehicle;";
		};
		/*
		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Remove Garrison Squads"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [] call removeGarrison";
		};
		*/
	};
};
class tu_madre 				{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Carpet Bombing Strike"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;//28
		};
		class HQ_button_back: RscListBox
		{
			idc = -1;
			//text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 35) * 1.2)";
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {1,1,1,1}; // Text selection color
			colorSelect2[] = {1,1,1,1}; // Text selection color (oscillates between this and colorSelect)
			colorShadow[] = {0,0,0,0.5}; // Text shadow color (used only when shadow is 1)
			pictureColor[] = {1,1,1,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {0,1,0,1}; // Disabled picture color


			//action = "closeDialog 0; nul = createDialog ""NATO_Options"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "HE Bombs"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 10 points";
			action = "closeDialog 0;[""HE""] spawn A3A_fnc_NATObomb;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "Carpet Bombing"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 10 points";
			action = "closeDialog 0;[""CARPET""] spawn A3A_fnc_NATObomb;";
		};

		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "NAPALM Bomb"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 10 points";
			action = "closeDialog 0;[""NAPALM""] spawn A3A_fnc_NATObomb;";
		};
	};
};



//Mortar shift+Y
class mortar_type {
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Select Mortar Ammo"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "HE"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;tipoMuni = SDKMortarHEMag;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "Smoke"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; tipoMuni = SDKMortarSmokeMag;";
		};
		/*
		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Remove Garrison Squads"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [] call removeGarrison";
		};
		*/
	};
};
class rounds_number {
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Select No. Rounds to be fired"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_AS: RscButton
		{
			idc = -1;
			text = "1"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;rondas = 1;";
		};
		class HQ_button_CONV: RscButton
		{
			idc = -1;
			text = "2"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;rondas = 2";
		};
		class HQ_button_DES: RscButton
		{
			idc = -1;
			text = "3"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; rondas = 3";
		};
		class HQ_button_LOG: RscButton
		{
			idc = -1;
			text = "5"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;rondas = 5";
		};
		class HQ_button_RES: RscButton
		{
			idc = -1;
			text = "7"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;rondas = 7";
		};
		class HQ_button_vehicle: RscButton
		{
			idc = -1;
			text = "6"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;rondas = 6";
		};
		class HQ_button_fpsplus: RscButton
		{
			idc = -1;
			text = "4"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; rondas = 4";
		};

		class HQ_button_AA: RscButton
		{
			idc = -1;
			text = "8"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;rondas = 8";
		};
	};
};
class strike_type {
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Select type of strike"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "Single Point Strike"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;tipoArty = ""NORMAL"";";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "Barrage Strike"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; tipoArty = ""BARRAGE"";";
		};
		/*
		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Remove Garrison Squads"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "nul = [] call removeGarrison";
		};
		*/
	};
};

//NATO
class NATO_player {
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "SpecOp Menu"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "Quadbike"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;[] call A3A_fnc_NATOQuadbike";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "Fast Travel"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;[] spawn A3A_fnc_NATOFT";
		};
	};
};


//Undefined
class mbt_type {
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Select type ammo for the strike"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "Back"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = -1;
			text = "HE"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;tipoMuni = ""32Rnd_155mm_Mo_shells"";";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = -1;
			text = "Laser Guided"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; tipoMuni = ""2Rnd_155mm_Mo_LG"";";
		};

		class HQ_button_Gremove: RscButton
		{
			idc = -1;
			text = "Smoke"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; tipoMuni = ""6Rnd_155mm_Mo_smoke"";";
		};
	};
};
class squad_options 	{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;//30
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "班组选项"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;//28
		};
		class HQ_button_back: RscButton
		{
			idc = -1;
			text = "后退"; //--- ToDo: Localize;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;_nul = createDialog ""squad_recruit"";";
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = 104;
			text = "步兵班"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			//tooltip = "";
			action = "closeDialog 0;nul = [gruposSDKSquad] spawn A3A_fnc_addFIAsquadHC;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = 105;
			text = "工兵班"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; nul = [gruposSDKSquadEng] spawn A3A_fnc_addFIAsquadHC;";
		};

		class HQ_button_Gremove: RscButton
		{
			idc = 106;
			text = "机枪班"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [gruposSDKSquadSupp,""MG""] spawn A3A_fnc_addFIAsquadHC;";
		};
		class HQ_button_unlock: RscButton
		{
			idc = 107;
			text = "炮击跑班"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;nul = [gruposSDKSquadSupp,""Mortar""] spawn A3A_fnc_addFIAsquadHC;";
		};
	};
};
class diff_menu 			{
	idd=-1;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Choose difficulty"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_mortar: RscButton
		{
			idc = -1;
			text = "Easy"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;skillMult = 0.5";
		};
		class HQ_button_MG: RscButton
		{
			idc = -1;
			text = "Normal"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;";
		};
		class HQ_button_AT: RscButton
		{
			idc = -1;
			text = "Hard"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; skillMult = 2";
		};
	};
};

class gameMode_menu 			{
	idd=100;
	movingenable=false;

	class controls {
		class HQ_box: BOX
		{
			idc = -1;
			text = ""; //--- ToDo: Localize;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame
		{
			idc = -1;
			text = "Select your Game Mode"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_Gsquad: RscButton
		{
			idc = 104;
			text = "Reb vs Gov vs Inv"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;gameMode = 1;";
		};
		class HQ_button_Gstatic: RscButton
		{
			idc = 105;
			text = "Rev vs Gov & Inv"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;gameMode = 2;";
		};
		class HQ_button_Gremove: RscButton
		{
			idc = 106;
			text = "Reb vs Gov"; //--- ToDo: Localize;
			//x = 0.37749 * safezoneW + safezoneX;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;gameMode = 3;";
		};
		class HQ_button_offroad: RscButton
		{
			idc = 107;
		 	text = "Reb vs Inv"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
		 	y = 0.415981 * safezoneH + safezoneY;
		 	w = 0.175015 * safezoneW;
		 	h = 0.0560125 * safezoneH;
		 	action = "closeDialog 0;gameMode = 4";
		 };
	};
};

class RscTitles {
	class Default {
       idd = -1;
       fadein = 0;
       fadeout = 0;
       duration = 0;
    };
    class H8erHUD {
        idd = 745;
        movingEnable =  0;
        enableSimulation = 1;
        enableDisplay = 1;
        duration     =  10e10;
        fadein       =  0;
        fadeout      =  0;
        name = "H8erHUD";
		onLoad = "with uiNameSpace do { H8erHUD = _this select 0 }";
		class controls {
		    class structuredText {
                access = 0;
                type = 13;
                idc = 1001;
                style = 0x00;
                lineSpacing = 1;
				x = 0.103165 * safezoneW + safezoneX;
				y = 0.007996 * safezoneH + safezoneY;//0.757996
				w = 0.778208 * safezoneW;
				h = 0.0660106 * safezoneH;
                size = 0.055;//0.020
                colorBackground[] = {0,0,0,0};
                colorText[] = {0.34,0.33,0.33,0};//{1,1,1,1}
                text = "";
                font = "PuristaSemiBold";
				class Attributes {
					font = "PuristaSemiBold";
					color = "#C1C0BB";//"#FFFFFF";
					align = "CENTER";
					valign = "top";
					shadow = true;
					shadowColor = "#000000";
					underline = false;
					size = "4";//4
				};
            };
		};
	};
};
