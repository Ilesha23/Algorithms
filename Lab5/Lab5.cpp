#define N 10
# define NO_OF_CHARS 256

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void FillRand(int* arr);
void FillUp(int* arr);
void FillDown(int* arr);
void show(int* arr);
void swap(int& a, int& b);
void ShellSort(int* arr);
int LinearSearch(int* arr, int data);
int BarrierSearch(int* arr, int key);
int BinarySearch(int* arr, int key);
int SubStringSearch(string& s, string key);
int KMP(string& s, string key);
void prefix(string& s, int*& P);
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]);
int BMSearch(string s, string key);
int rabinKarp(string pattern, string text, int inputBase);

int main()
{
	int* arr = new int[N];
	FillRand(arr);
	//show(arr);
	int search = 5;
	cout << "Looking for: " << search << endl << endl;
	cout << "Linear search: " << LinearSearch(arr, search) << endl << endl;
	cout << "Barrier search: " << BarrierSearch(arr, search) << endl << endl;
	cout << "Binary search: " << BinarySearch(arr, search) << endl << endl;

	string s = "wleekmrehciwaolluujgqseqslurwxbmisbddeydgbuiyfbdbphbmuwbyyiikrykbbcmpigebijeaemypcukzayrcmmmtbbmngfwwqggfrxetntdlempjtbritixyjjrlnflsfbgfiugfmaafxbxsnjesingropwojoscjwsbtiujeayumaoqvzqpmwooapszpskeywiucvjzzupvxhoqpddyqiaznympoqgyaqtbrnjkxcsywfnmrdgwtujmghhgzzqnnvplikjrqugssljvqwlvarpvotybdawvarkeiwxzpapdoaygwqhigrgarigjwmuofnhpujllwnjkfinwmdlmtyxnrotmnrgfbvzunoegxaduzvsuoglthiveyqrreboehszfufnbxdrwpuuqgxdobkndzccbbgojbyyyogqowlysyqhligfgxiptldlelqhcyvjtcglazzxiygtytzbugbioelojcpnnpnvluafqnfebirlgpxgrivtxcpsnhenpmiosmmkmawcwjygvflzibudjupumzhkqhdqqbilyjirlxzpxcynvvryvqqvfuqyaontccjicrrhifbupwdcqlezjwtvvxefviakpvignqwebnbegcxuwiytvczcjbtwdjgqkgkiillfpvfnnndccizgmmlrfugzraielmokwjjekcpnulmhbcnxadkxkbajwpvsfmchaplgilwovhgskmoyopymdumzwmoyniwzqtwmicgtpcygpxmwpepocwkyuipigjpvtrreghtrkjakbyfqmuyvdeonaysuejtpwhpgpvcfkmuyzhavyarzggomcvulijucdwvakcevelwwnnuxnqefpycvezuilrviboiyqvhkzsmtkjqujpvgdrkejctkrwctyjrbptcbmsieubbjnbqidpqihfxmxxcrbkzoirtqdpgptvbwsmtmupkupkvzfdhfhdsxcybriurswamfqxvkzlsvvsgxhumkkdpmsinbgaqmnsnmpyphkboxbyvhpysvtyfhklaicscelawtejcitcnuwvizohgyzdsfsjrwyptmsmextimpuzrkegzpvtijczjkqzvilpujfqfhnopppxdfxfxfdqfmtpxnepruliuauquozbkaofckwsjqxsyiuuvnysphpxpydyovkqlgqmpdbevuknowxtwncawdqyyglfuhukyyvkesjhfrnztbjcuezxjsdojaubthvwjrwhhrifjmrtpqioaioyncjmohcdjzyrqowpscyxlqzafjebgyqwxouhxiuzgzaugiyfwitmhnasyjyaafydziasljzffjyuuhtrqgmodyodcguktejmohnqyhpxtxrwvtygthbzovbqrkuoimsoksohpturndlwunjsnqelewnfqnuqmgjjfxsnjjezejtdpkaladfoyxgjlpusbbiseerxrhigbfzrclhsckoehfyaestihcczdqoktgjmmgwakrolebdfoyahsqxdtdqnnzdflrwpkhvmqcmcyckldtxbtnmabkhzsieaepkbbrstkvgcnypdsssoxloskhtkpbecseblcmehccrhohuqdfmbynljihqpsqfqwheoyxivfdlimjgtihefpwqbbsogowwadysdghmmxutvosjeriwudxzpuoqiuxkfekfyfhjrjejfrzojndozaoetvglaoahrnqrdlcvrmqxikercfvfalismlgabbrsxjmkduulymvlqgqaqhuowuvbtxugzvowvttihxjaghpdedafwuplgqmiygyjhgwlbeczvgculnmcgyvpnhkxjenfqzwqdbsyhgxgiqoqfhbnazfgbvtibvocxkkapkuehgycxrevnyrbomxbcfbnwzrnlpipqafqxjlzioncuymgsxeiahfsqxbupxodyieishjtmsrtuvoavexaayrgqmcqgsptkethwobztksiyubqaagjingljyiqbuptyulpocozgwpptrdfxecghnvgmsfqwdbgyyjornzkkgyhyyurnpnmjdmmpmbxzkntsxhbnonsopbawisofylinjilxlzvtcqteczitjwuknqonuekpyolzrsgekueywbwmeumqjjaimfbetryjywelqkpzujjsmmrkwtrhikzrhljwgetctiuihgowueihtucdfhoifzbcgedabdfywkyaavmahdbtjbbjkzmvmcglnmfmdkltorgeqsbitoziqasvjbsewmziumhfqhgqqckaqpjfvkltzuzhcoujwtamaozpinbvqvybsllcmcodkpxnaaqovzeksmtkdeldjpyhzzzhjextymqjhmxxnyuwtzolqilssrprbpymyvgazaztoevtqwsojalaadzpxrecsgqmfamkjofmnkiixtgtqkxatzklstevuhdinpifktvkvujjuzbanpcaglgmkysocwadimnmxkopgrvmmhxbiszsmgnekoiptdsshgzvxwgzfcshmfhkldsjbfkutaadtxqbgyvwlvmxsheckabquuijihncmtwssgxkfpiwhllmcvvgtskkdcsifyqakpdeewhkovutyjygtyspmqgcpwrqffqxvfzswrygrfedgxuphomodhwmpnnvjmmclcamvvmyixxwjgsqtzxezfyqteaguynwvnqkvbrcuxtpvkzsxbscvkuckwptrfuqrufnevpdyrmhbhugjpbprjjkmuiakqacgjxgoonljvgnxhnugvzbuolhzdpsqnnnjrggiobumxdhcqcbmbtunqdddoxixlduknmgscjawkwduuudlvuzfmqbiujgybkuxtqcfbxkdqksjjifvwudgwtuvuqxgzbudufnbqebvlbohbemmwkvgqoxnbfmfvgefgljeumyoflygiyzxyqcgsdasopayjhldlqkcwcibszmghbmvmaxopkvwlulfolhiiihbvfpagjjicjwyeyhrefjsgoerlfuegnmnuvfapiavhjogxcfmuxsdrnzofdfwhikeftqjrowqyndlemgeyoyhruahqhogcqwuywoqxadbcmbfcrxikhszcvfkrdqcnhrabepjsyncsusrnqugtkfiywlcppzhsnuootohwoobmpergdvaivwmoswvtcsgilanbxcixfmymudtgpakfuohydvfgqsppjrtebboibaapelboptjszkfymwaxwrgbbcpjyyvvtjtfgdzpkevanydoaxilwcqxhmpbetiasvpsfeftfgmmiamhonwxgjuyqwgsuejxbmlmeouenwhdrfsnufamdbjecweeduonarasolxfvzoldjrlssohgnaiotpjlzablehqkbdyudvqvflqqnokqneczvcyuuwjkwzkpcccsweulanfxhnkjmlafdbarkhbvbtbzakpjqrdzkwkiorkbajyycvvnzmrouigdfjvendivsqxcmppllpyptomeqarbevxdsablxckpzwvvcgxqkhcfklpvmrkxlxnpfwgaeusjgesswqccvflloldhxeqnudyrlbwkgbvqhmqbitnagxrcxhmtasgzobuqkvzondnkxvrgdumiywfnrmzthnekcittllfhjkylhtagoiufqqhjxnmdkexkfwomfkrxirujwaxaqihqwixevgucufxiarmjbaccvgogcejzufmcrfetirgmdawlaulmhbfwmcgjaltzdorqcvejvojxlyziykhwqztrmwetpuxfpvefxrwmzdbxqhtqwflghfdaytqgemyinnzeplsibghbzyiaqdzppnsaxaucvgpkugfecbrlgrebabayabmyhslqlrstfdrfyplbhdjbmxugftaejuocklhxuufldfnjqiiuoaeindmocqprdmntqypmnsncwghptzvlcbntztqmfhngspwvfriyiqnkiouofufzspcwivcvquvoiwapeezplwqbfbyofbllazxagjqixmjvxfhijvdfxvowseqgpuaqzrylbcbmcwozmxozwjyjagybtqydbatlfgcrgnsgovcbhctoreerebuhocquawxfiirffxevcxzxpejhaekrudtesubtukokdfkcokilyrdhgtvhvapaywqcebqqggtwpxmozjhgmkxlggpipsjawpoegvkbgtbbfljggjchkgyqlmtluhyhplnjjybtxgfskrzenjlweomxzfmxefjlnlqnhsykdennabqhijyckziaskbytzvgteugrpovqdbdrpltydipqvynvstkfbgjfkvsdrctuankezwioortxmhufgbshkueprhsoyxjtggfupctflvniurncbryflfxxwzcszzhqqbxmypohvvkhnwsbnnfgafrhrxyflszfeydfogfsbbzrqxhirbvixbnhlyfphciqkhqrbhbhierfijcxdcvaogcypqquozrrfucdbwrnhosxyzcnjaojywrlssnznvyvmexcghijuafvtbzbhvvljredewwwjhtngtqnbkzhvdunypneauhgbybayxjxsolfboenhzestrrpmmbonwoieewmtwlsubvojkpyhajehgmtxzcsbmtdgkotlotzczgyrovbfvqlocavssjrzodvjvopglqoezvvllqwxxquewwhlyyhxoxgnypnozermdyskihjcskkkqwsbbdenogirnourxowtlsvxghyjrbfavlgkrxhfkvwqcviqrprkxecvlnqzennipfqsjfarewmvjzjfnkgsukllmqmxjstoqkxrzqhkndtwtzryhdbctrexxaqokbhnqvfwkhzymfzgnwthqnmttijqxxykovhiqmhfktjsmgaugmgnisvcgzmlkjbhviuvfapnqbgateagssqzslhrfvtndjgndzvuoyovtrmpesbxzqfectuuzkirwnnilvyzdxpqyuzsisrerwejaeeawzxpvsdusnewmcvscwuwehzrrggsiwwzypzwvuiypceikrbqvvxgnfcedtqrrpnrpjpjnymuvstotcnidisvunxbudsjnnaytuwnruzhrvteftowhkxyqamkcxqakhswiakkookoxqqoqqvkxrujvgphlduhxbzunmkhgswylerwbwadazpotpdfnxwhsspxxgemyuunvdomnssyqbkdkgllctrzeknqnnnxgntquvudbxfqudenzbtlydgdhwudmkiwacslnjehwrusizekcsecnweuutawnvixfficqhmlyffotdkkblvyjndlgrkucdsssizmimqksnjdoryfhqfqcecbsfwfqkwlfhtygsvxhumhcdoprqpxzjoxxbxadedszktynprtynlosscytwpbldocuzwpbucdjeuihgkrkpcmrfvjecryspmptwwwhsbbkskrlzjjecepdfqbdacobfbijpmklnjasfippbuzkqhueigdeaewbtfmfjqhmpbevjjsmyoguasfpsercathtbqrccigpjhaeyruayctongeekmfbbtqwqcsguniwrgxqlmvradpfeltvkiejocyolzckbnyqbnfxgecmtxffhpigorwpghiuwsbijmipawxzokxarvcwabyszvmlejxbzcrkjiyylysantjomrrvovllfxdaaulknvjhgkhsfrzgvylxgkutnnvrqfatvroeajleenmpzoikbpapfcmrwstbyfzveicltmhlwtuufatmdjolfymdgvlyewcrdhafieuxhkrxufntlsepuksvhkxpinldltxzfqhknxydhvkxsvpennaaqrbbqeqkiiduqcppebloywxuhmuzxhhsooihzgfmnycduonyqebsgoludjvxenkwrqwkslietipngfaipeejyvnzlaujmnztwdlbjtdzubvfgdjfnvehipflmkzqoqfmwutliouywqittajxdusmopipvagfvgtvrjxoduuhpvauoajywfrkazraysefsrweojcxumfpenwjutglnxlfgmlknyfsnzitihfofwdngrhocrqpwlxyfmjrpcrbtjkesetzelqwhfrsltxvkciafrhwnnhwjkyqpuwavjnynkheldwbovustkhdmpnkcyhdioellsrawijhpgzgmktyjxkwgbalnegqfjclaffuxmtuolnhcdrdffhghearsmtwomlhvgyfbzngpuxxsbpspqehtzycgyjtgxpdnoddglcflwllpsxovugnrmixyfddugbsrqfsxngcjoclwtzpwgvkzyyvqpvcgbbgpvblplrtqpsfozxohpezfafyjfmenulbwjrkuvltulufhxlquyzzljhozhalhofdwxpaywhzwksacuwbhniramkmphvtfltjrasrvirwjjxxbpbtieynipniwvqfvxpkpsptaswiszmmmpypbqpubesrmegyjilododkpdoghrqfmrxswebcbhphyoflinakkozxjxzoleruvonyzwusmzuijilmgwsjpkqizprmnkgvirzpaxuskxgoyeehfemadnaflttdomtnwurkvvzjzhnyepegljzmrqrbfammtdtlzkqifpdfnninwkhvqrpyszxnkiufapjqxsootowvqgffkzfhjhbohaaitgqntcwghcrzyrdxdbqbchgzjcvxjaeivszrhpmzxxcipjqwmvrmtgkxopdjtdbdyjnugkxajhmlijrhvkajcozlqnpzpdkbdwfhfzbzbcwdeftxbutjtbewnydrpdbbdejjytdnotjxvpzidgrcmxmdfhciinxzgndeggncwgobckcelddupabxevmhhmnwwfycwtduhblcvtnjzmvpqlhwvumxaesbsyshudmysilmvfbxujovmmkmzqchlngfmppbtzwmqvbenaizmdlriigfofntcdjjrpuwxzudtoehlhzysbqqohnipdfmwdgfetxzqmwhwnqgfttnyiffooznictkrpycncrabcqxrdryfrkbvuecnjrzawhjtrinhgtkaynusetzrjwawcdpcglexcedfjtxmauvxyomzcufxgvfwnojqsbtpxcvcvcvlonivlmuigxjtjgvcnejmwnwyztsdiqgytumhmdjqnvwbtadocfksphbmzeydzdhxpxcdmnmdbkbvnuddfwqtdezlxrcqtaeyhnubowerdzodqliysaivfzrdjqtmcgvlqinukeebuxjdlgtjwurwfuxnzeivgotgrzooyjhnurhswzggrcfsrkqttgrdktzyeqvcshoctasiznenatnfuatyketchznqphndccmudxvedgrbkftmrzwluakylmmdetkhjeosjmkzgnrmxcdrmccjkknktpaohkibruowyafloigrksveskapppqmwejcoauinfufoameuwhbzpeuxjeaxlsmztppjdmtzfazdzcyrwxqxvajhqhruvhtufplzuwupgmlxaazdldkqerqsxwfuebmvfzfkfvygzpwujenaynqbpimpfbuyhrhpknjenqrydxfapmanzzgjjlfhlymtiiqtpwwppzuicrniefhaywhwfdktvztivehdxbepohlgcdhzaptichhwtsqrfyjsrnsefjrjikalwmrcqlbdecevdxqbbbwlltikfrdyujdhvugjisfhkaxzpbssadertnccjbkctywucsflxzvneimjjepbmzexfbobdgfaevjwtxndpwhkgwgtbplicrbnsurvlmtpkyxjjixylksnbathvyhxebbudmxltmqqhiktospupeviveryebkhzwahllvgfdywgyucimothimeznkpzrxoahdewptulldbfdnibuhwzqtcwmprtogdactaltyprnwkpovckuzxlsewnbdpgpndynpykvosemtyxhujknppeycfnblikxvxgywmbvxwcbhqkwpctkyojhreitiapguxfxlendxnstmhliflpaggyyaolvalmoxxbdaivuziebtxaulcxlsqqzapgqkteakowvyjrsotmogaggthqiovssjbyntmyxliwzounsimrfuyfybpqdhmxtfwqwdhimlrjwgwiqfblcfnzntwapudgdceituqzhtcfedtmuhdkxtjcgryzwpshzjfyxgfifajfyvncvhhgvtkbapnmezqquvvdjbjcjpkgtwgsjggzsjnebxzultmidqqcirnfvkkapqfkqexdfeuyerztjryfjoslpykthfuafcdobauiojffkagbsfvyblsuaksindmrqfkuwgtnmwngvegxdjwvcissfpicmqutxsxmdctmzexqajtsllrthcxtkhqpskklwdtjblvpgznxabrbbvmstnhiozvwfdrusedrasuayskfeswnyaklvkovucbeltiiqziwntgtdolwzegeacwdgcsqgnwtaiftgbjljwxpevcrgfqwuxfyuyqnvkkqfgcyjsshxhtmbbhgehjjwnuicvpekrsxrcmhstflbgptyudpgxnbazdqkcgovhskvcbozajjwxjkvlsukutltjefankopmchifcaelvhonwzkauvqqdielnjiwlwtaixcequdygnyssuychkxtrvsrvnorzoxcmwmihpxgqyaaacmhjhzthbcosqtqyojyqghwugtyoqbbrzsdtcvbfzkurcekphqkshuaurfoisubtxouuhisylkkzxyjdicxkejtzxjaayrtdancuouzznrvwdksqhboreyphnxnqjewtqdpqwxrorqmbolkqwolvvwpylqqtswgzujgkvqyegangnmxwfszytknzdemuxcuejxsoqrpdzbrrmqgpviruarmsmylmwnxkmldcayduyfwqgbffagkgsolxnvskugazymnirsuscrjjrffomewgdgrfcuampjtwgpohmvnuadkslfhutygpjpkbsspqodmfktoogepvmlhledngwdiatozrfnhpttsmbpglnfcsuprnijiganutcmwiobrnhkdimjsnvabopmqylbyhzwckalnrcpfymquhsvdukdvtxodubcnfkolkmaiqidzfqtwmrgfurxoxmkbyeyyvlgxxjajzfquitwantytwooxrqehxbkhdjklhxssbvzrqxszvhqiuldvkicvpliitqowzsvvxloqybcsnhxndbysxnpyusmifsrojsvgzvgoytoikijarowfdvkwhjuwaxsfkuyrzaohrovvoasrhgiscxhjhvwqkgxljwfmbyjztnuyoeadelrmqklryizqxuagatoirjuwkgsdnqcfqezzugywnagndqrxdwwcvsclwaaeirwcsyyjatumjeqqtqdiougomtlnecuxmebpuaiezpnczkxenxdskcqpgdghwbvzkwmzryvhwbkvpaqdbrsodmktoywunzwqvjrtevvbzgaysuggfubjapyawscyyivbvnawbuleryqzyigbsfpidicdlohkzuwzknvdjszongcezdmunpcwannzfiwhsjjqdtrljsxhpsmdfmqfhvkzdtyroanetkwztuuzqmisdhfsgkihxaxmzvrryfnzsifvbcplyjohyyqowyiicewtukdjidqhdeqgahwfjqbnimvjxycnoihaovwywpaodlfxxqmhviyyfkrsrmqqoeiresifnlpncdqtaeuimqyvqvdshalskjklzotryhtwzhoaohxmhjrsmdnxzalikptxhjehgjxdntksxzrljagmouvuzvkvnobxzjnwtdbhdvhvejlgjjgxgtpiyhtgyxuvveqxcovdtvpvzkflotiakqmircupdiawglqdagismtzuewmdynvvjloaaeazssuxvimzsvwralwdtiqyvadoberdxnimdkwuynnzchjvkwiafzxpcvkkteqihdhhdktwcyhmgnhbkfbuwer";
	cout << s;
	string s1 = "hdktwcyhmgnhbkfbuwer";
	cout << endl << "Looking for: " << s1 << endl << endl;
	cout << "Straight search: " << SubStringSearch(s, s1) << endl << endl;
	cout << "KMP: " << KMP(s, s1) << endl << endl;
	cout << "Boyer Moore: " << BMSearch(s, s1) << endl << endl;
	cout << "Rabin Karp: " << rabinKarp(s1, s, 333) << endl << endl;
}

