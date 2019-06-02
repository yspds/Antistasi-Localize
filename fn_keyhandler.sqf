waitUntil {!isNull(findDisplay 46)};
(findDisplay 46) displayAddEventHandler ["KeyDown","_this call keybind"];

keybind = {
_control = _this select 0;
_code = _this select 1; 
_shift = _this select 2; 
_ctrl = _this select 3; 
_alt = _this select 4; 
_handled = false;

if (!(actionKeys "User10" isEqualTo []) && {(inputAction "User10" > 0)}) exitWith {
if (player getVariable ["INCAPACITATED",false]) exitWith {};
	if (player getVariable ["owner",player] != player) exitWith {};
			if (!hasInterface) exitWith {};
			if (isNil"garageVeh") then
		{
		if (_this select 2) then
		{
		if (player == theBoss) then
			{
			[] spawn A3A_fnc_artySupport;
			};
		}
		else
		{
		closedialog 0;
		_nul = createDialog "radio_comm";
		};
	};

_handled;
};

if (!(actionKeys "User11" isEqualTo []) && {(inputAction "User11" > 0)}) exitWith {
		if (soundVolume isEqualTo 1) then {
		1 fadeSound 0.4; hintSilent "Ear Plugs Inserted";
		}else{
		1 fadeSound 1; hintSilent "Ear Plugs Removed";
		};
_handled;
};

if (!(actionKeys "User12" isEqualTo []) && {(inputAction "User12" > 0)}) exitWith {
			if (player == player && vehicle player == player) then {
			_mags = magazinesAmmo player;
			_inv = _mags select {(_x select 0) in getArray (configFile >> "cfgWeapons" >> currentWeapon player >> "magazines")};
			if (count _inv > 1) then {
			_sort = [_inv,[],{_x select 1},"ASCEND"] call BIS_fnc_sortBy;
			_lowest_mag = _sort select 0 select 0;
			_lowest_cnt = _sort select 0 select 1;
			_mags_space = _sort select [1, count _sort - 1];
			_full_tot = 0;
			_remain_tot = 0;
			{_full_tot = _full_tot + getnumber (configFile >> "cfgmagazines" >> _x select 0 >> "count")} forEach _mags_space;
			{_remain_tot = _remain_tot + (_x select 1)} forEach _mags_space;
			_full_space = _full_tot - _remain_tot;
			if (_lowest_cnt <= _full_space) then {
			for "_i" from 0 to count _mags_space - 1 do {
			if (_lowest_cnt > 0) then {
			_current_mag = _mags_space select _i select 0;
			_current_ammo = _mags_space select _i select 1;
			_current_space =  getnumber (configFile >> "cfgmagazines" >> _current_mag >> "count") - _current_ammo;
			if (_current_space > 0) then {
			_mags_space set [_i,[_current_mag,_current_ammo + _lowest_cnt]];
			_lowest_cnt = _lowest_cnt - _current_space;
						};
						};
						};
			{player removeMagazineGlobal (_x select 0)} forEach (magazinesAmmo player select {(_x select 0) in getArray (configFile >> "cfgWeapons" >> currentWeapon player >> "magazines")});
			{player addMagazine _x} forEach _mags_space;
					};
				}};
			player playAction "reloadMagazine";
			hintsilent "Mags Repacked";
_handled;
};

if (!(actionKeys "User13" isEqualTo []) && {(inputAction "User13" > 0)}) exitWith {
				player action ["SWITCHWEAPON",player,player,-1];
				waitUntil {currentWeapon player == "" or {primaryWeapon player == "" && handgunWeapon player == ""}};
			
		_handled;
		};

if (!(actionKeys "User14" isEqualTo []) && {(inputAction "User14" > 0)}) exitWith {
	if (player getVariable ["INCAPACITATED",false]) exitWith {};
	if (isNil "AR_active") then {AR_active = false;};
	if (AR_active) exitWith {AR_active = false; _handled = true;};

	if (!isNull objectParent player) exitWith {};
	if (surfaceIsWater (getPos player)) exitWith {};

	AR_active = true;
	AR_weapon = currentWeapon player;
	AR_animation = switch (true) do {
		case (AR_weapon isEqualTo ""): {"AmovPercMevaSnonWnonDf"};
		case (AR_weapon isEqualTo (primaryWeapon player)): {"AmovPercMevaSlowWrflDf"};
		case (AR_weapon isEqualTo (secondaryWeapon player)): {"AmovPercMevaSlowWrflDf"};
		case (AR_weapon isEqualTo (handgunWeapon player)): {"AmovPercMevaSlowWpstDf"};
	};

	player playMoveNow AR_animation;

	player addEventHandler ["AnimChanged", {
		if ((!AR_active) || {!((currentWeapon player) isEqualTo AR_weapon)} || (player getVariable ["INCAPACITATED",false]) || {!isNull objectParent player} || {surfaceIsWater (getPos player)}) exitWith {
			player removeEventHandler ["AnimChanged", _thisEventHandler];

			AR_weapon = currentWeapon player;
			AR_animation = switch (true) do {
				case (AR_weapon isEqualTo ""): {"AmovPercMstpSnonWnonDnon"};
				case (AR_weapon isEqualTo (primaryWeapon player)): {"AmovPercMstpSlowWrflDnon"};
				case (AR_weapon isEqualTo (secondaryWeapon player)): {"AmovPercMevaSlowWlnrDf"};
				case (AR_weapon isEqualTo (handgunWeapon player)): {"AmovPercMstpSlowWpstDnon"};
			};

			player playMoveNow AR_animation;

			AR_active = false;
			AR_weapon = nil;
			AR_animation = nil;
		};

		player playMoveNow AR_animation;
	}];

	_handled = true;
_handled;
};


switch (_code) do {

	case 19: {//R key

		if (!_shift && _ctrl && !_alt) then {
			if (player == player && vehicle player == player) then {
			_mags = magazinesAmmo player;
			_inv = _mags select {(_x select 0) in getArray (configFile >> "cfgWeapons" >> currentWeapon player >> "magazines")};
			if (count _inv > 1) then {
			_sort = [_inv,[],{_x select 1},"ASCEND"] call BIS_fnc_sortBy;
			_lowest_mag = _sort select 0 select 0;
			_lowest_cnt = _sort select 0 select 1;
			_mags_space = _sort select [1, count _sort - 1];
			_full_tot = 0;
			_remain_tot = 0;
			{_full_tot = _full_tot + getnumber (configFile >> "cfgmagazines" >> _x select 0 >> "count")} forEach _mags_space;
			{_remain_tot = _remain_tot + (_x select 1)} forEach _mags_space;
			_full_space = _full_tot - _remain_tot;
			if (_lowest_cnt <= _full_space) then {
			for "_i" from 0 to count _mags_space - 1 do {
			if (_lowest_cnt > 0) then {
			_current_mag = _mags_space select _i select 0;
			_current_ammo = _mags_space select _i select 1;
			_current_space =  getnumber (configFile >> "cfgmagazines" >> _current_mag >> "count") - _current_ammo;
			if (_current_space > 0) then {
			_mags_space set [_i,[_current_mag,_current_ammo + _lowest_cnt]];
			_lowest_cnt = _lowest_cnt - _current_space;
						};
						};
						};
			{player removeMagazineGlobal (_x select 0)} forEach (magazinesAmmo player select {(_x select 0) in getArray (configFile >> "cfgWeapons" >> currentWeapon player >> "magazines")});
			{player addMagazine _x} forEach _mags_space;
					};
				}};
			player playAction "reloadMagazine";
			hintsilent "Mags Repacked";
		};
	};

	case 21: {//Y key
	if (player getVariable ["INCAPACITATED",false]) exitWith {};
	if (player getVariable ["owner",player] != player) exitWith {};
		if (!_shift && !_ctrl && !_alt) then {
			if (!hasInterface) exitWith {};
			if (isNil"garageVeh") then
		{
		if (_this select 2) then
		{
		if (player == theBoss) then
			{
			[] spawn A3A_fnc_artySupport;
			};
		}
		else
		{
		closedialog 0;
		_nul = createDialog "radio_comm";
		};
	};
	}
		};


	case 35: {//H key

			if (!_shift && !_ctrl && !_alt) then {
				if (!hasInterface) exitWith {};
				player action ["SWITCHWEAPON",player,player,-1];
				waitUntil {currentWeapon player == "" or {primaryWeapon player == "" && handgunWeapon player == ""}};
			};
		};

	case 207: {//END key
		
		if (soundVolume isEqualTo 1) then {
		1 fadeSound 0.4; hintSilent "Ear Plugs Inserted";
		}else{
		1 fadeSound 1; hintSilent "Ear Plugs Removed";
		};
	_handled;
	};

	case 219: { //Windows Key
	if (player getVariable ["INCAPACITATED",false]) exitWith {};
	if (isNil "AR_active") then {AR_active = false;};
	if (AR_active) exitWith {AR_active = false; _handled = true;};

	if (!isNull objectParent player) exitWith {};
	if (surfaceIsWater (getPos player)) exitWith {};

	AR_active = true;
	AR_weapon = currentWeapon player;
	AR_animation = switch (true) do {
		case (AR_weapon isEqualTo ""): {"AmovPercMevaSnonWnonDf"};
		case (AR_weapon isEqualTo (primaryWeapon player)): {"AmovPercMevaSlowWrflDf"};
		case (AR_weapon isEqualTo (secondaryWeapon player)): {"AmovPercMevaSlowWrflDf"};
		case (AR_weapon isEqualTo (handgunWeapon player)): {"AmovPercMevaSlowWpstDf"};
	};

	player playMoveNow AR_animation;

	player addEventHandler ["AnimChanged", {
		if ((!AR_active) || {!((currentWeapon player) isEqualTo AR_weapon)} || (player getVariable ["INCAPACITATED",false]) || {!isNull objectParent player} || {surfaceIsWater (getPos player)}) exitWith {
			player removeEventHandler ["AnimChanged", _thisEventHandler];

			AR_weapon = currentWeapon player;
			AR_animation = switch (true) do {
				case (AR_weapon isEqualTo ""): {"AmovPercMstpSnonWnonDnon"};
				case (AR_weapon isEqualTo (primaryWeapon player)): {"AmovPercMstpSlowWrflDnon"};
				case (AR_weapon isEqualTo (secondaryWeapon player)): {"AmovPercMevaSlowWlnrDf"};
				case (AR_weapon isEqualTo (handgunWeapon player)): {"AmovPercMstpSlowWpstDnon"};
			};

			player playMoveNow AR_animation;

			AR_active = false;
			AR_weapon = nil;
			AR_animation = nil;
		};

		player playMoveNow AR_animation;
	}];

	_handled = true;
};

};
_handled;
};


