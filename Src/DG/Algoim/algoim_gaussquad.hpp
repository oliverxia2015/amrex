#ifndef ALGOIM_GAUSSQUAD_HPP
#define ALGOIM_GAUSSQUAD_HPP

// One-dimensional Gaussian quadrature schemes of degree 1 through 10.

#include <cassert>
#include "algoim_real.hpp"

namespace Algoim
{
    // Gaussian quadrature schemes for the interval [0,1] of node count p, 1 <= p <= 10.
    struct GaussQuad
    {
        // Corresponding to the degree p Gaussian quadrature scheme for the interval [0,1], position of node i, 0 <= i < p.
        static Real x(int p, int i)
        {
            assert(1 <= p && p <= 10 && 0 <= i && i < p);

            #ifndef ALGOIM_HPREAL
            // At least 37 digits of accuracy (could potentially use with IEEE754 binary128 if the compiler supported it)
            static const double data[(11*10)/2] = 
            {
                0.5,
                0.211324865405187117745425609749021272176, 0.788675134594812882254574390250978727824,
                0.112701665379258311482073460021760038917, 0.50000000000000000000000000000000000000, 0.88729833462074168851792653997823996108,
                0.069431844202973712388026755553595247452, 0.33000947820757186759866712044837765640, 0.66999052179242813240133287955162234360, 0.93056815579702628761197324444640475255,
                0.046910077030668003601186560850303517437, 0.23076534494715845448184278964989559752, 0.50000000000000000000000000000000000000, 0.76923465505284154551815721035010440248, 0.95308992296933199639881343914969648256,
                0.033765242898423986093849222753002695433, 0.16939530676686774316930020249004732650, 0.38069040695840154568474913915964403229, 0.61930959304159845431525086084035596771, 0.83060469323313225683069979750995267350, 0.96623475710157601390615077724699730457,
                0.02544604382862073773690515797607436879961, 0.1292344072003027800680676133596057964629, 0.2970774243113014165466967939615192683263, 0.5000000000000000000000000000000000000000, 0.7029225756886985834533032060384807316737, 0.8707655927996972199319323866403942035371, 0.9745539561713792622630948420239256312004,
                0.01985507175123188415821956571526350478588, 0.1016667612931866302042230317620847815814, 0.2372337950418355070911304754053768254790, 0.4082826787521750975302619288199080096666, 0.5917173212478249024697380711800919903334, 0.7627662049581644929088695245946231745210, 0.8983332387068133697957769682379152184186, 0.9801449282487681158417804342847364952141,
                0.01591988024618695508221189854816356497530, 0.08198444633668210285028510596513256172795, 0.1933142836497048013456489803292629076071, 0.3378732882980955354807309926783316957140, 0.5000000000000000000000000000000000000000, 0.6621267117019044645192690073216683042860, 0.8066857163502951986543510196707370923929, 0.9180155536633178971497148940348674382721, 0.9840801197538130449177881014518364350247,
                0.01304673574141413996101799395777397328587, 0.06746831665550774463395165578825347573623, 0.1602952158504877968828363174425632121154, 0.2833023029353764046003670284171079189000, 0.4255628305091843945575869994351400076912, 0.5744371694908156054424130005648599923088, 0.7166976970646235953996329715828920811000, 0.8397047841495122031171636825574367878846, 0.9325316833444922553660483442117465242638, 0.9869532642585858600389820060422260267141
            };
            #else
            // 69 digits of accuracy, suitable for double-double or quadruple-double precision implemented by QD library
            static const Real data[(11*10)/2] =
            {
                "0.5000000000000000000000000000000000000000000000000000000000000000000000",
                "0.2113248654051871177454256097490212721761991243649365619906988367580112",
                "0.7886751345948128822545743902509787278238008756350634380093011632419888",
                "0.1127016653792583114820734600217600389167078294708409173412426233886517",
                "0.5000000000000000000000000000000000000000000000000000000000000000000000",
                "0.8872983346207416885179265399782399610832921705291590826587573766113483",
                "0.06943184420297371238802675555359524745213731018514118119213903954673526",
                "0.3300094782075718675986671204483776563997120651145428237035230115894900",
                "0.6699905217924281324013328795516223436002879348854571762964769884105100",
                "0.9305681557970262876119732444464047525478626898148588188078609604532647",
                "0.04691007703066800360118656085030351743717404461873456856311885672811460",
                "0.2307653449471584544818427896498955975163566965472200218988841864702644",
                "0.5000000000000000000000000000000000000000000000000000000000000000000000",
                "0.7692346550528415455181572103501044024836433034527799781011158135297356",
                "0.9530899229693319963988134391496964825628259553812654314368811432718854",
                "0.03376524289842398609384922275300269543261713114385508756372519173669325",
                "0.1693953067668677431693002024900473264967757178024149645927366470739083",
                "0.3806904069584015456847491391596440322906946849299893249093024177128625",
                "0.6193095930415984543152508608403559677093053150700106750906975822871375",
                "0.8306046932331322568306997975099526735032242821975850354072633529260917",
                "0.9662347571015760139061507772469973045673828688561449124362748082633068",
                "0.02544604382862073773690515797607436879961453116469110822561544804346833",
                "0.1292344072003027800680676133596057964629261764293048699400223240162851",
                "0.2970774243113014165466967939615192683263089929503149368064783741026681",
                "0.5000000000000000000000000000000000000000000000000000000000000000000000",
                "0.7029225756886985834533032060384807316736910070496850631935216258973319",
                "0.8707655927996972199319323866403942035370738235706951300599776759837149",
                "0.9745539561713792622630948420239256312003854688353088917743845519565317",
                "0.01985507175123188415821956571526350478588238284927398086418011131378755",
                "0.1016667612931866302042230317620847815814141341920175839649148524803913",
                "0.2372337950418355070911304754053768254790178784398035711245714503637726",
                "0.4082826787521750975302619288199080096666210935435131088414057631503978",
                "0.5917173212478249024697380711800919903333789064564868911585942368496022",
                "0.7627662049581644929088695245946231745209821215601964288754285496362274",
                "0.8983332387068133697957769682379152184185858658079824160350851475196087",
                "0.9801449282487681158417804342847364952141176171507260191358198886862124",
                "0.01591988024618695508221189854816356497529759975403733522498834407545981",
                "0.08198444633668210285028510596513256172794664093766200194781401018027250",
                "0.1933142836497048013456489803292629076071396975297176535635935288593663",
                "0.3378732882980955354807309926783316957140218696315134555864762615789067",
                "0.5000000000000000000000000000000000000000000000000000000000000000000000",
                "0.6621267117019044645192690073216683042859781303684865444135237384210933",
                "0.8066857163502951986543510196707370923928603024702823464364064711406337",
                "0.9180155536633178971497148940348674382720533590623379980521859898197275",
                "0.9840801197538130449177881014518364350247024002459626647750116559245402",
                "0.01304673574141413996101799395777397328586502665380894038439396665170240",
                "0.06746831665550774463395165578825347573622849251733477373902013407731262",
                "0.1602952158504877968828363174425632121153526440825952661675914055237207",
                "0.2833023029353764046003670284171079188999640811718767517486492434281165",
                "0.4255628305091843945575869994351400076912175702896541521460053732420482",
                "0.5744371694908156054424130005648599923087824297103458478539946267579518",
                "0.7166976970646235953996329715828920811000359188281232482513507565718835",
                "0.8397047841495122031171636825574367878846473559174047338324085944762793",
                "0.9325316833444922553660483442117465242637715074826652262609798659226874",
                "0.9869532642585858600389820060422260267141349733461910596156060333482976"
            };
            #endif
            return data[(p*(p-1))/2 + i];
        }

