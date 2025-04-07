#pragma once

#include <cmath>
#include <cstdint>
#include <iostream>
#include "primitives.h"

namespace math::fp::detail {

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays
//,cppcoreguidelines-pro-bounds-pointer-arithmetic)

inline constexpr std::array<int64_t, 1991> kAcosLut = {
    6746518852LL, 6739807963LL, 6733097057LL,   6726386119LL, 6719675131LL, 6712964078LL,
    6706252944LL, 6699541710LL, 6692830362LL,   6686118883LL, 6679407257LL, 6672695466LL,
    6665983496LL, 6659271328LL, 6652558948LL,   6645846337LL, 6639133481LL, 6632420363LL,
    6625706966LL, 6618993273LL, 6612279269LL,   6605564936LL, 6598850259LL, 6592135221LL,
    6585419806LL, 6578703996LL, 6571987775LL,   6565271128LL, 6558554037LL, 6551836486LL,
    6545118459LL, 6538399938LL, 6531680908LL,   6524961351LL, 6518241252LL, 6511520593LL,
    6504799358LL, 6498077530LL, 6491355093LL,   6484632030LL, 6477908325LL, 6471183961LL,
    6464458920LL, 6457733187LL, 6451006745LL,   6444279577LL, 6437551665LL, 6430822995LL,
    6424093548LL, 6417363308LL, 6410632258LL,   6403900381LL, 6397167660LL, 6390434079LL,
    6383699621LL, 6376964269LL, 6370228005LL,   6363490813LL, 6356752676LL, 6350013577LL,
    6343273499LL, 6336532424LL, 6329790337LL,   6323047219LL, 6316303054LL, 6309557824LL,
    6302811513LL, 6296064102LL, 6289315576LL,   6282565917LL, 6275815107LL, 6269063129LL,
    6262309966LL, 6255555601LL, 6248800016LL,   6242043194LL, 6235285117LL, 6228525769LL,
    6221765130LL, 6215003185LL, 6208239916LL,   6201475304LL, 6194709333LL, 6187941984LL,
    6181173241LL, 6174403084LL, 6167631498LL,   6160858464LL, 6154083963LL, 6147307979LL,
    6140530494LL, 6133751489LL, 6126970946LL,   6120188849LL, 6113405178LL, 6106619916LL,
    6099833044LL, 6093044545LL, 6086254401LL,   6079462592LL, 6072669102LL, 6065873911LL,
    6059077002LL, 6052278355LL, 6045477954LL,   6038675778LL, 6031871811LL, 6025066033LL,
    6018258425LL, 6011448970LL, 6004637648LL,   5997824441LL, 5991009330LL, 5984192297LL,
    5977373322LL, 5970552387LL, 5963729472LL,   5956904559LL, 5950077629LL, 5943248663LL,
    5936417642LL, 5929584546LL, 5922749356LL,   5915912053LL, 5909072618LL, 5902231031LL,
    5895387274LL, 5888541325LL, 5881693167LL,   5874842779LL, 5867990142LL, 5861135236LL,
    5854278042LL, 5847418539LL, 5840556708LL,   5833692528LL, 5826825981LL, 5819957045LL,
    5813085701LL, 5806211929LL, 5799335708LL,   5792457019LL, 5785575840LL, 5778692152LL,
    5771805933LL, 5764917164LL, 5758025825LL,   5751131893LL, 5744235349LL, 5737336172LL,
    5730434340LL, 5723529834LL, 5716622632LL,   5709712712LL, 5702800055LL, 5695884638LL,
    5688966441LL, 5682045442LL, 5675121620LL,   5668194953LL, 5661265420LL, 5654332998LL,
    5647397667LL, 5640459405LL, 5633518190LL,   5626573999LL, 5619626811LL, 5612676604LL,
    5605723356LL, 5598767044LL, 5591807646LL,   5584845139LL, 5577879502LL, 5570910711LL,
    5563938744LL, 5556963578LL, 5549985191LL,   5543003559LL, 5536018659LL, 5529030469LL,
    5522038965LL, 5515044123LL, 5508045921LL,   5501044336LL, 5494039342LL, 5487030918LL,
    5480019038LL, 5473003680LL, 5465984819LL,   5458962432LL, 5451936493LL, 5444906980LL,
    5437873867LL, 5430837131LL, 5423796746LL,   5416752689LL, 5409704933LL, 5402653456LL,
    5395598230LL, 5388539233LL, 5381476437LL,   5374409819LL, 5367339353LL, 5360265013LL,
    5353186773LL, 5346104608LL, 5339018493LL,   5331928400LL, 5324834305LL, 5317736181LL,
    5310634001LL, 5303527739LL, 5296417370LL,   5289302865LL, 5282184198LL, 5275061343LL,
    5267934272LL, 5260802959LL, 5253667375LL,   5246527493LL, 5239383287LL, 5232234728LL,
    5225081788LL, 5217924440LL, 5210762656LL,   5203596406LL, 5196425664LL, 5189250400LL,
    5182070585LL, 5174886192LL, 5167697191LL,   5160503552LL, 5153305248LL, 5146102248LL,
    5138894523LL, 5131682043LL, 5124464779LL,   5117242701LL, 5110015778LL, 5102783980LL,
    5095547277LL, 5088305638LL, 5081059032LL,   5073807429LL, 5066550798LL, 5059289107LL,
    5052022324LL, 5044750419LL, 5037473360LL,   5030191114LL, 5022903649LL, 5015610934LL,
    5008312936LL, 5001009622LL, 4993700959LL,   4986386915LL, 4979067456LL, 4971742549LL,
    4964412161LL, 4957076257LL, 4949734804LL,   4942387767LL, 4935035113LL, 4927676807LL,
    4920312813LL, 4912943098LL, 4905567627LL,   4898186363LL, 4890799271LL, 4883406316LL,
    4876007461LL, 4868602671LL, 4861191909LL,   4853775138LL, 4846352322LL, 4838923424LL,
    4831488407LL, 4824047232LL, 4816599862LL,   4809146260LL, 4801686386LL, 4794220204LL,
    4786747673LL, 4779268755LL, 4771783412LL,   4764291603LL, 4756793289LL, 4749288430LL,
    4741776986LL, 4734258916LL, 4726734180LL,   4719202738LL, 4711664547LL, 4704119566LL,
    4696567754LL, 4689009068LL, 4681443467LL,   4673870907LL, 4666291346LL, 4658704741LL,
    4651111049LL, 4643510225LL, 4635902225LL,   4628287006LL, 4620664523LL, 4613034730LL,
    4605397584LL, 4597753037LL, 4590101044LL,   4582441560LL, 4574774537LL, 4567099929LL,
    4559417689LL, 4551727769LL, 4544030121LL,   4536324697LL, 4528611450LL, 4520890329LL,
    4513161286LL, 4505424271LL, 4497679234LL,   4489926126LL, 4482164895LL, 4474395490LL,
    4466617860LL, 4458831954LL, 4451037718LL,   4443235101LL, 4435424050LL, 4427604511LL,
    4419776431LL, 4411939755LL, 4404094429LL,   4396240397LL, 4388377606LL, 4380505998LL,
    4372625517LL, 4364736107LL, 4356837711LL,   4348930271LL, 4341013728LL, 4333088025LL,
    4325153103LL, 4317208902LL, 4309255362LL,   4301292423LL, 4293320024LL, 4285338103LL,
    4277346599LL, 4269345450LL, 4261334592LL,   4253313962LL, 4245283496LL, 4237243130LL,
    4229192798LL, 4221132436LL, 4213061977LL,   4204981354LL, 4196890501LL, 4188789349LL,
    4180677830LL, 4172555875LL, 4164423415LL,   4156280379LL, 4148126698LL, 4139962298LL,
    4131787109LL, 4123601057LL, 4115404070LL,   4107196074LL, 4098976994LL, 4090746754LL,
    4082505279LL, 4074252492LL, 4065988316LL,   4057712674LL, 4049425485LL, 4041126671LL,
    4032816151LL, 4024493845LL, 4016159671LL,   4007813547LL, 3999455389LL, 3991085113LL,
    3982702635LL, 3974307868LL, 3965900727LL,   3957481125LL, 3949048972LL, 3940604181LL,
    3932146662LL, 3923676323LL, 3915193073LL,   3906696820LL, 3898187471LL, 3889664931LL,
    3881129104LL, 3872579895LL, 3864017207LL,   3855440940LL, 3846850997LL, 3838247277LL,
    3829629679LL, 3820998100LL, 3812352438LL,   3803692587LL, 3795018443LL, 3786329898LL,
    3777626846LL, 3768909177LL, 3760176781LL,   3751429548LL, 3742667364LL, 3733890116LL,
    3725097690LL, 3716289970LL, 3707466837LL,   3698628174LL, 3689773860LL, 3680903774LL,
    3672017794LL, 3663115795LL, 3654197653LL,   3645263240LL, 3636312428LL, 3627345088LL,
    3618361088LL, 3609360295LL, 3600342575LL,   3591307793LL, 3582255811LL, 3573186490LL,
    3564099688LL, 3554995265LL, 3545873075LL,   3536732973LL, 3527574812LL, 3518398442LL,
    3509203711LL, 3499990467LL, 3490758555LL,   3481507818LL, 3472238097LL, 3462949232LL,
    3453641059LL, 3444313413LL, 3434966129LL,   3425599035LL, 3416211962LL, 3406804736LL,
    3397377181LL, 3387929118LL, 3378460368LL,   3368970747LL, 3359460071LL, 3349928151LL,
    3340374797LL, 3330799817LL, 3321203015LL,   3311584193LL, 3301943150LL, 3292279682LL,
    3282593583LL, 3272884644LL, 3263152652LL,   3253397392LL, 3243618646LL, 3233816192LL,
    3223989805LL, 3214139257LL, 3204264318LL,   3194364751LL, 3184440320LL, 3174490783LL,
    3164515894LL, 3154515404LL, 3144489060LL,   3134436606LL, 3124357781LL, 3114252322LL,
    3104119958LL, 3093960417LL, 3083773422LL,   3073558691LL, 3063315939LL, 3053044875LL,
    3042745203LL, 3032416623LL, 3022058830LL,   3011671515LL, 3001254362LL, 2990807050LL,
    2980329255LL, 2969820643LL, 2959280880LL,   2948709621LL, 2938106518LL, 2927471216LL,
    2916803355LL, 2906102567LL, 2895368479LL,   2884600709LL, 2873798871LL, 2862962569LL,
    2852091403LL, 2841184963LL, 2830242833LL,   2819264588LL, 2808249796LL, 2797198017LL,
    2786108800LL, 2774981689LL, 2763816217LL,   3435973836LL, 2763816217LL, -7158278826LL,
    3446040166LL, 2746995038LL, -7195910830LL,  3456106496LL, 2730084828LL, -7234255391LL,
    3466172825LL, 2713083892LL, -7273334109LL,  3476239155LL, 2695990483LL, -7313169514LL,
    3486305484LL, 2678802801LL, -7353785116LL,  3496371814LL, 2661518987LL, -7395205463LL,
    3506438144LL, 2644137126LL, -7437456200LL,  3516504473LL, 2626655241LL, -7480564130LL,
    3526570803LL, 2609071290LL, -7524557286LL,  3536637132LL, 2591383165LL, -7569465004LL,
    3546703462LL, 2573588685LL, -7615317997LL,  3556769792LL, 2555685598LL, -7662148446LL,
    3566836121LL, 2537671574LL, -7709990087LL,  3576902451LL, 2519544202LL, -7758878307LL,
    3586968780LL, 2501300985LL, -7808850257LL,  3597035110LL, 2482939339LL, -7859944957LL,
    3607101440LL, 2464456584LL, -7912203426LL,  3617167769LL, 2445849943LL, -7965668811LL,
    3627234099LL, 2427116533LL, -8020386534LL,  3637300428LL, 2408253365LL, -8076404444LL,
    3647366758LL, 2389257332LL, -8133772992LL,  3657433088LL, 2370125207LL, -8192545412LL,
    3667499417LL, 2350853635LL, -8252777919LL,  3677565747LL, 2331439124LL, -8314529934LL,
    3687632076LL, 2311878040LL, -8377864315LL,  3697698406LL, 2292166597LL, -8442847622LL,
    3707764736LL, 2272300848LL, -8509550400LL,  3717831065LL, 2252276678LL, -8578047489LL,
    3727897395LL, 2232089787LL, -8648418368LL,  3737963724LL, 2211735687LL, -8720747534LL,
    3748030054LL, 2191209683LL, -8795124908LL,  3758096384LL, 2170506864LL, -8871646298LL,
    3768162713LL, 2149622086LL, -8950413902LL,  3778229043LL, 2128549959LL, -9031536865LL,
    3788295372LL, 2107284826LL, -9115131895LL,  3798361702LL, 2085820749LL, -9201323957LL,
    3808428032LL, 2064151487LL, -9290247031LL,  3818494361LL, 2042270471LL, -9382044973LL,
    3828560691LL, 2020170784LL, -9476872462LL,  3838627020LL, 1997845134LL, -9574896076LL,
    3848693350LL, 1975285822LL, -9676295491LL,  3858759680LL, 1952484711LL, -9781264835LL,
    3868826009LL, 1929433190LL, -9890014218LL,  3878892339LL, 1906122138LL, -10002771460LL,
    3888958668LL, 1882541875LL, -10119784062LL, 3899024998LL, 1858682116LL, -10241321441LL,
    3909091328LL, 1834531917LL, -10367677489LL, 3919157657LL, 1810079613LL, -10499173506LL,
    3929223987LL, 1785312751LL, -10636161579LL, 3939290316LL, 1760218014LL, -10779028471LL,
    3949356646LL, 1734781131LL, -10928200144LL, 3959422976LL, 1708986784LL, -11084147012LL,
    3969489305LL, 1682818493LL, -11247390088LL, 3979555635LL, 1656258492LL, -11418508196LL,
    3989621964LL, 1629287582LL, -11598146489LL, 3999688294LL, 1601884963LL, -11787026545LL,
    4009754624LL, 1574028044LL, -11985958409LL, 4019820953LL, 1545692220LL, -12195855039LL,
    4029887283LL, 1516850604LL, -12417749740LL, 4039953612LL, 1487473731LL, -12652817355LL,
    4050019942LL, 1457529188LL, -12902400191LL, 4060086272LL, 1426981192LL, -13168040007LL,
    4070152601LL, 1395790072LL, -13451517788LL, 4080218931LL, 1363911658LL, -13754903675LL,
    1363911658LL, 1362836647LL, 1361760816LL,   1360684162LL, 1359606686LL, 1358528383LL,
    1357449253LL, 1356369292LL, 1355288500LL,   1354206875LL, 1353124413LL, 1352041114LL,
    1350956975LL, 1349871994LL, 1348786170LL,   1347699500LL, 1346611981LL, 1345523613LL,
    1344434393LL, 1343344318LL, 1342253388LL,   1341161599LL, 1340068949LL, 1338975438LL,
    1337881061LL, 1336785818LL, 1335689706LL,   1334592723LL, 1333494867LL, 1332396135LL,
    1331296526LL, 1330196038LL, 1329094667LL,   1327992413LL, 1326889272LL, 1325785243LL,
    1324680323LL, 1323574510LL, 1322467802LL,   1321360196LL, 1320251691LL, 1319142284LL,
    1318031972LL, 1316920754LL, 1315808628LL,   1314695590LL, 1313581639LL, 1312466772LL,
    1311350986LL, 1310234281LL, 1309116652LL,   1307998099LL, 1306878618LL, 1305758206LL,
    1304636863LL, 1303514585LL, 1302391369LL,   1301267214LL, 1300142117LL, 1299016076LL,
    1297889087LL, 1296761149LL, 1295632260LL,   1294502415LL, 1293371614LL, 1292239854LL,
    1291107131LL, 1289973444LL, 1288838791LL,   1287703167LL, 1286566571LL, 1285429001LL,
    1284290453LL, 1283150926LL, 1282010415LL,   1280868920LL, 1279726437LL, 1278582963LL,
    1277438497LL, 1276293034LL, 1275146573LL,   1273999111LL, 1272850645LL, 1271701173LL,
    1270550691LL, 1269399197LL, 1268246688LL,   1267093161LL, 1265938614LL, 1264783044LL,
    1263626448LL, 1262468823LL, 1261310167LL,   1260150476LL, 1258989747LL, 1257827979LL,
    1256665167LL, 1255501309LL, 1254336402LL,   1253170444LL, 1252003430LL, 1250835359LL,
    1249666227LL, 1248496031LL, 1247324769LL,   1246152437LL, 1244979032LL, 1243804552LL,
    1242628992LL, 1241452351LL, 1240274624LL,   1239095810LL, 1237915904LL, 1236734905LL,
    1235552807LL, 1234369609LL, 1233185308LL,   1231999899LL, 1230813380LL, 1229625748LL,
    1228436999LL, 1227247130LL, 1226056138LL,   1224864020LL, 1223670772LL, 1222476391LL,
    1221280874LL, 1220084217LL, 1218886417LL,   1217687471LL, 1216487375LL, 1215286126LL,
    1214083720LL, 1212880154LL, 1211675424LL,   1210469527LL, 1209262460LL, 1208054219LL,
    1206844801LL, 1205634201LL, 1204422417LL,   1203209444LL, 1201995280LL, 1200779920LL,
    1199563361LL, 1198345599LL, 1197126631LL,   1195906453LL, 1194685061LL, 1193462451LL,
    1192238621LL, 1191013565LL, 1189787280LL,   1188559763LL, 1187331009LL, 1186101015LL,
    1184869777LL, 1183637290LL, 1182403552LL,   1181168558LL, 1179932304LL, 1178694786LL,
    1177456000LL, 1176215943LL, 1174974609LL,   1173731996LL, 1172488099LL, 1171242914LL,
    1169996437LL, 1168748663LL, 1167499589LL,   1166249210LL, 1164997523LL, 1163744522LL,
    1162490204LL, 1161234565LL, 1159977600LL,   1158719304LL, 1157459674LL, 1156198705LL,
    1154936393LL, 1153672733LL, 1152407721LL,   1151141352LL, 1149873623LL, 1148604527LL,
    1147334062LL, 1146062222LL, 1144789002LL,   1143514399LL, 1142238408LL, 1140961023LL,
    1139682240LL, 1138402055LL, 1137120462LL,   1135837457LL, 1134553036LL, 1133267193LL,
    1131979923LL, 1130691222LL, 1129401084LL,   1128109506LL, 1126816481LL, 1125522005LL,
    1124226073LL, 1122928679LL, 1121629820LL,   1120329488LL, 1119027681LL, 1117724391LL,
    1116419615LL, 1115113347LL, 1113805581LL,   1112496312LL, 1111185536LL, 1109873246LL,
    1108559438LL, 1107244105LL, 1105927243LL,   1104608846LL, 1103288909LL, 1101967425LL,
    1100644390LL, 1099319797LL, 1097993642LL,   1096665918LL, 1095336620LL, 1094005742LL,
    1092673278LL, 1091339223LL, 1090003570LL,   1088666314LL, 1087327448LL, 1085986968LL,
    1084644866LL, 1083301137LL, 1081955775LL,   1080608774LL, 1079260127LL, 1077909828LL,
    1076557872LL, 1075204251LL, 1073848960LL,   1072491992LL, 1071133341LL, 1069773001LL,
    1068410964LL, 1067047225LL, 1065681777LL,   1064314613LL, 1062945727LL, 1061575112LL,
    1060202761LL, 1058828668LL, 1057452826LL,   1056075227LL, 1054695866LL, 1053314735LL,
    1051931828LL, 1050547136LL, 1049160653LL,   1047772373LL, 1046382287LL, 1044990389LL,
    1043596672LL, 1042201127LL, 1040803748LL,   1039404528LL, 1038003458LL, 1036600532LL,
    1035195742LL, 1033789079LL, 1032380538LL,   1030970109LL, 1029557785LL, 1028143559LL,
    1026727422LL, 1025309367LL, 1023889385LL,   1022467469LL, 1021043610LL, 1019617800LL,
    1018190032LL, 1016760296LL, 1015328585LL,   1013894890LL, 1012459202LL, 1011021514LL,
    1009581817LL, 1008140102LL, 1006696360LL,   1005250582LL, 1003802761LL, 1002352887LL,
    1000900950LL, 999446943LL,  997990856LL,    996532680LL,  995072405LL,  993610023LL,
    992145524LL,  990678899LL,  989210138LL,    987739232LL,  986266171LL,  984790946LL,
    983313547LL,  981833963LL,  980352185LL,    978868204LL,  977382008LL,  975893589LL,
    974402935LL,  972910037LL,  971414883LL,    969917465LL,  968417771LL,  966915790LL,
    965411512LL,  963904926LL,  962396022LL,    960884788LL,  959371213LL,  957855287LL,
    956336997LL,  954816334LL,  953293285LL,    951767839LL,  950239984LL,  948709709LL,
    947177002LL,  945641852LL,  944104245LL,    942564172LL,  941021618LL,  939476572LL,
    937929022LL,  936378955LL,  934826359LL,    933271221LL,  931713528LL,  930153268LL,
    928590427LL,  927024993LL,  925456952LL,    923886291LL,  922312997LL,  920737056LL,
    919158455LL,  917577180LL,  915993216LL,    914406551LL,  912817169LL,  911225057LL,
    909630201LL,  908032585LL,  906432196LL,    904829018LL,  903223037LL,  901614238LL,
    900002605LL,  898388124LL,  896770779LL,    895150554LL,  893527434LL,  891901403LL,
    890272445LL,  888640545LL,  887005684LL,    885367848LL,  883727020LL,  882083183LL,
    880436320LL,  878786414LL,  877133449LL,    875477406LL,  873818268LL,  872156017LL,
    870490637LL,  868822108LL,  867150412LL,    865475532LL,  863797448LL,  862116142LL,
    860431596LL,  858743789LL,  857052702LL,    855358317LL,  853660614LL,  851959572LL,
    850255173LL,  848547394LL,  846836217LL,    845121619LL,  843403582LL,  841682083LL,
    839957101LL,  838228614LL,  836496602LL,    834761042LL,  833021911LL,  831279188LL,
    829532849LL,  827782872LL,  826029234LL,    824271912LL,  822510881LL,  820746118LL,
    818977599LL,  817205299LL,  815429193LL,    813649258LL,  811865467LL,  810077795LL,
    808286217LL,  806490706LL,  804691235LL,    802887780LL,  801080311LL,  799268803LL,
    797453228LL,  795633557LL,  793809763LL,    791981817LL,  790149691LL,  788313354LL,
    786472779LL,  784627934LL,  782778790LL,    780925316LL,  779067482LL,  777205255LL,
    775338605LL,  773467499LL,  771591905LL,    769711790LL,  767827121LL,  765937863LL,
    764043985LL,  762145450LL,  760242223LL,    758334270LL,  756421555LL,  754504042LL,
    752581693LL,  750654472LL,  748722342LL,    746785263LL,  744843197LL,  742896106LL,
    740943949LL,  738986687LL,  737024278LL,    735056682LL,  733083857LL,  731105760LL,
    729122349LL,  727133580LL,  725139409LL,    723139791LL,  721134681LL,  719124034LL,
    717107801LL,  715085937LL,  713058393LL,    711025121LL,  708986071LL,  706941194LL,
    704890438LL,  702833752LL,  700771085LL,    698702382LL,  696627591LL,  694546657LL,
    692459524LL,  690366135LL,  688266435LL,    686160365LL,  684047867LL,  681928879LL,
    679803343LL,  677671195LL,  675532374LL,    673386816LL,  671234457LL,  669075230LL,
    666909069LL,  664735907LL,  662555673LL,    660368300LL,  658173714LL,  655971843LL,
    653762615LL,  651545955LL,  649321785LL,    647090029LL,  644850608LL,  642603441LL,
    640348448LL,  638085545LL,  635814648LL,    633535671LL,  631248526LL,  628953124LL,
    626649375LL,  624337186LL,  622016463LL,    619687109LL,  617349028LL,  615002120LL,
    612646284LL,  610281415LL,  607907409LL,    607907409LL,  607371987LL,  606836096LL,
    606299735LL,  605762902LL,  605225595LL,    604687815LL,  604149559LL,  603610826LL,
    603071616LL,  602531926LL,  601991755LL,    601451102LL,  600909966LL,  600368345LL,
    599826239LL,  599283645LL,  598740563LL,    598196991LL,  597652928LL,  597108372LL,
    596563323LL,  596017778LL,  595471736LL,    594925197LL,  594378158LL,  593830619LL,
    593282578LL,  592734033LL,  592184983LL,    591635427LL,  591085363LL,  590534790LL,
    589983706LL,  589432111LL,  588880002LL,    588327378LL,  587774238LL,  587220580LL,
    586666403LL,  586111705LL,  585556485LL,    585000741LL,  584444472LL,  583887677LL,
    583330353LL,  582772500LL,  582214115LL,    581655197LL,  581095746LL,  580535758LL,
    579975233LL,  579414169LL,  578852565LL,    578290418LL,  577727728LL,  577164493LL,
    576600710LL,  576036380LL,  575471499LL,    574906066LL,  574340080LL,  573773539LL,
    573206442LL,  572638786LL,  572070570LL,    571501793LL,  570932453LL,  570362547LL,
    569792075LL,  569221034LL,  568649424LL,    568077241LL,  567504485LL,  566931154LL,
    566357246LL,  565782759LL,  565207691LL,    564632042LL,  564055808LL,  563478988LL,
    562901580LL,  562323583LL,  561744995LL,    561165814LL,  560586037LL,  560005664LL,
    559424692LL,  558843120LL,  558260945LL,    557678165LL,  557094780LL,  556510786LL,
    555926183LL,  555340967LL,  554755138LL,    554168692LL,  553581629LL,  552993946LL,
    552405642LL,  551816713LL,  551227159LL,    550636977LL,  550046166LL,  549454722LL,
    548862645LL,  548269932LL,  547676581LL,    547082589LL,  546487956LL,  545892679LL,
    545296755LL,  544700182LL,  544102960LL,    543505084LL,  542906553LL,  542307366LL,
    541707519LL,  541107011LL,  540505839LL,    539904001LL,  539301495LL,  538698319LL,
    538094471LL,  537489947LL,  536884746LL,    536278866LL,  535672304LL,  535065059LL,
    534457126LL,  533848505LL,  533239193LL,    532629188LL,  532018487LL,  531407087LL,
    530794987LL,  530182184LL,  529568675LL,    528954459LL,  528339531LL,  527723891LL,
    527107536LL,  526490463LL,  525872669LL,    525254152LL,  524634909LL,  524014939LL,
    523394238LL,  522772803LL,  522150633LL,    521527724LL,  520904073LL,  520279679LL,
    519654538LL,  519028648LL,  518402006LL,    517774610LL,  517146456LL,  516517541LL,
    515887864LL,  515257421LL,  514626209LL,    513994226LL,  513361468LL,  512727934LL,
    512093619LL,  511458521LL,  510822638LL,    510185966LL,  509548501LL,  508910243LL,
    508271186LL,  507631329LL,  506990668LL,    506349200LL,  505706922LL,  505063831LL,
    504419925LL,  503775198LL,  503129650LL,    502483276LL,  501836073LL,  501188039LL,
    500539169LL,  499889460LL,  499238910LL,    498587515LL,  497935272LL,  497282177LL,
    496628227LL,  495973419LL,  495317749LL,    494661213LL,  494003809LL,  493345533LL,
    492686381LL,  492026350LL,  491365437LL,    490703637LL,  490040947LL,  489377363LL,
    488712883LL,  488047502LL,  487381216LL,    486714022LL,  486045916LL,  485376895LL,
    484706954LL,  484036090LL,  483364298LL,    482691576LL,  482017919LL,  481343322LL,
    480667783LL,  479991298LL,  479313861LL,    478635470LL,  477956120LL,  477275806LL,
    476594526LL,  475912274LL,  475229047LL,    474544841LL,  473859650LL,  473173471LL,
    472486300LL,  471798132LL,  471108963LL,    470418788LL,  469727603LL,  469035404LL,
    468342186LL,  467647944LL,  466952674LL,    466256372LL,  465559032LL,  464860650LL,
    464161222LL,  463460742LL,  462759206LL,    462056609LL,  461352946LL,  460648212LL,
    459942403LL,  459235513LL,  458527537LL,    457818471LL,  457108309LL,  456397046LL,
    455684677LL,  454971197LL,  454256601LL,    453540883LL,  452824038LL,  452106060LL,
    451386945LL,  450666686LL,  449945279LL,    449222718LL,  448498996LL,  447774110LL,
    447048052LL,  446320817LL,  445592399LL,    444862794LL,  444131993LL,  443399993LL,
    442666787LL,  441932368LL,  441196731LL,    440459870LL,  439721779LL,  438982451LL,
    438241880LL,  437500059LL,  436756984LL,    436012646LL,  435267039LL,  434520158LL,
    433771995LL,  433022544LL,  432271798LL,    431519750LL,  430766393LL,  430011721LL,
    429255727LL,  428498404LL,  427739744LL,    426979741LL,  426218386LL,  425455674LL,
    424691597LL,  423926147LL,  423159317LL,    422391099LL,  421621486LL,  420850470LL,
    420078044LL,  419304199LL,  418528928LL,    417752223LL,  416974075LL,  416194478LL,
    415413422LL,  414630899LL,  413846901LL,    413061419LL,  412274446LL,  411485972LL,
    410695990LL,  409904489LL,  409111462LL,    408316899LL,  407520792LL,  406723131LL,
    405923907LL,  405123111LL,  404320734LL,    403516767LL,  402711199LL,  401904021LL,
    401095223LL,  400284796LL,  399472730LL,    398659014LL,  397843638LL,  397026593LL,
    396207868LL,  395387453LL,  394565336LL,    393741508LL,  392915957LL,  392088673LL,
    391259644LL,  390428860LL,  389596310LL,    388761981LL,  387925863LL,  387087943LL,
    386248211LL,  385406654LL,  384563261LL,    383718019LL,  382870915LL,  382021939LL,
    381171076LL,  380318315LL,  379463643LL,    378607046LL,  377748512LL,  376888027LL,
    376025578LL,  375161152LL,  374294734LL,    373426311LL,  372555869LL,  371683394LL,
    370808870LL,  369932285LL,  369053623LL,    368172869LL,  367290008LL,  366405025LL,
    365517905LL,  364628631LL,  363737189LL,    362843562LL,  361947734LL,  361049688LL,
    360149408LL,  359246878LL,  358342080LL,    357434996LL,  356525610LL,  355613905LL,
    354699861LL,  353783460LL,  352864686LL,    351943518LL,  351019938LL,  350093928LL,
    349165467LL,  348234535LL,  347301114LL,    346365184LL,  345426722LL,  344485710LL,
    343542126LL,  342595948LL,  341647156LL,    340695726LL,  339741639LL,  338784869LL,
    337825396LL,  336863196LL,  335898245LL,    334930519LL,  333959996LL,  332986649LL,
    332010454LL,  331031387LL,  330049420LL,    329064530LL,  328076688LL,  327085869LL,
    326092045LL,  325095189LL,  324095273LL,    323092268LL,  322086146LL,  321076876LL,
    320064431LL,  319048778LL,  318029888LL,    317007728LL,  315982269LL,  314953477LL,
    313921319LL,  312885762LL,  311846773LL,    310804317LL,  309758358LL,  308708862LL,
    307655792LL,  306599111LL,  305538782LL,    304474767LL,  303407026LL,  302335521LL,
    301260212LL,  300181056LL,  299098014LL,    298011042LL,  296920097LL,  295825135LL,
    294726112LL,  293622982LL,  292515698LL,    291404213LL,  290288479LL,  289168447LL,
    288044066LL,  286915286LL,  285782053LL,    284644316LL,  283502020LL,  282355109LL,
    281203528LL,  280047217LL,  278886120LL,    277720175LL,  276549321LL,  275373495LL,
    274192635LL,  273006674LL,  271815545LL,    270619181LL,  269417511LL,  268210464LL,
    266997968LL,  265779948LL,  264556327LL,    263327028LL,  262091970LL,  260851071LL,
    259604249LL,  258351417LL,  257092487LL,    255827370LL,  254555972LL,  253278200LL,
    251993957LL,  250703142LL,  249405655LL,    248101390LL,  246790240LL,  245472094LL,
    244146840LL,  242814360LL,  241474536LL,    240127244LL,  238772358LL,  237409747LL,
    236039279LL,  234660816LL,  233274215LL,    231879330LL,  230476012LL,  229064105LL,
    227643450LL,  226213882LL,  224775230LL,    223327319LL,  221869968LL,  220402989LL,
    218926189LL,  217439369LL,  215942320LL,    214434829LL,  212916673LL,  211387624LL,
    209847443LL,  208295883LL,  206732687LL,    205157591LL,  203570317LL,  201970579LL,
    200358077LL,  198732502LL,  197093530LL,    195440823LL,  193774031LL,  192092786LL,
    192092786LL,  191717175LL,  191340828LL,    190963739LL,  190585905LL,  190207320LL,
    189827981LL,  189447883LL,  189067021LL,    188685391LL,  188302988LL,  187919808LL,
    187535845LL,  187151095LL,  186765552LL,    186379213LL,  185992071LL,  185604123LL,
    185215363LL,  184825785LL,  184435385LL,    184044157LL,  183652097LL,  183259198LL,
    182865455LL,  182470864LL,  182075417LL,    181679111LL,  181281939LL,  180883895LL,
    180484973LL,  180085169LL,  179684476LL,    179282887LL,  178880398LL,  178477001LL,
    178072691LL,  177667462LL,  177261306LL,    176854219LL,  176446193LL,  176037221LL,
    175627298LL,  175216416LL,  174804569LL,    174391750LL,  173977952LL,  173563168LL,
    173147391LL,  172730614LL,  172312829LL,    171894029LL,  171474207LL,  171053355LL,
    170631466LL,  170208531LL,  169784544LL,    169359495LL,  168933378LL,  168506184LL,
    168077904LL,  167648531LL,  167218056LL,    166786470LL,  166353766LL,  165919933LL,
    165484964LL,  165048849LL,  164611579LL,    164173145LL,  163733538LL,  163292748LL,
    162850765LL,  162407580LL,  161963183LL,    161517563LL,  161070712LL,  160622618LL,
    160173271LL,  159722660LL,  159270775LL,    158817605LL,  158363139LL,  157907365LL,
    157450273LL,  156991850LL,  156532086LL,    156070967LL,  155608483LL,  155144621LL,
    154679368LL,  154212713LL,  153744641LL,    153275141LL,  152804198LL,  152331801LL,
    151857934LL,  151382585LL,  150905739LL,    150427383LL,  149947500LL,  149466078LL,
    148983101LL,  148498553LL,  148012420LL,    147524686LL,  147035334LL,  146544349LL,
    146051714LL,  145557412LL,  145061427LL,    144563741LL,  144064336LL,  143563194LL,
    143060298LL,  142555628LL,  142049166LL,    141540892LL,  141030787LL,  140518831LL,
    140005004LL,  139489284LL,  138971652LL,    138452085LL,  137930561LL,  137407059LL,
    136881555LL,  136354027LL,  135824451LL,    135292802LL,  134759057LL,  134223189LL,
    133685175LL,  133144987LL,  132602600LL,    132057985LL,  131511116LL,  130961964LL,
    130410501LL,  129856696LL,  129300520LL,    128741941LL,  128180930LL,  127617453LL,
    127051478LL,  126482971LL,  125911898LL,    125338223LL,  124761912LL,  124182927LL,
    123601230LL,  123016784LL,  122429549LL,    121839484LL,  121246548LL,  120650699LL,
    120051893LL,  119450087LL,  118845233LL,    118237287LL,  117626199LL,  117011921LL,
    116394401LL,  115773589LL,  115149431LL,    114521871LL,  113890855LL,  113256324LL,
    112618218LL,  111976477LL,  111331038LL,    110681836LL,  110028804LL,  109371874LL,
    108710976LL,  108046035LL,  107376978LL,    106703727LL,  106026202LL,  105344320LL,
    104657996LL,  103967143LL,  103271669LL,    102571481LL,  101866481LL,  101156568LL,
    100441639LL,  99721585LL,   98996296LL,     98265654LL,   97529539LL,   96787828LL,
    96040389LL,   95287088LL,   94527786LL,     93762335LL,   92990585LL,   92212378LL,
    91427548LL,   90635923LL,   89837324LL,     89031562LL,   88218443LL,   87397760LL,
    86569298LL,   85732832LL,   84888126LL,     84034930LL,   83172983LL,   82302011LL,
    81421724LL,   80531816LL,   79631965LL,     78721830LL,   77801050LL,   76869242LL,
    75926001LL,   74970894LL,   74003463LL,     73023218LL,   72029635LL,   71022155LL,
    70000177LL,   68963058LL,   67910103LL,     66840564LL,   65753631LL,   64648428LL,
    63524001LL,   62379311LL,   61213220LL,     60024481LL,   58811721LL,   57573422LL,
    56307899LL,   55013274LL,   53687440LL,     52328027LL,   50932345LL,   49497326LL,
    48019444LL,   46494611LL,   44918047LL,     43284099LL,   41586004LL,   39815555LL,
    37962629LL,   36014501LL,   33954786LL,     31761783LL,   29405688LL,   26843589LL,
    24009628LL,   20792941LL,   16977359LL,     12004802LL,   0LL,
};

/**
 * @brief Calculate arc-cosine
 * @param x Input in fixed-point format, must be in range [-1, 1]
 * @return Fixed-point arc-cosine value in radians
 */
inline constexpr auto LookupAcos(int64_t x) noexcept -> int64_t {
    // Precision definitions
    constexpr int TABLE_PRECISION = 12;  // Lookup table precision (4096 = 2^12)
    constexpr int FRACTION_BITS = 32;    // Q31.32 format precision

    // Q31.32 format constants
    constexpr int64_t ONE = 1LL << FRACTION_BITS;
    constexpr int64_t PI = 13493037705LL;  // π * 2^32

    // Define interval boundary constants
    constexpr int64_t THRESHOLD_0_8 = ONE * 4LL / 5LL;         // 0.8
    constexpr int64_t THRESHOLD_0_95 = ONE * 19LL / 20LL;      // 0.95
    constexpr int64_t THRESHOLD_0_99 = ONE * 99LL / 100LL;     // 0.99
    constexpr int64_t THRESHOLD_0_999 = ONE * 999LL / 1000LL;  // 0.999
    constexpr int64_t THRESHOLD_SMALL = ONE - (ONE >> 16);     // 0.999984741211

    // Boundary check: ensure input is within [-ONE, ONE] range
    if (x >= ONE)
        return 0;
    if (x <= -ONE)
        return PI;

    bool is_negative = x < 0;
    x = is_negative ? -x : x;

    // Handle extremely small angles: x > 0.999984741211, use sqrt(2(1-x)) approximation
    if (x > THRESHOLD_SMALL) {
        int64_t epsilon = ONE - x;
        int64_t sqrt_input = (epsilon << 1);
        return Primitives::Fixed64SqrtFast(sqrt_input, FRACTION_BITS);
    }

    int64_t result;
    // Region 1: [0, 0.8], use 512-point uniform interpolation
    if (x < THRESHOLD_0_8) {
        int index = (x << 9) / THRESHOLD_0_8;  // x * 512 / (0.8 * ONE)
        index = std::min(index, 511);

        // Calculate interpolation
        int64_t x0 = (index * THRESHOLD_0_8) >> 9;  // index * 0.8 * ONE / 512
        int64_t dx = x - x0;
        constexpr int64_t delta = THRESHOLD_0_8 >> 9;  // 0.8 * ONE / 512
        result = kAcosLut[index] + ((kAcosLut[index + 1] - kAcosLut[index]) * dx) / delta;
    }
    // Region 2: [0.8, 0.95], use 64-segment cubic spline interpolation
    else if (x < THRESHOLD_0_95) {
        int seg = ((x - (THRESHOLD_0_8)) * 64LL) / (ONE * 3LL / 20LL);  // (x - 0.8) / (0.15/64)
        seg = std::min(seg, 63);

        int base_idx = 513 + seg * 3;
        int64_t x0 = kAcosLut[base_idx];
        int64_t y0 = kAcosLut[base_idx + 1];
        int64_t dydx = kAcosLut[base_idx + 2];

        int64_t dx = x - x0;
        result = y0 + ((dydx * dx) >> FRACTION_BITS);
    }
    // Region 3: [0.95, 0.99], use 512-point linear interpolation
    else if (x < THRESHOLD_0_99) {
        int base_idx = 513 + 195;              // 512 + 1 + 65*3
        int64_t rel_x = x - (THRESHOLD_0_95);  // x - 0.95
        int64_t scale = (ONE * 4LL / 100LL);   // 0.04 * ONE

        int index = (rel_x * 512LL) / scale;
        index = std::min(index, 511);

        int idx = base_idx + index;
        int64_t x1 = (THRESHOLD_0_95) + (scale * index) / 512LL;
        int64_t x2 = (THRESHOLD_0_95) + (scale * (index + 1)) / 512LL;

        int64_t alpha = ((x - x1) << FRACTION_BITS) / (x2 - x1);
        result = ((kAcosLut[idx] * (ONE - alpha)) + (kAcosLut[idx + 1] * alpha)) >> FRACTION_BITS;
    }
    // Region 4: [0.99, 0.999], use 512-point linear interpolation
    else if (x < THRESHOLD_0_999) {
        int base_idx = 513 + 195 + 513;
        int64_t rel_x = x - (THRESHOLD_0_99);  // x - 0.99
        int64_t scale = (ONE * 9LL / 1000LL);  // 0.009 * ONE

        int index = (rel_x * 512LL) / scale;
        index = std::min(index, 511);

        int idx = base_idx + index;
        int64_t x1 = (THRESHOLD_0_99) + (scale * index) / 512LL;
        int64_t x2 = (THRESHOLD_0_99) + (scale * (index + 1)) / 512LL;

        int64_t alpha = ((x - x1) << FRACTION_BITS) / (x2 - x1);
        result = ((kAcosLut[idx] * (ONE - alpha)) + (kAcosLut[idx + 1] * alpha)) >> FRACTION_BITS;
    }
    // Region 5: [0.999, 1.0), use 256-point linear interpolation
    else {
        int base_idx = 513 + 195 + 513 + 513;
        int64_t rel_x = x - (THRESHOLD_0_999);  // x - 0.999
        int64_t scale = ONE / 1000LL;           // 0.001 * ONE

        int index = (rel_x * 256LL) / scale;
        index = std::min(index, 255);

        int idx = base_idx + index;
        int64_t x1 = (THRESHOLD_0_999) + (scale * index) / 256LL;
        int64_t x2 = (THRESHOLD_0_999) + (scale * (index + 1)) / 256LL;

        int64_t alpha = ((x - x1) << FRACTION_BITS) / (x2 - x1);
        result = ((kAcosLut[idx] * (ONE - alpha)) + (kAcosLut[idx + 1] * alpha)) >> FRACTION_BITS;
    }

    return is_negative ? (PI - result) : result;
}

// NOLINTEND
}  // namespace math::fp::detail