void FillRand(int* arr) {
	srand(time(0));
	for (int i = 0; i < N; i++)
		arr[i] = rand() % N;
}
void FillUp(int* arr) {
	for (int i = 0; i < N; i++)
		arr[i] = i;
}
void FillDown(int* arr) {
	for (int i = 0; i < N; i++)
		arr[i] = N - i - 1;
}
void show(int* arr) {
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void ShellSort(int* arr) {
	int temp, s, i, j;
	for (s = N / 2; s > 0; s /= 2)
	{
		for (i = s; i < N; ++i)
		{
			for (j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s)
			{
				swap(arr[j], arr[j + s]);
			}
		}
	}
}
int LinearSearch(int* arr, int data)
{
	int k = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] == data) {
			cout << "k = " << k << endl;
			return i;
		}
		k += 2;
	}
	return -1;
}
int BarrierSearch(int* arr, int key)
{
	int k = 1;
	arr = (int*)realloc(arr, (N + 1) * sizeof(int));
	arr[N + 1] = key;
	int i = 0;
	while (arr[i] != key) {
		i++;
		k++;
	}
	cout << "K = " << k << endl;
	return i < N ? i : -1;
}
int BinarySearch(int* arr, int key)
{
	int k = 0;
	ShellSort(arr);
	//show(arr);
	int middle,
		low = 0,
		high = N;
	while (true) {
		middle = (low + high) / 2;
		k++;
		if (key < arr[middle]) {
			high = middle - 1;
			k++;
		}
		else if (key > arr[middle]) {
			low = middle + 1;
			k++;
		}
		else {
			cout << "K = " << k << " + sort" << endl;
			return middle;
		}
		
		if (low > high)
			return -1;
	}
}
int SubStringSearch(string& s, string key)//m*(n-m), n^2
{
	int n, k, j;
	int c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == key[0])
		{
			n = k = i;
			j = 0;
			c += 3;
			while (s[k] == key[j])
			{
				k++;
				j++;
				if (j >= key.size()) {
					cout << "K = " << c << endl;
					return n;
				}
				c += 4;
			}
		}
		c += 2;
	}
	return -1;
	/*int res = -1;
	int k = 0;
	for (int i = 0; i < (s.size() - key.size() + 1); i++)
	{
		for (int j = 0; j < key.size(); j++)
		{
			if (key[j] != s[i + j])
			{
				k += 2;
				break;
			}
			else if (j == key.size() - 1)
			{
				res = i;
				k += 3;
				break;
			}
			k++;
		}
		k++;
	}
	cout << "K = " << k << endl;
	return res;*/
}
int KMP(string& s, string key) //n + m //m
{
	int* P = new int[key.size()];
	prefix(key, P);
	int k,
		l = 0;
	int c = 0;
	for (k = 0; k < s.size(); ) {
		if (s[k] == key[l])
		{
			k++;
			l++;
			if (l == key.size()) {
				cout << "K = " << c/*+s.size()*3*/ << endl;
				return k - key.size();
			}
			c += 2;
		}
		else  if (l == 0)
		{
			k++;
			if (k == s.size()) {
				cout << "K = " << c /*+ s.size() * 3*/ << endl;
				return -1;
			}
			c += 2;
		}
		else if (l != 0) {
			l = P[l - 1];
			c++;
		}
		c++;
	}
	return -1;
}
void prefix(string& s, int*& P)
{
	P[0] = 0;
	int j = 0,
		i;
	for (i = 1; i < s.size();)
		if (s[i] == s[j])
		{
			P[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0)
		{
			P[i] = 0;
			i++;
		}
		else
			j = P[j - 1];
}
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}
int BMSearch(string txt, string pat) //n/m, n, nm //+m+alphabet
{
	int k = 256*2;
	int m = pat.size();
	int n = txt.size();
	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, m, badchar);
	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;
		k++;
		while (j >= 0 && pat[j] == txt[s + j]) {
			k++;
			j--;
		}
		if (j < 0)
		{
			cout << "K = " << k << endl;
			return s;
			//s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}
		else {
			s += max(1, j - badchar[txt[s + j]]);
			k++;
		}
		k++;
	}
	return -1;
}
int rabinKarp(string pattern1, string text1, int inputBase) { //n, n, nm //+m
	char pattern[10001];
	strcpy(pattern, pattern1.c_str());
	char text[10001];
	strcpy(text, text1.c_str());
	int patternLen = strlen(pattern);
	int textLen = strlen(text);
	int i, j, k = 0;
	int patternHash = 0;
	int textHash = 0;
	int patternLenOut = 0;

	for (i = 0; i < patternLen; i++) {
		patternHash = (pattern[i]) % inputBase;
		textHash = (text[i]) % inputBase;
		k += 5;
	}

	for (i = 0; i <= textLen - patternLen; i++) {
		if (patternHash == textHash) {
			for (j = 0; j < patternLen; j++) {
				if (text[i + j] != pattern[j])
					break;
				k += 2;
			}

			if (j == patternLen) {
				//out << "Pattern is found at position: " << i + 1 << endl;
				cout << "K = " << k << endl;
				return i;
			}
			k++;
		}

		if (i < textLen - patternLen) {
			textHash = (text[i + patternLen]) % inputBase;
			//k += 3;
			if (textHash < 0) {
				textHash = (textHash + inputBase);
				//k+=3;
			}
			//k += 2;
		}
		k++;
	}
	return -1;
}