        // Corresponding to the degree p Gaussian quadrature scheme for the interval [0,1], weight of node i, 0 <= i < p.
        static Real w(int p, int i)
        {
            assert(1 <= p && p <= 10 && 0 <= i && i < p);

            #ifndef ALGOIM_HPREAL
            // At least 37 digits of accuracy (could potentially use with IEEE754 binary128 if the compiler supported it)
            static const double data[(11*10)/2] =
            {
                1.0,
                0.5, 0.5,
                0.277777777777777777777777777777777777778, 0.444444444444444444444444444444444444444, 0.277777777777777777777777777777777777778,
                0.173927422568726928686531974610999703618, 0.326072577431273071313468025389000296382, 0.326072577431273071313468025389000296382, 0.173927422568726928686531974610999703618,
                0.118463442528094543757132020359958681322, 0.239314335249683234020645757417819096456, 0.284444444444444444444444444444444444444, 0.239314335249683234020645757417819096456, 0.118463442528094543757132020359958681322,
                0.085662246189585172520148071086366446763, 0.180380786524069303784916756918858055831, 0.233956967286345523694935171994775497406, 0.233956967286345523694935171994775497406, 0.180380786524069303784916756918858055831, 0.085662246189585172520148071086366446763,
                0.06474248308443484663530571633954100916429, 0.1398526957446383339507338857118897912435, 0.1909150252525594724751848877444875669392, 0.2089795918367346938775510204081632653061, 0.1909150252525594724751848877444875669392, 0.1398526957446383339507338857118897912435, 0.06474248308443484663530571633954100916429,
                0.05061426814518812957626567715498109505770, 0.1111905172266872352721779972131204422151, 0.1568533229389436436689811009933006566302, 0.1813418916891809914825752246385978060971, 0.1813418916891809914825752246385978060971, 0.1568533229389436436689811009933006566302, 0.1111905172266872352721779972131204422151, 0.05061426814518812957626567715498109505770,
                0.04063719418078720598594607905526182533783, 0.09032408034742870202923601562145640475717, 0.1303053482014677311593714347093164248859, 0.1561735385200014200343152032922218327994, 0.1651196775006298815822625346434870244394, 0.1561735385200014200343152032922218327994, 0.1303053482014677311593714347093164248859, 0.09032408034742870202923601562145640475717, 0.04063719418078720598594607905526182533783,
                0.03333567215434406879678440494666589642893, 0.07472567457529029657288816982884866620128, 0.1095431812579910219977674671140815962294, 0.1346333596549981775456134607847346764299, 0.1477621123573764350869464973256691647105, 0.1477621123573764350869464973256691647105, 0.1346333596549981775456134607847346764299, 0.1095431812579910219977674671140815962294, 0.07472567457529029657288816982884866620128, 0.03333567215434406879678440494666589642893,
            };
            #else
            // 69 digits of accuracy, suitable for double-double or quadruple-double precision implemented by QD library
            static const Real data[(11*10)/2] =
            {
                "1.0000000000000000000000000000000000000000000000000000000000000000000000",
                "0.5000000000000000000000000000000000000000000000000000000000000000000000",
                "0.5000000000000000000000000000000000000000000000000000000000000000000000",
                "0.2777777777777777777777777777777777777777777777777777777777777777777778",
                "0.4444444444444444444444444444444444444444444444444444444444444444444444",
                "0.2777777777777777777777777777777777777777777777777777777777777777777778",
                "0.1739274225687269286865319746109997036176743479169467702462646597593759",
                "0.3260725774312730713134680253890002963823256520830532297537353402406241",
                "0.3260725774312730713134680253890002963823256520830532297537353402406241",
                "0.1739274225687269286865319746109997036176743479169467702462646597593759",
                "0.1184634425280945437571320203599586813216300011062070077914139441108586",
                "0.2393143352496832340206457574178190964561477766715707699863638336669191",
                "0.2844444444444444444444444444444444444444444444444444444444444444444444",
                "0.2393143352496832340206457574178190964561477766715707699863638336669191",
                "0.1184634425280945437571320203599586813216300011062070077914139441108586",
                "0.08566224618958517252014807108636644676341125074202199119931771989947288",
                "0.1803807865240693037849167569188580558307609463733727411448696201185700",
                "0.2339569672863455236949351719947754974058278028846052676558126599819571",
                "0.2339569672863455236949351719947754974058278028846052676558126599819571",
                "0.1803807865240693037849167569188580558307609463733727411448696201185700",
                "0.08566224618958517252014807108636644676341125074202199119931771989947288",
                "0.06474248308443484663530571633954100916429370112997333198860431936232762",
                "0.1398526957446383339507338857118897912434625326132993822685070163468094",
                "0.1909150252525594724751848877444875669391825417669313673755417255153528",
                "0.2089795918367346938775510204081632653061224489795918367346938775510204",
                "0.1909150252525594724751848877444875669391825417669313673755417255153528",
                "0.1398526957446383339507338857118897912434625326132993822685070163468094",
                "0.06474248308443484663530571633954100916429370112997333198860431936232762",
                "0.05061426814518812957626567715498109505769704552584247852950184903237009",
                "0.1111905172266872352721779972131204422150654350256247823629546446468084",
                "0.1568533229389436436689811009933006566301644995013674688451319725374781",
                "0.1813418916891809914825752246385978060970730199471652702624115337833434",
                "0.1813418916891809914825752246385978060970730199471652702624115337833434",
                "0.1568533229389436436689811009933006566301644995013674688451319725374781",
                "0.1111905172266872352721779972131204422150654350256247823629546446468084",
                "0.05061426814518812957626567715498109505769704552584247852950184903237009",
                "0.04063719418078720598594607905526182533783086039120537535555383844034334",
                "0.09032408034742870202923601562145640475716891086602024224916795323567865",
                "0.1303053482014677311593714347093164248859201022186499759699985010598054",
                "0.1561735385200014200343152032922218327993774306309523227770055827995719",
                "0.1651196775006298815822625346434870244394053917863441672965482489292013",
                "0.1561735385200014200343152032922218327993774306309523227770055827995719",
                "0.1303053482014677311593714347093164248859201022186499759699985010598054",
                "0.09032408034742870202923601562145640475716891086602024224916795323567865",
                "0.04063719418078720598594607905526182533783086039120537535555383844034334",
                "0.03333567215434406879678440494666589642893241716007907256434744080670603",
                "0.07472567457529029657288816982884866620127831983471368391773863437661933",
                "0.1095431812579910219977674671140815962293859352613385449404782718176000",
                "0.1346333596549981775456134607847346764298799692304418979002816381210767",
                "0.1477621123573764350869464973256691647105233585134268006771540148779980",
                "0.1477621123573764350869464973256691647105233585134268006771540148779980",
                "0.1346333596549981775456134607847346764298799692304418979002816381210767",
                "0.1095431812579910219977674671140815962293859352613385449404782718176000",
                "0.07472567457529029657288816982884866620127831983471368391773863437661933",
                "0.03333567215434406879678440494666589642893241716007907256434744080670603"
            };
            #endif
            return data[(p*(p-1))/2 + i];
        }
    };

