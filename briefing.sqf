waitUntil {!isNull player};

if (side player == buenos) then
{
_index =player createDiarySubject ["游戏说明","初始新手教程"];
player createDiaryRecord ["新手教程",["伪装","在游戏初期，特别是完成某些任务时，保持伪装状态是及其有用的。就像真正的游击队员一样，你伪装时敌人不会主动攻击。有关伪装模式的详细说明，请参见“功能”部分"]];
player createDiaryRecord ["新手教程",["起始位置","选择一个好的位置开始任务。不同的营地位置选择有着不同的游戏体验。仔细研究准备安置营地的地形和它们之间的道路。如果你在敌占区或者道路附近建立营地，敌人的巡逻队可能会出现并杀死游击队领袖——老佩罗斯。"]];
player createDiaryRecord ["新手教程",["资源","拥有足够的资源才能支持更大规模的作战，尤其是武器和弹药。在初始阶段，您的主要资源来源是完成支线任务。"]];
player createDiaryRecord ["新手教程",["征服和占领","当你占领了像资源点、机场等战略要地时，敌人会尽其所能发动反击。如果你没有十足把握，打了就跑也是一个不错的选择。"]];
player createDiaryRecord ["新手教程",["策略","一旦你有了大量的资源，建议优先考虑攻击信号塔。这样敌人在你的骚扰下，我们面临的大规模的反击压力会小一些。"]];
player createDiaryRecord ["新手教程",["侵略性影响","时刻注意敌人的侵略性，该值越高，你所面对敌人反击的频率和力度就会越高."]];
player createDiaryRecord ["新手教程",["初期建议","不要指望一口吃成胖子。首先，你必须收集足够的资源（人力和资金）。这个任务试图模拟现实生活中的游击队情况，如果不知道该怎么办，假设自己在真实战场上设身处地时会做些什么。别指望每次都能打赢，打了就跑才是基本路线。获得更多的资源，武器和弹药才能对敌人构成真正的挑战。与此同时，不要忘了骚扰敌人的作战行动，以及获得当地民众的支持。"]];

_index =player createDiarySubject ["指挥官","指挥官选项"];
player createDiaryRecord ["指挥官",["内置会员系统","在HQ旗帜处，可以查询哪些会员正在游戏中，以及非成员的数量。"]];
player createDiaryRecord ["指挥官",["提取公款","使用此选项可以从阵营账户提取公款到您的个人帐户。请注意，这将影响您的分数和未来的晋升机会。腐败的指挥官可能会被纪委调查。"]];
player createDiaryRecord ["指挥官",["检查站","使用菜单并在地图上选择一个合适的地点。单击道路，一队AT士兵将来到营地。把他们送到选定的地方，他们会在那里设置检查站。"]];
player createDiaryRecord ["指挥官",["观察哨","在地图上选择一个视野良好的地点，一个狙击小组将到达营地。把他们送到所选的地方，他们会保持隐匿状态并帮你观察战场态势。"]];
player createDiaryRecord ["指挥官",["卖出车辆","使用此选项出售获取的车辆并增加阵营资金。"]];
player createDiaryRecord ["指挥官",["设置雷区","招募一队工程师开着卡车到指定位置去建一个雷区。在他们部署地雷时掩护他们。雷区建立完毕后，没有人能够安全地通过该区域（即使是你自己的单位——所以要小心使用）。地雷（AT和AP）是从你的弹药箱中取出的。野外地雷的数量将取决于弹药的库存，最大数量取决于地雷的类型。删除雷区可以恢复区域安全。"]];
player createDiaryRecord ["指挥官",["招募班组","指挥官可在营地旗帜处招募AI班组。使用高级指挥模式（ctrl+space）向您的班组下达命令。同样，你也可以临时控制或者解散班长和班组成员。"]];
player createDiaryRecord ["指挥官",["炮兵支援","有人操作的迫击炮可作为炮兵支援。使用高级指挥模式选择一个迫击炮小组，并在游戏中按SHIFT+Y呼叫炮火支援。"]];
player createDiaryRecord ["指挥官",["空袭支援","使用您的空袭点执行指定类型的轰炸任务。"]];
player createDiaryRecord ["指挥官",["营火","在HQ营火上的动作菜单可以休息（跳过游戏时间）8小时。"]];
player createDiaryRecord ["指挥官",["迁移HQ","指挥官可在HQ旗杆上选择此选项，以便将HQ搬迁到另一个地点。这将允许你把总部转移到一个更安全或更靠近前线的地方。你的总部离敌人越近，你可以进行的支线任务越多。记得！保持游击队领袖——老佩罗斯的安全，否则你会输掉游戏！"]];
player createDiaryRecord ["指挥官",["支线任务","向老佩罗斯领取不同类型的任务。任务是否可进行取决于总部的位置、当前分配的任务和周边地区的所有权。"]];
player createDiaryRecord ["指挥官",["技能训练","花费一定的费用，你可以升级阵营AI的训练水平，以便未来的友军AI有更好的作战技能。"]];
player createDiaryRecord ["指挥官",["驻防部队","指挥官可为被征服地区指派驻军。使用HQ旗杆的驻军管理选项添加或删除守卫部队。查看地图信息，可了解每个区域分配了多少士兵。"]];
player createDiaryRecord ["指挥官",["指挥官","有一个指挥官是很有必要的，因为游戏中许多选项仅对指挥官可用，并且根据设置，在多人任务中最有经验的玩家通常会占据这个位置。"]];

_index =player createDiarySubject ["自定义按键","特殊按键"];
player createDiaryRecord ["自定义按键",["自动奔跑","使用[自定义动作14]或Windows键启用/禁用自动奔跑。"]];
player createDiaryRecord ["自定义按键",["整理弹夹","使用[自定义动作12]或ctrl+r重新整理弹夹"]];
player createDiaryRecord ["自定义按键",["收起武器","使用[自定义动作13]或H键实现收枪功能"]];
player createDiaryRecord ["自定义按键",["降噪耳塞","使用[自定义动作11]或END键启用/禁用耳塞。ace模式下不可用。"]];
player createDiaryRecord ["自定义按键",["小队管理","仅限多人模式：在游戏中按U键加入其他玩家的组"]];
player createDiaryRecord ["自定义按键",["炮兵支援","在游戏中按SHIFT+Y，同时在HC栏上选择炮兵小队。"]];
player createDiaryRecord ["自定义按键",["高级指挥","当你是指挥官时，点击ctrl+space以使用高阶指挥模式给你的AI小队指示路点和其他命令。非指挥员可以使用它来检查共享的敌人动向。"]];
player createDiaryRecord ["自定义按键",["战斗选项","使用[自定义动作10]或在游戏中按Y，以便随时访问多个选项。其中具体用处已在指挥官或功能部分中进行了解释。"]];

_index =player createDiarySubject ["功能","功能详情"];
player createDiaryRecord ["功能",["玩家与金钱","玩家可以使用此选项向其他玩家或阵营资金捐款。"]];
player createDiaryRecord ["功能",["服务器会员","仅用于多人游戏。如果启用，非成员玩家不能成为指挥官及使用基地军火库未解锁的武器。此功能旨在避免您的游戏体验被公共服务器恶意玩家破坏。"]];
//player createDiaryRecord ["特别说明",["团队选择","仅用于多人模式。你可以建立最多10人玩家的团队，指挥官不算。"]];
player createDiaryRecord ["功能",["固定式武器","如果你把购买的固定式MG/AA/AT留在基地或区域，它们不会消失，AI友军会在需要时使用它们。"]];
player createDiaryRecord ["功能",["快速旅行","当附近没有敌人时，快速前往友军所控制的地方。指挥官还可以在高级指挥模式的班组上使用此选项，在高级指挥栏上选择组并单击此按钮"]];
player createDiaryRecord ["功能",["弹药箱转移","当你开着一辆卡车，可以使用动作菜单中的转移动作，它将会搜寻附近的弹药箱，并把距离最近的一个装载进卡车车厢。你可将之运回基地并卸货至军火库，储备为以后使用。卸货之前可以把自己身上的装备也放进卡车库存，一并转移至军火库。"]];
player createDiaryRecord ["功能",["征服","某些区域，如机场或机场，需要在其各自的旗帜上使用“夺旗”操作才能征服它们。有些比如检查站和前哨站，只需要你打败守卫部队即可。"]];
player createDiaryRecord ["功能",["固定式武器","你可以偷走在敌机场发现的固定式武器。您必须使用“偷取固定式武器”动作来执行此操作。在使用“偷取固定式武器”操作之前，不要拆卸它们！"]];
player createDiaryRecord ["功能",["车辆","你可以在基地旗杆滚轮选项中购买车辆。"]];
player createDiaryRecord ["功能",["通讯塔",format ["摧毁或占领信号塔，用以增加附近人民的信任度 %1 ",worldName]]];
player createDiaryRecord ["功能",["政治","这是一场内战。如果你不能征服人们的心，意味着你不能征服城市。每个城镇的公民都在一定程度上支持敌人或派别。占主导地位的派系可占领这座城市并从中获得资金和人力资源（HR）支持。你的行动可能会削弱敌人，加强自己。杀死敌人、完成任务、征服资源和发电站会影响公民的支持量。"]];
player createDiaryRecord ["功能",["虚拟军火库","从敌人那里扫荡好的装备装回基地军火库. 一旦达到一定数量，这些武器将被解锁并无限使用. 武器升级解锁也会影响到你招募的AI可用的武器，库存装备强弱也会一定程度影响AI装备配置,因为AI的武器来源就是我们的军火库里已解锁装备。"]];
player createDiaryRecord ["功能",["伪装模式","点击这个按钮进行卧底。如果你在卧底状态，敌人不会攻击你。步行时，要做卧底，你必须没有可见的武器或军事装备。当你换装、被敌方警卫犬发现、部署地雷时，你将失去卧底状态，并且一些平民也会向敌方报告。你也可以进入任何民用车辆开始卧底模式，不过如果你在车上开枪或远离道路将失去卧底身份，也就不能再在那辆车里继续卧底了。接近敌人的空军基地、哨所和路障也会使你失去卧底身份。"]];
player createDiaryRecord ["功能",["车库","在你的个人虚拟车库（或阵营车库，如果你是指挥官）附近可存储缴获或购买的载具以备将来使用。车辆添加选项位于Y菜单下。车库管理在总部选项（标志）中。但飞行载具需要在机场、船只在岸边旗帜点回收。"]];
player createDiaryRecord ["功能",["阵营领导","正如任何抵抗运动一样，领导层并不像有组织国家那样稳定。如果现在的玩家不是很受欢迎的话，任何玩家都可以扮演势力指挥官的角色…在完成任务和杀死敌人的同时展示你的技能，也许你会成为下一个领导者。"]];

_index =player createDiarySubject ["AI","AI管理"];
player createDiaryRecord ["AI",["解散班组成员","选择单位并使用“解雇班友”选项将其送回总部。你会收回你花在他们身上的钱"]];
player createDiaryRecord ["AI",["班组车辆","只有指挥官可用。使用此选项可增加车辆分配给任何招募的友军AI小组。检查车辆状态，命令他们上船或下船，并自动安装固定式武器等。"]];
player createDiaryRecord ["AI",["自动搜刮和重新武装","使用此选项，你的AI小队成员会自动寻找并搜刮附近尸体、车辆和弹药箱中的任何弹药。他们还将尝试用更强大的武器更新他们的装备。如果AI在车里时使用此选项，他们会搜刮附近的武器放在卡车上，非常方便战后打扫战场"]];
player createDiaryRecord ["AI",["自动治疗","AI队友将自动治疗其他AI，而无需发出任何命令。如果在战斗中，你的AI队友将使用烟雾弹作为掩护。如果小组中没有医生，AI将使用自己的医疗包。"]];
player createDiaryRecord ["AI",["AI无线电","此功能旨在模拟与AI缺乏无线电通信战斗时的情况。初期无线电没有解锁时，你的AI队友不会有无线电，如果走得太远，他们会迷路，在完成最后一个命令后回到队长的位置。为了避免这一点，你可以从敌人那里搜集一些无线电（自动无线电功能可以做到），或者让人工智能使用一个有远程无线电的军用车辆。如果脱队太久，他们会自动返回总部。"]];
player createDiaryRecord ["AI",["AI控制","选择一个班友或高阶指挥小组，在有限的时间内直接控制他们。在高阶指挥小队时选择这个选项可以让你控制小队的队长。"]];
player createDiaryRecord ["AI",["Recruit","你可以在派别的旗帜和总部的旗帜上招募最多9名AI队友。"]];

_index =player createDiarySubject ["选项","游戏选项"];
player createDiaryRecord ["选项",["初始化UI","当Y键或统计栏不工作时，选择此选项。"]];
player createDiaryRecord ["选项",["垃圾清理","只有指挥官可用。将删除掉服务器内丢弃的武器、杂志、衣服等。小心，它会卡顿游戏一段时间"]];
player createDiaryRecord ["选项",["刷新距离","只有指挥官可用。 增加或减少敌军刷新重生距离。可与其他选项结合使用."]];
player createDiaryRecord ["选项",["平民数量","增加或减少城市平民的刷新比例。在0%时，每个城市只刷新一个平民。"]];
player createDiaryRecord ["选项",["音乐开/关","游击战争中有一个情景音乐脚本，取决于玩家的立场和一天中的时间。多人游戏中的默认值为“关”，而在单人游戏中为“开”。"]];
player createDiaryRecord ["选项",["游戏进度保存","只有指挥官可用。 你可以在总部地图上保存游戏。这将允许您在任务更新或服务器重新启动时继续游戏，保留统计信息、玩家设备、被征服区域、敌人资产可用性和更多内容。警告：正常保存和加载在此任务中运行不正常。这个系统是你正确保存游戏的唯一保证"]];
player createDiaryRecord ["选项",["AI总数量限制","只有指挥官可用。 设置每台服务器或每台主机映射中的最大AI量。"]];
player createDiaryRecord ["选项",["地图信息","点击一个城市，了解他们对敌人或派系的支持力度。点击其他区域了解相关信息。"]];

player createDiaryRecord ["日记",["鸣谢","<br/>LanCommi 插图.<br/>Goon 和 jw custom: 部分凝固汽油弹脚本.<br/>rebel12340: 无线电脚本<br/>Manko: 耳塞脚本<br/>bobchaos: 机制设定管理<br/>和所有花时间在STEAM、Github和BIS论坛上发表评论、建议和报告的玩家"]];
player createDiaryRecord ["日记",["模组","集成（可选）模组:<br/>tfar：当玩家无意识时声音被禁用无线电集成模组。<br/>ACE医疗模组: 与自动治疗功能不兼容。<br/><br/>警告：系统自动保存无法保持稳定，请使用游戏地图互动保存。<br/><br/>任何客户端的mod，如jsrs、blastcore、ui mod都可以工作。<br/><br/>当单位和车辆模型不工作。AI可能会出现智障的情况）。"]];
player createDiaryRecord ["日记",["脚本","UPSMon by Monsada, Kronzy and Cool=Azroul13 <br/>Persistent Save by zooloo75.<br/>Tags by Marker and Melbo.<br/>JAS by Jeroen (sorry for including you that late)<br/>Tags by Marker and Melbo.<br/>Advanced Towing by Seth Duda."]];
player createDiaryRecord ["日记",["HQ基本功能","旗帜：车辆和班组招募。指挥官选项。<br/>Maru：支线任务（仅指挥官）。<br/>地图: 游戏选项.<br/>营地篝火: 休息8小时，清除森林（仅指挥官）。"]];
player createDiaryRecord ["日记",["资源","每10分钟，每个派系都会根据他们所属的地区和所处的城镇获得金钱和人力。拥有大量的资源区和一些工厂是获得足够的资源来赢得这场战争的途径。"]];
player createDiaryRecord ["日记",["金钱","资金来源于公民对每个城市的支持、被征服的资源、被征服的工厂（这有助于促进经济发展）以及提供给他们所有人的电力以及附近友好的发电厂（你也可以征服它们以切断对敌人的资金供应）。钱被用来购买车辆、单位和小队"]];
player createDiaryRecord ["日记",["金钱 - 多人模式","在多人游戏中有两个资金池。派系资金仅供指挥官使用。个人资金可以被任何玩家用来招募AI或购买车辆。派系资金通过征税和完成任务来赚钱。个人的钱来自杀死敌人和完成任务。在Y菜单中可以找到转账或捐款选项。指挥官可以从派系池里拿钱到个人的账户里"]];
player createDiaryRecord ["日记",["人力","人力资源来自每个城市的公民支持。招募更多部队需要人力（1人力点数=1名士兵）"]];
player createDiaryRecord ["日记",[format ["%1 和 %2 威胁值",nameMalos,nameMuyMalos],format ["这是一场多个势力之间的全面战争，%4. %1 和 %2 之间会互相攻击, 但这不意味着他们不会在起始阶段就攻击 %3. %1 和 %2 的威胁值代表着他们眼中 %3 势力的威胁程度。 一般来说，根据你对他们和平民采取的行动，这些观点会降低或提高。",nameMalos,nameMuyMalos,nameBuenos,worldName]]];
switch (gameMode) do
	{
	case 1: {player createDiaryRecord ["日记",["AI RoE",format ["全体 vs 全体 开战.<br/><br/>%1 和 %2 将会互相攻击并会攻击 %3.",nameMalos,nameMuyMalos,nameBuenos]]]};
	case 2: {player createDiaryRecord ["日记",["AI RoE",format ["%3 vs 全体 开战.<br/><br/>%1 和 %2 将分别独立行动且只攻击 %3 . 两方势力均可征服.",nameMalos,nameMuyMalos,nameBuenos]]]};
	case 3: {player createDiaryRecord ["日记",["AI RoE",format ["%2 vs %1 开战.",nameMalos,nameBuenos]]]};
	case 4: {player createDiaryRecord ["日记",["AI RoE",format ["%2 vs %1 开战.",nameMuyMalos,nameBuenos]]]};
	};
player createDiaryRecord ["日记",["失败",format ["如果 %1 谋杀了 1/3 人口，游戏失败.",nameMuyMalos]]];
player createDiaryRecord ["日记",["胜利","当你获得了大多数人的支持，并且征服了所有空军基地时，你将赢得比赛。"]];

_nombreMiss = if (hayIFA) then {"Armia Krajowa"} else {if (worldName == "Tanoa") then {"Warlords of the Pacific"} else {"Antistasi"}};

player createDiaryRecord ["日记",["欢迎",format ["欢迎来到武装突袭3 - %1. 该任务旨在模拟游击战争的战术和战略局势。你讲经历漫长的游击时光，在一场又一场的战斗任务结束后，带领人民走向胜利。",_nombreMiss]]];
}
else
{
player createDiaryRecord ["日记",["鸣谢","<br/>LanCommi 插图.<br/>Goon 和 jw custom: 部分凝固汽油弹脚本.<br/>rebel12340: 无线电脚本<br/>Manko: 耳塞脚本<br/>bobchaos: 机制设定管理<br/>和所有花时间在STEAM、Github和BIS论坛上发表评论、建议和报告的玩家"]];
player createDiaryRecord ["日记",["模组","集成（可选）模组:<br/>tfar：当玩家无意识时声音被禁用无线电集成模组。<br/>ACE医疗模组: 与自动治疗功能不兼容。<br/><br/>警告：系统自动保存无法保持稳定，请使用游戏地图互动保存。<br/><br/>任何客户端的mod，如jsrs、blastcore、ui mod都可以工作。<br/><br/>当单位和车辆模型不工作。AI可能会出现智障的情况）。"]];
player createDiaryRecord ["日记",["脚本编写","UPSMon by Monsada, Kronzy and Cool=Azroul13 <br/>Persistent Save by zooloo75.<br/>Tags by Marker and Melbo."]];
player createDiaryRecord ["日记",["要求",format ["%1 和 %2 玩家插槽要求:<br/> %3 在线玩家指挥官.<br/>JIP玩家.<br/>服务器成员.<br/>与 %3玩家编号相同",nameMalos,nameMuyMalos,nameBuenos]]];
player createDiaryRecord ["日记",["情报","您将收到与主线任务或敌方情报报告相关的通知。"]];
player createDiaryRecord ["日记",["特殊按键","按Y键可快速旅行并购买四轮自行车供您自己使用。按END使用耳塞。"]];
player createDiaryRecord ["日记",["杀死马鲁",format ["找到 %1 指挥官并杀死他，会让其阵营损失大量资产.",nameBuenos]]];
player createDiaryRecord ["日记",[format ["%1 和 %2 玩家们",nameMalos,nameMuyMalos],format ["你是 %1 或 %2 的一员. 你的主要任务是平定游击队的叛乱。",nameMalos,nameMuyMalos]]];
player createDiaryRecord ["日记",["欢迎","欢迎来到武装突袭3 - 太平洋军阀. 该任务旨在模拟游击战争的战术和战略局势。你讲经历漫长的游击时光，在一场又一场的战斗任务结束后，带领人民走向胜利。"]];
};