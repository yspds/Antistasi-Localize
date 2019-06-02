if (player != theBoss) exitWith {hint "只有指挥官才能清除树林"};
if (!isMultiplayer) then {{ _x hideObject true } foreach (nearestTerrainObjects [getMarkerPos respawnBuenos,["tree","bush"],70])} else {{[_x,true] remoteExec ["hideObjectGlobal",2]} foreach (nearestTerrainObjects [getMarkerPos respawnBuenos,["tree","bush"],70])};
hint "附近杂草和树木已清除";
chopForest = true; publicVariable "chopForest";