    // Gaussian-Lobatto quadrature schemes for the interval [0,1] of node count p, 1 <= p <= 10.
    struct GaussLobattoQuad
    {
        static Real x(int p, int i)
        {
            assert(1 <= p && p <= 10 && 0 <= i && i < p);

            static const double data[(11*10)/2] = 
            {
                0.0,
                -1.0, 1.0,
                -1.0, 0.0, 1.0,
                -1.0, -0.4472135954999579, 0.4472135954999579, 1.0,
                -1.0, -0.6546536707079771, 0.0, 0.6546536707079771, 1.0,
                -1.0, -0.7650553239294647, -0.2852315164806451, 0.2852315164806451, 0.7650553239294647, 1.0,
                -1.0, -0.8302238962785669, -0.4688487934707142, 0.0, 0.4688487934707142, 0.8302238962785669, 1.0,
                -1.0, -0.8717401485096066, -0.5917001814331423, -0.2092992179024789, 0.2092992179024789, 0.5917001814331423, 0.8717401485096066, 1.0,
                -1.0, -0.8997579954114602, -0.6771862795107378, -0.3631174638261782, 0.0, 0.3631174638261782, 0.6771862795107378, 0.8997579954114602, 1.0,
                -1.0, -0.9195339081664588, -0.7387738651055051, -0.4779249498104445, -0.1652789576663870, 0.1652789576663870, 0.4779249498104445, 0.7387738651055051, 0.9195339081664588, 1.0,
            };
            return 0.5*(data[(p*(p-1))/2 + i]+1.0);
        }

