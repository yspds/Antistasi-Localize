params ["_object"];
//diag_log ["addactionload"];
private _loadActionID = _object getVariable ["jnl_loadActionID",nil];

//Check if action exists already
if(!isnil "_loadActionID") then
{
	_object removeAction _loadActionID;
};

//Check if this vehicle can be loaded with JNL
if((_object call jn_fnc_logistics_getCargoType) == -1) exitWith {};

_text = "";

if (_object isKindOf "Man") then {_text = format ["<img image='\A3\ui_f\data\IGUI\Cfg\Actions\arrow_up_gs.paa' />  Load %1 in Vehicle</t>",name _object]} else {_text = "<img image='\A3\ui_f\data\IGUI\Cfg\Actions\arrow_up_gs.paa' />  Load Cargo in Vehicle</t>"};

_loadActionID = _object addAction [
	_text,
	{ //Action script
		private _cargo = _this select 0;
		private _player = _this select 1;
		//Search for vehicles able to load cargo of this type
		private _nearestVehicle = objNull;
		private _nearestDistance = 7;
		{
			_distance = _x distance _cargo;

			if(_distance < _nearestDistance && !(_x isEqualTo _cargo) && isnull (attachedTo _x)) then
			{
				if(_x call jn_fnc_garage_getVehicleIndex != -1 && _x call jn_fnc_garage_getVehicleIndex != 5) then
				{
					_nearestVehicle = _x;
					_nearestDistance = _distance;
				};
			};
		} forEach vehicles;

		_exit = false;
		if(isNull _nearestVehicle) then
		{
			hint '车辆离得太远';
			_exit = true;
		};
		if (_cargo isKindOf "Man") then
			{
			if (([_cargo] call A3A_fnc_canFight) or !(isNull (_cargo getVariable ["ayudado",objNull])) or !(isNull attachedTo _cargo)) then
				{
				hint format ["%1 正在被帮助或者不在需要你的帮助",name _cargo];
				_exit = true;
				};
			};
		if (_exit) exitWith {};
		private _nodeID = [_nearestVehicle, _cargo] call jn_fnc_logistics_canLoad;
		switch (_nodeID) do {
			case -4:
			{
				hint '无法载入货物: 乘客占据的载货空间!';
			};
			case -3:
			{
				hint '此车无法运输该货物!';
			};
		    case -2:
		    {
		   	hint '货仓空间不足!'
		    };
		    case -1:
		    {
		   	hint '无法载入此类型的货物!';
		    };
		    default
		    {
		   	[_nearestVehicle, _cargo, true, true] remoteexec ["jn_fnc_logistics_load", 2];
		    };
			};
	},
	nil, 1, true, false, "", "isnull attachedTo _target && vehicle player == player;", 3.5, false, ""
];

if (_object isKindOf "Man") then {_text = format ["Load %1 in Vehicle",name _object]} else {_text = "Load Cargo in Vehicle"};
_object setUserActionText [
	_loadActionID,
	_text,
	"<t size='2'><img image='\A3\ui_f\data\IGUI\Cfg\Actions\arrow_up_gs.paa'/></t>"
];

_object setVariable ["jnl_loadActionID", _loadActionID, false];