        static Real w(int p, int i)
        {
            assert(1 <= p && p <= 10 && 0 <= i && i < p);

            static const double data[(11*10)/2] =
            {
                2.0,
                1.0, 1.0,
                0.3333333333333333, 1.333333333333333, 0.3333333333333333,
                0.1666666666666667, 0.8333333333333333, 0.8333333333333333, 0.1666666666666667,
                0.1, 0.5444444444444444, 0.7111111111111111, 0.5444444444444444, 0.1,
                0.06666666666666667, 0.3784749562978470, 0.5548583770354863, 0.5548583770354863, 0.3784749562978470, 0.06666666666666667,
                0.04761904761904762, 0.2768260473615659, 0.4317453812098626, 0.4876190476190476, 0.4317453812098626, 0.2768260473615659, 0.04761904761904762,
                0.03571428571428571, 0.2107042271435060, 0.3411226924835044, 0.4124587946587039, 0.4124587946587039, 0.3411226924835044, 0.2107042271435060, 0.03571428571428571,
                0.02777777777777778, 0.1654953615608055, 0.2745387125001617, 0.3464285109730463, 0.3715192743764172, 0.3464285109730463, 0.2745387125001617, 0.1654953615608055, 0.02777777777777778,
                0.02222222222222222, 0.1333059908510701, 0.2248893420631265, 0.2920426836796838, 0.3275397611838975, 0.3275397611838975, 0.2920426836796838, 0.2248893420631265, 0.1333059908510701, 0.02222222222222222,
            };
            return 0.5*data[(p*(p-1))/2 + i];
        }
    };
} // namespace Algoim

#endif