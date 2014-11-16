/***************************************************************************/
/*                                                                         */
/* breviar.cpp                                                             */
/* (c)1999-2014 | Juraj Vidéky | videky@breviar.sk                         */
/*                                                                         */
/*                http://www.breviar.sk                                    */
/*                                                                         */
/* description | program tvoriaci stranky pre liturgiu hodin               */
/* document history                                                        */
/*   30/01/2000A.D. | trencin, modified                                    */
/*   01/02/2000A.D. | bratislava, modified                                 */
/*   18/02/2000A.D. | bratislava, modified                                 */
/*   25/02/2000A.D. | bratislava, modified                                 */
/*   30/03/2000A.D. | premenoval som dnes.cpp na breviar.cpp               */
/*   06/09/2001A.D. | tento popis                                          */
/*   2003-06-27a.D. | zacinam znova :))                                    */
/*                  - nefunguju detaily pre spomienku pm v sob.            */
/*                  - 2003-06-28: sv.Irenej; ma byt aj srdce pm            */
/*   2003-06-30a.D. | Peto Santavy napisal mail o chybach                  */
/*                  - prve vespery petra-pavla su zle v r.2003             */
/*                    (2003-06-28): zmena v liturgicke_obdobie             */
/*   2003-06-30a.D. | build (priliepa sa do hlavicky)                      */
/*                    (vypisovanie BUILD_DATE, mybase.h)                   */
/*   2003-07-01a.D. | opravene Detaily... pre Spom.PM v sobotu             */
/*   2003-07-02a.D. | pridana LINK_DEN_MESIAC_ROK_PRESTUP                  */
/*                    kvoli prestupnym rokom (_main_tabulka)               */
/*                  - pridane HTML_ elementy (mydefs.h)                    */
/*   2003-07-07a.D. | pridany batch mode (davkove spracovanie)             */
/*   2003-07-08a.D. | pridany parameter (option) `a' (append)              */
/*   2003-07-09a.D. | drobne zmeny kvoli HTML 4.01 Valid                   */
/*                  - zmena & v linkach na HTML_AMPERSAND                  */
/*   2003-07-14a.D. | zmena void main -> int main (gcc v3.2.2 )            */
/*                  - <font size=-1></font> zmeneny na                     */
/*                    <span class="small"></span>                          */
/*   2003-07-15a.D. | rozne pokusy s modlitbou cez den                     */
/*                  - pridane HTML_BUTTON_                                 */
/*   2003-07-15a.D. | odstraneny #include "mybase.h"                       */
/*   2003-07-16a.D. | este jedna zmena & na HTML_AMPERSAND                 */
/*                  - zmena WWW_ na ADD_WWW_PREFIX_                        */
/*                  - zmena exportovania uvodnej stranky                   */
/*   2003-07-17a.D. | zmena helpu (vypis pri commandd-line                 */
/*   2003-08-06a.D. | dalsie pokusy s modlitbou cez den                    */
/*   2003-08-11a.D. | -Wall upozornila na vselico                          */
/*   2003-08-11a.D. | Segmentation fault odhaleny-vid POUCENIE             */
/*   2003-08-13a.D. | zmena "" na STR_EMPTY (mystring.h)                   */
/*                  - odstranenie RUN_MODLITBA_CEZ_DEN                     */
/*                  - odstranenie POKUS_24_02_2000                         */
/*                  - male zmeny v includeFile()                           */
/*                  - option5 dorobena aj do getForm()                     */
/*   2003-08-21a.D. | interpretParameter() pre posv. citania               */
/*   2003-10-07a.D. | chybali prosby pre 1. vespery nediel OCR             */
/*                    dbzaltar.cpp::_SET_SPOLOCNE_VECI_NEDELA              */
/*   2003-11-20a.D. | interpretParameter(): pre posv. citania              */
/*                    pridane citanie1 a citanie2                          */
/*   2004-03-11a.D. | pre batch mod export parametrov                      */
/*   2004-03-16a.D. | pre batch mod export zoznamu ako HTML                */
/*   2004-03-17a.D. | cesty sa citaju z konfigu (cfg_INCLUDE_DIR_default)  */
/*   2005-03-21a.D. | novy typ exportu (1 den-1 riadok) pre LK             */
/*   2005-03-22a.D. | uprava funkcie parseQueryString()                    */
/*   2005-03-28a.D. | nova funkcia setForm(), uprava pre uncgi             */
/*   2005-03-30a.D. | upravene getForm()                                   */
/*   2005-05-24a.D. | opravena copy-paste chyba pre pom_ROK_TO             */
/*   2005-07-22a.D. | pridaný popis aj pre posv.čítanie a mcd              */
/*   2005-07-27a.D. | rozšírená štruktúra dm (lokalizácia slávení)         */
/*   2005-08-15a.D. | upravená _main_zaltar(): STR_MODL_                   */
/*                  - dorobený žaltár aj pre posvätné čítania              */
/*                  - interpretParameter: nové PARAM_HYMNUS_34_OCR_INY_... */
/*   2005-08-22a.D. | upravená _export_rozbor_dna() - všedné dni aj pre 11 */
/*   2005-11-11a.D. | Doplnené: Te Deum posvätným čítaniam                 */
/*   2006-01-20a.D. | Oprava: Už sa zobrazujú aj spomienky v pôste (ľ.s.)  */
/*   2006-01-25a.D. | zmena default pre _global_opt 2 => LINK_ISO_8601     */
/*   2006-01-28a.D. | upravený spôsob výpisu v includeFile()               */
/*   2006-01-31a.D. | batch mód exportuje aj mcd (mna) a posv. čítanie     */
/*   2006-02-02a.D. | vytvorená fcia _main_formular(),zobraz.pre každý deň */
/*   2006-02-06a.D. | úprava v _rozbor_dna() kvôli nastav. _global_opt 3   */
/*   2006-07-11a.D. | prvé kroky k jazykovým mutáciám                      */
/*   2006-08-18a.D. | pokus: zmena mnohých int na short int (stačí 32tis.) */
/*   2006-08-19a.D. | zavedený nedefinovaný define ZOBRAZ_JULIANSKY_DATUM  */
/*   2006-08-19a.D. | doplnené liturgické farby                            */
/*   2006-08-22a.D. | doplnená ružová liturgická farba                     */
/*   2006-09-06a.D. | upratanie vo funkcii init_global_string (týž.ž.preNE)*/
/*   2007-01-02a.D. | prvý zásah do kódu v r. 2007: DEBUG_2006_12_07       */
/*   2007-01-08a.D. | opravené priradenie týždňa žaltára pre VIAN po 1.1.  */
/*   2007-04-10a.D. | Te Deum je vo veľkonočnej oktáve; nie je počas pôstu */
/*   2007-05-18a.D. | nezobrazovať Sláva Otcu pre Dan 3, 57-87. 56         */
/*   2007-06-01a.D. | pridané OPT6 a OPT7 (pre zobrazenie mesiaca/roka)    */
/*   2007-08-15a.D. | _export_rozbor_dna_kalendar(typ);                    */
/*                  - premenovaný _main_formular()                         */
/*   2007-08-16a.D. | oprava Segmentation fault _main_dnes() - chyba init. */
/*   2007-09-13a.D. | BUTTON_SKRATKY_DALSIE_20070913 - skratky             */
/*   2007-10-02a.D. | dokončenie zohľadnenia smerníc pre sviatky svätých   */
/*                    (rozlíšenie slávností+sviatkov/ostatných slávení),   */
/*                  - rovnaké antifóny mcd zobrazuje len prvú a poslednú   */
/*   2007-10-23a.D. | dokončenie zohľadnenia smerníc pre sviatky svätých   */
/*                    (krátke responzórium, prosby pre r.chvály/vešpery)   */
/*   2007-11-27a.D. | oprava v interpretParameter(), hymnus 34.týždňa OCR  */
/*   2007-11-28a.D. | odlišné správanie pre CZ hymny 34.týždňa OCR         */
/*   2007-12-04a.D. | opravená podmienka pre zobrazovanie Sláva Otcu,      */
/*                    pretože nefungovala pre iné modlitby ako r.chvály    */
/*   2008-01-03a.D. | viacjazyčnosť pre text_DRUHA_NEDELA_PO_NAR_PANA[]    */
/*   2008-01-05a.D. | viacjazyčnosť pre text_PO_POPOLCOVEJ_STREDE[]        */
/*                  - a tiež text_V_OKTAVE_NARODENIA[]                     */
/*                  - opravené prebytočné </span> v _global_string         */
/*                  - dni po nar.pána pre m.cez deň dokončia 4.týždeň žalt.*/
/*   2008-02-27a.D. | doplnené tlačidlá "ten istý mesiac pred rokom",      */
/*                    "ten istý mesiac o rok" do _main_rozbor_dna()        */
/*   2008-03-30a.D. | čiastočne doriešené kompletórium s 2 rovnakými ant.  */
/*                    pre veľkonočné obdobie (úprava vn1.htm, komplet.htm) */
/*   2008-04-03a.D. | kompletórium vo veľkonočnom období,                  */
/*                    či pri druhej antifóne zobraziť dvojku alebo nie     */
/*   2008-04-10a.D. | zmeny pre úpravy include_dir                         */
/*                  - dopracovanie batch módu (všetky modlitby, aj pre cz) */
/*   2008-07-18a.D. | pridaný sviatok (text_JUL_24)                        */
/*   2008-08-08a.D. | pridaný parameter (option) `c' (css - vzhľad)        */
/*   2008-08-15a.D. | doposlovenčená _main_analyza_roku()                  */
/*   2008-08-15a.D. | prvý pokus "dominikánskej češtiny"                   */
/*   2008-11-29a.D. | pridané rôzne možnosti batch exportu                 */
/*   2008-12-20a.D. | úprava init_global_string() pre nedele niekt. období */
/*                  - _export_rozbor_dna_buttons(): komplet.+nunk dimittis */
/*   2009-01-05a.D. | úprava _export_rozbor_dna() pre všedné dni (poradie) */
/*   2009-01-06a.D. | Te Deum je pre posv.čít. aj v oktáve narodenia Pána  */
/*   2009-01-28a.D. | úprava includeFile()                                 */
/*   2009-01-29a.D. | pridaný ďalší jazyk - maďarčina (hu) [prvé kroky]    */
/*   2009-02-17a.D. | posv. čítanie (button) pre všetky jazykové mutácie   */
/*   2009-04-02a.D. | 8.11.2008 na vešpery treba brať pre sviatok 9.11.    */
/*   2009-04-08a.D. | zakončenie modlitby dynamicky (pre modlitbu cez deň a*/
/*                    kompletórium sa používa kratšie zakončenie)          */
/*                    ešte ostáva doriešiť niektoré prípady (v slovenčine) */
/*   2009-05-22a.D. | hlavicka((char *)html_title[_global_jazyk]);         */
/*                  - úprava v _main_dnes(): nový deň až po pol tretej     */
/*   2009-08-02a.D. | prepínač _global_opt_batch_monthly pre batch mód,    */
/*                    aby sa exportovali mesiace do samostatných adresárov */
/*   2009-08-04a.D. | dokončený druhý spôsob výstupu pre mesačný batch mód */
/*   2009-08-05a.D. | veľká úprava funkcie _main_batch_mode()              */
/*   2009-08-05a.D. | prerobenie čítania jazyka (skopírované v main() ešte */
/*                    na jedno vyššie miesto); už by sa <title> malo       */
/*                    vypisovať pri generovaní ne-SK modlitieb správne     */
/*                  - pri ukladaní Visual Studio solution odteraz Release  */
/*   2009-08-12a.D. | snáď hotový export -M2 (akoby offline web)           */
/*   2009-08-26a.D. | nový batch export -M3 (ako -M2, ale pre mobily)      */
/*   2009-11-26a.D. | oprava pre body 4, 8, 11 [Miestne slávnosti, Miestne */
/*                    sviatky, Miestne povinné spomienky]; pred touto      */
/*                    úpravou bola kontrola (_global_svaty1.smer >= 11)    */
/*   2009-12-14a.D. | zakončenie modlitby s malým písmenkom na začiatku    */
/*   2010-02-15a.D. | upravené hlavičky aj pätky; kvôli tomu parsovanie    */
/*                    parametra _global_modlitba predsunuté pred hlavicka()*/
/*   2010-02-19a.D. | oprava funkcie velkonocna_nedela (špec. prípady pre  */
/*                    Gaussovo pravidlo; čiastočne upozornil Peter Chren)  */
/*   2010-05-14a.D. | presunuté niektoré definy do breviar.h               */
/*   2010-05-24a.D. | upravený maďarský formát dátumu                      */
/*   2010-06-04a.D. | zapracované zobrazovanie ant. po Sláva Otcu v inv.   */
/*   2010-06-07a.D. | kvôli 5. pôstnej nedeli-SK doplnené ZAKONCENIE_ON_JE */
/*   2010-07-28a.D. | začiatok pokusov pre dominikánov 8.8. ak padne na NE */
/*   2010-08-03a.D. | do štruktúry "dm" pridaná premenná pre špecifikáciu, */
/*                    o aký kalendár ide: všeobecný danej cirk. provincie  */
/*                    alebo nejaký rehoľný a pod.                          */
/*   2010-08-04a.D. | pridaná premenná _global_kalendar kvôli kalendárom   */
/*                   (napr. rehoľný), súvisí s jazykovými mutáciami        */
/*   2010-09-14a.D. | opravená podmienka pre export kalendára; ak nie je   */
/*                    kalendár určený resp. je všeobecný pre daný jazyk,   */
/*                    nie je potrebné ho exportovať                        */
/*                  - pokus o dorobenie čítania pom_KALENDAR z formov      */
/*   2010-09-28a.D. | doplnená podmienka v init_global_string() pre prípad */
/*                    prvých vešpier napr. na sviatky pána (14.9.2008)     */
/*   2010-10-06a.D. | snáď opravené to, že pre niektoré lokálne (czop)     */
/*                    slávnosti [22.10. alebo 25.10.] ten zobrazený všedný */
/*                    deň (svaty == 0) bol "prebitý" slávnosťou            */
/*                  - snáď opravené aj to, že keď pripadne lokálna slávnosť*/
/*                    na nedeľu (czop: 8.8.2010), tak fungujú obe možnosti */
/*   2011-01-12a.D. | doplnené voliteľné zobrazovanie/skrývanie myšlienky  */
/*                    (alternatívnej antifóny) pre žalmy/chválospevy       */
/*   2011-01-14a.D. | SK doplnené ZAKONCENIE_KTORY_JE                      */
/*   2011-01-26a.D. | zmeny dizajnu,                                       */
/*                    pridanie VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON */
/*                  - dorobené force "opt_1" (_global_optf 1 )             */
/*   2011-02-02a.D. | použité MIESTNE_SLAVENIE_CZOP_SVATY(i)               */
/*   2011-02-02a.D. | dokončený liturgický kalendár pre SDB a SJ, úpravy   */
/*   2011-02-02a.D. | začiatok PRM_TXT -- export LK pre RKC (Peťo Zimen)   */
/*                  - ešte: 1. doladiť export &nbsp; a <p> HTML tagov      */
/*                          2. nejako popracovať na "zlepení" pre 1 deň    */
/*   2011-03-07a.D. | MIESTNE_SLAVENIE_CZOP_SVATY(i) použité aj pre iné    */
/*                    lokálne slávenia ako MIESTNE_SLAVENIE_LOKAL_SVATY(i) */
/*   2011-03-14a.D. | batch mód: nastavenie parametra o5 (_global_opt 5)   */
/*                    pre modlitbu cez deň (bežná/doplnková psalmódia)     */
/*   2011-03-16a.D. | liturgický kalendár pre OFM (začiatok)               */
/*   2011-03-22a.D. | doplnenie možnosti explicitne žiadať o prvé vešpery  */
/*                  - pridaná option 8 (práve pre prvé vešpery)            */
/*   2011-03-23a.D. | možnosť force pre option 8 + pridanie do formulára   */
/*                  - negenerovať vešpery pre soboty, ak je nastavené      */
/*                    _global_opt 8 == ANO (aj pre offline export,         */
/*                    hoci sa parameter o8 zatiaľ neexportuje)             */
/*   2011-03-25a.D. | doplnenie možnosti predĺženej vigílie (option 9)     */
/*                  - možnosť force pre option 9 + pridanie do formulára   */
/*   2011-03-29a.D. | vysporiadanie sa so situáciou, keď include súbor     */
/*                    obsahuje zablúdený znak '{' mimo regulérnej kotvy    */
/*   2011-03-30a.D. | použitie prilep_request_options na 6-tich rovnakých  */
/*                    miestach (prilepovanie parametrov do query stringu)  */
/*   2011-04-05a.D. | rozšírenie exportu (číslovanie veršov, hypertextový  */
/*                    odkaz na dkc.kbs.sk)                                 */
/*   2011-04-06a.D. | nastavenie antifón z doplnkovej psalmódie: funkcia   */
/*                    _set_antifony_mcd_doplnkova_psalmodia(void)          */
/*   2011-04-07a.D. | po dlhom boji prerobené options a force options      */
/*                    parametre na polia;                                  */
/*                    zjednotené local_str[SMALL] (predtým bolo MAX_STR)   */
/*                    (dúfam, že toto skrátenie v 3 funkciách nebude vadiť)*/
/*   2011-04-08a.D. | úprava významu (a interpretácie) option 0            */
/*   2011-04-11a.D. | úprava významu (a interpretácie) option 1;           */
/*                    rozdelenie na jednotlivé bit-komponenty              */
/*                  - ešte: -- option 3 zahrnúť ako bit do option 1;       */
/*                          -- option 0 rozbiť tiež na bitové komponenty   */
/*   2011-04-12a.D. | _global_opt 5 je jedným z bitov _global_opt 1        */
/*                  - tlačidlo "Detaily" netreba, ZOBRAZ_BUTTON_DETAILY    */
/*   2011-04-13a.D. | úprava konfiguračného súboru, dokončenie zlúčenia    */
/*                    options, rozdelenie force options na bit-komponenty  */
/*                  - v exporte zrušené \n v sekvencii <br/>\n (kvôli IE) */
/*                  - úprava vo funkcii stuffenv()                         */
/*   2011-04-20a.D. | zobrazenie _global_opt 2 vo formulári, načítanie     */
/*   2011-04-29a.D. | doplnené Sláva Otcu "špeciálne" kvôli chválospevu    */
/*                    Dan 3, 57-88. 56, kde nie je "Sláva Otcu" (pôvodne   */
/*                    to bolo dané poradím, ale templáty pre rôzne jazyky  */
/*                    majú rozličné poradie tohto "Sláva Otcu")            */
/*   2011-05-02a.D. | znak '_' používame ako zástupný pre nezlomiteľnú     */
/*                    medzeru (exportuje sa ako &nbsp;) v include súboroch */
/*   2011-05-03a.D. | vianočná oktáva: má modlitbu kompletória pre slávnosť*/
/*                  - opravené: nezobrazovať referencie v myšlienke        */
/*                    k žalmu, ak sa táto nezobrazuje                      */
/*                  - pridané preskočenie veľkej časti šablóny pre posv.   */
/*                    čítanie na veľkonočnú nedeľu                         */
/*   2011-05-05a.D. | vyčistenie CSS, možnosť serif/sans-serif font-family */
/*   2011-05-06a.D. | špeciálna úprava pri nastavovaní _global_opt[] resp. */
/*                    _global_optf[]: zohľadnenie defaultu z config súboru */
/*                    pre 4. bit (BIT_OPT_2_FONT_NAME_CHOOSER)             */
/*                  - ToDo: urobiť krajšie defaultné nastavenie: nastaviť  */
/*                    podľa toho, čo je v config (konfiguračnom súbore);   */
/*                    zatiaľ to tam nie je                                 */
/*   2011-05-13a.D. | doplnenie font size                                  */
/*   2011-05-24a.D. | pridaný "inverzný" štýl pre mobilné zariadenia       */
/*                    (čierne pozadie, biely text)                         */
/*   2011-07-01a.D. | prvý krok k zapracovaniu navigácie do modlitieb      */
/*   2011-07-03a.D. | navigácia zapracovaná                                */
/*                    ToDo: doriešiť 4. júla; vešpery berú deň 5. júla     */
/*                    ešte: predsunúť čítanie parametrov niekam vyššie do spoločnej časti; pre "lit. obd." sa tam dáva 1.1.1900 (neurčený _global_den)... */
/*   2011-09-01a.D. | zapracovanie odkazov na katechézy ako referencie     */
/*   2011-09-06a.D. | použitie prepínača BIT_OPT_1_INE_ZALMY pre žalm 95 namiesto 24, 67, 100 */
/*   2011-09-26a.D. | použitie prepínača BIT_OPT_1_ZALM95 pre žalm 95 namiesto 24, 67, 100 */
/*   2012-08-23a.D. | funkcia _export_rozbor_dna_zoznam() a spol.          */
/*   2014-09-22a.D. | most of description available in Git log             */
/*                                                                         */
/*                                                                         */
/* poznámky |                                                              */
/*   * ako kompilovat a linkovat?                                          */
/*     najdi zarazku KOMPILACIA -- niekde ku koncu                         */
/*     pozri tiez POUCENIE                                                 */
/*                                                                         */
/*   * unfinished parts: označené ToDo resp. [ToDo]                        */
/*                                                                         */
/*   * debug in VC++/VStudio: alt+f7, zalozka Debug, Program arguments     */
/*   * debug in Visual Studio: Alt+F7, or, in solution explorer,           */
/*     right click on your project and choose "properties" from the        */
/*     drop down menu.                                                     */
/*     then, go to: Configuration Properties->Debugging                    */
/*     You can pass command line arguments in on the line that says        */
/*     Command Arguments                                                   */
/*                                                                         */
/*   -i..\..\breviar.sk\include\ -qpsqs -s"qt=pdnes"                       */
/*   -qpbm -d1 -m1 -r2000 -f2 -g2 -p2001 -ba.txt                           */
/*   -i..\..\breviar.sk\include\ -qpsqs -s"qt=pcr&dvt=pondelok&t=2&p=mpc"  */
/*   -qpdt -d30 -m4 -r2002 -pmrch -ic:\temp\breviar\ -emoja.htm            */
/*   -qpsqs -s"qt=pdt&d=26&m=5&r=2010&p=mrch&ds=1"                         */
/*                                                                         */
/*                                                                         */
/***************************************************************************/
#undef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON

#include "vstudio.h"

#ifndef __BREVIAR_CPP_
#define __BREVIAR_CPP_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h> // kvôli funckii pow();

#include "mystring.h"
#include "myconf.h"
#include "mysystem.h"
#include "mysysdef.h"
#include "hodin.h"
#include "liturgia.h"                  
#include "cgiutils.h" // parsovanie query stringu
#include "mygetopt.h" // parsovanie argv[], t.j. options z command line
#include "utf8-utils.h"

// dbzaltar:: zaltar(); liturgicke_obdobie(); sviatky_svatych();
#include "dbzaltar.h"                  
// povodne tu bolo aj 'dbsvaty.cpp', obsahujuce sviatky_svatych(); potom tu bolo "dbzaltar.cpp" a este aj include "sets.c" | 22/02/2000A.D.: dal som tam dbzaltar.h a sets.c priamo do dbzaltar.cpp
#include "mydefs.h"
#include "mylog.h" // logovanie udalosti do suboru
#include "myexpt.h" // export do suboru alebo na konzolu printf
#include "myhpage.h" // hlavicka(); patka();
#include "mybuild.h" // 2011-07-11: pridané, kvôli BUILD_DATE

#ifdef IO_ANDROID
#include "android.h"
#endif // IO_ANDROID

#ifdef LITURGICKE_CITANIA_ANDROID
#include "citania.h"
#endif // LITURGICKE_CITANIA_ANDROID

// 2005-03-28: Pridane, pokusy nahradit uncgi
char *_global_buf; // 2006-08-01: túto premennú tiež alokujeme
char *_global_buf2; // 2006-08-01: vytvorené; túto premennú tiež alokujeme

#define ishex(x) (((x) >= '0' && (x) <= '9') || ((x) >= 'a' && (x) <= 'f') || \
		  ((x) >= 'A' && (x) <= 'F'))

#define MAX_BUFFER 160

#define ANCHOR_VYSVETLIVKY "VYSVETLIVKY"
#define FILE_VYSVETLIVKY "vysvetl.htm"

#define ANCHOR_VYSVETLIVKY_TABULKA "VYSVETL_TABULKA"
#define FILE_VYSVETLIVKY_TABULKA "vysvetlt.htm"

#define LOG_ciara Log("_____________________________________________________________\n");

#define FILE_LOG "breviar-log.log" // 2011-09-30: zmenené, lebo Visual Studio 2010 zapisuje "breviar.log"

#define _main_LOG_to_Export Log
#define _main_LOG Log

// #ifndef OS_linux
#include "breviar.h" // su tam deklarovane nasledovne globalne premenne a main()
// #endif

#ifdef IO_ANDROID
#define STDIN_FILE stdin_pipe
#else
#define STDIN_FILE stdin
#endif

#if defined(__APPLE__) || defined(__linux) || defined(__unix) || defined(__posix)
#ifndef LIBC_BIONIC
// Overwrite putenv() because it causes crashes if breviar_main() is called multiple times:
// unlike setenv(), the argument of putenv() is not copied (at least not on BSD), so
// getenv() is likely to crash after the buffers are freed / reused.
//
// Android libc (bionic) has no such problems, putenv copies the values as
// well. On the other hand, setenv seems to be not working properly there, so
// we disable this logic for android.
static int my_putenv(char *s) {
	char *key = strdup(s);
	if (!key) {
		return 0;
	}

	char *val = strchr(key, '=');
	if (!val) {
		free(key);
		return 0;
	}

	*(val++) = 0;
	int res = setenv(key, val, 1);

	free(key);
	return res;
}
#define putenv my_putenv
#endif /* LIBC_BIONIC */
#endif /* unix */

//---------------------------------------------------------------------
// globalne premenne -- deklarovane v liturgia.h, definovane tu

short int query_type; // premenna obsahujuca PRM_..., deklarovana v mydefs.h

// globalna premenna, do ktorej sa ukladaju info o analyzovanom dni
_struct_dm *_global_den_ptr;
// _struct_dm _global_den;
#define _global_den (*_global_den_ptr)

// globalne premenne, do ktorych sa ukladaju info o analyzovanom dni o sviatkoch svatych
_struct_dm *(_global_svaty_ptr[MAX_POCET_SVATY]); // an array of '_struct_dm' pointers
#define _global_svaty(i) (*(_global_svaty_ptr[i - 1]))
#define _global_svaty1 (*_global_svaty_ptr[0])
#define _global_svaty2 (*_global_svaty_ptr[1])
#define _global_svaty3 (*_global_svaty_ptr[2])
#define _global_svaty4 (*_global_svaty_ptr[3])
#define _global_svaty5 (*_global_svaty_ptr[4])

// globalna premenna, ktora obsahuje data o spomienke panny marie v sobotu

_struct_dm *_global_pm_sobota_ptr;
// _struct_dm _global_pm_sobota;
#define _global_pm_sobota (*_global_pm_sobota_ptr)

// globalne premenne obsahujuce data modlitbach

_type_1vespery     *_global_modl_prve_vespery_ptr;
// _type_1vespery      _global_modl_prve_vespery;
#define _global_modl_prve_vespery (*_global_modl_prve_vespery_ptr)

_type_1kompletorium *_global_modl_1kompletorium_ptr;
// _type_1kompletorium _global_modl_prve_kompletorium;
#define _global_modl_prve_kompletorium (*_global_modl_1kompletorium_ptr)

_type_invitatorium *_global_modl_invitatorium_ptr;
// _type_invitatorium  _global_modl_invitatorium;
#define _global_modl_invitatorium (*_global_modl_invitatorium_ptr)

// 2003-08-13 pridane posvatne citanie
_type_posv_citanie *_global_modl_posv_citanie_ptr;
#define _global_modl_posv_citanie (*_global_modl_posv_citanie_ptr)

_type_ranne_chvaly *_global_modl_ranne_chvaly_ptr;
// _type_ranne_chvaly  _global_modl_ranne_chvaly;
#define _global_modl_ranne_chvaly (*_global_modl_ranne_chvaly_ptr)

_type_cez_den_9     *_global_modl_cez_den_9_ptr;
// _type_cez_den_9     _global_modl_cez_den_9;
#define _global_modl_cez_den_9 (*_global_modl_cez_den_9_ptr)
_type_cez_den_12     *_global_modl_cez_den_12_ptr;
// _type_cez_den_12     _global_modl_cez_den_12;
#define _global_modl_cez_den_12 (*_global_modl_cez_den_12_ptr)
_type_cez_den_3     *_global_modl_cez_den_3_ptr;
// _type_cez_den_3     _global_modl_cez_den_3;
#define _global_modl_cez_den_3 (*_global_modl_cez_den_3_ptr)

_type_vespery      *_global_modl_vespery_ptr;
// _type_vespery       _global_modl_vespery;
#define _global_modl_vespery (*_global_modl_vespery_ptr)

_type_kompletorium *_global_modl_kompletorium_ptr;
// _type_kompletorium _global_modl_kompletorium;
#define _global_modl_kompletorium (*_global_modl_kompletorium_ptr)

_struct_anchor_and_file *_global_include_static_text_ptr;
#define _global_include_static_text (*_global_include_static_text_ptr)

// globalna premenna, ktora obsahuje MODL_...
short int _global_modlitba = MODL_NEURCENA;
// 2006-12-08: chýbala inicializácia

// globalna premenna, do ktorej ukladaju funkcie vytvor_query_string_... linku tvaru PATH_CGI(script_name) ++ "?param1=val&param2=val&..." | 2003-07-09 prerobeny & v linkach na HTML_AMPERSAND
char *_global_link_ptr;
// char _global_link[MAX_STR];
#define _global_link _global_link_ptr

char *_global_pom_str; // pomocný string: návratová hodnota viacerých funkcií (hľadaj "return (_global_pom_str);")
// char _global_pom_str[MAX_STR];

// globalna premenna, do ktorej sa ukladaju info o jednotlivych vyznacnych liturgickych dni, pouzivaju void _dm_...() funkcie a void analyzuj_rok() funkcia
_struct_dm *_global_result_ptr;
// _struct_dm _global_result;
#define _global_result (*_global_result_ptr)

// globalna premenna, do ktorej sa uklada info o liturgickom roku pouziva void analyzuj_rok() funkcia
_struct_lrok *_global_r_ptr;
// _struct_lrok _global_r;
#define _global_r (*_global_r_ptr)

// globálna premenná, ktorú je potrebné na miestach, kde by sme potrebovali zistiť v runtime #define a kombinovať ho s podmienkou z runtime (2011-04-20)
short int _global_system;

// globalna premenna, do ktorej sviatky_svatych() uklada pocet sviatkov (de facto lubovolnych spomienok), ktore pripadaju na dany den
// -- v podstate neuklada do nej, ale v _rozbor_dna() sa do nej priradi vysledok (navratova hodnota) z sviatky_svatych()
short int _global_pocet_svatych;

// globálna premenná -- pole -- obsahujúca options; pôvodne to boli globálne premenné _global_opt 1..9 atď., obsahujú pom_MODL_OPT...
short int _global_opt[POCET_GLOBAL_OPT];
// globálna premenná -- pole -- obsahujúca force options; pôvodne to boli globálne premenné _global_optf 1..9 atď., obsahujú pom_MODL_OPTF...
short int _global_optf[POCET_GLOBAL_OPT];

// globálne premenné -- polia -- obsahujúce jednotlivé bity pre force option 0, 1, 2, 4, 5
short int _global_opt_specialne[POCET_OPT_0_SPECIALNE];
short int _global_opt_casti_modlitby[POCET_OPT_1_CASTI_MODLITBY];      
short int _global_opt_html_export[POCET_OPT_2_HTML_EXPORT];
short int _global_opt_offline_export[POCET_OPT_4_OFFLINE_EXPORT];
short int _global_opt_alternatives[POCET_OPT_5_ALTERNATIVES];

// pridane 2003-07-08, append parameter
short int _global_opt_append = NIE;
short int _global_opt_tedeum = NIE;
short int _global_pocet_slava_otcu = 0; // pridaná 2007-05-18; 2011-04-28: zrušil som porovnanie pri kontrole chválospevu Dan 3, 57-88. 56; asi je táto premenná zbytočná, ale možno sa ešte zíde :)

short int _global_ant_mcd_rovnake = NIE; // 2007-10-02: pridané pre modlitbu cez deň
// 2008-11-29, pridané
short int _global_opt_export_date_format = EXPORT_DATE_SIMPLE;
// 2009-08-02, pridané
short int _global_opt_batch_monthly = NIE;
// 2009-08-05, pridané
short int _global_hlavicka_Export = 0;
// 2011-07-01, pridané
short int _global_patka_Export = 0;

// globalna premenna, co obsahuje string vypisany na obrazovku
char *_global_string;
// char _global_string[MAX_GLOBAL_STR];
char *_global_string2;
// char _global_string2[MAX_GLOBAL_STR2]; // obsahuje I, II, III, IV, V alebo pismeno roka
char *_global_string_farba; // 2006-08-19: doplnené
// 2011-10-04: pridané, pre titulok modlitby (už sa nepriliepa do _global_string)
char _global_string_modlitba[SMALL];
// 2012-04-03: pridané, pre podnadpis modlitby (napr. pre MCD: doplnková psalmódia)
char _global_string_podnadpis[SMALL];
// 2012-08-16: pridané, pre ďalší podnadpis modlitby (spoločná časť)
char _global_string_spol_cast[MAX_GLOBAL_STR2];

// 2012-08-16: doplnené kvôli návratovej hodnote z funkcie init_global_string_spol_cast()
short int ret_sc = MODL_SPOL_CAST_NULL;

// pridane 13/04/2000A.D.; deklarovane v liturgia.h
short int _global_linky;

// 2006-07-11: Pridané kvôli jazykovým mutáciám
// 2010-08-04: zmenené _global_language na _global_jazyk (doteraz bolo len pomocou #define)
short int _global_jazyk;
// 2010-08-04: pridané kvôli kalendárom (napr. rehoľný), súvisí s jazykovými mutáciami
short int _global_kalendar;
// 2014-09-22: pridané
short int _global_ritus;

short int _global_css; // 2008-08-08: Pridané kvôli rôznym css

short int _global_font; // 2011-05-06: Pridané kvôli rôznym fontom
short int _global_font_size; // 2011-05-13: Pridané kvôli rôznym veľkostiam fontov

// 2006-10-17: Pridané kvôli kompletóriu: niekedy obsahuje až dva žalmy
short int _global_pocet_zalmov_kompletorium;

// 2009-08-12: pridané pre batch mód; názov súboru pre odkaz "^ hore" / index.htm v modlitbe
char _global_export_navig_hore[SMALL] = DEFAULT_MONTH_EXPORT;
// 2009-08-12: pridané pre batch mód; názov súboru pre odkaz "^ hore" / index.htm v mesiaci
char _global_export_navig_hore_month[SMALL] = DEFAULT_MONTH_EXPORT;
// 2009-08-12: pridané pre batch mód; názov súboru pre odkaz "^ hore" / index.htm v modlitbe
char _global_export_navig_hore_day[SMALL] = DEFAULT_MONTH_EXPORT;

// 2011-05-05: kvôli možnosti serif/sans serif override (z css sme odstránili font-family)
char _global_css_font_family[SMALL] = DEFAULT_FONT_FAMILY_SERIF; // zatiaľ len pevné reťazce; časom možno bude premenná pre názov fontu
// 2011-05-13: kvôli možnosti voľby veľkosti písma
char _global_css_font_size[SMALL] = STR_EMPTY;

short int _global_vstup_den = 0;
short int _global_vstup_mesiac = 0;
short int _global_vstup_rok = 0;
short int _global_poradie_svaty = 0;

short int _global_pocet_navigacia = 0; // 2011-07-03: počet prejdených/spracovaných parametrov PARAM_NAVIGACIA

short int _global_pocet_volani_interpretTemplate = 0; // 2012-04-19: počet volaní _global_pocet_volani_interpretTemplate()
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// debuggovacie define'y

#define DEBUG_GET_FORM 	Log("getForm(): ");Log
#define DEBUG_GET_ARGV	Log("getArgv(): ");Log

//---------------------------------------------------------------------
// globalne premenne -- pouzite iba tu, v dnes.cpp -> breviar.cpp

// globalna premenna, ktora hovori, ci preskakovat <!--{ ... }--> tagy pri preskakovani Magnifikat / Benediktus (ak je _global_opt 1 == ANO)
short int _global_skip_in_prayer = NIE;
short int _global_skip_in_prayer_2 = NIE; // 2011-04-07: kvôli číslovaniu veršov v častiach, kde sa používa _global_skip_in_prayer
short int _global_skip_in_prayer_vnpc = NIE; // 2011-05-03: kvôli veľkonočnej nedeli, posvätné čítanie
short int _global_som_vo_vigilii = NIE;

// globalna premenna, ktora hovori, ci generujeme modlitbu
//int _global_gen_modlitba; == (_global_modlitba == MODL_NEURCENA)

short int params; 
// odkial su brane parametre; hodnoty
// SCRIPT_PARAM_FROM_FORM
// SCRIPT_PARAM_FROM_ARGV
// SCRIPT_PARAM_FROM_QS
char *query_string; // QUERY_STRING environment variable

char pom_QUERY_TYPE [MAX_POM_QUERY_TYPE] = STR_EMPTY; // typ dotazu, retazec
char pom_DEN        [SMALL] = STR_EMPTY; // sluzi aj ako pom_DEN_V_TYZDNI a pom_SVIATOK
#define pom_DEN_V_TYZDNI	pom_DEN
#define pom_SVIATOK			pom_DEN
char pom_MESIAC     [SMALL] = STR_EMPTY; // sluzi aj ako pom_TYZDEN aj ako mesiac roka
#define pom_TYZDEN		pom_MESIAC
char pom_ROK        [SMALL] = STR_EMPTY; // sluzi aj ako pom_ANALYZA_ROKU
#define pom_ANALYZA_ROKU	pom_ROK
#define pom_STATIC_TEXT     pom_ROK
char pom_MODLITBA   [SMALL] = STR_EMPTY;
#define pom_MODL_ORDINARIUM	pom_MODLITBA

char pom_MODL_OPT[POCET_GLOBAL_OPT][SMALL];
char pom_MODL_OPTF[POCET_GLOBAL_OPT][SMALL]; // 2011-01-26: doplnené force verzie pre options; 2011-04-07: prepracované na pole
// reťazcové polia pre force option 0, 1, 2, 4 (jednotlivé bit-komponenty)
char pom_MODL_OPTF_SPECIALNE[POCET_OPT_0_SPECIALNE][SMALL];
char pom_MODL_OPTF_CASTI_MODLITBY[POCET_OPT_1_CASTI_MODLITBY][SMALL];
char pom_MODL_OPTF_HTML_EXPORT[POCET_OPT_2_HTML_EXPORT][SMALL];
char pom_MODL_OPTF_OFFLINE_EXPORT[POCET_OPT_4_OFFLINE_EXPORT][SMALL];
char pom_MODL_OPTF_ALTERNATIVES[POCET_OPT_5_ALTERNATIVES][SMALL];

// append pridany 2003-07-08, bude v _global_opt_append
char pom_MODL_OPT_APPEND  [SMALL] = STR_EMPTY;
char pom_DALSI_SVATY[SMALL] = STR_EMPTY;
// tieto dalsie 3 pridane kvoli PRM_TABULKA, 15/03/2000A.D.
char pom_ROK_FROM   [SMALL] = STR_EMPTY;
char pom_ROK_TO     [SMALL] = STR_EMPTY;
// pom_LINKY sa povodne volala pom_TABULKA_LINKY, avsak pouzivame ju vo win32-release ako indikator, ci zobrazovat linky vseobecne, alebo iba "akoze"-odkazy, ako mi poradil Miro M. a aj Matko Bk | 13/04/2000A.D. 
char pom_LINKY		[SMALL] = STR_EMPTY;

// 2006-07-11: Pridané kvôli jazykovým mutáciám
char pom_JAZYK		[SMALL] = STR_EMPTY;
// 2010-08-04: Pridané kvôli jazykovým mutáciám -- kalendár (rehoľný napr.)
char pom_KALENDAR   [SMALL] = STR_EMPTY;

// 2008-08-08: Pridané kvôli rôznym css
char pom_CSS		[SMALL] = STR_EMPTY;

// 2011-05-06: Pridané kvôli rôznym fontom
char pom_FONT		[SMALL] = STR_EMPTY;
// 2011-05-13: Pridané kvôli veľkosti fontov
char pom_FONT_SIZE	[SMALL] = STR_EMPTY;

// 2008-11-29: pridané rôzne možnosti batch exportu
char pom_MODL_OPT_DATE_FORMAT [SMALL] = STR_EMPTY;

// 2009-08-02: pridané pre batch mód
char pom_EXPORT_MONTHLY [SMALL] = STR_EMPTY;
// 2009-08-03: pridané pre batch mód po mesiacoch; 0 = doterajší spôsob (riadok s dátumom a potom linky na modlitby)
short int export_monthly_druh = 0;
// 2009-08-03: pridané pre batch mód po mesiacoch
short int export_month_zaciatok = NIE;
// 2009-08-05: pridané pre batch mód po mesiacoch; iné zobrazenie (najprv názvy modlitieb, potom jednotlivé dni len ako čísla)
short int export_month_nova_modlitba = NIE;

// 2011-01-25: pridané pre liturgické obdobie
char pom_LIT_OBD [SMALL] = STR_EMPTY;
// 2011-01-26: pridané pre liturgický rok
char pom_LIT_ROK [SMALL] = STR_EMPTY;

char bad_param_str[MAX_STR] = STR_EMPTY;

urlvariable param[MAX_VARIABLES];
// struktura oznacujuca dvojice <meno, hodnota> z query stringu, napr. QUERY_STRING=QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976...
// je to i-tica (tuple)
//
// <WWW_QUERY_TYPE, PRM_DATUM>,
// <WWW_DEN, 7>,
// <WWW_MESIAC, 5>,
// <WWW_ROK, 1976>,
// <WWW_MODLITBA, ...>

char file_export[SMALL] = STR_EMPTY; 
// nazov suboru, do ktoreho sa mozno exportuje v pripade pouzitia switchu `e' pri getArgv();
// ak je na jeho konci '+', tak sa appenduje; vyuzite pre switch -a (append), pozri dolu 
// pre case SCRIPT_PARAM_FROM_ARGV

// nasledovna pasaz pridana 05/06/2000A.D., a to pre pridany parameter `i' (include directory)
// deklarovane pre OS_Windows v mydefs.h
// 2004-03-17 vyhodene #ifdef pre windows; pouziva sa to jednotne
//char FILE_PATH[MAX_STR] = "include\\";

char include_dir[MAX_STR] = STR_EMPTY;

// nasledovna pasaz pridana 2003-07-04, a to pre batch mode;
// pridany parameter `n' (name of binary executable),
// pridany parameter `b' (name of batch mode file) */
char name_binary_executable[MAX_STR] = STR_EMPTY;
char name_batch_file[MAX_STR] = STR_EMPTY;
FILE *batch_file = NULL;

// 2004-03-16 pridane pre batch mode, parameter `k', aby exportoval aj zoznam modlitieb do HTML
char name_batch_html_file[MAX_STR] = STR_EMPTY;
FILE *batch_html_file = NULL;

// 2009-08-02: pridaný názov adresára pre batch mód: generovanie po mesiacoch, parameter `M'
char dir_name[MAX_STR] = STR_EMPTY;

// 2009-08-03: pridaný súbor a jeho názov pre batch mód: generovanie po mesiacoch, parameter `M'
FILE *batch_month_file = NULL;
char name_batch_month_file[MAX_STR] = STR_EMPTY;

// 2009-08-03: pridaný reťazec pre batch mód, vytvorenie nového adresára: generovanie po mesiacoch, parameter `M'
char system_command[MAX_STR] = STR_EMPTY;

// 2009-08-03: či sa podarilo vytvoriť index.htm [_global_export_navig_hore/DEFAULT_MONTH_EXPORT] vnútri adresára jednotlivého mesiaca pre 'M' -- mesačný export v batch móde
short int index_pre_mesiac_otvoreny = NIE;

// 2010-05-14: definy presunuté do breviar.h:
// je_post | je_velka_noc | je_aleluja_aleluja | je_34_ocr | je_tedeum
// všetky testujú premennú "_global_den" a je_tedeum aj "type"

//---------------------------------------------------------------------
//
// Read a POST query from standard input into a dynamic buffer. Terminate it with a null character.
//
// Vzate 2005-03-28 z uncgi.c. Navratova hodnota SUCCESS/FAILURE, vysledok je v globalnej premennej _global_buf.
short int postread(void){
	char *buf = NULL;
	short int	size = 0, sofar = 0, got;

	Log("uncgi::postread() -- zaciatok\n");
	buf = getenv("CONTENT_TYPE");
	if (buf == NULL || strcmp(buf, "application/x-www-form-urlencoded")){
		Log("uncgi::No content type was passed.\n");
		return FAILURE;
	}

	buf = getenv("CONTENT_LENGTH");
	if (buf == NULL){
		Log("uncgi::The server did not tell uncgi how long the request was.\n");
		return FAILURE;
	}
	
	size = atoi(buf);
	buf = (char *)malloc(size + 1);
	if (buf == NULL){
		Log("uncgi::Error: postread\n");
		return FAILURE;
	}
	do
	{
		got = fread(buf + sofar, 1, size - sofar, STDIN_FILE);
		sofar += got;
	} while (got && sofar < size);

	buf[sofar] = '\0';

	_global_buf = buf;
	Log("uncgi::postread() -- koniec; výstupný buffer == %s\n", _global_buf);
	return SUCCESS;
}// postread();

//---------------------------------------------------------------------
// Convert two hex digits to a value.
static short int htoi(/* unsigned */ char *s){
	short int	value;
	char	c;

	c = s[0];
	if (isupper(c))
		c = tolower(c);
	value = (c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10) * 16;

	c = s[1];
	if (isupper(c))
		c = tolower(c);
	value += c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;

	return (value);
}// htoi();

//---------------------------------------------------------------------
// Get rid of all the URL escaping in a string.  Modify it in place, since the result will always be equal in length or smaller.
static void url_unescape(/* unsigned */ char *str){
	/* unsigned */ char *dest = str;

	while (str[0])
	{
		if (str[0] == '+')
			dest[0] = ' ';
		else if (str[0] == '%' && ishex(str[1]) && ishex(str[2]))
		{
			dest[0] = (/* unsigned */ char) htoi(str + 1);
			str += 2;
		}
		else
			dest[0] = str[0];

		str++;
		dest++;
	}

	dest[0] = '\0';
}// url_unescape();

//---------------------------------------------------------------------
// Stuff a URL-unescaped variable, with the prefix on its name, into the environment. Uses the "=" from the CGI arguments.
// Putting an "=" in a field name is probably a bad idea.
// If the variable is already defined, append a '#' to it along with the new value.
// If the variable name begins with an underline, strip whitespace from the start and end and normalize end-of-line characters.
static void stuffenv(char *var){
	char *buf, *c, *s, *t, *oldval, *newval;
	short int despace = 0, got_cr = 0;
	int putenv_ret;

#ifdef DEBUG
	Log("Before unescape: %s\n", var);
#endif

	url_unescape(var);

#ifdef DEBUG
	Log("After unescape: %s\n", var);
#endif

	// 2006-08-01: pridané
	if(strlen(_global_buf2) > 0)
		strcat(_global_buf2, "&");
	strcat(_global_buf2, var);
#ifdef DEBUG
	Log("Nabaľujem _global_buf2 == %s\n", _global_buf2);
#endif

	// Allocate enough memory for the variable name and its value.
	buf = (char *)malloc(strlen(var) + sizeof(WWW_PREFIX) + 2);
	if (buf == NULL){
		Log("  Not enough memory to allocate buffer for `buf'\n");
		return;
	}
	strcpy(buf, WWW_PREFIX);
	if (var[0] == '_')
	{
		strcpy(buf + sizeof(WWW_PREFIX) - 1, var + 1);
		despace = 1;
	}
	else
		strcpy(buf + sizeof(WWW_PREFIX) - 1, var);

	// If, for some reason, there wasn't an = in the query string, add one so the environment will be valid.
	// Also, change periods to underscores so folks can get at "image" input fields from the shell, which has trouble with periods in variable names.
	for (c = buf; *c != '\0'; c++)
	{
		if (*c == '.')
			*c = '_';
		if (*c == '=')
			break;
	}
	if (*c == '\0')
		c[1] = '\0';
	*c = '\0';

	// Do whitespace stripping, if applicable.  Since this can only ever shorten the value, it's safe to do in place.
	if (despace && c[1])
	{
#ifdef DEBUG
		Log("  Stripping whitespace.\n");
#endif
		for (s = c + 1; *s && isspace(*s); s++)
			;
		t = c + 1;
		while (*s)
		{
			if (*s == '\r')
			{
				got_cr = 1;
				s++;
				continue;
			}
			if (got_cr)
			{
				if (*s != '\n')
					*t++ = '\n';
				got_cr = 0;
			}
			*t++ = *s++;
		}

		// Strip trailing whitespace if we copied anything.
		while (t > c && isspace(*--t))
			;
		t[1] = '\0';
	}

	// Check for the presence of the variable.
	if ((oldval = getenv(buf))) // priradenie do oldval a následný test, či nie je pointer NULL
	{
#ifdef DEBUG
		Log("  Variable %s exists with value %s\n", buf, oldval);
#endif
		newval = (char *)malloc(strlen(oldval) + strlen(buf) + strlen(c+1) + 3);
		if (newval == NULL){
			Log("  Not enough memory to allocate buffer for `buf'\n");
			return;
		}
		*c = '=';
		sprintf(newval, "%s#%s", buf, oldval); // pôvodne tu bolo toto; zapoznámkované 2011-04-13 (pokus)
		// sprintf(newval, "%s", buf);
		*c = '\0';

		// Set up to free the entire old environment variable -- there really ought to be a library function for this.
		// It's safe to free it since the only place these variables come from is a previous call to this function; we can never be freeing a system-supplied environment variable.
		oldval -= strlen(buf) + 1; // skip past VAR=
	}
	else
	{
#ifdef DEBUG
		Log("  Variable %s doesn't exist yet.\n", buf);
#endif
		*c = '=';
		newval = buf;
	}

#ifdef DEBUG
	Log("  putenv %s\n", newval);
#endif
	putenv_ret = putenv(newval);
	if(putenv_ret != 0){
		Log("  putenv vrátila chybu! (%s)\n", newval);
	}
	else{
		Log("  putenv OK (%s, %s)\n", buf, newval);
	}
	
	if (oldval)
	{
		// Do the actual freeing of the old value after it's not being referred to any more.
		// 2011-04-13: neviem prečo, ale tieto free() spôsobovali, že v logu nasledovná premenná nešla korektne nastaviť (putenv vrátila chybu)
		// preto som tieto free() zapoznámkoval zrejme kvôli tomu, že v query stringu sa nachádzajú aj hidden checkboxy
		// Log("free oldval (%s)...\n", oldval);
		// free(oldval);
		// Log("free buf (%s)...\n", buf);
		// free(buf);
	}// if (oldval)
}// stuffenv();

//---------------------------------------------------------------------
// Scan a query string, stuffing variables into the environment. This should ideally just use strtok(), but that's not available everywhere.
static void scanquery(char *q){
	char	*next = q;

	Log("uncgi::scanquery() -- začiatok\n");
	do {
		next = strchr(next, '&');
		if (next)
			*next = '\0';

		stuffenv(q);
		if (next)
			*next++ = '&';
		q = next;
		Log("uncgi::scanquery(): \n\tq == %s\n\t_global_buf == %s\n", q, _global_buf);
	} while (q != NULL);
	Log("uncgi::scanquery() -- koniec\n");
}// scanquery();

//---------------------------------------------------------------------
// popis: naplni premenne WWW_... hodnotami z QS, t.j. akoby to vratilo uncgi.c
// vracia: on success, returns SUCCESS
//         on error,   returns FAILURE
short int setForm(void){
	char local_str[SMALL] = STR_EMPTY;
	short int ret;
	short int i; // kvôli prilep_request_options

	Log("setForm() -- begin\n");

	// 2005-03-29 (Bratislava): Pokus (pada tabulka) - vlozime aj
	// 2005-08-15: S hrôzou som zistil, že pri simulácii z qs je pom_QUERY_TYPE = psqs preto upravujem, aby bola hodnota parametra param[x].name == qt resp. berieme z query_type
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_QUERY_TYPE, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_QUERY_TYPE), SMALL);
		strcat(local_str, "=");
		if(equals(pom_QUERY_TYPE, STR_PRM_SIMULACIA_QS)){
			Log("\tpre simuláciu priraďujem hodnotu z query_type (%s)...\n", param[0].val);
			// 2005-08-15: Ak je simulácia, nastav hodnotu podľa query_type
			strcat(local_str, param[0].val);
		}
		else
			strcat(local_str, pom_QUERY_TYPE);
		Log("--- setForm: putenv(%s); ... ", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	// deň
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_DEN, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_DEN), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_DEN);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}
	// mesiac
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_MESIAC, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MESIAC), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_MESIAC);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}
	// rok
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_ROK, STR_EMPTY)){
		// 2005-03-29: Doplnene, lebo pri analyze roka pouzivame parameter "ar" namiesto "r"
		if(query_type == PRM_ANALYZA_ROKU)
			mystrcpy(local_str, ADD_WWW_PREFIX_(STR_ANALYZA_ROKU), SMALL);
		else
			mystrcpy(local_str, ADD_WWW_PREFIX_(STR_ROK), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_ROK);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}
	// modlitba
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_MODLITBA, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MODLITBA), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_MODLITBA);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}
	// pom_DALSI_SVATY
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_DALSI_SVATY, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_DALSI_SVATY), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_DALSI_SVATY);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	// 2011-04-07: upravené; options
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		mystrcpy(local_str, STR_EMPTY, SMALL);
		if(!equals(pom_MODL_OPT[i], STR_EMPTY)){
			mystrcpy(local_str, WWW_PREFIX, SMALL);
			switch(i){
				case OPT_0_SPECIALNE:		strcat(local_str, STR_MODL_OPT_0); break;
				case OPT_1_CASTI_MODLITBY:	strcat(local_str, STR_MODL_OPT_1); break;
				case OPT_2_HTML_EXPORT:		strcat(local_str, STR_MODL_OPT_2); break;
				case OPT_3_SPOLOCNA_CAST:	strcat(local_str, STR_MODL_OPT_3); break;
				case OPT_4_OFFLINE_EXPORT:	strcat(local_str, STR_MODL_OPT_4); break;
				case OPT_5_ALTERNATIVES:	strcat(local_str, STR_MODL_OPT_5); break;
			}// switch(i)
			strcat(local_str, "=");
			strcat(local_str, pom_MODL_OPT[i]);
			Log("--- setForm: putenv(%s); ...\n", local_str);
			ret = putenv(local_str);
			Log("--- setForm: putenv returned %d.\n", ret);
		}
	}// for i

	// 2011-04-07: upravené; force options
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		mystrcpy(local_str, STR_EMPTY, SMALL);
		if(!equals(pom_MODL_OPTF[i], STR_EMPTY)){
			mystrcpy(local_str, WWW_PREFIX, SMALL);
			switch(i){
				case OPT_0_SPECIALNE:		strcat(local_str, STR_MODL_OPTF_0); break;
				case OPT_1_CASTI_MODLITBY:	strcat(local_str, STR_MODL_OPTF_1); break;
				case OPT_2_HTML_EXPORT:		strcat(local_str, STR_MODL_OPTF_2); break;
				case OPT_3_SPOLOCNA_CAST:	strcat(local_str, STR_MODL_OPTF_3); break;
				case OPT_4_OFFLINE_EXPORT:	strcat(local_str, STR_MODL_OPTF_4); break;
				case OPT_5_ALTERNATIVES:	strcat(local_str, STR_MODL_OPTF_5); break;
			}// switch(i)
			strcat(local_str, "=");
			strcat(local_str, pom_MODL_OPTF[i]);
			Log("--- setForm: putenv(%s); ...\n", local_str);
			ret = putenv(local_str);
			Log("--- setForm: putenv returned %d.\n", ret);
		}
	}// for i

	// 2011-04-13: doplené; force option 0, jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(setForm)\n", OPT_0_SPECIALNE);
	for(i = 0; i < POCET_OPT_0_SPECIALNE; i++){
		mystrcpy(local_str, STR_EMPTY, SMALL);
		if(!equals(pom_MODL_OPTF_SPECIALNE[i], STR_EMPTY)){
			mystrcpy(local_str, WWW_PREFIX, SMALL);
			switch(i){
				case 0: strcat(local_str, STR_MODL_OPTF_0_VERSE); break; // BIT_OPT_0_VERSE
				case 1: strcat(local_str, STR_MODL_OPTF_0_REF); break; // BIT_OPT_0_REFERENCIE
				case 2: strcat(local_str, STR_MODL_OPTF_0_CIT); break; // BIT_OPT_0_CITANIA
				case 3: strcat(local_str, STR_MODL_OPTF_0_ZJAV_NED); break; // BIT_OPT_0_ZJAVENIE_PANA_NEDELA
				case 4: strcat(local_str, STR_MODL_OPTF_0_NAN_NED); break; // BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA
				case 5: strcat(local_str, STR_MODL_OPTF_0_TK_NED); break; // BIT_OPT_0_TELAKRVI_NEDELA
				case 6: strcat(local_str, STR_MODL_OPTF_0_FONT_NORMAL); break; // BIT_OPT_0_FONT_NORMAL
				case 7: strcat(local_str, STR_MODL_OPTF_0_BUTTONS_ORDER); break; // BIT_OPT_0_BUTTONS_ORDER
				case 8: strcat(local_str, STR_MODL_OPTF_0_BLIND_FRIENDLY); break; // BIT_OPT_0_BLIND_FRIENDLY
			}// switch(i)
			strcat(local_str, "=");
			strcat(local_str, pom_MODL_OPTF_SPECIALNE[i]);
			Log("--- setForm: putenv(%s); ...\n", local_str);
			ret = putenv(local_str);
			Log("--- setForm: putenv returned %d.\n", ret);
		}
	}// for i

	// 2011-04-11: doplené; force option 1, jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(setForm)\n", OPT_1_CASTI_MODLITBY);
	for(i = 0; i < POCET_OPT_1_CASTI_MODLITBY; i++){
		mystrcpy(local_str, STR_EMPTY, SMALL);
		if(!equals(pom_MODL_OPTF_CASTI_MODLITBY[i], STR_EMPTY)){
			mystrcpy(local_str, WWW_PREFIX, SMALL);
			switch(i){
				case 0: strcat(local_str, STR_MODL_OPTF_1_TD); break; // BIT_OPT_1_TEDEUM
				case 1: strcat(local_str, STR_MODL_OPTF_1_RUB); break; // BIT_OPT_1_RUBRIKY
				case 2: strcat(local_str, STR_MODL_OPTF_1_CHV); break; // BIT_OPT_1_CHVALOSPEVY
				case 3: strcat(local_str, STR_MODL_OPTF_1_SL); break; // BIT_OPT_1_SLAVA_OTCU
				case 4: strcat(local_str, STR_MODL_OPTF_1_OT); break; // BIT_OPT_1_OTCENAS
				case 5: strcat(local_str, STR_MODL_OPTF_1_MCD_DOPLNKOVA); break; // BIT_OPT_1_MCD_DOPLNKOVA
				case 6: strcat(local_str, STR_MODL_OPTF_1_VIGILIA); break; // BIT_OPT_1_PC_VIGILIA
				case 7: strcat(local_str, STR_MODL_OPTF_1_SPOMIENKA_SPOL_CAST); break; // BIT_OPT_1_SPOMIENKA_SPOL_CAST
				case 8: strcat(local_str, STR_MODL_OPTF_1_PLNE_RESP); break; // BIT_OPT_1_PLNE_RESP
				case 9: strcat(local_str, STR_MODL_OPTF_1_ZALM95); break; // BIT_OPT_1_ZALM95
				case 10: strcat(local_str, STR_MODL_OPTF_1_PROSBY_ZVOLANIE); break; // BIT_OPT_1_PROSBY_ZVOLANIE
				case 11: strcat(local_str, STR_MODL_OPTF_1_SKRY_POPIS); break; // BIT_OPT_1_SKRY_POPIS
				case 12: strcat(local_str, STR_MODL_OPTF_1_ZOBRAZ_SPOL_CAST); break; // BIT_OPT_1_ZOBRAZ_SPOL_CAST
				case 13: strcat(local_str, STR_MODL_OPTF_1_VESP_KRATSIE_PROSBY); break; // BIT_OPT_1_VESP_KRATSIE_PROSBY
				case 14: strcat(local_str, STR_MODL_OPTF_1_MCD_ZALTAR_TRI); break; // BIT_OPT_1_MCD_ZALTAR_TRI
			}// switch(i)
			strcat(local_str, "=");
			strcat(local_str, pom_MODL_OPTF_CASTI_MODLITBY[i]);
			Log("--- setForm: putenv(%s); ...\n", local_str);
			ret = putenv(local_str);
			Log("--- setForm: putenv returned %d.\n", ret);
		}
	}// for i

	// 2011-04-20: doplené; force option 2, jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(setForm)\n", OPT_2_HTML_EXPORT);
	for(i = 0; i < POCET_OPT_2_HTML_EXPORT; i++){
		mystrcpy(local_str, STR_EMPTY, SMALL);
		if(!equals(pom_MODL_OPTF_HTML_EXPORT[i], STR_EMPTY)){
			mystrcpy(local_str, WWW_PREFIX, SMALL);
			switch(i){
				case 0: strcat(local_str, STR_MODL_OPTF_2_ISO_DATUM); break; // BIT_OPT_2_ISO_DATUM
				case 1: strcat(local_str, STR_MODL_OPTF_2_PRVE_VESPERY); break; // BIT_OPT_2_BUTTON_PRVE_VESPERY
				case 2: strcat(local_str, STR_MODL_OPTF_2_FONT_FAMILY); break; // BIT_OPT_2_FONT_FAMILY
				case 3: strcat(local_str, STR_MODL_OPTF_2_FONT_NAME_CHOOSER); break; // BIT_OPT_2_FONT_NAME_CHOOSER
				// case 4: strcat(local_str, STR_MODL_OPTF_2_FONT_SIZE); break; // BIT_OPT_2_FONT_SIZE_CHOOSER
				case 5: strcat(local_str, STR_MODL_OPTF_2_NAVIGATION); break; // BIT_OPT_2_NAVIGATION
				case 6: strcat(local_str, STR_MODL_OPTF_2_TEXT_WRAP); break; // BIT_OPT_2_TEXT_WRAP
				case 7: strcat(local_str, STR_MODL_OPTF_2_BUTTONY_USPORNE); break; // BIT_OPT_2_BUTTONY_USPORNE
				case 8: strcat(local_str, STR_MODL_OPTF_2_NOCNY_REZIM); break; // BIT_OPT_2_NOCNY_REZIM
				case 9: strcat(local_str, STR_MODL_OPTF_2_ROZNE_MOZNOSTI); break; // BIT_OPT_2_ROZNE_MOZNOSTI
				case 10: strcat(local_str, STR_MODL_OPTF_2_HIDE_NAVIG_BUTTONS); break; // BIT_OPT_2_HIDE_NAVIG_BUTTONS
				case 11: strcat(local_str, STR_MODL_OPTF_2_HIDE_KALENDAR); break; // BIT_OPT_2_HIDE_KALENDAR
				case 12: strcat(local_str, STR_MODL_OPTF_2_HIDE_OPTIONS1); break; // BIT_OPT_2_HIDE_OPTIONS1
				case 13: strcat(local_str, STR_MODL_OPTF_2_HIDE_OPTIONS2); break; // BIT_OPT_2_HIDE_OPTIONS2
				case 14: strcat(local_str, STR_MODL_OPTF_2_ALTERNATIVES); break; // BIT_OPT_2_ALTERNATIVES
			}// switch(i)
			strcat(local_str, "=");
			strcat(local_str, pom_MODL_OPTF_HTML_EXPORT[i]);
			Log("--- setForm: putenv(%s); ...\n", local_str);
			ret = putenv(local_str);
			Log("--- setForm: putenv returned %d.\n", ret);
		}
	}// for i

	// 2013-01-29: doplené; force option 5, jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(setForm)\n", OPT_5_ALTERNATIVES);
	for(i = 0; i < POCET_OPT_5_ALTERNATIVES; i++){
		mystrcpy(local_str, STR_EMPTY, SMALL);
		if(!equals(pom_MODL_OPTF_ALTERNATIVES[i], STR_EMPTY)){
			mystrcpy(local_str, WWW_PREFIX, SMALL);
			switch(i){
				case 0: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_KOMPL); break; // BIT_OPT_5_HYMNUS_KOMPL
				case 1: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_PC); break; // BIT_OPT_5_HYMNUS_PC
				case 2: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_PREDPOL); break; // BIT_OPT_5_HYMNUS_MCD_PREDPOL
				case 3: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_NAPOL); break; // BIT_OPT_5_HYMNUS_MCD_NAPOL
				case 4: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_POPOL); break; // BIT_OPT_5_HYMNUS_MCD_POPOL
				case 5: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_122_129); break; // BIT_OPT_5_DOPLNK_PSALM_122_129
				case 6: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_127_131); break; // BIT_OPT_5_DOPLNK_PSALM_127_131
				case 7: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_126_129); break; // BIT_OPT_5_DOPLNK_PSALM_126_129
				case 8: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_PC); break; // BIT_OPT_5_HYMNUS_VN_PC
				case 9: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_RCH); break; // BIT_OPT_5_HYMNUS_VN_RCH
				case 10: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_VESP); break; // BIT_OPT_5_HYMNUS_VN_VESP
				case 11: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_1VESP); break; // BIT_OPT_5_HYMNUS_1VESP
			}// switch(i)
			strcat(local_str, "=");
			strcat(local_str, pom_MODL_OPTF_ALTERNATIVES[i]);
			Log("--- setForm: putenv(%s); ...\n", local_str);
			ret = putenv(local_str);
			Log("--- setForm: putenv returned %d.\n", ret);
		}
	}// for i

	// 2006-07-11: Pridané kvôli jazykovým mutáciám
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_JAZYK, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_JAZYK), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_JAZYK);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	// 2010-08-04: Pridané kvôli jazykovým mutáciám -- kalendár (napr. rehoľný)
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_KALENDAR, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_KALENDAR), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_KALENDAR);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	// 2008-08-08: Pridané kvôli rôznym css
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_CSS, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_CSS), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_CSS);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	// 2011-05-06: Pridané kvôli rôznym fontom
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_FONT, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_FONT_NAME), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_FONT);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	// 2011-05-13: Pridané kvôli rôznym veľkostiam fontov
	mystrcpy(local_str, STR_EMPTY, SMALL);
	if(!equals(pom_FONT_SIZE, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_FONT_SIZE), SMALL);
		strcat(local_str, "=");
		strcat(local_str, pom_FONT_SIZE);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	Log("setForm() -- end, returning SUCCESS\n");
	return SUCCESS;
}// setForm();

//---------------------------------------------------------------------
// popis: zisti, odkial sa citaju argumenty (vstupy);
// vracia:
//
// 	SCRIPT_PARAM_FROM_FORM (z formulara, t.j. syst. premennych WWW_...)
// 	SCRIPT_PARAM_FROM_ARGV (z argumentov dialogoveho riadka)
// 	SCRIPT_PARAM_FROM_QS   (zo systemovej premennej QUERY_STRING)
//
short int getSrciptParamFrom(int argc){

	// najprv zistime, ci existuje systemova premenna QUERY_STRING
	char *qs;
	char *method;
	short int ret;
	// kedze na zaciatku main() alokujeme pre `query_string' miesto, musime tu spravit nie
	// query_string = getenv("QUERY_STRING"); (vtedy by na konci free(query_string) urobil blbost zrejme, lebo query_string uz neukazuje na alokovane miesto, 
	// ale na nieco, kde vratila funkcia getenv() hodnotu -- a mozno to ani neexistuje...)
	// ale mystrcpy(query_string, getenv("QUERY_STRING")); | 25/02/2000A.D.
	Log("--- getSrciptParamFrom(): begin\n");
	qs = getenv("QUERY_STRING");
	if(qs != NULL) // znamená to, že existuje query string - či už klasický GET, alebo časť poslaná POST linkou; 2006-08-01
		mystrcpy(query_string, qs, MAX_QUERY_STR);
	else
		mystrcpy(query_string, STR_EMPTY, MAX_QUERY_STR);

	if(query_string != NULL)
		Log("query_string == %s\n", query_string);
	else
		Log("query_string is NULL\n");
	
	// 2005-03-28: Pridane zistenie, odkial sa cita
	method = getenv("REQUEST_METHOD");
	if(method != NULL)
		Log("method == %s\n", method);
	else
		Log("method is NULL\n");
	if (method != NULL && !strcmp(method, "POST")){
		ret = postread();
		if(ret == SUCCESS){
			Log("OK. Pokracujem skenovanim query...\n");
			if ((_global_buf != NULL) && (_global_buf[0] != '\0')){
				scanquery(_global_buf);
				// 2006-08-01: _global_buf sa mení, my si budujeme kópiu v _global_buf2
				Log("POST::Vysledok == %s\n", _global_buf2);
				// 2006-08-01: prilepíme ku query stringu aj celý global buffer
				if(query_string != NULL && !equals(query_string, STR_EMPTY)){
					Log("2006-08-01: Experiment - prilepujem _global_buf2 na koniec query_stringu...\n");
					strcat(query_string, "&");
					strcat(query_string, _global_buf2);
					Log("query_string == %s...\n", query_string);
				}
			}
		}
		else{
			Log("Chyba.\n");
		}
	}// POST

	Log("--- getSrciptParamFrom(): end...\n");
	// systemova premenna QUERY_STRING existuje prave vtedy, ked query_string nie je prazdny retazec
	if((query_string != NULL) && (strlen(query_string) > 0)){
		// existuje, teda budeme pekne parsovat
		Log("returning SCRIPT_PARAM_FROM_QS.\n");
		return SCRIPT_PARAM_FROM_QS;
	}
	else if(argc == 1){
		// query_string bud neexistuje alebo je "", pritom program nema vstupne argumenty (z dial. riadka)
		Log("returning SCRIPT_PARAM_FROM_FORM (argc == %d).\n", argc);
		return SCRIPT_PARAM_FROM_FORM;
	}
	else{// program ma vstupne argumenty, argc > 1
		Log("returning SCRIPT_PARAM_FROM_ARGV -- nothing else matched.\n");
		return SCRIPT_PARAM_FROM_ARGV;
	}
}// getSrciptParamFrom();

//---------------------------------------------------------------------
//
// _export_heading();
//
// exportuje heading velkosti size;
// 2003-06-17; jednotne exportovanie. <h2> pre Liturgiu hodin, <h3> pre detailnejsi vypis
void _export_heading(/* int size, */const char *string){
	short int size = 2;
	// 2003-07-16; pridany default vypis
	Export("\n<center><h%d>Kontrola údajov</h%d></center>\n\n", size, size);
	// 2003-07-16; pre prehladnost pridany este jeden \n
	size = 4;
	Export("\n<h%d "HTML_CLASS_BLUE">%s</h%d>\n\n", size, string, size);
}// _export_heading()

// 2003-07-16; podobna funkcnost ako puovodne _export_heading
void _export_heading_center(const char *string){
	short int size = 2;
	Export("\n<!-- BEGIN:heading -->");
	Export("\n<center><h%d>%s</h%d></center>\n", size, string, size);
	Export("<!-- END:heading -->\n\n");
}// _export_heading_center()

// 2012-10-03: vytvorené; funkcia vyexportuje link pre (skryť) / (zobraziť) podľa rozličných nastavení
// kvôli nastaveniam, čo sú formulované "default = zobrazené"; treba vždy zvážiť správne nastavenie vstupných parametrov!
void _export_link_show_hide(short int opt, short int bit, char popis_show[SMALL], char popis_hide[SMALL], char html_tag_begin[SMALL], char html_class[SMALL], char specific_string_before[SMALL], char specific_string_after[SMALL], char anchor[SMALL], char html_tag_end[SMALL]){
	char pom[MAX_STR] = STR_EMPTY;
	char pom2[MAX_STR];
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	char pom3[MAX_STR];
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	prilep_request_options(pom2, pom3);

	short int _global_opt_orig;

	// najprv upravíme o_opt
	_global_opt_orig = _global_opt[opt]; // backup pôvodnej hodnoty
	// nastavenie parametra o_opt: pridáme bit pre nastavenie
	if((_global_opt[opt] & bit) != bit){
		Log("Pre option %d nastavujem bit pre '%d'\n", opt, bit);
		_global_opt[opt] += bit;
	}// zmena: použitie nastavenia
	else{
		Log("Pre option %d ruším bit pre '%d'\n", opt, bit);
		_global_opt[opt] -= bit;
	}// zmena: zrušenie nastavenia

	// prilepenie poradia svätca
	if(_global_poradie_svaty > 0){
		sprintf(pom2, HTML_AMPERSAND"%s=%d", STR_DALSI_SVATY, _global_poradie_svaty);
	}// _global_poradie_svaty > 0
	else{
		mystrcpy(pom2, STR_EMPTY, MAX_STR);
	}// !(_global_poradie_svaty > 0)

	// teraz vytvoríme reťazec s options
	prilep_request_options(pom2, pom3);
/*	
	// 2013-03-07: pokus o opravu; napokon vyriešené elegantnejšie: doplnenie niektorých skrytých (hidden) checkboxov; úprava vo funkcii _rozparsuj_parametre_OPT()
	if((opt == OPT_2_HTML_EXPORT) && ((bit == BIT_OPT_2_HIDE_OPTIONS1) || (bit == BIT_OPT_2_HIDE_OPTIONS2))){
		prilep_request_options(pom2, pom3, PRILEP_REQUEST_OPTIONS_AJ_FORCE); // aj force
	}
	else{
		prilep_request_options(pom2, pom3);
	}
*/
	// prilepíme modlitbu
	if(_global_modlitba != MODL_NEURCENA){
		sprintf(pom3, HTML_LINK_CALL_PARAM, STR_MODLITBA, str_modlitby[_global_modlitba]);
		strcat(pom2, pom3);
	}

	// napokon prilepíme #anchor // 2012-10-01
	if(!equals(anchor, STR_EMPTY)){
		sprintf(pom3, "#%s", anchor);
		strcat(pom2, pom3);
	}

	// export hyperlinku
	if(query_type == PRM_DNES){
		sprintf(pom, "%s?%s=%s%s",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DNES,
			pom2);
	}
	else if(query_type == PRM_DATUM){
		sprintf(pom, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, _global_den.den,
			STR_MESIAC, _global_den.mesiac,
			STR_ROK, _global_den.rok,
			pom2);
	}
	else if(query_type == PRM_LIT_OBD){
		sprintf(pom, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%c%s",
			script_name,
			STR_QUERY_TYPE, STR_PRM_LIT_OBD,
			STR_DEN_V_TYZDNI, _global_den.denvt,
			STR_TYZDEN, _global_den.tyzden,
			STR_LIT_OBD, _global_den.litobd,
			STR_LIT_ROK, _global_den.litrok,
			pom2);
	}

	// sprintf(pom, HTML_LINK_CALL1"%s", script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, den, STR_MESIAC, mesiac, STR_ROK, rok, pom2, pom3);

	Export("%s\n", specific_string_before);
	if(!equals(html_tag_begin, STR_EMPTY)){
		Export("<%s>\n", html_tag_begin);
	}
	Export("<a href=\"%s\" %s>", pom, html_class);
	Export("(%s)", ((_global_opt[opt] & bit) != bit)? popis_show: popis_hide); // podmienka je opačne ako intuitívne kvôli nastaveniam, čo sú formulované "default = zobrazené"; treba vždy zvážiť správne nastavenie vstupných parametrov
	Export("</a>");
	if(!equals(html_tag_end, STR_EMPTY)){
		Export("%s\n", html_tag_end);
	}
	Export("%s\n", specific_string_after);

	// napokon o_opt vrátime späť
	_global_opt[opt] = _global_opt_orig; // restore pôvodnej hodnoty
}

// funkcia vyexportuje (vrátane formátovania) reťazec napr. "Zo spoločnej časti na sviatky duchovných pastierov: pre biskupov" s prípadným dovetkom "pri slávení spomienky vziať časti zo dňa podľa Všeobecných smerníc, č. 235 písm. b"
// parameter aj_vslh_235b: 
// ANO == použitie v konkrétnej modlitbe, funkcia interpretParameter()
// NIE == použitie v prehľade pre daný dátum, funkcia _export_rozbor_dna_buttons()
void _export_global_string_spol_cast(short int aj_vslh_235b){
	char pom[MAX_STR];
	mystrcpy(pom, STR_EMPTY, MAX_STR);
	Log("-- _export_global_string_spol_cast(aj_vslh_235b == %d): začiatok...\n", aj_vslh_235b);

	if(!equals(_global_string_spol_cast, STR_EMPTY)){
		Log("-- _export_global_string_spol_cast(): exportujem reťazec `%s'...\n", _global_string_spol_cast);

		// text o VSLH č. 235 b (pôvodne sa pridávalo do reťazca _global_string_spol_cast vo funkcii init_global_string_spol_cast()
		if((aj_vslh_235b == ANO) && ((_global_den.smer > 9) && ((_global_den.typslav == SLAV_SPOMIENKA) || (_global_den.typslav == SLAV_LUB_SPOMIENKA)))){
			if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SPOMIENKA_SPOL_CAST) != BIT_OPT_1_SPOMIENKA_SPOL_CAST){
				strcat(pom, " (");
				strcat(pom, nazov_bit_opt_1_spomienka_spol_cast_jazyk[_global_jazyk]);
				strcat(pom, ")");
			}// nebrať časti zo spol. časti
		}// ide nanajvýš o spomienku (ak je to slávenie s vyšším stupňom, nemá zmysel voľba BIT_OPT_1_SPOMIENKA_SPOL_CAST)

		// (aj_vslh_235b == ANO) means function is called from the generated prayer (for blind-friendly export is not necessary to export it at all) -- use different CSS style
		if(aj_vslh_235b == ANO){
			Export("<"HTML_DIV_RED_SMALL">");
		}
		else{
			Export("<"HTML_DIV_RED_SUBTITLE">");
		}

		// pre HU iný slovosled
		if(_global_jazyk == JAZYK_HU){
			Export("%s %s %s%s.", 
				(ret_sc != MODL_SPOL_CAST_ZA_ZOSNULYCH)? ((ret_sc == MODL_SPOL_CAST_POSVIACKA_CHRAMU)? nazov_spolc_vyrocie_jazyk[_global_jazyk]: nazov_spolc_sviatky_jazyk[_global_jazyk]): STR_EMPTY,
				mystr_first_upper(_global_string_spol_cast),
				(ret_sc == MODL_SPOL_CAST_ZA_ZOSNULYCH)? nazov_spolc_oficiumza_jazyk[_global_jazyk]: nazov_spolc_zospolc_jazyk[_global_jazyk],
				pom);
		}
		else{
			Export("%s %s %s%s.", 
				(ret_sc == MODL_SPOL_CAST_ZA_ZOSNULYCH)? nazov_spolc_oficiumza_jazyk[_global_jazyk]: nazov_spolc_zospolc_jazyk[_global_jazyk], 
				(ret_sc != MODL_SPOL_CAST_ZA_ZOSNULYCH)? ((ret_sc == MODL_SPOL_CAST_POSVIACKA_CHRAMU)? nazov_spolc_vyrocie_jazyk[_global_jazyk]: nazov_spolc_sviatky_jazyk[_global_jazyk]): STR_EMPTY,
				_global_string_spol_cast, 
				pom);
		}

		Export(HTML_DIV_END);
		Export("\n");
	}
	else{
		Log("-- _export_global_string_spol_cast(): prázdny reťazec.\n");
	}
	Log("-- _export_global_string_spol_cast(aj_vslh_235b == %d): koniec.\n", aj_vslh_235b);
}// _export_global_string_spol_cast()

//---------------------------------------------------------------------
// _main_prazdny_formular();
// vypise hlasky o tom, ze je prazdny formular resp. skript bol spusteny bez vstupnych hodnot
// historicka poznamka: kedysi sa vtedy volala procedura dnes(); potom prazdny_formular(); a napokon sa _main_dnes(); vola az pri PRM_DNES
void _main_prazdny_formular(void){
	ALERT;
	Export("Programu neboli zadané argumenty.\n");
}// _main_prazdny_formular()

//---------------------------------------------------------------------
// Converts wide char into utf8 string and exports it.
void ExportRawWchar(int c) {
	char buf[5];
	char *out = buf;
	EncodeWchar(c, &out);
	*out = 0;
	Export("%s", buf);
}

void ExportChar(int c){
	// ToDo: consider special behaviour for 'plain' text export

	// blind-friendly export
	if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BLIND_FRIENDLY) == BIT_OPT_0_BLIND_FRIENDLY){
		if((c == CHAR_PRAYER_ASTERISK) || (c == CHAR_PRAYER_CROSS) || (c == CHAR_PRAYER_CROSS_ALT)){
			; // skip special characters for blind-friendly version
		}
		else if(c == CHAR_NONBREAKING_SPACE){
			Export("%c", CHAR_SPACE);
		}
		else{
			ExportRawWchar(c);
		}
		return;
	}

	// ordinary behaviour
	if(c == CHAR_NONBREAKING_SPACE){
		Export(HTML_NONBREAKING_SPACE);
	}
	else{
		ExportRawWchar(c);
	}
	return;
}// ExportChar()

//---------------------------------------------------------------------
// includeFile():
// podla parametra paramname (PARAM_...)
// 
// 2006-01-28: upravený spôsob výpisu kvôli zjednodušenej diagnostike
// 2011-05-02: znak '_' používame ako zástupný pre nezlomiteľnú medzeru (exportuje sa ako &nbsp;)
// 2011-05-03: zadefinované EXPORT_REFERENCIA -- aby sa neexportovala referencia, ak netreba (v rámci HTML poznámky) (možno časom sa ukáže, že treba testovať aj niečo iné ako len referencie v rámci myšlienok k žalmom/chválospevom)
// 2011-09-01: exportovanie odkazu na katechézu podobne ako referencie (používa BIT_OPT_0_REFERENCIE a EXPORT_REFERENCIA ako referencie)
// 2011-09-30: opravená definícia EXPORT_REFERENCIA -- musia byť splnené obe podmienky
#define DetailLog emptyLog
#define MAX_ZAKONCENIE 200
#define EXPORT_REFERENCIA ((!vnutri_myslienky || je_myslienka) && (!vnutri_nadpisu || je_nadpis))
#define je_velkonocna_nedela_posv_cit (((equals(paramname, PARAM_CITANIE1)) || (equals(paramname, PARAM_CITANIE2))) && (_global_den.denvr = VELKONOCNA_NEDELA) && (_global_modlitba == MODL_POSV_CITANIE))
short int antifona_pocet = 0; // 2011-07-08: počet antifón (ant1, ant2, ant3 pre psalmódiu a ant. na benediktus/magnifikat kvôli krížikom)
char rest_krizik[MAX_BUFFER] = STR_EMPTY; // 2011-07-08: pre to, čo je za krížikom v antifóne
char rest_zakoncenie[MAX_BUFFER] = STR_EMPTY;
void includeFile(short int type, const char *paramname, const char *fname, const char *modlparam){
	int c, buff_index = 0, ref_index = 0, kat_index = 0, z95_index = 0;
	char strbuff[MAX_BUFFER];
	char rest[MAX_BUFFER];
	char isbuff = 0;
	short int write = NIE;
	short int je_antifona = NIE; // 2011-07-08: kvôli krížikom
	short int write_krizik = NIE; // 2011-07-08: kvôli krížikom
	short int je_modlitba = NIE;

	char vnutri_inkludovaneho = 0; // 17/02/2000A.D., kvoli "V.O. Aleluja" v inkludovanych napr. antifonach
	char zakoncenie[MAX_ZAKONCENIE]; // 2009-12-14: zakončenie s veľkým písmenkom na začiatku, následne sa prípadne mení 1. písmeno na malé
	short int vnutri_referencie = NIE; // 2011-04-05, kvôli biblickým referenciám v inkludovaných súboroch
	short int vnutri_katechezy = NIE; // 2011-09-01, kvôli odkazom na katechézy v inkludovaných súboroch
	short int vnutri_z95 = NIE; // 2011-09-06, kvôli odkazu na modlitbu so žalmom 95
	short int vnutri_myslienky = NIE; // 2011-05-03, kvôli myšlienkam k žalmom, ktoré v sebe vnútri môžu obsahovať biblickú referenciu
	short int vnutri_nadpisu = NIE; // 2011-08-31, kvôli nadpisu pre psalmódiu
	short int je_myslienka = NIE; // 2011-05-03, či sa má myšlienka vkladať alebo nie
	short int je_nadpis = NIE; // 2011-08-31, či sa má nadpis pre psalmódiu vkladať alebo nie
	char refbuff[MAX_BUFFER]; // 2011-04-05: buffer pre referenciu
	char refrest[MAX_BUFFER]; // 2011-04-05: 'rest' uložené zo začiatku referencie (používa sa až pri parsovaní konca referencie)
	char katbuff[MAX_BUFFER]; // 2011-09-01: buffer pre odkaz na katechézu
	char katrest[MAX_BUFFER]; // 2011-09-01: 'rest' uložené zo začiatku odkazu na katechézu (používa sa až pri parsovaní konca odkazu na katechézu)
	char z95buff[MAX_BUFFER]; // 2011-09-06: buffer pre odkaz na ž95
	char z95rest[MAX_BUFFER]; // 2011-09-06: 'rest' uložené zo začiatku odkazu na ž 95

	Log("--includeFile(%d, %s, %s, %s): begin,\n", type, paramname, fname, modlparam);

	// nasledovné sú potrebné pre hyperlink v texte modlitby s prípadne upravenými parametrami
#ifdef BEHAVIOUR_WEB
	short int _global_opt_casti_modlitby_orig; // parameter o1 (_global_opt 1) pre modlitbu cez deň (doplnková psalmódia)
#endif

	char pom[MAX_STR];
	mystrcpy(pom, STR_EMPTY, MAX_STR);
	char pompom[MAX_STR];
	mystrcpy(pompom, STR_EMPTY, MAX_STR);

	// init
	mystrcpy(strbuff, STR_EMPTY, MAX_BUFFER);
	mystrcpy(rest, STR_EMPTY, MAX_BUFFER);
	mystrcpy(refbuff, STR_EMPTY, MAX_BUFFER);
	mystrcpy(refrest, STR_EMPTY, MAX_BUFFER);
	mystrcpy(katbuff, STR_EMPTY, MAX_BUFFER);
	mystrcpy(katrest, STR_EMPTY, MAX_BUFFER);
	mystrcpy(z95buff, STR_EMPTY, MAX_BUFFER);
	mystrcpy(z95rest, STR_EMPTY, MAX_BUFFER);

	FILE *body = fopen(fname, "r");

	Log("  replacing {%s} with %s from file `%s':\n", paramname, modlparam, fname);
	if(body == NULL){
		// printf("error `%s'\n", sys_errlist[errno]);
		Log("  file `%s' not found\n", fname);
#if defined(EXPORT_HTML_FILENAME_ANCHOR)
		Export("file `%s' not found (anchor `%s')", fname, modlparam);
#elif defined(EXPORT_HTML_FILENAME)
		Export("file `%s' not found", fname);
#else
		Export("file not found");
#endif
		Log("--includeFile(): end (because of no body)\n");
		return;
	}
	// 2006-01-28: pridané kvôli ľahšej diagnostike
#if defined(EXPORT_HTML_FILENAME_ANCHOR)
	Export("(file `%s', anchor `%s')", fname, modlparam);
#elif defined(EXPORT_HTML_FILENAME)
	Export("(file `%s')", fname);
#elif defined(EXPORT_HTML_ANCHOR)
	Export("(anchor `%s')", modlparam);
#endif

	// 2011-05-03: doplnené
	if((_global_skip_in_prayer == ANO) || (_global_skip_in_prayer_vnpc == ANO)){
		Log("--includeFile(): end (because _global_skip_in_prayer || _global_skip_in_prayer_vnpc == ANO)\n");
		return;
	}

	// 2011-05-03: nastavenie toho, či sa má zobrazovať myšlienka k žalmom/chválospevom
	// 2011-08-31: doplnené aj nastavenie pre zobrazenie nadpisu pre žalm/chválospev (zatiaľ rovnako ako pre myšlienku)
	if(((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BLIND_FRIENDLY) == BIT_OPT_0_BLIND_FRIENDLY) || (_global_den.typslav == SLAV_SLAVNOST) || (_global_den.typslav == SLAV_SVIATOK) || (_global_den.typslav == SLAV_VLASTNE) || (_global_den.litobd == OBD_VELKONOCNA_OKTAVA) || (_global_den.smer == 1) /* && (_global_den.spolcast != _encode_spol_cast(MODL_SPOL_CAST_NEURCENA)) */){
		je_myslienka = NIE;
		je_nadpis = NIE;
	}
	else{
		je_myslienka = ANO;
		je_nadpis = ANO;
	}
	Log("nastavil som je_myslienka == %d\n", je_myslienka);
	Log("nastavil som je_nadpis == %d\n", je_nadpis);

	// 2011-09-30: bod č. 114 všeobecných smerníc: "V ofíciu v Cezročnom období, ak sa nespievajú, možno namiesto týchto antifón použiť — ak je to vhodné — myšlienky pripojené k žalmom."
	/* zatiaľ zapoznámkované, lebo jedna vec je zobrazovať to, druhá vec možnosť použiť ako antifónu -- zobrazujeme podľa tlačenej LH
	if(_global_den.litobd != OBD_CEZ_ROK){
		je_myslienka = NIE;
		Log("upravil som je_myslienka == %d (nie je cezročné obdobie)\n", je_myslienka);
	}
	*/

	// Export("before while...");
	int b;
	struct Utf8DecoderState state;
	InitUtf8DecoderState(&state);

	while((b = fgetc(body)) != EOF){
		if (!Utf8StreamingDecoder(b, &state)) continue;
		c = state.result;
		// Export("inside[%c]...", c);
		switch (c){
			// 2011-03-29: ak sa nachádza znak CHAR_KEYWORD_BEGIN (t. j. '{') len tak voľne v texte, program zblbol; nevedel zistiť, či ide o keyword alebo nie; pokus o opravu
			case CHAR_KEYWORD_BEGIN:
				isbuff = 1;
				buff_index = 0;
				continue;
			case CHAR_KEYWORD_END:
				isbuff = 0;
				strbuff[buff_index] = '\0';
				DetailLog("\nFile %s, \n\tparam {%s} found\n", fname, strbuff);
				mystrcpy(rest, strbuff, MAX_BUFFER);
				splitword(strbuff, rest, CHAR_KEYWORD_DIVIDER);
				DetailLog("\tstrbuff  == %s\n", strbuff);
				DetailLog("\trest     == %s\n", rest);
				DetailLog("\tmodlparam== %s\n", modlparam);

				// Export("[INPUT:paramname=%s|fname=%s|modlparam=%s|READ:strbuff=%s|rest=%s]", paramname, fname, modlparam, strbuff, rest);

				if(equalsi(rest, modlparam)){
#if defined(EXPORT_HTML_SPECIALS)
					Export("[%s|%s:%s]", fname, strbuff, modlparam);
/*
#elif defined(EXPORT_HTML_FILENAME_ANCHOR)
					Export("[%s|%s:%s]", fname, strbuff, modlparam);
#elif defined(EXPORT_HTML_ANCHOR)
					Export("%s:%s", strbuff, modlparam);
*/
#endif
					if(equals(strbuff, INCLUDE_BEGIN)){
						write = ANO;
						vnutri_inkludovaneho = ANO;
					}// INCLUDE_BEGIN
					else if(equals(strbuff, INCLUDE_END)){
						write = NIE;
						vnutri_inkludovaneho = NIE;
						// pridane 2003-08-13 kvoli viacnasobnym inkludom
						Export("--><!--");
						// ak to aj je posledny inklude, potom v nadradenom subore, do ktoreho "inkludujeme", sa vypise "-->"
					}// INCLUDE_END
					Log("[%s|%s:%s]", fname, strbuff, modlparam);
				}// equalsi(rest, modlparam)

				else if(equals(strbuff, PARAM_KRIZIK)){
					if((vnutri_inkludovaneho == ANO) && (write == ANO)){
						// Export("[INPUT:paramname=%s|fname=%s|modlparam=%s|READ:strbuff=%s|rest=%s]", paramname, fname, modlparam, strbuff, rest);
						if(equals(paramname, PARAM_ANTIFONA1) || equals(paramname, PARAM_ANTIFONA2) || equals(paramname, PARAM_ANTIFONA3) || equals(paramname, PARAM_ANTRCHVAL) || equals(paramname, PARAM_ANTVCHVAL) || equals(paramname, PARAM_ANTIFONA1x) || equals(paramname, PARAM_ANTIFONA3x)){
							je_antifona = ANO;
							if(rest != NULL && strlen(rest) > 0)
								mystrcpy(rest_krizik, rest, MAX_BUFFER);
							// Export("antifóna[%d] -> zapamätám, ku ktorému žalmu/chválospevu patrí...\n", antifona_pocet);
						}
#if defined(EXPORT_HTML_SPECIALS)
						Export("[%s:%s|rest_krizik=%s]", strbuff, modlparam, (rest_krizik == NULL) ? STR_EMPTY: rest_krizik);
/*
#elif defined(EXPORT_HTML_FILENAME_ANCHOR)
						Export("[%s:%s]", strbuff, modlparam);
#elif defined(EXPORT_HTML_ANCHOR)
						Export("%s:%s", strbuff, modlparam);
*/
#endif
						// 2011-07-08: krížik v texte includovaného žalmu/chválospevu
						if((je_antifona == ANO) || (equals(paramname, PARAM_ZALM1) || equals(paramname, PARAM_ZALM2) || equals(paramname, PARAM_ZALM3) || equals(paramname, PARAM_RCHVALOSPEV) || equals(paramname, PARAM_VCHVALOSPEV))){
							write_krizik = ANO;
							if((je_antifona == ANO) && ((antifona_pocet MOD 2) == 0)){
								// krížik sa vypisuje len v počiatočných (nepárnych) antifónach [ToDo] preveriť, či funguje dobre aj pre modlitbu cez deň v silných obdobiach
								Log("-párna antifóna-");
								write_krizik = NIE;
							}
							if((je_antifona == ANO) && (antifona_pocet > 1) && (_global_modlitba == MODL_INVITATORIUM)){
								// pre invitatórium sa antifóna opakuje... krížik sa vypisuje len na začiatku
								Log("-párna antifóna-");
								write_krizik = NIE;
							}
							/*
							 * [ToDo] môže nastať situácia, že antifóna má v sebe krížik, ale nasleduje taký žalm/chválospev, ktorý tam ten verš nemá?
							 * pre žaltár sa to asi nemôže stať, ale pre voliteľné napr. spomienky (keď si vezme iné žalmy), by sa to teoreticky stať mohlo... 
							 * potom treba vyšpecifikovať podmienku, ktorá bude kontrolovať: ak je to antifóna 1, treba porovnať, či equals(rest_krizik, "_global_modl_...".zalm1.anchor) a pod.
							 * case pre danú modlitbu: pre MODL_RANNE_CHVALY: _global_modl_ranne_chvaly.zalm1.anchor; pre iné modlitby iný "_global_modl_..."

							if((je_antifona == ANO) && ((antifona_pocet MOD 2) == 1) && (-- zložitá podmienka --)){
								// krížik sa vypisuje v počiatočných (nepárnych) antifónach len vtedy, ak nasledujúci žalm/chválospev je ten zodpovedajúci
								Log("-nepárna antifóna/iný žalm-");
								write_krizik = NIE;
							}
							*/
							if((je_antifona == NIE) && !equals(modlparam, rest_krizik)){
								// krížik sa v žalmoch/chválospevoch vypisuje len v prípade, že predtým (v načítanej antifóne) bolo správne uvedené, ku ktorému žalmu sa to vzťahuje
								Log("-iný žalm-");
								write_krizik = NIE;
							}
							if(write_krizik == ANO){
								Export("-->");
								if(je_antifona == ANO){
									Export(HTML_NONBREAKING_SPACE); // pre krížik na začiatku žalmu/chválospevu medzeru netreba
								}
								Export("<"HTML_SPAN_RED">"HTML_CROSS""HTML_SPAN_END);
								if(je_antifona != ANO){
									Export(HTML_NONBREAKING_SPACE); // pre krížik na konci chválospevu medzeru netreba
								}
								Export("<!--");
							}
						}
					}// vypísať krížik, nakoľko antifóna nastavila, že má byť; ináč nerob nič
				}// PARAM_KRIZIK

				// 2013-02-26: doplnková psalmódia, alternatívne žalmy
				else if((equals(strbuff, PARAM_DOPLNK_PSALM_122_129)) || (equals(strbuff, PARAM_DOPLNK_PSALM_127_131)) || (equals(strbuff, PARAM_DOPLNK_PSALM_126_129))){
					if((vnutri_inkludovaneho == ANO) && (write == ANO)){
						Log("(if((equals(strbuff, PARAM_DOPLNK_PSALM_...)): _global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI == %d: (doplnková psalmódia, alternatívne žalmy)\n", _global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI);

						short int bit;
						short int opt = OPT_5_ALTERNATIVES;
						short int nastavene = NIE;

						char popis_show[SMALL];
						char popis_hide[SMALL];
						mystrcpy(popis_show, html_text_option_zobrazit[_global_jazyk], SMALL);
						mystrcpy(popis_hide, html_text_option_skryt[_global_jazyk], SMALL);

						char specific_string[SMALL];
						mystrcpy(specific_string, STR_EMPTY, SMALL);

						char anchor[SMALL];
						mystrcpy(anchor, STR_EMPTY, SMALL);

						short int podmienka = ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) == BIT_OPT_2_ROZNE_MOZNOSTI); // len ak je táto možnosť (zobrazovanie všeličoho) zvolená
						podmienka &= (_global_skip_in_prayer != ANO);

						if(equals(strbuff, PARAM_DOPLNK_PSALM_122_129)){
							podmienka &= ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ALTERNATIVES) == BIT_OPT_2_ALTERNATIVES); // len ak je táto možnosť (zobrazovanie alternatívy) zvolená
							podmienka &= (je_alternativa_doplnkova_psalmodia_z122_129(_global_modlitba));
							mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);
							bit = BIT_OPT_5_DOPLNK_PSALM_122_129;
							sprintf(popis_show, "%s", html_text_option5_DPsalmZ122_129[_global_jazyk]);
							sprintf(popis_hide, "%s", html_text_option5_DPsalmZ122_NORMAL[_global_jazyk]);
							mystrcpy(anchor, ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_122_129) == BIT_OPT_5_DOPLNK_PSALM_122_129)? PARAM_ZALM122: PARAM_ZALM129, SMALL);
							nastavene = ANO;
						}
						if(!nastavene && equals(strbuff, PARAM_DOPLNK_PSALM_126_129)){
							podmienka &= ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ALTERNATIVES) == BIT_OPT_2_ALTERNATIVES); // len ak je táto možnosť (zobrazovanie alternatívy) zvolená
							podmienka &= (je_alternativa_doplnkova_psalmodia_z126_129(_global_modlitba));
							mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);
							bit = BIT_OPT_5_DOPLNK_PSALM_126_129;
							sprintf(popis_show, "%s", html_text_option5_DPsalmZ126_129[_global_jazyk]);
							sprintf(popis_hide, "%s", html_text_option5_DPsalmZ126_NORMAL[_global_jazyk]);
							mystrcpy(anchor, ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_126_129) == BIT_OPT_5_DOPLNK_PSALM_126_129)? PARAM_ZALM126: PARAM_ZALM129, SMALL);
							nastavene = ANO;
						}
						if(!nastavene && equals(strbuff, PARAM_DOPLNK_PSALM_127_131)){
							podmienka &= ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ALTERNATIVES) == BIT_OPT_2_ALTERNATIVES); // len ak je táto možnosť (zobrazovanie alternatívy) zvolená
							podmienka &= (je_alternativa_doplnkova_psalmodia_z127_131(_global_modlitba));
							mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);
							bit = BIT_OPT_5_DOPLNK_PSALM_127_131;
							sprintf(popis_show, "%s", html_text_option5_DPsalmZ127_131[_global_jazyk]);
							sprintf(popis_hide, "%s", html_text_option5_DPsalmZ127_NORMAL[_global_jazyk]);
							mystrcpy(anchor, ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_127_131) == BIT_OPT_5_DOPLNK_PSALM_127_131)? PARAM_ZALM127: PARAM_ZALM131, SMALL);
							nastavene = ANO;
						}

						// má zmysel len ak platí daná podmienka
						if(podmienka){
							Log("including %s\n", paramname);
							Export("%s:begin-->", paramname);

							char before[SMALL] = STR_EMPTY;
							sprintf(before, "<p "HTML_ALIGN_CENTER" "HTML_CLASS_SMALL">");
							char after[SMALL] = STR_EMPTY;
							mystrcpy(after, "</p>", SMALL);
							_export_link_show_hide(opt, bit, /* opačné nastavenie kvôli špeciálnej podmienke, defaulty */ popis_hide, popis_show, (char *)HTML_SPAN_RED_SMALL, (char *)HTML_CLASS_QUIET, specific_string, (char *)STR_EMPTY, anchor, (char *)HTML_SPAN_END);

							Export("<!--%s:end", paramname);
						}
						else{
							Export("[skipping %s]", paramname);
							Log("skipping %s\n", paramname);
						}
					}// ináč nerob nič
				}// PARAM_DOPLNK_PSALM_122_129 || PARAM_DOPLNK_PSALM_127_131 || PARAM_DOPLNK_PSALM_126_129

				// 2011-10-07: zakončenie v texte includovanej modlitby
				else if(equals(strbuff, PARAM_ZAKONCENIE)){
					if((vnutri_inkludovaneho == ANO) && (write == ANO)){
						// Export("[INPUT:paramname=%s|fname=%s|modlparam=%s|READ:strbuff=%s|rest=%s]", paramname, fname, modlparam, strbuff, rest);
						if((equals(paramname, PARAM_MODLITBA)) || (equals(paramname, PARAM_MODL_SPOMPRIVILEG)) || (je_velkonocna_nedela_posv_cit)){

							// pre ranné chvály a vešpery, ak sa pridáva 'modlitba' pre spomienku v privilegované dni, tak zakončenie sa dáva až pre PARAM_MODL_SPOMPRIVILEG
							if((equals(paramname, PARAM_MODLITBA)) && (je_ant_modl_spomprivileg))
								je_modlitba = !(_global_modlitba == MODL_RANNE_CHVALY || _global_modlitba == MODL_VESPERY);
							else if(equals(paramname, PARAM_MODL_SPOMPRIVILEG))
								je_modlitba = ANO;
							else
								je_modlitba = ANO;
							
							if(rest != NULL && strlen(rest) > 0)
								mystrcpy(rest_zakoncenie, rest, MAX_BUFFER);
						}
#if defined(EXPORT_HTML_SPECIALS)
						Export("[%s:%s|rest_zakoncenie=%s]", strbuff, modlparam, (rest_zakoncenie == NULL) ? STR_EMPTY: rest_zakoncenie);
/*
#elif defined(EXPORT_HTML_FILENAME_ANCHOR)
						Export("[%s:%s]", strbuff, modlparam);
#elif defined(EXPORT_HTML_ANCHOR)
						Export("%s:%s", strbuff, modlparam);
*/
#endif
						if((je_modlitba == ANO) && ((equals(paramname, PARAM_MODLITBA)) || (equals(paramname, PARAM_MODL_SPOMPRIVILEG)) || (je_velkonocna_nedela_posv_cit))){
							Export("%s--> ", (rest_zakoncenie == NULL) ? STR_EMPTY: rest_zakoncenie);
							if(equals(rest_zakoncenie, PARAM_ZAKONCENIE_SKRZE) || equals(rest_zakoncenie, PARAM_ZAKONCENIE_SKRZE_MALE)){
								if(je_modlitba_cez_den(_global_modlitba) || je_kompletorium12(_global_modlitba) || (je_velkonocna_nedela_posv_cit)){
									mystrcpy(zakoncenie, text_ZAKONCENIE_SKRZE_kratke[_global_jazyk], MAX_ZAKONCENIE);
								}
								else{
									mystrcpy(zakoncenie, text_ZAKONCENIE_SKRZE_dlhe[_global_jazyk], MAX_ZAKONCENIE);
								}
							} // ZAKONCENIE_SKRZE
							else if(equals(rest_zakoncenie, PARAM_ZAKONCENIE_LEBO_TY) || equals(rest_zakoncenie, PARAM_ZAKONCENIE_LEBO_TY_MALE)){
								if(je_modlitba_cez_den(_global_modlitba) || je_kompletorium12(_global_modlitba) || (je_velkonocna_nedela_posv_cit)){
									mystrcpy(zakoncenie, text_ZAKONCENIE_LEBO_TY_kratke[_global_jazyk], MAX_ZAKONCENIE);
								}
								else{
									mystrcpy(zakoncenie, text_ZAKONCENIE_LEBO_TY_dlhe[_global_jazyk], MAX_ZAKONCENIE);
								}
							} // ZAKONCENIE_LEBO_TY
							else if(equals(rest_zakoncenie, PARAM_ZAKONCENIE_LEBO_ON) || equals(rest_zakoncenie, PARAM_ZAKONCENIE_LEBO_ON_MALE)){
								if(je_modlitba_cez_den(_global_modlitba) || je_kompletorium12(_global_modlitba) || (je_velkonocna_nedela_posv_cit)){
									mystrcpy(zakoncenie, text_ZAKONCENIE_LEBO_ON_kratke[_global_jazyk], MAX_ZAKONCENIE);
								}
								else{
									mystrcpy(zakoncenie, text_ZAKONCENIE_LEBO_ON_dlhe[_global_jazyk], MAX_ZAKONCENIE);
								}
							} // ZAKONCENIE_LEBO_ON
							else if(equals(rest, PARAM_ZAKONCENIE_ON_JE) && _global_jazyk == JAZYK_SK){
								if(je_modlitba_cez_den(_global_modlitba) || je_kompletorium12(_global_modlitba) || (je_velkonocna_nedela_posv_cit)){
									mystrcpy(zakoncenie, text_ZAKONCENIE_ON_JE_kratke, MAX_ZAKONCENIE);
								}
								else{
									mystrcpy(zakoncenie, text_ZAKONCENIE_ON_JE_dlhe, MAX_ZAKONCENIE);
								}
							} // SK: ZAKONCENIE_ON_JE
							else if(equals(rest, PARAM_ZAKONCENIE_KTORY_JE) && _global_jazyk == JAZYK_SK){
								if(je_modlitba_cez_den(_global_modlitba) || je_kompletorium12(_global_modlitba) || (je_velkonocna_nedela_posv_cit)){
									mystrcpy(zakoncenie, text_ZAKONCENIE_KTORY_JE_kratke, MAX_ZAKONCENIE);
								}
								else{
									mystrcpy(zakoncenie, text_ZAKONCENIE_KTORY_JE_dlhe, MAX_ZAKONCENIE);
								}
							} // SK: ZAKONCENIE_KTORY_JE
							else if(equals(rest_zakoncenie, PARAM_ZAKONCENIE_O_TO_TA_PROSIME)){
								mystrcpy(zakoncenie, text_ZAKONCENIE_O_TO_TA_PROSIME[_global_jazyk], MAX_ZAKONCENIE);
							} // PARAM_ZAKONCENIE_O_TO_TA_PROSIME

							if(equals(rest_zakoncenie, PARAM_ZAKONCENIE_SKRZE_MALE) || equals(rest_zakoncenie, PARAM_ZAKONCENIE_LEBO_TY_MALE) || equals(rest_zakoncenie, PARAM_ZAKONCENIE_LEBO_ON_MALE)){
								zakoncenie[0] = zakoncenie[0] + ('a'-'A'); // posun z veľkého písmena na malé: pozor, funguje len pre základné znaky ASCII
							}
							// 2011-05-16: nezlomiteľné medzery
							Export("%s", convert_nonbreaking_spaces(zakoncenie));
							Export("<!--%s", (rest_zakoncenie == NULL) ? STR_EMPTY: rest_zakoncenie);
							je_modlitba = NIE;
						}
					}// vypísať zakončenie
				}// PARAM_ZAKONCENIE

				else{
					// !equalsi(rest, modlparam)
					// write = NIE; -- aby mohli byt nestovane viacere :-)
					DetailLog("parameter does not match: %s != %s\n", rest, modlparam);

					// 2011-04-05: upraviť referencie na hyperlinky
					if(equals(strbuff, PARAM_REFERENCIA_BEGIN) && (vnutri_inkludovaneho == 1)){
						vnutri_referencie = ANO;
						write = NIE;
						ref_index = 0;
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE){
							if(rest != NULL){
								mystrcpy(refrest, rest, MAX_BUFFER);
							}
							DetailLog("\trest     == %s\n", rest);
							DetailLog("\trefrest  == %s\n", refrest);
						}
					}// upraviť referencie na hyperlinky -- PARAM_REFERENCIA_BEGIN
					if(equals(strbuff, PARAM_REFERENCIA_END) && (vnutri_inkludovaneho == 1)){
						refbuff[ref_index] = '\0';
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE){
							// ToDo: časom dať odkaz napr. do konfiguračného súboru
							if(EXPORT_REFERENCIA){
								if(_global_jazyk == JAZYK_HU){
									Export("<a href=\"http://www.szentiras.hu/SZIT/");
								}
								else{
									Export("<a href=\"http://dkc.kbs.sk/?in=");
								}
							}
							DetailLog("\trest     == %s\n", rest);
							DetailLog("\trefrest  == %s\n", refrest);
							if((refrest != NULL) && !(equals(refrest, STR_EMPTY))){
								// [ToDo]: doplniť nevypisovanie refbuff, ak refrest obsahuje medzeru
								if(EXPORT_REFERENCIA){
#ifdef IO_ANDROID
									Export("%s", remove_diacritics(refrest));
#else
									Export("%s", refrest); // 2013-06-12: pôvodne sa odstraňovala diakritika; ponechané len pre Android
#endif
								}
							}// načítanie na začiatok referencie
							if(EXPORT_REFERENCIA){
#ifdef IO_ANDROID
								Export("%s\" target=\"_blank\" "HTML_CLASS_QUIET">", remove_diacritics(refbuff)); 
#else
								Export("%s\" target=\"_blank\" "HTML_CLASS_QUIET">", refbuff); // a.quiet { text-decoration:none; color: inherit; } // 2013-06-12: pôvodne sa odstraňovala diakritika; ponechané len pre Android
#endif
							}
						}
						if(EXPORT_REFERENCIA){
							Export("%s", refbuff);
						}
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE){
							if(EXPORT_REFERENCIA){
								Export("</a>");
							}
						}
						vnutri_referencie = NIE;

						// 2011-05-02: doplnené kvôli referenciám, ktoré sú v rámci myšlienok, čo sa nemajú zobrazovať
						if(EXPORT_REFERENCIA){
							write = ANO;
						}
						strcpy(refrest, STR_EMPTY);
					}// upraviť referencie na hyperlinky -- PARAM_REFERENCIA_END

#if defined(BEHAVIOUR_WEB)
					// 2011-09-01: upraviť odkazy na katechézy (zatiaľ napojené na BIT_OPT_0_REFERENCIE a EXPORT_REFERENCIA ako referencie)
					if(equals(strbuff, PARAM_KATECHEZA_BEGIN) && (vnutri_inkludovaneho == 1)){
						vnutri_katechezy = ANO;
						write = NIE;
						kat_index = 0;
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE){
							if(rest != NULL){
								mystrcpy(katrest, rest, MAX_BUFFER);
							}
							DetailLog("\trest     == %s\n", rest);
							DetailLog("\tkatrest  == %s\n", katrest);
						}
					}// upraviť odkazy na katechézy na hyperlinky -- PARAM_KATECHEZA_BEGIN
					if(equals(strbuff, PARAM_KATECHEZA_END) && (vnutri_inkludovaneho == 1)){
						katbuff[kat_index] = '\0';
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE){
							// ToDo: časom dynamicky
							if(EXPORT_REFERENCIA){
								Export("<a href=\"/include/");
							}
							DetailLog("\trest     == %s\n", rest);
							DetailLog("\tkatrest  == %s\n", katrest);
							if((katrest != NULL) && !(equals(katrest, STR_EMPTY))){
								// [ToDo]: doplniť nevypisovanie katbuff, ak katrest obsahuje medzeru (prevzaté z časti pre referencie)
								if(EXPORT_REFERENCIA){
									Export("%s", katrest);
								}
							}// načítanie na začiatok referencie
							if(EXPORT_REFERENCIA){
								// prípadne odstrániť target=\"_blank\"
								Export("\" target=\"_blank\" "HTML_CLASS_QUIET">"); // a.quiet { text-decoration:none; color: inherit; }
							}
						}
						if(EXPORT_REFERENCIA){
							// 2014-04-10: nezlomiteľné medzery
							Export("%s", convert_nonbreaking_spaces(katbuff));
						}
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE){
							if(EXPORT_REFERENCIA){
								Export("</a>");
							}
						}
						vnutri_katechezy = NIE;

						// prevzaté z časti pre referencie: 2011-05-02: doplnené kvôli referenciám, ktoré sú v rámci myšlienok, čo sa nemajú zobrazovať
						if(EXPORT_REFERENCIA){
							write = ANO;
						}
						strcpy(katrest, STR_EMPTY);
					}// upraviť odkazy na katechézy na hyperlinky -- PARAM_KATECHEZA_END
#endif

					// 2011-09-06: upraviť odkaz na žalm 95 (zatiaľ napojené na BEHAVIOUR_WEB)
					if(equals(strbuff, PARAM_LINK_ZALM95_BEGIN) && (vnutri_inkludovaneho == 1)){
						vnutri_z95 = ANO;
						write = NIE;
						z95_index = 0;
#ifdef BEHAVIOUR_WEB
						if(rest != NULL){
							mystrcpy(z95rest, rest, MAX_BUFFER);
						}
						DetailLog("\trest     == %s\n", rest);
						DetailLog("\tz95rest  == %s\n", z95rest);
#endif
					}// upraviť odkaz na žalm 95 na hyperlink -- PARAM_LINK_ZALM95_BEGIN
					if(equals(strbuff, PARAM_LINK_ZALM95_END) && (vnutri_inkludovaneho == 1)){
						Log("(if(equals(strbuff, PARAM_LINK_ZALM95_END)): _global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI == %d: \n", _global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI);
						char specific_string[SMALL];
						mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);
						if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) == BIT_OPT_2_ROZNE_MOZNOSTI){ // len ak je táto možnosť (zobrazovanie všeličoho) zvolená
							z95buff[z95_index] = '\0';
#ifdef BEHAVIOUR_WEB
							// najprv upravíme o1
							_global_opt_casti_modlitby_orig = _global_opt[OPT_1_CASTI_MODLITBY]; // backup pôvodnej hodnoty
							// nastavenie parametra o1: pridáme bit pre alternatívnu psalmódiu
							if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZALM95) != BIT_OPT_1_ZALM95){
								Log("Pre option 1 odstraňujem bit pre ž95 (pôvodnú hodnotu som si zapamätal)\n");
								_global_opt[OPT_1_CASTI_MODLITBY] += BIT_OPT_1_ZALM95;
							}
							else{
								Log("Pre option 1 pridávam bit pre ž95 (pôvodnú hodnotu som si zapamätal)\n");
								_global_opt[OPT_1_CASTI_MODLITBY] -= BIT_OPT_1_ZALM95;
							}
							// prilepenie poradia svätca
							if(_global_poradie_svaty > 0){
								sprintf(pom, HTML_AMPERSAND"%s=%d", STR_DALSI_SVATY, _global_poradie_svaty);
							}// _global_poradie_svaty > 0
							else{
								mystrcpy(pom, STR_EMPTY, MAX_STR);
							}// !(_global_poradie_svaty > 0)
							// teraz vytvoríme reťazec s options
							prilep_request_options(pom, pompom);

							// v hyperlinku prilepíme aj #ZALM95 (do z95.htm a ostatných sme doplnili <a name...>) // napokon prilepíme #anchor // 2012-10-01 -> 2012-11-23 podobne ako v _export_link_show_hide()
							sprintf(pompom, "#%s", PARAM_ZALM95);
							strcat(pom, pompom);

							// export hyperlinku
							if(query_type == PRM_DATUM){
								Export("%s\n<"HTML_SPAN_RED_SMALL">\n<a href=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\"",
									specific_string,
									script_name,
									STR_QUERY_TYPE, STR_PRM_DATUM,
									STR_DEN, _global_den.den,
									STR_MESIAC, _global_den.mesiac,
									STR_ROK, _global_den.rok,
									STR_MODLITBA, str_modlitby[_global_modlitba],
									pom);
							}
							else if(query_type == PRM_LIT_OBD){
								Export("%s\n<"HTML_SPAN_RED_SMALL">\n<a href=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%c"HTML_AMPERSAND"%s=%s%s\"",
									specific_string,
									script_name,
									STR_QUERY_TYPE, STR_PRM_LIT_OBD,
									STR_DEN_V_TYZDNI, _global_den.denvt,
									STR_TYZDEN, _global_den.tyzden,
									STR_LIT_OBD, _global_den.litobd,
									STR_LIT_ROK, _global_den.litrok,
									STR_MODLITBA, str_modlitby[_global_modlitba],
									pom);
							}
							// napokon o1 vrátime späť
							_global_opt[OPT_1_CASTI_MODLITBY] = _global_opt_casti_modlitby_orig; // restore pôvodnej hodnoty
							/*
							// pre žalm 95 by nemalo za referenciou nasledovať nič; ak, tak to nevypisujeme
							DetailLog("\trest     == %s\n", rest);
							DetailLog("\tz95rest  == %s\n", z95rest);
							if((z95rest != NULL) && !(equals(z95rest, STR_EMPTY))){
								// Export("%s", z95rest);
							}
							*/
							Export(" "HTML_CLASS_QUIET">"); // a.quiet { text-decoration:none; color: inherit; }
#endif
							Export("%s", z95buff);
#ifdef BEHAVIOUR_WEB
							Export("</a>");
							Export(HTML_SPAN_END"\n");
#endif
						}
						else{
#if defined(EXPORT_HTML_SPECIALS)
							Export("<!--%s-->", PARAM_LINK_ZALM95_BEGIN);
#endif
						}
						vnutri_z95 = NIE;
						// prevzaté z časti pre referencie: 2011-05-02: doplnené kvôli referenciám, ktoré sú v rámci myšlienok, čo sa nemajú zobrazovať
						write = ANO;
						strcpy(z95rest, STR_EMPTY);
					}// upraviť odkaz na žalm 95 na hyperlink -- PARAM_LINK_ZALM95_END

					// 2011-07-14: zobraziť/nezobraziť zalomenie veršov podľa tlačenej LH
					if(equals(strbuff, PARAM_ZALOMENIE) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
						Export("[%s:%s|rest=%s]", strbuff, modlparam, (rest == NULL) ? STR_EMPTY: rest);
/*
#elif defined(EXPORT_HTML_FILENAME_ANCHOR)
						Export("[%s:%s]", strbuff, modlparam);
#elif defined(EXPORT_HTML_ANCHOR)
						Export("%s:%s", strbuff, modlparam);
*/
#endif
						if((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_TEXT_WRAP) == BIT_OPT_2_TEXT_WRAP){
							// MAX_BUFFER bol zvýšený, lebo strbuff bol v tomto prípade veľmi dlhý
							Export("zalomenie-->%s<!--zalomenie", rest);
						}
						else{
#if defined(EXPORT_HTML_SPECIALS)
							Export("zalomenie-nie");
#endif
						}
					}// zobraziť/nezobraziť zalomenie veršov podľa tlačenej LH -- PARAM_ZALOMENIE

					// 2011-04-04: zobraziť/nezobraziť číslovanie veršov
					if(equals(strbuff, PARAM_CISLO_VERSA_BEGIN) && (vnutri_inkludovaneho == 1)){
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_VERSE) == BIT_OPT_0_VERSE){
							Export("<sup>");
						}
						else{
							write = NIE;
#if defined(EXPORT_HTML_SPECIALS)
							Export("<!--č.verša:zač.");
#endif
							Log("  ruším writing to export file, kvôli PARAM_CISLO_VERSA_BEGIN...\n");
						}
					}// zobraziť/nezobraziť číslovanie veršov
					if(equals(strbuff, PARAM_CISLO_VERSA_END) && (vnutri_inkludovaneho == 1)){
						if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_VERSE) == BIT_OPT_0_VERSE){
							Export("</sup>");
						}
						else{
							write = ANO;
#if defined(EXPORT_HTML_SPECIALS)
							Export("č.verša:end-->");
#endif
							Log("  opäť writing to export file, PARAM_CISLO_VERSA_END...\n");
						}
					}// zobraziť/nezobraziť číslovanie veršov

					// 2013-04-03: prenesená oprava z interpretParameter(): 2008-05-08: opravené, aby sa správne používalo - ant. na nunk dimittis pre kompletórium
					if((!(je_velka_noc)) && (equals(rest, PARAM_ALELUJA_VO_VELKONOCNOM))){
						if(equals(strbuff, INCLUDE_BEGIN) && (vnutri_inkludovaneho == 1)){
							write = NIE;
#if defined(EXPORT_HTML_SPECIALS)
							Export("(stop)nie je v.o.");
#endif
							Log("  rusim writing to export file, kvoli V.O. Aleluja...\n");
						}
						else if(equals(strbuff, INCLUDE_END) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("nie je v.o.(start)");
#endif
							write = ANO;
							Log("  opat writing to export file, end of V.O. Aleluja.\n");
						}
					}// aleluja vo veľkonočnom období

					// 2009-01-28, doplnené: aleluja mimo pôstneho obdobia - doteraz fungovala len pre templáty -- interpretParameter()
					if((je_post) && (equals(rest, PARAM_ALELUJA_NIE_V_POSTE))){
						if(equals(strbuff, INCLUDE_BEGIN) && (vnutri_inkludovaneho == 1)){
							write = NIE;
#if defined(EXPORT_HTML_SPECIALS)
							Export("(stop)je post");
#endif
							Log("  rusim writing to export file, kvoli Aleluja...\n");
						}
						else if(equals(strbuff, INCLUDE_END) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("nie je post(start)");
#endif
							write = ANO;
							Log("  opat writing to export file, end of Aleluja.\n");
						}
					}// aleluja mimo pôstneho obdobia

					// 2009-04-08, doplnené: zakončenie modlitby (pre modlitbu cez deň a kompletórium sa používa kratšie zakončenie)
					// 2011-10-07, upravené: zakončenia modlitieb presunuté inde

					// 2011-07-07, doplnené: zobrazovanie/skrývanie dlhšieho zakončenia responzória po druhom čítaní (tlačená verzia má kratšie zakončenie, pokiaľ nie je responzórium rozdelené zlomom strany, presnejšie, otočením listu)

					// plné responzórium...
					if((equals(rest, PARAM_PLNE_RESP)) || (equals(rest, PARAM_PLNE_RESP_BODKA))){
						if(equals(strbuff, INCLUDE_BEGIN) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("(start)dlhe-resp.");
#endif
							if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PLNE_RESP) == BIT_OPT_1_PLNE_RESP){
								;
							}
							else{
								write = NIE;
								Log("  ruším writing to export file, kvôli PARAM_PLNE_RESP...\n");
							}
						}// INCLUDE_BEGIN
						else if(equals(strbuff, INCLUDE_END) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("dlhe-resp.(stop)");
#endif
							if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PLNE_RESP) == BIT_OPT_1_PLNE_RESP){
								;
							}
							else{
								write = ANO;
								Log("  opäť writing to export file, PARAM_PLNE_RESP...\n");
								// 2011-07-08: ak končí iným znakom ako bodkou (napr. ?!), pri skrátenom výpise (indikovaný iným parametrom) je treba vypísať bodku
								if(equals(rest, PARAM_PLNE_RESP_BODKA)){
									Export("-->.<!--");
								}
							}
							Log("resp-koniec.\n");
						}// INCLUDE_END
					}// plné responzórium...

					// 2011-10-05, doplnené: zobrazovanie/skrývanie opakovaného zvolania v prosbách (ranné chvály, vešpery)

					// zvolanie v prosbách...
					if(equals(rest, PARAM_ZVOLANIE)){
						if(equals(strbuff, INCLUDE_BEGIN) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("(start)zvolanie");
#endif
							if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PROSBY_ZVOLANIE) == BIT_OPT_1_PROSBY_ZVOLANIE){
								;
							}
							else{
								write = NIE;
								Log("  ruším writing to export file, kvôli PARAM_ZVOLANIE...\n");
							}
						}// INCLUDE_BEGIN
						else if(equals(strbuff, INCLUDE_END) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("zvolanie(stop)");
#endif
							if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PROSBY_ZVOLANIE) == BIT_OPT_1_PROSBY_ZVOLANIE){
								// Export("-->"HTML_LINE_BREAK"<!--"); // 2012-09-07: doplnené, aby sa to podobalo na tie prosby, kde v LH je zvolanie opakované (napr. SCAP_rPROSBY) | 2012-09-28: presunuté vypisovanie len ak sa zvolania opakujú
							}
							else{
								write = ANO;
								Log("  opäť writing to export file, PARAM_ZVOLANIE...\n");
							}
							Log("zvolanie-koniec.\n");
						}// INCLUDE_END
					}// zvolanie v prosbách...

					// 2011-10-26: pridané zobrazovanie/skrývanie rubrík podľa interpretParameter()

					// rubriky
					if(equals(rest, PARAM_RUBRIKA)){
						if(equals(strbuff, INCLUDE_BEGIN) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("(start)rubrika");
#endif
							if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) == BIT_OPT_1_RUBRIKY){
								;
							}
							else{
								write = NIE;
								Log("  ruším writing to export file, kvôli PARAM_RUBRIKA...\n");
							}
						}// INCLUDE_BEGIN
						else if(equals(strbuff, INCLUDE_END) && (vnutri_inkludovaneho == 1)){
#if defined(EXPORT_HTML_SPECIALS)
							Export("rubrika(stop)");
#endif
							if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) == BIT_OPT_1_RUBRIKY){
								;
							}
							else{
								write = ANO;
								Log("  opäť writing to export file, PARAM_RUBRIKA...\n");
							}
							Log("rubrika-koniec.\n");
						}// INCLUDE_END
					}// rubriky

					// 2011-01-12: doplnené voliteľné zobrazovanie/skrývanie alternatívnej antifóny pre žalmy/chválospevy 
					// 2011-01-17: upravené tak, aby sa nezobrazovalo len pre spomienky svätých [tam spadajú aj liturgické slávenia 1.1. a pod.]
					// 2011-03-01: upravené tak, že sa nezobrazuje len pre slávnosti a sviatky; pre spomienky sa zobrazuje (smer < 5: pre trojdnie)
					// 2011-04-30: doplnené, aby sa nezobrazovalo vo Veľkonočnej oktáve
					// 2011-05-03: upravené, aby sa nastavovalo vnutri_myslienky kvôli tomu, že z viacerých miest sa nastavovalo write
					if(equals(rest, PARAM_PSALMODIA_MYSLIENKA)){
						if(je_myslienka){
#if defined(EXPORT_HTML_SPECIALS)
							Export("myslienka");
#endif
						}
						else{
							if(equals(strbuff, INCLUDE_BEGIN)){
								vnutri_myslienky = ANO;
								if(vnutri_inkludovaneho == 1){
									write = NIE;
#if defined(EXPORT_HTML_SPECIALS)
									Export("(stop)nie je myslienka");
#endif
									Log("  rusim writing to export file, kvoli myslienka-k-zalmu...\n");
								}// vnutri_inkludovaneho == 1
							}// INCLUDE_BEGIN
							else if(equals(strbuff, INCLUDE_END)){
								vnutri_myslienky = NIE;
								if(vnutri_inkludovaneho == 1){
#if defined(EXPORT_HTML_SPECIALS)
									Export("nie je myslienka(start)");
#endif
									write = ANO;
									Log("  opat writing to export file, end of myslienka-k-zalmu.\n");
								}// vnutri_inkludovaneho == 1
							}// INCLUDE_END
						}
					}// voliteľné zobrazovanie/skrývanie alternatívnej antifóny pre žalmy/chválospevy

					// 2011-08-31: doplnené voliteľné zobrazovanie/skrývanie nadpisu pre žalmy/chválospevy podľa myšlienky
					if(equals(rest, PARAM_PSALMODIA_NADPIS)){
						if(je_nadpis){
#if defined(EXPORT_HTML_SPECIALS)
							Export("nadpis");
#endif
						}
						else{
							if(equals(strbuff, INCLUDE_BEGIN)){
								vnutri_nadpisu = ANO;
								if(vnutri_inkludovaneho == 1){
									write = NIE;
#if defined(EXPORT_HTML_SPECIALS)
									Export("(stop)nie je nadpis");
#endif
									Log("  rusim writing to export file, kvoli psalmodia-nadpis...\n");
								}// vnutri_inkludovaneho == 1
							}// INCLUDE_BEGIN
							else if(equals(strbuff, INCLUDE_END)){
								vnutri_nadpisu = NIE;
								if(vnutri_inkludovaneho == 1){
#if defined(EXPORT_HTML_SPECIALS)
									Export("nie je nadpis(start)");
#endif
									write = ANO;
									Log("  opat writing to export file, end of psalmodia-nadpis.\n");
								}// vnutri_inkludovaneho == 1
							}// INCLUDE_END
						}
					}// voliteľné zobrazovanie/skrývanie nadpisu pre žalmy/chválospevy

				}// !equalsi(rest, modlparam)
				continue;
		}// switch(c)
		if(!isbuff){
			if(vnutri_referencie == ANO){
				// bez ohľadu na to, ako je nastavené write
				AppendWchar(c, sizeof(refbuff), refbuff, &ref_index);
			}
			if(vnutri_katechezy == ANO){
				// bez ohľadu na to, ako je nastavené write
				AppendWchar(c, sizeof(katbuff), katbuff, &kat_index);
			}
			if(vnutri_z95 == ANO){
				// bez ohľadu na to, ako je nastavené write
				AppendWchar(c, sizeof(z95buff), z95buff, &z95_index);
			}
			if(write == ANO){
				// 2011-05-02: nezlomiteľné medzery; v DetailLog logujeme 1:1 presne znak bez transformácie
				ExportChar(c);
				// DetailLog("%c", c);
			}
			else{
				; //skip
			}
		}// if(!isbuff)
		else{
                        AppendWchar(c, sizeof(strbuff), strbuff, &buff_index);
			// 2011-03-29: doplnená kontrola, či nejde o osamotený znak '{'
			if(((isbuff == 1) && (strlen(strbuff) > MAX_BUFFER - 2)) || (buff_index > MAX_BUFFER - 2)){
				Log("pravdepodobne osamotený znak '{'...\n");
				isbuff = 0;
				if(write == ANO){
					// 2011-05-02: nezlomiteľné medzery; v DetailLog logujeme 1:1 presne reťazec bez transformácie
					Export("%s", convert_nonbreaking_spaces(strbuff));
					// DetailLog("%s", strbuff);
				}
				// vyčistenie buffra
				buff_index = 0;
				strbuff[buff_index] = '\0';
			}// osamotený znak '{'
		}// else if(!isbuff)
	}// while((c = fgetc(body)) != EOF)
	fclose(body);
	Log("--includeFile(): end\n");
}// includeFile()

void _export_rozbor_dna_navig_top_bottom(char *target, const char *text){
	Export("\n<!--p-navigation-->\n");
	Export("<p "HTML_ALIGN_CENTER" "HTML_CLASS_SMALL">");
	Export("<a href=\"#%s\""HTML_CLASS_QUIET">%s</a>", target, text);
	Export("</p>");
}// _export_rozbor_dna_navig_top_bottom()

// --------------------------------------------------------------------

void init_marianske_anfifony_file(_struct_anchor_and_file &af){
	mystrcpy(af.anchor, ANCHOR_MARIANSKE_ANTIFONY, MAX_STR_AF_ANCHOR);
	mystrcpy(af.file, FILE_MARIANSKE_ANTIFONY, MAX_STR_AF_FILE);
	/*
	mystrcpy(af.file, ".."STR_PATH_SEPARATOR_HTML, MAX_STR_AF_FILE);
	if(strlen(postfix_jazyka[_global_jazyk]) > 0){
		strcat(af.file, postfix_jazyka[_global_jazyk]);
		strcat(af.file, STR_PATH_SEPARATOR_HTML);
	}
	strcat(af.file, DOCS_FOLDER""STR_PATH_SEPARATOR_HTML);
	strcat(af.file, FILE_MARIANSKE_ANTIFONY);
	*/
	Log_filename_anchor(af);
	return;
}

void init_url_marianske_antifony(char url[MAX_STR]){
	Log("init_url_marianske_antifony(): začiatok...\n");
	char pom2[MAX_STR];
	char pom3[MAX_STR];
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	prilep_request_options(pom2, pom3);

	sprintf(pom3, HTML_LINK_CALL3, script_name, STR_QUERY_TYPE, STR_PRM_STATIC_TEXT, STR_STATIC_TEXT, skratka_static_text[STATIC_TEXT_MARIANSKE_ANTIFONY], pom2);
	
	mystrcpy(url, pom3, MAX_STR);
	Log("URL == %s\n", url);

	Log("init_url_marianske_antifony(): koniec.\n");
}

void init_ordinarium_file(_struct_anchor_and_file &af, short int modlitba){
	mystrcpy(af.anchor, ANCHOR_ORDINARIUM, MAX_STR_AF_ANCHOR);
	mystrcpy(af.file, ORDINARIUM[modlitba], MAX_STR_AF_FILE);
	Log_filename_anchor(af);
	return;
}


//---------------------------------------------------------------------
// definicie pre _rozbor_dna():
// obsahuju sviatky, ktore su bud pevne alebo pohyblive, v kazdom pripade su to dolezite "hranicne" dni medzi obdobiami
// 2011-05-03: predsunuté pred interpretParameter(), lebo sa tu používajú
// 2012-04-02: presunuté do breviar.h, lebo sa používa aj v includeFile(), tam používame VELKONOCNA_NEDELA

//---------------------------------------------------------------------
// interpretParameter():
// dostane vstup to, co sa pri parsovani templatu nachadza medzi znakmi CHAR_KEYWORD_BEGIN a CHAR_KEYWORD_END;
// zrejme ide o parameter; podla neho inkluduje subor (alebo cast suboru)
// 27/04/2000A.D.: pozmenene (pridane #definy):
//    -- je_post(): odpoved je kladna, ak je niektore z nasledujucich
//                 * OBD_POSTNE_I
//                 * OBD_POSTNE_II_VELKY_TYZDEN
//                 * OBD_VELKONOCNE_TROJDNIE && (den == piatok || sobota)
//    -- je_velka_noc(): odpoved je kladna, ak je niektore z nasledujucich
//                 * OBD_VELKONOCNE_I
//                 * OBD_VELKONOCNE_II
//                 * OBD_VELKONOCNE_TROJDNIE && (den == nedela)
//    -- je_aleluja_aleluja(): odpoved je kladna, ak je splnene niektore z nasledovnych
//                 * OBD_VELKONOCNA_OKTAVA
//                 * OBD_VELKONOCNE_TROJDNIE && (den == nedela)
//                 * _ZOSLANIE_DUCHA_SV && MODL_VESPERY
// 2007-04-10: Doplnené: Te Deum je vo veľkonočnej oktáve; nie je počas pôstu (ani len pre nedele)
// 2009-01-06: Doplnené: Te Deum je aj v oktáve narodenia Pána (vianočná oktáva)
// 2009-01-28: jednotlivé define presunuté na začiatok súboru, nakoľko ich používa nielen interpretParameter(), ale aj includeFile()

// 2007-11-20: doplnené @ifdef EXPORT_HTML_SPECIALS
void interpretParameter(short int type, char *paramname, short int aj_navigacia = ANO){
	char path[MAX_STR] = STR_EMPTY;
	mystrcpy(path, include_dir, MAX_STR);
	// 2004-03-17 // strcat(path, FILE_PATH); // prerobene 05/06/2000A.D.
	// short int _local_skip_in_prayer = _global_skip_in_prayer; // 2011-04-07: zapamätáme si pôvodný stav
	// short int _global_opt_casti_modlitby_orig; // parameter o1 (_global_opt 1) pre modlitbu cez deň (doplnková psalmódia)

	short int zobrazit = NIE;
	_struct_sc sc;

	Log("interpretParameter(%s): Dumping by %s\n", paramname, paramname);

	if(equals(paramname, PARAM_CISLO_VERSA_BEGIN)){
		if(_global_skip_in_prayer != ANO){
			if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_VERSE) == BIT_OPT_0_VERSE){
				Export("<sup>");
			}
			else{
				// Log("  ruším writing to export file, kvôli PARAM_CISLO_VERSA_BEGIN...\n");
				_global_skip_in_prayer_2 = ANO;
				// Export("<!--");
			}
		}// skip in prayer
	}// zobraziť/nezobraziť číslovanie veršov
	else if(equals(paramname, PARAM_CISLO_VERSA_END)){
		if(_global_skip_in_prayer != ANO){
			if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_VERSE) == BIT_OPT_0_VERSE){
				Export("</sup>");
			}
			else{
				// Log("  opäť writing to export file, PARAM_CISLO_VERSA_END...\n");
				// Export("-->");
				_global_skip_in_prayer_2 = NIE;
			}
		}// skip in prayer
	}// zobraziť/nezobraziť číslovanie veršov
	else if(equals(paramname, PARAM_ALELUJA_NIE_V_POSTE_BEGIN)){
		if(!je_post){
#if defined(EXPORT_HTML_SPECIALS)
			Export("nie je pôst");
#endif
			Export("-->");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("je pôst(");
#endif
			Log("(beg)je postne obdobie\n");
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_NIE_V_POSTE_END)){
		if(!je_post){
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("nie je pôst");
#endif
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export(")je pôst");
#endif
			Log("(end)je postne obdobie\n");
		}
	}
	// 2008-05-08: opravené, aby sa správne používalo - ant. na nunk dimittis pre kompletórium
	else if(equals(paramname, PARAM_ALELUJA_VO_VELKONOCNOM_BEGIN)){
		if(je_velka_noc){
#if defined(EXPORT_HTML_SPECIALS)
			Export("je veľkonočné obdobie");
#endif
			Export("-->");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("nie je v.o.(");
#endif
			Log("(beg)nie je velkonocne obdobie\n");
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_VO_VELKONOCNOM_END)){
		if(je_velka_noc){
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("je veľkonočné obdobie");
#endif
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export(")nie je v.o.");
#endif
			Log("(end)nie je velkonocne obdobie\n");
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_ALELUJA_BEGIN)){
		if(_global_skip_in_prayer == ANO){
			// ak zakoncenie preskakujem, tak musim sa tvarit, ze nic
#if defined(EXPORT_HTML_SPECIALS)
			Export("{AAB:skip}");
#endif
			Log("  ALELUJA_ALELUJA_BEGIN: skipping -- because skipping ZAKONCENIE\n");
		}
		else{
			// Od nedele Pánovho zmŕtvychvstania až do Druhej veľkonočnej nedele vrátane, ako aj na druhé vešpery slávnosti Zoslania Ducha Svätého (teda veľkonočná oktáva + zakončenie veľkonočného obdobia)
			if(je_aleluja_aleluja){
#if defined(EXPORT_HTML_SPECIALS)
				Export("veľkonočná oktáva");
#endif
				Export("-->");
				Log("  ALELUJA_ALELUJA_BEGIN: copying\n");
			}
			else{
				Log("  ALELUJA_ALELUJA_BEGIN: skipping -- because not velkonocna oktava\n");
			}
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_ALELUJA_END)){
		if(_global_skip_in_prayer == ANO){
			// ak zakoncenie preskakujem, tak musim sa tvarit, ze nic
			// preto otvorim poznamku, ktora sa zacala
#if defined(EXPORT_HTML_SPECIALS)
			Export("{AAE:skip}");
#endif
			Log("  ALELUJA_ALELUJA_END: skipping -- because skipping ZAKONCENIE\n");
		}
		else{
			// Od nedele Pánovho zmŕtvychvstania až do Druhej veľkonočnej nedele vrátane, ako aj na druhé vešpery slávnosti Zoslania Ducha Svätého (teda veľkonočná oktáva + zakončenie veľkonočného obdobia)
			if(je_aleluja_aleluja){
				Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
				Export("veľkonočná oktáva");
#endif
				Log("  ALELUJA_ALELUJA_END: copying\n");
			}
			else{
				Log("  ALELUJA_ALELUJA_END: skipping -- because not velkonocna oktava\n");
			}
		}
	}
	// teraz nasleduje kontrola options pre modlitbu
	else if(equals(paramname, PARAM_OTCENAS_BEGIN)){
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_OTCENAS) == BIT_OPT_1_OTCENAS){
			// zobrazit Otcenas
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť Otčenáš");
#endif
			Export("-->");
			Log("  `Otcenas': begin...\n");
		}
		else{
			// nezobrazovat Otcenas
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť Otčenáš");
#endif
			Log("  `Otcenas' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_OTCENAS_END)){
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_OTCENAS) == BIT_OPT_1_OTCENAS){
			// zobrazit Otcenas
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť Otčenáš");
#endif
			Log("  `Otcenas': copied.\n");
		}
		else{
			// nezobrazovat Otcenas
			_global_skip_in_prayer = NIE;
			Log("  `Otcenas' skipped.\n");
		}
	}
	else if(equals(paramname, PARAM_CHVALOSPEV_BEGIN)){
		Log("_global_opt[OPT_1_CASTI_MODLITBY == %d] == %d\n", OPT_1_CASTI_MODLITBY, _global_opt[OPT_1_CASTI_MODLITBY]);
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_CHVALOSPEVY) == BIT_OPT_1_CHVALOSPEVY){
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť chválospev");
#endif
			Log("  `chvalospev': begin...\n");
		}
		else{
			// nezobrazovat chvalospev
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť chválospev");
#endif
			Log("  `chvalospev' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_CHVALOSPEV_END)){
		Log("_global_opt[OPT_1_CASTI_MODLITBY == %d] == %d\n", OPT_1_CASTI_MODLITBY, _global_opt[OPT_1_CASTI_MODLITBY]);
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_CHVALOSPEVY) == BIT_OPT_1_CHVALOSPEVY){
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť chválospev");
#endif
			Log("  `chvalospev' copied.\n");
		}
		else{
			// nezobrazovat chvalospev
			_global_skip_in_prayer = NIE;
			Log("  `chvalospev' skipped.\n");
		}
	}
	// 2007-06-28: podmienka na Te Deum osamostatnená 
	// 2011-04-11: pridané voliteľné NEzobrazovanie celého hymnu (ostane len nadpis v podobe rubrikového small caps headingu) nižšie nasleduje samotné vypísanie textu chválospevu Te Deum, ak _global_opt[OPT_1_CASTI_MODLITBY]...
	else if(equals(paramname, PARAM_TEDEUM_BEGIN)){
		Log("_global_opt[OPT_1_CASTI_MODLITBY == %d] == %d\n", OPT_1_CASTI_MODLITBY, _global_opt[OPT_1_CASTI_MODLITBY]);

		if(((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_TEDEUM) == BIT_OPT_1_TEDEUM) && (_global_opt_tedeum == ANO) && (_global_skip_in_prayer != ANO)){
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť Te Deum");
#endif
			Log("  `Te Deum': begin...\n");
		}
		else{
			// nezobrazovať Te Deum, hoci daná modlitba ho má -- vtedy len nadpis
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť Te Deum");
#endif
			Log("  `Te Deum' skipping...\n");
		}
	}// if(equals(paramname, PARAM_TEDEUM_BEGIN))
	else if(equals(paramname, PARAM_TEDEUM_END)){
		if(((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_TEDEUM) == BIT_OPT_1_TEDEUM) && (_global_opt_tedeum == ANO) && (_global_skip_in_prayer != ANO)){
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť Te Deum");
#endif
			Log("  `Te Deum' copied.\n");
		}
		else{
			// nezobrazovať Te Deum [či už preto, že nemá byť, alebo preto, lebo ho používateľ nechcel]
			if(_global_opt_tedeum == ANO){
				_global_skip_in_prayer = NIE; // nesmie tu byť, ak tedeum nemá byť; až PARAM_JE_TEDEUM_END to (v takom prípade) nastaví na NIE
			}
			Log("  `Te Deum' skipped.\n");
		}
	}// if(equals(paramname, PARAM_TEDEUM_END))
	// 2007-06-28: podmienka na Te Deum osamostatnená 
	// 2011-04-11: pridané voliteľné NEzobrazovanie celého hymnu (ostane len nadpis v podobe rubrikového small caps headingu) tu je uvedené len zobrazenie/nezobrazenie uvedeného nadpisu
	else if(equals(paramname, PARAM_JE_TEDEUM_BEGIN)){
		if(_global_opt_tedeum == NIE){ // 2007-05-18 pridaná podmienka na tedeum
			// nezobrazovat Te Deum
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nemá byť Te Deum");
#endif
			Log("  `Te Deum' heading skipping...\n");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("má byť Te Deum");
#endif
			Log("  `Te Deum' heading: begin...\n");
		}
	}// if(equals(paramname, PARAM_JE_TEDEUM_BEGIN))
	else if(equals(paramname, PARAM_JE_TEDEUM_END)){
		if(_global_opt_tedeum == NIE){
			// nezobrazovat Te Deum
			_global_skip_in_prayer = NIE;
			Log("  `Te Deum' heading skipped.\n");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("má byť Te Deum");
#endif
			Log("  `Te Deum' heading copied.\n");
		}
	}// if(equals(paramname, PARAM_JE_TEDEUM_END))

	// 2012-05-24: doplnené -- predĺžené slávenie vigílií v rámci posvätných čítaní
	else if(equals(paramname, PARAM_JE_VIGILIA_BEGIN)){
		_global_som_vo_vigilii = ANO;
		// 2013-02-28: nechápem, prečo tu bola podmienka aj na Te Deum, ktoré napr. v Pôstnom období nie je, hoci je tam predĺžené slávenie vigílie
		if(((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PC_VIGILIA) != BIT_OPT_1_PC_VIGILIA) || !(je_vigilia)){
			// nezobrazovať vigíliu
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nemá byť vigília");
#endif
			Log("  `vigília' heading skipping...\n");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("má byť vigília");
#endif
			Log("  `vigília' heading: begin...\n");
		}
	}// if(equals(paramname, PARAM_JE_VIGILIA_BEGIN))
	else if(equals(paramname, PARAM_JE_VIGILIA_END)){
		_global_som_vo_vigilii = NIE;
		if((_global_opt_tedeum == NIE) || ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PC_VIGILIA) != BIT_OPT_1_PC_VIGILIA) || !(je_vigilia)){
			// nezobrazovať vigíliu
			_global_skip_in_prayer = NIE;
			Log("  `vigília' heading skipped.\n");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("má byť vigília");
#endif
			Log("  `vigília' heading copied.\n");
		}
	}// if(equals(paramname, PARAM_JE_VIGILIA_END))

	else if(equals(paramname, PARAM_ZAKONCENIE_BEGIN)){
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) != BIT_OPT_1_RUBRIKY){
			// nezobrazit zakoncenie
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť zakončenie");
#endif
			Log("  `zakoncenie' skipping...\n");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť zakončenie");
#endif
			Export("-->");
			Log("  `zakoncenie': begin...\n");
		}
	}
	else if(equals(paramname, PARAM_ZAKONCENIE_END)){
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) != BIT_OPT_1_RUBRIKY){
			// nezobrazit zakoncenie
			_global_skip_in_prayer = NIE;
			Log("  `zakoncenie' skipped.\n");
		}
		else{
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť zakončenie");
#endif
			Log("  `zakoncenie' copied.\n");
		}
	}

	else if(equals(paramname, PARAM_KOMPLETORIUM_DVA_ZALMY_BEGIN)){
		Log("interpretParameter(): _global_modl_kompletorium.pocet_zalmov == %d...\n", _global_modl_kompletorium.pocet_zalmov);
		Log("interpretParameter(): _global_modl_prve_kompletorium.pocet_zalmov == %d...\n", _global_modl_prve_kompletorium.pocet_zalmov);
		if(_global_pocet_zalmov_kompletorium == 1){
			// nezobrazovať druhý žalm/antifónu pre kompletórium, ktoré má len 1 žalm+antifónu
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("(beg)nezobrazovať druhý žalm/ant. pre komplet., ktoré má len 1 ž.+ant.");
#endif
			Log("  `2. žalm+antifóna v kompletóriu' skipping...\n");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("(beg)zobrazovať druhý žalm/ant. pre komplet., ktoré má aj 2.ž.+ant.");
#endif
			Log("  `2. žalm+antifóna v kompletóriu': begin...\n");
		}
	}
	else if(equals(paramname, PARAM_KOMPLETORIUM_DVA_ZALMY_END)){
		if(_global_pocet_zalmov_kompletorium == 1){
			// nezobrazovať druhý žalm/antifónu pre kompletórium, ktoré má len 1 žalm+antifónu
			_global_skip_in_prayer = NIE;
			Log("  `2. žalm+antifóna v kompletóriu' skipped.\n");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("(end)zobrazovať druhý žalm/ant. pre komplet., ktoré má aj 2.ž.+ant.");
#endif
			Log("  `2. žalm+antifóna v kompletóriu' copied.\n");
		}
	}

	// 2011-04-11: pridané rubriky
	else if(equals(paramname, PARAM_RUBRIKA_BEGIN)){
		_global_pocet_slava_otcu = _global_pocet_slava_otcu + 1;
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) == BIT_OPT_1_RUBRIKY){
			// zobrazit rubriky
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť rubriku");
#endif
			Export("-->");
			Log("  `rubrika': begin...\n");
		}
		else{
			// nezobrazovať rubriky
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť rubriku");
#endif
			Log("  `rubrika' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_RUBRIKA_END)){
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) == BIT_OPT_1_RUBRIKY){
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť rubriku");
#endif
			Log("  `rubrika': copied.\n");
		}
		else{
			// nezobrazovať rubriky
			_global_skip_in_prayer = NIE;
			Log("  `rubrika' skipped.\n");
		}
	}

	// 2011-05-03: pridané preskočenie veľkej časti šablóny pre posvätné čítanie na veľkonočnú nedeľu
	else if(equals(paramname, PARAM_VN_VYNECHAJ_BEGIN)){
		if(_global_den.denvr != VELKONOCNA_NEDELA){
			// zobrazit celé posv. čítanie
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť posv.čítanie");
#endif
			Export("-->");
			Log("  `posv.čítanie': begin...\n");
		}
		else{
			// nezobrazovať celé posv. čítanie
			_global_skip_in_prayer_vnpc = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť posv.čítanie");
#endif
			Log("  `posv.čítanie' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_VN_VYNECHAJ_END)){
		if(_global_den.denvr != VELKONOCNA_NEDELA){
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť posv.čítanie");
#endif
			Log("  `posv.čítanie': copied.\n");
		}
		else{
			// zobrazovať celé posv. čítanie
			_global_skip_in_prayer_vnpc = NIE;
			Log("  `posv.čítanie' skipped.\n");
		}
	}

	// 2012-05-24: podmienka zosilnená kvôli sláva otcu vo vigíliách (vtedy preskakujeme)
	else if((equals(paramname, PARAM_SLAVAOTCU_BEGIN) || equals(paramname, PARAM_SLAVAOTCU_SPEC_BEGIN)) && (!((_global_som_vo_vigilii == ANO) && (((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PC_VIGILIA) != BIT_OPT_1_PC_VIGILIA) || !(je_vigilia))))){
		_global_pocet_slava_otcu = _global_pocet_slava_otcu + 1;
		// 2007-05-18: zosilnená podmienka, aby Sláva Otcu nebolo pre špeciálne prípady 
		// 2007-12-04: opravená podmienka, pretože nefungovala pre modlitby odlišné od ranných chvál
		// 2011-04-28: doplnením ďalších "Sláva Otcu", ktoré sa rozbaľujú, sa posunulo číslovanie, a tak radšej podmienku "_global_pocet_slava_otcu == 2" zrušíme
		// 2011-04-29: doplnené Sláva Otcu "špeciálne" pre účely chválospevu Dan 3, 57-88. 56, kde nie je "Sláva Otcu" (pôvodne to bolo dané poradím, ale templáty pre rôzne jazyky majú rozličné poradie tohto "Sláva Otcu")
		if(((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SLAVA_OTCU) == BIT_OPT_1_SLAVA_OTCU) && (
			_global_modlitba != MODL_RANNE_CHVALY
			|| (_global_modlitba == MODL_RANNE_CHVALY
				&& !(equals(paramname, PARAM_SLAVAOTCU_SPEC_BEGIN) && equals(_global_modl_ranne_chvaly.zalm2.anchor, "CHVAL_DAN3,57-88.56"))
			)
		)){
			// zobrazit Slava Otcu
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť Sláva Otcu(%d)", _global_pocet_slava_otcu);
#endif
			Export("-->");
			Log("  `Slava Otcu': begin...\n");
		}
		else{
			// nezobrazovat Slava Otcu
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť Sláva Otcu (%d)", _global_pocet_slava_otcu);
#endif
			Log("  `Slava Otcu' skipping...\n");
		}
	}
	// 2012-05-24: podmienka zosilnená kvôli sláva otcu vo vigíliách (vtedy preskakujeme)
	else if((equals(paramname, PARAM_SLAVAOTCU_END) || equals(paramname, PARAM_SLAVAOTCU_SPEC_END)) && (!((_global_som_vo_vigilii == ANO) && (((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PC_VIGILIA) != BIT_OPT_1_PC_VIGILIA) || !(je_vigilia))))){
		// 2007-05-18: zosilnená podmienka, aby Sláva Otcu nebolo pre špeciálne prípady 
		// 2007-12-04: opravená podmienka, pretože nefungovala pre modlitby odlišné od ranných chvál
		// 2011-04-28: doplnením ďalších "Sláva Otcu", ktoré sa rozbaľujú, sa posunulo číslovanie, a tak radšej podmienku "_global_pocet_slava_otcu == 2" zrušíme
		// 2011-04-29: doplnené Sláva Otcu "špeciálne" pre účely chválospevu Dan 3, 57-88. 56, kde nie je "Sláva Otcu" (pôvodne to bolo dané poradím, ale templáty pre rôzne jazyky majú rozličné poradie tohto "Sláva Otcu")
		if(((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SLAVA_OTCU) == BIT_OPT_1_SLAVA_OTCU) && (
			_global_modlitba != MODL_RANNE_CHVALY
			|| (_global_modlitba == MODL_RANNE_CHVALY
				&& !(equals(paramname, PARAM_SLAVAOTCU_SPEC_END) && equals(_global_modl_ranne_chvaly.zalm2.anchor, "CHVAL_DAN3,57-88.56"))
			)
		)){
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť Sláva Otcu(%d)", _global_pocet_slava_otcu);
#endif
			Log("  `Slava Otcu': copied.\n");
		}
		else{
			// nezobrazovat Slava Otcu
			_global_skip_in_prayer = NIE;
			Log("  `Slava Otcu' (%d) skipped.\n", _global_pocet_slava_otcu);
		}
	}

	// 2005-08-15: Pridané parsovanie PARAM_HYMNUS_34_OCR_INY_BEGIN/END
	// 2007-11-27: upravené (lebo to tam zahŕňalo ten hymnus)
	// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr a má vlastný hymnus: vtedy sa hymnus pre 34. týždeň OCR neberie
	else if(equals(paramname, PARAM_HYMNUS_34_OCR_INY_BEGIN)){
		if(!((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && ((su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type))))){
			if(je_34_ocr){
				// zobraziť alternatívny hymnus 34. týždňa OCR
#if defined(EXPORT_HTML_SPECIALS)
				Export("zobraziť alternatívny hymnus 34. týždňa OCR");
#endif
				Export("-->");
				Log("JE 34.týždeň OCR... BEGIN\n");
			}
			else{
				// nezobraziť alternatívny hymnus 34. týždňa OCR
				_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
				Export("nezobraziť alternatívny hymnus 34. týždňa OCR");
#endif
				Log("NIE JE 34.týždeň OCR... BEGIN\n");
			}
		}// pre iné ako CZ a pre CZ mimo 34. OCR kde má vlastný hymnus 
		else{
			// odvetvenie pre CZ, ak je_34_ocr a má vlastný hymnus: vtedy sa hymnus pre 34. týždeň OCR neberie
		}
	}// PARAM_HYMNUS_34_OCR_INY_BEGIN
	else if(equals(paramname, PARAM_HYMNUS_34_OCR_INY_END)){
		if(!((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && ((su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type))))){
			if(je_34_ocr){
				// zobraziť alternatívny hymnus 34. týždňa OCR
				Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
				Export("je 34.týždeň OCR");
#endif
				Log("JE 34.týždeň OCR... END\n");
			}
			else{
				// nezobraziť alternatívny hymnus 34. týždňa OCR
				_global_skip_in_prayer = NIE;
				Log("NIE JE 34.týždeň OCR... END\n");
			}
		}// pre iné ako CZ a pre CZ mimo 34. OCR kde má vlastný hymnus 
		else{
			// odvetvenie pre CZ, ak je_34_ocr a má vlastný hymnus: vtedy sa hymnus pre 34. týždeň OCR neberie
		}
	}// PARAM_HYMNUS_34_OCR_INY_END

	// 2007-10-02: pridané nezobrazovanie "Ant. 2" a pod. keď sú rovnaké antifóny na mcd
	else if(equals(paramname, PARAM_SKRY_ANTIFONU_BEGIN)){
		if(_global_ant_mcd_rovnake == NIE){
			// zobrazit nazvy antifon
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť ant.");
#endif
			Export("-->");
			Log("  `Ant.': begin...\n");
		}
		else{
			// nezobrazovat nazvy antifon
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť ant.");
#endif
			Log("  `Ant.' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_SKRY_ANTIFONU_END)){
		if(_global_ant_mcd_rovnake == NIE){
			// zobrazit nazvy antifon
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť ant.");
#endif
			Log("  `Ant.': copied.\n");
		}
		else{
			// nezobrazovat nazvy antifon
			_global_skip_in_prayer = NIE;
			Log("  `Ant.' skipped.\n");
		}
	}

	// 2013-10-21: pridané: zobrazovanie "Ant." a pod., keď sú rovnaké antifóny na mcd | ToDo: vyriešiť krajšie
	else if(equals(paramname, PARAM_ZOBRAZ_ANTIFONU_BEGIN)){
		if(_global_ant_mcd_rovnake == ANO){
			// zobrazit nazvy antifon
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť 1 ant.");
#endif
			Export("-->");
			Log("  `Ant.': begin...\n");
		}
		else{
			// zobrazovat nazvy antifon
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť ant.");
#endif
			Log("  `Ant.' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_ZOBRAZ_ANTIFONU_END)){
		if(_global_ant_mcd_rovnake == ANO){
			// zobrazit nazvy antifon
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť 1 ant.");
#endif
			Log("  `Ant.': copied.\n");
		}
		else{
			// zobrazovat nazvy antifon
			_global_skip_in_prayer = NIE;
			Log("  `Ant.' skipped.\n");
		}
	}

	// 2010-05-21: pridané voliteľné zobrazovanie antifóny a modlitby pre spomienku svätca v pôstnom období 
	// 2010-05-24: podmienka zosilnená, aby sa v pôste nezobrazovalo "Ant." červenou farbou z templáty, ak nie je nastavená tá ant. + modlitba pre spomienku
	else if(equals(paramname, PARAM_SPOMIENKA_PRIVILEG_BEGIN)){
		if(je_privileg && je_ant_modl_spomprivileg){
			// zobraziť antifónu/modlitbu na spomienky svätcov, ktoré padnú na privilegované dni (VSLH č. 238-239)
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť spom.privileg.");
#endif
			Export("-->");
			Log("  `spom.privileg.': begin...\n");
		}
		else{
			// nezobraziť antifónu/modlitbu na spomienky svätcov, ktoré padnú na privilegované dni (VSLH č. 238-239)
			_global_skip_in_prayer = ANO;
#if defined(EXPORT_HTML_SPECIALS)
			Export("nezobraziť spom.privileg.");
#endif
			Log("  `spom.privileg.' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_SPOMIENKA_PRIVILEG_END)){
		if(je_privileg && je_ant_modl_spomprivileg){
			// zobraziť antifónu/modlitbu na spomienky svätcov, ktoré padnú na privilegované dni (VSLH č. 238-239)
			Export("<!--");
#if defined(EXPORT_HTML_SPECIALS)
			Export("zobraziť spom.privileg.");
#endif
			Log("  `spom.privileg.': copied.\n");
		}
		else{
			// nezobraziť antifónu/modlitbu na spomienky svätcov, ktoré padnú na privilegované dni (VSLH č. 238-239)
			_global_skip_in_prayer = NIE;
			Log("  `spom.privileg.' skipped.\n");
		}
	}

	else if(equals(paramname, PARAM_NADPIS)){
		Export("nadpis:begin-->");
		Export(_global_string_modlitba);
		Export("<!--nadpis:end");
	}// PARAM_NADPIS

	else if(equals(paramname, PARAM_PODNADPIS)){
		Export("podnadpis:begin-->");
		Export(_global_string_podnadpis);
		Export("<!--podnadpis:end");
	}// PARAM_PODNADPIS

	else if(equals(paramname, PARAM_SPOL_CAST)){
		Log("  _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST == %d: \n", _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST);
		Log("  _global_den.typslav == %d (%s)...\n", _global_den.typslav, nazov_slavenia(_global_den.typslav));
		zobrazit = ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST) == BIT_OPT_1_ZOBRAZ_SPOL_CAST);
		if(zobrazit == ANO){
			// ďalšie rozhodovanie
			Log("_global_poradie_svaty == %d...\n", _global_poradie_svaty);
			// 2012-08-21: pre ľubovoľné aj záväzné spomienky nemá význam | č. 236 VSLH: V modlitbe cez deň, čiže predpoludním, napoludnie a popoludní, a v kompletóriu sa neberie nič z ofícia o svätom, všetko je zo všedného dňa.
			if(_global_poradie_svaty == 0){
				zobrazit = (((_global_den.typslav != SLAV_LUB_SPOMIENKA) && (_global_den.typslav != SLAV_SPOMIENKA)) || ((_global_modlitba != MODL_PREDPOLUDNIM) && (_global_modlitba != MODL_NAPOLUDNIE) && (_global_modlitba != MODL_POPOLUDNI) && (_global_modlitba != MODL_KOMPLETORIUM) && (_global_modlitba != MODL_PRVE_KOMPLETORIUM) && (_global_modlitba != MODL_DRUHE_KOMPLETORIUM)));
				Log("_global_den.spolcast == %d\n", _global_den.spolcast);
				Log("zobrazit == %d...\n", zobrazit);
				// napokon rozkódujeme, čo je v _global_den.spolcast
				sc = _decode_spol_cast(_global_den.spolcast);
				Log("sc.a1 == %d (%s)...\n", sc.a1, nazov_spolc(sc.a1));
				zobrazit &= ((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT));
				Log("zobrazit == %d...\n", zobrazit);
			}
			// 2012-09-07: pre miestne sviatky má zmysel pre MCD (nie pre kompletórium)
			else{
				zobrazit &= ((_global_modlitba != MODL_KOMPLETORIUM) && (_global_modlitba != MODL_PRVE_KOMPLETORIUM) && (_global_modlitba != MODL_DRUHE_KOMPLETORIUM));
				if(zobrazit == ANO){
					if((_global_poradie_svaty > 0) && (_global_poradie_svaty < PORADIE_PM_SOBOTA)){
						zobrazit = (((_global_svaty(_global_poradie_svaty).typslav != SLAV_LUB_SPOMIENKA) && (_global_svaty(_global_poradie_svaty).typslav != SLAV_SPOMIENKA)) || ((_global_modlitba != MODL_PREDPOLUDNIM) && (_global_modlitba != MODL_NAPOLUDNIE) && (_global_modlitba != MODL_POPOLUDNI) && (_global_modlitba != MODL_KOMPLETORIUM) && (_global_modlitba != MODL_PRVE_KOMPLETORIUM) && (_global_modlitba != MODL_DRUHE_KOMPLETORIUM)));
						zobrazit |= (MIESTNE_SLAVENIE_LOKAL_SVATY(_global_poradie_svaty)) && (je_modlitba_cez_den(_global_modlitba));
						// napokon rozkódujeme, čo je v _global_svaty(_global_poradie_svaty).spolcast
						sc = _decode_spol_cast(_global_svaty(_global_poradie_svaty).spolcast);
						zobrazit &= ((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT));
					}
					else if(_global_poradie_svaty == PORADIE_PM_SOBOTA){
						zobrazit = (((_global_pm_sobota.typslav != SLAV_LUB_SPOMIENKA) && (_global_pm_sobota.typslav != SLAV_SPOMIENKA)) || ((_global_modlitba != MODL_PREDPOLUDNIM) && (_global_modlitba != MODL_NAPOLUDNIE) && (_global_modlitba != MODL_POPOLUDNI) && (_global_modlitba != MODL_KOMPLETORIUM) && (_global_modlitba != MODL_PRVE_KOMPLETORIUM) && (_global_modlitba != MODL_DRUHE_KOMPLETORIUM)));
						// zobrazit |= (MIESTNE_SLAVENIE_LOKAL_SVATY(_global_poradie_svaty)) && (je_modlitba_cez_den(_global_modlitba));
						// napokon rozkódujeme, čo je v _global_pm_sobota.spolcast
						sc = _decode_spol_cast(_global_pm_sobota.spolcast);
						zobrazit &= ((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT));
					}
				}// ináč nemá zmysel komplikované rozhodovanie (pre kompletórium)
			}
		}// ináč nemá zmysel komplikované rozhodovanie (ak nie je zvolený BIT_OPT_1_ZOBRAZ_SPOL_CAST)
		if(zobrazit == ANO){
			Log("including SPOL_CAST\n");
			Export("spol_cast:begin-->");
			Export(HTML_NEW_PARAGRAPH);
			_export_global_string_spol_cast(ANO);
			Export("<!--spol_cast:end");
		}
		else{
			Export("[skipping SPOL_CAST]");
			Log("skipping SPOL_CAST\n");
		}
	}// PARAM_SPOL_CAST

	if((equals(paramname, PARAM_CHVALOSPEV)) 
		|| (equals(paramname, PARAM_OTCENAS)) 
		|| (equals(paramname, PARAM_TEDEUM)) 
		|| (equals(paramname, PARAM_DOPLNKOVA_PSALMODIA)) 
		|| (equals(paramname, PARAM_PSALMODIA_TRI_TYZDNE))
		|| (equals(paramname, PARAM_ZVOLANIA)) 
		|| (equals(paramname, PARAM_POPIS)) 
		|| (equals(paramname, PARAM_SLAVAOTCU))
		|| (equals(paramname, PARAM_RESPONZ))
		|| (equals(paramname, PARAM_NADPIS))
		|| (equals(paramname, PARAM_KRATSIE_PROSBY))
		|| (equals(paramname, PARAM_VIGILIA)) 
		|| (equals(paramname, PARAM_ALT_HYMNUS)) 
		|| (equals(paramname, PARAM_SPOL_CAST_SPOM)) 
		){
		Log("(if((equals(paramname == %s)): _global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI == %d: \n", paramname, _global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI);

		short int bit;
		short int opt = OPT_1_CASTI_MODLITBY; // pozor, pre niektoré je to OPT_5_ALTERNATIVES

		char popis_show[SMALL];
		char popis_hide[SMALL];
		mystrcpy(popis_show, html_text_option_zobrazit[_global_jazyk], SMALL);
		mystrcpy(popis_hide, html_text_option_skryt[_global_jazyk], SMALL);

		char specific_string[SMALL];
		mystrcpy(specific_string, STR_EMPTY, SMALL);

		char anchor[SMALL];
		mystrcpy(anchor, paramname, SMALL);

		short int podmienka = ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) == BIT_OPT_2_ROZNE_MOZNOSTI); // len ak je táto možnosť (zobrazovanie všeličoho) zvolená
		podmienka &= (_global_skip_in_prayer != ANO);

		if(equals(paramname, PARAM_OTCENAS)){
			bit = BIT_OPT_1_OTCENAS;
		}
		else if(equals(paramname, PARAM_CHVALOSPEV)){
			bit = BIT_OPT_1_CHVALOSPEVY;
		}
		else if(equals(paramname, PARAM_TEDEUM)){
			bit = BIT_OPT_1_TEDEUM;
		}
		else if(equals(paramname, PARAM_ZVOLANIA)){
			bit = BIT_OPT_1_PROSBY_ZVOLANIE;
			mystrcpy(popis_show, html_text_option_zobrazit_zvolania[_global_jazyk], SMALL);
			mystrcpy(popis_hide, html_text_option_skryt_zvolania[_global_jazyk], SMALL);
			podmienka &= (!(((_global_modlitba == MODL_VESPERY) || (_global_modlitba == MODL_PRVE_VESPERY)) && ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_VESP_KRATSIE_PROSBY) == BIT_OPT_1_VESP_KRATSIE_PROSBY))); // ak sú zvolené kratšie prosby, tam sa neopakuje zvolanie (zatiaľ)
		}
		else if(equals(paramname, PARAM_KRATSIE_PROSBY)){
			bit = BIT_OPT_1_VESP_KRATSIE_PROSBY;
			mystrcpy(popis_show, html_text_option_zobrazit_kratsie_prosby[_global_jazyk], SMALL);
			mystrcpy(popis_hide, html_text_option_skryt_kratsie_prosby[_global_jazyk], SMALL);
		}
		else if(equals(paramname, PARAM_DOPLNKOVA_PSALMODIA)){
			bit = BIT_OPT_1_MCD_DOPLNKOVA;
			Log("  _global_den.typslav == %d (%s)...\n", _global_den.typslav, nazov_slavenia(_global_den.typslav));
			Log("  _global_den.smer == %d...\n", _global_den.smer);
			// pre slávnosti nemá význam | č. 134 VSLH: (...) Na modlitbu cez deň slávností, okrem tých, o ktorých sa už hovorilo, a ak nepripadnú na nedeľu, berú sa žalmy z doplnkového cyklu (graduálne).
			// OLD: podmienka &= (!((_global_den.typslav == SLAV_SLAVNOST) || (_global_den.smer < 5))); // nie pre slávnosti
			// nemá význam jedine vtedy, ak je predpísaná doplnová psalmódia; nastavuje sa vo funkcii _set_zalmy_mcd_doplnkova_psalmodia() funkciou _set_mcd_len_doplnkova_psalmodia()
			podmienka &= (!(je_len_doplnkova_psalmodia(_global_modlitba))); // nemá zmysel jedine vtedy, ak je predpísaná doplnková psalmódia
			podmienka &= (je_modlitba_cez_den(_global_modlitba)); // len pre MCD
			mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);
			mystrcpy(popis_show, html_text_option1_mcd_zalmy_ine_short[_global_jazyk], SMALL);
			mystrcpy(popis_hide, html_text_option1_mcd_zalmy_nie_ine_short[_global_jazyk], SMALL);
		}
		else if(equals(paramname, PARAM_PSALMODIA_TRI_TYZDNE)){
			bit = BIT_OPT_1_MCD_ZALTAR_TRI;
			Log("  _global_den.typslav == %d (%s)...\n", _global_den.typslav, nazov_slavenia(_global_den.typslav));
			Log("  _global_den.smer == %d...\n", _global_den.smer);
			// pre slávnosti nemá význam | č. 134 VSLH: (...) Na modlitbu cez deň slávností, okrem tých, o ktorých sa už hovorilo, a ak nepripadnú na nedeľu, berú sa žalmy z doplnkového cyklu (graduálne).
			// OLD: podmienka &= (!((_global_den.typslav == SLAV_SLAVNOST) || (_global_den.smer < 5))); // nie pre slávnosti
			// nemá význam jedine vtedy, ak je predpísaná doplnová psalmódia; nastavuje sa vo funkcii _set_zalmy_mcd_doplnkova_psalmodia() funkciou _set_mcd_len_doplnkova_psalmodia()
			podmienka &= (!(je_len_doplnkova_psalmodia(_global_modlitba))); // nemá zmysel jedine vtedy, ak je predpísaná doplnková psalmódia
			podmienka &= ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_DOPLNKOVA) != BIT_OPT_1_MCD_DOPLNKOVA); // len ak nie je zvolená možnosť brať doplnkovú psalmódiu
			podmienka &= (je_modlitba_cez_den(_global_modlitba)); // len pre MCD
			mystrcpy(popis_show, html_text_option1_mcd_zalmy_tri_short[_global_jazyk], SMALL);
			mystrcpy(popis_hide, html_text_option1_mcd_zalmy_nie_tri_short[_global_jazyk], SMALL);
		}
		else if(equals(paramname, PARAM_POPIS)){
			bit = BIT_OPT_1_SKRY_POPIS;
			// keďže logika prepínača je obrátená, je potrebné nastaviť opačne!
			mystrcpy(popis_hide, html_text_option_zobrazit[_global_jazyk], SMALL);
			mystrcpy(popis_show, html_text_option_skryt[_global_jazyk], SMALL);
			podmienka &= (je_popis);
		}
		else if(equals(paramname, PARAM_SLAVAOTCU)){
			bit = BIT_OPT_1_SLAVA_OTCU;
			sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option1_slava_otcu[_global_jazyk]);
			sprintf(popis_hide, "%s %s", html_text_option_skryt[_global_jazyk], html_text_option1_slava_otcu[_global_jazyk]);
		}
		else if(equals(paramname, PARAM_RESPONZ)){
			bit = BIT_OPT_1_PLNE_RESP;
			podmienka &= (_global_modlitba == MODL_POSV_CITANIE); // len pre posv. čítanie // ToDo: časom aj pre ranné chvály a vešpery (krátke resp.)
			mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);
			sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option1_plne_resp[_global_jazyk]);
			sprintf(popis_hide, "%s %s", html_text_option_skryt[_global_jazyk], html_text_option1_plne_resp[_global_jazyk]);
		}
		else if(equals(paramname, PARAM_NADPIS)){
			bit = BIT_OPT_1_RUBRIKY;
			mystrcpy(specific_string, HTML_LINE_BREAK, SMALL);
			sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option1_rubriky[_global_jazyk]);
			sprintf(popis_hide, "%s %s", html_text_option_skryt[_global_jazyk], html_text_option1_rubriky[_global_jazyk]);
		}
		else if(equals(paramname, PARAM_SPOL_CAST_SPOM)){
			// 2013-02-22: doplnená možnosť pre spomienky a ľubovoľné spomienky prepínať, či brať časti zo spol. časti alebo zo dňa 
			// 2013-10-08: prepínač má zmysel len vtedy, ak je spoločná časť nastavená
			bit = BIT_OPT_1_SPOMIENKA_SPOL_CAST;
			podmienka &= ((_global_den.typslav == SLAV_SPOMIENKA) || (_global_den.typslav == SLAV_LUB_SPOMIENKA));
			podmienka &= ((_global_den.spolcast != MODL_SPOL_CAST_NEBRAT) && (_global_den.spolcast != MODL_SPOL_CAST_NEURCENA) && (_global_den.spolcast != MODL_SPOL_CAST_NULL));
			// mystrcpy(specific_string, HTML_LINE_BREAK, SMALL);
			sprintf(popis_show, "%s", html_text_option1_spomienka_spolcast[_global_jazyk]);
			sprintf(popis_hide, "%s", html_text_option1_spomienka_spolcast_NIE[_global_jazyk]);
		}
		else if(equals(paramname, PARAM_VIGILIA)){
			bit = BIT_OPT_1_PC_VIGILIA;
			podmienka &= (je_vigilia); // 2013-01-25: doplnené -- predĺžené slávenie vigílií v rámci posvätných čítaní (prepínanie)
			mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);
			sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option1_vigilia[_global_jazyk]);
			sprintf(popis_hide, "%s %s", html_text_option_skryt[_global_jazyk], html_text_option1_vigilia[_global_jazyk]);
		}
		else if(equals(paramname, PARAM_ALT_HYMNUS)){
			opt = OPT_5_ALTERNATIVES;
			podmienka &= ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ALTERNATIVES) == BIT_OPT_2_ALTERNATIVES); // len ak je táto možnosť (zobrazovanie alternatívy) zvolená
			Log("podmienka == %d pred kontrolou je_alternativa_hymnus...\n", podmienka);
			podmienka &= ((je_alternativa_hymnus_ocr) || ((je_alternativa_hymnus_vn) && (_global_den.litobd == OBD_VELKONOCNE_I))); // (je_alternativa_hymnus_ocr) platí napr. pre kompletórium aj pre iné obdobia?...
			mystrcpy(specific_string, HTML_NEW_PARAGRAPH, SMALL);

			Log("podmienka == %d pred kontrolou _global_modlitba == %s...\n", podmienka, nazov_modlitby(_global_modlitba));

			// 2013-05-14: doplnená kontrola na prvé resp. druhé nedeľné kompletórium, aby hymnus bolo v Cezročnom období možno voliť aj pre nedele
			if((_global_modlitba == MODL_KOMPLETORIUM) || (_global_modlitba == MODL_PRVE_KOMPLETORIUM) || (_global_modlitba == MODL_DRUHE_KOMPLETORIUM)){
				bit = BIT_OPT_5_HYMNUS_KOMPL;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_KomplHymnusB[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_KomplHymnusA[_global_jazyk]);
			}
			else if(_global_modlitba == MODL_POSV_CITANIE){
				bit = (je_alternativa_hymnus_ocr) ? BIT_OPT_5_HYMNUS_PC : BIT_OPT_5_HYMNUS_VN_PC;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], (je_alternativa_hymnus_ocr) ? html_text_option5_PCHymnusII[_global_jazyk] : html_text_option5_PCHymnusVNferia[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], (je_alternativa_hymnus_ocr) ? html_text_option5_PCHymnusI[_global_jazyk] : html_text_option5_PCHymnusVNnedela[_global_jazyk]);
			}
			else if(_global_modlitba == MODL_PREDPOLUDNIM){
				bit = BIT_OPT_5_HYMNUS_MCD_PREDPOL;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_MCDPredHymnus2[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_MCDPredHymnus1[_global_jazyk]);
			}
			else if(_global_modlitba == MODL_NAPOLUDNIE){
				bit = BIT_OPT_5_HYMNUS_MCD_NAPOL;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_MCDNaHymnus2[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_MCDNaHymnus1[_global_jazyk]);
			}
			else if(_global_modlitba == MODL_POPOLUDNI){
				bit = BIT_OPT_5_HYMNUS_MCD_POPOL;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_MCDPoHymnus2[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_MCDPoHymnus1[_global_jazyk]);
			}
			else if(_global_modlitba == MODL_RANNE_CHVALY){
				bit = BIT_OPT_5_HYMNUS_VN_RCH;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_RChHymnusVNferia[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_RChHymnusVNnedela[_global_jazyk]);
			}
			else if(_global_modlitba == MODL_VESPERY){
				// 2013-05-14: nie je potrebné, aby tu bolo explicitne kontrolované, či ide o MODL_PRVE_VESPERY || MODL_DRUHE_VESPERY, pretože tie vždy patria nedeli; alternatívny hymnus len pre férie
				bit = BIT_OPT_5_HYMNUS_VN_VESP;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_VespHymnusVNferia[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_VespHymnusVNnedela[_global_jazyk]);
			}
			else if(_global_modlitba == MODL_PRVE_VESPERY){
				bit = BIT_OPT_5_HYMNUS_1VESP;
				sprintf(popis_show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_1VHymnusPC[_global_jazyk]);
				sprintf(popis_hide, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_option5_1VHymnusNe[_global_jazyk]);
			}
			else{
				podmienka = NIE;
			}
		}

		// má zmysel len ak platí daná podmienka
		if(podmienka){
			Log("including %s\n", paramname);
			Export("%s:begin-->", paramname);

			char before[SMALL] = STR_EMPTY;
			sprintf(before, "<p "HTML_ALIGN_CENTER" "HTML_CLASS_SMALL">");
			char after[SMALL] = STR_EMPTY;
			mystrcpy(after, "</p>", SMALL);
			_export_link_show_hide(opt, bit, /* opačné nastavenie kvôli špeciálnej podmienke, defaulty */ popis_hide, popis_show, (char *)HTML_SPAN_RED_SMALL, (char *)HTML_CLASS_QUIET, specific_string, (char *)STR_EMPTY, anchor, (char *)HTML_SPAN_END);

			Export("<!--%s:end", paramname);
		}
		else{
			Export("[skipping %s]", paramname);
			Log("skipping %s\n", paramname);
		}
	}// PARAM_CHVALOSPEV, PARAM_OTCENAS, PARAM_TEDEUM, PARAM_DOPLNKOVA_PSALMODIA, PARAM_POPIS, PARAM_SLAVAOTCU, PARAM_RESPONZ, PARAM_NADPIS, PARAM_KRATSIE_PROSBY, PARAM_VIGILIA, PARAM_ALT_HYMNUS, PARAM_SPOL_CAST_SPOM

	if(equals(paramname, PARAM_NAVIGACIA)){
		if(aj_navigacia == ANO){
#ifdef BEHAVIOUR_WEB
			// 2011-07-01: doplnená možnosť zobrazenia navigácie v texte modlitieb 
			// 2011-07-03: presunuté sem z funkcie _patka()
			_global_pocet_navigacia++;
			if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_NAVIGATION) == BIT_OPT_2_NAVIGATION){
				Export("navigácia:begin-->\n");
				Export("<!-- navigácia %d -->\n", _global_pocet_navigacia);
				if((_global_pocet_navigacia <= 1) && (_global_pocet_volani_interpretTemplate < 2)){
					_export_rozbor_dna_navig_top_bottom((char *)HTML_BOTTOM, html_text_bottom[_global_jazyk]);

					_export_rozbor_dna_buttons_dni(EXPORT_DNA_JEDEN_DEN, NIE, aj_navigacia);
					
					// najprv dni, potom modlitby
					
					Export("<table "HTML_ALIGN_CENTER">\n<tr><td>\n");
					_export_rozbor_dna_buttons(EXPORT_DNA_JEDEN_DEN, _global_poradie_svaty, NIE);
					Export("</td></tr>\n</table>\n");
				}// if((_global_pocet_navigacia <= 1) && (_global_pocet_volani_interpretTemplate < 2))
				else{
					_export_rozbor_dna_navig_top_bottom((char *)HTML_TOP, html_text_top[_global_jazyk]);

					Export("<table "HTML_ALIGN_CENTER">\n<tr><td>\n");
					_export_rozbor_dna_buttons(EXPORT_DNA_JEDEN_DEN, _global_poradie_svaty, NIE);
					Export("</td></tr>\n</table>\n");
					
					// najprv modlitby, potom dni
					
					_export_rozbor_dna_buttons_dni(EXPORT_DNA_JEDEN_DEN, NIE, aj_navigacia);
				}// _global_pocet_navigacia > 1 || (_global_pocet_volani_interpretTemplate >= 2)
				Export("<!--navigácia:end");
			}
			else{
				Export("[skipping NAVIGACIA]");
				Log("skipping NAVIGACIA\n");
			}
#endif
		}// if(aj_navigacia == ANO)
		else if(aj_navigacia == CIASTOCNE){
			Export("navigácia:begin-->\n");
			Export(HTML_NEW_PARAGRAPH"\n");
			_export_rozbor_dna_buttons_dni(EXPORT_DNA_JEDEN_DEN, NIE, aj_navigacia);
			Export("<!--navigácia:end");
#ifdef BEHAVIOUR_WEB
#endif
		}// if(aj_navigacia == CIASTOCNE)
	}// PARAM_NAVIGACIA

	// pokracuju dalsie klasicke `tagy' v modlitbach (teda templatoch)
	// 2012-10-01: odstránené "else", aby sa PARAM_POPIS správal aj ako uvedené vyššie, aj tu
	if(equals(paramname, PARAM_POPIS)){
		Log("  _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SKRY_POPIS == %d: ", _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SKRY_POPIS);
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SKRY_POPIS) != BIT_OPT_1_SKRY_POPIS){ // != preto, lebo pôvodne tu bolo: ak zobraziť popis == ANO
			Log("including POPIS\n");
			switch(type){
				case MODL_INVITATORIUM:
					strcat(path, _global_modl_invitatorium.popis.file);
					includeFile(type, paramname, path, _global_modl_invitatorium.popis.anchor);
					break;
				case MODL_RANNE_CHVALY:
					strcat(path, _global_modl_ranne_chvaly.popis.file);
					includeFile(type, paramname, path, _global_modl_ranne_chvaly.popis.anchor);
					break;
				case MODL_VESPERY:
					strcat(path, _global_modl_vespery.popis.file);
					includeFile(type, paramname, path, _global_modl_vespery.popis.anchor);
					break;
				case MODL_POSV_CITANIE:
					strcat(path, _global_modl_posv_citanie.popis.file);
					includeFile(type, paramname, path, _global_modl_posv_citanie.popis.anchor);
					break;
				// ToDo: pre modlitbu cez deň zobrazovať popis len pre sviatky a slávnosti -- 2012-08-27: bolo vyriešené v set_popis_svaty_rch_mcd_pc_vesp()
				case MODL_CEZ_DEN_9:
					strcat(path, _global_modl_cez_den_9.popis.file);
					includeFile(type, paramname, path, _global_modl_cez_den_9.popis.anchor);
					break;
				case MODL_CEZ_DEN_12:
					strcat(path, _global_modl_cez_den_12.popis.file);
					includeFile(type, paramname, path, _global_modl_cez_den_12.popis.anchor);
					break;
				case MODL_CEZ_DEN_3:
					strcat(path, _global_modl_cez_den_3.popis.file);
					includeFile(type, paramname, path, _global_modl_cez_den_3.popis.anchor);
					break;
				case MODL_KOMPLETORIUM:
					strcat(path, _global_modl_kompletorium.popis.file);
					includeFile(type, paramname, path, _global_modl_kompletorium.popis.anchor);
					break;
				case MODL_PRVE_VESPERY:
					strcat(path, _global_modl_prve_vespery.popis.file);
					includeFile(type, paramname, path, _global_modl_prve_vespery.popis.anchor);
					break;
				case MODL_PRVE_KOMPLETORIUM:
					strcat(path, _global_modl_prve_kompletorium.popis.file);
					includeFile(type, paramname, path, _global_modl_prve_kompletorium.popis.anchor);
					break;
				default:
					// tieto modlitby nemajú popis
					break;
			}// switch
		}
		else{
			Export("skipping POPIS");
			Log("skipping POPIS\n");
		}
	}// PARAM_POPIS
	else if(equals(paramname, PARAM_HYMNUS)){
		switch(type){
			case MODL_RANNE_CHVALY:
				// 2007-11-28: upravené pre český breviár
				// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr: len ak nemá vlastný hymnus, tak vtedy sa hymnus pre 34. týždeň OCR berie
				if((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && (!(su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type)))){
					Log("pro ranní chvály 34. týdne v mezidobí se bere jiný hymnus");
#if defined(EXPORT_HTML_SPECIALS)
					Export("jiný hymnus pro 34. týden mezidobí");
#endif
				}
				else{
					strcat(path, _global_modl_ranne_chvaly.hymnus.file);
					includeFile(type, paramname, path, _global_modl_ranne_chvaly.hymnus.anchor);
				}
				break;
			case MODL_CEZ_DEN_9:
				// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr: len ak nemá vlastný hymnus, tak vtedy sa hymnus pre 34. týždeň OCR berie
				if((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && (!(su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type)))){
					Log("pro modlitbu uprostřed dne 34. týdne v mezidobí se bere jiný hymnus");
#if defined(EXPORT_HTML_SPECIALS)
					Export("jiný hymnus pro 34. týden mezidobí");
#endif
				}
				else{
					strcat(path, _global_modl_cez_den_9.hymnus.file);
					includeFile(type, paramname, path, _global_modl_cez_den_9.hymnus.anchor);
				}
				break;
			case MODL_CEZ_DEN_12:
				// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr: len ak nemá vlastný hymnus, tak vtedy sa hymnus pre 34. týždeň OCR berie
				if((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && (!(su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type)))){
					Log("pro modlitbu uprostřed dne 34. týdne v mezidobí se bere jiný hymnus");
#if defined(EXPORT_HTML_SPECIALS)
					Export("jiný hymnus pro 34. týden mezidobí");
#endif
				}
				else{
					strcat(path, _global_modl_cez_den_12.hymnus.file);
					includeFile(type, paramname, path, _global_modl_cez_den_12.hymnus.anchor);
				}
				break;
			case MODL_CEZ_DEN_3:
				// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr: len ak nemá vlastný hymnus, tak vtedy sa hymnus pre 34. týždeň OCR berie
				if((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && (!(su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type)))){
					Log("pro modlitbu uprostřed dne 34. týdne v mezidobí se bere jiný hymnus");
#if defined(EXPORT_HTML_SPECIALS)
					Export("jiný hymnus pro 34. týden mezidobí");
#endif
				}
				else{
					strcat(path, _global_modl_cez_den_3.hymnus.file);
					includeFile(type, paramname, path, _global_modl_cez_den_3.hymnus.anchor);
				}
				break;
			case MODL_VESPERY:
				// 2007-11-28: upravené pre český breviár
				// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr: len ak nemá vlastný hymnus, tak vtedy sa hymnus pre 34. týždeň OCR berie
				if((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && (!(su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type)))){
					Log("pro nešpory 34. týdne v mezidobí se bere jiný hymnus");
#if defined(EXPORT_HTML_SPECIALS)
					Export("jiný hymnus pro 34. týden mezidobí");
#endif
				}
				else{
					strcat(path, _global_modl_vespery.hymnus.file);
					includeFile(type, paramname, path, _global_modl_vespery.hymnus.anchor);
				}
				break;
			case MODL_POSV_CITANIE:
				// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr: len ak nemá vlastný hymnus, tak vtedy sa hymnus pre 34. týždeň OCR berie
				if((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && (!(su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type)))){
					Log("pro modlitbu se čtením 34. týdne v mezidobí se bere jiný hymnus");
#if defined(EXPORT_HTML_SPECIALS)
					Export("jiný hymnus pro 34. týden mezidobí");
#endif
				}
				else{
					strcat(path, _global_modl_posv_citanie.hymnus.file);
					includeFile(type, paramname, path, _global_modl_posv_citanie.hymnus.anchor);
				}
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.hymnus.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.hymnus.anchor);
				break;
			case MODL_PRVE_VESPERY:
				// 2011-11-22: odvetvenie pre CZ, ak je_34_ocr: len ak nemá vlastný hymnus, tak vtedy sa hymnus pre 34. týždeň OCR berie
				if((_global_jazyk == JAZYK_CZ) && (je_34_ocr) && (!(su_inv_hymnus_kcit_kresp_benmagn_prosby_vlastne(type)))){
					Log("pro nešpory 34. týdne v mezidobí se bere jiný hymnus");
#if defined(EXPORT_HTML_SPECIALS)
					Export("jiný hymnus pro 34. týden mezidobí");
#endif
				}
				else{
					strcat(path, _global_modl_prve_vespery.hymnus.file);
					includeFile(type, paramname, path, _global_modl_prve_vespery.hymnus.anchor);
				}
				break;
			case MODL_PRVE_KOMPLETORIUM:
				strcat(path, _global_modl_prve_kompletorium.hymnus.file);
				includeFile(type, paramname, path, _global_modl_prve_kompletorium.hymnus.anchor);
				break;
			default:
				// tieto modlitby nemajú hymnus
				break;
		}// switch
	}// PARAM_HYMNUS
	else if(equals(paramname, PARAM_ANTIFONA1)){
		antifona_pocet++;
		switch(type){
			case MODL_INVITATORIUM:
				strcat(path, _global_modl_invitatorium.antifona1.file);
				includeFile(type, paramname, path, _global_modl_invitatorium.antifona1.anchor);
				break;
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.antifona1.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.antifona1.anchor);
				break;
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.antifona1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.antifona1.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.antifona1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.antifona1.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.antifona1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.antifona1.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona1.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona1.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.antifona1.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.antifona1.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.antifona1.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.antifona1.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.antifona1.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.antifona1.anchor);
				break;
			case MODL_PRVE_KOMPLETORIUM:
				strcat(path, _global_modl_prve_kompletorium.antifona1.file);
				includeFile(type, paramname, path, _global_modl_prve_kompletorium.antifona1.anchor);
				break;
			default:
				// tieto modlitby nemaju antifonu1
				break;
		}// switch
	}// PARAM_ANTIFONA1
	else if(equals(paramname, PARAM_ANTIFONA1x)){
		antifona_pocet++;
		switch(type){
			case MODL_CEZ_DEN_9:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_9.antifona1.file);
					includeFile(type, PARAM_ANTIFONA1, path, _global_modl_cez_den_9.antifona1.anchor);
				}
				break;
			case MODL_CEZ_DEN_12:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_12.antifona1.file);
					includeFile(type, PARAM_ANTIFONA1, path, _global_modl_cez_den_12.antifona1.anchor);
				}
				break;
			case MODL_CEZ_DEN_3:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_3.antifona1.file);
					includeFile(type, PARAM_ANTIFONA1, path, _global_modl_cez_den_3.antifona1.anchor);
				}
				break;
			case MODL_KOMPLETORIUM:
				if((_global_ant_mcd_rovnake == NIE) /* (_global_modl_kompletorium.pocet_zalmov == 2) */){
					strcat(path, _global_modl_kompletorium.antifona1.file);
					includeFile(type, PARAM_ANTIFONA1, path, _global_modl_kompletorium.antifona1.anchor);
				}
				break;
			case MODL_PRVE_KOMPLETORIUM:
				if((_global_ant_mcd_rovnake == NIE) /* (_global_modl_kompletorium.pocet_zalmov == 2) */){
					strcat(path, _global_modl_prve_kompletorium.antifona1.file);
					includeFile(type, paramname, path, _global_modl_prve_kompletorium.antifona1.anchor);
				}
				break;
			default:
				// tieto modlitby nemajú antifonu1x (má to len mcd)
				break;
		}// switch
	}// PARAM_ANTIFONA1x
	else if(equals(paramname, PARAM_ANTIFONA2)){
		antifona_pocet++;
		switch(type){
			// ranné chvály nie
			case MODL_CEZ_DEN_9:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_9.antifona2.file);
					includeFile(type, paramname, path, _global_modl_cez_den_9.antifona2.anchor);
				}
				break;
			case MODL_CEZ_DEN_12:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_12.antifona2.file);
					includeFile(type, paramname, path, _global_modl_cez_den_12.antifona2.anchor);
				}
				break;
			case MODL_CEZ_DEN_3:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_3.antifona2.file);
					includeFile(type, paramname, path, _global_modl_cez_den_3.antifona2.anchor);
				}
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona2.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona2.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.antifona2.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.antifona2.anchor);
				break;
			case MODL_KOMPLETORIUM:
				// 2008-04-03: pridaná podmienka, aby sa preskakovalo v modlitbe kompletória pre veľkonočné obdobie - vnorená kotva
				Log("interpretParameter(): _global_modl_kompletorium.pocet_zalmov == %d...\n", _global_modl_kompletorium.pocet_zalmov);
				if((_global_modl_kompletorium.pocet_zalmov == 2) && (_global_skip_in_prayer != ANO)){
					strcat(path, _global_modl_kompletorium.antifona2.file);
					includeFile(type, paramname, path, _global_modl_kompletorium.antifona2.anchor);
				}
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.antifona2.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.antifona2.anchor);
				break;
			case MODL_PRVE_KOMPLETORIUM:
				// 2008-04-03: pridaná podmienka, aby sa preskakovalo v modlitbe kompletória pre veľkonočné obdobie - vnorená kotva
				Log("interpretParameter(): _global_modl_prve_kompletorium.pocet_zalmov == %d...\n", _global_modl_prve_kompletorium.pocet_zalmov);
				if((_global_modl_prve_kompletorium.pocet_zalmov == 2) && (_global_skip_in_prayer != ANO)){
					strcat(path, _global_modl_prve_kompletorium.antifona2.file);
					includeFile(type, paramname, path, _global_modl_prve_kompletorium.antifona2.anchor);
				}
				break;
			// 2010-06-04: zneužitie parametra "ANTIFONA2" pre zobrazenie "záverečnej" antifóny v prípade, že sa tlačí aj Sláva Otcu 
			//             funguje tak, že ak chce zobraziť Sláva Otcu (if(_global_opt 1 == ANO)), nastaví sa interpretovanie podľa ANTIFONA1; ináč sa nič nevykoná
			case MODL_INVITATORIUM:
				if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SLAVA_OTCU) == BIT_OPT_1_SLAVA_OTCU){
					strcat(path, _global_modl_invitatorium.antifona1.file);
					includeFile(type, paramname, path, _global_modl_invitatorium.antifona1.anchor);
				}
				else{
					Export("-->");
					Export((char *)html_text_inv_slavaotcu[_global_jazyk]);
					Export("<!--");
				}
				break;
			default:
				// tieto modlitby nemajú antifonu2
				break;
		}// switch
	}// PARAM_ANTIFONA2
	else if(equals(paramname, PARAM_ANTIFONA3)){
		antifona_pocet++;
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.antifona3.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.antifona3.anchor);
				break;
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.antifona3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.antifona3.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.antifona3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.antifona3.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.antifona3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.antifona3.anchor);
				break;
/*			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona3.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona3.anchor);
				break;
*/
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.antifona3.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.antifona3.anchor);
				break;
			default:
				// tieto modlitby nemajú antifonu3
				break;
		}// switch
	}// PARAM_ANTIFONA3
	else if(equals(paramname, PARAM_ANTIFONA3x)){
		antifona_pocet++;
		switch(type){
			case MODL_CEZ_DEN_9:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_9.antifona3.file);
					includeFile(type, PARAM_ANTIFONA3, path, _global_modl_cez_den_9.antifona3.anchor);
				}
				break;
			case MODL_CEZ_DEN_12:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_12.antifona3.file);
					includeFile(type, PARAM_ANTIFONA3, path, _global_modl_cez_den_12.antifona3.anchor);
				}
				break;
			case MODL_CEZ_DEN_3:
				if(_global_ant_mcd_rovnake == NIE){
					strcat(path, _global_modl_cez_den_3.antifona3.file);
					includeFile(type, PARAM_ANTIFONA3, path, _global_modl_cez_den_3.antifona3.anchor);
				}
				break;
			default:
				// tieto modlitby nemajú antifonu3x (má to len mcd)
				break;
		}// switch
	}// PARAM_ANTIFONA3x
	else if(equals(paramname, PARAM_ANTIFONA1k)){
		// 2008-04-03: pridané kvôli kompletóriu vo veľkonočnom období, či pri druhej antifóne zobraziť dvojku alebo nie 
		// 2011-07-09: opravená podmienka
		// 2013-10-21: pre HU, CZ upravené | ToDo: vyriešiť krajšie
		if((((type == MODL_KOMPLETORIUM) && (_global_modl_kompletorium.pocet_zalmov == 2)) || ((type == MODL_PRVE_KOMPLETORIUM) && (_global_modl_prve_kompletorium.pocet_zalmov == 2))) && (_global_ant_mcd_rovnake == NIE)){
			Export("-->");
			if((_global_jazyk == JAZYK_HU) || (_global_jazyk == JAZYK_CZ)){
				Export("1. ant.");
			}
			else{
				Export("1");
			}
			Export("<!--");
		}
		else{
			if((_global_jazyk == JAZYK_HU) || (_global_jazyk == JAZYK_CZ)){
				Export("-->");
				Export("Ant.");
				Export("<!--");
			}
			else{
#if defined(EXPORT_HTML_SPECIALS)
				Export("nie je 1. antifona v kompletku");
#endif
			}
			Log("nie je 1. antifona v kompletku");
		}
	}// ANTIFONA1_KOMPLET
	else if(equals(paramname, PARAM_ANTIFONA2k)){
		// 2008-04-03: pridané kvôli kompletóriu vo veľkonočnom období, či pri druhej antifóne zobraziť dvojku alebo nie 
		// 2011-07-09: opravená podmienka
		if((((type == MODL_KOMPLETORIUM) && (_global_modl_kompletorium.pocet_zalmov == 2)) || ((type == MODL_PRVE_KOMPLETORIUM) && (_global_modl_prve_kompletorium.pocet_zalmov == 2))) && (_global_ant_mcd_rovnake == NIE)){
			Export("-->2<!--");
		}
		else{
#if defined(EXPORT_HTML_SPECIALS)
			Export("nie je 2. antifona v kompletku");
#endif
			Log("nie je 2. antifona v kompletku");
		}
	}// ANTIFONA2_KOMPLET
	else if(equals(paramname, PARAM_ZALM1)){
		switch(type){
			// hoci nie je zapoznámkované, nepoužíva sa: 2006-10-11: invitatórium nemá žalm / resp. má fixný žalm 95 a alternatívy
			case MODL_INVITATORIUM:
				strcat(path, _global_modl_invitatorium.zalm1.file);
				includeFile(type, paramname, path, _global_modl_invitatorium.zalm1.anchor);
				break;
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.zalm1.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.zalm1.anchor);
				break;
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.zalm1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.zalm1.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.zalm1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.zalm1.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.zalm1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.zalm1.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm1.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm1.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.zalm1.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.zalm1.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.zalm1.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.zalm1.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.zalm1.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.zalm1.anchor);
				break;
			case MODL_PRVE_KOMPLETORIUM:
				strcat(path, _global_modl_prve_kompletorium.zalm1.file);
				includeFile(type, paramname, path, _global_modl_prve_kompletorium.zalm1.anchor);
				break;
			default:
				// tieto modlitby nemajú zalm1
				break;
		}// switch
	}// PARAM_ZALM1
	else if(equals(paramname, PARAM_ZALM2)){
		switch(type){
			// ranné chvály nie
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.zalm2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.zalm2.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.zalm2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.zalm2.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.zalm2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.zalm2.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm2.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm2.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.zalm2.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.zalm2.anchor);
				break;
			case MODL_KOMPLETORIUM:
				if(_global_modl_kompletorium.pocet_zalmov == 2){
					strcat(path, _global_modl_kompletorium.zalm2.file);
					includeFile(type, paramname, path, _global_modl_kompletorium.zalm2.anchor);
				}
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.zalm2.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.zalm2.anchor);
				break;
			case MODL_PRVE_KOMPLETORIUM:
				if(_global_modl_prve_kompletorium.pocet_zalmov == 2){
					strcat(path, _global_modl_prve_kompletorium.zalm2.file);
					includeFile(type, paramname, path, _global_modl_prve_kompletorium.zalm2.anchor);
				}
				break;
			default:
				// tieto modlitby nemajú zalm2
				break;
		}// switch
	}// PARAM_ZALM2
	else if(equals(paramname, PARAM_ZALM3)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.zalm3.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.zalm3.anchor);
				break;
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.zalm3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.zalm3.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.zalm3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.zalm3.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.zalm3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.zalm3.anchor);
				break;
			// vešpery nie
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.zalm3.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.zalm3.anchor);
				break;
			default:
				// tieto modlitby nemajú zalm3
				break;
		}// switch
	}// PARAM_ZALM3
	else if(equals(paramname, PARAM_KCITANIE)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.kcitanie.anchor);
				break;
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.kcitanie.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.kcitanie.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.kcitanie.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_vespery.kcitanie.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.kcitanie.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.kcitanie.anchor);
				break;
			case MODL_PRVE_KOMPLETORIUM:
				strcat(path, _global_modl_prve_kompletorium.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_prve_kompletorium.kcitanie.anchor);
				break;
			default:
				// tieto modlitby nemajú kcitanie
				break;
		}// switch
	}// PARAM_KCITANIE
	else if(equals(paramname, PARAM_KRESPONZ)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.kresponz.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.kresponz.anchor);
				break;
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.kresponz.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.kresponz.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.kresponz.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.kresponz.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.kresponz.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.kresponz.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.kresponz.file);
				includeFile(type, paramname, path, _global_modl_vespery.kresponz.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.kresponz.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.kresponz.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.kresponz.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.kresponz.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.kresponz.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.kresponz.anchor);
				break;
			case MODL_PRVE_KOMPLETORIUM:
				strcat(path, _global_modl_prve_kompletorium.kresponz.file);
				includeFile(type, paramname, path, _global_modl_prve_kompletorium.kresponz.anchor);
				break;
			default:
				// tieto modlitby nemajú kresponz
				break;
		}// switch
	}// PARAM_KRESPONZ
	else if(equals(paramname, PARAM_CITANIE1)){
		if(type == MODL_POSV_CITANIE){
			strcat(path, _global_modl_posv_citanie.citanie1.file);
			Log("interpretParameter(): equals(paramname, PARAM_CITANIE1). idem spustiť includeFile()...\n");
			includeFile(type, paramname, path, _global_modl_posv_citanie.citanie1.anchor);
			Log("interpretParameter(): equals(paramname, PARAM_CITANIE1), po spustení includeFile().\n");
		}
		else{
			; // ostatné modlitby 1. čítanie nemajú
		}
	}// PARAM_CITANIE1
	else if(equals(paramname, PARAM_CITANIE2)){
		if(type == MODL_POSV_CITANIE){
			strcat(path, _global_modl_posv_citanie.citanie2.file);
			includeFile(type, paramname, path, _global_modl_posv_citanie.citanie2.anchor);
		}
		else{
			; // ostatné modlitby 2. čítanie nemajú
		}
	}// PARAM_CITANIE2
	else if(equals(paramname, PARAM_MAGNIFIKAT)){
		// ak _global_skip_in_prayer je ANO, tak preskoc Magnifikat
		if(((type == MODL_VESPERY) || (type == MODL_PRVE_VESPERY)) && (_global_skip_in_prayer != ANO)){
			if(type == MODL_VESPERY){
				strcat(path, _global_modl_vespery.magnifikat.file);
				includeFile(type, paramname, path, _global_modl_vespery.magnifikat.anchor);
			}
			else{
				strcat(path, _global_modl_prve_vespery.magnifikat.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.magnifikat.anchor);
			}
		}
		else{
			; // ostatné modlitby nemajú večerný chválospev
		}
	}// PARAM_MAGNIFIKAT
	else if(equals(paramname, PARAM_ANTVCHVAL)){
		antifona_pocet++;
		if(type == MODL_VESPERY){
			strcat(path, _global_modl_vespery.antifona3.file);
			includeFile(type, paramname, path, _global_modl_vespery.antifona3.anchor);
		}
		else if(type == MODL_PRVE_VESPERY){
			strcat(path, _global_modl_prve_vespery.antifona3.file);
			includeFile(type, paramname, path, _global_modl_prve_vespery.antifona3.anchor);
		}
		else{
			; // ostatné modlitby nemajú večerný chválospev
		}
	}// PARAM_ANTVCHVAL
	else if(equals(paramname, PARAM_VCHVALOSPEV)){
		if(type == MODL_VESPERY){
			strcat(path, _global_modl_vespery.zalm3.file);
			includeFile(type, paramname, path, _global_modl_vespery.zalm3.anchor);
		}
		else if(type == MODL_PRVE_VESPERY){
			strcat(path, _global_modl_prve_vespery.zalm3.file);
			includeFile(type, paramname, path, _global_modl_prve_vespery.zalm3.anchor);
		}
		else{
			; // ostatné modlitby nemajú večerný chválospev
		}
	}// PARAM_VCHVALOSPEV
	else if(equals(paramname, PARAM_BENEDIKTUS)){
		// ak _global_skip_in_prayer je ANO, tak preskoc Benediktus
		if((type == MODL_RANNE_CHVALY) && (_global_skip_in_prayer != ANO)){
			strcat(path, _global_modl_ranne_chvaly.benediktus.file);
			includeFile(type, paramname, path, _global_modl_ranne_chvaly.benediktus.anchor);
		}
		else{
			; // ostatné modlitby nemajú ranný chválospev
		}
	}// PARAM_BENEDIKTUS
	else if(equals(paramname, PARAM_ANTRCHVAL)){
		antifona_pocet++;
		if(type == MODL_RANNE_CHVALY){
			strcat(path, _global_modl_ranne_chvaly.antifona2.file);
			includeFile(type, paramname, path, _global_modl_ranne_chvaly.antifona2.anchor);
		}
		else{
			; // ostatné modlitby nemajú ranný chválospev
		}
	}// PARAM_ANTRCHVAL
	else if(equals(paramname, PARAM_RCHVALOSPEV)){
		if(type == MODL_RANNE_CHVALY){
			strcat(path, _global_modl_ranne_chvaly.zalm2.file);
			includeFile(type, paramname, path, _global_modl_ranne_chvaly.zalm2.anchor);
		}
		else{
			; // ostatné modlitby nemajú ranný chválospev
		}
	}// PARAM_RCHVALOSPEV
	else if(equals(paramname, PARAM_NUNC_DIMITTIS)){
		if((je_kompletorium12(type)) && (_global_skip_in_prayer != ANO)){
			if(type == MODL_KOMPLETORIUM){
				strcat(path, _global_modl_kompletorium.nunc_dimittis.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.nunc_dimittis.anchor);
			}
			else{
				strcat(path, _global_modl_prve_kompletorium.nunc_dimittis.file);
				includeFile(type, paramname, path, _global_modl_prve_kompletorium.nunc_dimittis.anchor);
			}
		}
		else{
			; // ostatné modlitby nemajú Nunc dimittis
		}
	}// PARAM_NUNC_DIMITTIS
	else if(equals(paramname, PARAM_MARIANSKE_ANTIFONY_LINK)){
		if((je_kompletorium12(type)) && (_global_skip_in_prayer != ANO)){
			// využijeme parameter path, ktorý sa nepoužíva
#ifndef BEHAVIOUR_WEB
			_struct_anchor_and_file af;
			init_marianske_anfifony_file(af);
			mystrcpy(path, af.file, SMALL);
#else
			init_url_marianske_antifony(path);
#endif
			Export("--><a href=\"%s\"><!--", path);
		}
		else{
			; // ostatné modlitby nemajú link na mariánske antifóny
		}
	}// PARAM_MARIANSKE_ANTIFONY_LINK
	else if(equals(paramname, PARAM_PROSBY)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.prosby.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.prosby.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.prosby.file);
				includeFile(type, paramname, path, _global_modl_vespery.prosby.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.prosby.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.prosby.anchor);
				break;
			default:
				// tieto modlitby nemajú prosby
				break;
		}// switch
	}// PARAM_PROSBY
	else if(equals(paramname, PARAM_MODLITBA)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.modlitba.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.modlitba.anchor);
				break;
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.modlitba.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.modlitba.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.modlitba.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.modlitba.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.modlitba.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.modlitba.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.modlitba.file);
				includeFile(type, paramname, path, _global_modl_vespery.modlitba.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.modlitba.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.modlitba.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.modlitba.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.modlitba.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.modlitba.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.modlitba.anchor);
				break;
			case MODL_PRVE_KOMPLETORIUM:
				strcat(path, _global_modl_prve_kompletorium.modlitba.file);
				includeFile(type, paramname, path, _global_modl_prve_kompletorium.modlitba.anchor);
				break;
			default:
				// tieto modlitby nemaju antifonu1
				break;
		}// switch
	}// PARAM_MODLITBA
	else if(equals(paramname, PARAM_ANT_SPOMPRIVILEG)){
		// 2010-05-21: pridané kvôli spomienkam a ľubovoľným spomienkam v pôstnom období (zobrazenie po modlitbe dňa pôstnej férie)
		// 2012-02-09: zovšeobecnené v zmysle VSLH č. 238 (Spomienky pripadajúce na privilegované dni)
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.ant_spomprivileg.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.ant_spomprivileg.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.ant_spomprivileg.file);
				includeFile(type, paramname, path, _global_modl_vespery.ant_spomprivileg.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.ant_spomprivileg.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.ant_spomprivileg.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť spomienky na svätca v pôstnom období
				break;
		}// switch
	}// PARAM_ANT_SPOMPRIVILEG
	else if(equals(paramname, PARAM_MODL_SPOMPRIVILEG)){
		// 2010-05-21: pridané kvôli spomienkam a ľubovoľným spomienkam v pôstnom období (zobrazenie po modlitbe dňa pôstnej férie)
		// 2012-02-09: zovšeobecnené v zmysle VSLH č. 238 (Spomienky pripadajúce na privilegované dni)
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.modlitba_spomprivileg.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.modlitba_spomprivileg.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.modlitba_spomprivileg.file);
				includeFile(type, paramname, path, _global_modl_vespery.modlitba_spomprivileg.anchor);
				break;
			case MODL_PRVE_VESPERY:
				strcat(path, _global_modl_prve_vespery.modlitba_spomprivileg.file);
				includeFile(type, paramname, path, _global_modl_prve_vespery.modlitba_spomprivileg.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť spomienky na svätca v pôstnom období
				break;
		}// switch
	}// PARAM_MODL_SPOMPRIVILEG
	else if(equals(paramname, PARAM_CITANIE2_SPOMPRIVILEG)){ // 2011-03-16: pridané kvôli spomienkam a ľubovoľným spomienkam v pôstnom období (zobrazenie po 2. čítaní)
		switch(type){
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.citanie_spomprivileg.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.citanie_spomprivileg.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť spomienky na svätca v pôstnom období
				break;
		}// switch
	}// PARAM_CITANIE2_SPOMPRIVILEG

	// 2012-05-24: doplnené -- predĺžené slávenie vigílií v rámci posvätných čítaní
	else if(equals(paramname, PARAM_ANTIFONA_VIG)){
		switch(type){
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.ant_chval.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.ant_chval.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť predĺženého slávenia vigílie
				break;
		}// switch
	}// PARAM_ANTIFONA_VIG
	else if(equals(paramname, PARAM_CHVALOSPEV1)){
		switch(type){
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.chval1.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.chval1.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť predĺženého slávenia vigílie
				break;
		}// switch
	}// PARAM_CHVALOSPEV1
	else if(equals(paramname, PARAM_CHVALOSPEV2)){
		switch(type){
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.chval2.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.chval2.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť predĺženého slávenia vigílie
				break;
		}// switch
	}// PARAM_CHVALOSPEV2
	else if(equals(paramname, PARAM_CHVALOSPEV3)){
		switch(type){
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.chval3.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.chval3.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť predĺženého slávenia vigílie
				break;
		}// switch
	}// PARAM_CHVALOSPEV3
	else if(equals(paramname, PARAM_EVANJELIUM)){
		switch(type){
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.evanjelium.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.evanjelium.anchor);
				break;
			default:
				// tieto modlitby nemajú možnosť predĺženého slávenia vigílie
				break;
		}// switch
	}// PARAM_EVANJELIUM
	else if(equals(paramname, PARAM_TEXT)){
		// bez ohľadu na type, ktorý nie je nastavený, sa includuje nastavený súbor
		strcat(path, _global_include_static_text.file);
		Log("volám includeFile(%d, %s, file = %s, anchor = %s)...\n", type, paramname, _global_include_static_text.file, _global_include_static_text.anchor);
		includeFile(type, paramname, path, _global_include_static_text.anchor);
	}// PARAM_TEXT

	Log("interpretParameter(%s): Dumped by %s - OK.\n", paramname, paramname);
}// interpretParameter()

//---------------------------------------------------------------------
// interpretTemplate():
// uz ma presnu cestu k suboru s templatom (vzorom) pre danu modlitbu, potom tento templat interpretuje citajuc znak po znaku nasledovne:
// -- normalne kopiruje a exportuje,
// -- ak narazi na znak CHAR_KEYWORD_BEGIN, do buffra uklada vsetko az po znak CHAR_KEYWORD_END, pototm zavola interpretParameter(strbuff) a po skonceni pokracuje dalej az do EOF.
//
// CHAR_KEYWORD_BEGIN a CHAR_KEYWORD_END su #define'ovane v liturgia.h | exportfile je definovane v myexpt.[h|c]
// 2011-05-02: znak '_' používame ako zástupný pre nezlomiteľnú medzeru (exportuje sa ako &nbsp;)
void interpretTemplate(short int type, char *tempfile, short int aj_navigacia = ANO){
	short buff_index = 0;
	char strbuff[MAX_BUFFER];
	char isbuff = 0;

	_global_pocet_slava_otcu = 0; // pre každý súbor templátu individuálne počítame sláva otcu; 2007-05-18
	_global_pocet_navigacia = 0; // podobne aj počet parametrov navigácie; 2011-07-03 | 2012-04-19: avšak treba aj počítať počty volania interpretTemplate()
	_global_pocet_volani_interpretTemplate++;
	antifona_pocet = 0; // 2011-07-08: počet antifón (ant1, ant2, ant3 pre psalmódiu a ant. na benediktus/magnifikat kvôli krížikom)
	mystrcpy(rest_krizik, STR_EMPTY, MAX_BUFFER); // 2011-07-08: pre to, čo je za krížikom v antifóne

	FILE *ftemplate = fopen(tempfile, "rb");

	Log("interpretTemplate(%s): Interpreting template %s\n", tempfile, tempfile);

	if(ftemplate == NULL){
		ALERT;
		Export((char *)html_error_template[_global_jazyk], tempfile);
		Export("\n");
		return;
	}// chyba -- šablóna sa nenašla

	int b;
	Utf8DecoderState c;
	InitUtf8DecoderState(&c);

	while((b = fgetc(ftemplate)) != EOF){
		if (!Utf8StreamingDecoder(b, &c)) continue;
		switch (c.result){
			case CHAR_KEYWORD_BEGIN:
				isbuff = 1;
				buff_index = 0;
				continue;
			case CHAR_KEYWORD_END:
				isbuff = 0;
				strbuff[buff_index] = '\0';
				interpretParameter(type, strbuff, aj_navigacia);
				continue;
		}// switch(c)
		if(!isbuff){
			if((_global_skip_in_prayer != ANO) && (_global_skip_in_prayer_2 != ANO) && (_global_skip_in_prayer_vnpc != ANO)){
				ExportChar(c.result);
			}// !_global_skip_in_prayer && !_global_skip_in_prayer_2
		}// if(!isbuff)
		else{
			strbuff[buff_index++] = (char)c.result;
		}// else if(!isbuff)
	}
	fclose(ftemplate);
	Log("interpretTemplate(): end.\n");
}// interpretTemplate()

//---------------------------------------------------------------------
// showPrayer():
// podla typu modlitby pripravi templat a spusti interpretTemplate()
//
// ak je vstupom typ vespery resp. kompletorium, a v _global_modlitba je nieco ine (t.j. prve/druhe), vtedy predpokladam, ze v premennych _global_[prve_]kompletorium/vespery su spravne data
void showPrayer(short int type, short int ktore_templaty = SHOW_TEMPLAT_MODLITBA, short int aj_navigacia = ANO){
	char templat[SMALL];
	char path[MAX_STR] = STR_EMPTY;
	mystrcpy(path, include_dir, MAX_STR);
	short int i = 0;

	if(type == MODL_NEURCENA){
		Log("/* teraz nasleduje zobrazenie textu (type == MODL_NEURCENA) */\n");
	}
	else{
		Log("/* teraz nasleduje zobrazenie modlitby %d */\n", type);
	}
	Log("showPrayer(): begin\n");

	Log("2006-10-18: _global_pocet_zalmov_kompletorium == %d\n", _global_pocet_zalmov_kompletorium);

	// 2005-11-11: Pridané: ak je potrebné vytlačiť Te Deum, tak zmeníme atribút
	if(je_tedeum){
		Log("JE tedeum...\n");
		_global_opt_tedeum = ANO; // opravené 2007-05-18
	}
	else{
		Log("NIE JE tedeum...\n");
		_global_opt_tedeum = NIE; // opravené 2007-05-18
	}

	Log("showPrayer: jazyk == `%s' (%d)\n", pom_JAZYK, _global_jazyk); // 2006-07-11: Pridané kvôli jazykovým mutáciám
	Log("showPrayer: opt tedeum == %d\n", _global_opt_tedeum);

	// log options parametrov
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		Log("showPrayer: opt %d == `%s' (%d)\n", i, pom_MODL_OPT[i], _global_opt[i]);
	}// Log pom_MODL_OPT[i]

	// log force options parametrov
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		Log("showPrayer: optF %d == `%s' (%d)\n", i, pom_MODL_OPTF[i], _global_optf[i]);
	}// Log pom_MODL_OPTF[i]

	// force options parametre
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		if(_global_opt[i] != _global_optf[i]){
			Log("showPrayer: používam _global_optf[%d] (force)...\n", i);
			_global_opt[i] = _global_optf[i];
		}
	}// override pre _global_opt[i] z _global_optf[i]

	// 2011-04-08: log option 0
	Log("option 0 == %d, čo znamená: \n", _global_opt[OPT_0_SPECIALNE]);
	Log("\t BIT_OPT_0_VERSE == %d (áno == %d)\n", _global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_VERSE, BIT_OPT_0_VERSE);
	Log("\t BIT_OPT_0_REFERENCIE == %d (áno == %d)\n", _global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE, BIT_OPT_0_REFERENCIE);

	// 2013-11-26: log option 1
	Log("option 1 == %d, čo znamená: \n", _global_opt[OPT_1_CASTI_MODLITBY]);
	Log("\t BIT_OPT_1_PROSBY_ZVOLANIE == %d (áno == %d)\n", _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PROSBY_ZVOLANIE, BIT_OPT_1_PROSBY_ZVOLANIE);
	Log("\t BIT_OPT_1_SLAVA_OTCU == %d (áno == %d)\n", _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SLAVA_OTCU, BIT_OPT_1_SLAVA_OTCU);

	// samotne vypisanie, o aku modlitbu ide
	Log("showPrayer(type %i, %s), _global_modlitba == %s\n", type, nazov_modlitby(type), nazov_modlitby(_global_modlitba));

	// umožníme aj MODL_NEURCENA -- pre statické texty
	if(((type > MODL_PRVE_KOMPLETORIUM) || (type < MODL_INVITATORIUM))){
		ALERT;
		Export("Neznámy typ modlitby.\n");
		return;
	}// neznámy typ modlitby

	if(_global_modlitba != type){
		// zrejme ide o prvé/druhé vešpery či kompletórium
		if((_global_modlitba == MODL_PRVE_VESPERY) && (type == MODL_VESPERY)){
			_global_modl_vespery = _global_modl_prve_vespery;
		}
		else if((_global_modlitba == MODL_PRVE_KOMPLETORIUM) && (type == MODL_KOMPLETORIUM)){
			_global_modl_kompletorium = _global_modl_prve_kompletorium;
		}
		else if((_global_modlitba == MODL_DRUHE_VESPERY) && (type == MODL_VESPERY)){
			// v poriadku: všetko je v _global_modl_vespery
		}
		else if((_global_modlitba == MODL_DRUHE_KOMPLETORIUM) && (type == MODL_KOMPLETORIUM)){
			// v poriadku: všetko je v _global_modl_kompletorium
		}
		else{
			Log("_global_modlitba (%s) != type (%s), showPrayer()\n", _global_modlitba, type);
			ALERT;
			Export("Nastala chyba programu (type != _global_modlitba).\n");
			return;
		}// chyba
	}// _global_modlitba != type

	// podľa parametra ktore_templaty sa rozhodneme, ktorý templát použiť
	if(ktore_templaty == SHOW_TEMPLAT_MODLITBA){
		mystrcpy(templat, TEMPLAT[type], SMALL);
	}
	else if(ktore_templaty == SHOW_TEMPLAT_STATIC_TEXT){
		mystrcpy(templat, TEMPLAT_STATIC_TEXT, SMALL);
	}
	Log("showPrayer: používam šablónu %s...\n", templat);
	strcat(path, templat);
	Log("showPrayer: po prilepení cesty: %s...\n", path);
	
	// 2007-10-02: doplnené nezobrazovanie rovnakej antifóny v modlitbe cez deň; keďže je daný jediný typ modlitby, nie je potrebné pole pre jednotlivé modlitby 
	// 2008-03-30: doplnené pre kompletórium vo veľkonočnej oktáve a celom veľkonočnom období
	if (
			// chvíľu existovalo ako #define su_antifony_mcd_rovnake(type)
			(
				(type == MODL_CEZ_DEN_9)
				&& (equals(_global_modl_cez_den_9.antifona1.file, _global_modl_cez_den_9.antifona2.file)  && equals(_global_modl_cez_den_9.antifona1.file, _global_modl_cez_den_9.antifona3.file))
				&& (equals(_global_modl_cez_den_9.antifona1.anchor, _global_modl_cez_den_9.antifona2.anchor)  && equals(_global_modl_cez_den_9.antifona1.anchor, _global_modl_cez_den_9.antifona3.anchor))
			) ||
			(
				(type == MODL_CEZ_DEN_12)
				&& (equals(_global_modl_cez_den_12.antifona1.file, _global_modl_cez_den_12.antifona2.file)  && equals(_global_modl_cez_den_12.antifona1.file, _global_modl_cez_den_12.antifona3.file))
				&& (equals(_global_modl_cez_den_12.antifona1.anchor, _global_modl_cez_den_12.antifona2.anchor)  && equals(_global_modl_cez_den_12.antifona1.anchor, _global_modl_cez_den_12.antifona3.anchor))
			) ||
			(
				(type == MODL_CEZ_DEN_3)
				&& (equals(_global_modl_cez_den_3.antifona1.file, _global_modl_cez_den_3.antifona2.file)  && equals(_global_modl_cez_den_3.antifona1.file, _global_modl_cez_den_3.antifona3.file))
				&& (equals(_global_modl_cez_den_3.antifona1.anchor, _global_modl_cez_den_3.antifona2.anchor)  && equals(_global_modl_cez_den_3.antifona1.anchor, _global_modl_cez_den_3.antifona3.anchor))
			)
			||
			(
				(type == MODL_KOMPLETORIUM) && (_global_modl_kompletorium.pocet_zalmov == 2)
				&& (equals(_global_modl_kompletorium.antifona1.file, _global_modl_kompletorium.antifona2.file))
				&& (equals(_global_modl_kompletorium.antifona1.anchor, _global_modl_kompletorium.antifona2.anchor))
			)
			||
			(
				(type == MODL_PRVE_KOMPLETORIUM) && (_global_modl_prve_kompletorium.pocet_zalmov == 2)
				&& (equals(_global_modl_prve_kompletorium.antifona1.file, _global_modl_prve_kompletorium.antifona2.file))
				&& (equals(_global_modl_prve_kompletorium.antifona1.anchor, _global_modl_prve_kompletorium.antifona2.anchor))
			)
		){
		_global_ant_mcd_rovnake = ANO;
	}
	else{
		_global_ant_mcd_rovnake = NIE;
	}
	Log("showPrayer: _global_ant_mcd_rovnake == %d\n", _global_ant_mcd_rovnake);

	interpretTemplate(type, path, aj_navigacia);
	Log("showPrayer(): end\n");
}// showPrayer();

//---------------------------------------------------------------------
void vysvetlivky(void){
	char fname[MAX_STR] = STR_EMPTY;
	mystrcpy(fname, include_dir, MAX_STR);
	strcat(fname, FILE_VYSVETLIVKY);
	Export("<!--"); // simulacia toho, ze replacujeme nejaky anchor
	includeFile(0, ANCHOR_VYSVETLIVKY, fname, ANCHOR_VYSVETLIVKY);
	Export("-->"); // simulacia toho, ze replacujeme nejaky anchor
}

void vysvetlivky_tabulka(void){
	char fname[MAX_STR] = STR_EMPTY;
	mystrcpy(fname, include_dir, MAX_STR);
	strcat(fname, FILE_VYSVETLIVKY_TABULKA);
	Export("<!--"); // simulacia toho, ze replacujeme nejaky anchor
	includeFile(0, ANCHOR_VYSVETLIVKY_TABULKA, fname, ANCHOR_VYSVETLIVKY_TABULKA);
	Export("-->"); // simulacia toho, ze replacujeme nejaky anchor
}

//---------------------------------------------------------------------
// kontrola_den_mesiac_rok();
// skontroluje dátum, či je správne zadaný,
// vracia: on success, returns SUCCESS
//         on error,   returns FAILURE
#define ExportKONTROLA _export_heading("Kontrola dňa"); Export
short int kontrola_den_mesiac_rok(short int den, short int mesiac, short int rok){
	if((mesiac < 1) || (mesiac > 12)){
		ExportKONTROLA("Takýto mesiac nepoznám (%d).\n", mesiac);
		return FAILURE;
	}
	if(prestupny(rok))
		pocet_dni[MES_FEB] = 29;
	else
		pocet_dni[MES_FEB] = 28;
	if((den < 1) || (den > pocet_dni[mesiac - 1])){
		if((mesiac == 2) && (pocet_dni[MES_FEB] == 29)){
			ExportKONTROLA("Rok %d je síce prestupný, ale aj tak má %s len 29 dní.\n",
				rok, nazov_mesiaca(MES_FEB));
		}
		else if(mesiac == 2){
			ExportKONTROLA("Rok %d nie je prestupný, takže %s má len 28 dní.\n",
				rok, nazov_mesiaca(MES_FEB));
		}
		else{
			ExportKONTROLA("Mesiac %s má %d dní.\n",
				nazov_mesiaca(mesiac - 1), pocet_dni[mesiac - 1]);
		}
		return FAILURE;
	}
	return SUCCESS;
}// kontrola_den_mesiac_rok()

// popis: vráti číslo liturgického obdobia (0--6), ak sa lo == cezročné atď...
//        inak vráti OBD_CEZ_ROK (cezročné obdobie)
short int atolitobd(char *lo){
	short int i = 0;
	Log("lo == '%s'\n", lo);
	do{
		// Log("nazov_obdobia_ext(%d) == %s...\n", i, nazov_obdobia_ext(i));
		if(equals(lo, nazov_obdobia_ext(i))){
			Log("atolitobd: returning %d\n", i);
			return i;
		}
		if(equals(lo, nazov_obdobia_short(i))){
			Log("atolitobd: returning %d\n", i);
			return i;
		}
		i++;
	}while(i <= POCET_OBDOBI);
	// 2011-05-11: ak sa nenašlo obdobie porovnaním s reťazcom, skúsim prekonvertovať na číslo
	i = atoi(lo);
	i = ((i < OBD_ADVENTNE_I) || (i > OBD_VELKONOCNE_II)) ? OBD_CEZ_ROK : i;
	Log("atolitobd: returning %d\n", i);
	return i;
	// return OBD_CEZ_ROK;
}// atolitobd()

// popis: vráti číslo dňa (0--6), ak sa den == pondelok...
//        inak vráti UNKNOWN_DEN
short int atodenvt(char *den){
	short int i = 0;
	do{
		if(equals(den, nazov_dna(i)) || equals(den, nazov_dna_asci(i))){
			return i;
		}
		i++;
	}while(i < DEN_UNKNOWN);
	// 2011-05-11: ak sa nenašiel deň v týždni porovnaním s reťazcom, skúsim prekonvertovať na číslo
	i = atoi(den);
	return ((i < DEN_NEDELA) || (i > DEN_SOBOTA)) ? DEN_UNKNOWN : i;
	// return DEN_UNKNOWN;
}// atodenvt()

// popis: vráti int (číslo dňa 1--31), ak sa den == 1,2...
//        alebo (ako den == STR_VSETKY_DNI) vráti VSETKY_DNI;
//        v pripade iných údajov vráti 0
short int atoden(char *den){
	short int d;
	if(equals(den, STR_VSETKY_DNI))
		return VSETKY_DNI;
	else{
		d = atoi(den);
		return ((d < 0) || (d > 31)) ? 0 : d;
	}
}// atoden()

// popis: vráti číslo mesiaca (0--11), ak sa den == januar...
//        alebo vráti VSETKY_MESIACE, ak den == STR_VSETKY_MESIACE;
//        inak vráti UNKNOWN_MESIAC
short int atomes(char *mesiac){
	// sprintf(pom_MESIAC, "%d", cislo_mesiaca(pom_MESIAC));
	if(equals(mesiac, STR_VSETKY_MESIACE))
		return VSETKY_MESIACE;
	// mesiac moze byt string "1" -- "12" alebo nazov_mesiaca(0 -- 11)
	short int i = atoi(mesiac) - 1;
	if((i >= MES_JAN) && (i <= MES_DEC))
		return i;
	i = 0;
	do{
		if(equals(mesiac, nazov_mesiaca(i)) ||
//		if(equals(mesiac, nazov_mesiaca_jazyk[i][_global_jazyk]) ||
			equals(mesiac, nazov_mesiaca_asci(i))){
			return i;
		}
		i++;
	}while(i < UNKNOWN_MESIAC);
	// ešte jeden pokus pre ostatné jazyky
	int j = -1;
	if(i == UNKNOWN_MESIAC){
		do{
			++j;
			if((j != JAZYK_UNDEF) && (j != _global_jazyk)){
				i = 0;
				do{
					if(equals(mesiac, nazov_mesiaca_jazyk[i][j])){
						return i;
					}
					i++;
				}while(i < UNKNOWN_MESIAC);
			}
		}while(j <= POCET_JAZYKOV);
	}
	return UNKNOWN_MESIAC;
}// atomes()

// popis: vráti číslo jazyka 
//        inak vráti JAZYK_UNDEF
short int atojazyk(char *jazyk){
	short int i = 0;
	do{
		if(equalsi(jazyk, skratka_jazyka[i]) || equalsi(jazyk, nazov_jazyka[i])){
			return i;
		}
		i++;
	}while(i <= POCET_JAZYKOV);
	return JAZYK_UNDEF;
}// atojazyk()

// popis: vráti číslo kalendára, napr. rehoľný
//        inak vráti KALENDAR_NEURCENY
// 2010-10-11: doplnené porovnanie aj s nazov_kalendara_long[]
short int atokalendar(char *kalendar){
	short int i = 0;
	do{
		if(equalsi(kalendar, skratka_kalendara[i]) || equalsi(kalendar, nazov_kalendara_short[i]) || equalsi(kalendar, nazov_kalendara_long[i])){
			return i;
		}
		i++;
	}while(i <= POCET_KALENDAROV);
	return KALENDAR_NEURCENY;
}// atokalendar()

// popis: vráti číslo css-ka
//        inak vráti CSS_UNDEF
short int atocss(char *css){
	short int i = 0;
	do{
		if(equalsi(css, skratka_css[i]) || equalsi(css, nazov_css[i])){
			return i;
		}
		i++;
	}while(i <= POCET_CSS);
	return CSS_UNDEF;
}// atocss()

// popis: vráti číslo fontu
//        inak vráti FONT_UNDEF
short int atofont(char *font){
	short int i = 0;
	do{
		if(equalsi(font, nazov_fontu[i])){
			return i;
		}
		if((i == FONT_CSS) && equalsi(font, nazov_fontu_CSS[_global_jazyk])){
			return i;
		}
		if((i == FONT_CHECKBOX) && equalsi(font, nazov_fontu_CHECKBOX[_global_jazyk])){
			return i;
		}
		i++;
	}while(i <= POCET_FONTOV);
	return FONT_UNDEF;
}// atofont()

// popis: vráti index veľkosti fontu
//        inak vráti FONT_SIZE_UNDEF
short int atofontsize(char *font){
	short int i = 0;
	do{
		if(equalsi(font, nazov_font_size(i))){
			return i;
		}
		if(equalsi(font, nazov_font_size_css[i])){
			return i;
		}
		i++;
	}while(i <= POCET_FONT_SIZE);
	return FONT_SIZE_UNDEF;
}// atofontsize()

// popis: vráti číslo statického textu
//        inak vráti STATIC_TEXT_UNDEF
short int atoStaticText(char *css){
	short int i = 0;
	do{
		if(equalsi(css, skratka_static_text[i])){
			return i;
		}
		i++;
	}while(i <= POCET_STATIC_TEXTOV);
	return STATIC_TEXT_UNDEF;
}// atoStaticText()

// 2006-02-10: nový define; používa premenné int i, p 
// 2006-10-11: odpoznámkované invitatórium a kompletórium
// 2011-05-11: možno by bolo osožné prerobiť štýlom funkcie atodenvt(), atoden(), atomes()... [ToDo] -> #define _parsuj_parameter_MODLITBA(modlitba, p) | 2012-10-16: hotovo
// 2011-10-03: doplnené MODL_VSETKY
// popis: vráti číslo modlitby
//        inak vráti MODL_NEURCENA
short int atomodlitba(char *modlitba){
	short int p = MODL_NEURCENA;
	// rozparsovanie parametra modlitba
	Log("atomodlitba(%s): rozparsovanie parametra modlitba...\n", modlitba);
	if(equals(modlitba, STR_EMPTY))
		p = MODL_NEURCENA;
	else if(equals(modlitba, STR_MODL_VSETKY))
		p = MODL_VSETKY;
	else if(equals(modlitba, STR_MODL_DETAILY))
		p = MODL_DETAILY;
	else if(equals(modlitba, STR_MODL_INVITATORIUM))
		p = MODL_INVITATORIUM;
	else if(equals(modlitba, STR_MODL_RANNE_CHVALY))
		p = MODL_RANNE_CHVALY;
	else if(equals(modlitba, STR_MODL_POSV_CITANIE))
		p = MODL_POSV_CITANIE;
	else if(equals(modlitba, STR_MODL_PREDPOLUDNIM))
		p = MODL_PREDPOLUDNIM;
	else if(equals(modlitba, STR_MODL_NAPOLUDNIE))
		p = MODL_NAPOLUDNIE;
	else if(equals(modlitba, STR_MODL_POPOLUDNI))
		p = MODL_POPOLUDNI;
	else if(equals(modlitba, STR_MODL_VESPERY))
		p = MODL_VESPERY;
	else if(equals(modlitba, STR_MODL_KOMPLETORIUM))
		p = MODL_KOMPLETORIUM;
	// 2011-03-22 pridané prvé vešpery a kompletórium po prvých vešperách (experimentálne)
	else if(equals(modlitba, STR_MODL_PRVE_VESPERY))
		p = MODL_PRVE_VESPERY;
	else if(equals(modlitba, STR_MODL_PRVE_KOMPLETORIUM))
		p = MODL_PRVE_KOMPLETORIUM;
	else
		p = MODL_NEURCENA;
	// este treba skontrolovat, ci nazov modlitby nie je string ...azov_modlitby[...]
	if(p == MODL_NEURCENA){
		int pom_i = atoi(modlitba); 
		// atoi() vracia hodnotu 0 (naša hodnota MODL_INVITATORIUM) pre každý reťazec, ktorý nie je konvertovateľný na číslo, 
		// preto sme vyššie porovnali s "0" špeciálne a tu značí pom_i == 0 nie MODL_INVITATORIUM, ale chybu
		Log("atomodlitba(): pokus určenia modlitby konverziou reťazca `%s' na číslo (%d)...\n", modlitba, pom_i);
		if((pom_i < MODL_POSV_CITANIE) || (pom_i > MODL_VSETKY)){
			// postupne porovnavame s troma konstantami, nazov_[modlitby|Modlitby|MODLITBY], a to pre konstanty MODL_INVITATORIUM -- MODL_VSETKY (vratane)
			Log("atomodlitba(): pokus určenia modlitby podľa jazykovo závislých reťazcov pre modlitba == `%s'...\n", modlitba);
			for(pom_i = MODL_INVITATORIUM; pom_i <= MODL_VSETKY; pom_i++){
				Log("\tstep: %d `%s'...\n", pom_i, nazov_modlitby(pom_i));
				if(equals(modlitba, nazov_modlitby(pom_i)) || 
					equals(modlitba, nazov_modlitby_short(pom_i)) || 
					equals(modlitba, nazov_Modlitby(pom_i)) || 
					equals(modlitba, nazov_MODLITBY(pom_i))){
					// ak je zhoda, potom prirad do p a ukonci `for'
					p = pom_i;
					break;
				}
			}// for pom_i
		}
		else{
			p = pom_i;
		}
	}
	Log("atomodlitba(): returning %d...\n", p);
	return p;
}// atomodlitba()

//---------------------------------------------------------------------
// _rozbor_dna()
// predpokoladam, ze pred jeho volanim bolo pouzite analyzuj_rok(rok); ktore da vysledok do _global_r
// dostane {den, mesiac} a rok
// 01/03/2000A.D.: pridal som detailny vypis (_rozbor_dna_LOG)
// 08/03/2000A.D.: pridal som parameter poradie_svaty, ktory je potrebny, aby som zbytocne nepriradoval do _global_den veci z _global_svaty1
// 28/03/2000A.D.: navratova hodnota je SUCCESS alebo FAILURE
#define _rozbor_dna_LOG Log("-- _rozbor_dna({%d, %d}, %d, %d): ", datum.den, datum.mesiac, rok, poradie_svaty); Log

short int _rozbor_dna(_struct_den_mesiac datum, short int rok, short int poradie_svaty){
	Log("_rozbor_dna(): 3 parametre -- begin\n");
	_rozbor_dna_LOG("begin\n");

	if(poradie_svaty == UNKNOWN_PORADIE_SVATEHO){
		Log("spustam pre poradie_svaty == UNKNOWN_PORADIE_SVATEHO\n");
	}

	short int NARODENIE_PANA = poradie(25, 12, rok); // narodenie pana
	// slavnosti
	short int BOHORODICKY_PANNY_MARIE = poradie(1, 1, rok); // panny marie bohorodicky
	short int ZJAVENIE_PANA; // zjavenie Pána
	char nedelne_pismenko = _global_r.p1;
	if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_ZJAVENIE_PANA_NEDELA) == BIT_OPT_0_ZJAVENIE_PANA_NEDELA){
		if(nedelne_pismenko == 'A'){
			nedelne_pismenko = 'h'; // aby vyšla nedeľa Zjavenia Pána na 8.1.
		}
		Log("Zjavenie Pána sa slávi v nedeľu; %c/%c\n", _global_r.p1, nedelne_pismenko);
		ZJAVENIE_PANA = poradie((nedelne_pismenko - 'a') + 1, 1, rok); // nedeľa medzi 2. a 8. januárom
	}
	else{
		ZJAVENIE_PANA = poradie(6, 1, rok);
	}
	// ak padne Zjavenia Pána na nedeľu 7. alebo 8.1., treba upraviť slávenie sviatku Krstu Krista Pána (SK LH, zv. I, str. 377) -- realizované v _dm_krst_krista_pana()
	short int DECEMBER_16 = poradie(16, 12, rok); // 16. december, prelom v adventnom období
	short int TELAKRVI; // štvrtok po Trojici: Kristovho tela a krvi (alebo: v krajinách, kde sa presúva na nedeľu)
	if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_TELAKRVI_NEDELA) == BIT_OPT_0_TELAKRVI_NEDELA){
		Log("Najsv. Kristovho tela a krvi sa slávi v nedeľu\n");
		TELAKRVI = (ZOSLANIE_DUCHA_SV + 14);
	}
	else{
		TELAKRVI = (ZOSLANIE_DUCHA_SV + 11);
	}
	
	// 2006-02-06: pomocná premenná kvôli eventuálnemu prednastaveniu _global_opt 3
	_struct_sc sc;
	sc.a1 = MODL_SPOL_CAST_NEURCENA;
	sc.a2 = MODL_SPOL_CAST_NEURCENA;
	sc.a3 = MODL_SPOL_CAST_NEURCENA;

	// určenie "občianskych" (civilných) záležitostí dňa:
	// den, mesiac, rok, denvr, denvt
	Log("urcenie 'obcianskych' zalezitosti dna:\n");
	_global_den.den = datum.den;
	_global_den.mesiac = datum.mesiac;
	_global_den.rok = rok;
	_global_den.denvr = poradie(datum.den, datum.mesiac, rok);
	_global_den.denvt = den_v_tyzdni(datum.den, datum.mesiac, rok);
	_rozbor_dna_LOG("denvr == %d, denvt == %d...\n", _global_den.denvr, _global_den.denvt);

	// určenie všeobecnych "liturgických" záležitostí dňa:
	//
	// litrok,
	// tyzzal	= 0;
	// tyzden	= 0;
	// smer		= 14;
	// meno		= STR_EMPTY;
	// prik		= NIE_JE_PRIKAZANY_SVIATOK;
	// typslav	= SLAV_NEURCENE;
	// farba	= LIT_FARBA_NEURCENA;
	// kalendar = KALENDAR_NEURCENY;
	// lc_str_id = STR_EMPTY;
	if(_global_den.denvr < PRVA_ADVENTNA_NEDELA){
		_global_den.litrok = _global_r._POPOLCOVA_STREDA.litrok;
		_rozbor_dna_LOG("pred prvou adventnou nedelou v roku\n");
	}
	else{
		_global_den.litrok = _global_r._SVATEJ_RODINY.litrok;
		_rozbor_dna_LOG("po prvej adventnej nedeli v roku (vratane)\n");
	}
	_global_den.tyzzal = 0;
	_global_den.tyzden = 0;
	_global_den.smer = 14;
	_global_den.typslav = SLAV_NEURCENE;
	_global_den.prik = NIE_JE_PRIKAZANY_SVIATOK;
	_global_den.typslav_lokal = LOKAL_SLAV_NEURCENE;
	mystrcpy(_global_den.meno, STR_EMPTY, MENO_SVIATKU);
	_global_den.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
	_global_den.farba = LIT_FARBA_NEURCENA;
	_global_den.kalendar = KALENDAR_NEURCENY;
	mystrcpy(_global_den.lc_str_id, STR_EMPTY, MAX_LC_STR_ID);

	// určenie ostatných špecifických "liturgických" záležitostí:
	//
	// tyzzal, litobd, tyzden, smer, typslav, prip. meno
	if(_global_den.denvr < VELKONOCNA_NEDELA){
		// pred velkou nocou
		_rozbor_dna_LOG("/* pred velkou nocou */\n");
		if(_global_den.denvr >= POPOLCOVA_STREDA){
			// postne obdobie
			_global_den.farba = LIT_FARBA_FIALOVA;
			_global_den.kalendar = KALENDAR_VSEOBECNY;
			_rozbor_dna_LOG("/* postne obdobie */\n");
			_global_den.litobd = OBD_POSTNE_I; // do soboty v 5. post.tyzdni
			_global_den.smer = 9; // vsedne dni v poste

			if(_global_den.denvr == POPOLCOVA_STREDA){
				// _global_den.denvr == POPOLCOVA_STREDA
				_rozbor_dna_LOG("/* _global_den.denvr == POPOLCOVA_STREDA */\n");
				_global_den = _global_r._POPOLCOVA_STREDA;
			}
			else if(_global_den.denvr <= POPOLCOVA_STREDA + 3){
				// stvrtok, piatok, sobota po popolcovej strede
				_rozbor_dna_LOG("/* stvrtok, piatok, sobota po popolcovej strede */\n");
				/* mystrcpy(_global_den.meno, nazov_dna(_global_den.denvt));
				strcat(_global_den.meno, " po popolcovej strede"); */
				_global_den.tyzden = 0; // pridane 06/03/2000A.D. namiesto tohto: // _global_den.tyzzal = 4;
			}
			else if(_global_den.denvr <= BIELA_SOBOTA){
				// pred a vratane bielej soboty
				_rozbor_dna_LOG("/* pred a vratane bielej soboty */\n");

				// urcuje postny tyzden
				_rozbor_dna_LOG("/* urcuje postny tyzden */\n");
				_global_den.tyzden = ((_global_den.denvr - POPOLCOVA_STREDA - 4) DIV 7) + 1;

				if(_global_den.denvr < KVETNA_NEDELA){
					// pred kvetnou nedelou
					_rozbor_dna_LOG("/* pred kvetnou nedelou */\n");
					if(_global_den.denvt == DEN_NEDELA){
						// nedela v postnom obdobi
						_rozbor_dna_LOG("/* nedela v postnom obdobi */\n");
						_global_den.smer = 2; // nedele adventné, pôstne a veľkonočné
						// 2006-08-22: pre 4. pôstnu nedeľu je ružová farbe rúcha
						if(_global_den.denvr == STVRTA_POSTNA_NEDELA)
							_global_den.farba = LIT_FARBA_RUZOVA_FIALOVA;
					}
					else{
						// vsedny den v poste
						_rozbor_dna_LOG("/* vsedny den v poste */\n");
						_global_den.smer = 9;
					}
				}
				else if(_global_den.denvr == KVETNA_NEDELA){
					// kvetna nedela
					_rozbor_dna_LOG("/* kvetna nedela */\n");
					_global_den.farba = LIT_FARBA_CERVENA;
					_global_den.litobd = OBD_POSTNE_II_VELKY_TYZDEN;
					_global_den.smer = 2; // nedele adventné, pôstne a veľkonočné
					mystrcpy(_global_den.meno, text_KVETNA_NEDELA[_global_jazyk], MENO_SVIATKU);
				}
				else if(_global_den.denvr <= ZELENY_STVRTOK){
					// po kvetnej nedeli, vo velkom tyzdni
					_rozbor_dna_LOG("/* po kvetnej nedeli, vo velkom tyzdni */\n");
					_global_den.litobd = OBD_POSTNE_II_VELKY_TYZDEN;
					_global_den.smer = 2; // nedele adventné, pôstne a veľkonočné
					// vsedne dni velkeho tyzdna od pondelka do stvrtka vratane
					if(_global_den.denvr == ZELENY_STVRTOK){
						mystrcpy(_global_den.meno, text_ZELENY_STVRTOK[_global_jazyk], MENO_SVIATKU);
						_global_den.farba = LIT_FARBA_FIALOVA_BIELA;
					}
				}
				else{
					_global_den.litobd = OBD_VELKONOCNE_TROJDNIE;
					_global_den.smer = 1;
					// velkonocne trojdnie umucenia a zmrtvychvstania
					_rozbor_dna_LOG("/* velkonocne trojdnie umucenia a zmrtvychvstania */\n");
					if(_global_den.denvr == VELKY_PIATOK){
						mystrcpy(_global_den.meno, text_VELKY_PIATOK[_global_jazyk], MENO_SVIATKU);
						_global_den.farba = LIT_FARBA_CERVENA;
					}
					else if(_global_den.denvr == BIELA_SOBOTA){
						mystrcpy(_global_den.meno, text_BIELA_SOBOTA[_global_jazyk], MENO_SVIATKU);
						// 2006-08-19: farba ostáva nastavená ako pre celý pôst - fialová
						// 2009-04-17: pridaná poznámka: biela sobota má fialovú farbu; len pre vigíliu je biela
						// _global_den.farba = LIT_FARBA_BIELA;
					}
				}
			}// if(_global_den.denvr <= BIELA_SOBOTA)

			// 2014-03-21: nastavenie lc_str_id pre pôstne obdobie -- iba ak nebolo nastavené vyššie
			if(equals(_global_den.lc_str_id, STR_EMPTY)){
				if(_global_den.denvt == DEN_NEDELA){
					sprintf(_global_den.lc_str_id, "%dP", _global_den.tyzden);
				}
				else{
					sprintf(_global_den.lc_str_id, "%dP%d", _global_den.tyzden, _global_den.denvt);
				}
			}
		}// if(_global_den.denvr >= POPOLCOVA_STREDA)
		else if(_global_den.denvr < POPOLCOVA_STREDA){
			// od 1.1. po post, teda bud vianocne obdobie alebo obdobie cez rok
			_rozbor_dna_LOG("/* od 1.1. po post, teda bud vianocne obdobie alebo obdobie cez rok */\n");
			if(_global_den.denvr == BOHORODICKY_PANNY_MARIE){
				// slavnost panny marie bohorodicky
				_rozbor_dna_LOG("/* slavnost panny marie bohorodicky */\n");
				_global_den.tyzden = 1; // 2011-01-27: doplnené; overoval som, či to nemôže padnúť na iný týždeň (nemôže)
				_global_den.farba = LIT_FARBA_BIELA;
				_global_den.kalendar = KALENDAR_VSEOBECNY;
				_global_den.smer = 3;
				_global_den.typslav = SLAV_SLAVNOST;
				_global_den.litobd = OBD_OKTAVA_NARODENIA;
				_global_den.prik = PRIKAZANY_SVIATOK;
				// 2011-02-01: pre SJ odlišný názov; ináč je všetko rovnaké
				if((_global_jazyk == JAZYK_SK) && (_global_kalendar == KALENDAR_SK_SJ)){
					mystrcpy(_global_den.meno, text_JAN_01_SJ[_global_jazyk], MENO_SVIATKU);
					_global_den.kalendar = KALENDAR_SK_SJ;
				}
				else{
					mystrcpy(_global_den.meno, text_JAN_01[_global_jazyk], MENO_SVIATKU);
				}
				// 2006-02-16: podreťazec (koniec Oktávy narodenia Pána) podobne ako (2. veľkonočná nedeľa) riešený pomocou "typslav_lokal"
				if((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP)){
					_global_den.typslav_lokal = LOKAL_SLAV_KONIEC_OKTAVY_NAR_CZ;
				}
				else if(_global_jazyk == JAZYK_HU){
					_global_den.typslav_lokal = LOKAL_SLAV_KONIEC_OKTAVY_NAR_HU;
				}
				else {
					_global_den.typslav_lokal = LOKAL_SLAV_KONIEC_OKTAVY_NAR;
				}
				// 2006-08-14: upravené; bude potrebné pre iné jazyky dorobiť konštanty

				sprintf(_global_den.lc_str_id, "%d.%d.", _global_den.den, _global_den.mesiac);
			}
			else if(_global_den.denvr == ZJAVENIE_PANA){
				// slavnost zjavenia pana
				_rozbor_dna_LOG("/* slavnost zjavenia pana */\n");
				_global_den.farba = LIT_FARBA_BIELA;
				_global_den.kalendar = KALENDAR_VSEOBECNY;
				_global_den.smer = 2; // zjavenie Pána
				_global_den.typslav = SLAV_SLAVNOST;
				_global_den.litobd = OBD_VIANOCNE_II; // ma vlastne slavenie; zmenil som na vianocne obd. II
				_global_den.prik = PRIKAZANY_SVIATOK;
				mystrcpy(_global_den.meno, text_JAN_06[_global_jazyk], MENO_SVIATKU);
				sprintf(_global_den.lc_str_id, "%d.%d.", _global_den.den, _global_den.mesiac);
			}
			else if((_global_den.denvt == DEN_NEDELA) && (_global_den.denvr >= 2) && (_global_den.denvr <= 5)){
				// druha nedela po narodeni pana medzi 2. a 5. januarom; v krajinach, kde sa slavnost zjavenia pana slavi 6. januara
				_rozbor_dna_LOG("/* druha nedela po narodeni pana medzi 2. a 5. januarom; v krajinach, kde sa slavnost zjavenia pana slavi 6. januara */\n");
				_global_den.farba = LIT_FARBA_BIELA;
				_global_den.kalendar = KALENDAR_VSEOBECNY;
				_global_den.smer = 6; // nedele vianocneho obdobia a obdobia "cez rok"
				_global_den.litobd = OBD_VIANOCNE_I;
				mystrcpy(_global_den.meno, text_DRUHA_NEDELA_PO_NAR_PANA[_global_jazyk], MENO_SVIATKU);
				_global_den.tyzden = 2; // 2009-01-05: doplnené, keďže v časti nižšie sme (správne) zapoznámkovali natvrdo nastavenie týždňa na 2
				mystrcpy(_global_den.lc_str_id, "2NP", MAX_LC_STR_ID);
			}
			else if(_global_den.denvr < KRST){
				// vianočné obdobie
				_rozbor_dna_LOG("/* vianocne obdobie */\n");
				_global_den.farba = LIT_FARBA_BIELA;
				_global_den.kalendar = KALENDAR_VSEOBECNY;
				// _global_den.tyzden = 2; -- 2007-01-08: pripomienkoval don Valábek; 2. týždeň je to až po 2. nedeli po narodení Pána | 2012-01-01 opravené nižšie
				// všedné dni vianočného obdobia od 2. januára do soboty po zjavení pána
				_global_den.smer = 13;
				// zistíme, či je pred alebo po zjavení pána
				if(_global_den.denvr < ZJAVENIE_PANA){
					_global_den.litobd = OBD_VIANOCNE_I;
					_rozbor_dna_LOG("/* pred zjavenim Pana */\n");
				}
				else{
					_global_den.litobd = OBD_VIANOCNE_II;
					_rozbor_dna_LOG("/* po zjaveni Pana (vratane) */\n");
				}
				// 2007-01-08, upravené priradenie týždňa žaltára;
				// keďže KRST je poradové číslo dňa v roku, ale je to vždy január, je to vlastne aj dátum
				// 2012-01-01: opravené; podľa smerníc (č. 133) -- "prvý týždeň sa začína na Prvú adventnú nedeľu, v prvý týždeň v Cezročnom období, na Prvú pôstnu nedeľu a na Prvú veľkonočnú nedeľu."
				if(KRST == 8){
					if(((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_ZJAVENIE_PANA_NEDELA) == BIT_OPT_0_ZJAVENIE_PANA_NEDELA)){
						// v krajinách, kde sa Zjavenie Pána slávi v nedeľu: ak Krst Krista Pána padne na 8.1. (pondelok), potom pred nedeľou Zjavenia Pána 7.1. sú všedné dni 1. týždeň žaltára (8.1. ako Krst Krista Pána nemôže padnúť na nedeľu; 8.1. ak je nedeľa, je to Zjavenie Pána a Krst Krista Pána je v pondelok 9.1.)
						_global_den.tyzden = 1;
					}
					else{
						// v krajinách, kde sa Zjavenie Pána slávi 6.1.: ak Krst Krista Pána pripadne na 8.1., všedné dni od 2. do 5. januára majú mať 1. týždeň žaltára (v tomto prípade 2. nedeľa po narodení Pána nie je, ale jej úlohu akoby zohráva 1.1.)
						_global_den.tyzden = 2;
					}// napr. SK rok 2012
				}
				else if(KRST == 7){
					// ak Krst Krista Pána pripadne na 7.1., všedné dni od 2. do 5. januára majú mať 1. týždeň žaltára (v týchto prípadoch 2. nedeľa po narodení Pána nie je)
					_global_den.tyzden = 1;
				}
				else{
					// keď Krst Krista Pána pripadne na 9.-13.1., závisí týždeň žaltára od toho, či deň je pred alebo po 2. nedeli po narodení Pána (jej dátum je vlastne KRST - 7)
					if(KRST - 7 > _global_den.denvr)
						_global_den.tyzden = 1;
					else
						_global_den.tyzden = 2;
					// 2012-01-01: podmienka je pre krajiny, kde sa slávnosť Zjavenia Pána slávi 6.1., ekvivalentná nasledovnej:
					// _global_den.tyzden = _global_den.denvr < "_global_r.p1" + 1)? 1: 2; // pritom "_global_r.p1" je 'A' = 0, 'b' = 1, 'c' = 2, 'd' = 3..., 'g' = 6
				}
			}// vianočné obdobie od KRST
			else if(_global_den.denvr > KRST){
				// obdobie cez rok po vianociach do popolcovej stredy
				_rozbor_dna_LOG("/* obdobie cez rok po vianociach do popolcovej stredy */\n");
				_global_den.farba = LIT_FARBA_ZELENA;
				_global_den.kalendar = KALENDAR_VSEOBECNY;
				_global_den.litobd = OBD_CEZ_ROK;
				// určenie týždňa v cezročnom období (v období "cez rok")
				// 2012-01-13: oprava pre prípady, kedy KRST padol na pondelok (po nedeli Zjavenia Pána v krajinách, kde sa Zjavenie Pána slávi v nedeľu, napr. HU)
				_global_den.tyzden = ((_global_den.denvr - KRST + _global_r._KRST_KRISTA_PANA.denvt) DIV 7) + 1; // nedeľa = 0, teda ako doteraz
				if(_global_den.denvt == DEN_NEDELA){
					// nedela v obdobi cez rok
					_rozbor_dna_LOG("/* nedela v obdobi cez rok */\n");
					_global_den.smer = 6; // nedele vianocneho obdobia a obdobia "cez rok"
				}
				else{
					// vsedny den v obdobi cez rok
					_rozbor_dna_LOG("/* vsedny den v obdobi cez rok */\n");
					_global_den.smer = 13; // vsedne dni "cez rok"
				}

				// 2014-03-21: nastavenie lc_str_id pre cezročné obdobie -- iba ak nebolo nastavené vyššie
				if(equals(_global_den.lc_str_id, STR_EMPTY)){
					if(_global_den.denvt == DEN_NEDELA){
						sprintf(_global_den.lc_str_id, "%dC", _global_den.tyzden);
					}
					else{
						sprintf(_global_den.lc_str_id, "%dC%d", _global_den.tyzden, _global_den.denvt);
					}
				}
			}// if(_global_den.denvr > KRST)
			else if(_global_den.denvr == KRST){
				// sviatok krstu krista pana, nedela po 6. januari
				_rozbor_dna_LOG("/* sviatok krstu krista pana, nedela po 6. januari */\n");
				_global_den = _global_r._KRST_KRISTA_PANA;
			}// if(_global_den.denvr == KRST)
		}// if(_global_den.denvr < POPOLCOVA_STREDA)
	}// if(_global_den.denvr < VELKONOCNA_NEDELA)
	else if(_global_den.denvr >= VELKONOCNA_NEDELA){
		// po velkej noci
		_rozbor_dna_LOG("/* po veľkej noci vrátane veľkonočnej nedele (t.j. _global_den.denvr >= VELKONOCNA_NEDELA) */\n");
		if(_global_den.denvr <= ZOSLANIE_DUCHA_SV){
			// velkonocne obdobie (po zoslanie d.s.)
			_rozbor_dna_LOG("/* velkonocne obdobie (po zoslanie d.s.) */\n");
			_global_den.farba = LIT_FARBA_BIELA;
			_global_den.kalendar = KALENDAR_VSEOBECNY;
			_global_den.tyzden = ((_global_den.denvr - VELKONOCNA_NEDELA) DIV 7) + 1;

			if(_global_den.denvr == ZOSLANIE_DUCHA_SV){
				// zoslanie ducha svateho
				_rozbor_dna_LOG("/* zoslanie ducha svateho */\n");
				_global_den = _global_r._ZOSLANIE_DUCHA_SV;
			}
			else if(_global_den.denvr <= DRUHA_VELKONOCNA_NEDELA){
				// velkonocna oktava
				_rozbor_dna_LOG("/* velkonocna oktava */\n");
				_global_den.litobd = OBD_VELKONOCNA_OKTAVA;
				_global_den.smer = 2; // dni velkonocnej oktavy
				if(_global_den.denvr == VELKONOCNA_NEDELA){
					// velkonocna nedela
					_rozbor_dna_LOG("/* velkonocna nedela */\n");
					_global_den = _global_r._VELKONOCNA_NEDELA;
				}
				else{
					// velkonocna oktava
					_rozbor_dna_LOG("/* velkonocna oktava */\n");
					_global_den.litobd = OBD_VELKONOCNA_OKTAVA;
					if(_global_den.denvr == DRUHA_VELKONOCNA_NEDELA){
						// 2. velkonocna nedela
						_rozbor_dna_LOG("/* 2. velkonocna nedela */\n");
						mystrcpy(_global_den.meno, text_NEDELA_VO_VELKONOCNEJ_OKTAVE[_global_jazyk], MENO_SVIATKU);
						// 2006-02-08: podreťazec (2. veľkonočná nedeľa) riešený pomocou "typslav_lokal"
						if(_global_jazyk == JAZYK_SK)
							_global_den.typslav_lokal = LOKAL_SLAV_DRUHA_VELK_NEDELA;
						else if(_global_jazyk == JAZYK_CZ)
							_global_den.typslav_lokal = LOKAL_SLAV_DRUHA_VELK_NEDELA_CZ;
						else if(_global_jazyk == JAZYK_HU)
							_global_den.typslav_lokal = LOKAL_SLAV_DRUHA_VELK_NEDELA_HU;
					}
					else{
						// veľkonočná oktáva - 'všedný deň' vo veľkonočnej oktáve
						_rozbor_dna_LOG("/* veľkonočná oktáva - 'všedný deň' vo veľkonočnej oktáve */\n");
						if(_global_jazyk == JAZYK_SK){
							sprintf(_global_den.meno, text_DEN_VO_VELKONOCNEJ_OKTAVE[_global_jazyk], koncovka_dna(_global_den.denvt), nazov_dna(_global_den.denvt));
						}
						else if((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP)){
							sprintf(_global_den.meno, text_DEN_VO_VELKONOCNEJ_OKTAVE[_global_jazyk], nazov_Dna(_global_den.denvt));
						}
						else if(_global_jazyk == JAZYK_HU){
							if(_global_den.denvt == DEN_PONDELOK){
								// veľkonočný pondelok ináč
								mystrcpy(_global_den.meno, (char *)text_HU_VELKONOCNY_PONDELOK, MENO_SVIATKU);
							}
							else{
								sprintf(_global_den.meno, text_DEN_VO_VELKONOCNEJ_OKTAVE[_global_jazyk], nazov_dna(_global_den.denvt));
							}
						}
						else{ // default
							sprintf(_global_den.meno, text_DEN_VO_VELKONOCNEJ_OKTAVE[_global_jazyk], nazov_dna(_global_den.denvt));
						}
					}
				}
			}// if(_global_den.denvr <= DRUHA_VELKONOCNA_NEDELA)
			else if(_global_den.denvr == NANEBOVSTUPENIE){
				// _global_den.denvr == NANEBOVSTUPENIE, nanebovstupenie Pana
				_rozbor_dna_LOG("/* nanebovstupenie Pana */\n");
				_global_den = _global_r._NANEBOVSTUPENIE_PANA;
			}// if(_global_den.denvr == NANEBOVSTUPENIE)
			else{
				if(_global_den.denvr < NANEBOVSTUPENIE){
					// velkonocne obdobie do nanebovstupenia
					_rozbor_dna_LOG("/* velkonocne obdobie do nanebovstupenia */\n");
					_global_den.litobd = OBD_VELKONOCNE_I;
				}
				else{
					// velkonocne obdobie po nanebovstupeni do zoslania ducha
					_rozbor_dna_LOG("/* velkonocne obdobie po nanebovstupeni do zoslania ducha */\n");
					_global_den.litobd = OBD_VELKONOCNE_II;
				}
				if(_global_den.denvt == DEN_NEDELA){
					_rozbor_dna_LOG("/* nedela */\n");
					_global_den.smer = 2; // nedele adventné, pôstne a veľkonočné
				}// nedela
				else{
					_rozbor_dna_LOG("/* vsedne dni velkonocneho obdobia od pondelka po velkonocnej oktave az do soboty pred zoslanim ducha svateho vcitane */\n");
					_global_den.smer = 13; // vsedne dni velkonocneho obdobia od pondelka po velkonocnej oktave az do soboty pred zoslanim ducha svateho vcitane
				}// nie nedela
			}// if(_global_den.denvr != NANEBOVSTUPENIE)

			// 2014-03-21: nastavenie lc_str_id pre veľkonočné obdobie
			if(_global_den.denvt == DEN_NEDELA){
				sprintf(_global_den.lc_str_id, "%dV", _global_den.tyzden);
			}
			else{
				sprintf(_global_den.lc_str_id, "%dV%d", _global_den.tyzden, _global_den.denvt);
			}
		}// if(_global_den.denvr >= VELKONOCNA_NEDELA)
		else if(_global_den.denvr > ZOSLANIE_DUCHA_SV){
			// obdobie cez rok po velkej noci a dalej (advent, vianocne obdobie do 31.12.)
			_rozbor_dna_LOG("/* obdobie cez rok po velkej noci a dalej (advent, vianocne obdobie do 31.12.) */\n");
			if(_global_den.denvr < PRVA_ADVENTNA_NEDELA){
				// obdobie cez rok po velkej noci do prvej adventnej nedele
				_rozbor_dna_LOG("/* obdobie cez rok po velkej noci do prvej adventnej nedele */\n");
				_global_den.farba = LIT_FARBA_ZELENA;
				_global_den.kalendar = KALENDAR_VSEOBECNY;
				_global_den.litobd = OBD_CEZ_ROK;
				// urcim tyzden v obdobi "cez rok"
				_global_den.tyzden = POCET_NEDIEL_CEZ_ROK -
					((PRVA_ADVENTNA_NEDELA - _global_den.denvr - 1) DIV 7);
				_rozbor_dna_LOG("/* %d. tyzden v obdobi cez rok */\n", _global_den.tyzden);

				// 2011-11-07: slávnosť najsv. Kristovho tela a krvi predsunutá pred rozhodovanie, či je nedeľa (pretože v niektorých krajinách nie je ZOSLANIE_DUCHA_SV + 11 (teda vo štvrtok), ale presúva sa na nedeľu)
				if(_global_den.denvr == TELAKRVI){
					// najsv. Kristovho tela a krvi == ZOSLANIE_DUCHA_SV + 11
					_global_den.farba = LIT_FARBA_BIELA;
					_rozbor_dna_LOG("/* najsv. krist. tela a krvi */\n");
					_global_den.smer = 3; // slávnosti Pána
					_global_den.typslav = SLAV_SLAVNOST;
					_global_den.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_den.meno, text_NAJSV_KRISTOVHO_TELA_A_KRVI[_global_jazyk], MENO_SVIATKU);
					mystrcpy(_global_den.lc_str_id, "9V4", MAX_LC_STR_ID);
				}// TELAKRVI
				else if(_global_den.denvt == DEN_NEDELA){
					// i.-ta nedela v obdobi cez rok
					_rozbor_dna_LOG("/* nedela v ocr */\n");
					if(_global_den.denvr == TROJICA){
						// najsv. trojice == ZOSLANIE_DUCHA_SV + 7
						_global_den.farba = LIT_FARBA_BIELA;
						_rozbor_dna_LOG("/* najsv. trojice */\n");
						_global_den.smer = 3; // slávnosti Pána
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, text_NAJSVATEJSEJ_TROJICE[_global_jazyk], MENO_SVIATKU);
						mystrcpy(_global_den.lc_str_id, "9V", MAX_LC_STR_ID);
					}
					else if(_global_den.tyzden == KRISTA_KRALA){
						// krista krala
						_global_den.farba = LIT_FARBA_BIELA;
						_rozbor_dna_LOG("/* krista krala */\n");
						_global_den.smer = 3; // slávnosti Pána
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, text_KRISTA_KRALA[_global_jazyk], MENO_SVIATKU);
						// _global_den.lc_str_id je nastavené nižšie, štandardne
					}
					// 2010-10-13: pridané: pre redemptoristov: 3. nedeľa v júli
					else if((((_global_jazyk == JAZYK_SK) && (_global_kalendar == KALENDAR_SK_CSSR)) || ((_global_jazyk == JAZYK_CZ) && (_global_kalendar == KALENDAR_CZ_CSSR))) && (_global_den.mesiac - 1 == MES_JUL) && (_global_den.den > 14) && (_global_den.den <= 21)){
						// pre redemptoristov: 3. nedeľa v júli
						_global_den.farba = LIT_FARBA_BIELA;
						_rozbor_dna_LOG("/* pre redemptoristov: 3. nedeľa v júli */\n");
						_global_den.smer = 3; // slávnosti Pána
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, text_CSSR_TITUL_KONGREGACIE[_global_jazyk], MENO_SVIATKU);
						_global_den.kalendar = _global_kalendar;
					}
					else{
						_global_den.smer = 6; // nedele vianocneho obdobia a obdobia "cez rok"
					}
				}// DEN_NEDELA
				else{
					// den v i.-tom tyzdni obdobia cez rok
					_rozbor_dna_LOG("/* den v %d. tyzdni obdobia cez rok */\n", _global_den.tyzden);

					if(_global_den.denvr == ZOSLANIE_DUCHA_SV + 1){
						// Svätodušný pondelok -- kvôli liturgickým čítaniam
						mystrcpy(_global_den.lc_str_id, "8V1", MAX_LC_STR_ID);
						_global_den.smer = 13; // vsedne dni `cez rok'
						_rozbor_dna_LOG("/* vsedne dni `cez rok' -- Svätodušný pondelok */\n");
					}
					else if(_global_den.denvr == SRDCA){
						// srdca jezisovho == ZOSLANIE_DUCHA_SV + 19
						_global_den.farba = LIT_FARBA_BIELA;
						_rozbor_dna_LOG("/* srdca jezisovho */\n");
						_global_den.smer = 3; // slávnosti Pána
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, text_NAJSV_SRDCA_JEZISOVHO[_global_jazyk], MENO_SVIATKU);
						mystrcpy(_global_den.lc_str_id, "10V5", MAX_LC_STR_ID);
					}
					else if((_global_den.denvr == KRISTA_KNAZA) && (_global_jazyk == JAZYK_SK)){
						// KRISTA_KNAZA (ZOSLANIE_DUCHA_SV + 4)
						_global_den.farba = LIT_FARBA_BIELA;
						_rozbor_dna_LOG("/* Krista kňaza */\n");
						_global_den.smer = 5; // sviatky Pána uvedené vo všeobecnom kalendári
						_global_den.typslav = SLAV_SVIATOK;
						mystrcpy(_global_den.meno, text_NPJK_NAJ_KNAZA[_global_jazyk], MENO_SVIATKU);
					}
					else if(_global_den.denvr == SRDPM){
						// srdca prebl. panny marie == ZOSLANIE_DUCHA_SV + 20
						_global_den.farba = LIT_FARBA_BIELA;
						_rozbor_dna_LOG("/* srdca prebl. panny marie */\n");

						// 2003-06-30: povodne tu bolo 11: "miestne povinne spomienky podla vseobecneho kalendara",
						// zmenil som to na 10.
						if((_global_jazyk == JAZYK_SK) && (_global_kalendar == KALENDAR_SK_OFM)){
							_global_den.smer = 10;
							_global_den.typslav = SLAV_SPOMIENKA;
							_global_den.kalendar = KALENDAR_SK_OFM;
							_global_den.typslav_lokal = LOKAL_SLAV_SVIATOK_OFMCAP;
							mystrcpy(_global_den.meno, text_NEPOSKVRNENEHO_SRDCA_PM_OFM[_global_jazyk], MENO_SVIATKU);
						}
						else{
							_global_den.smer = 10;
							_global_den.typslav = SLAV_SPOMIENKA;
							mystrcpy(_global_den.meno, text_NEPOSKVRNENEHO_SRDCA_PM[_global_jazyk], MENO_SVIATKU);
						}
						_global_den.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_opt[OPT_3_SPOLOCNA_CAST] = MODL_SPOL_CAST_PANNA_MARIA;
						// 2003-06-30: porov. pasaz venovanu srdcu pm vo funkcii dbzaltar.cpp::sviatky_svatych(); -- 2 vstupy

						// nemá popis; 2013-02-04: doplnené
						if((_global_jazyk != JAZYK_CZ) || (_global_jazyk != JAZYK_CZ_OP)){
							set_popis_dummy();
						}
					}
					else{
						_global_den.smer = 13; // vsedne dni `cez rok'
						_rozbor_dna_LOG("/* vsedne dni `cez rok' */\n");
					}
				}// všedný deň, nie nedeľa

				// 2014-03-21: nastavenie lc_str_id pre cezročné obdobie -- iba ak nebolo nastavené vyššie
				if(equals(_global_den.lc_str_id, STR_EMPTY)){
					if(_global_den.denvt == DEN_NEDELA){
						sprintf(_global_den.lc_str_id, "%dC", _global_den.tyzden);
					}
					else{
						sprintf(_global_den.lc_str_id, "%dC%d", _global_den.tyzden, _global_den.denvt);
					}
				}
			}// if(_global_den.denvr < PRVA_ADVENTNA_NEDELA)
			else if(_global_den.denvr >= PRVA_ADVENTNA_NEDELA){
				// adventne obdobie resp. vianocne
				_rozbor_dna_LOG("/* adventne obdobie resp. vianocne */\n");

				if(_global_den.denvr < NARODENIE_PANA){
					// adventne obdobie
					_rozbor_dna_LOG("/* adventne obdobie */\n");
					_global_den.farba = LIT_FARBA_FIALOVA;
					_global_den.kalendar = KALENDAR_VSEOBECNY;
					_global_den.tyzden = ((_global_den.denvr - PRVA_ADVENTNA_NEDELA) DIV 7) + 1;
					if(_global_den.denvr <= DECEMBER_16){
						// do 16. decembra
						_rozbor_dna_LOG("/* do 16. decembra */\n");
						_global_den.litobd = OBD_ADVENTNE_I;
						if(_global_den.denvt == DEN_NEDELA){
							_global_den.smer = 2; // nedele adventné, pôstne a veľkonočné
							_rozbor_dna_LOG("/* nedela */\n");
							sprintf(_global_den.lc_str_id, "%dA", _global_den.tyzden);
						}
						else{
							_global_den.smer = 13; // vsedne dni adventne az do 16. decembra
							_rozbor_dna_LOG("/* vsedny den */\n");
							sprintf(_global_den.lc_str_id, "%dA%d", _global_den.tyzden, _global_den.denvt);
						}
					}
					else{
						// po 16. decembri
						_rozbor_dna_LOG("/* po 16. decembri */\n");
						_global_den.litobd = OBD_ADVENTNE_II;
						if(_global_den.denvt == DEN_NEDELA){
							_global_den.smer = 2; // nedele adventné, pôstne a veľkonočné
							_rozbor_dna_LOG("/* nedela */\n");
							sprintf(_global_den.lc_str_id, "%dA", _global_den.tyzden);
						}
						else{
							_global_den.smer = 9; // adventne dni od 17. do 24. decembra vratane
							_rozbor_dna_LOG("/* vsedny den od 17. do 24. decembra vratane */\n");
							sprintf(_global_den.lc_str_id, "%d.%d.", _global_den.den, _global_den.mesiac);
						}
					}
					// 2006-08-22: pre 3. adventnú nedeľu je ružová farba rúcha
					if(_global_den.denvr == TRETIA_ADVENTNA_NEDELA){
						_global_den.farba = LIT_FARBA_RUZOVA_FIALOVA;
					}
				}// if(_global_den.denvr < NARODENIE_PANA)
				else if(_global_den.denvr >= NARODENIE_PANA){
					// vianocne obdobie
					_rozbor_dna_LOG("/* vianocne obdobie */\n");
					_global_den.farba = LIT_FARBA_BIELA;
					_global_den.kalendar = KALENDAR_VSEOBECNY;
					_global_den.litobd = OBD_OKTAVA_NARODENIA; // pretoze do 31.12.
					// 2008-01-05: podľa smerníc, č. 133, nie je 1. týždeň žaltára;  pokračuje sa v týždňoch od 1. adventnej nedele
					// upozornil Vlado Kiš (napr. 29. december 2007 al. 2012 = 4. týždeň žaltára)
					// kedysi tu bolo: _global_den.tyzden = 1; 
					// 2011-01-27: keďže sa to používa na určenie týždňa žaltára, môžeme tam pokojne dať "MOD 4", pretože "5. týždeň" nemá zmysel
					_global_den.tyzden = (((_global_den.denvr - PRVA_ADVENTNA_NEDELA) DIV 7) MOD 4) + 1;
					if(_global_den.denvr == NARODENIE_PANA){
						// narodenie pana
						_rozbor_dna_LOG("/* narodenie pana */\n");
						_global_den.typslav = SLAV_SLAVNOST;
						_global_den.smer = 2; // narodenie pana
						_global_den.prik = PRIKAZANY_SVIATOK;
						mystrcpy(_global_den.meno, text_NARODENIE_PANA[_global_jazyk], MENO_SVIATKU);
						sprintf(_global_den.lc_str_id, "%d.%d.", _global_den.den, _global_den.mesiac);
					}
					else if(_global_den.denvr == SV_RODINY){
						// nedela sv. rodiny
						_rozbor_dna_LOG("/* nedela sv. rodiny */\n");
						// ked padne NARODENIE_PANA na nedelu, sviatok sv. rodiny sa slavi 30. dec a nema prve vespery
						_global_den = _global_r._SVATEJ_RODINY;
					}
					else{
						_global_den.smer = 9; // dni v oktave narodenia pana
						_rozbor_dna_LOG("/* dni v oktave narodenia pana */\n");
						sprintf(_global_den.lc_str_id, "%d.%d.", _global_den.den, _global_den.mesiac);
					}
				}// if(_global_den.denvr >= NARODENIE_PANA)
			}// if(_global_den.denvr >= PRVA_ADVENTNA_NEDELA)
		}// if(_global_den.denvr > ZOSLANIE_DUCHA_SV)
	}// if(_global_den.denvr >= VELKONOCNA_NEDELA)

	if(_global_den.tyzzal == 0){
		// neurčili sme týždeň v žaltári, urobíme tak teraz
		_rozbor_dna_LOG("/* neurčili sme týždeň v žaltári, urobíme tak teraz */\n");
		_rozbor_dna_LOG("/* _global_den.tyzden == %d */\n", _global_den.tyzden);
		_global_den.tyzzal = TYZZAL(_global_den.tyzden); // ((_global_den.tyzden + 3) MOD 4) + 1; // povodne tu bolo: (_global_den.tyzden - 1) MOD 4
		_rozbor_dna_LOG("tyzzal == %d\n", _global_den.tyzzal);
	}
	else{
		_rozbor_dna_LOG("/* týždeň žaltára už bol určený, tyzzal == %d */\n", _global_den.tyzzal);
	}

	// _rozbor_dna_LOG("_global_den:\n"); Log(_global_den); // pridane 01/03/2000A.D.

	_rozbor_dna_LOG("Nasleduje porovnanie so sviatkami svätých (môže ich byť viacero):\n");
	// nasleduje porovnanie so sviatkami svatych; berieme do uvahy, ze moze byt viac lubovolnych spomienok
	_rozbor_dna_LOG("_global_den.smer == %d\n", _global_den.smer);
	_rozbor_dna_LOG("_global_den.spolcast == %d\n", _global_den.spolcast);

	// 2003-06-30, odkomentovane kvoli lepsiemu debugovaniu
	_rozbor_dna_LOG("spustam sviatky_svatych(%d, %d);...\n", _global_den.den, _global_den.mesiac);

	_global_pocet_svatych = sviatky_svatych(_global_den.den, _global_den.mesiac);
	_rozbor_dna_LOG("_global_pocet_svatych = %d\n", _global_pocet_svatych);

	// 2003-06-30
	// 2003-10-07; prve nedelne vespery nemali prosby, chyba bola v dbzaltar.cpp::_SET_SPOLOCNE_VECI_NEDELA
	// _rozbor_dna_LOG("(1) _global_modl_prve_vespery:\n"); Log(_global_modl_prve_vespery);
	// 2009-03-19: debugovanie kvôli kompletóriu po prvých vešperách 18. marca - sv. Jozefa
	// _rozbor_dna_LOG("(1) _global_modl_prve_kompletorium:\n"); Log(_global_modl_prve_kompletorium);

	// pridane 28/03/2000A.D.: ak chce vacsie cislo (poradie svateho) ako je v _global_pocet_svatych resp. ked nie je sobota a chce poradie svateho PORADIE_PM_SOBOTA (spomienka p. marie v sobotu)
	if((_global_pocet_svatych == 0) && (_global_pocet_svatych < poradie_svaty) && (poradie_svaty != PORADIE_PM_SOBOTA)){
		_rozbor_dna_LOG("returning from _rozbor_dna(), because: (_global_pocet_svatych == 0) && (_global_pocet_svatych < poradie_svaty) && (poradie_svaty != %d)\n", PORADIE_PM_SOBOTA);
		ALERT;
		Export("V tento deň nie je sviatok žiadneho svätého, preto nemôžete požadovať svätého č. %d.", poradie_svaty);
		return FAILURE;
	}
	else if((_global_pocet_svatych < poradie_svaty) && (poradie_svaty != PORADIE_PM_SOBOTA)){
		_rozbor_dna_LOG("returning from _rozbor_dna(), because: (_global_pocet_svatych < poradie_svaty) && (poradie_svaty != %d)\n", PORADIE_PM_SOBOTA);
		ALERT;
		Export("Nie je viac ako %d sviatkov svätých v tento deň, preto nemôžete požadovať svätého č. %d.", _global_pocet_svatych, poradie_svaty);
		return FAILURE;
	}
	else if((_global_den.denvt != DEN_SOBOTA) && (poradie_svaty == PORADIE_PM_SOBOTA)){
		_rozbor_dna_LOG("returning from _rozbor_dna(), because: (_global_den.denvt != DEN_SOBOTA) && (poradie_svaty == %d)\n", PORADIE_PM_SOBOTA);
		ALERT;
		Export("Tento deň je %s, a nie je sobota, takže nemôžete požadovať modlitbu `Spomienka Panny Márie v sobotu'.\n", nazov_dna(_global_den.denvt));
		return FAILURE;
	}

	// ak predošlé kontroly sú OK, ideme porovnávať "dôležitosť" sviatku určeného v sviatky_svatych() s "bežným" dňom určeným vyššie
	_rozbor_dna_LOG("ak predošlé kontroly sú OK, ideme porovnávať `dôležitosť' sviatku určeného v sviatky_svatych() s `bežným' dňom určeným vyššie\n");
	_rozbor_dna_LOG("sviatky_svatych() == %d\n", _global_pocet_svatych);
	if(_global_pocet_svatych > 0){

		// treba pamatat na to, ze v poste sa vsetky spomienky stavaju lubovolnymi (c. 14 vseob. smernic)
		// 2012-03-21: doplnené: aj _global_svaty2/3 môže maž v sebe "spomienku" (miestnu), preto treba opraviť aj toto
		for(short int i = 0; i < MAX_POCET_SVATY; i++){
			if((_global_den.litobd == OBD_POSTNE_I) && (_global_pocet_svatych > i) &&
				(_global_svaty(i + 1).typslav == SLAV_SPOMIENKA)){
				 _rozbor_dna_LOG("je pôstne obdobie, tak mením `spomienku' na `ľubovoľnú spomienku' aj pre _global_svaty(%d)\n", i + 1);
				 _global_svaty(i + 1).typslav = SLAV_LUB_SPOMIENKA;
				 // 2006-01-20: doplnené, lebo nezobrazovalo tieto ľubovoľné spomienky
				 if(_global_svaty(i + 1).smer < 12){
					 _global_svaty(i + 1).smer = 12;
				 }
			}
			else{
				_rozbor_dna_LOG("nie je pôstne obdobie, nie je potrebné meniť spomienku na ľubovoľnú spomienku (_global_svaty(%d))...\n", i + 1);
			}
		}

		short int podmienka_svaty_vedie = NIE;
		short int podmienka_svaty_vedie_pom = NIE;
		Log("_global_den.smer == %d...\n", _global_den.smer);
		for(short int i = 0; i < MAX_POCET_SVATY; i++){
			Log("_global_svaty(%d).smer == %d...\n", i + 1, _global_svaty(i + 1).smer);
			// 2013-08-04: pridaná kontrola podmienky 'podmienka_svaty_vedie'
			if((_global_den.smer > _global_svaty(i + 1).smer) && !MIESTNE_SLAVENIE_LOKAL_SVATY(i + 1)){
				podmienka_svaty_vedie = ANO;
			}
			if(_global_den.smer > _global_svaty(i + 1).smer){
				podmienka_svaty_vedie_pom = ANO;
			}
		}

		// c. 12 v c. 59 vseob. smernic: "lubovolne spomienky, ktore sa mozu slavit aj v dnoch uvedenych pod c. 9 [...] tak isto v omsi a oficiu
		// na sposob lubovolnych spomienok mozno slavit tie povinne spomienky, ktore obcas pripadnu na vsedne dni v poste." ...
		if(((_global_den.smer == 9) &&
			 (_global_svaty1.typslav == SLAV_LUB_SPOMIENKA)) || (podmienka_svaty_vedie == ANO)
			// ... alebo c. 60: "ak na jeden den pripadnu viacere slavenia, uprednostni sa to, ktore ma v tabulke liturgickych dni vyssi stupen [t.j. .smer].
			// 2010-07-28: doplnené alternatívne porovnanie aj s _global_svaty2.smer (kvôli dominikánskej slávnosti 8.8.) 
			// 2010-10-06: upravené; nesmie ísť o lokálnu slávnosť (smer == 4) lebo nemá prebíjať "globálnu" v danom kalendári [napr. czop pre 22.10.]
			// 2011-02-02: zadefinované MIESTNE_SLAVENIE_CZOP_SVATY(i), aby sa zjednodušila podmienka (platí len pre CZOP)
			// 2011-03-07: MIESTNE_SLAVENIE_CZOP_SVATY(i) použité aj pre iné lokálne slávenia ako MIESTNE_SLAVENIE_LOKAL_SVATY(i)
			// 2013-08-04: kontroluje sa dynamicky, vyššie
		){

			// ked bola nasledovna pasaz zapoznamkovana, tak vsetko (bez modlitby) slo v poriadku; neslo generovanie modlitby ok;
			// naopak, ked som ju odpoznamkoval 16/02/2000A.D., prestalo to ist bez modlitby (iba generovalo ok)
			// preto som to dal podla toho, ci _global_modlitba != MODL_NEURCENA (18/02/2000A.D.)
			// 23/02/2000A.D. -- SVATY_VEDIE
			_rozbor_dna_LOG("svaty ma prednost pred dnom (SVATY_VEDIE)\n");
			_rozbor_dna_LOG("_global_den.smer == %d, _global_svaty1.smer == %d, _global_svaty1.prik == %d\n", _global_den.smer, _global_svaty1.smer, _global_svaty1.prik);

			// cele to tu bolo asi kvoli tomu, ze niektore veci sa pri generovani modlitby citali z _global_den explicitne; zda sa, ze to ide aj bez toho;
			// napr. v BUTTONS (teda v tom export...) sa cita z _global_svaty... | 08/03/2000A.D.
			// akvsak ked som to cele zrusil, tak prestali fungovat prve vespery slavnosti, ktore mali definovane vecicky v _global_svaty1, pretoze sa nikde nepriradili do _global_den;
			// takze som to napokon dal sem a pridal podmienku "iba ak ide o slavnost" | 15/03/2000A.D.
			_rozbor_dna_LOG("modlitba == %d (%s)...\n", _global_modlitba, nazov_modlitby(_global_modlitba));
			if((_global_modlitba != MODL_NEURCENA) && 
				(
					(poradie_svaty != UNKNOWN_PORADIE_SVATEHO) || // 08/03/2000A.D. -- pridané; 2009-03-27: zmenená konštanta 0 na UNKNOWN_PORADIE_SVATEHO
					((poradie_svaty == UNKNOWN_PORADIE_SVATEHO) 
						// a je to alebo slávnosť, alebo sviatok Pána v Cezročnom období, ktorý padne na nedeľu (2013-02-03: opravené) -- napr. kvôli Obetovaniu Pána 2.2.2003/2014, prvé vešpery
						&& (
								(_global_svaty1.smer < 5) ||
								((_global_svaty1.smer == 5) && (_global_den.denvt == DEN_NEDELA) && ((_global_den.litobd == OBD_CEZ_ROK) || je_vianocne(_global_den.litobd)))
						)
						// a neplatí, že ide o lokálnu slávnosť: tá nesmie prebiť všedný deň
						// 2010-10-06: upravené; nesmie ísť o lokálnu slávnosť (smer == 4) lebo nemá prebíjať "globálnu" v danom kalendári [napr. czop pre 22.10.]
						// 2011-02-02: zadefinované MIESTNE_SLAVENIE_CZOP_SVATY(i), aby sa zjednodušila podmienka (platí len pre CZOP)
						// 2011-03-07: MIESTNE_SLAVENIE_CZOP_SVATY(i) použité aj pre iné lokálne slávenia ako MIESTNE_SLAVENIE_LOKAL_SVATY(i)
						&& !MIESTNE_SLAVENIE_LOKAL_SVATY(1)
					) // slavnosti
				)
			){
				short int poradie_svaty_pom = 1;
				if(poradie_svaty != UNKNOWN_PORADIE_SVATEHO){
					poradie_svaty_pom = poradie_svaty;
				}
				_rozbor_dna_LOG("bola splnená podmienka...\n");
				// menim, lebo svaty ma prednost
				// 2006-02-06: pre viacero ľubovoľných spomienok treba byť obozretnejší | 2013-08-05: snáď opravené
				_rozbor_dna_LOG("\tporadie_svaty == %d; poradie_svaty_pom == %d\n", poradie_svaty, poradie_svaty_pom);
				_rozbor_dna_LOG("\t_global_den.denvt == %d (%s), _global_den.litobd == %d (%s)...\n", _global_den.denvt, nazov_dna(_global_den.denvt), _global_den.litobd, nazov_obdobia_ext(_global_den.litobd));
				_rozbor_dna_LOG("mením, lebo svätý `%d'/`%d' má prednosť...\n", poradie_svaty, poradie_svaty_pom);
				
				if(poradie_svaty_pom != PORADIE_PM_SOBOTA){
					_rozbor_dna_LOG("\t_global_svaty(%d).smer == %d...\n", poradie_svaty_pom, _global_svaty(poradie_svaty_pom).smer);

					Log("do _global_den priraďujem _global_svaty(%d)... (`%s')\n", poradie_svaty_pom, _global_svaty(poradie_svaty_pom).meno);
					mystrcpy(_global_den.meno, _global_svaty(poradie_svaty_pom).meno, MENO_SVIATKU); // priradenie názvu dňa
					_global_den.smer = _global_svaty(poradie_svaty_pom).smer; // dôležitosť sviatku podľa smerníc
					_global_den.typslav = _global_svaty(poradie_svaty_pom).typslav;
					_global_den.typslav_lokal = _global_svaty(poradie_svaty_pom).typslav_lokal;
					_global_den.spolcast = _global_svaty(poradie_svaty_pom).spolcast;
					_global_den.prik = _global_svaty(poradie_svaty_pom).prik;
				}
				else{
					Log("do _global_den by som mal priradiť _global_pm_sobota (%d)... (`%s') -- PRESKAKUJEM, ANI DOTERAZ SA TO NEROBILO!\n", poradie_svaty_pom, _global_pm_sobota.meno);
				}
			}// koniec menenia pre _global_modlitba != MODL_NEURCENA a svaty > 0 resp. slavnost
		}
		else{
			// neuprednostnujeme svatych pred dnom
			_rozbor_dna_LOG("neuprednostňujeme svätých pred dňom (alternatíva k SVATY_VEDIE)\n");
			// 2010-10-06: upravené; v tejto vetve rozhodovania treba riešiť to, že nebola splnená vyššie uvedená novo-upravená podmienka o "prebití" nedele napr. lokálnou slávnosťou
			if(podmienka_svaty_vedie_pom == ANO){
				_rozbor_dna_LOG("HOCI neuprednostňujeme svätých pred dňom (alternatíva k SVATY_VEDIE), keďže je tu lokálna slávnosť, ponechávame nastavené _global_pocet_svatych == %d\n", _global_pocet_svatych);
			}
			else{
				_global_pocet_svatych = 0;
			}
		}

		if(_global_pocet_svatych > 0){
			// nasledovná úprava _global_opt[OPT_3_SPOLOCNA_CAST] presunutá sem z časti, kedy "SVATY_VEDIE", aby sa aplikovala aj na druhú vetvu
			// pridané 2006-02-06; upravujeme premennú _global_opt[OPT_3_SPOLOCNA_CAST] ak nebola nastavená MODL_SPOL_CAST_NEBRAT
			// treba nastaviť podľa toho, ktorý svätý je (môže byť 1--3)  a zároveň brať do úvahy eventuálne prednastavenie od používateľa
			// 2012-10-22: doplnený case 0 vo switch-i, spôsobovalo problémy pre slávnosti, ktoré majú nastavenú spoločnú časť priamo v _global_den (napr. 15. septembra) | upozornil Vlado Kiš
			_rozbor_dna_LOG("Premenná _global_opt[OPT_3_SPOLOCNA_CAST] pred úpravou == %d (%s)...(poradie_svaty == %d)\n", _global_opt[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_3_SPOLOCNA_CAST] <= MODL_SPOL_CAST_NEBRAT ? nazov_spolc(_global_opt[OPT_3_SPOLOCNA_CAST]) : STR_EMPTY, poradie_svaty);
			if(_global_opt[OPT_3_SPOLOCNA_CAST] != MODL_SPOL_CAST_NEBRAT){
				switch(poradie_svaty){
					case 0:
						sc = _decode_spol_cast(_global_den.spolcast);
						break;
					case PORADIE_PM_SOBOTA:
						sc.a1 = MODL_SPOL_CAST_PANNA_MARIA; // 2006-02-06: spomienka PM v sobotu
						break;
					default: 
						sc = _decode_spol_cast(_global_svaty(poradie_svaty).spolcast);
						break;
				}// switch(poradie_svaty)
				_rozbor_dna_LOG("\tNastavil som do premennej sc == (%d) %s, (%d) %s, (%d) %s\n", sc.a1, nazov_spolc(sc.a1), sc.a2, nazov_spolc(sc.a2), sc.a3, nazov_spolc(sc.a3));
				if(sc.a1 != MODL_SPOL_CAST_NEURCENA){
					if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
						if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
							if((_global_opt[OPT_3_SPOLOCNA_CAST] != sc.a1)
							&& (_global_opt[OPT_3_SPOLOCNA_CAST] != sc.a2)
							&& (_global_opt[OPT_3_SPOLOCNA_CAST] != sc.a3)){
								_global_opt[OPT_3_SPOLOCNA_CAST] = sc.a1; // iba ak nie je ani podľa jednej z nenullovývch, zmením
							}
						}
						else{
							if((_global_opt[OPT_3_SPOLOCNA_CAST] != sc.a1)
							&& (_global_opt[OPT_3_SPOLOCNA_CAST] != sc.a2)){
								_global_opt[OPT_3_SPOLOCNA_CAST] = sc.a1; // iba ak nie je ani podľa jednej z nenullovývch, zmením
							}
						}
					}
					else{
						if(_global_opt[OPT_3_SPOLOCNA_CAST] != sc.a1){
							_global_opt[OPT_3_SPOLOCNA_CAST] = sc.a1; // iba ak nie je ani podľa jednej z nenullovývch, zmením
						}
					}
				}
				else{
					_rozbor_dna_LOG("\tHmmm, pre svätca nie je nastavená spoločná časť, nechávam _global_opt[OPT_3_SPOLOCNA_CAST] tak ako je...\n");
				}

				_rozbor_dna_LOG("\tNastavil som _global_opt[OPT_3_SPOLOCNA_CAST] == %d (%s)...\n", 
					_global_opt[OPT_3_SPOLOCNA_CAST], 
					_global_opt[OPT_3_SPOLOCNA_CAST] <= MODL_SPOL_CAST_NEBRAT ? nazov_spolc(_global_opt[OPT_3_SPOLOCNA_CAST]) : STR_EMPTY);
			}// if(_global_opt[OPT_3_SPOLOCNA_CAST] != MODL_SPOL_CAST_NEBRAT)
			else{
				_rozbor_dna_LOG("\tKeďže používateľ nechcel brať spoločnú časť, neupravujem.\n");
			}
		}
	}// (_global_pocet_svatych > 0)

	_rozbor_dna_LOG("sviatky_svatych(%d, %d) skoncila a ukoncilo sa aj rozhodovanie\n", _global_den.den, _global_den.mesiac);

	// prikazane sviatky - boli oznacene na prislusnych miestach

	// inicializujem spomienku panny marie v sobotu
	_rozbor_dna_LOG("inicializujem spomienku panny márie v sobotu... (realizuje sa vždy napevno)\n");
	init_global_pm_sobota(); // v liturgia.cpp
	// _rozbor_dna_LOG("init_global_pm_sobota(): _global_pm_sobota:\n"); Log(_global_pm_sobota); // pridane 27/04/2000A.D.

	_rozbor_dna_LOG("end\n", datum.den, datum.mesiac, rok, poradie_svaty);
	// export -- je inde: _export_rozbor_dna() a v _rozbor_dna_s_modlitbou();

	Log("_rozbor_dna(): 3 parametre -- returning SUCCESS...\n");
	return SUCCESS;
}// _rozbor_dna()

short int _rozbor_dna(_struct_den_mesiac datum, short int rok){
	short int ret;
	Log("_rozbor_dna(): 2 parametre -- begin (spúšťame s tretím parametrom == UNKNOWN_PORADIE_SVATEHO [%d])\n", UNKNOWN_PORADIE_SVATEHO);
	ret = _rozbor_dna(datum, rok, UNKNOWN_PORADIE_SVATEHO);
	Log("_rozbor_dna(): 2 parametre -- returning %d\n", ret);
	return ret;
}// _rozbor_dna()

// --------------------------------------------------------------------

// init_global_string()
// vstup: typ (o aky sposob vypisu ide)
//        poradie_svateho
//        modlitba
//        aj_citanie -- či prilepiť odkaz na liturgické čítanie
//
// vystup: do _global_string da string (spolu s HTML tagmi) s nazvom slavenia;
//
// navratova hodnota: SUCCESS/FAILURE
#define CASE_VELKE  5
#define CASE_MALE   4
#define COLOR_RED   3
#define COLOR_BLACK 2

// lokalna premenna, do ktorej sa ukladaju info o analyzovanom dni
// 2012-10-12: z funkcie init_global_string() som ju spravil globálnou kvôli tomu, aby sme ju mohli používať v 
_struct_dm _local_den;

short int init_global_string(short int typ, short int poradie_svateho, short int modlitba, short int aj_citanie = NIE) {
	_INIT_DM(_local_den); // 2003-08-07 pridana

	char pom[MAX_STR], pom2[MAX_STR], pom3[SMALL]; // pom2 doplnené 2011-02-02; pom3 doplnené 2011-03-23
	char popisok_lokal[MAX_STR];
	char popisok_kalendar[MAX_STR];
	mystrcpy(pom, STR_EMPTY, MAX_STR);
	mystrcpy(popisok_lokal, STR_EMPTY, MAX_STR);
	mystrcpy(popisok_kalendar, STR_EMPTY, MAX_STR);
	mystrcpy(_global_string, STR_EMPTY, MAX_GLOBAL_STR);
	mystrcpy(_global_string2, STR_EMPTY, MAX_GLOBAL_STR2); // inicializácia, upravená dĺžka
	mystrcpy(_global_string_farba, STR_EMPTY, MAX_GLOBAL_STR_FARBA);
	mystrcpy(_global_string_modlitba, STR_EMPTY, SMALL);
	mystrcpy(_global_string_podnadpis, STR_EMPTY, SMALL);

	short int farba = COLOR_BLACK;
	short int velkost = CASE_MALE;
	short int obyc = NIE;
	short int liturgicka_farba = LIT_FARBA_NEURCENA;
	short int liturgicka_farba_alt = LIT_FARBA_NEURCENA;
	short int export_farby = ANO; // 2013-03-13: doplnené
#ifdef LITURGICKE_CITANIA_ANDROID
	struct citanie *cit = NULL;
#endif // LITURGICKE_CITANIA_ANDROID

	Log("-- init_global_string(EXPORT_DNA_%d, %d, %s, %d) -- začiatok\n", typ, poradie_svateho, nazov_modlitby(modlitba), aj_citanie);
	Log("   (inicializuje tri _global_string* premenné)\n");
	// --------------------------------------------------------------------
	// najprv priradime do _local_den to, co tam ma byt

	Log("poradie_svateho == %d\n", poradie_svateho);
	// sviatky (spomienky, ls) svatych

	if(poradie_svateho == PORADIE_PM_SOBOTA){
		// do _local_den priradim slavenie pm v sobotu v dalsom
		if(_global_den.denvt != DEN_SOBOTA){
			Log("Tento den nie je sobota, preto nemoze mat spomienku P. Marie v sobotu!\n");
			ALERT;
	        Export("Tento deň nie je sobota, preto nemôže mať `spomienku Panny Márie v sobotu'!\n");
			return FAILURE;
		}
		else{
			// do _local_den priradim dane slavenie
			_local_den = _global_pm_sobota;
			Log("priradujem _local_den = _global_pm_sobota;\n");
		}
	}// poradie_svateho == PORADIE_PM_SOBOTA
	else if((poradie_svateho > 0) && (poradie_svateho < PORADIE_PM_SOBOTA)){
		if(_global_pocet_svatych > poradie_svateho - 1){
			// do _local_den priradim dane slavenie
			_local_den = _global_svaty(poradie_svateho);
#ifdef LITURGICKE_CITANIA_ANDROID
			cit = najdiCitanie(getCode(&_global_svaty(poradie_svateho)));
#endif // LITURGICKE_CITANIA_ANDROID
			Log("priradujem _local_den = _global_svaty(%d);\n", poradie_svateho);
		}
		else{
			// sice chce svateho c. 'poradie_svateho', ale máme ich menej
			Log("-- Error: _global_svaty(%d) not assigned (init_global_string)\n", poradie_svateho);
			ALERT;
			sprintf(pom, "Error: _global_svaty(%d) not assigned (init_global_string)", poradie_svateho);
			strcat(_global_string, pom);
			Export("%s\n", _global_string);
			return FAILURE;
		}
	}// poradie_svateho = 1, 2, 3... až MAX_POCET_SVATY
	else if(poradie_svateho > PORADIE_PM_SOBOTA){
		Log("-- Error/init_global_string: poradie_svateho == %d (max.: %d)\n", poradie_svateho, PORADIE_PM_SOBOTA);
		ALERT;
		Export("Error/init_global_string: poradie_svateho == %d (max.: %d)\n", poradie_svateho, PORADIE_PM_SOBOTA);
		return FAILURE;
	}// poradie_svateho > PORADIE_PM_SOBOTA
	else{
		// poradie_svateho == UNKNOWN_PORADIE_SVATEHO
		// 2010-09-28: odvetvené kvôli tým prípadom, keď na nedeľu padne sviatok pána, ale používa sa poradie_svaty == UNKNOWN_PORADIE_SVATEHO == 0 
		//             časť prevzatá z: liturgicke_obdobie(), začiatok funkcie; hoci tu sa použije len pre smer == 5 (sviatky pána); slávnosti sa riešia samostatne
		Log("_global_den.smer == %d\n", _global_den.smer);
		Log("_global_svaty1.smer == %d\n", _global_svaty1.smer);
		// 2014-04-08: presunuté do #define PODMIENKA_SVIATKY_PANA_SVATYCH_PREDNOST | sviatky Pána a svätých, ktoré majú prednosť pred Cezročnou nedeľou a majú (ak padnú na nedeľu) svoje vlastné prvé vešpery
		if((_global_svaty1.smer == 5) && (PODMIENKA_SVIATKY_PANA_SVATYCH_PREDNOST)){
			// do _local_den priradim dane slavenie
			_local_den = _global_svaty(1);
#ifdef LITURGICKE_CITANIA_ANDROID
			cit = najdiCitanie(getCode(&_global_svaty(1)));
#endif // LITURGICKE_CITANIA_ANDROID
			Log("priradujem _local_den = _global_svaty(1);\n");
		}
		else{
			// bezny den
			Log("/* bezny den */\n");
			obyc = ANO;
			_local_den = _global_den;
		}
	}// poradie_svateho == UNKNOWN_PORADIE_SVATEHO

	int ma_nazov = 0;
#ifdef LITURGICKE_CITANIA_ANDROID
	if (!cit){
		Log("nepodarilo sa načítať cit, preto použijem default...\n");
		cit = najdiCitanie(getCode(&_global_den));
		if (!cit){
			Log("nepodarilo sa načítať ani len default pre cit.\n");
		}// if (!cit); 2. pokus
	}// if (!cit)
#endif // LITURGICKE_CITANIA_ANDROID

	Log("1:_local_den.meno == %s\n", _local_den.meno);

	// spomienka panny márie v sobotu
	// este spomienka panny marie v sobotu, cl. 15
	// 2006-02-02: pridané posv. čítania a upravené; keďže smer == 11 používame pre lokálne povinné spomienky, upravili sme kontrolu z 12 na 11
	// 2009-11-26: porovnávame klasicky, resp. špeciálne pre body 4, 8, 11 [Miestne slávnosti, Miestne sviatky, Miestne povinné spomienky] pred touto úpravou tu bola kontrola (_global_svaty1.smer >= 11)
	// 2011-02-02: zadefinované MIESTNE_SLAVENIE_CZOP_SVATY(i), aby sa zjednodušila podmienka (platí len pre CZOP)
	// 2011-03-07: MIESTNE_SLAVENIE_CZOP_SVATY(i) použité aj pre iné lokálne slávenia ako MIESTNE_SLAVENIE_LOKAL_SVATY(i)
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			((_global_den.smer >= 11) && (_global_pocet_svatych == 0)) ||
			(((_global_svaty1.smer >= 12) || MIESTNE_SLAVENIE_LOKAL_SVATY(1)) && (_global_pocet_svatych > 0))) &&
		(poradie_svateho == PORADIE_PM_SOBOTA)){
		// teraz do _global_den priradim dane slavenie
		_local_den = _global_pm_sobota;
	}

	Log("2:_local_den.meno == %s\n", _local_den.meno);
	
	// skontrolujeme ešte pondelok -- štvrtok vo veľkom týždni (nastavenie názvu aj pre export na viac dní)
	if(_local_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN){
		// 2008-04-04: aj kompletórium pre zelený štvrtok má svoj vlastný názov, tak isto ako doteraz vešpery
		if(!((_local_den.denvt == DEN_NEDELA) || ((_local_den.denvt == DEN_STVRTOK) && ((typ != EXPORT_DNA_VIAC_DNI) && ((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM))) ))){
			if(_global_jazyk == JAZYK_HU){
				// 2012-03-21: pre HU sú aj dni pondelok až streda (štvrtok sa rieši inde) s vlastnými názvami
				mystrcpy(_local_den.meno, text_HU_VELKY_TYZDEN_PREFIX, MENO_SVIATKU);
				strcat(_local_den.meno, nazov_dna(_local_den.denvt));
			}// HU only
			else{
				mystrcpy(_local_den.meno, nazov_dna(_local_den.denvt), MENO_SVIATKU);
				// 2007-04-05: upravené pre viacero jazykov
				strcat(_local_den.meno, " ");
				strcat(_local_den.meno, nazov_obdobia_v(_local_den.litobd));
			}
		}
	}

	Log("3:_local_den.meno == %s\n", _local_den.meno);
	// --------------------------------------------------------------------
	// teraz podla toho, co je v _local_den, vytvorime _global_string
	Log("_local_den.smer < 5 -- ");
	if(_local_den.smer < 5){
		// slávnosti
		velkost = CASE_VELKE;
		Log("ano\n");
	}
	else{
		Log("nie\n");
	}

	Log("_local_den.denvt == DEN_NEDELA || _local_den.prik == PRIKAZANY_SVIATOK -- ");
	if((_local_den.denvt == DEN_NEDELA) ||
		(_local_den.prik == PRIKAZANY_SVIATOK)){
		// prikazane sviatky a nedele
		farba = COLOR_RED;
		Log("ano\n");
	}
	else{
		Log("nie\n");
	}

	// najprv názov; ak ide o ľubovoľnú spomienku na blahoslaveného (napr. SK OP), zobrazí sa názov kurzívou
	if(_local_den.prik == VOLNA_LUBOVOLNA_SPOMIENKA){
		mystrcpy(_global_string, "<"HTML_SPAN_BOLD_IT">", MAX_GLOBAL_STR);
	}
	else if(typ != EXPORT_DNA_VIAC_DNI_TXT){
		mystrcpy(_global_string, "<"HTML_SPAN_BOLD">", MAX_GLOBAL_STR);
	}

	if((farba == COLOR_RED) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
		strcat(_global_string, "<"HTML_SPAN_RED_TITLE">");
	}
	Log("4:_local_den.meno == %s\n", _local_den.meno);

	if(equals(_local_den.meno, STR_EMPTY)){
		Log("slávenie nemá vlastný názov...\n");
		if(_local_den.denvt == DEN_NEDELA){
			Log("nedeľa, ktorá nemá vlastný názov... (_global_string == %s)\n", _global_string);
			// nedeľa bez vlastného názvu
			// 2008-12-20: úprava názvov nedieľ v štýle "3. NEDEĽA V ADVENTNOM OBDOBÍ" -> "Tretia adventná nedeľa" 
			// 2011-05-16: dlho bolo len pre slovenčinu; upravené kvôli maďarčine
			if(
				(_local_den.litobd == OBD_ADVENTNE_I) || (_local_den.litobd == OBD_ADVENTNE_II)
				|| (_local_den.litobd == OBD_POSTNE_I)
				|| (_local_den.litobd == OBD_VELKONOCNE_I) || (_local_den.litobd == OBD_VELKONOCNE_II)
			){
				if((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP)){
					sprintf(pom, "%s %s %s", poradie_SLOVOM(_local_den.tyzden - 1), nazov_DNA(_local_den.denvt), nazov_OBDOBIA_AKA(_local_den.litobd));
				}
				else if(_global_jazyk == JAZYK_HU){
					sprintf(pom, "%s %s %s%s", nazov_OBDOBIA_AKA(_local_den.litobd), poradie_SLOVOM(_local_den.tyzden - 1), nazov_DNA(_local_den.denvt), KONCOVKA_DNA_HU);
				}
				else /* if(_global_jazyk == JAZYK_SK) */{
					sprintf(pom, "%s %s %s", poradie_SLOVOM(_local_den.tyzden - 1), nazov_OBDOBIA_AKA(_local_den.litobd), nazov_DNA(_local_den.denvt));
				}
			}// špeciálne nedele slovom
			else{
				// _local_den.litobd == OBD_CEZ_ROK; pre cezročné ostáva poradové číslo
				if(_global_jazyk == JAZYK_HU){
					sprintf(pom, "%s %d. %s", nazov_OBDOBIA_AKA(_local_den.litobd), _local_den.tyzden, nazov_DNA(_local_den.denvt));
				}
				else{
					sprintf(pom, "%d. %s %s", _local_den.tyzden, nazov_DNA(_local_den.denvt), nazov_OBDOBIA_V(_local_den.litobd));
				}
			}// ostatné nedele číslom

			if((farba == COLOR_RED) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
				// zmenene <font color> na <span>, 2003-07-02
				strcat(pom, HTML_SPAN_END);
			}

			if(typ != EXPORT_DNA_VIAC_DNI_TXT){
				strcat(pom, HTML_SPAN_END); // kvôli HTML_SPAN_BOLD, 2003-09-06
			}

			// 2006-09-06: pridané prilepenie "týždňa žaltára" aj pre nedele
			if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
				strcat(_global_string, pom); // 2006-08-03: prilepujeme nadvakrát
				sprintf(pom, HTML_LINE_BREAK"<"HTML_SPAN_SMALL">");
				sprintf(pom2, html_text_tyzden_zaltara_cislo[_global_jazyk], tyzden_zaltara(_local_den.tyzden));
				strcat(pom, pom2);
				strcat(pom, HTML_SPAN_END);
			}
			strcat(_global_string, pom);
			ma_nazov = 1;
		}// nedeľa
		else{ // nie nedeľa
			Log("deň iný ako nedeľa, ktorý nemá vlastný názov... (_global_string == %s)\n", _global_string);
			// doplnené zátvorky, kvôli span-ovačkám na konci
			if(obyc == ANO){
			// 2005-03-21: Pridany dalsi typ exportu
				if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE)){
					Log("(typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE)\n");
#ifdef OLD_STYLE_obycajny_den
					sprintf(pom, "%s, %s"HTML_SPAN_END", %d",
						nazov_Dna(_local_den.denvt),
						nazov_obdobia(_local_den.litobd),
						tyzden_zaltara(_local_den.tyzden));
					strcat(pom, html_text_tyzden_zaltara[_global_jazyk]);
#else
					// dni po popolcovej strede na začiatku pôstneho obdobia - "nultý" týždeň
					if((_local_den.tyzden == 0) && (_local_den.litobd == OBD_POSTNE_I)){
						Log("dni po popolcovej strede na začiatku pôstneho obdobia - 'nultý' týždeň\n");
						// 2008-01-05: doplnená viacjazyčnosť pre text "po Popolcovej strede"
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, HTML_SPAN_END""HTML_LINE_BREAK"<"HTML_SPAN_SMALL">");
						}
						else{
							mystrcpy(pom2, STR_EMPTY, MAX_STR);
						}
						sprintf(pom, "%s %s, %s", nazov_Dna(_local_den.denvt), (char *)text_PO_POPOLCOVEJ_STREDE[_global_jazyk], nazov_obdobia(_local_den.litobd));
						strcat(pom, pom2);
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, html_text_tyzden_zaltara_cislo[_global_jazyk], tyzden_zaltara(_local_den.tyzden));
							strcat(pom, pom2);
						}
					}// ((_local_den.tyzden == 0) && (_local_den.litobd == OBD_POSTNE_I))
					// dni po narodení pána pred nedeľou v oktáve narodenia pána (ak je) majú žaltár zo 4. týždňa | 2008-01-05: doplnenné, zmenený popis
					else if(_local_den.litobd == OBD_OKTAVA_NARODENIA){
						Log("_local_den.litobd == OBD_OKTAVA_NARODENIA\n");
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, HTML_SPAN_END""HTML_LINE_BREAK"<"HTML_SPAN_SMALL">");
						}
						else{
							mystrcpy(pom2, STR_EMPTY, MAX_STR);
						}
						if(_global_jazyk == JAZYK_HU){
							sprintf(pom, "%s alatti %d. nap", (char *)text_V_OKTAVE_NARODENIA[_global_jazyk], (_local_den.den - 24));
						}
						else{
							sprintf(pom, "%s %s", nazov_Dna(_local_den.denvt), (char *)text_V_OKTAVE_NARODENIA[_global_jazyk]);
						}
						strcat(pom, pom2);
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, html_text_tyzden_zaltara_cislo[_global_jazyk], tyzden_zaltara(_local_den.tyzden));
							strcat(pom, pom2);
						}
					}// (_local_den.litobd == OBD_OKTAVA_NARODENIA)
					// skontrolujeme ešte 17.-23. decembra (obdobie OBD_ADVENTNE_II)
					else if((_local_den.litobd == OBD_ADVENTNE_II) && (typ != EXPORT_DNA_VIAC_DNI)){
						Log("(_local_den.litobd == OBD_ADVENTNE_II) && (typ != EXPORT_DNA_VIAC_DNI)\n");

						// 2011-12-19: pôvodne: sprintf(pom, "%d. %s, %s, ", _local_den.den, nazov_mesiaca_gen(_local_den.mesiac - 1), nazov_obdobia(_local_den.litobd));

						// najprv názov dňa (pondelok, utorok...)...
						sprintf(pom, "%s, ", nazov_Dna(_local_den.denvt));

						// ...potom dátum + genitív mesiaca...
						// 2013-05-17: ale iba v takom prípade, že mesiac je december (pre použitie "liturgické obdobie" je dátum neinicializovaný, teda 1. januára
						if((_local_den.mesiac == MES_DEC) && (_local_den.den >= 16) && (_local_den.den <= 24)){
							mystrcpy(pom2, _vytvor_string_z_datumu(_local_den.den, _local_den.mesiac, _local_den.rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN) || (_global_jazyk == JAZYK_HU))? CASE_Case : CASE_case, LINK_DEN_MESIAC_GEN, NIE), MAX_STR);
							strcat(pom, pom2);
							mystrcpy(pom2, ", ", MAX_STR);
							strcat(pom, pom2);
						}

						// ...liturgické obdobie (adventné)...
						sprintf(pom2, "%s, ", nazov_obdobia(_local_den.litobd));
						strcat(pom, pom2);

						// ...a napokon týždeň žaltára
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, HTML_SPAN_END);
						}
						else{
							mystrcpy(pom2, STR_EMPTY, MAX_STR);
						}
						strcat(pom, pom2);
						sprintf(pom2, html_text_tyzden_cislo[_global_jazyk], _local_den.tyzden);
						strcat(pom, pom2);
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, HTML_LINE_BREAK"<"HTML_SPAN_SMALL">");
						}
						else{
							mystrcpy(pom2, STR_EMPTY, MAX_STR);
						}
						strcat(pom, pom2);
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, html_text_tyzden_zaltara_cislo[_global_jazyk], tyzden_zaltara(_local_den.tyzden));
							strcat(pom, pom2);
						}
					}// ((_local_den.litobd == OBD_ADVENTNE_II) && (typ != EXPORT_DNA_VIAC_DNI))
					else{
						Log("else...\n");
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							sprintf(pom2, HTML_SPAN_END);
						}
						else{
							mystrcpy(pom2, STR_EMPTY, MAX_STR);
						}
						sprintf(pom, "%s, %s, ", nazov_Dna(_local_den.denvt), nazov_obdobia(_local_den.litobd));
						sprintf(pom3, html_text_tyzden_cislo[_global_jazyk], _local_den.tyzden);
						strcat(pom, pom3);
						strcat(pom, pom2);
						if(typ != EXPORT_DNA_VIAC_DNI_TXT){
							strcat(_global_string, pom); // 2006-08-03: prilepujeme nadvakrát
							sprintf(pom, HTML_LINE_BREAK"<"HTML_SPAN_SMALL">");
							sprintf(pom3, html_text_tyzden_zaltara_cislo[_global_jazyk], tyzden_zaltara(_local_den.tyzden));
							strcat(pom, pom3);
							// strcat(pom, pom2); // </span> sa priliepa nižšie; 2011-03-23
						}
					}// default, cezročné obdobie a ostatné "obyčajné" dni
#endif
					strcat(_global_string, pom);
					ma_nazov = 1;
				}// nie export na viac dní
				else 
					Log("else [ (typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) ] \n");
					if (typ == EXPORT_DNA_VIAC_DNI_SIMPLE){
						// 2005-03-21: Pridane
						sprintf(pom, "%s, %s"HTML_SPAN_END", ", nazov_Dna(_local_den.denvt), nazov_obdobia(_local_den.litobd));
						sprintf(pom2, html_text_tyzden_zaltara_cislo[_global_jazyk], _local_den.tyzden);
						strcat(pom, pom2);
						strcat(_global_string, pom);
						ma_nazov = 1;
					}
				// inak ostane string prazdny

				if((farba == COLOR_RED) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
					Log("(farba == COLOR_RED) && (typ != EXPORT_DNA_VIAC_DNI_TXT), priliepam koniec span...\n");
					// zmenene <font color> na <span>, 2003-07-02
					strcat(_global_string, HTML_SPAN_END);
				}
				if(typ != EXPORT_DNA_VIAC_DNI_TXT){
					Log("typ != EXPORT_DNA_VIAC_DNI_TXT, priliepam koniec span...\n");
					strcat(_global_string, HTML_SPAN_END);
				}
			}
			else{
				Log("-- Error: _local_den.meno == \"\", avsak obyc != ANO\n");
			}
		}// nie je to nedeľa, teda iba obyčajný deň, ktorý nemá vlastný názov
	}// if(equals(_local_den.meno, STR_EMPTY))
	else{
		Log("pridávam vlastný názov...\n");
		// vlastny nazov
		if(_local_den.denvt == DEN_NEDELA){
			// nedela co ma vlastny nazov
			strcat(_global_string, caps_BIG(_local_den.meno));
		}
		else if(velkost == CASE_VELKE)
			strcat(_global_string, caps_BIG(_local_den.meno));
		else
			strcat(_global_string, _local_den.meno);
		ma_nazov = 1;

		if((farba == COLOR_RED) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
			// zmenene <font color> na <span>, 2003-07-02
			strcat(_global_string, HTML_SPAN_END);
		}
		if(typ != EXPORT_DNA_VIAC_DNI_TXT){
			strcat(_global_string, HTML_SPAN_END);
		}
	}// _local_den.meno != STR_EMPTY

	// 2006-09-06: z tohto miesta presunutá kontrola na červenú farbu vyššie - if(farba == COLOR_RED)

	// teraz typ slávenia; nevypisuje sa, ak ide o ľubovoľnú spomienku na blahoslaveného (napr. SK OP), kedy sa zobrazí názov kurzívou
	if((_local_den.typslav != SLAV_NEURCENE) && ((_local_den.prik != VOLNA_LUBOVOLNA_SPOMIENKA) /* || (typ != EXPORT_DNA_VIAC_DNI) */)){
		// 2011-01-27: úprava (možnosť zalomenia; Igor Galád)
		if(typ != EXPORT_DNA_VIAC_DNI_TXT){
#define TYPSLAV_NOVY_RIADOK
#if defined(TYPSLAV_NOVY_RIADOK_CIARKA)
			sprintf(pom, ", "HTML_LINE_BREAK);
#elif defined(TYPSLAV_NOVY_RIADOK)
			sprintf(pom, " "HTML_LINE_BREAK);
#else
			sprintf(pom, ", ");
#endif
		}
		else{
			sprintf(pom, ", ");
		}
		strcat(_global_string, pom);

		if(typ != EXPORT_DNA_VIAC_DNI_TXT){
			sprintf(pom, "<"HTML_SPAN_RED_TITLE">");
		}
		else{
			mystrcpy(pom, STR_EMPTY, MAX_STR);
		}
		// 2012-02-09: pre spomienku na privilegované dni (VSLH č. 238-239) sa exportuje iný názov slávenia
		if((_local_den.typslav == SLAV_LUB_SPOMIENKA) && (je_privileg)){
			sprintf(pom2, "%s", nazov_slavenia_na_spomienku_jazyk[_global_jazyk]);
		}
		else{
			sprintf(pom2, "%s", nazov_slavenia(_local_den.typslav));
		}
		strcat(pom, pom2);
		if(typ != EXPORT_DNA_VIAC_DNI_TXT){
			strcat(pom, HTML_SPAN_END);
		}
		Log("pridávam typ slávenia: %s\n", pom);
		strcat(_global_string, pom);
	}
	
	// 2010-10-11: pôvodne tu bola len lokalizácia slavenia; pridali sme k tomu aj prípadnú poznámku o lokálnom kalendári 
	// 2011-02-02: odvetvené len pre exporty iné ako EXPORT_DNA_VIAC_DNI_TXT
	if(typ != EXPORT_DNA_VIAC_DNI_TXT){
		mystrcpy(popisok_kalendar, nazov_kalendara_long[_local_den.kalendar], MAX_STR);
		mystrcpy(popisok_lokal, STR_EMPTY, MAX_STR);
		// teraz lokalizácia slavenia resp. poznámku o lokálnom kalendári, 2005-07-27: pridané; 2010-10-11: rozšírené
		if(_local_den.typslav_lokal != LOKAL_SLAV_NEURCENE) {
			mystrcpy(popisok_lokal, nazov_slavenia_lokal[_local_den.typslav_lokal], MAX_STR);
		}
		short int strlen_popisok_kalendar = 0, strlen_popisok_lokal = 0;
		strlen_popisok_kalendar = strlen(popisok_kalendar);
		strlen_popisok_lokal = strlen(popisok_lokal);
		if(strlen_popisok_kalendar + strlen_popisok_lokal > 0){
			if((strlen_popisok_kalendar > 0) && (strlen_popisok_lokal > 0)){
				strcat(popisok_kalendar, " | ");
			}
			sprintf(pom, "\n"HTML_LINE_BREAK"<"HTML_SPAN_RED_SUBTITLE">(%s%s)"HTML_SPAN_END"\n", popisok_kalendar, popisok_lokal);
			Log("pridávam lokalizáciu slávenia resp. poznámku o lokálnom kalendári: %s\n", pom);
			strcat(_global_string, pom);
		}

#ifdef OS_Windows_Ruby
		if(typ != EXPORT_DNA_XML){
			// 2010-08-03: pridaný ako poznámka typ kalendára
			if((_local_den.kalendar >= KALENDAR_NEURCENY) && (_local_den.kalendar <= POCET_KALENDAROV)){
				sprintf(pom, "<!-- kalendár: %s -->", nazov_kalendara_short[_local_den.kalendar]);
				Log("pridávam ako poznámku typ kalendára: %s\n", pom);
				strcat(_global_string, pom);
			}
			else{
				sprintf(pom, "<!-- kalendár nie je určený správne -->");
				strcat(_global_string, pom);
			}
		}
#endif

		// 2011-10-03: odkaz na liturgické čítanie sa doplní, iba ak je aj_citanie == ANO
		if(((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_CITANIA) == BIT_OPT_0_CITANIA) && aj_citanie){
#ifdef LITURGICKE_CITANIA_ANDROID
			if (cit && aj_citanie) {
				if (typ == EXPORT_DNA_DNES || typ == EXPORT_DNA_JEDEN_DEN || typ == EXPORT_DNA_VIAC_DNI) {
					if(ma_nazov){
						strcat(_global_string, HTML_LINE_BREAK);
					}
					sprintf(pom, "<a href=\"svpismo://svpismo.riso.ksp.sk/?d=%d&amp;m=%d&amp;y=%d&amp;c=", _local_den.den, _local_den.mesiac, _local_den.rok);
					strcat(_global_string, pom);
					strcat(_global_string, StringEncode(cit->citania));
					sprintf(pom, "&amp;zalm=");
					strcat(_global_string, pom);
					strcat(_global_string, StringEncode(cit->zalm));
					//
					sprintf(pom, "&amp;aleluja=");
					strcat(_global_string, pom);
					strcat(_global_string, StringEncode(cit->aleluja));
					sprintf(pom, "\">%s</a>", cit->citania);
					strcat(_global_string, pom);
				}
			}// if (cit && aj_citanie)
#elif defined(BEHAVIOUR_WEB)
			// 2011-07-26: doplnené pre BEHAVIOUR_WEB ináč ako pre ANDROID
			sprintf(pom, HTML_LINE_BREAK"<"HTML_SPAN_SMALLCAPS">");
			strcat(_global_string, pom);
			if(_global_jazyk == JAZYK_SK){
				sprintf(pom, "<a target=\"_blank\" href=\"http://lc.kbs.sk/?den=%04d%02d%02d", _local_den.rok, _local_den.mesiac, _local_den.den);
			}
			else if((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP)){
				sprintf(pom, "<a target=\"_blank\" href=\"http://www.katolik.cz/kalendar/kalendar.asp?d=%d&m=%d&r=%d", _local_den.den, _local_den.mesiac, _local_den.rok);
			}
			else if(_global_jazyk == JAZYK_HU){
				sprintf(pom, "<a target=\"_blank\" href=\"http://www.katolikus.hu/igenaptar/%04d%02d%02d.html", _local_den.rok, _local_den.mesiac, _local_den.den);
			}
			else{
				sprintf(pom, "<a target=\"_blank\" href=\"%04d-%02d-%02d", _local_den.rok, _local_den.mesiac, _local_den.den);
			}
			Log("pridávam odkaz na liturgické čítania (1): %s\n", pom);
			strcat(_global_string, pom);
			sprintf(pom, "\">%s</a>", (char *)html_text_option0_citania[_global_jazyk]);
			Log("pridávam odkaz na liturgické čítania (2): %s\n", pom);
			strcat(_global_string, pom);
			sprintf(pom, HTML_SPAN_END);
			Log("pridávam odkaz na liturgické čítania (3): %s\n", pom);
			strcat(_global_string, pom);
#endif // not LITURGICKE_CITANIA_ANDROID // BEHAVIOUR_WEB
		}// if(((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_CITANIA) == BIT_OPT_0_CITANIA) && aj_citanie)
	}// lokalizácia slávenia a kalendár
	else{
		sprintf(pom, " (%s)", _local_den.lc_str_id);
		Log("pridávam odkaz na liturgické čítania (lc.kbs.sk): %s\n", pom);
		strcat(_global_string, pom);
	}// typ == EXPORT_DNA_VIAC_DNI_TXT

	Log("  -- _global_string == %s\n", _global_string);

	// inicializujem _global_string2
	if(((_global_r._POPOLCOVA_STREDA.den == _local_den.den) &&
		(_global_r._POPOLCOVA_STREDA.mesiac == _local_den.mesiac)) || // popolcova streda
		((_local_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) && (typ == EXPORT_DNA_VIAC_DNI)) || // pondelok -- streda velkeho tyzdna
		(_local_den.smer > 8)) // nie slavnosti ani sviatky ani nedele
	{
		mystrcpy(_global_string2, rimskymi_tyzden_zaltara[tyzden_zaltara(_global_den.tyzden)], MAX_GLOBAL_STR2);
	}
	else if(_local_den.denvt == DEN_NEDELA){
		// 13/03/2000A.D. -- pridane, aby aj nedele mali tyzden zaltara
		sprintf(_global_string2, "%c, %s", _local_den.litrok, rimskymi_tyzden_zaltara[tyzden_zaltara(_global_den.tyzden)]);
	}
	else{
		mystrcpy(_global_string2, "V", MAX_GLOBAL_STR2);
	}

	Log("  -- _global_string2 == %s\n", _global_string2);

	// napokon inicializujem _global_string_farba

	// 2006-08-19: pridaná liturgická farba
	liturgicka_farba = _local_den.farba;

	// 2011-03-24: zložené farby
	//	LIT_FARBA_FIALOVA_CIERNA	== LIT_FARBA_FIALOVA a LIT_FARBA_CIERNA
	//	LIT_FARBA_FIALOVA_BIELA		== LIT_FARBA_FIALOVA a LIT_FARBA_BIELA
	// 2011-03-25: ešte zložená farba
	//	LIT_FARBA_RUZOVA_FIALOVA	== LIT_FARBA_RUZOVA a LIT_FARBA_FIALOVA
	if((liturgicka_farba == LIT_FARBA_FIALOVA_CIERNA) || (liturgicka_farba == LIT_FARBA_FIALOVA_BIELA) || (liturgicka_farba == LIT_FARBA_RUZOVA_FIALOVA)){
		if(liturgicka_farba == LIT_FARBA_RUZOVA_FIALOVA){
			liturgicka_farba_alt = LIT_FARBA_FIALOVA;
			liturgicka_farba = LIT_FARBA_RUZOVA;
		}
		else{
			liturgicka_farba_alt = (liturgicka_farba == LIT_FARBA_FIALOVA_CIERNA)? LIT_FARBA_CIERNA : LIT_FARBA_BIELA;
			liturgicka_farba = LIT_FARBA_FIALOVA;
		}
	}
	else{
		liturgicka_farba_alt = LIT_FARBA_NEURCENA;
	}

	// 2013-03-13: pre spomienku na privilegované dni (VSLH č. 238-239 -- commemoratio) sa farba neexportuje
	if((_local_den.typslav == SLAV_LUB_SPOMIENKA) && (je_privileg)){
		if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
			// farba sa neexportuje
			export_farby = NIE;
			sprintf(_global_string_farba, "<!-- %s %s -->", (char *)nazov_farby(liturgicka_farba), (liturgicka_farba_alt != LIT_FARBA_NEURCENA)? (char *)nazov_farby(liturgicka_farba_alt): STR_EMPTY);
		}
		else{
			// exportuje sa liturgická farba privilegovaných dní (VSLH, č. 238-239)
			export_farby = ANO;
			liturgicka_farba = (_local_den.litobd == OBD_OKTAVA_NARODENIA)? LIT_FARBA_BIELA: LIT_FARBA_FIALOVA;
			liturgicka_farba_alt = LIT_FARBA_NEURCENA;
		}
	}// ľubovoľná spomienka v privilegované dni

	if(export_farby){
		// 2009-08-26: pre iný export netreba tabuľku
		if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2){
			sprintf(_global_string_farba, "\n"HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE"\n<span style=\"background-color: %s; color: %s\">(%s)"HTML_SPAN_END"\n",
				(char *)html_farba_pozadie[liturgicka_farba], 
				(char *)html_farba_popredie[liturgicka_farba], 
				(char *)nazov_farby(liturgicka_farba));
			if(liturgicka_farba_alt != LIT_FARBA_NEURCENA){
				// oddeľovač
				sprintf(pom, "/");
				strcat(_global_string_farba, pom);
				// druhá farba
				sprintf(pom, "<span style=\"background-color: %s; color: %s\">(%s)"HTML_SPAN_END"\n",
					(char *)html_farba_pozadie[liturgicka_farba_alt], 
					(char *)html_farba_popredie[liturgicka_farba_alt], 
					(char *)nazov_farby(liturgicka_farba_alt));
				strcat(_global_string_farba, pom);
			}// liturgicka_farba_alt != LIT_FARBA_NEURCENA
			sprintf(pom, HTML_LINE_BREAK);
			strcat(_global_string_farba, pom);
		}// if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2)
		else{
			sprintf(_global_string_farba, "\n<table width=\"100%%\"><tr>");
			sprintf(pom, "<td "HTML_ALIGN_CENTER" bgcolor=\"%s\" style=\"border: 1px solid %s\"><font color=\"%s\" size=\""HTML_FONT_SIZE_FARBA"\">%s</font></td>\n", 
				(char *)html_farba_pozadie[liturgicka_farba], 
				(char *)html_farba_okraj[liturgicka_farba], 
				(char *)html_farba_popredie[liturgicka_farba], 
				(char *)nazov_farby(liturgicka_farba));
			strcat(_global_string_farba, pom);
			if(liturgicka_farba_alt != LIT_FARBA_NEURCENA){
				// oddeľovač
				sprintf(pom, "<td>/</td>\n");
				strcat(_global_string_farba, pom);
				// druhá farba
				sprintf(pom, "<td "HTML_ALIGN_CENTER" bgcolor=\"%s\" style=\"border: 1px solid %s\"><font color=\"%s\" size=\""HTML_FONT_SIZE_FARBA"\">%s</font></td>\n", 
					(char *)html_farba_pozadie[liturgicka_farba_alt], 
					(char *)html_farba_okraj[liturgicka_farba_alt], 
					(char *)html_farba_popredie[liturgicka_farba_alt], 
					(char *)nazov_farby(liturgicka_farba_alt));
				strcat(_global_string_farba, pom);
			}// liturgicka_farba_alt != LIT_FARBA_NEURCENA
			sprintf(pom, "</tr></table>\n");
			strcat(_global_string_farba, pom);
		}// else (_global_opt_batch_monthly == ANO && export_monthly_druh > 2)
	}// export farby
	Log("  -- _global_string_farba == %s\n", _global_string_farba);

	Log("-- init_global_string(EXPORT_DNA_%d, %d, %s, %d) -- returning SUCCESS\n", typ, poradie_svateho, nazov_modlitby(modlitba), aj_citanie);
	return SUCCESS;
}// init_global_string();

void init_global_string_modlitba(short int modlitba){
	short int _local_modlitba = _global_modlitba;
	// 2011-10-04: vytvorené; reťazec modlitby (dovtedy len "Prvé vešpery" a pod.) neprilepujeme do _global_string, ale do novej premennej _global_string_modlitba
	Log("-- init_global_string_modlitba(%d, %s) -- začiatok\n", modlitba, nazov_modlitby(modlitba));
	Log("pôvodná hodnota: %s\n", _global_string_modlitba);
	if(modlitba != _global_modlitba){
		Export("<!-- modlitba == %d, _global_modlitba == %d -->\n", modlitba, _global_modlitba);
	}
	if((_global_den.den == 2) && (_global_den.mesiac - 1 == MES_NOV) && ((_global_modlitba == MODL_DRUHE_VESPERY) || (_global_modlitba == MODL_DRUHE_KOMPLETORIUM))){
		Log("Spomienka vsetkych vernych zosnulych -- nevypisem, ze su druhe vespery (resp. kompletórium po nich)...\n");
		_global_modlitba -= 5; // MODL_DRUHE_VESPERY -> MODL_VESPERY; MODL_DRUHE_KOMPLETORIUM -> MODL_KOMPLETORIUM
	}
	mystrcpy(_global_string_modlitba, nazov_MODLITBY(_global_modlitba), SMALL);
	Log("nová hodnota: %s\n", _global_string_modlitba);
	_global_modlitba = _local_modlitba;
	Log("-- init_global_string_modlitba(%d, %s) -- koniec\n", modlitba, nazov_modlitby(modlitba));
}// init_global_string_modlitba()

void init_global_string_podnadpis(short int modlitba){
	// 2012-04-03: vytvorené
	Log("-- init_global_string_podnadpis(%d, %s) -- začiatok\n", modlitba, nazov_modlitby(modlitba));
	Log("pôvodná hodnota: %s\n", _global_string_podnadpis);
	if(modlitba != _global_modlitba){
		Export("<!-- modlitba == %d, _global_modlitba == %d -->\n", modlitba, _global_modlitba);
	}
	// pre modlitbu cez deň dáme do nadpisu informáciu o tom, že ide o doplnkovú psalmódiu
	if((je_modlitba_cez_den(modlitba))
		&& (je_len_doplnkova_psalmodia(modlitba)) // nie vtedy, keď je predpísaná iba doplnková psalmódia (na slávnosti);
		&& !((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) == BIT_OPT_2_ROZNE_MOZNOSTI) // ani vtedy nie, keď sú jednotlivé možnosti priamo v textoch modlitieb
	){
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_DOPLNKOVA) == BIT_OPT_1_MCD_DOPLNKOVA){
			mystrcpy(_global_string_podnadpis, HTML_LINE_BREAK"\n(", SMALL);
			strcat(_global_string_podnadpis, str_doplnkova_psalmodia[_global_jazyk]);
			strcat(_global_string_podnadpis, ")");
		}// doplnková psalmódia
		else{
			mystrcpy(_global_string_podnadpis, STR_EMPTY, SMALL);
		}// nie je doplnková psalmódia
	}// MCD
	Log("nová hodnota: %s\n", _global_string_podnadpis);
	Log("-- init_global_string_podnadpis(%d, %s) -- koniec\n", modlitba, nazov_modlitby(modlitba));
}// init_global_string_podnadpis()

// 2014-09-03: prvé písmeno veľké majú len názvy vlastných častí pre CZOP (pre SK chybne dávalo: "panny Márie")
#define lowered_nazov_spolc(a) ((_global_jazyk == JAZYK_CZ_OP)? mystr_first_lower(nazov_spolc(a)) : nazov_spolc(a))

short int init_global_string_spol_cast(short int sc_jedna, short int poradie_svateho){
	// 2012-08-16: vytvorené
	short int ret_sc = sc_jedna; // obsahuje nejakú hodnotu MODL_SPOL_CAST_...: buď spol. časť na vstupe alebo ak bol MODL_SPOL_CAST_NULL (-1), tak prvú zo zoznamu
	Log("-- init_global_string_spol_cast(%d, %s) -- začiatok\n", sc_jedna, nazov_spolc(sc_jedna));
	Log("pôvodná hodnota: %s\n", _global_string_spol_cast);
	if(sc_jedna == MODL_SPOL_CAST_NULL){
		mystrcpy(_global_string_spol_cast, STR_EMPTY, SMALL);

		// najprv si rozkódujeme, čo je v "_global_den".spolcast podľa poradie_svateho
		_struct_sc sc = _decode_spol_cast(MODL_SPOL_CAST_NEURCENA);
		switch(poradie_svateho){
			case 0: sc = _decode_spol_cast(_global_den.spolcast);
				break;
			case PORADIE_PM_SOBOTA: sc = _decode_spol_cast(_global_pm_sobota.spolcast);
				break;
			default:
				sc = _decode_spol_cast(_global_svaty(poradie_svateho).spolcast);
				break;
		}

		if((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT)){
			ret_sc = sc.a1;
			strcat(_global_string_spol_cast, lowered_nazov_spolc(sc.a1));
			if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
				strcat(_global_string_spol_cast, ", ");
				strcat(_global_string_spol_cast, nazov_spolc_alebo_jazyk[_global_jazyk]);
				strcat(_global_string_spol_cast, " ");
				strcat(_global_string_spol_cast, lowered_nazov_spolc(sc.a2));
				if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
					strcat(_global_string_spol_cast, ", ");
					strcat(_global_string_spol_cast, nazov_spolc_alebo_jazyk[_global_jazyk]);
					strcat(_global_string_spol_cast, " ");
					strcat(_global_string_spol_cast, lowered_nazov_spolc(sc.a3));
				}
			}
		}
	}
	else if((sc_jedna != MODL_SPOL_CAST_NEURCENA) && (sc_jedna != MODL_SPOL_CAST_NEBRAT)){
		sprintf(_global_string_spol_cast, "%s", lowered_nazov_spolc(sc_jedna));
	}
	else{
		mystrcpy(_global_string_spol_cast, STR_EMPTY, SMALL);
	}
	Log("nová hodnota: %s\n", _global_string_spol_cast);
	Log("-- init_global_string_spol_cast(%d, %s) -- koniec\n", sc_jedna, nazov_spolc(sc_jedna));
	return ret_sc;
}// init_global_string_spol_cast()

void xml_export_spol_cast(short int poradie_svateho){
	// 2012-10-12: vytvorené podľa init_global_string_spol_cast()
	Log("-- xml_export_spol_cast(%d) -- začiatok\n", poradie_svateho);
	// rozkódujeme si, čo je v "_global_den".spolcast podľa poradie_svateho
	_struct_sc sc = _decode_spol_cast(MODL_SPOL_CAST_NEURCENA);
	// dalo by sa možno použiť aj globálna premenná _local_den; takto je to istejšie
	switch(poradie_svateho){
		case 0: 
			sc = _decode_spol_cast(_global_den.spolcast);
			break;
		case PORADIE_PM_SOBOTA: 
			sc = _decode_spol_cast(_global_pm_sobota.spolcast);
			break;
		default:
			sc = _decode_spol_cast(_global_svaty(poradie_svateho).spolcast);
			break;
	}

	if((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT)){
		Export(ELEMID_BEGIN(XML_LIT_COMMUNIA)"%s"ELEM_END(XML_LIT_COMMUNIA)"\n", sc.a1, nazov_spolc(sc.a1));
		if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
			Export(ELEMID_BEGIN(XML_LIT_COMMUNIA)"%s"ELEM_END(XML_LIT_COMMUNIA)"\n", sc.a2, nazov_spolc(sc.a2));
			if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
				Export(ELEMID_BEGIN(XML_LIT_COMMUNIA)"%s"ELEM_END(XML_LIT_COMMUNIA)"\n", sc.a3, nazov_spolc(sc.a3));
			}
		}
	}

	Log("-- xml_export_spol_cast() -- koniec\n");
}// xml_export_spol_cast()

void xml_export_options(void){
	// 2012-10-17: vytvorené
	short int i, j;
	Log("-- xml_export_options() -- začiatok\n");

	Export(ELEM_BEGIN(XML_OPTIONS)"\n");

	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		switch(i){
			case OPT_0_SPECIALNE:
				Export(ELEMVAL_BEGIN(XML_OPT_0_SPECIALNE)"\n", _global_opt[OPT_0_SPECIALNE], STR_MODL_OPT_0, STR_MODL_OPTF_0, html_text_option1_kalendar[_global_jazyk]);
				Log("option %d, jednotlivé bit-komponenty...(xml_export_options)\n", OPT_0_SPECIALNE);
				for(j = 0; j < POCET_OPT_0_SPECIALNE; j++){
					switch(j){
						case 0: // BIT_OPT_0_VERSE
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_VERSE)"%d"ELEM_END(XML_BIT_OPT_0_VERSE)"\n", BIT_OPT_0_VERSE, STR_MODL_OPTF_0_VERSE, html_text_option0_verse[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_VERSE) == BIT_OPT_0_VERSE));
							break;
						case 1: // BIT_OPT_0_REFERENCIE
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_REFERENCIE)"%d"ELEM_END(XML_BIT_OPT_0_REFERENCIE)"\n", BIT_OPT_0_REFERENCIE, STR_MODL_OPTF_0_REF, html_text_option0_referencie[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE));
							break;
						case 2: // BIT_OPT_0_CITANIA
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_CITANIA)"%d"ELEM_END(XML_BIT_OPT_0_CITANIA)"\n", BIT_OPT_0_CITANIA, STR_MODL_OPTF_0_CIT, html_text_option0_citania[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_CITANIA) == BIT_OPT_0_CITANIA));
							break;
						case 3: // BIT_OPT_0_ZJAVENIE_PANA_NEDELA
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_ZJAVENIE_PANA_NEDELA)"%d"ELEM_END(XML_BIT_OPT_0_ZJAVENIE_PANA_NEDELA)"\n", BIT_OPT_0_ZJAVENIE_PANA_NEDELA, STR_MODL_OPTF_0_ZJAV_NED, html_text_option0_zjv_ne[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_ZJAVENIE_PANA_NEDELA) == BIT_OPT_0_ZJAVENIE_PANA_NEDELA));
							break;
						case 4: // BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA)"%d"ELEM_END(XML_BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA)"\n", BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA, STR_MODL_OPTF_0_NAN_NED, html_text_option0_nan_ne[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA) == BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA));
							break;
						case 5: // BIT_OPT_0_TELAKRVI_NEDELA
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_TELAKRVI_NEDELA)"%d"ELEM_END(XML_BIT_OPT_0_TELAKRVI_NEDELA)"\n", BIT_OPT_0_TELAKRVI_NEDELA, STR_MODL_OPTF_0_TK_NED, html_text_option0_tk_ne[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_TELAKRVI_NEDELA) == BIT_OPT_0_TELAKRVI_NEDELA));
							break;
						case 6: // BIT_OPT_0_FONT_NORMAL
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_FONT_NORMAL)"%d"ELEM_END(XML_BIT_OPT_0_FONT_NORMAL)"\n", BIT_OPT_0_FONT_NORMAL, STR_MODL_OPTF_0_FONT_NORMAL, html_text_option0_font_normal[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_FONT_NORMAL) == BIT_OPT_0_FONT_NORMAL));
							break;
						case 7: // BIT_OPT_0_BUTTONS_ORDER
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_BUTTONS_ORDER)"%d"ELEM_END(XML_BIT_OPT_0_BUTTONS_ORDER)"\n", BIT_OPT_0_BUTTONS_ORDER, STR_MODL_OPTF_0_BUTTONS_ORDER, html_text_option0_buttons_order[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BUTTONS_ORDER) == BIT_OPT_0_BUTTONS_ORDER));
							break;
						case 8: // BIT_OPT_0_BLIND_FRIENDLY
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_0_BLIND_FRIENDLY)"%d"ELEM_END(XML_BIT_OPT_0_BLIND_FRIENDLY)"\n", BIT_OPT_0_BLIND_FRIENDLY, STR_MODL_OPTF_0_BLIND_FRIENDLY, html_text_option0_blind_friendly[_global_jazyk], ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BLIND_FRIENDLY) == BIT_OPT_0_BLIND_FRIENDLY));
							break;
					}// switch(j)
				}// for j
				Export(ELEM_END(XML_OPT_0_SPECIALNE)"\n");
				break;
			case OPT_1_CASTI_MODLITBY:
				Export(ELEMVAL_BEGIN(XML_OPT_1_CASTI_MODLITBY)"\n", _global_opt[OPT_1_CASTI_MODLITBY], STR_MODL_OPT_1, STR_MODL_OPTF_1, html_text_option1_dalsie_prepinace[_global_jazyk]);
				Log("option %d, jednotlivé bit-komponenty...(xml_export_options)\n", OPT_1_CASTI_MODLITBY);
				for(j = 0; j < POCET_OPT_1_CASTI_MODLITBY; j++){
					switch(j){
						case 0: // BIT_OPT_1_TEDEUM
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_TEDEUM)"%d"ELEM_END(XML_BIT_OPT_1_TEDEUM)"\n", BIT_OPT_1_TEDEUM, STR_MODL_OPTF_1_TD, html_text_option1_tedeum[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_TEDEUM) == BIT_OPT_1_TEDEUM));
							break;
						case 1: // BIT_OPT_1_RUBRIKY
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_RUBRIKY)"%d"ELEM_END(XML_BIT_OPT_1_RUBRIKY)"\n", BIT_OPT_1_RUBRIKY, STR_MODL_OPTF_1_RUB, html_text_option1_rubriky[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) == BIT_OPT_1_RUBRIKY));
							break;
						case 2: // BIT_OPT_1_CHVALOSPEVY
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_CHVALOSPEVY)"%d"ELEM_END(XML_BIT_OPT_1_CHVALOSPEVY)"\n", BIT_OPT_1_CHVALOSPEVY, STR_MODL_OPTF_1_CHV, html_text_option1_chvalospevy[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_CHVALOSPEVY) == BIT_OPT_1_CHVALOSPEVY));
							break;
						case 3: // BIT_OPT_1_SLAVA_OTCU
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_SLAVA_OTCU)"%d"ELEM_END(XML_BIT_OPT_1_SLAVA_OTCU)"\n", BIT_OPT_1_SLAVA_OTCU, STR_MODL_OPTF_1_SL, html_text_option1_slava_otcu[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SLAVA_OTCU) == BIT_OPT_1_SLAVA_OTCU));
							break;
						case 4: // BIT_OPT_1_OTCENAS
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_OTCENAS)"%d"ELEM_END(XML_BIT_OPT_1_OTCENAS)"\n", BIT_OPT_1_OTCENAS, STR_MODL_OPTF_1_OT, html_text_option1_otcenas[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_OTCENAS) == BIT_OPT_1_OTCENAS));
							break;
						case 5: // BIT_OPT_1_MCD_DOPLNKOVA
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_MCD_DOPLNKOVA)"%d"ELEM_END(XML_BIT_OPT_1_MCD_DOPLNKOVA)"\n", BIT_OPT_1_MCD_DOPLNKOVA, STR_MODL_OPTF_1_MCD_DOPLNKOVA, html_text_option1_mcd_zalmy_ine[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_DOPLNKOVA) == BIT_OPT_1_MCD_DOPLNKOVA));
							break;
						case 6: // BIT_OPT_1_PC_VIGILIA
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_PC_VIGILIA)"%d"ELEM_END(XML_BIT_OPT_1_PC_VIGILIA)"\n", BIT_OPT_1_PC_VIGILIA, STR_MODL_OPTF_1_VIGILIA, html_text_option1_vigilia[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PC_VIGILIA) == BIT_OPT_1_PC_VIGILIA));
							break;
						case 7: // BIT_OPT_1_SPOMIENKA_SPOL_CAST
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_SPOMIENKA_SPOL_CAST)"%d"ELEM_END(XML_BIT_OPT_1_SPOMIENKA_SPOL_CAST)"\n", BIT_OPT_1_SPOMIENKA_SPOL_CAST, STR_MODL_OPTF_1_SPOMIENKA_SPOL_CAST, html_text_option1_spomienka_spolcast[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SPOMIENKA_SPOL_CAST) == BIT_OPT_1_SPOMIENKA_SPOL_CAST));
							break;
						case 8: // BIT_OPT_1_PLNE_RESP
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_PLNE_RESP)"%d"ELEM_END(XML_BIT_OPT_1_PLNE_RESP)"\n", BIT_OPT_1_PLNE_RESP, STR_MODL_OPTF_1_PLNE_RESP, html_text_option1_plne_resp[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PLNE_RESP) == BIT_OPT_1_PLNE_RESP));
							break;
						case 9: // BIT_OPT_1_ZALM95
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_ZALM95)"%d"ELEM_END(XML_BIT_OPT_1_ZALM95)"\n", BIT_OPT_1_ZALM95, STR_MODL_OPTF_1_ZALM95, html_text_option1_zalm95[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZALM95) == BIT_OPT_1_ZALM95));
							break;
						case 10: // BIT_OPT_1_PROSBY_ZVOLANIE
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_PROSBY_ZVOLANIE)"%d"ELEM_END(XML_BIT_OPT_1_PROSBY_ZVOLANIE)"\n", BIT_OPT_1_PROSBY_ZVOLANIE, STR_MODL_OPTF_1_PROSBY_ZVOLANIE, html_text_option1_prosby_zvolanie[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PROSBY_ZVOLANIE) == BIT_OPT_1_PROSBY_ZVOLANIE));
							break;
						case 11: // BIT_OPT_1_SKRY_POPIS
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_SKRY_POPIS)"%d"ELEM_END(XML_BIT_OPT_1_SKRY_POPIS)"\n", BIT_OPT_1_SKRY_POPIS, STR_MODL_OPTF_1_SKRY_POPIS, html_text_option1_skryt_popis_svaty[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SKRY_POPIS) == BIT_OPT_1_SKRY_POPIS));
							break;
						case 12: // BIT_OPT_1_ZOBRAZ_SPOL_CAST
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_ZOBRAZ_SPOL_CAST)"%d"ELEM_END(XML_BIT_OPT_1_ZOBRAZ_SPOL_CAST)"\n", BIT_OPT_1_ZOBRAZ_SPOL_CAST, STR_MODL_OPTF_1_ZOBRAZ_SPOL_CAST, html_text_option1_spolc_svaty[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST) == BIT_OPT_1_ZOBRAZ_SPOL_CAST));
							break;
						case 13: // BIT_OPT_1_VESP_KRATSIE_PROSBY
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_VESP_KRATSIE_PROSBY)"%d"ELEM_END(XML_BIT_OPT_1_VESP_KRATSIE_PROSBY)"\n", BIT_OPT_1_VESP_KRATSIE_PROSBY, STR_MODL_OPTF_1_VESP_KRATSIE_PROSBY, html_text_option1_vesp_kratsie_prosby[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_VESP_KRATSIE_PROSBY) == BIT_OPT_1_VESP_KRATSIE_PROSBY));
							break;
						case 14: // BIT_OPT_1_MCD_ZALTAR_TRI
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_1_MCD_ZALTAR_TRI)"%d"ELEM_END(XML_BIT_OPT_1_MCD_ZALTAR_TRI)"\n", BIT_OPT_1_MCD_ZALTAR_TRI, STR_MODL_OPTF_1_MCD_ZALTAR_TRI, html_text_option1_mcd_zalmy_tri[_global_jazyk], ((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_ZALTAR_TRI) == BIT_OPT_1_MCD_ZALTAR_TRI));
							break;
					}// switch(j)
				}// for j
				Export(ELEM_END(XML_OPT_1_CASTI_MODLITBY)"\n");
				break;
			case OPT_2_HTML_EXPORT:
				Export(ELEMVAL_BEGIN(XML_OPT_2_HTML_EXPORT)"\n", _global_opt[OPT_2_HTML_EXPORT], STR_MODL_OPT_2, STR_MODL_OPTF_2, html_text_option2_html_export[_global_jazyk]);
				Log("option %d, jednotlivé bit-komponenty...(xml_export_options)\n", OPT_2_HTML_EXPORT);
				for(j = 0; j < POCET_OPT_2_HTML_EXPORT; j++){
					switch(j){
						case 0: // BIT_OPT_2_ISO_DATUM
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_ISO_DATUM)"%d"ELEM_END(XML_BIT_OPT_2_ISO_DATUM)"\n", BIT_OPT_2_ISO_DATUM, STR_MODL_OPTF_2_ISO_DATUM, html_text_option2_iso_datum[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ISO_DATUM) == BIT_OPT_2_ISO_DATUM));
							break;
						case 1: // BIT_OPT_2_BUTTON_PRVE_VESPERY
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_BUTTON_PRVE_VESPERY)"%d"ELEM_END(XML_BIT_OPT_2_BUTTON_PRVE_VESPERY)"\n", BIT_OPT_2_BUTTON_PRVE_VESPERY, STR_MODL_OPTF_2_PRVE_VESPERY, html_text_option2_prve_vespery[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY));
							break;
						case 2: // BIT_OPT_2_FONT_FAMILY
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_FONT_FAMILY)"%d"ELEM_END(XML_BIT_OPT_2_FONT_FAMILY)"\n", BIT_OPT_2_FONT_FAMILY, STR_MODL_OPTF_2_FONT_FAMILY, html_text_option2_font_family[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_FAMILY) == BIT_OPT_2_FONT_FAMILY));
							break;
						case 3: // BIT_OPT_2_FONT_NAME_CHOOSER
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_FONT_NAME_CHOOSER)"%d"ELEM_END(XML_BIT_OPT_2_FONT_NAME_CHOOSER)"\n", BIT_OPT_2_FONT_NAME_CHOOSER, STR_MODL_OPTF_2_FONT_NAME_CHOOSER, html_text_font_name[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_NAME_CHOOSER) == BIT_OPT_2_FONT_NAME_CHOOSER)); // ToDo Text
							break;
						case 4: // BIT_OPT_2_FONT_SIZE_CHOOSER
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_FONT_SIZE_CHOOSER)"%d"ELEM_END(XML_BIT_OPT_2_FONT_SIZE_CHOOSER)"\n", BIT_OPT_2_FONT_SIZE_CHOOSER, STR_MODL_OPTF_2_FONT_SIZE, html_text_font_size[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_SIZE_CHOOSER) == BIT_OPT_2_FONT_SIZE_CHOOSER)); // ToDo Text
							break;
						case 5: // BIT_OPT_2_NAVIGATION
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_NAVIGATION)"%d"ELEM_END(XML_BIT_OPT_2_NAVIGATION)"\n", BIT_OPT_2_NAVIGATION, STR_MODL_OPTF_2_NAVIGATION, html_text_option2_navigation[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_NAVIGATION) == BIT_OPT_2_NAVIGATION));
							break;
						case 6: // BIT_OPT_2_TEXT_WRAP
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_TEXT_WRAP)"%d"ELEM_END(XML_BIT_OPT_2_TEXT_WRAP)"\n", BIT_OPT_2_TEXT_WRAP, STR_MODL_OPTF_2_TEXT_WRAP, html_text_option2_textwrap[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_TEXT_WRAP) == BIT_OPT_2_TEXT_WRAP));
							break;
						case 7: // BIT_OPT_2_BUTTONY_USPORNE
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_BUTTONY_USPORNE)"%d"ELEM_END(XML_BIT_OPT_2_BUTTONY_USPORNE)"\n", BIT_OPT_2_BUTTONY_USPORNE, STR_MODL_OPTF_2_BUTTONY_USPORNE, html_text_option2_buttons_usporne[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE));
							break;
						case 8: // BIT_OPT_2_NOCNY_REZIM
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_NOCNY_REZIM)"%d"ELEM_END(XML_BIT_OPT_2_NOCNY_REZIM)"\n", BIT_OPT_2_NOCNY_REZIM, STR_MODL_OPTF_2_NOCNY_REZIM, html_text_option2_nocny_rezim[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_NOCNY_REZIM) == BIT_OPT_2_NOCNY_REZIM));
							break;
						case 9: // BIT_OPT_2_ROZNE_MOZNOSTI
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_ROZNE_MOZNOSTI)"%d"ELEM_END(XML_BIT_OPT_2_ROZNE_MOZNOSTI)"\n", BIT_OPT_2_ROZNE_MOZNOSTI, STR_MODL_OPTF_2_ROZNE_MOZNOSTI, html_text_option2_moznosti[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) == BIT_OPT_2_ROZNE_MOZNOSTI));
							break;
						case 10: // BIT_OPT_2_HIDE_NAVIG_BUTTONS
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_HIDE_NAVIG_BUTTONS)"%d"ELEM_END(XML_BIT_OPT_2_HIDE_NAVIG_BUTTONS)"\n", BIT_OPT_2_HIDE_NAVIG_BUTTONS, STR_MODL_OPTF_2_HIDE_NAVIG_BUTTONS, STR_EMPTY, ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_NAVIG_BUTTONS) == BIT_OPT_2_HIDE_NAVIG_BUTTONS)); // ToDo Text
							break;
						case 11: // BIT_OPT_2_HIDE_KALENDAR
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_HIDE_KALENDAR)"%d"ELEM_END(XML_BIT_OPT_2_HIDE_KALENDAR)"\n", BIT_OPT_2_HIDE_KALENDAR, STR_MODL_OPTF_2_HIDE_KALENDAR, STR_EMPTY, ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_KALENDAR) == BIT_OPT_2_HIDE_KALENDAR)); // ToDo Text
							break;
						case 12: // BIT_OPT_2_HIDE_OPTIONS1
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_HIDE_OPTIONS1)"%d"ELEM_END(XML_BIT_OPT_2_HIDE_OPTIONS1)"\n", BIT_OPT_2_HIDE_OPTIONS1, STR_MODL_OPTF_2_HIDE_OPTIONS1, STR_EMPTY, ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_OPTIONS1) == BIT_OPT_2_HIDE_OPTIONS1)); // ToDo Text
							break;
						case 13: // BIT_OPT_2_HIDE_OPTIONS2
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_HIDE_OPTIONS2)"%d"ELEM_END(XML_BIT_OPT_2_HIDE_OPTIONS2)"\n", BIT_OPT_2_HIDE_OPTIONS2, STR_MODL_OPTF_2_HIDE_OPTIONS2, STR_EMPTY, ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_OPTIONS2) == BIT_OPT_2_HIDE_OPTIONS2)); // ToDo Text
							break;
						case 14: // BIT_OPT_2_ALTERNATIVES
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_2_ALTERNATIVES)"%d"ELEM_END(XML_BIT_OPT_2_ALTERNATIVES)"\n", BIT_OPT_2_ALTERNATIVES, STR_MODL_OPTF_2_ALTERNATIVES, html_text_option2_alternatives[_global_jazyk], ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ALTERNATIVES) == BIT_OPT_2_ALTERNATIVES));
							break;
					}// switch(j)
				}// for j
				Export(ELEM_END(XML_OPT_2_HTML_EXPORT)"\n");
				break;
			case OPT_3_SPOLOCNA_CAST:
				Export(ELEMVAL_BEGIN(XML_OPT_3_SPOLOCNA_CAST), _global_opt[OPT_3_SPOLOCNA_CAST], STR_MODL_OPT_3, STR_MODL_OPTF_3, html_text_spol_casti_vziat_zo[_global_jazyk]);
				Log("option %d...\n", OPT_3_SPOLOCNA_CAST);
				Export("%s", _global_opt[OPT_3_SPOLOCNA_CAST] <= MODL_SPOL_CAST_NEBRAT ? nazov_spolc(_global_opt[OPT_3_SPOLOCNA_CAST]) : STR_EMPTY);
				Export(ELEM_END(XML_OPT_3_SPOLOCNA_CAST)"\n");
				break;
			case OPT_4_OFFLINE_EXPORT:
				break;
			case OPT_5_ALTERNATIVES:
				Export(ELEMVAL_BEGIN(XML_OPT_5_ALTERNATIVES)"\n", _global_opt[OPT_5_ALTERNATIVES], STR_MODL_OPT_5, STR_MODL_OPTF_5, html_text_option2_alternatives[_global_jazyk]);
				Log("option %d, jednotlivé bit-komponenty...(xml_export_options)\n", OPT_5_ALTERNATIVES);
				for(j = 0; j < POCET_OPT_5_ALTERNATIVES; j++){
					switch(j){
						case 0: // BIT_OPT_5_HYMNUS_KOMPL
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_KOMPL)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_KOMPL)"\n", BIT_OPT_5_HYMNUS_KOMPL, STR_MODL_OPTF_5_HYMNUS_KOMPL, html_text_option5_KomplHymnusA[_global_jazyk], html_text_option5_KomplHymnusB[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_KOMPL) == BIT_OPT_5_HYMNUS_KOMPL));
							break;
						case 1: // BIT_OPT_5_HYMNUS_PC
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_PC)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_PC)"\n", BIT_OPT_5_HYMNUS_PC, STR_MODL_OPTF_5_HYMNUS_PC, html_text_option5_PCHymnusI[_global_jazyk], html_text_option5_PCHymnusII[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_PC) == BIT_OPT_5_HYMNUS_PC));
							break;
						case 2: // BIT_OPT_5_HYMNUS_MCD_PREDPOL
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_MCD_PREDPOL)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_MCD_PREDPOL)"\n", BIT_OPT_5_HYMNUS_MCD_PREDPOL, STR_MODL_OPTF_5_HYMNUS_MCD_PREDPOL, html_text_option5_MCDPredHymnus1[_global_jazyk], html_text_option5_MCDPredHymnus2[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_MCD_PREDPOL) == BIT_OPT_5_HYMNUS_MCD_PREDPOL));
							break;
						case 3: // BIT_OPT_5_HYMNUS_MCD_PREDPOL
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_MCD_NAPOL)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_MCD_NAPOL)"\n", BIT_OPT_5_HYMNUS_MCD_NAPOL, STR_MODL_OPTF_5_HYMNUS_MCD_NAPOL, html_text_option5_MCDNaHymnus1[_global_jazyk], html_text_option5_MCDNaHymnus2[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_MCD_NAPOL) == BIT_OPT_5_HYMNUS_MCD_NAPOL));
							break;
						case 4: // BIT_OPT_5_HYMNUS_MCD_POPOL
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_MCD_POPOL)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_MCD_POPOL)"\n", BIT_OPT_5_HYMNUS_MCD_POPOL, STR_MODL_OPTF_5_HYMNUS_MCD_POPOL, html_text_option5_MCDPoHymnus1[_global_jazyk], html_text_option5_MCDPoHymnus2[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_MCD_POPOL) == BIT_OPT_5_HYMNUS_MCD_POPOL));
							break;
						case 5: // BIT_OPT_5_DOPLNK_PSALM_122_129
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_5_DOPLNK_PSALM_122_129)"%d"ELEM_END(XML_BIT_OPT_5_DOPLNK_PSALM_122_129)"\n", BIT_OPT_5_DOPLNK_PSALM_122_129, STR_MODL_OPTF_5_DOPLNK_PSALM_122_129, html_text_option5_DPsalmZ122_129[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_122_129) == BIT_OPT_5_DOPLNK_PSALM_122_129));
							break;
						case 6: // BIT_OPT_5_DOPLNK_PSALM_127_131
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_5_DOPLNK_PSALM_127_131)"%d"ELEM_END(XML_BIT_OPT_5_DOPLNK_PSALM_127_131)"\n", BIT_OPT_5_DOPLNK_PSALM_127_131, STR_MODL_OPTF_5_DOPLNK_PSALM_127_131, html_text_option5_DPsalmZ127_131[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_127_131) == BIT_OPT_5_DOPLNK_PSALM_127_131));
							break;
						case 7: // BIT_OPT_5_DOPLNK_PSALM_126_129
							Export(ELEMOPT_BEGIN(XML_BIT_OPT_5_DOPLNK_PSALM_126_129)"%d"ELEM_END(XML_BIT_OPT_5_DOPLNK_PSALM_126_129)"\n", BIT_OPT_5_DOPLNK_PSALM_126_129, STR_MODL_OPTF_5_DOPLNK_PSALM_126_129, html_text_option5_DPsalmZ126_129[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_126_129) == BIT_OPT_5_DOPLNK_PSALM_126_129));
							break;
						case 8: // BIT_OPT_5_HYMNUS_VN_PC
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_VN_PC)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_VN_PC)"\n", BIT_OPT_5_HYMNUS_VN_PC, STR_MODL_OPTF_5_HYMNUS_VN_PC, html_text_option5_PCHymnusVNnedela[_global_jazyk], html_text_option5_PCHymnusVNferia[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_VN_PC) == BIT_OPT_5_HYMNUS_VN_PC));
							break;
						case 9: // BIT_OPT_5_HYMNUS_VN_RCH
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_VN_RCH)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_VN_RCH)"\n", BIT_OPT_5_HYMNUS_VN_RCH, STR_MODL_OPTF_5_HYMNUS_VN_RCH, html_text_option5_RChHymnusVNnedela[_global_jazyk], html_text_option5_RChHymnusVNferia[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_VN_RCH) == BIT_OPT_5_HYMNUS_VN_RCH));
							break;
						case 10: // BIT_OPT_5_HYMNUS_VN_VESP
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_VN_VESP)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_VN_VESP)"\n", BIT_OPT_5_HYMNUS_VN_VESP, STR_MODL_OPTF_5_HYMNUS_VN_VESP, html_text_option5_VespHymnusVNnedela[_global_jazyk], html_text_option5_VespHymnusVNferia[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_VN_VESP) == BIT_OPT_5_HYMNUS_VN_VESP));
							break;
						case 11: // BIT_OPT_5_HYMNUS_1VESP
							Export(ELEMOPT_SLASH_BEGIN(XML_BIT_OPT_5_HYMNUS_1VESP)"%d"ELEM_END(XML_BIT_OPT_5_HYMNUS_1VESP)"\n", BIT_OPT_5_HYMNUS_1VESP, STR_MODL_OPTF_5_HYMNUS_1VESP, html_text_option5_1VHymnusNe[_global_jazyk], html_text_option5_1VHymnusPC[_global_jazyk], ((_global_opt[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_1VESP) == BIT_OPT_5_HYMNUS_1VESP));
							break;
					}// switch(j)
				}// for j
				Export(ELEM_END(XML_OPT_5_ALTERNATIVES)"\n");
				break;
		}// switch(i)
	}// for i

	Export(ELEM_END(XML_OPTIONS)"\n\n");

	Log("-- xml_export_options() -- koniec\n");
}// xml_export_options()

//---------------------------------------------------------------------
// _rozbor_dna_s_modlitbou()
// predpokoladam, ze pred jeho volanim bolo pouzite analyzuj_rok(rok); ktore da vysledok do _global_r
// ak poradie_svateho == 5, znamena to, ze analyzujem nasledujuci den.
// dostane {den, mesiac} a rok
// 28/03/2000A.D.: prirobena navratova hodnota SUCCESS/FAILURE
short int _rozbor_dna_s_modlitbou(_struct_den_mesiac datum, short int rok, short int modlitba, short int poradie_svateho){
	short int ret;
	Log("-- _rozbor_dna_s_modlitbou(_struct_den_mesiac, int, int, int): begin ({%d, %d}, %d, %s, %d)\n", datum.den, datum.mesiac, rok, nazov_modlitby(modlitba), poradie_svateho);

	Log("vo funkcii _rozbor_dna_s_modlitbou() spustam set_popis_dummy();\n");
	set_popis_dummy();
	Log("set_popis_dummy() skoncila.\n");

	Log("vo funkcii _rozbor_dna_s_modlitbou() spustam _rozbor_dna();\n");
	ret = _rozbor_dna(datum, rok, poradie_svateho);
	if(ret == FAILURE){
		Log("_rozbor_dna() returned FAILURE, so returning FAILURE...\n");
		return FAILURE;
	}
	Log("_rozbor_dna() skoncila.\n");

	// nasledovna pasaz pridana 28/03/2000A.D. -- aby sme dobre kontrolovali, ci vobec mozeme spustit generovanie modlitby
	if((poradie_svateho == PORADIE_PM_SOBOTA) && (_global_den.denvt != DEN_SOBOTA)){
		Log("(poradie_svateho == %d) && (_global_den.denvt != DEN_SOBOTA), so returning FAILURE...\n", PORADIE_PM_SOBOTA);
		ALERT;
		Export("Nemôžete požadovať túto modlitbu, pretože nie je sobota.\n");
		return FAILURE;
	}
	// toto sa vypisovalo aj pre "detaily" (tlacidlo na webe), ked je MODL_NEURCENA, preto som `modlitba >= MODL_VESPERY' upravil na `(modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)'
	// aby kontroloval len vespery a kompletorium. | 2003-07-01
	else if((poradie_svateho == PORADIE_PM_SOBOTA) && (_global_den.denvt == DEN_SOBOTA) && ((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM))){
		Log("(poradie_svateho == %d) && (_global_den.denvt != DEN_SOBOTA), so returning FAILURE...\n", PORADIE_PM_SOBOTA);
		ALERT;
		Export("Nemôžete požadovať túto modlitbu, pretože `Spomienka Panny Márie v sobotu' nemá vešpery ani kompletórium.\n");
		return FAILURE;
	}
	else if((poradie_svateho != PORADIE_PM_SOBOTA) && (_global_pocet_svatych < poradie_svateho)){
		Log("(poradie_svateho != %d) && (_global_pocet_svatych < poradie_svateho), so returning FAILURE...\n", PORADIE_PM_SOBOTA);
		ALERT;
		Export("Nemôžete požadovať túto modlitbu, pretože na daný deň je menej svätých.\n");
		return FAILURE;
	}

	// teraz nasleduje niečo, čo nahrádza export -- avšak dáta ukladá do stringu _global_string
	Log("1:spustam init_global_string(EXPORT_DNA_JEDEN_DEN, svaty == %d, modlitba == %s)...\n", poradie_svateho, nazov_modlitby(modlitba));
	ret = init_global_string(EXPORT_DNA_JEDEN_DEN, poradie_svateho, modlitba, /* aj_citanie */ NIE);

	if(ret == FAILURE){
		Log("init_global_string() returned FAILURE, so returning FAILURE...\n");
		return FAILURE;
	}

	// 2012-11-20: doplnené podľa vzoru v rozbor_dna_s_modlitbou()
	Log("nastavujem _global_string_modlitba... _rozbor_dna_s_modlitbou()\n");
	init_global_string_modlitba(_global_modlitba);
	Log("nastavujem _global_string_podnadpis... _rozbor_dna_s_modlitbou()\n");
	init_global_string_podnadpis(_global_modlitba);
	Log("nastavujem _global_string_spol_cast... _rozbor_dna_s_modlitbou()\n");
	ret_sc = init_global_string_spol_cast(((_global_modlitba == MODL_DETAILY) || (_global_modlitba == MODL_NEURCENA))? MODL_SPOL_CAST_NULL: _global_opt[OPT_3_SPOLOCNA_CAST], poradie_svateho);

	// určenie dát k modlitbe
	Log("spustam liturgicke_obdobie(%s, %d. tyzden, %s, %d. tyzden zaltara; svaty: %d)...\n", nazov_obdobia_ext(_global_den.litobd),// nazov_obdobia_
		_global_den.tyzden, nazov_dna(_global_den.denvt), _global_den.tyzzal, poradie_svateho);
	
	Log("PRED:\t%d. %s %d\n", _global_den.den, nazov_mesiaca(_global_den.mesiac - 1), _global_den.rok);

	liturgicke_obdobie(_global_den.litobd, _global_den.tyzden, _global_den.denvt, _global_den.tyzzal, poradie_svateho);

	Log("PO:\t%d. %s %d\n", _global_den.den, nazov_mesiaca(_global_den.mesiac - 1), _global_den.rok);

	Log("-- _rozbor_dna_s_modlitbou:\n");
	Log("\t%d. %s %d, %s\n", _global_den.den, nazov_mesiaca(_global_den.mesiac - 1), _global_den.rok, _global_string);

	Log("prípadné upravenie _global_opt[OPT_3_SPOLOCNA_CAST] sa realizovalo vo funkcii _rozbor_dna()...\n"); // 2012-08-27

	Log("-- _rozbor_dna_s_modlitbou(_struct_den_mesiac, int, int, int): returning SUCCESS\n");
	return SUCCESS;
}// _rozbor_dna_s_modlitbou()

void Export_HtmlFormGET(char* action){
	char action_changed[MAX_STR];
	// 1. replace HTML_AMPERSAND "&amp;" to simple "&" char
	mystrcpy(action_changed, mystr_replace(action, HTML_AMPERSAND, "&"), MAX_STR);
	// 2. export
	Export(HTML_FORM_METHOD_GET, action_changed);
}// Export_HtmlFormGET()

void Export_HtmlFormPOST(char* action){
	// 1. not necessary to replace HTML_AMPERSAND "&amp;" to simple "&" char
	// 2. export
	Export(HTML_FORM_METHOD_POST, action);
}// Export_HtmlFormPOST()

#ifdef BEHAVIOUR_CMDLINE
#define Export_HtmlForm Export_HtmlFormGET
#else
#define Export_HtmlForm Export_HtmlFormPOST
#endif

// #define prilep_request_options(pom2, pom3) v breviar.h

void _export_rozbor_dna_button_modlitba(short int typ, short int poradie_svateho, short int modl, char pom[MAX_STR], short int doplnkova_psalmodia, short int som_v_tabulke, short int modl_visible = MODL_NEURCENA){
	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);
	short int orig_doplnkova_psalmodia = doplnkova_psalmodia;
	if(orig_doplnkova_psalmodia == MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA){
		doplnkova_psalmodia = MODL_CEZ_DEN_ZALMY_ZO_DNA;
	}
	char export_fname_modl_str[SMALL] = STR_EMPTY; // reťazec pre identifikáciu modlitby v názve súboru (ID modlitby alebo char_modlitby[i])
	// 2013-07-29: generovanie názvu súboru s písmenkom modlitby (default) alebo s ID modlitby
	if((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_FNAME_MODL_ID) != BIT_OPT_4_FNAME_MODL_ID){
		sprintf(export_fname_modl_str, "%c", char_modlitby[modl]);
	}
	else{
		sprintf(export_fname_modl_str, "%d", modl);
	}

	// ak nie je nastavená modlitba pre zobrazenie (napr. druhé vešpery), použije sa vstup modl (default správanie)
	if(modl_visible == MODL_NEURCENA){
		modl_visible = modl;
		Log("modl_visible zmenená (default na modl == %s)...\n", nazov_modlitby(modl));
	}
	else{
		Log("modl_visible == %s...\n", nazov_modlitby(modl_visible));
	}

	if(query_type == PRM_LIT_OBD){
		Log("pre query_type == PRM_LIT_OBD sa buttony pre modlitby tlačia ináč (nemám nastavený dátum)...\n");
		// predpokladáme, že máme _global_linky == ANO
		sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%c"HTML_AMPERSAND"%s=%s%s",
		// Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%c"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_LIT_OBD,
			STR_DEN_V_TYZDNI, _global_den.denvt,
			STR_TYZDEN, _global_den.tyzden,
			STR_LIT_OBD, _global_den.litobd,
			STR_LIT_ROK, _global_den.litrok,
			STR_MODLITBA, str_modlitby[modl],
			pom);
		Export_HtmlForm(action);
	}// query_type == PRM_LIT_OBD
	else{
		// 2011-10-03: vytlačenie buttona pre jednotlivú modlitbu; bolo nakopírované pre jednotlivé modlitby; zjednodušenie a zapracovanie pôvodnej INIT_POM()
		if(_global_linky == ANO){
			sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s",
			// Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, str_modlitby[modl],
				pom);
			Export_HtmlForm(action);
		}
		else{
			// BEGIN: pôvodné INIT_POM()
			if(typ == EXPORT_DNA_JEDEN_DEN_LOCAL){
				sprintf(pom, "#m-%c", char_modlitby[modl]);
			}
			else if(_global_opt_batch_monthly == ANO){
				if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
					sprintf(pom, FILENAME_EXPORT_DATE_SIMPLE"_%d%s%s", _global_den.rok % 100, _global_den.mesiac, _global_den.den, poradie_svateho, export_fname_modl_str /* char_modlitby[modl] */, doplnkova_psalmodia == MODL_CEZ_DEN_ZALMY_ZO_DNA ? ".htm" : "d.htm");
				}
				else{
					sprintf(pom, FILENAME_EXPORT_DATE_FULL"_%d%s%s", _global_den.rok, _global_den.mesiac, _global_den.den, poradie_svateho, export_fname_modl_str /* char_modlitby[modl] */, doplnkova_psalmodia == MODL_CEZ_DEN_ZALMY_ZO_DNA ? ".htm" : "d.htm");
				}
			}
			Log("\treťazec pom == %s; doplnkova_psalmodia == %d\n", pom, doplnkova_psalmodia);
			if((doplnkova_psalmodia != MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA)){
				if((som_v_tabulke == ANO) && (typ != EXPORT_DNA_JEDEN_DEN_LOCAL)){
					Export_HtmlForm(pom);
				}
				else{
					Export(HTML_LINE_BREAK"<a href=\"%s\" "HTML_CLASS_BUTTON">\n", pom);
				}
			}
			// END: pôvodné INIT_POM()
		}
	}// !(query_type == PRM_LIT_OBD)

	if((som_v_tabulke == ANO) && (typ != EXPORT_DNA_JEDEN_DEN_LOCAL)){
		Export("<"HTML_FORM_INPUT_SUBMIT" title=\"%s\" value=\"", nazov_modlitby(modl_visible));
		Export("%s", html_button_nazov_modlitby(modl_visible));
		Export("\">\n");
		Export("</form>\n");
	}
	else{
		if(typ == EXPORT_DNA_JEDEN_DEN_LOCAL){
			Export("%s", html_button_nazov_modlitby(modl_visible));
		}
		else{
			Export("%s", nazov_modlitby(modl_visible));
		}
		Export("</a>\n");
	}

	// 2011-04-06: odvetvené, aby sa to nedostalo na web resp. jeho simuláciu, teda len pre command-line export (tam BEHAVIOUR_CMDLINE)
#ifndef BEHAVIOUR_WEB
	if(orig_doplnkova_psalmodia == MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA){
		doplnkova_psalmodia = orig_doplnkova_psalmodia;
		if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_DOPLNKOVA) == BIT_OPT_1_MCD_DOPLNKOVA){
			// BEGIN: opakuje sa pôvodné INIT_POM()
			if(typ == EXPORT_DNA_JEDEN_DEN_LOCAL){
				sprintf(pom, "#m-%c", char_modlitby[modl]);
			}
			else if(_global_opt_batch_monthly == ANO){
				if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
					sprintf(pom, FILENAME_EXPORT_DATE_SIMPLE"_%d%s%s", _global_den.rok % 100, _global_den.mesiac, _global_den.den, poradie_svateho, export_fname_modl_str /* char_modlitby[modl] */, doplnkova_psalmodia == MODL_CEZ_DEN_ZALMY_ZO_DNA ? ".htm" : "d.htm");
				}
				else{
					sprintf(pom, FILENAME_EXPORT_DATE_FULL"_%d%s%s", _global_den.rok, _global_den.mesiac, _global_den.den, poradie_svateho, export_fname_modl_str /* char_modlitby[modl] */, doplnkova_psalmodia == MODL_CEZ_DEN_ZALMY_ZO_DNA ? ".htm" : "d.htm");
				}
			}
			Log("\treťazec pom == %s; doplnkova_psalmodia == %d\n", pom, doplnkova_psalmodia);
			// 2011-12-01: pôvodne tu bola copy-paste podmienka if((doplnkova_psalmodia != MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA)), avšak nesmie tu byť
			if((som_v_tabulke == ANO) && (typ != EXPORT_DNA_JEDEN_DEN_LOCAL)){
				Export_HtmlForm(pom);
			}
			else{
				Export(HTML_LINE_BREAK"<a href=\"%s\" "HTML_CLASS_BUTTON">\n", pom);
			}
			// END: pôvodné INIT_POM()
			if((som_v_tabulke == ANO) && (typ != EXPORT_DNA_JEDEN_DEN_LOCAL)){
				Export("<"HTML_FORM_INPUT_SUBMIT" title=\"%s (%s)\" value=\"", nazov_modlitby(modl), str_doplnkova_psalmodia[_global_jazyk]);
				Export("(alt)"); // alternatíva s doplnkovou psalmódiou [prípadne neskôr doriešiť krajšie]
				Export("\">\n");
				Export("</form>\n");
			}
			else{
				Export("(alt)"); // alternatíva s doplnkovou psalmódiou [prípadne neskôr doriešiť krajšie]
				Export("</a>\n");
			}
		}// alternatíva s doplnkovou psalmódiou
	}// orig_doplnkova_psalmodia == MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA
#endif
}// _export_rozbor_dna_button_modlitba();

void _export_rozbor_dna_button_modlitba2(short int modl, char pom[MAX_STR]){
	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);
	if((query_type == PRM_LIT_OBD) && (modl == MODL_VSETKY)){
		Log("pre query_type == PRM_LIT_OBD button pre všetky modlitby ešte nie je doriešený...\n");
		// ToDo
		return;
	}
	// kvôli buttonom "Detaily..." a "všetky" (všetky modlitby)
	if(query_type == PRM_LIT_OBD){
		Log("pre query_type == PRM_LIT_OBD sa buttony pre modlitby tlačia ináč (nemám nastavený dátum)...\n");
		// predpokladáme, že máme _global_linky == ANO
		sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%c"HTML_AMPERSAND"%s=%s%s",
		// Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%c"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_LIT_OBD,
			STR_DEN_V_TYZDNI, _global_den.denvt,
			STR_TYZDEN, _global_den.tyzden,
			STR_LIT_OBD, _global_den.litobd,
			STR_LIT_ROK, _global_den.litrok,
			STR_MODLITBA, str_modlitby[modl],
			pom);
	}// query_type == PRM_LIT_OBD
	else{
		Log("query_type != PRM_LIT_OBD, buttony sa teda pre modlitby tlačia klasicky (STR_PRM_DETAILY alebo STR_PRM_DATUM)...\n");
		sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s",
		// Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, (modl == MODL_DETAILY)? STR_PRM_DETAILY : STR_PRM_DATUM,
			STR_DEN, _global_den.den,
			STR_MESIAC, _global_den.mesiac,
			STR_ROK, _global_den.rok,
			STR_MODLITBA, str_modlitby[modl],
			pom);
	}// !(query_type == PRM_LIT_OBD)
	Export_HtmlForm(action);
	Export("<"HTML_FORM_INPUT_SUBMIT2" title=\"%s\" value=\"", nazov_modlitby(modl));
	Export("%s", html_button_nazov_modlitby(modl));
	Export("\">\n");
	Export("</form>\n");
}// _export_rozbor_dna_button_modlitba2

short int ma_na_vyber_spolocne_casti(short int poradie_svateho){
	// 2011-10-03: vytvorené
	short int ret = NIE;
	_struct_sc sc;
	sc.a1 = MODL_SPOL_CAST_NEURCENA;
	sc.a2 = MODL_SPOL_CAST_NEURCENA;
	sc.a3 = MODL_SPOL_CAST_NEURCENA;

	Log("ma_na_vyber_spolocne_casti(%d) -- začiatok...\n", poradie_svateho);

	if(poradie_svateho == PORADIE_PM_SOBOTA){
		sc.a1 = MODL_SPOL_CAST_PANNA_MARIA;
	}
	else if(poradie_svateho > 0){
		sc = _decode_spol_cast(_global_svaty(poradie_svateho).spolcast);
	}

	// if((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a2 != MODL_SPOL_CAST_NEURCENA)){ // ak má viac ako jednu spoločnú časť nastavenú
	if((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT)){ // stačí, že má jednu spoločnú časť nastavenú
		ret = ANO;
	}
	Log("ma_na_vyber_spolocne_casti(%d) -- koniec: %d.\n", poradie_svateho, ret);
	return ret;
}// ma_na_vyber_spolocne_casti();

//---------------------------------------------------------------------
// _export_rozbor_dna_buttons(typ, int, int)
// typ - ako v _export_rozbor_dna()
//
// exportuje buttony pre _export_rozbor_dna()
// int poradie_svateho: ak je 2 alebo 3, znamena to, ze ide o druheho resp. tretieho svateho (ked je viac ako 1 lubovolna spomienka) -- v takom pripade este pridavame premennu STR_DALSI_SVATY s hodnotou 2 resp. 3
// 2011-07-03: pridaný parameter, či chce tlačiť liturgickú farbu (použitie v navigácii)
void _export_rozbor_dna_buttons(short int typ, short int poradie_svateho, short int den_zoznam, short int zobrazit_mcd){
// 2005-03-21: Pridany dalsi typ exportu 
// 2009-08-11: pre tento typ exportu berieme do úvahy parameter 'M'
// 2011-10-03: predsunutá časť, ktorá bola súčasťou #define BUTTONS
	Log("--- _export_rozbor_dna_buttons(typ == %d) -- begin\n", typ);
#ifdef OS_Windows_Ruby
	if((typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
		Export("\n<!--buttons:begin-->\n");
	}
#endif
	short int i = MODL_NEURCENA;
	short int smer = SLAV_NEURCENE;
	char pom[MAX_STR];
	char pom2[MAX_STR];

	mystrcpy(pom, STR_EMPTY, MAX_STR);
	mystrcpy(pom2, STR_EMPTY, MAX_STR);

	short int som_v_tabulke = ANO; // 2009-08-26: či sa používa tabuľka; bežne pre web áno, pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku

	short int _pom_den = _global_den.den;
	short int _pom_mesiac = _global_den.mesiac;
	short int _pom_rok = _global_den.rok;

	short int su_prve_vespery = NIE; // 2013-04-05: pomocná premenná, do ktorej sa uloží, či sa exportovali aj buttony pre prvé vešpery a prvé kompletórium; podľa toho sa potom zmení label pre druhé vešpery

	// XML export -- začiatok daného slávenia
	if(typ == EXPORT_DNA_XML){
		Export(ELEMID_BEGIN(XML_CELEBRATION)"\n", poradie_svateho);
		Export(ELEM_BEGIN(XML_CELEBRATION_ID)"%d"ELEM_END(XML_CELEBRATION_ID)"\n", poradie_svateho); // pre istotu duplikovanie :)
	}

	// BEGIN: časť podľa #define BUTTONS (len pre volania, kde bolo použité BUTTONS, t. j. den_zoznam == ANO)
	if(den_zoznam == ANO){

		if((typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
			Export("\n"); // presunuté sem z nasledujúceho if-u
		}
		if(typ == EXPORT_DNA_XML){
			Export(ELEM_BEGIN(XML_STRING_TITLE));
		}
		else{
			Export("<!-- BEGIN:_global_string -->");
		}

		init_global_string(typ, poradie_svateho, MODL_NEURCENA, /* aj_citanie */ ((den_zoznam == ANO) && ((typ == EXPORT_DNA_JEDEN_DEN) || (typ == EXPORT_DNA_JEDEN_DEN_LOCAL) || (typ == EXPORT_DNA_DNES)))? ANO: NIE);

		if(typ == EXPORT_DNA_VIAC_DNI_TXT){
			Export("\"");
		}

		Export("%s", _global_string);

		if(typ == EXPORT_DNA_XML){
			Export(ELEM_END(XML_STRING_TITLE));
		}
		else{
			Export("<!-- END:_global_string -->");
		}

		if(typ == EXPORT_DNA_VIAC_DNI_TXT){
			Export("\"; ");
		}
		else{
			Export("\n"); // presunuté sem z predošlého if-u
		}

		if(typ != EXPORT_DNA_VIAC_DNI_TXT){
			Log("  _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST == %d: \n", _global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST);
			if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST) == BIT_OPT_1_ZOBRAZ_SPOL_CAST){
				ret_sc = init_global_string_spol_cast(MODL_SPOL_CAST_NULL, poradie_svateho);
				Log("including SPOL_CAST\n");
				if(!equals(_global_string_spol_cast, STR_EMPTY)){
					Export(HTML_LINE_BREAK);
					if(typ == EXPORT_DNA_XML){
						Export(ELEM_BEGIN(XML_STRING_COMMUNIA));
					}
					else{
						Export("<!-- BEGIN:_global_string_spol_cast -->");
					}
					_export_global_string_spol_cast(NIE);
					if(typ == EXPORT_DNA_XML){
						Export(ELEM_END(XML_STRING_COMMUNIA)"\n");
					}
					else{
						Export("<!-- END:_global_string_spol_cast -->");
					}
				}// if(!equals(_global_string_spol_cast, STR_EMPTY))
			}// if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZOBRAZ_SPOL_CAST) == BIT_OPT_1_ZOBRAZ_SPOL_CAST)
		}
	}// if(den_zoznam == ANO)
	// END: časť podľa #define BUTTONS

	if(typ == EXPORT_DNA_XML){
		som_v_tabulke = NIE;
		// ďalšie vlastnosti z "_global_den"; používa sa globálne definovaná _struct_dm _local_den; nastavená vo funkcii init_global_string()
		Export(ELEM_BEGIN(XML_LIT_YEAR_LETTER)"%c"ELEM_END(XML_LIT_YEAR_LETTER)"\n", _local_den.litrok);
		Export(ELEM_BEGIN(XML_LIT_WEEK)"%d"ELEM_END(XML_LIT_WEEK)"\n", _local_den.tyzden);
		Export(ELEM_BEGIN(XML_LIT_WEEK_PSALT)"%d"ELEM_END(XML_LIT_WEEK_PSALT)"\n", _local_den.tyzzal);
		Export(ELEMID_BEGIN(XML_LIT_SEASON)"%s"ELEM_END(XML_LIT_SEASON)"\n", _local_den.litobd, nazov_obdobia(_local_den.litobd));
		Export(ELEMID_BEGIN(XML_LIT_TYPE)"%s"ELEM_END(XML_LIT_TYPE)"\n", _local_den.typslav, nazov_slavenia(_local_den.typslav));
		Export(ELEM_BEGIN(XML_LIT_TYPE_LOCAL)"%s"ELEM_END(XML_LIT_TYPE_LOCAL)"\n", nazov_slavenia_lokal[_local_den.typslav_lokal]);
		Export(ELEM_BEGIN(XML_LIT_LEVEL)"%d"ELEM_END(XML_LIT_LEVEL)"\n", _local_den.smer);
		Export(ELEM_BEGIN(XML_LIT_REQUIRED)"%d"ELEM_END(XML_LIT_REQUIRED)"\n", _local_den.prik);
		xml_export_spol_cast(poradie_svateho);
		Export(ELEM_BEGIN(XML_LIT_NAME)"%s"ELEM_END(XML_LIT_NAME)"\n", _local_den.meno);
		Export(ELEMID_BEGIN(XML_LIT_COLOR)"%s"ELEM_END(XML_LIT_COLOR)"\n", _local_den.farba, nazov_farby(_local_den.farba));
		if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_CZ)){
			Export(ELEM_BEGIN(XML_LIT_CALENDAR)"%s"ELEM_END(XML_LIT_CALENDAR)"\n", nazov_kalendara_short[_local_den.kalendar]);
		}
		Export(ELEM_BEGIN(XML_LIT_READINGS)"%s"ELEM_END(XML_LIT_READINGS)"\n", _local_den.lc_str_id);
	}

	if(den_zoznam != ANO){
		// 2011-07-05/2011-07-11: pre tlačidlá predošlého a nasledujúceho dňa pre navigáciu v modlitbe treba použiť iný dátum ako _global_den, 
		// nakoľko pre vešpery v predvečer nedele resp. slávnosti sa dátum posunul o jeden deň...
		// Export("<!-- úprava _global_den na: den %d | mesiac %d | rok %d -->", _global_vstup_den, _global_vstup_mesiac, _global_vstup_rok);
		_global_den.den = _global_vstup_den;
		_global_den.mesiac = _global_vstup_mesiac;
		_global_den.rok = _global_vstup_rok;
	}

	if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): keďže sme v _global_opt_batch_monthly == ANO a export_monthly_druh (%d) > 2, nebudeme exportovať tabuľku...\n", typ, export_monthly_druh);
	}

	if(typ == EXPORT_DNA_VIAC_DNI_TXT){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): kvôli typu nebudeme exportovať tabuľku...\n", typ);
	}

	if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
		Log("--- _export_rozbor_dna_buttons(): idem tlačiť buttony...\n");

		Export("\n");

		if(_global_opt_batch_monthly == NIE){
			// prerobene 13/04/2000A.D.: tlacitka niekedy linkuju iba subor, nie linku: podla _global_linky
			if(_global_linky == ANO){
				if(poradie_svateho > 0){
					// 2003-07-16 zmeneny & na HTML_AMPERSAND
					sprintf(pom, HTML_AMPERSAND"%s=%d", STR_DALSI_SVATY, poradie_svateho);
				}// poradie_svateho > 0
				else{
					mystrcpy(pom, STR_EMPTY, MAX_STR);
				}// !(poradie_svateho > 0)
			}
			else{// nezobrazovat linky
				if((poradie_svateho >= UNKNOWN_PORADIE_SVATEHO) && (poradie_svateho < 5)) // 2009-03-27: snáď OK: UNKNOWN_PORADIE_SVATEHO (bolo tu: poradie_svateho >= 0)
					sprintf(pom, "%s%d.htm", FILE_NAME_POKEC, poradie_svateho);
				else
					mystrcpy(pom, FILE_NAME_CHYBA, MAX_STR);
			}

			prilep_request_options(pom, pom2);

		}// if(_global_opt_batch_monthly == NIE)
		else{
			// 2009-11-08: nový spôsob exportu pre batch mód s prepínačom 'M'
			mystrcpy(pom, STR_EMPTY, MAX_STR);
			// bude sa nastavovať na príslušnom mieste
		}// else if(_global_opt_batch_monthly == NIE)

		if(den_zoznam == ANO){
			// 2006-08-19: pridaná liturgická farba - pre buttons je treba v každom riadku 
			// 2011-07-03: možnosť explicitne neeexportovať farbu
			if(som_v_tabulke == ANO){
				Export("</td>\n<td>");
				Export(HTML_NONBREAKING_SPACE); // empty table cell
				Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
			}
			Export("%s", _global_string_farba);
			if(som_v_tabulke == ANO){
				Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
				Export(HTML_NONBREAKING_SPACE);
			}
		}// den_zoznam == ANO

		// 2011-10-03: cleanup kódu (odstránenie nepotrebných a nepoužívaných častí)

		// oddelenie (1)
		if(som_v_tabulke == ANO){
			Export("</td>\n");
		}

		if(den_zoznam == ANO){
			Export("<!-- buttony/tabuľka s buttonmi pre jednotlivé modlitby riadka v rámci dňa -->\n");
		}
		else{
			Export("<!-- buttony/tabuľka s buttonmi pre jednotlivé modlitby zvoleného slávenia dňa -->\n");
		}

		// oddelenie (2)
		if(som_v_tabulke == ANO){
			Export("<td "HTML_VALIGN_MIDDLE">");
		}

		// 2011-10-05: pridaný nový element (ďalšia tabuľka)
		if((som_v_tabulke == ANO) && ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE)){
			// ukončenie riadka
			Export("</td>\n</tr>\n");
			// nový riadok, v ktorom bude jediná bunka s tabuľkou
			Export("<tr>\n<td colspan=\"6\">\n");
			// tabuľka -- začiatok
			Export("<!-- BEGIN:úsporné zobrazenie v tabuľke -->\n");
			Export("\n<table "HTML_ALIGN_CENTER">\n");
			Export("<tbody>\n");
		}

		// 2011-03-22: doplnené "prvé vešpery"; môžu byť pre smer < 5 ale nie pre všetky dni, preto táto podmienka... | odvetvené len ak je _global_opt 8 == ANO
		// 2013-04-05: ToDo: doriešiť pre všelijaké špeciálne "konflikty", napr. 8. apríl 2013 (presunutá slávnosť Zvestovania Pána na pondelok po Veľkonočnej oktáve) -- má mať prvé vešpery? a pod.77
		if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY){
			smer = _global_den.smer;
			for(short int ii = 0; ii < MAX_POCET_SVATY; ii++){
				if(poradie_svateho == ii + 1){
					smer = (smer > _global_svaty(poradie_svateho).smer) ? _global_svaty(poradie_svateho).smer : smer;
				}
			}
			if(
			((smer < 5) ||
				// cl. 11: slavnosti su zvlast vyznacnymi dnami. ich slavenie sa zacina prvymi vesperami v predchadzajuci den.
				((smer == 5) && (_global_den.denvt == DEN_NEDELA) && ((_global_den.litobd == OBD_CEZ_ROK) || je_vianocne(_global_den.litobd))) ||
				// cl. 13: sviatky sa slavia v rozsahu jedneho dna, a preto nemaju prve vespery, ak len nejde o sviatky pana, ktore pripadaju na nedelu v obdobi ,,cez rok" a na nedelu vo vianocnom obdobi a nahradzuju nedelnajsiu liturgiu hodin.
				(_global_den.denvt == DEN_NEDELA) ||
				// nedeľa
				(
					((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) && (_global_den.denvt == DEN_SOBOTA)) ||// 2. velkonocna nedela
					((_global_den.mesiac - 1 == MES_DEC) && (_global_den.den == 25)) // ked narodenie pana pripadne na pondelok, tak prve vespery maju prednost pred 4. adventnou nedelou; napr. rok 2000
				)
			)
			&& !(
				((_global_den.denvr <= VELKONOCNA_NEDELA + 6) && (_global_den.denvr >= KVETNA_NEDELA + 1)) // všedné dni veľkého týždňa počnúc pondelkom, veľkonočné trojdnie od veľkého piatka do veľkonočnej oktávy, soboty (2013-04-05: opravené; bolo len + 5, do piatka)
				|| (_global_den.denvr == POPOLCOVA_STREDA) // popolcová streda
			)){
				// oddelenie riadka
				if((som_v_tabulke == ANO) && ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE)){
					Export("<!-- riadok -->\n");
					Export("<tr>\n");
					Export("<td>\n");
				}
				// 2011-03-22: prvé vešpery, len pre tie modlitby, ktoré môžu mať prvé vešpery
				// prvé vešpery -- button
				i = MODL_PRVE_VESPERY;
				_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ NIE, som_v_tabulke);

				// oddelenie
				if(som_v_tabulke == ANO)
					Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");

				// kompletórium po prvých vešperách -- button
				i = MODL_PRVE_KOMPLETORIUM;
				_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ NIE, som_v_tabulke);

				// oddelenie riadka
				if((som_v_tabulke == ANO) && ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE)){
					Export("</td>");
					Export("</tr>\n");
				}

				su_prve_vespery = ANO; // aby sa pri normálnych vešperách (v ďalšom) vedelo, že to sú "druhé vešpery"

			}// if(_global_den.smer < 5)...
			else{
				// Log Export("nemôžu byť prvé vešpery (smer == %d, denvt == %d, denvr == %d, VELKONOCNA_NEDELA == %d, KVETNA_NEDELA == %d, POPOLCOVA_STREDA == %d)...\n", _global_den.smer, _global_den.denvt, _global_den.denvr, VELKONOCNA_NEDELA, KVETNA_NEDELA, POPOLCOVA_STREDA);
				// oddelenie
				if(som_v_tabulke == ANO){
					if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
					}
					else{
						Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
					}
				}
			}
		}// (_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY

		// oddelenie
		if(som_v_tabulke == ANO){
			if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
				Export("<!-- riadok -->\n");
				Export("<tr>\n");
				Export("<td "HTML_VALIGN_MIDDLE" "HTML_ALIGN_RIGHT">\n");
			}
			else{
				Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
			}
		}

		// invitatórium -- button
		i = MODL_INVITATORIUM;
		_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ NIE, som_v_tabulke);
		
		// oddelenie
		if(som_v_tabulke == ANO){
			if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
				Export("</td>\n<td "HTML_VALIGN_MIDDLE" "HTML_ALIGN_CENTER">\n");
			}
			else{
				Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
			}
		}

		// modlitba posvätného čítania -- button
		i = MODL_POSV_CITANIE;
		_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ NIE, som_v_tabulke);
		// 2007-03-19: Na základe pripomienky Vlada Kiša posvätné čítanie predsunuté pred ranné chvály

		// oddelenie
		if(som_v_tabulke == ANO){
			if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
				Export("</td>\n<td "HTML_VALIGN_MIDDLE" "HTML_ALIGN_LEFT">\n");
			}
			else{
				Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
			}
		}

		// ranné chvály -- button
		i = MODL_RANNE_CHVALY;
		_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ NIE, som_v_tabulke);

		// oddelenie
		if(som_v_tabulke == ANO){
			if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
				Export("</td>\n");
				Export("</tr>\n");
				Export("<!-- riadok -->\n");
				Export("<tr>\n");
				Export("<td "HTML_VALIGN_MIDDLE" "HTML_ALIGN_RIGHT">\n");
			}
			else{
				Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
			}
		}

		// Export("<!-- zobrazit_mcd == %d | poradie_svateho == %d -->\n", zobrazit_mcd, poradie_svateho);

		// 2012-08-21: zobraziť buttony pre modlitbu cez deň + kompletórium len ak nejde o ľubovoľnú spomienku (vtedy nemajú význam)
		if((zobrazit_mcd == ANO) || (poradie_svateho == 0)){

			// modlitba cez deň (predpoludním) -- button
			i = MODL_PREDPOLUDNIM;
			_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ ANO, som_v_tabulke);

			// oddelenie
			if(som_v_tabulke == ANO){
				if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
					Export("</td>\n<td "HTML_VALIGN_MIDDLE" "HTML_ALIGN_CENTER">\n");
				}
				else{
					Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
				}
			}

			// modlitba cez deň (napoludnie) -- button
			i = MODL_NAPOLUDNIE;
			_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ ANO, som_v_tabulke);

			// oddelenie
			if(som_v_tabulke == ANO){
				if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
					Export("</td>\n<td "HTML_VALIGN_MIDDLE" "HTML_ALIGN_LEFT">\n");
				}
				else{
					Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
				}
			}

			// modlitba cez deň (popoludní) -- button
			i = MODL_POPOLUDNI;
			_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ ANO, som_v_tabulke);

			// oddelenie
			if(som_v_tabulke == ANO){
				if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
					Export("</td>\n");
					Export("</tr>\n");
					Export("<!-- riadok -->\n");
					Export("<tr>\n");
					Export("<td "HTML_ALIGN_RIGHT">\n");
				}
				else{
					Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
				}
			}

		}// zobraziť buttony pre modlitbu cez deň + kompletórium
		else{
			// pre "neúsporné" zobrazenie treba kvôli zarovnaniu doplniť prázdne 3 bunky tabuľky
			if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
				Export("<!-- nezobraziť mcd -->\n");
			}
			else{
				Export(HTML_NONBREAKING_SPACE);

				Export("</td>\n");
				Export("<td "HTML_VALIGN_MIDDLE">\n");

				Export(HTML_NONBREAKING_SPACE);

				Export("</td>\n");
				Export("<td "HTML_VALIGN_MIDDLE">\n");

				Export(HTML_NONBREAKING_SPACE);

				Export("</td>\n");
				Export("<td "HTML_VALIGN_MIDDLE">\n");
			}
		}// NEzobraziť buttony pre modlitbu cez deň + kompletórium

		// spomienka panny márie v sobotu nemá vešpery (ani kompletórium po nich)
		// 2003-07-15: správne odsadené
		// 2011-03-23: ak je (_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY, zobrazujú sa prvé vešpery pre nedele a slávnosti priamo pre tie dni
		// 2012-08-27: vešpery a kompletórium nemá zmysel zobrazovať, ak ide o sobotu a ďalšieho svätého (pri viacerých ľubovoľných spomienkach)
		// 2013-04-05: zavedené "nie_su_vespery" kvôli Bielej (veľkej) sobote
		if((poradie_svateho != PORADIE_PM_SOBOTA) && !(((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY) && (nie_su_vespery))
			&& (((zobrazit_mcd == ANO) || (_global_den.denvt != DEN_SOBOTA)) || (poradie_svateho == 0))
			){
			// vešpery -- button
			i = MODL_VESPERY;
			_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ NIE, som_v_tabulke, (su_prve_vespery == ANO)? MODL_DRUHE_VESPERY: i);

			// oddelenie
			if(som_v_tabulke == ANO){
				if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
					Export("</td>\n<td "HTML_VALIGN_MIDDLE" "HTML_ALIGN_CENTER">\n");
				}
				else{
					Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
				}
			}

			// 2012-08-21: zobraziť buttony pre modlitbu cez deň + kompletórium len ak nejde o ľubovoľnú spomienku (vtedy nemajú význam)
			if((zobrazit_mcd == ANO) || (poradie_svateho == 0)){
				// kompletórium -- button
				i = MODL_KOMPLETORIUM;
				_export_rozbor_dna_button_modlitba(typ, poradie_svateho, i, pom, /* doplnkova_psalmodia */ NIE, som_v_tabulke, (su_prve_vespery == ANO)? MODL_DRUHE_KOMPLETORIUM: i);
			}// zobraziť buttony pre modlitbu cez deň + kompletórium
			else{
				Export("<!-- nezobraziť kompletórium -->\n");
			}// NEzobraziť buttony pre modlitbu cez deň + kompletórium
		}// if(poradie_svateho != PORADIE_PM_SOBOTA) &&...
		else{
			// 2006-10-11: treba ešte jedno odsadenie, aby Detaily... boli pod sebou, ak ide napr. o sobotu
			// oddelenie
			if(som_v_tabulke == ANO)
				Export("</td>\n<td>");
		}// prázdne odsadenie

#define ZOBRAZ_BUTTON_VSETKY_MODLITBY
#ifdef ZOBRAZ_BUTTON_VSETKY_MODLITBY
		// oddelenie
		if(som_v_tabulke == ANO){
			if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
				Export("</td>\n");
				Export("</tr>\n");
				Export("<!-- riadok -->\n");
				Export("<tr>\n");
				Export("<td "HTML_ALIGN_RIGHT">\n");
			}
			else{
				Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
			}
		}

		// button 'Všetky modlitby...'
		i = MODL_VSETKY;
		if(_global_linky == ANO){
			_export_rozbor_dna_button_modlitba2(i, pom);
		}
#endif

#define ZOBRAZ_BUTTON_DETAILY
#ifdef ZOBRAZ_BUTTON_DETAILY
		// nezobrazujú sa pre sobotnú spomienku panny márie
		if(ma_na_vyber_spolocne_casti(poradie_svateho) && (poradie_svateho != PORADIE_PM_SOBOTA)){

			Log("ma_na_vyber_spolocne_casti(poradie_svateho == %d) vrátilo ANO...\n", poradie_svateho);

			// oddelenie
			if(som_v_tabulke == ANO){
				if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
					Export("</td>\n<td "HTML_VALIGN_MIDDLE" colspan=\"2\">");
				}
				else{
					Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
				}
			}

			// button 'Detaily...'
			i = MODL_DETAILY;
			if(_global_linky == ANO){
				_export_rozbor_dna_button_modlitba2(i, pom);
			}// ak nie zobrazovat linky na internet (2009-08-11: teda napr. pre batch mód), tlacidlo `Detaily...' je zbytocne
		}// ma_na_vyber_spolocne_casti(poradie_svateho)
		else{
			Log("nemá na výber spoločné časti...\n");
		}
#endif

		// 2011-10-05: pridaný nový element (ďalšia tabuľka)
		if((som_v_tabulke == ANO) && ((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE)){
			Export("</tr>\n");
			Export("</tbody>\n");
			Export("</table>\n");
			// tabuľka -- koniec
			Export("<!-- END:úsporné zobrazenie v tabuľke -->\n");
		}

	}// if(typ)
	else{
		// inak (pre ostatné typy exportu) buttony neexportujem
		Log("--- _export_rozbor_dna_buttons_dni(): buttony nedávam...\n");
		if(typ == EXPORT_DNA_VIAC_DNI){
			// 2006-08-19: pridaná liturgická farba - pre buttons je treba v každom riadku
			if(som_v_tabulke == ANO){
				Export("<td>"HTML_NONBREAKING_SPACE"</td>\n"); // empty table cell
				Export("<td>%s</td>\n", _global_string_farba);
			}
		}// (typ == EXPORT_DNA_VIAC_DNI)
	}

	// späť pôvodné nastavenia (pre den_zoznam != ANO boli zmenené)
	_global_den.den = _pom_den;
	_global_den.mesiac = _pom_mesiac;
	_global_den.rok = _pom_rok;
#ifdef OS_Windows_Ruby
	if((typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
		Export("\n<!--buttons:end-->\n");
	}
#endif

	// XML export -- koniec daného slávenia
	if(typ == EXPORT_DNA_XML){
		Export(ELEM_END(XML_CELEBRATION)"\n");
	}

	Log("--- _export_rozbor_dna_buttons(typ == %d) -- end\n", typ);
}// _export_rozbor_dna_buttons()

void _export_rozbor_dna_buttons_dni_dnes(short int dnes_dnes, short int som_v_tabulke, char pom2[MAX_STR], short int zobraz_odkaz_na_skrytie){
#ifdef OS_Windows_Ruby
	Export("\n<!--buttons/dni/dnes:begin-->\n");
#endif
	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);

	// 2009-08-12: tlačidlo pre dnešok sa pre 'M' (batch módový export) nezobrazuje
	if(_global_opt_batch_monthly == NIE){
		if(som_v_tabulke == ANO){
			Export("<td "HTML_ALIGN_CENTER">\n");
		}
		else{
			Export("<center>\n");
		}
		if(dnes_dnes >= ANO){
			sprintf(action, "%s?%s=%s%s", script_name, STR_QUERY_TYPE, STR_PRM_DNES, pom2);
			// Export("<form action=\"%s?%s=%s%s\" method=\"post\">\n", script_name, STR_QUERY_TYPE, STR_PRM_DNES, pom2);
			Export_HtmlForm(action);
			Export("<"HTML_FORM_INPUT_SUBMIT1" title=\"%s\" value=\"", html_button_dnes[_global_jazyk]);
		}
		else{
			sprintf(action, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, _global_den.den, STR_MESIAC, _global_den.mesiac, STR_ROK, _global_den.rok, pom2);
			Export_HtmlForm(action);
			Export("<"HTML_FORM_INPUT_SUBMIT1" title=\"%s\" value=\"", /* html_button_tento_den[_global_jazyk] */ _vytvor_string_z_datumu(_global_den.den, _global_den.mesiac, _global_den.rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
		}
		if(dnes_dnes == 2){
			Export((char *)html_text_batch_Prev[_global_jazyk]);
			Export(HTML_NONBREAKING_SPACE);
			Export((char *)html_button_tento_den[_global_jazyk]);
		}
		else if(dnes_dnes == ANO){
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
			Export((char *)html_button_Dnes[_global_jazyk]);
#else
			Export((char *)html_button_dnes[_global_jazyk]);
		}
		else{
			Export((char *)html_button_hore[_global_jazyk]);
#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
			Export((char *)html_button_tento_den[_global_jazyk]);
#else
			Export(_vytvor_string_z_datumu(_global_den.den, _global_den.mesiac, _global_den.rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
#endif
		}
#endif
		Export("\">\n");

		// 2012-10-02: doplnenie možnosti skryť navigáciu
		if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) == BIT_OPT_2_ROZNE_MOZNOSTI){ // len ak je táto možnosť (zobrazovanie všeličoho) zvolená
			if(zobraz_odkaz_na_skrytie == ANO){
				char show[MAX_STR] = STR_EMPTY;
				char hide[MAX_STR] = STR_EMPTY;
				sprintf(show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_navig_buttons[_global_jazyk]);
				sprintf(hide, "%s %s", html_text_option_skryt[_global_jazyk], html_text_navig_buttons[_global_jazyk]);
				_export_link_show_hide(OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_NAVIG_BUTTONS, show, hide, (char *)HTML_SPAN_SMALL, (char *)HTML_CLASS_QUIET, (char *)STR_EMPTY, (char *)STR_EMPTY, (char *)STR_EMPTY, (char *)HTML_SPAN_END);
			}
		}
		Export("</form>\n");

		if(som_v_tabulke == ANO){
			Export("</td>\n");
		}
		else{
			Export("</center>\n");
		}
	}// _global_opt_batch_monthly == NIE
#ifdef OS_Windows_Ruby
	Export("<!--buttons/dni/dnes:end-->\n");
#endif
}// _export_rozbor_dna_buttons_dni_dnes()

//---------------------------------------------------------------------
// _export_rozbor_dna_buttons_dni(int, int)
//
// typ - ako v _export_rozbor_dna()
//
// exportuje buttony pre _export_rozbor_dna() a to button predosleho a nasledujuceho dna
// 2011-07-03: pridaná možnosť zmeniť default look (tlačidlo "dnes" pre navigáciu v modlitbe nebude mať popis "dnes" a iné zmeny pre navigáciu)
void _export_rozbor_dna_buttons_dni(short int typ, short int dnes_dnes /* = ANO */, short int aj_navigacia /* = ANO */){
	// 2014-10-20: pre blind-friendly vôbec nezobrazujeme
	if(((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BLIND_FRIENDLY) == BIT_OPT_0_BLIND_FRIENDLY) & (aj_navigacia != ANO)){
		char pom2[MAX_STR];
		mystrcpy(pom2, STR_EMPTY, MAX_STR);
		char pom3[MAX_STR];
		mystrcpy(pom3, STR_EMPTY, MAX_STR);

		prilep_request_options(pom2, pom3);

		_export_rozbor_dna_buttons_dni_dnes(dnes_dnes, NIE, pom2, NIE);
	}
	// 2012-10-01: zobrazujeme, iba ak nie je explicitne vyžiadané skrývanie
	else if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_NAVIG_BUTTONS) != BIT_OPT_2_HIDE_NAVIG_BUTTONS){
		_export_rozbor_dna_buttons_dni_call(typ, dnes_dnes);
	}
	else{
		// Export("\n<!--hide buttons-->\n");
		char show[SMALL] = STR_EMPTY;
		char hide[SMALL] = STR_EMPTY;
		sprintf(show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_navig_buttons[_global_jazyk]);
		sprintf(hide, "%s %s", html_text_option_skryt[_global_jazyk], html_text_navig_buttons[_global_jazyk]);
		char before[SMALL] = STR_EMPTY;
		sprintf(before, "<p "HTML_ALIGN_CENTER" "HTML_CLASS_SMALL">");
		char after[SMALL] = STR_EMPTY;
		mystrcpy(after, "</p>", SMALL);
		_export_link_show_hide(OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_NAVIG_BUTTONS, show, hide, (char *)STR_EMPTY, (char *)HTML_CLASS_QUIET, before, after, (char *)STR_EMPTY, (char *)STR_EMPTY);
	}
}// _export_rozbor_dna_buttons_dni()

void _export_rozbor_dna_buttons_dni_orig(short int typ, short int dnes_dnes /* = ANO */){
	Log("--- _export_rozbor_dna_buttons_dni_orig(typ == %d) -- begin\n", typ);
#ifdef OS_Windows_Ruby
	Export("\n<!--buttons/dni:begin-->\n");
#endif
	char str_month[SMALL] = STR_EMPTY;
	short int zmena_mesiaca = NIE;
	short int som_v_tabulke = ANO; // 2009-08-26: či sa používa tabuľka; bežne pre web áno, pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku

	short int _orig_den = _global_den.den;
	short int _orig_mesiac = _global_den.mesiac;
	short int _orig_rok = _global_den.rok;

	_struct_den_mesiac datum;

	char pom[MAX_STR] = STR_EMPTY;
	char pom2[MAX_STR];
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	char pom3[MAX_STR];
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	if(_global_opt_batch_monthly == NIE){
		prilep_request_options(pom2, pom3);
	}// if(_global_opt_batch_monthly == NIE)

	if(query_type == PRM_LIT_OBD){
		Log("pre query_type == PRM_LIT_OBD sa dni netlačia (nemám nastavený dátum), iba 'dnes'...\n");
		_export_rozbor_dna_buttons_dni_dnes(ANO /* dnes_dnes */, NIE /* som_v_tabulke */, pom2, ANO /* zobraz_odkaz_na_skrytie */);
		return;
	}// query_type == PRM_LIT_OBD

	if((_global_pocet_navigacia <= 1) && (_global_pocet_volani_interpretTemplate < 2)){
		// najprv dnes, potom ostatné
		if((query_type == PRM_DATUM) && (_global_modlitba != MODL_NEURCENA)){
			_export_rozbor_dna_buttons_dni_dnes(ANO /* dnes_dnes */, NIE /* som_v_tabulke */, pom2, ANO /* zobraz_odkaz_na_skrytie */);
		}
	}// if((_global_pocet_navigacia <= 1) && (_global_pocet_volani_interpretTemplate < 2))

	if(dnes_dnes != ANO){
		// 2011-07-05: pre tlačidlá predošlého a nasledujúceho dňa pre navigáciu v modlitbe treba použiť iný dátum ako _global_den, 
		// nakoľko pre vešpery v predvečer nedele resp. slávnosti sa dátum posunul o jeden deň...
		// Export("<!-- úprava _global_den na: den %d | mesiac %d | rok %d -->", _global_vstup_den, _global_vstup_mesiac, _global_vstup_rok);
		_global_den.den = _global_vstup_den;
		_global_den.mesiac = _global_vstup_mesiac;
		_global_den.rok = _global_vstup_rok;
	}

	if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): keďže sme v _global_opt_batch_monthly == ANO a export_monthly_druh (%d) > 2, nebudeme exportovať tabuľku...\n", typ, export_monthly_druh);
	}

	if(typ == EXPORT_DNA_VIAC_DNI_TXT){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): kvôli typu nebudeme exportovať tabuľku...\n", typ);
	}

	if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
		Log("--- _export_rozbor_dna_buttons_dni(): idem tlacit buttony...\n");
		short int _local_rok;

		if(dnes_dnes == ANO){
			Export("<!-- tabuľka s buttonmi predošlý, nasledovný rok/mesiac/deň presunutá pred rozbor daného dňa (teda navrch stránky) (orig) -->\n");
		}
		else{
			Export("<!-- tabuľka s buttonmi predošlý, nasledovný deň (orig) -->\n");
		}

		// tabuľka pre buttony Predchádzajúci/Nasledujúci deň/mesiac/rok a Dnes
		if(som_v_tabulke == ANO)
			Export("\n<table "HTML_ALIGN_CENTER">\n<tr>\n");
		else{
			Export("\n<center><p>\n");
			Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
		}

		if(dnes_dnes == ANO){
			// vypočítanie toho istého dňa v predošlom roku
			datum.den = _global_den.den;
			datum.mesiac = _global_den.mesiac;
			_local_rok = _global_den.rok - 1;
			if((_global_den.den == 29) && (_global_den.mesiac - 1 == MES_FEB)){ // 29FEB
				if(!prestupny(_local_rok)){
					datum.den = 28;
				}
			}

			// << predošlý rok -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR); // 2009-08-12: možno v budúcnosti by sa mohol dať odkaz na adresár s rok+mesiacom predošlého roka
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_RIGHT">");
					Export_HtmlForm(pom);
					// 2003-07-16; << zmenene na &lt;&lt; 2007-03-19: zmenené na HTML_LEFT_ARROW; 2011-01-26: zmenené na HTML_LEFT_ARROW_HUGE
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %d\" value=\""HTML_LEFT_ARROW_HUGE" ", html_button_predchadzajuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_predchadzajuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_rok[_global_jazyk]);
					Export(" \">\n");
					Export("</form>");
					Export("</td>\n");
				}
				else{
					Export("<a href=\"%s\">"HTML_LEFT_ARROW_HUGE" %s %s %d</a>\n", pom, html_button_predchadzajuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}

			// << predošlý mesiac
			if((_global_den.mesiac - 1) == MES_JAN){
				datum.mesiac = MES_DEC + 1;
				_local_rok = _global_den.rok - 1;
			}
			else{
				datum.mesiac = _global_den.mesiac - 1;
				_local_rok = _global_den.rok;
			}
			if(_global_den.den > pocet_dni[datum.mesiac - 1]){
				datum.den = pocet_dni[datum.mesiac - 1];
			}
			else{
				datum.den = _global_den.den;
			}

			// predošlý mesiac -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR);
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_RIGHT">");
					Export_HtmlForm(pom);
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\""HTML_LEFT_ARROW" ", html_button_predchadzajuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_predchadzajuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_mesiac[_global_jazyk]);
					Export(" \">\n");
					Export("</form>");
					Export("</td>\n");
				}
				else{
					Export("<a href=\"%s\">"HTML_LEFT_ARROW" %s %s %s</a>\n", pom, html_button_predchadzajuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}
		}// predošlý rok, mesiac -- len pre "dnes"

		// vypočítanie predošlého dňa
		zmena_mesiaca = NIE;
		_local_rok = _global_den.rok;
		if(_global_den.den == 1){
			zmena_mesiaca = ANO;
			if(_global_den.mesiac - 1 == MES_JAN){ // 01JAN
				datum.mesiac = 12;
				_local_rok = _global_den.rok - 1;
			}
			else{
				datum.mesiac = _global_den.mesiac - 1;
			}
			datum.den = pocet_dni[datum.mesiac - 1];
		}
		else{
			datum.den = _global_den.den - 1;
			datum.mesiac = _global_den.mesiac;
		}

		if(zmena_mesiaca == ANO){
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_SIMPLE""STR_PATH_SEPARATOR_HTML, _local_rok % 100, datum.mesiac, nazov_mes[datum.mesiac - 1]);
			}
			else{
				// EXPORT_DATE_FULL
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_FULL""STR_PATH_SEPARATOR_HTML, _local_rok, datum.mesiac, nazov_mesiaca_asci(datum.mesiac - 1));
			}
		}// if(zmena_mesiaca == ANO)
		else{
			mystrcpy(str_month, STR_EMPTY, SMALL);
		}
		Log("str_month == %s\n", str_month);

		// << predošlý deň -- button
		if(_global_opt_batch_monthly == NIE){
			sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
		}// if(_global_opt_batch_monthly == NIE)
		else{
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_SIMPLE".htm", str_month, _local_rok % 100, datum.mesiac, datum.den);
			}
			else{
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_FULL".htm", str_month, _local_rok, datum.mesiac, datum.den);
			}
		}
		Log("\treťazec pom == %s\n", pom);
		if(som_v_tabulke == ANO){
			Export("<td "HTML_ALIGN_RIGHT">");
			Export_HtmlForm(pom);
			// 2003-07-16; < zmenene na &lt; 2007-03-19: zmenené na HTML_LEFT_ARROW; 2011-01-26: zmenené na HTML_LEFT_ARROW_SINGLE
			Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\""HTML_LEFT_ARROW_SINGLE" ", html_button_predchadzajuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			if(dnes_dnes == ANO){
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
				Export((char *)html_button_predchadzajuci_[_global_jazyk]);
				Export(" ");
#endif
				Export((char *)html_text_den[_global_jazyk]);
			}
			else{
				Export(_vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			}
			Export(" \">\n");
			Export("</form>");
			Export("</td>\n");
		}
		else{
			if(_global_jazyk == JAZYK_HU){
				Export("<a href=\"%s\">"HTML_LEFT_ARROW_SINGLE" %s %s: %s</a>\n", pom, html_button_predchadzajuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			}
			else{
				Export("<a href=\"%s\">"HTML_LEFT_ARROW_SINGLE" %s %s %s</a>\n", pom, html_button_predchadzajuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			}
			Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
		}

		// 2007-03-19: Dorobené tlačidlo pre dnešok
		// 2011-10-07: presunuté do samostatnej funkcie
		_export_rozbor_dna_buttons_dni_dnes(dnes_dnes, som_v_tabulke, pom2, NIE);

		// vypočítanie nasledujúceho dňa
		zmena_mesiaca = NIE;
		_local_rok = _global_den.rok;
		if(_global_den.den == pocet_dni[_global_den.mesiac - 1]){
			zmena_mesiaca = ANO;
			datum.den = 1;
			if(_global_den.mesiac - 1 == MES_DEC){
				datum.mesiac = 1;
				_local_rok = _global_den.rok + 1;
			}
			else{
				datum.mesiac = _global_den.mesiac + 1;
			}
		}
		else{
			datum.den = _global_den.den + 1;
			datum.mesiac = _global_den.mesiac;
		}

		if(zmena_mesiaca == ANO){
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_SIMPLE""STR_PATH_SEPARATOR_HTML, _local_rok % 100, datum.mesiac, nazov_mes[datum.mesiac - 1]);
			}
			else{
				// EXPORT_DATE_FULL
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_FULL""STR_PATH_SEPARATOR_HTML, _local_rok, datum.mesiac, nazov_mesiaca_asci(datum.mesiac - 1));
			}
		}// if(zmena_mesiaca == ANO)
		else{
			mystrcpy(str_month, STR_EMPTY, SMALL);
		}
		Log("str_month == %s\n", str_month);

		// >> nasledujúci deň -- button
		if(_global_opt_batch_monthly == NIE){
			sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
		}// if(_global_opt_batch_monthly == NIE)
		else{
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_SIMPLE".htm", str_month, _local_rok % 100, datum.mesiac, datum.den);
			}
			else{
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_FULL".htm", str_month, _local_rok, datum.mesiac, datum.den);
			}
		}
		Log("\treťazec pom == %s\n", pom);
		if(som_v_tabulke == ANO){
			Export("<td "HTML_ALIGN_LEFT">");
			Export_HtmlForm(pom);
			// 2003-07-16; > zmenene na &gt; 2007-03-19: zmenené na HTML_RIGHT_ARROW; 2011-01-26: zmenené na HTML_RIGHT_ARROW_SINGLE
			Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\"", html_button_nasledujuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));

			if(dnes_dnes == ANO){
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
				Export((char *)html_button_nasledujuci_[_global_jazyk]);
				Export(" ");
#endif
				Export((char *)html_text_den[_global_jazyk]);
			}
			else{
				Export(_vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			}
			Export(" "HTML_RIGHT_ARROW_SINGLE"\">\n");
			Export("</form>");
			Export("</td>\n");
		}
		else{
			if(_global_jazyk == JAZYK_HU){
				Export("<a href=\"%s\">%s %s: %s "HTML_RIGHT_ARROW_SINGLE"</a>\n", pom, html_button_nasledujuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			}
			else{
				Export("<a href=\"%s\">%s %s %s "HTML_RIGHT_ARROW_SINGLE"</a>\n", pom, html_button_nasledujuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			}
			Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
		}

		if(dnes_dnes == ANO){
			// >> nasledovný mesiac
			if((_global_den.mesiac - 1) == MES_DEC){
				datum.mesiac = MES_JAN + 1;
				_local_rok = _global_den.rok + 1;
			}
			else{
				datum.mesiac = _global_den.mesiac + 1;
				_local_rok = _global_den.rok;
			}
			if(_global_den.den > pocet_dni[datum.mesiac - 1]){
				datum.den = pocet_dni[datum.mesiac - 1];
			}
			else{
				datum.den = _global_den.den;
			}

			// >> nasledovný mesiac -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR);
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_LEFT">");
					Export_HtmlForm(pom);
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\"", html_button_nasledujuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_nasledujuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_mesiac[_global_jazyk]);
					Export(" "HTML_RIGHT_ARROW"\">\n");
					Export("</form>");
					Export("</td>\n");
				}
				else{
					Export("<a href=\"%s\">"HTML_LEFT_ARROW" %s %s %s</a>\n", pom, html_button_nasledujuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}

			// vypočítanie toho istého dňa v nasledujúcom roku
			datum.den = _global_den.den;
			datum.mesiac = _global_den.mesiac;
			_local_rok = _global_den.rok + 1;
			if((_global_den.den == 29) && (_global_den.mesiac - 1 == MES_FEB)){ // 29FEB
				if(!prestupny(_local_rok)){
					datum.den = 28;
				}
			}
			// nasledujúci rok -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR);
				// 2009-08-12: možno v budúcnosti by sa mohol dať odkaz na adresár s rok+mesiacom nasledovného roka
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_LEFT">");
					Export_HtmlForm(pom);
					// 2003-07-16; >> zmenene na &gt;&gt; 2007-03-19: zmenené na HTML_RIGHT_ARROW; 2011-01-26: zmenené na HTML_RIGHT_ARROW_HUGE
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %d\" value=\"", html_button_nasledujuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_nasledujuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_rok[_global_jazyk]);
					Export(" "HTML_RIGHT_ARROW_HUGE"\">\n");
					Export("</form>");
					Export("</td>\n");
				}
				else{
					Export("<a href=\"%s\">%s %s %d "HTML_RIGHT_ARROW_HUGE"</a>\n", pom, html_button_nasledujuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}
		}// nasledovný mesiac, rok -- len pre "dnes"

		if(som_v_tabulke == ANO){
			Export("</tr>\n");
			Export("</table>\n");
		}

		// 2007-08-15: pokus o krajšie zobrazenie formou kalendára presunutý do _export_rozbor_dna_kalendar()

	}// if(typ)
	else{
		// inak buttony nedávam
		Log("--- _export_rozbor_dna_buttons_dni(): buttony nedávam...\n");
	}

	if((_global_pocet_navigacia > 1) || (_global_pocet_volani_interpretTemplate >= 2)){
		// najprv ostatné, potom dnes
		if((query_type == PRM_DATUM) && (_global_modlitba != MODL_NEURCENA)){
			_export_rozbor_dna_buttons_dni_dnes(ANO /* dnes_dnes */, NIE /* som_v_tabulke */, pom2, ANO /* zobraz_odkaz_na_skrytie */);
		}
	}// if((_global_pocet_navigacia > 1) || (_global_pocet_volani_interpretTemplate >= 2))

	// späť pôvodné nastavenia (pre dnes_dnes != ANO boli zmenené)
	_global_den.den = _orig_den;
	_global_den.mesiac = _orig_mesiac;
	_global_den.rok = _orig_rok;
#ifdef OS_Windows_Ruby
	Export("\n<!--buttons/dni:end-->\n");
#endif
	Log("--- _export_rozbor_dna_buttons_dni_orig(typ == %d) -- end\n", typ);
}// _export_rozbor_dna_buttons_dni_orig()

void _export_rozbor_dna_buttons_dni_compact(short int typ, short int dnes_dnes /* = ANO */){
	Log("--- _export_rozbor_dna_buttons_dni_compact(typ == %d) -- begin\n", typ);
#ifdef OS_Windows_Ruby
	Export("\n<!--buttons/dni:begin-->\n");
#endif
	char str_month[SMALL] = STR_EMPTY;
	short int zmena_mesiaca = NIE;
	short int som_v_tabulke = ANO; // 2009-08-26: či sa používa tabuľka; bežne pre web áno, pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku

	short int _orig_den = _global_den.den;
	short int _orig_mesiac = _global_den.mesiac;
	short int _orig_rok = _global_den.rok;

	short int _global_opt_orig;

	_struct_den_mesiac datum;

	char pom[MAX_STR] = STR_EMPTY;
	char pom2[MAX_STR];
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	char pom3[MAX_STR];
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	if(_global_opt_batch_monthly == NIE){
		prilep_request_options(pom2, pom3);
	}// if(_global_opt_batch_monthly == NIE)

	if(query_type == PRM_LIT_OBD){
		Log("pre query_type == PRM_LIT_OBD sa dni netlačia (nemám nastavený dátum), iba 'dnes'...\n");
		_export_rozbor_dna_buttons_dni_dnes(ANO /* dnes_dnes */, NIE /* som_v_tabulke */, pom2, ANO /* zobraz_odkaz_na_skrytie */);
		return;
	}// query_type == PRM_LIT_OBD

	if((_global_pocet_navigacia <= 1) && (_global_pocet_volani_interpretTemplate < 2)){
		// najprv dnes, potom ostatné
		if((query_type == PRM_DATUM) && (_global_modlitba != MODL_NEURCENA)){
			_export_rozbor_dna_buttons_dni_dnes(ANO /* dnes_dnes */, NIE /* som_v_tabulke */, pom2, ANO /* zobraz_odkaz_na_skrytie */);
		}
	}// if((_global_pocet_navigacia <= 1) && (_global_pocet_volani_interpretTemplate < 2))

	if(dnes_dnes != ANO){
		// 2011-07-05: pre tlačidlá predošlého a nasledujúceho dňa pre navigáciu v modlitbe treba použiť iný dátum ako _global_den, 
		// nakoľko pre vešpery v predvečer nedele resp. slávnosti sa dátum posunul o jeden deň...
		// Export("<!-- úprava _global_den na: den %d | mesiac %d | rok %d -->", _global_vstup_den, _global_vstup_mesiac, _global_vstup_rok);
		_global_den.den = _global_vstup_den;
		_global_den.mesiac = _global_vstup_mesiac;
		_global_den.rok = _global_vstup_rok;
	}

	if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): keďže sme v _global_opt_batch_monthly == ANO a export_monthly_druh (%d) > 2, nebudeme exportovať tabuľku...\n", typ, export_monthly_druh);
	}

	if(typ == EXPORT_DNA_VIAC_DNI_TXT){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): kvôli typu nebudeme exportovať tabuľku...\n", typ);
	}

	if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
		Log("--- _export_rozbor_dna_buttons_dni(): idem tlacit buttony...\n");
		short int _local_rok;

		if(dnes_dnes == ANO){
			Export("<!-- tabuľka s buttonmi predošlý, nasledovný rok/mesiac/deň presunutá pred rozbor daného dňa (teda navrch stránky) (compact) -->\n");
		}
		else{
			Export("<!-- tabuľka s buttonmi predošlý, nasledovný deň (compact) -->\n");
		}

		// tabuľka pre buttony Predchádzajúci/Nasledujúci deň/mesiac/rok a Dnes
		if(som_v_tabulke == ANO){
			Export("\n<table "HTML_ALIGN_CENTER">\n");
			Export("<tr>\n");
		}
		else{
			Export("\n<p>\n");
			Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
		}

		// ---------------------------------------------------
		// vypočítanie predošlého dňa
		zmena_mesiaca = NIE;
		_local_rok = _global_den.rok;
		if(_global_den.den == 1){
			zmena_mesiaca = ANO;
			if(_global_den.mesiac - 1 == MES_JAN){ // 01JAN
				datum.mesiac = 12;
				_local_rok = _global_den.rok - 1;
			}
			else{
				datum.mesiac = _global_den.mesiac - 1;
			}
			datum.den = pocet_dni[datum.mesiac - 1];
		}
		else{
			datum.den = _global_den.den - 1;
			datum.mesiac = _global_den.mesiac;
		}

		if(zmena_mesiaca == ANO){
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_SIMPLE""STR_PATH_SEPARATOR_HTML, _local_rok % 100, datum.mesiac, nazov_mes[datum.mesiac - 1]);
			}
			else{
				// EXPORT_DATE_FULL
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_FULL""STR_PATH_SEPARATOR_HTML, _local_rok, datum.mesiac, nazov_mesiaca_asci(datum.mesiac - 1));
			}
		}// if(zmena_mesiaca == ANO)
		else{
			mystrcpy(str_month, STR_EMPTY, SMALL);
		}
		Log("str_month == %s\n", str_month);

		// << predošlý deň -- button
		if(_global_opt_batch_monthly == NIE){
			sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
		}// if(_global_opt_batch_monthly == NIE)
		else{
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_SIMPLE".htm", str_month, _local_rok % 100, datum.mesiac, datum.den);
			}
			else{
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_FULL".htm", str_month, _local_rok, datum.mesiac, datum.den);
			}
		}
		Log("\treťazec pom == %s\n", pom);
		if(som_v_tabulke == ANO){
			Export("<td "HTML_ALIGN_RIGHT">");
			Export_HtmlForm(pom);
			// 2003-07-16; < zmenene na &lt; 2007-03-19: zmenené na HTML_LEFT_ARROW; 2011-01-26: zmenené na HTML_LEFT_ARROW_SINGLE
			Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\""HTML_LEFT_ARROW_SINGLE" ", html_button_predchadzajuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			// použijeme vždy, nielen keď if(dnes_dnes == ANO)
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
			Export((char *)html_button_predchadzajuci_[_global_jazyk]);
			Export(" ");
#endif
			Export((char *)html_text_den[_global_jazyk]);
			// 2012-10-02: pre kompaktné nepoužívame toto: Export(_vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			Export(" \">\n");
			Export("</form>");
			Export("</td>\n");
		}
		else{
			Export("<a href=\"%s\">"HTML_LEFT_ARROW_SINGLE" %s %s %s</a>\n", pom, html_button_predchadzajuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
		}

		// ---------------------------------------------------
		// 2007-03-19: Dorobené tlačidlo pre dnešok
		// 2011-10-07: presunuté do samostatnej funkcie
		_export_rozbor_dna_buttons_dni_dnes(dnes_dnes, som_v_tabulke, pom2, NIE);

		// ---------------------------------------------------
		// vypočítanie nasledujúceho dňa
		zmena_mesiaca = NIE;
		_local_rok = _global_den.rok;
		if(_global_den.den == pocet_dni[_global_den.mesiac - 1]){
			zmena_mesiaca = ANO;
			datum.den = 1;
			if(_global_den.mesiac - 1 == MES_DEC){
				datum.mesiac = 1;
				_local_rok = _global_den.rok + 1;
			}
			else{
				datum.mesiac = _global_den.mesiac + 1;
			}
		}
		else{
			datum.den = _global_den.den + 1;
			datum.mesiac = _global_den.mesiac;
		}

		if(zmena_mesiaca == ANO){
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_SIMPLE""STR_PATH_SEPARATOR_HTML, _local_rok % 100, datum.mesiac, nazov_mes[datum.mesiac - 1]);
			}
			else{
				// EXPORT_DATE_FULL
				sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_FULL""STR_PATH_SEPARATOR_HTML, _local_rok, datum.mesiac, nazov_mesiaca_asci(datum.mesiac - 1));
			}
		}// if(zmena_mesiaca == ANO)
		else{
			mystrcpy(str_month, STR_EMPTY, SMALL);
		}
		Log("str_month == %s\n", str_month);

		// >> nasledujúci deň -- button
		if(_global_opt_batch_monthly == NIE){
			sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
		}// if(_global_opt_batch_monthly == NIE)
		else{
			if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_SIMPLE".htm", str_month, _local_rok % 100, datum.mesiac, datum.den);
			}
			else{
				sprintf(pom, "%s"FILENAME_EXPORT_DATE_FULL".htm", str_month, _local_rok, datum.mesiac, datum.den);
			}
		}
		Log("\treťazec pom == %s\n", pom);
		if(som_v_tabulke == ANO){
			Export("<td "HTML_ALIGN_LEFT">");
			Export_HtmlForm(pom);
			// 2003-07-16; > zmenene na &gt; 2007-03-19: zmenené na HTML_RIGHT_ARROW; 2011-01-26: zmenené na HTML_RIGHT_ARROW_SINGLE
			Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\"", html_button_nasledujuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			// if(dnes_dnes == ANO){
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
			Export((char *)html_button_nasledujuci_[_global_jazyk]);
			Export(" ");
#endif
			Export((char *)html_text_den[_global_jazyk]);
			// Export(_vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			Export(" "HTML_RIGHT_ARROW_SINGLE"\">\n");
			Export("</form>");
			Export("</td>\n");
			Export("</tr>\n");
		}
		else{
			Export("<a href=\"%s\">%s %s %s "HTML_RIGHT_ARROW_SINGLE"</a>\n", pom, html_button_nasledujuci_[_global_jazyk], html_text_den[_global_jazyk], _vytvor_string_z_datumu(datum.den, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
			Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
		}

		if(dnes_dnes == ANO){
			// ---------------------------------------------------
			// << predošlý mesiac
			if((_global_den.mesiac - 1) == MES_JAN){
				datum.mesiac = MES_DEC + 1;
				_local_rok = _global_den.rok - 1;
			}
			else{
				datum.mesiac = _global_den.mesiac - 1;
				_local_rok = _global_den.rok;
			}
			if(_global_den.den > pocet_dni[datum.mesiac - 1]){
				datum.den = pocet_dni[datum.mesiac - 1];
			}
			else{
				datum.den = _global_den.den;
			}

			// predošlý mesiac -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR);
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<tr>\n");
					Export("<td "HTML_ALIGN_RIGHT">");
					Export_HtmlForm(pom);
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\""HTML_LEFT_ARROW" ", html_button_predchadzajuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_predchadzajuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_mesiac[_global_jazyk]);
					Export(" \">\n");
					Export("</form>");
					Export("</td>\n");
				}
				else{
					Export("<a href=\"%s\">"HTML_LEFT_ARROW" %s %s %s</a>\n", pom, html_button_predchadzajuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}

			// možnosť skryť všetky tlačidlá (celý komponent)

			// obnovenie na "dnes"
			datum.den = _global_den.den;
			datum.mesiac = _global_den.mesiac;
			_local_rok = _global_den.rok;

			if(_global_opt_batch_monthly == NIE){

				// najprv upravíme o2
				_global_opt_orig = _global_opt[OPT_2_HTML_EXPORT]; // backup pôvodnej hodnoty
				// nastavenie parametra o1: pridáme BIT_OPT_2_HIDE_NAVIG_BUTTONS pre alternatívnu psalmódiu
				if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_NAVIG_BUTTONS) != BIT_OPT_2_HIDE_NAVIG_BUTTONS){
					Log("Pre option %d nastavujem bit pre '%d'\n", OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_NAVIG_BUTTONS);
					_global_opt[OPT_2_HTML_EXPORT] += BIT_OPT_2_HIDE_NAVIG_BUTTONS;
				}// zmena: použitie doplnkovej psalmódie
				else{
					Log("Pre option %d ruším bit pre '%d'\n", OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_NAVIG_BUTTONS);
					_global_opt[OPT_2_HTML_EXPORT] -= BIT_OPT_2_HIDE_NAVIG_BUTTONS;
				}

				mystrcpy(pom2, STR_EMPTY, MAX_STR);
				mystrcpy(pom3, STR_EMPTY, MAX_STR);
				// teraz vytvoríme reťazec s options
				prilep_request_options(pom2, pom3);

				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);

				Export("<td "HTML_ALIGN_CENTER" "HTML_CLASS_SMALL">\n");
				Export("<a href=\"%s\" "HTML_CLASS_QUIET">(%s)</a>"HTML_SPAN_END, pom, html_text_option_skryt[_global_jazyk]);
				Export("</td>\n");

				// napokon o2 vrátime späť
				_global_opt[OPT_2_HTML_EXPORT] = _global_opt_orig; // restore pôvodnej hodnoty

				mystrcpy(pom2, STR_EMPTY, MAX_STR);
				mystrcpy(pom3, STR_EMPTY, MAX_STR);
				// teraz vytvoríme reťazec s options (revert)
				prilep_request_options(pom2, pom3);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR);
			}

			// ---------------------------------------------------
			// >> nasledovný mesiac
			if((_global_den.mesiac - 1) == MES_DEC){
				datum.mesiac = MES_JAN + 1;
				_local_rok = _global_den.rok + 1;
			}
			else{
				datum.mesiac = _global_den.mesiac + 1;
				_local_rok = _global_den.rok;
			}
			if(_global_den.den > pocet_dni[datum.mesiac - 1]){
				datum.den = pocet_dni[datum.mesiac - 1];
			}
			else{
				datum.den = _global_den.den;
			}

			// >> nasledovný mesiac -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR);
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_LEFT">");
					Export_HtmlForm(pom);
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %s\" value=\"", html_button_nasledujuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_nasledujuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_mesiac[_global_jazyk]);
					Export(" "HTML_RIGHT_ARROW"\">\n");
					Export("</form>");
					Export("</td>\n");
					Export("</tr>\n");
				}
				else{
					Export("<a href=\"%s\">"HTML_LEFT_ARROW" %s %s %s</a>\n", pom, html_button_nasledujuci_[_global_jazyk], html_text_mesiac[_global_jazyk], _vytvor_string_z_datumu(VSETKY_DNI, datum.mesiac, _local_rok, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}

		}// predošlý, nasledovný mesiac -- len pre "dnes"

		if(dnes_dnes == ANO){
			// ---------------------------------------------------
			// vypočítanie toho istého dňa v predošlom roku
			datum.den = _global_den.den;
			datum.mesiac = _global_den.mesiac;
			_local_rok = _global_den.rok - 1;
			if((_global_den.den == 29) && (_global_den.mesiac - 1 == MES_FEB)){ // 29FEB
				if(!prestupny(_local_rok)){
					datum.den = 28;
				}
			}

			// << predošlý rok -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR); // 2009-08-12: možno v budúcnosti by sa mohol dať odkaz na adresár s rok+mesiacom predošlého roka
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<tr>\n");
					Export("<td "HTML_ALIGN_RIGHT">");
					Export_HtmlForm(pom);
					// 2003-07-16; << zmenene na &lt;&lt; 2007-03-19: zmenené na HTML_LEFT_ARROW; 2011-01-26: zmenené na HTML_LEFT_ARROW_HUGE
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %d\" value=\""HTML_LEFT_ARROW_HUGE" ", html_button_predchadzajuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_predchadzajuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_rok[_global_jazyk]);
					Export(" \">\n");
					Export("</form>");
					Export("</td>\n");
				}
				else{
					Export("<a href=\"%s\">"HTML_LEFT_ARROW_HUGE" %s %s %d</a>\n", pom, html_button_predchadzajuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}

			Export("<td> </td>");

			// ---------------------------------------------------
			// vypočítanie toho istého dňa v nasledujúcom roku
			datum.den = _global_den.den;
			datum.mesiac = _global_den.mesiac;
			_local_rok = _global_den.rok + 1;
			if((_global_den.den == 29) && (_global_den.mesiac - 1 == MES_FEB)){ // 29FEB
				if(!prestupny(_local_rok)){
					datum.den = 28;
				}
			}
			// nasledujúci rok -- button
			if(_global_opt_batch_monthly == NIE){
				sprintf(pom, HTML_LINK_CALL1, script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, datum.den, STR_MESIAC, datum.mesiac, STR_ROK, _local_rok, pom2);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				mystrcpy(pom, STR_EMPTY, MAX_STR);
				// 2009-08-12: možno v budúcnosti by sa mohol dať odkaz na adresár s rok+mesiacom nasledovného roka
			}
			if(_global_opt_batch_monthly == NIE){
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_LEFT">");
					Export_HtmlForm(pom);
					// 2003-07-16; >> zmenene na &gt;&gt; 2007-03-19: zmenené na HTML_RIGHT_ARROW; 2011-01-26: zmenené na HTML_RIGHT_ARROW_HUGE
					Export("<"HTML_FORM_INPUT_SUBMIT0" title=\"%s %s %d\" value=\"", html_button_nasledujuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
#ifdef VYPISOVAT_PREDCHADZAJUCI_NASLEDUJUCI_BUTTON
					Export((char *)html_button_nasledujuci_[_global_jazyk]);
					Export(" ");
#endif
					Export((char *)html_text_rok[_global_jazyk]);
					Export(" "HTML_RIGHT_ARROW_HUGE"\">\n");
					Export("</form>");
					Export("</td>\n");
				}
				else{
					Export("<a href=\"%s\">%s %s %d "HTML_RIGHT_ARROW_HUGE"</a>\n", pom, html_button_nasledujuci_[_global_jazyk], html_text_rok[_global_jazyk], _local_rok);
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}
			}
		}// predošlý, nasledovný rok -- len pre "dnes"

		if(som_v_tabulke == ANO){
			Export("</tr>\n");
			Export("</table>\n");
		}

		// 2007-08-15: pokus o krajšie zobrazenie formou kalendára presunutý do _export_rozbor_dna_kalendar()

	}// if(typ)
	else{
		// inak buttony nedávam
		Log("--- _export_rozbor_dna_buttons_dni(): buttony nedávam...\n");
	}

	if((_global_pocet_navigacia > 1) || (_global_pocet_volani_interpretTemplate >= 2)){
		// najprv ostatné, potom dnes
		if((query_type == PRM_DATUM) && (_global_modlitba != MODL_NEURCENA)){
			_export_rozbor_dna_buttons_dni_dnes(ANO /* dnes_dnes */, NIE /* som_v_tabulke */, pom2, ANO /* zobraz_odkaz_na_skrytie */);
		}
	}// if((_global_pocet_navigacia > 1) || (_global_pocet_volani_interpretTemplate >= 2))

	// späť pôvodné nastavenia (pre dnes_dnes != ANO boli zmenené)
	_global_den.den = _orig_den;
	_global_den.mesiac = _orig_mesiac;
	_global_den.rok = _orig_rok;
#ifdef OS_Windows_Ruby
	Export("\n<!--buttons/dni:end-->\n");
#endif
	Log("--- _export_rozbor_dna_buttons_dni_compact(typ == %d) -- end\n", typ);
}// _export_rozbor_dna_buttons_dni_compact()

// 2013-12-02: enable to display date-navigation buttons in compact mode also for online web
void _export_rozbor_dna_buttons_dni_call(short int typ, short int dnes_dnes /* = ANO */){
	if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTONY_USPORNE) == BIT_OPT_2_BUTTONY_USPORNE){
		//bolo: #if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
		_export_rozbor_dna_buttons_dni_compact(typ, dnes_dnes);
	}
	else{
		_export_rozbor_dna_buttons_dni_orig(typ, dnes_dnes);
	}
}// _export_rozbor_dna_buttons_dni_call()

//---------------------------------------------------------------------
// _export_rozbor_dna_kalendar(int, int)
//
// typ - ako v _export_rozbor_dna()
//
// exportuje kalendárik
// vytvorená 2007-08-15 odštiepením konca kódu z funkcie _export_rozbor_dna_buttons_dni()
void _export_rozbor_dna_kalendar(short int typ){
	// 2012-10-01: zobrazujeme, iba ak nie je explicitne vyžiadané skrývanie
	if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_KALENDAR) != BIT_OPT_2_HIDE_KALENDAR){
		_export_rozbor_dna_kalendar_orig(typ);
	}
	else{
		// Export("\n<!--hide calendar-->\n");
		char show[SMALL] = STR_EMPTY;
		char hide[SMALL] = STR_EMPTY;
		sprintf(show, "%s %s", html_text_option_zobrazit[_global_jazyk], html_text_kalendar[_global_jazyk]);
		sprintf(hide, "%s %s", html_text_option_skryt[_global_jazyk], html_text_kalendar[_global_jazyk]);
		char before[SMALL] = STR_EMPTY;
		sprintf(before, "<p "HTML_ALIGN_CENTER" "HTML_CLASS_SMALL">");
		char after[SMALL] = STR_EMPTY;
		mystrcpy(after, "</p>", SMALL);
		_export_link_show_hide(OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_KALENDAR, show, hide, (char *)STR_EMPTY, (char *)HTML_CLASS_QUIET, before, after, (char *)STR_EMPTY, (char *)STR_EMPTY);
	}
}// _export_rozbor_dna_kalendar()

void _export_rozbor_dna_kalendar_orig(short int typ){
	Log("--- _export_rozbor_dna_kalendar_orig(typ == %d) -- begin\n", typ);
	Export("\n<!--kalendar-->\n");

	if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT)){
		Log("--- _export_rozbor_dna_kalendar_orig(): idem tlacit kalendar...\n");
		short int i, j, k;

		// 2013-01-08: hypertextový odkaz "(skryť)" sa neexportuje pre batch mód; nestačí porovnanie query_type != PRM_BATCH_MODE, pretože sa volá napr. "..\breviar.exe -i..\..\..\breviar.sk\include\ -qpdt -d6 -m1 -r2013 -u0 -e130106.htm -00 -15184 -2224 -30 -40 -jsk -M2 -I1301.htm"
		if(_global_opt_batch_monthly != ANO && query_type != PRM_BATCH_MODE){
			char before[SMALL] = STR_EMPTY;
			sprintf(before, "<p "HTML_ALIGN_CENTER" "HTML_CLASS_SMALL">");
			char after[SMALL] = STR_EMPTY;
			mystrcpy(after, "</p>", SMALL);
			_export_link_show_hide(OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_KALENDAR, (char *)html_text_option_zobrazit[_global_jazyk], (char *)html_text_option_skryt[_global_jazyk], (char *)STR_EMPTY, (char *)HTML_CLASS_QUIET, before, after, (char *)STR_EMPTY, (char *)STR_EMPTY);
		}

		char pom2[MAX_STR];
		mystrcpy(pom2, STR_EMPTY, MAX_STR);
		char pom3[MAX_STR];
		mystrcpy(pom3, STR_EMPTY, MAX_STR);

		// teraz vytvoríme reťazec s options
		prilep_request_options(pom2, pom3);

		Export("\n<div "HTML_CLASS_CALENDAR">\n");
		// zoznam dní vo forme kalendárika
		Export("\n<table "HTML_ALIGN_CENTER">\n");

		Export("<tr "HTML_ALIGN_CENTER">\n<th colspan=\"7\">\n");
		// nadpis tabuľky v tvare: << mesiac rok >>

		// << predošlý mesiac
		if((_global_den.mesiac - 1) == MES_JAN){
			j = MES_DEC + 1;
			k = _global_den.rok - 1;
		}
		else{
			j = _global_den.mesiac - 1;
			k = _global_den.rok;
		}
		if(_global_den.den > pocet_dni[j - 1])
			i = pocet_dni[j - 1];
		else
			i = _global_den.den;
		Vytvor_global_link(i, j, k, LINK_DEN_MESIAC_PREDOSLY, NIE);
		Export("<"HTML_CALENDAR_HEADING">%s"HTML_SPAN_END, _global_link);

		Export(HTML_NONBREAKING_SPACE); // oddelenie << a mesiaca

		// názov mesiaca
		Vytvor_global_link(VSETKY_DNI, _global_den.mesiac, _global_den.rok, LINK_DEN_MESIAC, NIE);
		Export("<"HTML_CALENDAR_HEADING">%s"HTML_SPAN_END, _global_link);

		Export(HTML_NONBREAKING_SPACE); // oddelenie mesiaca a roka

		// rok
		if(_global_opt_batch_monthly == NIE){
			Vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, _global_den.rok, LINK_DEN_MESIAC, NIE);
		}// if(_global_opt_batch_monthly == NIE)
		else{
			// 2009-08-12: pre batch mód export vytlačíme len rok bez linku
			sprintf(_global_link, "%d", _global_den.rok);
		}// else if(_global_opt_batch_monthly == NIE)
		Export("<"HTML_CALENDAR_HEADING">%s"HTML_SPAN_END, _global_link);

		Export(HTML_NONBREAKING_SPACE); // oddelenie roka a >>

		// >> nasledovný mesiac
		if((_global_den.mesiac - 1) == MES_DEC){
			j = MES_JAN + 1;
			k = _global_den.rok + 1;
		}
		else{
			j = _global_den.mesiac + 1;
			k = _global_den.rok;
		}
		if(_global_den.den > pocet_dni[j - 1])
			i = pocet_dni[j - 1];
		else
			i = _global_den.den;
		Vytvor_global_link(i, j, k, LINK_DEN_MESIAC_NASLEDOVNY, NIE);
		Export("<"HTML_CALENDAR_HEADING">%s"HTML_SPAN_END, _global_link);

		Export("</th>\n</tr>\n");

		// prvý riadok tabuľky "hlavička" so skratkami dní v týždni
		Export("<tr><!--(hlavička)-->\n");
		for(k = DEN_NEDELA; k <= DEN_SOBOTA; k++){
			Export("<td "HTML_ALIGN_RIGHT"><"HTML_CALENDAR_DAYS">%s"HTML_SPAN_END"</td>", (char *)nazov_Dn(k));
		}
		Export("</tr>\n");

		Export("<tr><!--(prvý riadok)-->\n");

		// prípadné prázdne bunky
		j = ((1 + _global_den.denvt - _global_den.den) MOD 7);
		if(j < 0)
			j += 7;
		if(j > 0){
			for(k = 0; k < j; k++){
				Export("<td>"HTML_NONBREAKING_SPACE"<!--_(%s)_--></td>", (char *)nazov_Dn(k));
			}
		}

		// jednotlivé dni mesiaca
		for(i = 1; i <= pocet_dni[_global_den.mesiac - 1]; i++){
			if(i == _global_den.den){
				if(((i + _global_den.denvt - _global_den.den) MOD 7) == 0){
					Export("</tr>\n");
					Export("<tr><!--(ďalší riadok)-->\n");
					// nedeľa
					Export("<td "HTML_ALIGN_RIGHT"><"HTML_CALENDAR_TODAY_SUNDAY">%d"HTML_SPAN_END"</td> ", i);
				}
				else{
					Export("<td "HTML_ALIGN_RIGHT"><"HTML_CALENDAR_TODAY">%d"HTML_SPAN_END"</td> ", i);
				}
			}
			else{
				if(((i + _global_den.denvt - _global_den.den) MOD 7) == 0){
					vytvor_global_link_class(i, _global_den.mesiac, _global_den.rok, LINK_DEN, NIE, (char *)HTML_CLASS_NAME_CALENDAR_SUNDAY);
					Export("</tr>\n");
					Export("<tr><!--(ďalší riadok)-->\n");
					// nedeľa
					Export("<td "HTML_ALIGN_RIGHT">%s</td> ", _global_link);
				}
				else{
					vytvor_global_link_class(i, _global_den.mesiac, _global_den.rok, LINK_DEN, NIE, (char *)HTML_CLASS_NAME_CALENDAR_DAY);
					Export("<td "HTML_ALIGN_RIGHT">%s</td> ", _global_link);
				}
			}
		}

		// prípadné prázdne bunky
		j = ((pocet_dni[_global_den.mesiac - 1] + _global_den.denvt - _global_den.den) MOD 7);
		if(j < 0)
			j += 7;
		if(j < 6){
			for(k = j + 1; k < 7; k++){
				Export("<td>"HTML_NONBREAKING_SPACE"<!--_(%s)_--></td>", (char *)nazov_Dn(k));
			}
		}

		Export("</tr>\n");
		Export("</table>\n");
		Export(HTML_DIV_END"\n");
	}// if(typ)
	else{
		// inak kalendar nedavam
		Log("--- _export_rozbor_dna_kalendar(): kalendár nedávam...\n");
	}

	Export("\n");
	Log("--- _export_rozbor_dna_kalendar_orig(typ == %d) -- end\n", typ);
}// _export_rozbor_dna_kalendar_orig()

// 2013-11-28: vytvorené
void _export_main_formular_checkbox(short int opt, short int bit_opt, const char * str_modl_optf, const char * html_text_opt_description, const char * html_text_opt_description_explain, short int line_break_before = ANO){
	Log("_export_main_formular_checkbox(%d, %d, %s, %s, %s) -- begin...\n", opt, bit_opt, str_modl_optf, html_text_opt_description, html_text_opt_description_explain);
	char html_label[MAX_STR];
	mystrcpy(html_label, html_text_opt_description, MAX_STR);
#if defined(OS_Windows_Ruby) || defined(DEBUG)
	char html_label_debug[SMALL];
	sprintf(html_label_debug, " [%s]", str_modl_optf);
	strcat(html_label, html_label_debug);
#endif

	// pole (checkbox) WWW_/str_modl_optf
	if(line_break_before == ANO){
		Export(HTML_CRLF_LINE_BREAK);
	}
	Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", str_modl_optf, NIE);
	Export("<"HTML_FORM_INPUT_CHECKBOX" name=\"%s\" value=\"%d\" title=\"%s\"%s>\n", str_modl_optf, ANO, html_text_opt_description_explain, ((_global_optf[opt] & bit_opt) == bit_opt)? html_option_checked: STR_EMPTY);
	Export("<"HTML_SPAN_TOOLTIP">%s"HTML_SPAN_END, html_text_opt_description_explain, html_label);

	Log("_export_main_formular_checkbox(%d, %d, %s, %s, %s) -- end.\n", opt, bit_opt, str_modl_optf, html_text_opt_description, html_text_opt_description_explain);
}// _export_main_formular_checkbox()

void _export_main_formular_checkbox_slash(short int opt, short int bit_opt, const char * str_modl_optf, const char * html_text_opt_description1, const char * html_text_opt_description2, short int line_break_before = ANO){
	Log("_export_main_formular_checkbox(%d, %d, %s, %s / %s) -- begin...\n", opt, bit_opt, str_modl_optf, html_text_opt_description1, html_text_opt_description2);
	char html_label[MAX_STR];
	sprintf(html_label, "%s%s%s", html_text_opt_description1, HTML_LINE_BREAK_SPACE_LOONG, html_text_opt_description2);

	_export_main_formular_checkbox(opt, bit_opt, str_modl_optf, html_label, STR_EMPTY, line_break_before);
	
	Log("_export_main_formular_checkbox(%d, %d, %s, %s / %s) -- end.\n", opt, bit_opt, str_modl_optf, html_text_opt_description1, html_text_opt_description2);
}// _export_main_formular_checkbox()

//---------------------------------------------------------------------
//
// _export_main_formular();
// 2006-02-02 (doma pri chrípke)
// vypluje celý formulár, dolnú časť, ktorá pôvodne bola v _main_dnes(), ktorý obsahuje:
// -- okienka pre deň, mesiac, rok; 
// -- okienko pre (analýzu) rok;
// -- okienko pre sviatok,
// -- okienko pre liturgický kalendár,
// atď. a to kvôli tomu, aby sa to eventuálne dalo použiť aj pre iný deň ako "dnes".
void _export_main_formular(short int den, short int mesiac, short int rok, short int denvt){
	// 2006-02-02: premenné z _main_dnes musíme naplniť podľa vstupných hodnôt

	struct tm dnes;
	short int month, day;
	short int lo; // liturgické obdobie
	short int font;

	dnes.tm_mday = den;
	dnes.tm_mon  = mesiac;
	dnes.tm_year = rok;
	dnes.tm_wday = denvt;

	char pom2[MAX_STR];
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	char pom3[MAX_STR];
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	prilep_request_options(pom2, pom3);

	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);

	// 2012-10-03: before, after -- kvôli (skryť), (zobraziť)
	char before[SMALL] = STR_EMPTY;
	sprintf(before, "<"HTML_SPAN_SMALL">");
	char after[SMALL] = STR_EMPTY;
	sprintf(after, HTML_SPAN_END);

	short int zobrazit_moznosti1 = ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_OPTIONS1) != BIT_OPT_2_HIDE_OPTIONS1);
	short int zobrazit_moznosti2 = ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_OPTIONS2) != BIT_OPT_2_HIDE_OPTIONS2);

#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
	Export("<table "HTML_ALIGN_CENTER"><tr>\n<td>\n");
	// 2012-07-23, doplnené pre Ruby
	// ak by sa malo použiť "dnes": Export("\n<form action=\"%s?%s=%s%s\" method=\"post\">\n", uncgi_name, STR_QUERY_TYPE, STR_PRM_DNES, pom2);
	sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s", script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, _global_den.den, STR_MESIAC, _global_den.mesiac, STR_ROK, _global_den.rok, pom2);
	// Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n", script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, _global_den.den, STR_MESIAC, _global_den.mesiac, STR_ROK, _global_den.rok, pom2);
	Export_HtmlFormPOST(action);

	Export("<!-- combobox pre výber jazyka -->\n");

	Export("<"HTML_SPAN_TOOLTIP">%s:"HTML_SPAN_END, html_text_jazyk_explain[_global_jazyk], html_text_jazyk[_global_jazyk]);
	Export(" ");
	// drop-down list pre výber jazyka
	// pole WWW_JAZYK
	Export("<select name=\"%s\" title=\"%s\">\n", STR_JAZYK, html_text_jazyk_explain[_global_jazyk]);

	for(int i = 0; i <= POCET_JAZYKOV; i++){
		if(i == JAZYK_EN){
			continue;
		}
		if(i == JAZYK_LA){
			continue;
		}
		if(i == JAZYK_UNDEF){
			continue;
		}
#if !defined(OS_Windows_Ruby)
		if(i == JAZYK_CZ_OP){
			continue;
		}
#endif
		Export("<option%s>%s\n", (i != _global_jazyk)? STR_EMPTY: html_option_selected, nazov_jazyka[i]);
	}
	Export("</select>\n");

	Export("<!-- button Nastaviť/Potvrdiť (jazyk)-->\n");
	// button Nastaviť/Potvrdiť
	Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
	Export((char *)HTML_BUTTON_DNES_APPLY_SETTINGS);
	Export("\">");

	Export("</form>\n\n");
	Export("</td>\n</tr>\n</table>\n");
#endif

	// 2006-02-02: prevzatá časť z _main_dnes

	// 2003-07-09, zmenene <center><table> na <table align="center">
	Export("<!--TABLE:BEGIN(options)-->\n");
	Export("\n<table "HTML_ALIGN_CENTER">\n");

	// pokračujem vypísaním formulára
	// 2012-07-23: rozdelenie jednoho formu na dva; prvý použije PRM_DATUM podľa globálneho nastavenia
	// 2012-10-03: export <form> len ak platí: zobrazit_moznosti1
	if(zobrazit_moznosti1){
		sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s", script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, _global_den.den, STR_MESIAC, _global_den.mesiac, STR_ROK, _global_den.rok, pom2);
		// Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n", script_name, STR_QUERY_TYPE, STR_PRM_DATUM, STR_DEN, _global_den.den, STR_MESIAC, _global_den.mesiac, STR_ROK, _global_den.rok, pom2);
		Export_HtmlFormPOST(action);
	}

// -------------------------------------------
	Export("<tr>\n<td>\n");
	Export("<!-- heading -->\n");

	_export_link_show_hide(OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_OPTIONS1, /* opačné nastavenie kvôli špeciálnej podmienke, defaulty */ (char *)html_text_option_zobrazit[_global_jazyk], (char *)html_text_option_skryt[_global_jazyk], (char *)STR_EMPTY, (char *)HTML_CLASS_QUIET, before, after, (char *)STR_EMPTY, (char *)STR_EMPTY);

	Export("<"HTML_SPAN_BOLD_IT">");
	Export((char *)html_text_dalsie_moznosti_1[_global_jazyk]);
	Export(HTML_SPAN_END"\n");
	Export("</td>");
	Export("</tr>\n\n");
	if(zobrazit_moznosti1){ // len ak NIE JE možnosť (skrytie options1) zvolená

		//---------------------------------------------------------------------

		// 2013-03-07: doplnené zobrazenie neviditeľných checkboxov, aby sa po submite zmenených nastavení neresetovalo skrytie/zobrazenie kalendára, navigácie a časti "Ďalšie zobrazenia"
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_HIDE_NAVIG_BUTTONS, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_NAVIG_BUTTONS) == BIT_OPT_2_HIDE_NAVIG_BUTTONS)? ANO: NIE);
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_HIDE_KALENDAR, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_KALENDAR) == BIT_OPT_2_HIDE_KALENDAR)? ANO: NIE);
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_HIDE_OPTIONS2, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_OPTIONS2) == BIT_OPT_2_HIDE_OPTIONS2)? ANO: NIE);

		// rítus - nedá sa vybrať, iba informatívne
		Export("<tr><td>\n");
		Export("%s: %s\n", html_text_ritus[_global_jazyk], nazov_ritu(_global_ritus));
		Export("</td></tr>\n");

		// 2011-01-31: sem presunutá možnosť výberu liturgického kalendára
		// 2011-09-26: predsunutá pred všetky ostatné options (Igor Galád)
		if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_HU)){

			Export("<!-- výber kalendára (propriá) -->\n");

			Export("<tr><td>\n");
			// formular pre výber kalendára

			Export("<"HTML_SPAN_TOOLTIP">%s%s"HTML_SPAN_END, html_text_kalendar_miestny_explain[_global_jazyk], html_text_kalendar_miestny[_global_jazyk], (equals(html_text_kalendar_miestny_post[_global_jazyk], STR_EMPTY)? ": " : ""));
			// 2012-10-01: doplnený zlom riadka pre android
#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
			Export(HTML_CRLF_LINE_BREAK);
#endif

			// drop-down list pre výber kalendára (propriá)
			// pole WWW_KALENDAR
			Export("<select name=\"%s\" title=\"%s\">\n", STR_KALENDAR, html_text_kalendar_miestny_explain[_global_jazyk]);

			if(_global_jazyk == JAZYK_SK){
				Export("<option%s>%s\n", 
					((_global_kalendar == KALENDAR_NEURCENY) || (_global_kalendar == KALENDAR_VSEOBECNY) || (_global_kalendar == KALENDAR_VSEOBECNY_SK))? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[default_kalendar[_global_jazyk]]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_SK_CSSR)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_SK_CSSR]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_SK_SVD)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_SK_SVD]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_SK_OFM)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_SK_OFM]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_SK_SDB)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_SK_SDB]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_SK_OP)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_SK_OP]);
#ifdef OS_Windows_Ruby
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_SK_SJ)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_SK_SJ]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_SK_CM)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_SK_CM]);
#endif
			}// SK
			else if(_global_jazyk == JAZYK_CZ){
				Export("<option%s>%s\n", 
					((_global_kalendar == KALENDAR_NEURCENY) || (_global_kalendar == KALENDAR_VSEOBECNY) || (_global_kalendar == KALENDAR_VSEOBECNY_CZ))? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[default_kalendar[_global_jazyk]]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_CZ_OPRAEM)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_CZ_OPRAEM]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_CZ_OFMCAP)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_CZ_OFMCAP]);
#ifdef OS_Windows_Ruby
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_CZ_SDB)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_CZ_SDB]);
				Export("<option%s>%s\n", 
					(_global_kalendar == KALENDAR_CZ_CSSR)? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[KALENDAR_CZ_CSSR]);
#endif
			}// CZ
			else if(_global_jazyk == JAZYK_HU){
				Export("<option%s>%s\n", 
					((_global_kalendar == KALENDAR_NEURCENY) || (_global_kalendar == KALENDAR_VSEOBECNY) || (_global_kalendar == KALENDAR_VSEOBECNY_HU))? html_option_selected: STR_EMPTY,
					nazov_kalendara_long[default_kalendar[_global_jazyk]]);
			}// HU
			Export("</select>\n");

			if(!(equals(html_text_kalendar_miestny_post[_global_jazyk], STR_EMPTY))){
#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
				Export(HTML_CRLF_LINE_BREAK);
#endif
				Export(html_text_kalendar_miestny_post[_global_jazyk]);
			}

			Export("</td></tr>\n");

		}// if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_CZ))

		// 2013-01-29: predsunuté sem...
		Export("<tr>\n<td>\n");
		// pole (checkbox) WWW_/STR_MODL_OPTF_2_ROZNE_MOZNOSTI
		_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_ROZNE_MOZNOSTI, STR_MODL_OPTF_2_ROZNE_MOZNOSTI, html_text_option2_moznosti[_global_jazyk], html_text_option2_moznosti_explain[_global_jazyk], NIE);

		Export("</td></tr>\n\n");

	// -------------------------------------------
		if((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) != BIT_OPT_2_ROZNE_MOZNOSTI){ // len ak NIE JE táto možnosť (zobrazovanie všeličoho) zvolená
	
			Export("<tr>\n<td>\n");

			Export("<!-- tabuľka pre checkboxy 1 (options pre modlitbu) -->\n");
			// 2011-01-26: doplnená tabuľka pre checkboxy (options pre modlitbu) 
			// 2011-04-13: upravená tak, aby bola delená pre jednotivé skupiny checkboxov
			// 2012-10-01: zobrazuje sa len pre klasický web
			Export("<table "HTML_ALIGN_LEFT">\n"); // table option 1 (1/2)

			Export("<tr><td>\n");
			// formular pre options...

			// option 1: zobraziť nasledovné (nemenné, pevné) súčasti modlitby (používame force opt_1)...
			Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, html_text_option1_nemenne_sucasti_explain[_global_jazyk], html_text_option1_nemenne_sucasti[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_CHV
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_CHVALOSPEVY, STR_MODL_OPTF_1_CHV, html_text_option1_chvalospevy[_global_jazyk], html_text_option1_chvalospevy_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_SL
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_SLAVA_OTCU, STR_MODL_OPTF_1_SL, html_text_option1_slava_otcu[_global_jazyk], html_text_option1_slava_otcu_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_RUB
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_RUBRIKY, STR_MODL_OPTF_1_RUB, html_text_option1_rubriky[_global_jazyk], html_text_option1_rubriky_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_OT
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_OTCENAS, STR_MODL_OPTF_1_OT, html_text_option1_otcenas[_global_jazyk], html_text_option1_otcenas_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_TD
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_TEDEUM, STR_MODL_OPTF_1_TD, html_text_option1_tedeum[_global_jazyk], html_text_option1_tedeum_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_PLNE_RESP
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_PLNE_RESP, STR_MODL_OPTF_1_PLNE_RESP, html_text_option1_plne_resp[_global_jazyk], html_text_option1_plne_resp_explain[_global_jazyk]);

			Export("</td></tr>\n");

			Export("</table>\n"); // table option 1 (1/2)
			Export("</td></tr>\n\n");
		}// tabuľka pre checkboxy 1 (options pre modlitbu)
		else{
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_CHV, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_CHVALOSPEVY) == BIT_OPT_1_CHVALOSPEVY)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_SL, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SLAVA_OTCU) == BIT_OPT_1_SLAVA_OTCU)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_RUB, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_RUBRIKY) == BIT_OPT_1_RUBRIKY)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_OT, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_OTCENAS) == BIT_OPT_1_OTCENAS)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_TD, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_TEDEUM) == BIT_OPT_1_TEDEUM)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_PLNE_RESP, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PLNE_RESP) == BIT_OPT_1_PLNE_RESP)? ANO: NIE);
		}// else: treba nastaviť hidden pre všetky options pre _global_optf

		//---------------------------------------------------------------------

		Export("<tr>\n<td>\n");
		Export("<!-- tabuľka pre checkboxy 2 (options pre modlitbu) -->\n");
		Export("<table "HTML_ALIGN_LEFT">\n"); // table option 1 (2/2)

		Export("<tr><td>\n");
		// formular pre options...

		// option 1: ďalšie bity ovplyvňujúce vygenerovanú modlitbu (používame force opt_1)...
		Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, html_text_option1_dalsie_prepinace_explain[_global_jazyk], html_text_option1_dalsie_prepinace[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_1_ZOBRAZ_SPOL_CAST
		_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_ZOBRAZ_SPOL_CAST, STR_MODL_OPTF_1_ZOBRAZ_SPOL_CAST, html_text_option1_spolc_svaty[_global_jazyk], html_text_option1_spolc_svaty_explain[_global_jazyk]);

		if((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) != BIT_OPT_2_ROZNE_MOZNOSTI){ // len ak NIE JE táto možnosť (zobrazovanie všeličoho) zvolená

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_SPOMIENKA_SPOL_CAST
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_SPOMIENKA_SPOL_CAST, STR_MODL_OPTF_1_SPOMIENKA_SPOL_CAST, html_text_option1_spomienka_spolcast[_global_jazyk], html_text_option1_spomienka_spolcast_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_SKRY_POPIS
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_SKRY_POPIS, STR_MODL_OPTF_1_SKRY_POPIS, html_text_option1_skryt_popis_svaty[_global_jazyk], html_text_option1_skryt_popis_svaty_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_MCD_DOPLNKOVA
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_MCD_DOPLNKOVA, STR_MODL_OPTF_1_MCD_DOPLNKOVA, html_text_option1_mcd_zalmy_ine[_global_jazyk], html_text_option1_mcd_zalmy_ine_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_MCD_ZALTAR_TRI
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_MCD_ZALTAR_TRI, STR_MODL_OPTF_1_MCD_ZALTAR_TRI, html_text_option1_mcd_zalmy_tri[_global_jazyk], html_text_option1_mcd_zalmy_tri_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_ZALM95
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_ZALM95, STR_MODL_OPTF_1_ZALM95, html_text_option1_zalm95[_global_jazyk], html_text_option1_zalm95_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_PROSBY_ZVOLANIE
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_PROSBY_ZVOLANIE, STR_MODL_OPTF_1_PROSBY_ZVOLANIE, html_text_option1_prosby_zvolanie[_global_jazyk], html_text_option1_prosby_zvolanie_explain[_global_jazyk]);

			// pole (checkbox) MODL_OPTF_1_VESP_KRATSIE_PROSBY
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_VESP_KRATSIE_PROSBY, STR_MODL_OPTF_1_VESP_KRATSIE_PROSBY, html_text_option1_vesp_kratsie_prosby[_global_jazyk], html_text_option1_vesp_kratsie_prosby_explain[_global_jazyk]);

			// pole (checkbox) WWW_/STR_MODL_OPTF_1_VIGILIA
			_export_main_formular_checkbox(OPT_1_CASTI_MODLITBY, BIT_OPT_1_PC_VIGILIA, STR_MODL_OPTF_1_VIGILIA, html_text_option1_vigilia[_global_jazyk], html_text_option1_vigilia_explain[_global_jazyk]);
		}
		else{
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_SPOMIENKA_SPOL_CAST, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SPOMIENKA_SPOL_CAST) == BIT_OPT_1_SPOMIENKA_SPOL_CAST)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_SKRY_POPIS, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_SKRY_POPIS) == BIT_OPT_1_SKRY_POPIS)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_MCD_DOPLNKOVA, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_DOPLNKOVA) == BIT_OPT_1_MCD_DOPLNKOVA)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_MCD_ZALTAR_TRI, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_ZALTAR_TRI) == BIT_OPT_1_MCD_ZALTAR_TRI)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_ZALM95, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_ZALM95) == BIT_OPT_1_ZALM95)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_PROSBY_ZVOLANIE, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PROSBY_ZVOLANIE) == BIT_OPT_1_PROSBY_ZVOLANIE)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_VESP_KRATSIE_PROSBY, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_VESP_KRATSIE_PROSBY) == BIT_OPT_1_VESP_KRATSIE_PROSBY)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_1_VIGILIA, ((_global_optf[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_PC_VIGILIA) == BIT_OPT_1_PC_VIGILIA)? ANO: NIE);
		}// else: treba nastaviť hidden pre všetky options pre _global_optf

		if(_global_jazyk != JAZYK_CZ){
			// pole (checkbox) WWW_/STR_MODL_OPTF_2_ALTERNATIVES
			_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_ALTERNATIVES, STR_MODL_OPTF_2_ALTERNATIVES, html_text_option2_alternatives[_global_jazyk], html_text_option2_alternatives_explain[_global_jazyk]);
		}

		Export(HTML_CRLF_LINE_BREAK);
		Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, str_doplnkova_psalmodia[_global_jazyk], str_doplnkova_psalmodia[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_5_DOPLNK_PSALM_122_129
		_export_main_formular_checkbox(OPT_5_ALTERNATIVES, BIT_OPT_5_DOPLNK_PSALM_122_129, STR_MODL_OPTF_5_DOPLNK_PSALM_122_129, html_text_option5_DPsalmZ122_129[_global_jazyk], html_text_option5_DPsalmZ122_129_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_5_DOPLNK_PSALM_126_129
		_export_main_formular_checkbox(OPT_5_ALTERNATIVES, BIT_OPT_5_DOPLNK_PSALM_126_129, STR_MODL_OPTF_5_DOPLNK_PSALM_126_129, html_text_option5_DPsalmZ126_129[_global_jazyk], html_text_option5_DPsalmZ126_129_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_5_DOPLNK_PSALM_127_131
		_export_main_formular_checkbox(OPT_5_ALTERNATIVES, BIT_OPT_5_DOPLNK_PSALM_127_131, STR_MODL_OPTF_5_DOPLNK_PSALM_127_131, html_text_option5_DPsalmZ127_131[_global_jazyk], html_text_option5_DPsalmZ127_131_explain[_global_jazyk]);

		if((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_ROZNE_MOZNOSTI) != BIT_OPT_2_ROZNE_MOZNOSTI){ // len ak NIE JE táto možnosť (zobrazovanie všeličoho) zvolená

			if(_global_jazyk != JAZYK_CZ){

				// posvätné čítanie
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s (%s)"HTML_SPAN_END, nazov_modlitby(MODL_POSV_CITANIE), nazov_modlitby(MODL_POSV_CITANIE), nazov_obdobia(OBD_CEZ_ROK));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_PC
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_PC, STR_MODL_OPTF_5_HYMNUS_PC, html_text_option5_PCHymnusI[_global_jazyk], html_text_option5_PCHymnusII[_global_jazyk]);

				// predpoludním
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, nazov_modlitby(MODL_PREDPOLUDNIM), nazov_modlitby(MODL_PREDPOLUDNIM));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_MCD_PREDPOL
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_MCD_PREDPOL, STR_MODL_OPTF_5_HYMNUS_MCD_PREDPOL, html_text_option5_MCDPredHymnus1[_global_jazyk], html_text_option5_MCDPredHymnus2[_global_jazyk]);

				// napoludnie
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, nazov_modlitby(MODL_NAPOLUDNIE), nazov_modlitby(MODL_NAPOLUDNIE));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_MCD_NAPOL
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_MCD_NAPOL, STR_MODL_OPTF_5_HYMNUS_MCD_NAPOL, html_text_option5_MCDNaHymnus1[_global_jazyk], html_text_option5_MCDNaHymnus2[_global_jazyk]);

				// popoludní
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, nazov_modlitby(MODL_POPOLUDNI), nazov_modlitby(MODL_POPOLUDNI));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_MCD_POPOL
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_MCD_POPOL, STR_MODL_OPTF_5_HYMNUS_MCD_POPOL, html_text_option5_MCDPoHymnus1[_global_jazyk], html_text_option5_MCDPoHymnus2[_global_jazyk]);

				// prvé vešpery
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s (%s/%s)"HTML_SPAN_END, nazov_modlitby(MODL_PRVE_VESPERY), nazov_modlitby(MODL_PRVE_VESPERY), nazov_dna(DEN_NEDELA), nazov_obdobia(OBD_CEZ_ROK));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_1VESP
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_1VESP, STR_MODL_OPTF_5_HYMNUS_1VESP, html_text_option5_1VHymnusNe[_global_jazyk], html_text_option5_1VHymnusPC[_global_jazyk]);

				// kompletórium
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, nazov_modlitby(MODL_KOMPLETORIUM), nazov_modlitby(MODL_KOMPLETORIUM));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_KOMPL
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_KOMPL, STR_MODL_OPTF_5_HYMNUS_KOMPL, html_text_option5_KomplHymnusA[_global_jazyk], html_text_option5_KomplHymnusB[_global_jazyk]);

				// hymny vo Veľkonočnom období

				// posvätné čítanie
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s (%s)"HTML_SPAN_END, nazov_modlitby(MODL_POSV_CITANIE), nazov_modlitby(MODL_POSV_CITANIE), nazov_obdobia(OBD_VELKONOCNE_I));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_VN_PC
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_VN_PC, STR_MODL_OPTF_5_HYMNUS_VN_PC, html_text_option5_PCHymnusVNnedela[_global_jazyk], html_text_option5_PCHymnusVNferia[_global_jazyk]);

				// ranné chvály
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s (%s)"HTML_SPAN_END, nazov_modlitby(MODL_RANNE_CHVALY), nazov_modlitby(MODL_RANNE_CHVALY), nazov_obdobia(OBD_VELKONOCNE_I));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_VN_RCH
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_VN_RCH, STR_MODL_OPTF_5_HYMNUS_VN_RCH, html_text_option5_RChHymnusVNnedela[_global_jazyk], html_text_option5_RChHymnusVNferia[_global_jazyk]);

				// vešpery
				Export(HTML_CRLF_LINE_BREAK);
				Export("<"HTML_SPAN_BOLD_TOOLTIP">%s (%s)"HTML_SPAN_END, nazov_modlitby(MODL_VESPERY), nazov_modlitby(MODL_VESPERY), nazov_obdobia(OBD_VELKONOCNE_I));

				// pole (checkbox) WWW_/STR_MODL_OPTF_5_HYMNUS_VN_VESP
				_export_main_formular_checkbox_slash(OPT_5_ALTERNATIVES, BIT_OPT_5_HYMNUS_VN_VESP, STR_MODL_OPTF_5_HYMNUS_VN_VESP, html_text_option5_VespHymnusVNnedela[_global_jazyk], html_text_option5_VespHymnusVNferia[_global_jazyk]);
			}
		}
		else{
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_DOPLNK_PSALM_122_129, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_122_129) == BIT_OPT_5_DOPLNK_PSALM_122_129)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_DOPLNK_PSALM_126_129, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_126_129) == BIT_OPT_5_DOPLNK_PSALM_126_129)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_DOPLNK_PSALM_127_131, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_DOPLNK_PSALM_127_131) == BIT_OPT_5_DOPLNK_PSALM_127_131)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_PC, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_PC) == BIT_OPT_5_HYMNUS_PC)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_MCD_PREDPOL, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_MCD_PREDPOL) == BIT_OPT_5_HYMNUS_MCD_PREDPOL)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_MCD_NAPOL, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_MCD_NAPOL) == BIT_OPT_5_HYMNUS_MCD_NAPOL)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_MCD_POPOL, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_MCD_POPOL) == BIT_OPT_5_HYMNUS_MCD_POPOL)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_KOMPL, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_KOMPL) == BIT_OPT_5_HYMNUS_KOMPL)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_VN_PC, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_VN_PC) == BIT_OPT_5_HYMNUS_VN_PC)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_VN_RCH, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_VN_RCH) == BIT_OPT_5_HYMNUS_VN_RCH)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_VN_VESP, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_VN_VESP) == BIT_OPT_5_HYMNUS_VN_VESP)? ANO: NIE);
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_5_HYMNUS_1VESP, ((_global_optf[OPT_5_ALTERNATIVES] & BIT_OPT_5_HYMNUS_1VESP) == BIT_OPT_5_HYMNUS_1VESP)? ANO: NIE);
		}// else: treba nastaviť hidden pre všetky options pre _global_optf

		Export("</td></tr>\n");

		Export("</table>\n"); // table option 1 (2/2)
		Export("</td></tr>\n\n");

		//---------------------------------------------------------------------

		// option 3: časti modlitby zo spoločnej časti ... -- alternatíva: doplniť pre každý riadok modlitby
		Export("<tr><td>\n");
		// formulár pre výber preferovanej spoločnej časti
		Export("<"HTML_SPAN_TOOLTIP">%s"HTML_SPAN_END, html_text_spol_casti_vziat_zo_explain[_global_jazyk], html_text_spol_casti_vziat_zo[_global_jazyk]);
		Export("\n");
		// 2012-10-01: doplnený zlom riadka pre android
#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
		Export(HTML_CRLF_LINE_BREAK);
#endif
		Export("<select name=\"%s\" title=\"%s\">\n", STR_MODL_OPTF_3, html_text_spol_casti_vziat_zo_explain[_global_jazyk]);
		for(int i = 0; i < POCET_SPOL_CASTI; i++){
			if((i == MODL_SPOL_CAST_NEURCENA) || (i == MODL_SPOL_CAST_NEBRAT))
				continue;
			if((i == MODL_SPOL_CAST_ZA_ZOSNULYCH) || (i == MODL_SPOL_CAST_POSVIACKA_CHRAMU))
				continue;
			Export("<option%s>%s\n", (i != _global_opt[OPT_3_SPOLOCNA_CAST])? STR_EMPTY: html_option_selected, nazov_spolc(i));
		}
		Export("</select>\n");
		Export("</td></tr>\n");

		//---------------------------------------------------------------------

		Export("<tr>\n<td>\n");
		Export("<!-- tabuľka pre checkboxy 3 (options pre modlitbu) -->\n");
		Export("<table "HTML_ALIGN_LEFT">\n"); // table option 0

		Export("<tr><td>\n");
		// formular pre options...

		// option 0: ďalšie bity ovplyvňujúce vygenerovanú modlitbu (číslovanie veršov, biblické referencie...) (používame force opt_0)...
		Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, html_text_option0_specialne_explain[_global_jazyk], html_text_option0_specialne[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_0_VERSE
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_VERSE, STR_MODL_OPTF_0_VERSE, html_text_option0_verse[_global_jazyk], html_text_option0_verse_explain[_global_jazyk]);

		if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU)){
			// pole (checkbox) WWW_/STR_MODL_OPTF_0_REF
			_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_REFERENCIE, STR_MODL_OPTF_0_REF, html_text_option0_referencie[_global_jazyk], html_text_option0_referencie_explain[_global_jazyk]);
		}// if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))
		else{
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_0_REF, ((_global_optf[OPT_0_SPECIALNE] & BIT_OPT_0_REFERENCIE) == BIT_OPT_0_REFERENCIE)? ANO: NIE);
		}// else: treba nastaviť hidden pre všetky options pre _global_optf

#ifdef BEHAVIOUR_WEB
		// pole (checkbox) WWW_/STR_MODL_OPTF_0_CIT
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_CITANIA, STR_MODL_OPTF_0_CIT, html_text_option0_citania[_global_jazyk], html_text_option0_citania_explain[_global_jazyk]);
#else
		// else: treba nastaviť hidden pre všetky options pre _global_optf
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_0_CIT, ((_global_optf[OPT_0_SPECIALNE] & BIT_OPT_0_CITANIA) == BIT_OPT_0_CITANIA)? ANO: NIE);
#endif

		Export("</td></tr>\n");

		Export("</table>\n"); // table option 0
		Export("</td></tr>\n\n");

		//---------------------------------------------------------------------

		Export("<tr>\n<td>\n");
		Export("<!-- tabuľka pre checkboxy 4 (options pre modlitbu) -->\n");
		Export("<table "HTML_ALIGN_LEFT">\n"); // table option 2

		Export("<tr><td>\n");
		// formular pre options...

		// option 2: bity ovplyvňujúce HTML export -- vygenerované stránky, nie vygenerované modlitby (ISO dátum, button prvé vešpery...) (používame force opt_2)...
		Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, html_text_option2_html_export_explain[_global_jazyk], html_text_option2_html_export[_global_jazyk]);

#ifdef OS_Windows_Ruby
		// pole (checkbox) WWW_/STR_MODL_OPTF_2_ISO_DATUM
		_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_ISO_DATUM, STR_MODL_OPTF_2_ISO_DATUM, html_text_option2_iso_datum[_global_jazyk], html_text_option2_iso_datum_explain[_global_jazyk]);
#else
		// else: treba nastaviť hidden pre všetky options pre _global_optf
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_ISO_DATUM, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_ISO_DATUM) == BIT_OPT_2_ISO_DATUM)? ANO: NIE);
#endif

		// 2011-04-20: pre CZOP zobrazovať aj prepínatko... (možno časom sa podmienka úplne odstráni a bude to zobrazené pre všetky jazyky/systémy)
		if((_global_system == SYSTEM_RUBY) || (_global_jazyk == JAZYK_CZ_OP)){
			// pole (checkbox) WWW_/STR_MODL_OPTF_2_PRVE_VESPERY
			_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_BUTTON_PRVE_VESPERY, STR_MODL_OPTF_2_PRVE_VESPERY, html_text_option2_prve_vespery[_global_jazyk], html_text_option2_prve_vespery_explain[_global_jazyk]);
		}
		else{
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_PRVE_VESPERY, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY)? ANO: NIE);
		}// else: treba nastaviť hidden pre všetky options pre _global_optf

		// pole (checkbox) WWW_/STR_MODL_OPTF_2_FONT_FAMILY
		_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_FONT_FAMILY, STR_MODL_OPTF_2_FONT_FAMILY, html_text_option2_font_family[_global_jazyk], html_text_option2_font_family_explain[_global_jazyk]);
		// drop-down list pre výber názvu písma, len ak je nastavená OPT_2_HTML_EXPORT.BIT_OPT_2_FONT_NAME_CHOOSER
		if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_NAME_CHOOSER) == BIT_OPT_2_FONT_NAME_CHOOSER){
			Export(HTML_CRLF_LINE_BREAK);
			Export(HTML_NONBREAKING_SPACE_LOOONG);
			Export("<"HTML_SPAN_TOOLTIP">%s"HTML_SPAN_END"\n", html_text_font_name_explain[_global_jazyk], html_text_font_name[_global_jazyk]);

			// pole WWW_FONT_NAME
			Export("<select name=\"%s\" title=\"%s\">\n", STR_FONT_NAME, html_text_font_name_explain[_global_jazyk]);
			// FONT_UNDEF neexportujeme
			for(font = FONT_UNDEF + 1; font <= POCET_FONTOV; font++){
				// 2011-05-12: pom2 bolo nastavené funkciou prilep_request_options() a používa sa v ďalšom; použiť môžeme pom3
				mystrcpy(pom3, nazov_fontu[font], MAX_STR);
				if((_global_jazyk != JAZYK_SK) && ((font == FONT_CSS) || (font == FONT_CHECKBOX))){
					if(font == FONT_CSS){
						mystrcpy(pom3, nazov_fontu_CSS[_global_jazyk], MAX_STR);
					}
					else if(font == FONT_CHECKBOX){
						mystrcpy(pom3, nazov_fontu_CHECKBOX[_global_jazyk], MAX_STR);
					}
				}
				Export("<option%s>%s\n", (font == _global_font)? html_option_selected: STR_EMPTY, pom3 /* nazov_fontu[font] */);
			}
			Export("</select>\n");
		}// if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_NAME_CHOOSER) == BIT_OPT_2_FONT_NAME_CHOOSER)

		// drop-down list pre výber veľkosti písma WWW_MODL_OPTF_2_FONT_SIZE, len ak je nastavená OPT_2_HTML_EXPORT.BIT_OPT_2_FONT_NAME_CHOOSER
		if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_SIZE_CHOOSER) == BIT_OPT_2_FONT_SIZE_CHOOSER){
			Export(HTML_CRLF_LINE_BREAK);
			Export(HTML_NONBREAKING_SPACE_LOOONG);
			Export("<"HTML_SPAN_TOOLTIP">%s"HTML_SPAN_END"\n", html_text_font_size_explain[_global_jazyk], html_text_font_size[_global_jazyk]);

			// pole WWW_FONT_SIZE
			Export("<select name=\"%s\" title=\"%s\">\n", STR_FONT_SIZE, html_text_font_size_explain[_global_jazyk]);
			// FONT_SIZE_UNDEF neexportujeme
			for(font = FONT_SIZE_UNDEF + 1; font <= POCET_FONT_SIZE; font++){
				Export("<option%s>%s\n", (font == _global_font_size)? html_option_selected: STR_EMPTY, nazov_font_size(font));
			}
			Export("</select>\n");
		}// if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_SIZE_CHOOSER) == BIT_OPT_2_FONT_SIZE_CHOOSER)

		// pole (checkbox) WWW_/STR_MODL_OPTF_2_NAVIGATION
		_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_NAVIGATION, STR_MODL_OPTF_2_NAVIGATION, html_text_option2_navigation[_global_jazyk], html_text_option2_navigation_explain[_global_jazyk]);

		// 2013-01-29: tu bolo pôvodne MODL_OPTF_2_ROZNE_MOZNOSTI

		if((_global_system == SYSTEM_RUBY) || (_global_jazyk == JAZYK_SK)){
			// pole (checkbox) WWW_/STR_MODL_OPTF_2_TEXT_WRAP
			_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_TEXT_WRAP, STR_MODL_OPTF_2_TEXT_WRAP, html_text_option2_textwrap[_global_jazyk], html_text_option2_textwrap_explain[_global_jazyk]);
		}
		else{
			Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_TEXT_WRAP, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_TEXT_WRAP) == BIT_OPT_2_TEXT_WRAP)? ANO: NIE);
		}// else: treba nastaviť hidden pre všetky options pre _global_optf

		// pole (checkbox) WWW_/STR_MODL_OPTF_2_BUTTONY_USPORNE
		_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_BUTTONY_USPORNE, STR_MODL_OPTF_2_BUTTONY_USPORNE, html_text_option2_buttons_usporne[_global_jazyk], html_text_option2_buttons_usporne_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_2_NOCNY_REZIM
		_export_main_formular_checkbox(OPT_2_HTML_EXPORT, BIT_OPT_2_NOCNY_REZIM, STR_MODL_OPTF_2_NOCNY_REZIM, html_text_option2_nocny_rezim[_global_jazyk], html_text_option2_nocny_rezim_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_0_FONT_NORMAL
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_FONT_NORMAL, STR_MODL_OPTF_0_FONT_NORMAL, html_text_option0_font_normal[_global_jazyk], html_text_option0_font_normal_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_0_FONT_NORMAL
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_BLIND_FRIENDLY, STR_MODL_OPTF_0_BLIND_FRIENDLY, html_text_option0_blind_friendly[_global_jazyk], html_text_option0_blind_friendly_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_0_BUTTONS_ORDER
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_BUTTONS_ORDER, STR_MODL_OPTF_0_BUTTONS_ORDER, html_text_option0_buttons_order[_global_jazyk], html_text_option0_buttons_order_explain[_global_jazyk]);

		Export("</td></tr>\n");

		Export("</table>\n"); // table option 2
		Export("</td></tr>\n\n");

		//---------------------------------------------------------------------

		// 2012-03-15: zasunuté nižšie, aby to nemiatlo (pripomienka MBK)
		Export("<tr>\n<td>\n");
		Export("<!-- tabuľka pre checkboxy 0 (options pre modlitbu) -->\n");
		Export("<table "HTML_ALIGN_LEFT">\n"); // table option 0 (1/2)

		Export("<tr><td>\n");
		// formular pre options...

		// option 0: bity ovplyvňujúce liturgický kalendár (používame force opt_0)...
		Export("<"HTML_SPAN_BOLD_TOOLTIP">%s"HTML_SPAN_END, html_text_option1_kalendar_explain[_global_jazyk], html_text_option1_kalendar[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_0_VERSE
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_ZJAVENIE_PANA_NEDELA, STR_MODL_OPTF_0_ZJAV_NED, html_text_option0_zjv_ne[_global_jazyk], html_text_option0_zjv_ne_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_0_VERSE
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA, STR_MODL_OPTF_0_NAN_NED, html_text_option0_nan_ne[_global_jazyk], html_text_option0_nan_ne_explain[_global_jazyk]);

		// pole (checkbox) WWW_/STR_MODL_OPTF_0_VERSE
		_export_main_formular_checkbox(OPT_0_SPECIALNE, BIT_OPT_0_TELAKRVI_NEDELA, STR_MODL_OPTF_0_TK_NED, html_text_option0_tk_ne[_global_jazyk], html_text_option0_tk_ne_explain[_global_jazyk]);

		Export("</td></tr>\n");

		Export("</table>\n"); // table option 0
		Export("</td></tr>\n\n");

		//---------------------------------------------------------------------

		// 2011-01-28: doplnené podľa buttonov na konci formulára; v podstate vykonajú ten istý efekt
		// 2011-04-11: button "vyčisti" aj tak nefunguje korektne; zapoznámkované (Igor Galád) / odstránené
		Export("<tr>\n<td "HTML_ALIGN_CENTER">\n");
		Export("<!-- riadok pre button Nastaviť/Potvrdiť (options)-->\n");
		// button Nastaviť/Potvrdiť
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)HTML_BUTTON_DNES_APPLY_CHOICES);
		Export("\">");
		Export("</td></tr>\n\n");

		// 2012-07-23: rozdelenie jednoho formu na dva; prvý použije PRM_DATUM podľa globálneho nastavenia
		Export("</form>\n");

	}
	Export("<!--TABLE:END(options)-->\n");
	Export("</table>");

	// -------------------------------------------

	Export("<!--TABLE:BEGIN(choices)-->\n");
	Export("\n<table "HTML_ALIGN_CENTER">\n");

	// 2012-10-03: export <form> len ak platí: zobrazit_moznosti1
	if(zobrazit_moznosti2){
		// 2012-07-23: rozdelenie jednoho formu na dva; prvý použije PRM_DATUM podľa globálneho nastavenia
		sprintf(action, "%s?%s", uncgi_name, pom2);
		// Export("\n<form action=\"%s?%s\" method=\"post\">\n", uncgi_name, pom2);
		Export_HtmlFormPOST(action);
	}
/*
	// -------------------------------------------
	Export("<tr>\n<td>\n");
	Export("<!-- prázdny riadok -->\n"HTML_NONBREAKING_SPACE"\n");
	Export("</td>");
	Export("</tr>\n\n");
*/
	// -------------------------------------------
	Export("<tr>\n<td>\n");
	Export("<!-- heading -->\n");

	_export_link_show_hide(OPT_2_HTML_EXPORT, BIT_OPT_2_HIDE_OPTIONS2, /* opačné nastavenie kvôli špeciálnej podmienke, defaulty */ (char *)html_text_option_zobrazit[_global_jazyk], (char *)html_text_option_skryt[_global_jazyk], (char *)STR_EMPTY, (char *)HTML_CLASS_QUIET, before, after, (char *)STR_EMPTY, (char *)STR_EMPTY);

	Export("<"HTML_SPAN_BOLD_IT">");
	Export((char *)html_text_dalsie_moznosti_2[_global_jazyk]);
	Export(HTML_SPAN_END"\n");
	Export("</td>");
	Export("</tr>\n\n");
	if(zobrazit_moznosti2){ // len ak NIE JE možnosť (skrytie options2) zvolená

		// 2013-03-07: doplnené zobrazenie neviditeľných checkboxov
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_HIDE_NAVIG_BUTTONS, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_NAVIG_BUTTONS) == BIT_OPT_2_HIDE_NAVIG_BUTTONS)? ANO: NIE);
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_HIDE_KALENDAR, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_KALENDAR) == BIT_OPT_2_HIDE_KALENDAR)? ANO: NIE);
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%d\">\n", STR_MODL_OPTF_2_HIDE_OPTIONS1, ((_global_optf[OPT_2_HTML_EXPORT] & BIT_OPT_2_HIDE_OPTIONS1) == BIT_OPT_2_HIDE_OPTIONS1)? ANO: NIE);

		// -------------------------------------------
		Export("<tr>\n<td>\n");

		Export("<!--TABLE:BEGIN(PRM_DATUM)-->\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td>\n");

		short int radio_checked = NIE;

#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
#else
		// formular pre PRM_DATUM
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>", STR_QUERY_TYPE, STR_PRM_DATUM, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td>\n");
	
		Export("<td "HTML_ALIGN_LEFT">\n");
	
		if(strlen(html_text_modlitby_pre_den[_global_jazyk]) > 0){
			// Export(HTML_NONBREAKING_SPACE); // netreba, je to v tabuľke
			Export((char *)html_text_modlitby_pre_den[_global_jazyk]);
			Export(" \n");
		}

		if(format_datumu[_global_jazyk] == FORMAT_DATUMU_ROK_MESIAC_DEN){
			// pole WWW_ROK
			Export("<"HTML_FORM_INPUT_TEXT_ROK" name=\"%s\" value=\"%d\" />\n", STR_ROK, dnes.tm_year);

			// pole WWW_MESIAC
			Export("<select name=\"%s\">\n", STR_MESIAC);
			for(month = 1; month < 13; month++){
				Export("<option%s>%s\n", (month == dnes.tm_mon)? html_option_selected: STR_EMPTY, nazov_mesiaca(month - 1));
			}
			Export("\n</select>\n");

			// pole WWW_DEN
			Export("<select name=\"%s\">\n", STR_DEN);
			for(day = 1; day < 32; day++){
				Export("<option%s>%d\n", (day == dnes.tm_mday)? html_option_selected: STR_EMPTY, day);
			}
			Export("\n</select>.\n");

		}// FORMAT_DATUMU_ROK_MESIAC_DEN
		else if(format_datumu[_global_jazyk] == FORMAT_DATUMU_MESIAC_DEN_ROK){
			// pole WWW_MESIAC
			Export("<select name=\"%s\">\n", STR_MESIAC);
			for(month = 1; month < 13; month++){
				Export("<option%s>%s\n", (month == dnes.tm_mon)? html_option_selected: STR_EMPTY, nazov_mesiaca(month - 1));
			}
			Export("\n</select>\n");

			// pole WWW_DEN
			Export("<select name=\"%s\">\n", STR_DEN);
			for(day = 1; day < 32; day++){
				Export("<option%s>%d\n", (day == dnes.tm_mday)? html_option_selected: STR_EMPTY, day);
			}
			Export("\n</select>.\n");

			// pole WWW_ROK
			Export("<"HTML_FORM_INPUT_TEXT_ROK" name=\"%s\" value=\"%d\" />\n", STR_ROK, dnes.tm_year);
		}// FORMAT_DATUMU_MESIAC_DEN_ROK
		else{ // if(format_datumu[_global_jazyk] == FORMAT_DATUMU_DEN_MESIAC_ROK){
			// pole WWW_DEN
			Export("<select name=\"%s\">\n", STR_DEN);
			for(day = 1; day < 32; day++){
				Export("<option%s>%d\n", (day == dnes.tm_mday)? html_option_selected: STR_EMPTY, day);
			}
			Export("\n</select>.\n");

			// pole WWW_MESIAC
			Export("<select name=\"%s\">\n", STR_MESIAC);
			for(month = 1; month < 13; month++){
				Export("<option%s>%s\n", (month == dnes.tm_mon)? html_option_selected: STR_EMPTY, nazov_mesiaca(month - 1));
			}
			Export("\n</select>\n");

			// pole WWW_ROK
			Export("<"HTML_FORM_INPUT_TEXT_ROK" name=\"%s\" value=\"%d\" />\n", STR_ROK, dnes.tm_year);
		}// FORMAT_DATUMU_DEN_MESIAC_ROK

		Export(HTML_NONBREAKING_SPACE);
		Export((char *)html_text_alebo_pre[_global_jazyk]);
		Export(" ");
		Export("<a href=\"%s?%s=%s"HTML_AMPERSAND"%s\">\n", script_name, STR_QUERY_TYPE, STR_PRM_DNES, pom2); // 2006-08-01: pridaný jazyk; 2011-05-12: bolo nastavené funkciou prilep_request_options()
		Export((char *)html_text_dnesok[_global_jazyk]);
		Export("</a></td>\n");

		// 2011-01-31: chvíľu tu bol výber liturgického kalendára (len pre SK), napr. SVD, SDB, SJ, CSsR; presunuté inde

		Export("</tr>\n");
		Export("<!--TABLE:END(PRM_DATUM)-->\n");
		Export("</table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");
#endif

#ifdef FORMULAR_PRE_PRM_SVIATOK
	// -------------------------------------------
		Export("<tr>\n<td>\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td>\n");
		// formular pre PRM_SVIATOK
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>\n", STR_QUERY_TYPE, STR_PRM_SVIATOK, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td><td>\n");
		// sviatky --- [ToDo]
		Export("</td></tr></table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");
#endif

	// -------------------------------------------
		Export("<tr>\n<td>\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td>\n");
		// formular pre PRM_ANALYZA_ROKU
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>", STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td><td>\n");
		// Export(HTML_NONBREAKING_SPACE); // netreba, je to v tabuľke
		Export((char *)html_text_prik_sviatky_atd[_global_jazyk]);
		Export("\n");
		// pole WWW_ANALYZA_ROKU
		Export("<"HTML_FORM_INPUT_TEXT_ROK" name=\"%s\" value=\"%d\" />\n", STR_ANALYZA_ROKU, dnes.tm_year);
		Export("</td></tr></table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");

	// -------------------------------------------
		Export("<tr>\n<td>\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td>\n");
		// formular pre PRM_MESIAC_ROKA
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>", STR_QUERY_TYPE, STR_PRM_MESIAC_ROKA, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td><td>\n");
		// Export(HTML_NONBREAKING_SPACE); // netreba, je to v tabuľke
		Export((char *)html_text_lit_kalendar[_global_jazyk]);
		Export(" \n"); // 2003-07-16; povodne tu bolo "mesiac"
		// pole WWW_MESIAC_ROKA
		Export("<select name=\"%s\">\n", STR_MESIAC_ROKA);
		for(month = 1; month < 13; month++){
			Export("<option%s>%s\n", (month == dnes.tm_mon)? html_option_selected: STR_EMPTY, nazov_mesiaca(month - 1));
		}
		Export("\n</select>\n");

		Export((char *)html_text_roku[_global_jazyk]);
		Export(" \n"); // 2003-07-16; povodne tu bolo "v roku"
		// pole WWW_ROK_ROKA
		Export("<"HTML_FORM_INPUT_TEXT_ROK" name=\"%s\" value=\"%d\" />\n", STR_ROK_ROKA, dnes.tm_year);
		Export("</td></tr></table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");

	// -------------------------------------------
		Export("<tr>\n<td>\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td>\n");
		// formular pre PRM_TABULKA
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>", STR_QUERY_TYPE, STR_PRM_TABULKA, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td><td>\n");
		// Export(HTML_NONBREAKING_SPACE); // netreba, je to v tabuľke
		Export((char *)html_text_tabulka_pohyblive_od[_global_jazyk]);
		Export(HTML_NONBREAKING_SPACE);
		// pole WWW_ROK_FROM
		Export("<"HTML_FORM_INPUT_TEXT_ROK" name=\"%s\" value=\"%d\" />\n", STR_ROK_FROM, dnes.tm_year - 12);
		Export(HTML_NONBREAKING_SPACE);
		Export((char *)html_text_do_roku[_global_jazyk]);
		Export(HTML_NONBREAKING_SPACE);
		Export("\n");
		// pole WWW_ROK_TO
		Export("<"HTML_FORM_INPUT_TEXT_ROK" name=\"%s\" value=\"%d\" />\n", STR_ROK_TO, dnes.tm_year + 12);
		Export("</td></tr>\n<tr><td></td><td>");
		// pole WWW_TABULKA_LINKY
		Export(HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE); // 2011-01-26
		Export("<"HTML_FORM_INPUT_CHECKBOX" name=\"%s\" value=\"%d\">\n", STR_TABULKA_LINKY, 1); // ked bude zaskrtnuty, tak vrati hodnotu 1
		Export(HTML_NONBREAKING_SPACE);

		Export("<"HTML_SPAN_EXPLAIN">");
		Export((char *)html_text_zobrazit_linky[_global_jazyk]);
		Export(HTML_SPAN_END);

		Export("\n");
		Export("</td></tr></table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");

	// -------------------------------------------
		Export("<tr>\n<td>\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td "HTML_VALIGN_TOP">\n");
		// formulár pre PRM_STATIC_TEXT, parameter 
		radio_checked = ANO;
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>", STR_QUERY_TYPE, STR_PRM_STATIC_TEXT, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td><td>\n");
		// Export(HTML_NONBREAKING_SPACE); // netreba, je to v tabuľke
		Export((char *)html_text_ordinarium[_global_jazyk]);
		Export(HTML_NONBREAKING_SPACE);
		Export((char *)html_text_pre[_global_jazyk]);
		Export(HTML_NONBREAKING_SPACE);
		Export("<"HTML_FORM_INPUT_HIDDEN" name=\"%s\" value=\"%s\">\n", STR_STATIC_TEXT, skratka_static_text[STATIC_TEXT_ORDINARIUM]);

		Export("</td><td "HTML_ALIGN_LEFT">\n");

		// pole WWW_MODL_ORDINARIUM
		Export("<select name=\"%s\">\n", STR_MODL_ORDINARIUM);
		Export("<option>%s\n", nazov_modlitby_short(MODL_INVITATORIUM));
		Export("<option>%s\n", nazov_modlitby_short(MODL_POSV_CITANIE));
		Export("<option selected>%s\n", nazov_modlitby_short(MODL_RANNE_CHVALY));
		Export("<option>%s\n", nazov_modlitby_short(MODL_PREDPOLUDNIM));
		Export("<option>%s\n", nazov_modlitby_short(MODL_NAPOLUDNIE));
		Export("<option>%s\n", nazov_modlitby_short(MODL_POPOLUDNI));
		Export("<option>%s\n", nazov_modlitby_short(MODL_VESPERY));
		Export("<option>%s\n", nazov_modlitby_short(MODL_KOMPLETORIUM));
		Export("</select>\n");

		Export("</td></tr></table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");
	// -------------------------------------------

#define formular_PRM_LIT_OBD
#ifdef formular_PRM_LIT_OBD
	// -------------------------------------------
		Export("<tr>\n<td>\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td "HTML_VALIGN_TOP">\n");
		// 2011-01-25; formulár nahrádzajúci "PRM_CEZ_ROK"
		// formulár pre PRM_LIT_OBD
		// 2013-01-28: default pre druhú časť možností
		radio_checked = ANO;
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>", STR_QUERY_TYPE, STR_PRM_LIT_OBD, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td><td "HTML_ALIGN_LEFT">\n");

		// pole WWW_MODLITBA
		Export("<select name=\"%s\">\n", STR_MODLITBA);
		Export("<option>%s\n", nazov_modlitby_short(MODL_PRVE_VESPERY));
		Export("<option>%s\n", nazov_modlitby_short(MODL_PRVE_KOMPLETORIUM));
		Export("<option>%s\n", nazov_modlitby_short(MODL_INVITATORIUM));
		Export("<option selected>%s\n", nazov_modlitby_short(MODL_POSV_CITANIE));
		Export("<option>%s\n", nazov_modlitby_short(MODL_RANNE_CHVALY));
		Export("<option>%s\n", nazov_modlitby_short(MODL_PREDPOLUDNIM));
		Export("<option>%s\n", nazov_modlitby_short(MODL_NAPOLUDNIE));
		Export("<option>%s\n", nazov_modlitby_short(MODL_POPOLUDNI));
		Export("<option>%s\n", nazov_modlitby_short(MODL_DRUHE_VESPERY));
		Export("<option>%s\n", nazov_modlitby_short(MODL_DRUHE_KOMPLETORIUM));
		Export("</select>\n");

#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
		Export(HTML_CRLF_LINE_BREAK);
#else
		Export(HTML_NONBREAKING_SPACE);
#endif
		Export((char *)html_text_den[_global_jazyk]);
		Export(HTML_NONBREAKING_SPACE);

		// pole WWW_DEN_V_TYZDNI
		Export("<select name=\"%s\">\n", STR_DEN_V_TYZDNI);
		for(day = DEN_NEDELA; day <= DEN_SOBOTA; day++){
			Export("<option%s>%s\n", (day == dnes.tm_wday)? html_option_selected: STR_EMPTY, nazov_dna(day));
		}
		Export("\n</select>\n");

		Export(",\n");
#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
		Export(HTML_CRLF_LINE_BREAK);
#else
		Export(HTML_SPACE);
#endif
		Export((char *)html_text_liturgicky_rok[_global_jazyk]);
		Export(HTML_NONBREAKING_SPACE);

		// pole WWW_LIT_ROK
		Export("<select name=\"%s\">\n", STR_LIT_ROK);
		for(lo = 'A'; lo <= 'C'; lo++){
			Export("<option%s>%c\n", (lo == _global_den.litrok)? html_option_selected: STR_EMPTY, lo);
		}
		Export("\n</select>\n");
		Export(", "HTML_LINE_BREAK);

		// pole WWW_TYZDEN
		if(_global_jazyk == JAZYK_LA){
			Export((char *)html_text_tyzden[_global_jazyk]);
		}
		Export("<select name=\"%s\">\n", STR_TYZDEN);
		for(day = 0; day <= POCET_NEDIEL_CEZ_ROK; day++){
			Export("<option%s>%d\n", (day == _global_den.tyzden)? html_option_selected: STR_EMPTY, day);
		}
		Export("\n</select>"HTML_NONBREAKING_SPACE);

		if(_global_jazyk != JAZYK_LA){
			Export((char *)html_text_tyzden[_global_jazyk]);
		}
		Export(",\n");
#if defined(OS_Windows_Ruby) || defined(IO_ANDROID)
		Export(HTML_CRLF_LINE_BREAK);
#else
		Export(HTML_SPACE);
#endif

		// pole WWW_LIT_OBD
		Export("<select name=\"%s\">\n", STR_LIT_OBD);
		for(lo = 0; lo <= POCET_OBDOBI; lo++){
			Export("<option%s>%s\n", (lo == _global_den.litobd)? html_option_selected: STR_EMPTY, nazov_obdobia_short(lo));
		}
		Export("\n</select>\n");

		Export("</td></tr></table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");
#else
	// -------------------------------------------
		Export("<tr>\n<td>\n");
		Export("<table "HTML_ALIGN_LEFT">\n<tr><td>\n");
		// 2003-07-16; tento formular bol povodne na 2. mieste
		// formular pre PRM_CEZ_ROK
		Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\"%s>", STR_QUERY_TYPE, STR_PRM_CEZ_ROK, radio_checked? html_option_checked: STR_EMPTY);
		radio_checked = NIE;
		Export("</td><td "HTML_ALIGN_LEFT">\n");

		// 2003-07-16; povodne toto pole bolo na konci
		// pole WWW_MODLITBA
		Export("<select name=\"%s\">\n", STR_MODLITBA);
		Export("<option>%s\n", nazov_modlitby(MODL_PRVE_VESPERY));
		Export("<option>%s\n", nazov_modlitby(MODL_PRVE_KOMPLETORIUM));
		Export("<option>%s\n", nazov_modlitby(MODL_INVITATORIUM));
		Export("<option selected>%s\n", nazov_modlitby(MODL_POSV_CITANIE));
		Export("<option>%s\n", nazov_modlitby(MODL_RANNE_CHVALY));
		Export("<option>%s\n", nazov_modlitby(MODL_PREDPOLUDNIM));
		Export("<option>%s\n", nazov_modlitby(MODL_NAPOLUDNIE));
		Export("<option>%s\n", nazov_modlitby(MODL_POPOLUDNI));
		Export("<option>%s\n", nazov_modlitby(MODL_DRUHE_VESPERY));
		Export("<option>%s\n", nazov_modlitby(MODL_DRUHE_KOMPLETORIUM));
		Export("</select>\n");

		Export(HTML_NONBREAKING_SPACE);
		Export((char *)html_text_pre_cezrocne_obd[_global_jazyk]);
		Export(", "HTML_LINE_BREAK);

		// pole WWW_DEN_V_TYZDNI
		Export("<select name=\"%s\">\n", STR_DEN_V_TYZDNI);
		for(day = DEN_NEDELA; day <= DEN_SOBOTA; day++){
			Export("<option%s>%s\n", (day == dnes.tm_wday)? html_option_selected: STR_EMPTY, nazov_dna(day));
		}
		Export("\n</select> v\n");

		// pole WWW_TYZDEN
		Export("<select name=\"%s\">\n", STR_TYZDEN);
		for(day = 1; day < 5; day++){
			Export("<option%s>%d\n", (day == _global_den.tyzzal)? html_option_selected: STR_EMPTY, day);
		}
		Export("\n</select> ");
		Export((char *)html_text_v_tyzdni_zaltara[_global_jazyk]);

		Export("</td></tr></table>\n");
		Export("</td>\n");
		Export("</tr>\n\n");
#endif
	// -------------------------------------------

		// predtym tu bolo <br/>, ale kedze hore som dal <table align="center">,  tak tu musi byt <center> kvoli buttonom; 2003-07-09
		// 2012-07-23: upravené, aby sa stalo súčasťou tabuľky s možnosťami voľby
		Export("<!-- riadok pre button Zobraziť/Vyčistiť (choices)-->\n");
		Export("<tr "HTML_ALIGN_CENTER">\n<td>\n");
		// button Zobraziť (GO!)
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)HTML_BUTTON_DNES_SHOW);
		Export("\">");
	/*
		// button Pôvodné hodnoty (CLEAR!)
		Export(HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE"\n");
		Export("<"HTML_FORM_INPUT_RESET2" value=\"");
		Export((char *)HTML_BUTTON_DNES_DEFAULTS);
		Export("\">");
	*/
		Export("</td>\n");
		Export("</tr>\n\n");

		Export("</form>\n\n");
	}
	Export("<!--TABLE:END(choices)-->\n");
	Export("</table>\n");

}// _export_main_formular()


//---------------------------------------------------------------------
// _export_rozbor_dna_batch()
//
// exportuje udaje, ktore nacitala _rozbor_dna() zalozene na _export_rozbor_dna(); 2003-07-07
// ale tento ich exportuje do batch suboru (pre dalsie davkove spracovanie)

// BATCH_COMMAND vygeneruje do batch suboru prikazy, ktore sa pri dalsom behu spustia;
// 2003-08-13 pre batch bude treba na miesto TUTOLA dodat modlitby cez den, asi cez nejaku option (ci ranne chvaly a vespery, alebo vsetky modlitby 

// 2004-03-11 pre batch mod sa nevyexportovali niektore parametre, mailom upozornil Stanislav Čúzy <trobon@inMail.sk> 2004-03-06. Vdaka. | pridane do BATCH_COMMAND
// 2006-01-31: zmenené TUTOLA na 2006-01-31-TUTOLA, pridali sme modlitbu cez deň (len napoludnie) a posvätné čítanie
// 2006-02-06: upravené: negenerovať vešpery pre ľubovoľnú spomienku PM (a != PORADIE_PM_SOBOTA)
// 2007-09-25: iba poznámka - možno by bolo dobré tie stringy vytvárať dynamicky pre jednotlivé modlitby (ktoré by sa dali parametrizovať)
// 2008-04-09: makro upravené na funkciu, BATCH_COMMAND() -> execute_batch_command()
void execute_batch_command(short int a, char batch_command[MAX_STR], short int zobrazit_mcd, short int modlitba = MODL_NEURCENA, short int d_from_m_from_r_from = 0){
	short int i;
// ak je nastaveny _global_opt_append, tak vsetko do 1 suboru, 2003-07-08
// 2003-08-11 -Wall upozornila na too many arguments for format
// 2004-03-11 pridane niektore dalsie parametre
// 2004-03-16 pridany vypis do batch_html_file
// 2006-01-31 pridaný zápis modlitby cez deň a posv. čítania
// 2008-04-09 pridaný zápis modlitby cez deň (predpoludním a popoludní), invitatórium a kompletórium; doplnený jazyk
// 2008-08-08: bolo kedysi nedokončené: ostáva prilepiť info o css
// 2009-09-03: podľa nastavenia exportujeme do odlišných súborov odlišné veci
// 2009-08-04: rozšírené o nepovinný vstupný parameter 'modlitba', ktorý hovorí, či sa majú exportovať všetky modlitby (ako doteraz) alebo len táto modlitba (pre export_monthly_druh >= 1)
// 2011-03-14: doplnené vyplnenie parametra o5 (_global_opt 5) pre modlitbu cez deň [doteraz sme generovali pre všetky 3 modlitby MCD žalmy "vlastné", teraz pre 2 z nich budeme dávať doplnkovú psalmódiu]
// 2011-03-18: doplnené exportovanie parametra k (_global_kalendar)
// 2011-03-23: upravené: negenerovať vešpery pre soboty, ak je nastavené (_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY (hoci sa parameter o8 zatiaľ neexportuje)
// 2011-04-12: keďže _global_opt 5 sa stáva súčasťou _global_opt 1, nie je potrebné nastaviť o5; je však potrebné správne upraviť o1
// 2011-04-13: doplnené exportovanie chýbajúcich option 0 až 4
// 2012-12-12: oprava pre append batch mód; export_fname_pattern
	FILE *batch_export_file = NULL;
	char parameter_M[SMALL] = STR_EMPTY; // parametre pre výsledné HTML (parameter 'M' a parametre pre odkazy na súbory, napr. 'I')
	char parameter_I[SMALL] = STR_EMPTY;
	char poradie_svateho[SMALL] = STR_EMPTY; // pre export_monthly_druh >= 1
	char _local_export_navig_hore[SMALL] = STR_EMPTY;
	short int _global_opt_casti_modlitby_orig; // parameter o1 (_global_opt 1) pre modlitbu cez deň (doplnková psalmódia)
	char export_doplnkova_psalmodia[SMALL] = STR_EMPTY; // reťazec pre alternatívny súbor modlitby cez deň obsahujúci doplnkovú psalmódiu
	char pom[SMALL] = STR_EMPTY; // pomocný reťazec (priliepanie parametrov do export_dalsie_parametre)
	char export_dalsie_parametre[SMALL] = STR_EMPTY; // reťazec pre kalendár (export_kalendar); 2011-11-30: pridaný do toho istého reťazca aj font
	char export_fname_pattern[MAX_STR] = STR_EMPTY; // reťazec, ktorý sa prilepuje na koniec názvu súboru pre ne-append mód // 2013-01-27: rozšírené; pôvodne bolo SMALL, čo ale niekedy nepostačovalo (upozornil peter.chodelka@gmail.com)
	char export_fname_modl_str[SMALL] = STR_EMPTY; // reťazec pre identifikáciu modlitby v názve súboru (ID modlitby alebo char_modlitby[i])

	Log("execute_batch_command(): začiatok...\n");

	_global_opt_casti_modlitby_orig = _global_opt[OPT_1_CASTI_MODLITBY]; // backup pôvodnej hodnoty
	// 2011-04-12: nastavenie parametra o1 pre bežnú a doplnkovú psalmódiu; parameter o1 očistíme a _global_opt_casti_modlitby_orig bude obsahovať aj bit pre doplnkovú psalmódiu
	// 2011-09-06: neriešime otázku žalmu 95 pre ranné chvály resp. vešpery, kde je použitý žalm 24, 67, 100
	if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_MCD_DOPLNKOVA) == BIT_OPT_1_MCD_DOPLNKOVA){
		Log("Pre option 1 odstraňujem bit pre 'doplnkovú psalmódiu', pomocná premenná to bude obsahovať\n");
		_global_opt[OPT_1_CASTI_MODLITBY] -= BIT_OPT_1_MCD_DOPLNKOVA;
		_global_opt_casti_modlitby_orig = _global_opt[OPT_1_CASTI_MODLITBY] + BIT_OPT_1_MCD_DOPLNKOVA;
	}
	// 2010-08-04: pridané odovzdanie parametra pre kalendár; 2011-11-30: pridaný do toho istého reťazca aj font
	// 2010-09-14: podmienka opravená; ak nie je kalendár určený resp. je všeobecný pre daný jazyk, nie je potrebné ho exportovať
	strcpy(export_dalsie_parametre, STR_EMPTY);
	// 2011-03-18: použité z iných miest aj v execute_batch_command() -- exportovanie parametra k (_global_kalendar)
	if(PODMIENKA_EXPORTOVAT_KALENDAR){
		sprintf(pom, " -k%s", skratka_kalendara[_global_kalendar]);
	}
	else{
		Log("\tNetreba prilepiť kalendár (jazyk == %s, kalendár == %s)\n", skratka_jazyka[_global_jazyk], skratka_kalendara[_global_kalendar]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem kalendár: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// 2011-11-30: exportovanie parametra F (_global_font)
	if(PODMIENKA_EXPORTOVAT_FONT){
		sprintf(pom, " -F%s", nazov_fontu[_global_font]);
	}
	else{
		Log("\tNetreba prilepiť font (font == %s)\n", nazov_fontu[_global_font]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem font: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// 2011-11-30: exportovanie parametra S (_global_font_size)
	if(PODMIENKA_EXPORTOVAT_FONTSIZE){
		sprintf(pom, " -S%s", nazov_font_size_css[_global_font_size]);
	}
	else{
		Log("\tNetreba prilepiť font size (font size == %s)\n", nazov_font_size_css[_global_font_size]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem font size: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// 2013-12-12: exportovanie parametra c (_global_css)
	if(PODMIENKA_EXPORTOVAT_CSS){
		sprintf(pom, " -c%s", skratka_css[_global_css]); // nazov_css[_global_css]
	}
	else{
		Log("\tNetreba prilepiť css (css == %s/%s)\n", skratka_css[_global_css], nazov_css[_global_css]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem css: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// 2009-08-03: exportovanie do adresárov po mesiacoch
	if(_global_opt_batch_monthly == ANO){
		Log("_global_opt_batch_monthly == ANO\n");
		if(export_monthly_druh >= 2){
			mystrcpy(_local_export_navig_hore,_global_export_navig_hore_day, SMALL);
		}
		else{
			mystrcpy(_local_export_navig_hore,_global_export_navig_hore, SMALL);
		}
		if(index_pre_mesiac_otvoreny == ANO){
			Log("index_pre_mesiac_otvoreny == ANO\n");
			// najskôr do zoznamu mesiacov vyprintujeme odkaz na index.htm daného mesiaca (ak bolo prvého resp. začiatok exportu)...
			if((_global_den.den == 1 && ((export_monthly_druh >= 1 && modlitba == MODL_INVITATORIUM) || export_monthly_druh != 1)) || export_month_zaciatok == ANO){
				// sem sa už name_batch_month_file dostane s upraveným oddeľovačom STR_PATH_SEPARATOR_HTML; upravené v _main_batch_mode()
				if(_global_jazyk == JAZYK_HU){
					fprintf(batch_html_file, "<li><a href=\"%s\">%d. %s</a></li>\n", name_batch_month_file,  _global_den.rok, nazov_mesiaca(_global_den.mesiac - 1));
				}
				else{
					fprintf(batch_html_file, "<li><a href=\"%s\">%s %d</a></li>\n", name_batch_month_file, nazov_mesiaca(_global_den.mesiac - 1), _global_den.rok);
				}
				export_month_zaciatok = NIE;
			}
			// ... a presmerujeme výstup pre daný deň do index.htm daného mesiaca; potrebujeme si poslať názov, kam má pre jednotlivú modlitbu ukazovať ^ hore
			batch_export_file = batch_month_file;
		}// if(index_pre_mesiac_otvoreny == ANO)
		else{
			// 2009-08-05: netreba; pretože DEFAULT_MONTH_EXPORT sa zatiaľ nedá meniť
			batch_export_file = batch_html_file;
		}// else if(index_pre_mesiac_otvoreny == ANO)

		// 2009-08-12: doplnená premenná _global_export_navig_hore; pôvodne bolo: // mystrcpy(parameter_M, " -M", SMALL);
		// 2013-01-07: táto časť bola v predošlom "else"; nefungovalo to správne (napr. pri command-line príkaze: breviar.exe -qpbm -d1 -m1 -r2013 -f31 -g12 -p2013 -brobSK.bat -jsk -nbreviar.exe -i..\..\breviar.sk\include\ -usimple -M2 -00 -15184 -2224)
		Log("2:parameter_M...\n");
		sprintf(parameter_M, " -M%d", export_monthly_druh);
		Log("parameter_M == `%s'...\n", parameter_M);
		if(!(equals(_local_export_navig_hore, STR_EMPTY) || equals(_local_export_navig_hore, DEFAULT_MONTH_EXPORT))){
			sprintf(parameter_I, " -I%s", _local_export_navig_hore);
			Log("parameter_I == `%s'...\n", parameter_I);
			strcat(parameter_M, parameter_I);
			Log("parameter_M == `%s'...\n", parameter_M);
		}
	}// if(_global_opt_batch_monthly == ANO)
	else{
		batch_export_file = batch_html_file;
		mystrcpy(parameter_M, STR_EMPTY, SMALL);
	}// else if(_global_opt_batch_monthly == ANO)

	// 2009-08-04: iný export
	if(export_monthly_druh >= 1 && modlitba != MODL_NEURCENA){
		i = modlitba;
		Log("/* generujem len modlitbu i == %d `%s' (export_monthly_druh >= 1)...*/\n", i, nazov_modlitby(i));

		// 2013-07-29: generovanie názvu súboru s písmenkom modlitby (default) alebo s ID modlitby
		if((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_FNAME_MODL_ID) != BIT_OPT_4_FNAME_MODL_ID){
			sprintf(export_fname_modl_str, "%c", char_modlitby[i]);
		}
		else{
			sprintf(export_fname_modl_str, "%d", i);
		}
		Log("export_fname_modl_str == %s...\n", export_fname_modl_str);

		Log("a == %d, i == %d, zobrazit_mcd == %d...\n", a, i, zobrazit_mcd);

		// 2012-08-23: generovať modlitbu cez deň + kompletórium len ak nejde o ľubovoľnú spomienku (vtedy nemajú význam)
		if(!((zobrazit_mcd == ANO) || (a == 0)) && (je_modlitba_cez_den(i) || je_kompletorium12(i))){
			Log("(generovať modlitbu cez deň + kompletórium len ak nejde o ľubovoľnú spomienku -- vtedy nemajú význam)\n");
		}
		else{
			if((_global_den.den == 1 || d_from_m_from_r_from == 1) && export_month_nova_modlitba == 1 && export_monthly_druh == 1){
				// pre prvého (resp. prvého v prvom mesiaci, ktorý nezačal prvého) musím vypísať aj názov modlitby
				fprintf(batch_export_file, "\n<p><b>%s</b>"HTML_LINE_BREAK, nazov_modlitby(i));
				export_month_nova_modlitba = 0;
			}
			// 2011-03-23: upravené: negenerovať vešpery pre soboty, ak je nastavené (_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY
			// 2012-08-27: vešpery a kompletórium nemá zmysel zobrazovať, ak ide o sobotu a ďalšieho svätého (pri viacerých ľubovoľných spomienkach)
			// 2013-06-27: pridané zátvorky okolo prvej podmienky, aby && v druhom riadku viazalo sa na obe "||" možnosti s "a"-čkom | breviar.cpp:9804: warning: suggest parentheses around '&&' within '||'
			// 2013-09-30: namiesto prostej podmienky B:(zobrazit_mcd == ANO) použitá podmienená implikácia A => B (A:modlitba cez deň) vo forme (non A) OR B
			if(((a != PORADIE_PM_SOBOTA) || (a == PORADIE_PM_SOBOTA && (i != MODL_VESPERY && i != MODL_KOMPLETORIUM)))
				&& !(((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY) && (nie_su_vespery))
				&& (
					(/*non A*/ !(je_modlitba_cez_den(i)) || /*B*/(zobrazit_mcd == ANO))
					|| (_global_den.denvt != DEN_SOBOTA) 
					|| (a == 0)
				)
			){ // 2006-01-31-TUTOLA; 2008-04-09 presunuté
				// 2011-03-14: nastavenie parametra o5 (_global_opt 5) pre modlitbu cez deň (bežná alebo doplnková psalmódia) 
				// 2011-03-16: upravené tak, že je to len fakultatívne (ako odlišný súbor)
				// 2011-04-12: používa sa option 1 (jej upravená hodnota _global_opt_casti_modlitby_orig)
				// 2011-04-13: nemôžeme porovnávať s _global_opt[OPT_1_CASTI_MODLITBY] (bola očistená), ale s _global_opt_casti_modlitby_orig (obsahuje pôvodnú hodnotu)
				// 2012-12-12: oprava pre append batch mód; export_fname_pattern
				if(((_global_opt_casti_modlitby_orig & BIT_OPT_1_MCD_DOPLNKOVA) == BIT_OPT_1_MCD_DOPLNKOVA) && (je_modlitba_cez_den(i))){
					if(_global_opt_append == YES){
						sprintf(export_fname_pattern, "%s", batch_command);
					}
					else{
						sprintf(export_fname_pattern, "%s%d%sd.htm", batch_command, a, export_fname_modl_str /* char_modlitby[i] */);
					}
					Log("1:parameter_M == `%s'...\n", parameter_M);
					fprintf(batch_file, "%s -0%d -1%d -2%d -3%d -4%d -x%d -p%s -j%s%s%s\n", export_fname_pattern, 
						_global_opt[OPT_0_SPECIALNE], _global_opt_casti_modlitby_orig /* _global_opt[OPT_1_CASTI_MODLITBY] */, _global_opt[OPT_2_HTML_EXPORT], _global_opt[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_4_OFFLINE_EXPORT], 
						a, str_modlitby[i], skratka_jazyka[_global_jazyk], parameter_M, export_dalsie_parametre); // modlitba `i'
					if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
						sprintf(export_doplnkova_psalmodia, " (<a href=\""FILENAME_EXPORT_DATE_SIMPLE"_%d%sd.htm\">alt</a>)", _global_den.rok % 100, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /*char_modlitby[i] */);
					}
					else{
						// EXPORT_DATE_FULL
						sprintf(export_doplnkova_psalmodia, " (<a href=\""FILENAME_EXPORT_DATE_FULL"_%d%sd.htm\">alt</a>)", _global_den.rok, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /* char_modlitby[i] */);
					}
				}
				else{
					strcpy(export_doplnkova_psalmodia, STR_EMPTY);
				}
				if(_global_opt_append == YES){
					sprintf(export_fname_pattern, "%s", batch_command);
				}
				else{
					sprintf(export_fname_pattern, "%s%d%s.htm", batch_command, a, export_fname_modl_str /* char_modlitby[i] */);
				}
				Log("2:parameter_M == `%s'...\n", parameter_M);
				fprintf(batch_file, "%s -0%d -1%d -2%d -3%d -4%d -x%d -p%s -j%s%s%s\n", export_fname_pattern, 
					_global_opt[OPT_0_SPECIALNE], _global_opt[OPT_1_CASTI_MODLITBY], _global_opt[OPT_2_HTML_EXPORT], _global_opt[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_4_OFFLINE_EXPORT], 
					a, str_modlitby[i], skratka_jazyka[_global_jazyk], parameter_M, export_dalsie_parametre); // modlitba `i'
				if(export_monthly_druh == 1){
					Log("mY: export_monthly_druh == 1...\n");
					if(a > 0){
						sprintf(poradie_svateho, "/%d", a);
					}
					else{
						mystrcpy(poradie_svateho, STR_EMPTY, SMALL);
					}
					if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
						fprintf(batch_export_file, "<a href=\""FILENAME_EXPORT_DATE_SIMPLE"_%d%s.htm\">%d%s</a>%s | ", _global_den.rok % 100, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /* char_modlitby[i] */, _global_den.den, /* char */ poradie_svateho, export_doplnkova_psalmodia);
					}
					else{
						// EXPORT_DATE_FULL
						fprintf(batch_export_file, "<a href=\""FILENAME_EXPORT_DATE_FULL"_%d%s.htm\">%d%s</a>%s | ", _global_den.rok, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /* char_modlitby[i] */, _global_den.den, /* char */ poradie_svateho, export_doplnkova_psalmodia);
					}
				}// if(export_monthly_druh == 1)
			}
			else{
				Log("nič sa nedeje.\n");
			}
		}// generovať modlitbu
	}
	else{
		Log("mY: modlitba určená...\n");
		Log("execute_batch_command(): pre všetky modlitby...\n");
		fprintf(batch_export_file, "<li>%d. %s %d: \n", _global_den.den, nazov_mesiaca(_global_den.mesiac - 1), _global_den.rok);
		for(i = MODL_INVITATORIUM; i < MODL_NEURCENA; i++){

			// 2013-07-29: generovanie názvu súboru s písmenkom modlitby (default) alebo s ID modlitby
			if((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_FNAME_MODL_ID) != BIT_OPT_4_FNAME_MODL_ID){
				sprintf(export_fname_modl_str, "%c", char_modlitby[i]);
			}
			else{
				sprintf(export_fname_modl_str, "%d", i);
			}

			// 2012-08-23: generovať modlitbu cez deň + kompletórium len ak nejde o ľubovoľnú spomienku (vtedy nemajú význam)
			if(!((zobrazit_mcd == ANO) || (a == 0)) && (je_modlitba_cez_den(i) || je_kompletorium12(i))){
				continue;
			}

			Log("/* generujem: %d `%s'... */\n", i, nazov_modlitby(i));
			// 2011-03-23: upravené: negenerovať vešpery pre soboty, ak je nastavené (_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY
			// 2012-08-27: vešpery a kompletórium nemá zmysel zobrazovať, ak ide o sobotu a ďalšieho svätého (pri viacerých ľubovoľných spomienkach)
			// 2013-04-05: zavedené "nie_su_vespery" kvôli Bielej (veľkej) sobote
			// 2013-09-30: namiesto prostej podmienky B:(zobrazit_mcd == ANO) použitá podmienená implikácia A => B (A:modlitba cez deň) vo forme (non A) OR B
			if(((a != PORADIE_PM_SOBOTA) || (a == PORADIE_PM_SOBOTA && (i != MODL_VESPERY && i != MODL_KOMPLETORIUM))) 
				&& !(((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_BUTTON_PRVE_VESPERY) == BIT_OPT_2_BUTTON_PRVE_VESPERY) && (nie_su_vespery))
				&& (
					(/*non A*/ !(je_modlitba_cez_den(i)) || /*B*/(zobrazit_mcd == ANO))
					|| (_global_den.denvt != DEN_SOBOTA) 
					|| (a == 0)
				)
			){ // 2006-01-31-TUTOLA; 2008-04-09 presunuté
				if(_global_opt_append == YES){
					fprintf(batch_file, "%s -0%d -1%d -2%d -3%d -4%d -x%d -p%s -j%s%s\n", batch_command, 
						_global_opt[OPT_0_SPECIALNE], _global_opt[OPT_1_CASTI_MODLITBY], _global_opt[OPT_2_HTML_EXPORT], _global_opt[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_4_OFFLINE_EXPORT], 
						a, str_modlitby[i], skratka_jazyka[_global_jazyk], export_dalsie_parametre); // modlitba `i'
				}// endif _global_opt_append == YES
				else{
					// 2011-03-14: nastavenie parametra o5 (_global_opt 5) pre modlitbu cez deň (bežná alebo doplnková psalmódia) 
					// 2011-03-16: upravené tak, že je to len fakultatívne (ako odlišný súbor)
					// 2011-04-12: používa sa option 1 (jej upravená hodnota _global_opt_casti_modlitby_orig)
					// 2011-04-13: nemôžeme porovnávať s _global_opt[OPT_1_CASTI_MODLITBY] (bola očistená), ale s _global_opt_casti_modlitby_orig (obsahuje pôvodnú hodnotu)
					if(((_global_opt_casti_modlitby_orig & BIT_OPT_1_MCD_DOPLNKOVA) == BIT_OPT_1_MCD_DOPLNKOVA) && (je_modlitba_cez_den(i))){
						Log("3:parameter_M == `%s'...\n", parameter_M);
						fprintf(batch_file, "%s%d%sd.htm -0%d -1%d -2%d -3%d -4%d -x%d -p%s -j%s%s%s\n", batch_command, a, export_fname_modl_str /* char_modlitby[i] */, 
							_global_opt[OPT_0_SPECIALNE], _global_opt_casti_modlitby_orig /* _global_opt[OPT_1_CASTI_MODLITBY] */, _global_opt[OPT_2_HTML_EXPORT], _global_opt[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_4_OFFLINE_EXPORT], 
							a, str_modlitby[i], skratka_jazyka[_global_jazyk], parameter_M, export_dalsie_parametre); // modlitba `i'
						if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
							sprintf(export_doplnkova_psalmodia, " (<a href=\""FILENAME_EXPORT_DATE_SIMPLE"_%d%sd.htm\">alt</a>)", _global_den.rok % 100, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /* char_modlitby[i] */);
						}
						else{ // EXPORT_DATE_FULL
							sprintf(export_doplnkova_psalmodia, " (<a href=\""FILENAME_EXPORT_DATE_FULL"_%d%sd.htm\">alt</a>)", _global_den.rok, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /* char_modlitby[i] */);
						}
					}
					else{
						strcpy(export_doplnkova_psalmodia, STR_EMPTY);
					}
					// 2009-08-03: doplnená možnosť exportovať parameter -M ak exportuje batch mód pre jednotlivé mesiace kvôli hlavičke jednotlivej modlitby
					Log("4:parameter_M == `%s'...\n", parameter_M);
					fprintf(batch_file, "%s%d%s.htm -0%d -1%d -2%d -3%d -4%d -x%d -p%s -j%s%s%s\n", batch_command, a, export_fname_modl_str /* char_modlitby[i] */, 
						_global_opt[OPT_0_SPECIALNE], _global_opt[OPT_1_CASTI_MODLITBY], _global_opt[OPT_2_HTML_EXPORT], _global_opt[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_4_OFFLINE_EXPORT], 
						a, str_modlitby[i], skratka_jazyka[_global_jazyk], parameter_M, export_dalsie_parametre); // modlitba `i'
					// 2008-11-29: rozličný export
					if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
						fprintf(batch_export_file, "\t<a href=\""FILENAME_EXPORT_DATE_SIMPLE"_%d%s.htm\">%s</a>%s, \n", _global_den.rok % 100, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /* char_modlitby[i] */, nazov_modlitby(i), export_doplnkova_psalmodia);
					}
					else{ // EXPORT_DATE_FULL
						fprintf(batch_export_file, "\t<a href=\""FILENAME_EXPORT_DATE_FULL"_%d%s.htm\">%s</a>%s, \n", _global_den.rok, _global_den.mesiac, _global_den.den, a, export_fname_modl_str /* char_modlitby[i] */, nazov_modlitby(i), export_doplnkova_psalmodia);
					}
				}
			}
		}
		fprintf(batch_export_file, "</li>\n");
	}// else if(export_monthly_druh >= 1)

	// napokon o1 vrátime späť
	_global_opt[OPT_1_CASTI_MODLITBY] = _global_opt_casti_modlitby_orig; // restore pôvodnej hodnoty

	Log("execute_batch_command(): koniec.\n");
}// execute_batch_command()

//---------------------------------------------------------------------
// _export_rozbor_dna()
//
// exportuje udaje, ktore nacitala _rozbor_dna()
// 2005-03-21: Pridany dalsi typ exportu - EXPORT_DNA_VIAC_DNI_SIMPLE
#define NEWLINE		{\
	if(typ == EXPORT_DNA_VIAC_DNI_SIMPLE){ \
		Export("; "); \
	} \
	else if(som_v_tabulke == NIE){ \
		if(typ == EXPORT_DNA_VIAC_DNI){ \
			Export("\n"HTML_LINE_BREAK""HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE"%s\n", html_text_alebo[_global_jazyk]); \
		} \
		else{ \
			if(typ != EXPORT_DNA_VIAC_DNI_TXT){ \
				Export("\n<p>\n"); \
			} \
		} \
	} \
	else{ \
		Export("</td>\n</tr>\n\n<tr "HTML_VALIGN_MIDDLE">\n<td></td>\n<td></td>\n<td>"); \
	} \
}

// 2012-08-23; upravené 2013-08-05 | zoznam[0] značí počet; zoznam[1] = _global_den; zoznam[2] až [MAX_POCET_SVATY+1] = _global_svaty(1)..._global_svaty(MAX_POCET_SVATY); zoznam[POCET_ZOZNAM-1] = _global_pm_sobota
#define POCET_ZOZNAM (MAX_POCET_SVATY + 3)
#define PORADIE_SVATY_NULL -1
short int zoznam[POCET_ZOZNAM]; 
// prvá hodnota, t. j. zoznam[0], určuje počet; ak je číslo > 10, znamená to, že ide o * 10 kvôli informácii o tom, že sa neexportuje modlitba cez deň a kompletórium pre ľubovoľné spomienky
// od druhej hodnoty reprezentuje: _global_den, _global_svaty(1)..._global_svaty(MAX_POCET_SVATY), _global_pm_sobota

void init_zoznam(void){
	zoznam[0] = 0;
	for(int i = 1; i < POCET_ZOZNAM; i++){
		zoznam[i] = PORADIE_SVATY_NULL;
	}
}// init_zoznam()

void Log_zoznam(void){
	for(int i = 0; i < POCET_ZOZNAM; i++){
		Log("zoznam[%d] == %d\n", i, zoznam[i]);
		// Export("zoznam[%d] == %d"HTML_LINE_BREAK"\n", i, zoznam[i]);
	}
}// Log_zoznam()

#define LOG_ZOZNAM /* zoznam[0] = pocet; */ Log_zoznam();

void _export_rozbor_dna_zoznam(short int typ){
	short int pocet = 1; // počet záznamov, ktoré sa exportujú (či už riadky tabuľky alebo len zoznam)
	short int poradie_svaty = PORADIE_SVATY_NULL, poradie_svaty_vedie = PORADIE_SVATY_NULL;
	short int aj_feria = NIE;

	Log("_export_rozbor_dna_zoznam(): začiatok...\n");
	init_zoznam();

	short int podmienka_svaty_vedie = NIE;
	short int podmienka_svaty_vedie_pom = NIE;
	Log("_global_den.smer == %d...\n", _global_den.smer);
	for(short int i = 0; i < MAX_POCET_SVATY; i++){
		Log("_global_svaty(%d).smer == %d...\n", i + 1, _global_svaty(i + 1).smer);
		// 2013-08-04: pridaná kontrola podmienky 'podmienka_svaty_vedie'
		if((_global_den.smer > _global_svaty(i + 1).smer) && !MIESTNE_SLAVENIE_LOKAL_SVATY(i + 1)){
			podmienka_svaty_vedie = ANO;
			poradie_svaty_vedie = i + 1; // vyberie posledný!!!
		}
		if(_global_den.smer > _global_svaty(i + 1).smer){
			podmienka_svaty_vedie_pom = ANO;
			poradie_svaty_vedie = i + 1; // vyberie posledný!!!
		}
	}
	Log("podmienka_svaty_vedie == %d\n", podmienka_svaty_vedie);
	Log("podmienka_svaty_vedie_pom == %d\n", podmienka_svaty_vedie_pom);
	Log("poradie_svaty_vedie == %d\n", poradie_svaty_vedie);

	Log("počet == %d\n", pocet);
	// pozor, hoci je nedela, predsa na nu mohlo pripadnut slavenie s vyssou prioritou
	if((_global_den.denvt == DEN_NEDELA) ||
		(_global_den.prik == PRIKAZANY_SVIATOK) ||
		(_global_den.smer < 5)){

		Log("nedele a prikázané sviatky...\n");
		// nedele a prikazane sviatky - cervenou, velkymi pismenami
		// slavnosti - velkymi pismenami

		// 23/02/2000A.D. -- teraz este testujeme, ci nema nahodou pred nedelou (trebars v obdobi cez rok, smer == 6) prednost napr. sviatok Pana (smer == 5); dalsia cast je skopirovana podla casti v _rozbor_dna, v poznamke SVATY_VEDIE
		// ... alebo c. 60: "ak na jeden den pripadnu viacere slavenia, uprednostni sa to, ktore ma v tabulke liturgickych dni vyssi stupen [t.j. .smer].

		// 2006-12-07: slávnosti svätých (k fixným dátumom: napr. 8.12., 29.6., 5.7., 15.8.), ktoré nepripadnú na nedeľu, neboli správne zobrazované
		// 2010-07-28: doplnené alternatívne porovnanie aj s _global_svaty2.smer (kvôli dominikánskej slávnosti 8.8.)
		// 2010-10-06: upravené; nesmie ísť o lokálnu slávnosť (smer == 4) lebo nemá prebíjať "globálnu" v danom kalendári [napr. czop pre 22.10.]
		// 2011-02-02: zadefinované MIESTNE_SLAVENIE_CZOP_SVATY(i), aby sa zjednodušila podmienka (platí len pre CZOP)
		// 2011-03-07: MIESTNE_SLAVENIE_CZOP_SVATY(i) použité aj pre iné lokálne slávenia ako MIESTNE_SLAVENIE_LOKAL_SVATY(i)
		if(podmienka_svaty_vedie == ANO){
			Log("podmienka_svaty_vedie == ANO...\n");
			poradie_svaty = poradie_svaty_vedie;
			zoznam[pocet] = poradie_svaty;
			LOG_ZOZNAM;
		}
		else{
			Log("podmienka_svaty_vedie == NIE...\n");
			poradie_svaty = 0;
			zoznam[pocet] = poradie_svaty;
			LOG_ZOZNAM;
			// 2010-10-06: upravené; v tejto vetve rozhodovania treba riešiť to, že je splnená základná podmienka (nedeľa alebo prikázaný sviatok alebo smer < 5),
			//             avšak nebola splnená vyššie uvedená novo-upravená podmienka o "prebití" nedele napr. lokálnou slávnosťou
			if(podmienka_svaty_vedie_pom == ANO){
				Log("podmienka_svaty_vedie_pom == ANO...\n");
				pocet = 2; // možno by bolo lepšie, keby tu bolo: pocet++;
				poradie_svaty = poradie_svaty_vedie;
				zoznam[pocet] = poradie_svaty;
				LOG_ZOZNAM;
			}
		}
	}// if((_global_den.denvt == DEN_NEDELA) || (_global_den.prik == PRIKAZANY_SVIATOK) || (_global_den.smer < 5))
	else if(_global_pocet_svatych > 0){
		Log("NIE nedele a prikázané sviatky; _global_pocet_svatych (%d) > 0...\n", _global_pocet_svatych);
		// sviatky (spomienky, ls) svatych
		// 2010-07-28: doplnené alternatívne porovnanie aj s _global_svaty2.smer (kvôli dominikánskej slávnosti 8.8.)
		// 2014-03-22: v skutočnosti môže byť podmienka_svaty_vedie_pom == ANO, a pritom podmienka_svaty_vedie == NIE
		if((podmienka_svaty_vedie_pom == ANO) ||
			((_global_den.smer == 9) && (_global_svaty1.smer == 12))){
			Log("svätý má prednosť...\n");
			// svaty
			// 2009-01-05: Vlado K. ma upozornil, že ak je smer svätý == 12, ale deň je 9 (bod 59. smerníc o LH a kalendári, č. 12), bolo by lepšie ponúknuť najprv deň a až potom ostatné slávenia 
			// 2010-05-21: Rastislav Hamráček SDB <rastohamracek@sdb.sk> upozornil defacto na to isté ako Vlado: aby to bolo podľa direktória
			// ----------------------------------------------------------------------------
			// 2005-08-22: pôvodne sa tu porovnávalo s 12, ale aj pre 11 (lokálne slávenia) by mal systém ponúknuť všedný deň - keď je to napr. v inej diecéze
			// 2009-11-26: porovnávame klasicky, resp. špeciálne pre body 4, 8, 11 [Miestne slávnosti, Miestne sviatky, Miestne povinné spomienky] pred touto úpravou tu bolo: if((_global_svaty1.smer >= 11) && atď.
			// 2010-05-21: sem presunuté potenciálne vypisovanie (export) všedného dňa pred prvého svätca, ak je ľubovoľná spomienka teraz vlastne obe vetvy vyzerajú rovnako, asi to zjednotím časom...
			// 2010-05-24: zjednotené; bolo odvetvené "if(_global_den.smer > _global_svaty1.smer)"; 
			//             else vetva mala napísané: "ľubovoľná spomienka svätého/svätých, pričom všedný deň má vyššiu prioritu slávenia"
			//             a ešte: "2010-05-21: odtiaľto presunuté potenciálne vypisovanie (export) všedného dňa pred prvého svätca, ak je ľubovoľná spomienka"
			// 2011-02-02: zadefinované MIESTNE_SLAVENIE_CZOP_SVATY(i), aby sa zjednodušila podmienka (platí len pre CZOP)
			// 2011-03-07: MIESTNE_SLAVENIE_CZOP_SVATY(i) použité aj pre iné lokálne slávenia ako MIESTNE_SLAVENIE_LOKAL_SVATY(i)
			// 2012-08-21: cdoplnená premenná (kvôli tomu, či sa majú pre svätca 1 zobraziť buttons modlitba cez deň)
			aj_feria = NIE;
			if(((_global_svaty1.smer >= 12) || MIESTNE_SLAVENIE_LOKAL_SVATY(1)) && (typ != EXPORT_DNA_VIAC_DNI)){
				Log("nastavujem: aj féria...\n");
				// ak je to iba lubovolna spomienka, tak vsedny den
				// 2010-05-21: NEWLINE; bolo pred; musíme ho zaradiť za :)
				aj_feria = ANO;
			}
			if(aj_feria == ANO){
				Log("spracúvam, keďže je aj féria (pocet == %d)...\n", pocet);
				// ak je to iba lubovolna spomienka, tak vsedny den
				poradie_svaty = 0;
				zoznam[pocet] = poradie_svaty;
				pocet++;
				LOG_ZOZNAM;
			}
			// 2010-05-21: pôvodne bolo: "sviatok, spomienka alebo ľubovoľná spomienka svätého/svätých, ide prv ako všedný deň"; dnes ide prv len ak je to sviatok alebo spomienka 
			// (a vlastne vtedy sa všedný deň vypisuje len pre lokálne sviatky resp. spomienky) 
			for(short int i = 0; i < MAX_POCET_SVATY; i++){
				Log("i == %d; pocet == %d...\n", i, pocet);
				if(_global_pocet_svatych > i){
					Log("_global_pocet_svatych (%d) > i (%d)...\n", _global_pocet_svatych, i);
					poradie_svaty = i + 1;
					Log("poradie_svaty == %d...\n", poradie_svaty);
					if(poradie_svaty == 1){
						// podmienka pre 1. svätého je iná ako pre 2. a ďalšieho
						if((aj_feria) && (!MIESTNE_SLAVENIE_LOKAL_SVATY(poradie_svaty))){
							poradie_svaty *= 10;
						}
					}
					else{
						if((!MIESTNE_SLAVENIE_LOKAL_SVATY(poradie_svaty))){
							poradie_svaty *= 10;
						}
					}
					if((poradie_svaty != 1) && (poradie_svaty != 10)){
						pocet++;
					}
					zoznam[pocet] = poradie_svaty;
					LOG_ZOZNAM;
				}
			}
		}// svaty ma prednost
		else{
			Log("prednosť má deň...\n");
			// prednost ma den
			poradie_svaty = 0;
			zoznam[pocet] = poradie_svaty;
			LOG_ZOZNAM;
		}// prednost ma den
	}// if(_global_pocet_svatych > 0)
	else{
		Log("NIE nedele a prikázané sviatky; obyčajný deň | _global_pocet_svatych (%d) == 0...\n", _global_pocet_svatych);
		// obycajne dni, nie sviatok
		poradie_svaty = 0;
		zoznam[pocet] = poradie_svaty;
		LOG_ZOZNAM;
	}// if(equals(_global_den.meno, STR_EMPTY))

	Log("počet == %d (pred kontrolou PM v sobotu; POCET_ZOZNAM == %d)\n", pocet, POCET_ZOZNAM);

	// este spomienka panny marie v sobotu, cl. 15
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			((_global_den.smer >= 11) && (_global_pocet_svatych == 0)) ||
			(((_global_svaty1.smer >= 12) || MIESTNE_SLAVENIE_LOKAL_SVATY(1)) && (_global_pocet_svatych > 0))
		) && 
		(typ != EXPORT_DNA_VIAC_DNI)){
		Log("je aj spomienka PM v sobotu...\n");
		// 2005-08-22: pôvodne sa tu porovnávalo s 12, ale aj pre 11 (lokálne slávenia) by mal systém ponúknuť (v sobotu) spomienku p. márie - keď je to napr. v inej diecéze 
		// 2006-02-02: pridané posv. čítania a upravené; keďže smer == 11 používame pre lokálne povinné spomienky, upravili sme kontrolu z 12 na 11
		// 2011-02-02: zadefinované MIESTNE_SLAVENIE_CZOP_SVATY(i), aby sa zjednodušila podmienka (platí len pre CZOP)
		// 2011-03-07: MIESTNE_SLAVENIE_CZOP_SVATY(i) použité aj pre iné lokálne slávenia ako MIESTNE_SLAVENIE_LOKAL_SVATY(i)
		poradie_svaty = PORADIE_PM_SOBOTA;
		poradie_svaty *= 10;
		pocet++;
		zoznam[pocet] = poradie_svaty;
		LOG_ZOZNAM;
	}
	zoznam[0] = pocet;
	Log("počet == %d\n", pocet);
	Log("_export_rozbor_dna_zoznam(): koniec.\n");
	LOG_ZOZNAM;
}// _export_rozbor_dna_zoznam()

void _export_rozbor_dna_interpretuj_zoznam(short int export_typ, short int typ, short int som_v_tabulke, char batch_command[MAX_STR], short int modlitba, short int d_from_m_from_r_from){
	short int poradie_svaty;
	short int zobrazit_mcd = ANO;
	short int pocet = zoznam[0];
	short int _global_opt_orig; // pre o4

	Log("_export_rozbor_dna_interpretuj_zoznam(): začiatok (pocet == %d)...\n", pocet);

	if(pocet > POCET_ZOZNAM - 1){
		pocet = POCET_ZOZNAM - 1;
	}
	for(int i = 1; i <= pocet; i++){
		poradie_svaty = zoznam[i];
		zobrazit_mcd = ANO;

		Log("_export_rozbor_dna_interpretuj_zoznam(): i == %d, poradie_svaty == zoznam[i] == %d...\n", i, poradie_svaty);

		if(poradie_svaty <= PORADIE_SVATY_NULL){
			continue;
		}

		if(poradie_svaty >= 10){
			poradie_svaty /= 10;
			zobrazit_mcd = NIE;
		}

		Log("_export_rozbor_dna_interpretuj_zoznam(): option %d = %d\n", OPT_4_OFFLINE_EXPORT, _global_opt[OPT_4_OFFLINE_EXPORT]);

		// 2014-10-03: úprava o4 pre indikovanie, že sa nemajú exportovať buttony pre niektoré modlitby
		_global_opt_orig = _global_opt[OPT_4_OFFLINE_EXPORT]; // backup pôvodnej hodnoty
		
		if(!((zobrazit_mcd == ANO) || (poradie_svaty == 0))){
			// nastavenie parametra o4: pridáme BIT_OPT_4_EXCLUDE_MCD_KOMPLET pre indikovanie, že sa nemajú exportovať buttony pre niektoré modlitby
			if((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_EXCLUDE_MCD_KOMPLET) != BIT_OPT_4_EXCLUDE_MCD_KOMPLET){
				Log("Pre option %d nastavujem bit pre '%d'\n", OPT_4_OFFLINE_EXPORT, BIT_OPT_4_EXCLUDE_MCD_KOMPLET);
				_global_opt[OPT_4_OFFLINE_EXPORT] += BIT_OPT_4_EXCLUDE_MCD_KOMPLET;
				Log("option %d = %d\n", OPT_4_OFFLINE_EXPORT, _global_opt[OPT_4_OFFLINE_EXPORT]);
			}// zmena: indikovanie, že sa nemajú exportovať buttony pre niektoré modlitby
			/*
			else{
				Log("Pre option %d ruším bit pre '%d'\n", OPT_4_OFFLINE_EXPORT, BIT_OPT_4_EXCLUDE_MCD_KOMPLET);
				_global_opt[OPT_4_OFFLINE_EXPORT] -= BIT_OPT_4_EXCLUDE_MCD_KOMPLET;
			}
			*/
		}

		if(export_typ == EXPORT_TYP_BATCH_MODE){
			execute_batch_command(poradie_svaty, batch_command, zobrazit_mcd, modlitba, d_from_m_from_r_from);
		}
		else if(export_typ == EXPORT_TYP_WEB_MODE){
			if((i > 1) && (typ != EXPORT_DNA_XML)){
				NEWLINE;
			}
			_export_rozbor_dna_buttons(typ, poradie_svaty, ANO, zobrazit_mcd);
		}
		else{
			// nepodporovaný export
		}

		// 2014-10-03: úprava o4
		_global_opt[OPT_4_OFFLINE_EXPORT] = _global_opt_orig; // restore pôvodnej hodnoty
	}
	Log("_export_rozbor_dna_interpretuj_zoznam(): koniec.\n");
}// _export_rozbor_dna_interpretuj_zoznam()

void _export_rozbor_dna(short int typ){
// treba brat do uvahy:
// 1. ked ma sviatok prioritu, tak ide on (ulozeny v _global_den, ak pocet_svatych == 0; resp. v _global_svaty1, ak pocet_svatych > 0;)
// 2. ked su lubovolne spomienky, su ulozene v premennych
//    _global_svaty1 (_global_pocet_svatych == 1),
//    _global_svaty2 (_global_pocet_svatych == 2),
//    _global_svaty3 (_global_pocet_svatych == 3),
//    naviac treba napisat _global_den (ako vsedny den)
// 3. ak ide o sobotu v OBD_CEZ_ROK, treba ponuknut moznost _global_pm_sobota (spomienka panny marie v sobotu)
	short int i;
	char pom1[SMALL] = STR_EMPTY;
	char ciarka = ' ';     // 2003-08-11 bolo tu 0
	char dvojbodka = ' ';  // 2003-08-11 bolo tu 0
	char pom2[SMALL] = STR_EMPTY;
	char pom3[SMALL] = STR_EMPTY;
	short int som_v_tabulke = ANO; // 2009-08-26: či sa používa tabuľka; bežne pre web áno, pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku

	Log("-- _export_rozbor_dna(typ == %d): začiatok...\n", typ);

if (!((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BUTTONS_ORDER) == BIT_OPT_0_BUTTONS_ORDER)) {
	if((typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
		_export_rozbor_dna_buttons_dni(typ);
		Export("<p></p>\n"); // 2011-01-27: doplnené oddelenie
	}
}

	if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna(typ == %d): keďže sme v _global_opt_batch_monthly == ANO a export_monthly_druh (%d) > 2, nebudeme exportovať tabuľku...\n", typ, export_monthly_druh);
	}
	if((typ == EXPORT_DNA_VIAC_DNI_TXT) || (typ == EXPORT_DNA_XML)){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): kvôli typu nebudeme exportovať tabuľku...\n", typ);
	}

	// XML export -- začiatok pre daný deň (dátum)
	if(typ == EXPORT_DNA_XML){
		som_v_tabulke = NIE;
		Export(ELEM_BEGIN(XML_DAY)"\n");
		Export(ELEM_BEGIN(XML_DATE_ISO)""HTML_ISO_FORMAT""ELEM_END(XML_DATE_ISO)"\n", _global_den.rok, _global_den.mesiac, _global_den.den);
		Export(ELEM_BEGIN(XML_DATE_DAY)"%d"ELEM_END(XML_DATE_DAY)"\n", _global_den.den);
		Export(ELEM_BEGIN(XML_DATE_MONTH)"%d"ELEM_END(XML_DATE_MONTH)"\n", _global_den.mesiac);
		Export(ELEM_BEGIN(XML_DATE_YEAR)"%d"ELEM_END(XML_DATE_YEAR)"\n", _global_den.rok);
		Export(ELEM_BEGIN(XML_DAY_OF_YEAR)"%d"ELEM_END(XML_DAY_OF_YEAR)"\n", _global_den.denvr);
		Export(ELEMID_BEGIN(XML_DAY_OF_WEEK)"%s"ELEM_END(XML_DAY_OF_WEEK)"\n", _global_den.denvt, nazov_dna(_global_den.denvt));
	}

	if(typ != EXPORT_DNA_VIAC_DNI && som_v_tabulke == ANO){
		// 2009-08-26: pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku
		Export("\n<!-- tabuľka obsahujúca jednotlivé slávenia pre daný dátum s odkazmi na modlitby (buttons) -->\n"); // 2011-01-26: doplnený popis
		Export("\n<table "HTML_ALIGN_CENTER">\n");
	}
	// vytvorenie linku
	if(typ == EXPORT_DNA_VIAC_DNI){
		// 2005-03-22: Upravene. Da sa dat aj ISO-8601 datum. 
		// 2006-01-15: Vzhľadom k zmene default hodnoty zmenená podmienka (pôvodne: NIE).
		// 2007-06-01: Zmenené - namiesto _global_opt 2 sa kontroluje nová _global_opt 7.
		if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ISO_DATUM) == BIT_OPT_2_ISO_DATUM){
			i = LINK_ISO_8601;
		}else{
			i = LINK_DEN;
		}
		mystrcpy(pom1, "<"HTML_SPAN_BOLD">", SMALL);
		mystrcpy(pom2, HTML_SPAN_END, SMALL);
		mystrcpy(pom3, nazov_Dn(_global_den.denvt), SMALL);
		if(som_v_tabulke == NIE)
			dvojbodka = '.';
	}// typ == EXPORT_DNA_VIAC_DNI
	else if(typ == EXPORT_DNA_VIAC_DNI_SIMPLE){
		// 2005-03-22: Upravene. Da sa dat aj ISO-8601 datum. 
		// 2006-01-15: Vzhľadom k zmene default hodnoty zmenená podmienka (pôvodne: NIE).
		// 2007-06-01: Zmenené - namiesto _global_opt 2 sa kontroluje nová _global_opt 7.
		if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_ISO_DATUM) == BIT_OPT_2_ISO_DATUM){
			i = LINK_ISO_8601;
		}
		else{
			i = LINK_DEN;
		}
		mystrcpy(pom3, nazov_Dn(_global_den.denvt), SMALL);
	}// typ == EXPORT_DNA_VIAC_DNI_SIMPLE
	else if(typ == EXPORT_DNA_VIAC_DNI_TXT){
		i = LINK_DEN_MESIAC_NIE;
		dvojbodka = 0;
		ciarka = 0;
	}// typ == EXPORT_DNA_VIAC_DNI_TXT
	else{
		i = LINK_DEN_MESIAC_NIE; // 2008-01-22: zmenené, pôvodne tu bolo LINK_DEN_MESIAC_ROK
		// najprv toto, -- if(_global_den.denvt != DEN_NEDELA) mystrcpy(pom3, nazov_dna(_global_den.denvt), SMALL);
		// potom toto: -- if((_global_den.denvt != DEN_NEDELA) 
		//	-- zapoznamkovane && (!equals(_global_den.meno, STR_EMPTY))
		//	) ciarka = ',';
		dvojbodka = ' '; // 2008-01-22: zmenené, pôvodne tu bolo dvojbodka = ':';
	}// typ != EXPORT_DNA_VIAC_DNI ani EXPORT_DNA_VIAC_DNI_SIMPLE ani EXPORT_DNA_VIAC_DNI_TXT

	if(i == LINK_DEN_MESIAC_NIE){
		mystrcpy(_global_link, STR_EMPTY, MAX_STR);
	}
	else{
		vytvor_global_link_class(_global_den.den, _global_den.mesiac, _global_den.rok, i, NIE, HTML_CLASS_NAME_CALENDAR_DAY);
		// 2006-08-19: okrem premennej _global_string táto funkcia ešte naplní aj _global_string2 a _global_string_farba
	}

	// export vytvoreného linku
	if(som_v_tabulke == ANO){
		Export("\n<tr "HTML_VALIGN_MIDDLE">\n");
	}

	// zmenene <div align> na priamo do <td>, 2003-07-09 kvoli HTML 4.01

	Log("-- _export_rozbor_dna(typ == %d): pomocné výpisy...\n", typ);

	Log("pom1 == %s\n", pom1);
	Log("_global_link == %s\n", _global_link);
	Log("pom2 == %s\n", pom2);
	Log("_global_opt_batch_monthly == %d\n", _global_opt_batch_monthly);
	Log("export_monthly_druh == %d\n", export_monthly_druh);

	// prvy stlpec: cislo dna
	if(som_v_tabulke == ANO){
		Export("<td "HTML_ALIGN_RIGHT" "HTML_VALIGN_TOP">");
	}
	if(typ != EXPORT_DNA_XML){
		Export("%s%s%s", pom1, _global_link, pom2);
		if(dvojbodka > 0)
			Export("%c", dvojbodka);
	}
	if(som_v_tabulke == ANO){
		Export("</td>");
		Export("\n");
	}
	else{
		if((typ != EXPORT_DNA_JEDEN_DEN) && (typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
			Export(HTML_NONBREAKING_SPACE);
		}
	}
	
	// druhy stlpec: nazov dna 
	// 2005-03-21: Vypisujeme, iba ak typ != EXPORT_DNA_VIAC_DNI_SIMPLE  && (typ != EXPORT_DNA_XML) (2012-10-12)
	if((typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_XML)){
		if(som_v_tabulke == ANO){
			Export("<td "HTML_ALIGN_LEFT" "HTML_VALIGN_TOP">");
		}
		Export("%s%s%s", pom1, pom3, pom2);
		if(ciarka > 0)
			Export("%c", ciarka);
		if(som_v_tabulke == ANO){
			Export("</td>");
			Export("\n");
		}
		else{
			if((typ != EXPORT_DNA_JEDEN_DEN) && (typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
				Export(HTML_NONBREAKING_SPACE);
				Export("\n");
			}
		}
	}

	// ďalší stĺpec: buttons (tlačidlá), podľa typu výpisu
	if(som_v_tabulke == ANO){
		Export("<td "HTML_VALIGN_MIDDLE">");
	}

	// 2012-08-23: kód presunutý do funkcie _export_rozbor_dna_zoznam(); a _export_rozbor_dna_interpretuj_zoznam();
	_export_rozbor_dna_zoznam(typ);
	// Log_zoznam();
	_export_rozbor_dna_interpretuj_zoznam(EXPORT_TYP_WEB_MODE, typ, som_v_tabulke, (char *)STR_EMPTY, 0, 0);

	if(typ == EXPORT_DNA_VIAC_DNI){
		// ďalší stĺpec: rímske číslo podľa týždňa žaltára, pre nedele aj liturgický rok A, B resp. C
		if(som_v_tabulke == ANO){
			Export("</td>\n<td "HTML_VALIGN_MIDDLE">\n");
			Export("<div "HTML_ALIGN_RIGHT">"); // 2006-08-19: podľa mňa zbytočne sa to vypisovalo aj pri obyčajnom exporte 1 dňa
		}
		else{
			Export(HTML_NONBREAKING_SPACE);
			Export("\n");
		}
		// vypisanie rimskeho cisla (citanie)
		Export("%s", _global_string2);
		if(som_v_tabulke == ANO){
			Export(HTML_DIV_END);
		}
	}// (typ == EXPORT_DNA_VIAC_DNI)
	else if(typ == EXPORT_DNA_XML){
		Export(ELEM_BEGIN(XML_STRING_VOLUME)"%s"ELEM_END(XML_STRING_VOLUME)"\n", _global_string2);
	}

	if(som_v_tabulke == ANO){
		Export("</td>\n</tr>\n");
	}
	else{
		if((typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
			Export("<p>\n");
		}
	}
	// EXPORT_DNA_VIAC_DNI: predpoklada, ze sme v tabulke, <table>
	if(typ != EXPORT_DNA_VIAC_DNI && som_v_tabulke == ANO){
		// 2009-08-26: pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku
		Export("</table>\n");
	}

	if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){

		if((_global_linky == ANO) || ((_global_opt_batch_monthly == ANO) && (export_monthly_druh >= 2))){ // pridane 13/04/2000A.D.; upravené 2009-08-12

			// 2007-08-15: vložené vypísanie kalendára a hlavného formulára 
			// 2011-01-27: tu bolo kedysi volanie _export_rozbor_dna_buttons_dni(typ); -- presunuté vyššie
			if ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BUTTONS_ORDER) == BIT_OPT_0_BUTTONS_ORDER) {
				Export("<p></p>\n"); // 2011-01-26: doplnené oddelenie
				if((typ != EXPORT_DNA_VIAC_DNI_TXT) && (typ != EXPORT_DNA_XML)){
					_export_rozbor_dna_buttons_dni(typ);
				}
			}

			Export("\n<!--BEGIN: kalendárik-->\n");
			if((_global_opt_batch_monthly == ANO) && (export_monthly_druh > 2)){
				// 2009-08-26: doplnené; 2011-04-13: podmienka rozšírená vyššie ((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE) && (typ != EXPORT_DNA_VIAC_DNI_TXT))
				Log("pre tento typ exportu sa kalendárik negeneruje\n");
			}
			else{
				_export_rozbor_dna_kalendar(typ);
			}
			Export("<!--END: kalendárik-->\n");

			Export("\n<!--BEGIN: veľká tabuľka s kalendárom a hlavným formulárom-->\n");
/*
			// 2012-10-22: úplne zapoznámkované
			if(_global_linky == ANO){
				// 2008-01-22: podľa Vladovho návrhu presunutý nadpis sem
				Export("<p "HTML_CLASS_BOLD_IT" "HTML_ALIGN_CENTER">\n");
				Export((char *)html_text_dalsie_moznosti[_global_jazyk]); // 2006-08-02: jazykové mutácie; \n presunutý pred <table>; staršia poznámka: 2003-07-16; kedysi tu bolo "Chcem zobraziť"
				Export("</p>\n");
			}// if(_global_linky == ANO)
*/
			Log("_global_opt_batch_monthly == %d [2011-04-13]\n", _global_opt_batch_monthly);
			Log("export_monthly_druh == %d [2011-04-13]\n", export_monthly_druh);

			if(_global_linky == ANO){
				// Export("\n<!-- prázdny riadok ako oddelenie -->\n");
				// Export("<br/>\n");
				Export("<!--nasleduje formulár-->\n");
				_export_main_formular(_global_den.den, _global_den.mesiac, _global_den.rok, _global_den.denvt);
			}// if(_global_linky == ANO)

			Export("<!--END: veľká tabuľka s kalendárom a hlavným formulárom-->\n");
		}
	}// (typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_TXT)
	else{
		Log("-- _export_rozbor_dna(): skip...\n");
	}

	// XML export -- koniec pre daný deň (dátum)
	if(typ == EXPORT_DNA_XML){
		Export(ELEM_END(XML_DAY)"\n\n");
	}

	Log("-- _export_rozbor_dna(typ == %d): koniec.\n", typ);
}// _export_rozbor_dna()

void _export_rozbor_dna_batch(short int typ, short int modlitba = MODL_NEURCENA, short int d_from_m_from_r_from = 0){
// poznamky bez uvedenia datumu su prevzate z _export_rozbor_dna; 2003-07-07

// treba brat do uvahy:
// 1. ked ma sviatok prioritu, tak ide on (ulozeny v _global_den, ak pocet_svatych == 0; resp. v _global_svaty1, ak pocet_svatych > 0;)
// 2. ked su lubovolne spomienky, su ulozene v premennych _global_svaty1 (_global_pocet_svatych == 1), _global_svaty2 (_global_pocet_svatych == 2), _global_svaty3 (_global_pocet_svatych == 3),
//    naviac treba napisat _global_den (ako vsedny den)
// 3. ak ide o sobotu v OBD_CEZ_ROK, treba ponuknut moznost _global_pm_sobota (spomienka panny marie v sobotu)
// 4. ak ide o ľubovoľné spomienky, odkaz na modlitbu cez deň má byť pre všedný deň (== 0) [2014-10-03, Laci Dvornik]

// 2009-08-04: rozšírené o nepovinný vstupný parameter 'modlitba', ktorý hovorí, či sa majú exportovať všetky modlitby (ako doteraz) alebo len táto modlitba (pre export_monthly_druh >= 1)
	char batch_command[MAX_STR] = STR_EMPTY;
	// ak vypisovat do jednotlivych suborov, 2003-07-08
	if(_global_opt_append != YES){
		// pripravime si command line string pre dany datum
		// 2008-11-29: rozličný export
		if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
			sprintf(batch_command, "%s -i%s -qpdt -d%d -m%d -r%d -u%d -e"FILENAME_EXPORT_DATE_SIMPLE"_", 
				name_binary_executable, include_dir, 
				_global_den.den, _global_den.mesiac, _global_den.rok,
				_global_opt_export_date_format,
				_global_den.rok % 100, _global_den.mesiac, _global_den.den);
		else // EXPORT_DATE_FULL
			sprintf(batch_command, "%s -i%s -qpdt -d%d -m%d -r%d -u%d -e"FILENAME_EXPORT_DATE_FULL"_", 
				name_binary_executable, include_dir, 
				_global_den.den, _global_den.mesiac, _global_den.rok,
				_global_opt_export_date_format,
				_global_den.rok, _global_den.mesiac, _global_den.den);
	}
	// v opacnom pripade je furt ten isty fajl, 2003-07-08, pridame tam aj "-a1" = append
	else{
		sprintf(batch_command, "%s -i%s -qpdt -d%d -m%d -r%d -a1 -e%s.htm", 
			name_binary_executable, include_dir, 
			_global_den.den, _global_den.mesiac, _global_den.rok,
			_global_string); // _global_string sa nastavi v _main_batch_mode();
	}
	Log("_export_rozbor_dna_batch(): batch_command == %s...\n", batch_command);

	Log("vo funkcii _export_rozbor_dna_batch() volám _export_rozbor_dna_zoznam()...\n");
	_export_rozbor_dna_zoznam(typ);

	// Log_zoznam();

	Log("vo funkcii _export_rozbor_dna_batch() volám _export_rozbor_dna_interpretuj_zoznam()...\n");
	_export_rozbor_dna_interpretuj_zoznam(EXPORT_TYP_BATCH_MODE, typ, 0, batch_command, modlitba, d_from_m_from_r_from);

}// _export_rozbor_dna_batch()

void _export_rozbor_dna_mesiaca_batch(short int d, short int m, short int r){
// 2009-08-12: vytvorené podľa _export_rozbor_dna_batch() a execute_batch_command()
	Log("_export_rozbor_dna_mesiaca_batch() -- začiatok\n");
	// časť podľa _export_rozbor_dna_batch() 
	char batch_command[MAX_STR] = STR_EMPTY;
	char str_den[SMALL] = STR_EMPTY;
	char str_subor[SMALL] = STR_EMPTY;
	char str_month[SMALL] = STR_EMPTY;
	char _local_export_navig_hore[SMALL] = STR_EMPTY;
	char pom[SMALL] = STR_EMPTY; // pomocný reťazec (priliepanie parametrov do export_dalsie_parametre)
	char export_dalsie_parametre[SMALL] = STR_EMPTY; // reťazec pre kalendár (export_kalendar); 2011-11-30: pridaný do toho istého reťazca aj font

	// 2010-08-04: pridané odovzdanie parametra pre kalendár 
	// 2010-09-14: podmienka opravená; ak nie je kalendár určený resp. je všeobecný pre daný jazyk, nie je potrebné ho exportovať
	// 2011-03-18: použité z iných miest aj v _export_rozbor_dna_mesiaca_batch() -- exportovanie parametra k (_global_kalendar)
	strcpy(export_dalsie_parametre, STR_EMPTY);
	// 2011-03-18: použité z iných miest aj v execute_batch_command() -- exportovanie parametra k (_global_kalendar)
	if(PODMIENKA_EXPORTOVAT_KALENDAR){
		sprintf(pom, " -k%s", skratka_kalendara[_global_kalendar]);
	}
	else{
		Log("\tNetreba prilepiť kalendár (jazyk == %s, kalendár == %s)\n", skratka_jazyka[_global_jazyk], skratka_kalendara[_global_kalendar]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem kalendár: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// 2011-11-30: exportovanie parametra F (_global_font)
	if(PODMIENKA_EXPORTOVAT_FONT){
		sprintf(pom, " -F%s", nazov_fontu[_global_font]);
	}
	else{
		Log("\tNetreba prilepiť font (font == %s)\n", nazov_fontu[_global_font]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem font: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// 2011-11-30: exportovanie parametra S (_global_font_size)
	if(PODMIENKA_EXPORTOVAT_FONTSIZE){
		sprintf(pom, " -S%s", nazov_font_size_css[_global_font_size]);
	}
	else{
		Log("\tNetreba prilepiť font size (size == %s)\n", nazov_font_size_css[_global_font_size]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem font size: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// 2013-12-12: exportovanie parametra c (_global_css)
	if(PODMIENKA_EXPORTOVAT_CSS){
		sprintf(pom, " -c%s", skratka_css[_global_css]); // nazov_css[_global_css]
	}
	else{
		Log("\tNetreba prilepiť css (css == %s/%s)\n", skratka_css[_global_css], nazov_css[_global_css]);
		strcpy(pom, STR_EMPTY);
	}
	strcat(export_dalsie_parametre, pom);
	Log("Exportujem css: export_dalsie_parametre == `%s'\n", export_dalsie_parametre);

	// reťazec pre deň a pre názov súboru
	if(d != VSETKY_DNI){
		LOG_ciara;
		Log("deň d == %d...\n", d);
		sprintf(str_den, "%d", d);
		if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
			sprintf(str_subor, FILENAME_EXPORT_DATE_SIMPLE, r % 100, m, d);
		else // EXPORT_DATE_FULL
			sprintf(str_subor, FILENAME_EXPORT_DATE_FULL, r, m, d);
		mystrcpy(_local_export_navig_hore, _global_export_navig_hore_month, SMALL);
	}
	else{
		// d == VSETKY_DNI
		Log("deň d == VSETKY_DNI...\n");
		mystrcpy(str_den, STR_VSETKY_DNI, SMALL);
		if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
			sprintf(str_subor, FILENAME_EXPORT_MONTH_SIMPLE, r % 100, m);
		else // EXPORT_DATE_FULL
			sprintf(str_subor, FILENAME_EXPORT_MONTH_FULL, r, m);
		// mystrcpy(_local_export_navig_hore, _global_export_navig_hore, SMALL);
		sprintf(_local_export_navig_hore, "..%s%s", STR_PATH_SEPARATOR_HTML, name_batch_html_file);
		// vypísanie linku do zoznamu mesiacov (len v prípade d == VSETKY_DNI) -- ten istý adresár
		if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
			sprintf(str_month, "."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_SIMPLE""STR_PATH_SEPARATOR_HTML, r % 100, m, nazov_mes[m - 1]);
		else // EXPORT_DATE_FULL
			sprintf(str_month, "."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_FULL""STR_PATH_SEPARATOR_HTML, r, m, nazov_mesiaca_asci(m - 1));
		Log("str_month == %s\n", str_month);
		if(_global_jazyk == JAZYK_HU){
			fprintf(batch_html_file, "<li><a href=\"%s%s.htm\">%d. %s</a></li>\n", str_month, str_subor, r, nazov_mesiaca(m - 1));
		}
		else{
			fprintf(batch_html_file, "<li><a href=\"%s%s.htm\">%s %d</a></li>\n", str_month, str_subor, nazov_mesiaca(m - 1), r);
		}
	}
	if(_global_opt_append != YES){
		Log("pripravíme si command-line string pre daný mesiac...\n");
		// pripravíme si command-line string pre daný mesiac
		sprintf(batch_command, "%s -i%s -qpdt -d%s -m%d -r%d -u%d -e%s.htm", name_binary_executable, include_dir, str_den, m, r, _global_opt_export_date_format, str_subor);
		Log("batch_command == `%s'...\n", batch_command);
	}

	// časť podľa execute_batch_command() 
	FILE *batch_export_file = NULL;
	char parameter_M[SMALL] = STR_EMPTY; // parametre pre výsledné HTML (parameter 'M' a parametre pre odkazy na súbory, napr. 'I')
	char parameter_I[SMALL] = STR_EMPTY;
	if(_global_opt_batch_monthly == ANO){
		Log("1:parameter_M...\n");
		sprintf(parameter_M, " -M%d", export_monthly_druh);
		Log("parameter_M == `%s'...\n", parameter_M);
		if(!(equals(_local_export_navig_hore, STR_EMPTY) || equals(_local_export_navig_hore, DEFAULT_MONTH_EXPORT))){
			Log("parameter_I...\n");
			sprintf(parameter_I, " -I%s", _local_export_navig_hore);
			Log("parameter_I == `%s'...\n", parameter_I);
			strcat(parameter_M, parameter_I);
			Log("parameter_M == `%s'...\n", parameter_M);
		}
		batch_export_file = batch_html_file;
	}// if(_global_opt_batch_monthly == ANO)
	else{
		batch_export_file = batch_html_file;
		mystrcpy(parameter_M, STR_EMPTY, SMALL);
	}// else if(_global_opt_batch_monthly == ANO)

	// samotné vytlačenie príkazu
	// 2011-04-13: doplnené exportovanie chýbajúcich option 0 až 4
	// 2012-12-12: nie pre append (mohla by tam byť celá časť kódu od prípravy batch_command)
	if(_global_opt_append != YES){
		Log("zapisujem do batch_file...\n");
		Log("5:parameter_M == `%s'...\n", parameter_M);
		fprintf(batch_file, "%s -0%d -1%d -2%d -3%d -4%d -j%s%s%s\n", batch_command, 
			_global_opt[OPT_0_SPECIALNE], _global_opt[OPT_1_CASTI_MODLITBY], _global_opt[OPT_2_HTML_EXPORT], _global_opt[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_4_OFFLINE_EXPORT], 
			skratka_jazyka[_global_jazyk], parameter_M, export_dalsie_parametre);
	}
	Log("_export_rozbor_dna_mesiaca_batch() -- koniec\n");
}// _export_rozbor_dna_mesiaca_batch()

//---------------------------------------------------------------------

// 2011-10-28: vytvorené podľa je_1cit_vlastne()
short int je_mozne_spol_cast_nebrat(short int poradie_svaty){
	Log("je_mozne_spol_cast_nebrat(%d): ", poradie_svaty);
	short int ret;
	ret = TRUE; // default

	if(poradie_svaty == 0){
		if((_global_den.typslav == SLAV_SLAVNOST) || (_global_den.typslav == SLAV_SVIATOK))
			ret = FALSE;
	}
	else if(poradie_svaty < PORADIE_PM_SOBOTA){
		if((_global_svaty(poradie_svaty).typslav == SLAV_SLAVNOST) || (_global_svaty(poradie_svaty).typslav == SLAV_SVIATOK))
			ret = FALSE;
	}
	// netreba else if poradie_svaty == PORADIE_PM_SOBOTA | 2012-10-22: spomienka PM v sobotu je vždy ľubovoľná spomienka

	if((_global_den.den == 2) && (_global_den.mesiac - 1 == MES_NOV)){
		ret = FALSE;
	}// NOV02 == 02NOV
	Log("%d\n", ret);
	return ret;
}// je_mozne_spol_cast_nebrat()

// showDetails(): vytvorena v Trencine, 29/01/2000A.D.
// vyskusat Run -> Arguments...: `-qpdt -r2000 -m1 -d20 -x1 -p* -1nie -2sviatku'
// 2003-08-13: vo VC++ je to Project->Settings zalozka Debug, Program arguments

//---------------------------------------------------------------------
// ked stlaci button 'Detaily...' pri konretnej modlitbe, zavola sa z funkcie rozbor_dna_s_modlitbou() toto vypisanie detailov (options) pre konretnu modlitbu
// vela z jadra je prevzateho z funkcie _main_dnes()
// 2011-10-03: prerobená; opätovne sprístupnená
void showDetails(short int den, short int mesiac, short int rok, short int poradie_svaty){
	Log("showDetails(%d, %s, %d, %d) -- začiatok...\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
	Log("_global_den: \n");
	Log(_global_den);

	char pom2[MAX_STR]; // 2006-08-01: pridané
	mystrcpy(pom2, STR_EMPTY, MAX_STR); // 2006-07-31: pridané
	char pom3[MAX_STR]; // 2008-08-08: pridané
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	prilep_request_options(pom2, pom3);

	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);

	// úvodná navigácia
	if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_NAVIGATION) == BIT_OPT_2_NAVIGATION){
		Export("<!-- navigácia začiatok -->\n");
		_export_rozbor_dna_buttons_dni(EXPORT_DNA_JEDEN_DEN, NIE);
		// najprv dni, potom modlitby
		Export("<table "HTML_ALIGN_CENTER">\n<tr><td>\n");
		_export_rozbor_dna_buttons(EXPORT_DNA_JEDEN_DEN, _global_poradie_svaty, NIE, ANO);
		Export("</td></tr>\n</table>\n");
	}

	// začiatok formulára
	Export(HTML_NEW_PARAGRAPH);
	Export((char *)html_text_detaily_uvod[_global_jazyk]);
	Export("</p>\n");
	sprintf(action, "%s?%s=%s&%s=%d&%s=%d&%s=%d&%s=%d%s",
	// Export("<form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d&%s=%d%s\" method=\"post\">\n",
		uncgi_name,
		STR_QUERY_TYPE, STR_PRM_DATUM, // chvilu tu bolo PRM_DETAILY
		STR_DEN, den,
		STR_MESIAC, mesiac,
		STR_ROK, rok,
		STR_DALSI_SVATY, poradie_svaty,
		pom2);
	Export_HtmlFormPOST(action);

	Export("<ul>\n");

	Export("<li>");
	Export((char *)html_text_modlitba[_global_jazyk]);
	Export(" \n");

	// pole WWW_MODLITBA
	// ToDo: zvážiť pre slávnosti zobraziť aj prvé vešpery s kompletóriom...
	Export("<select name=\"%s\">\n", STR_MODLITBA);
	Export("<option>%s\n", nazov_modlitby(MODL_INVITATORIUM));
	Export("<option selected>%s\n", nazov_modlitby(MODL_POSV_CITANIE));
	Export("<option>%s\n", nazov_modlitby(MODL_RANNE_CHVALY));
	Export("<option>%s\n", nazov_modlitby(MODL_PREDPOLUDNIM));
	Export("<option>%s\n", nazov_modlitby(MODL_NAPOLUDNIE));
	Export("<option>%s\n", nazov_modlitby(MODL_POPOLUDNI));
	// spomienka P. Márie v sobotu nemá vešpery ani kompletórium
	if(poradie_svaty != PORADIE_PM_SOBOTA){
		Export("<option>%s\n", nazov_modlitby(MODL_VESPERY));
		Export("<option>%s\n", nazov_modlitby(MODL_KOMPLETORIUM));
	}
	Export("<option>%s\n", nazov_modlitby(MODL_VSETKY));
	Export("</select>\n");
	Export("</li>\n");

	if((poradie_svaty > 0) && (poradie_svaty < PORADIE_PM_SOBOTA)){

		// najprv si rozkodujeme, co je v _global_den.spolcast
		_struct_sc sc = _decode_spol_cast(_global_den.spolcast);
		// pole WWW_MODL_OPT_3 // 2012-08-27: zmenené na WWW_MODL_OPTF_3
		Export("<li>");
		Export((char *)html_text_spol_casti_vziat_zo[_global_jazyk]);
		Export(" \n");
		Export("<select name=\"%s\">\n", STR_MODL_OPTF_3);
		if((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT)){
			Export("<option selected>%s\n", nazov_spolc(sc.a1));
			if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
				// Export("<option>%s\n", nazov_spolc(sc.a2));
				// 2012-08-27: prednastaviť podľa opt 3
				Export("<option%s>%s\n", (sc.a2 != _global_opt[OPT_3_SPOLOCNA_CAST])? STR_EMPTY: html_option_selected, nazov_spolc(sc.a2));
				if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
					// Export("<option>%s\n", nazov_spolc(sc.a3));
					// 2012-08-27: prednastaviť podľa opt 3
					Export("<option%s>%s\n", (sc.a3 != _global_opt[OPT_3_SPOLOCNA_CAST])? STR_EMPTY: html_option_selected, nazov_spolc(sc.a3));
				}
			}
			if(je_mozne_spol_cast_nebrat(poradie_svaty)){
				Export("<option>%s\n", nazov_spolc(MODL_SPOL_CAST_NEBRAT));
			}
		}
		else{
			Export("<option selected>%s\n", nazov_spolc(MODL_SPOL_CAST_NEBRAT));
		}
		Export("</select>\n");
		Export(HTML_LINE_BREAK"<"HTML_SPAN_EXPLAIN">");
		Export((char *)html_text_spol_casti_vziat_zo_explain[_global_jazyk]);
		Export(HTML_SPAN_END);
		Export("</li>\n");
	}// if(poradie svateho == 1, 2, 3... až MAX_POCET_SVATY)

	Export("</ul>\n");

	// 2011-10-03: toto by tu v konečnom dôsledku nejako malo byť... ale nie je to skĺbené s pôvodnými detailami (lebo celé detaily sú jeden <form>)
	// _export_main_formular(den, mesiac, rok, _global_den.denvt);

	// 2003-08-13 pridane vysvetlenie
	Export("<p>\n");
	Export((char *)html_text_detaily_explain[_global_jazyk]);
	Export("</p>\n");

	Export("<!-- button Zobraziť -->\n");
	Export("<center>\n");
	// button "Zobraz modlitbu"
	Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
	Export((char *)HTML_BUTTON_DET_SHOW);
	Export("\">");

	// button "Vyčisti"
	Export(""HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE""HTML_NONBREAKING_SPACE"\n");
	Export("<"HTML_FORM_INPUT_RESET2" value=\"");
	Export((char *)HTML_BUTTON_DET_DEFAULTS);
	Export("\">");

	// koniec formulára
	Export("</center>\n</form>\n");

	Log("showDetails(%d, %s, %d, %d) -- koniec\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
}// showDetails();

void _nastav_global_pocet_zalmov_kompletorium(short int modlitba){
	// 2006-10-18: pridané | 2011-07-09: rozšírené | 2013-03-11: vyčlenené do samostatnej funkcie (aby sa dalo použiť aj inde)
	Log("_nastav_global_pocet_zalmov_kompletorium(modlitba == %d): začiatok...\n", modlitba);
	// Log("nastavujem do _global_pocet_zalmov_kompletorium počet žalmov...\n");
	if((modlitba == MODL_KOMPLETORIUM) || (modlitba == MODL_DRUHE_KOMPLETORIUM)){
		_global_pocet_zalmov_kompletorium = _global_modl_kompletorium.pocet_zalmov;
	}
	else if(modlitba == MODL_PRVE_KOMPLETORIUM){
		_global_pocet_zalmov_kompletorium = _global_modl_prve_kompletorium.pocet_zalmov;
	}
	else{
		_global_pocet_zalmov_kompletorium = 1;
	}
	Log("SET: _global_pocet_zalmov_kompletorium == %d...\n", _global_pocet_zalmov_kompletorium);
	Log("_nastav_global_pocet_zalmov_kompletorium(): koniec\n");
}// _nastav_global_pocet_zalmov_kompletorium()

//---------------------------------------------------------------------
// rozbor_dna_s_modlitbou(int, int, int, int)
//
// skoro ako rozbor_dna(), avsak dostane este int, ktory oznacuje modlitbu; a int, ktory oznacuje poradie svateho, ak je ich viac (2,3).
// pracuje takto:
//
// -- kvoli prvym vesperam nasledujuceho dna spusti analyzuj_rok(rok + 1);
// -- spusti _rozbor_dna(datum + 1, X) (kde X je rok alebo rok + 1, podla dna)
// -- ulozi vysledok do lokalnej premennej _local_den, _local_svaty...
// -- spusti analyzuj_rok(rok);
// -- spusti _rozbor_dna(datum, rok);
// -- porovna, ci (ked su modlitbou vespery) budu prve vespery z dalsieho dna alebo nie,
// -- napokon spusti vytvorenie modlitby
//
// POZOR! Narozdiel od rozbor dna, pred samotnym spustenim generovania modlitby je vysledok (co sa presne bude modlit) v premennej _global_den;
// 2003-06-30: chyba toho, ze pre 2003-06-28, vespery, neboli 1. vespery zo sviatku (slavnosti) sv. Petra a sv. Pavla, bude asi v porovnani
// 2003-08-13: neviem preco boli hore tri vykricniky ("napokon spusti vytvorenie modlitby")
void rozbor_dna_s_modlitbou(short int den, short int mesiac, short int rok, short int modlitba, short int poradie_svaty, short int aj_navigacia = ANO){
	short int ret = SUCCESS;

	// lokalne premenne, v ktorych sa pamata to, co vrati _rozbor_dna()
	// lokalna premenna, do ktorej sa ukladaju info o analyzovanom dni
	_struct_dm _local_den; // 2012-10-12: už je globálna 
	// 2012-10-14: hoci jestvuje aj globálna premenná, tá sa preplácava napr. v init_global_string(), čo bolo zle (negenerovali sa správne prvé vešpery), preto vrátená sem späť lokálna premenná
	_INIT_DM(_local_den); // 2003-08-07 pridana

	// lokalne premenne obsahujuce data modlitbach -- 23/02/2000A.D. | prerobene, aby sa alokovali dynamicky

	_type_1vespery      *_local_modl_prve_vespery_ptr;
#define _local_modl_prve_vespery (*_local_modl_prve_vespery_ptr)
	_type_1kompletorium *_local_modl_1kompletorium_ptr;
#define _local_modl_prve_kompletorium (*_local_modl_1kompletorium_ptr)
	_type_vespery       *_local_modl_vespery_ptr;
#define _local_modl_vespery (*_local_modl_vespery_ptr)
	_type_kompletorium *_local_modl_kompletorium_ptr;
#define _local_modl_kompletorium (*_local_modl_kompletorium_ptr)

	short _local_spol_cast = MODL_SPOL_CAST_NEURCENA;

	Log("Allocating memory...\n");
// _local_modl_prve_vespery_ptr
	if((_local_modl_prve_vespery_ptr = (_type_1vespery*) malloc(sizeof(_type_1vespery))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_prve_vespery_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_prve_vespery_ptr'\n", sizeof(_type_1vespery));
		_INIT_TMODLITBA1(_local_modl_prve_vespery); // pridana 2003-08-13
	}

// _local_modl_1kompletorium_ptr
	if((_local_modl_1kompletorium_ptr = (_type_1kompletorium*) malloc(sizeof(_type_1kompletorium))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_1kompletorium_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_1kompletorium_ptr'\n", sizeof(_type_1kompletorium));
		_INIT_TMODLITBA3(_local_modl_prve_kompletorium); // pridané 2006-10-17
	}
// _local_modl_vespery_ptr
	if((_local_modl_vespery_ptr = (_type_vespery*) malloc(sizeof(_type_vespery))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_vespery_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_vespery_ptr'\n", sizeof(_type_vespery));
		_INIT_TMODLITBA1(_local_modl_vespery); // pridana 2003-08-13
	}

// _local_modl_kompletorium_ptr
	if((_local_modl_kompletorium_ptr = (_type_kompletorium*) malloc(sizeof(_type_kompletorium))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_kompletorium_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_kompletorium_ptr'\n", sizeof(_type_kompletorium));
		_INIT_TMODLITBA3(_local_modl_kompletorium); // pridané 2006-10-17
	}

	Log("...done.\n");

	// lokalna kopia roka; ak treba analyzovat dalsi rok
	short int _local_rok = -1;

	// lokálna premenná, čo obsahuje string vypísaný na obrazovku -- je to kópia _global_string (preto veľkosť 2011-09-27 opravená)
	char _local_string[MAX_GLOBAL_STR];

	// char pom[MAX_STR];

	_global_modlitba = modlitba;

	Log("-- rozbor_dna_s_modlitbou(int, int, int, int, int): begin (%d.%d %d, %d; %d)\n", den, mesiac, rok, modlitba, poradie_svaty);
	_struct_den_mesiac datum;

	short int svaty_dalsi_den = UNKNOWN_PORADIE_SVATEHO;
	if((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)){
		// najprv analyzujem nasledujuci den - kvoli prvym vesperam resp. kompletoriu
		Log("kedze modlitba je vespery alebo kompletorium, robim tuto cast... (naplnenie _local_den)\n");
		_local_rok = rok;
		// do premennej datum dame datum nasledujuceho dna
		if(den == pocet_dni[mesiac - 1]){
			datum.den = 1;
			if(mesiac == 12){
				datum.mesiac = 1;
				_local_rok = rok + 1;
			}
			else{
				datum.mesiac = mesiac + 1;
			}
		}
		else{
			datum.den = den + 1;
			datum.mesiac = mesiac;
		}
		Log("spustam analyzu roka (rok %d)...\n", _local_rok);
		analyzuj_rok(_local_rok); // výsledok dá do _global_r
		LOG_ciara;

		Log("spustam analyzu nasledujuceho dna (%d. %s %d), poradie_svaty == %d...\n", datum.den, nazov_mesiaca(datum.mesiac - 1), _local_rok, svaty_dalsi_den);
		ret = _rozbor_dna_s_modlitbou(datum, _local_rok, modlitba, svaty_dalsi_den);
		if(ret == FAILURE){
			Log("_rozbor_dna_s_modlitbou() pre nasledujuci den returned FAILURE, so...\n");
			Log("-- rozbor_dna_s_modlitbou(int, int, int, int): uncomplete end\n");
			goto LABEL_s_modlitbou_DEALLOCATE;
		}// ret == FAILURE
		Log("analyza nasledujuceho dna (%d. %s %d) skoncila.\n", datum.den, nazov_mesiaca(datum.mesiac - 1), rok);
		LOG_ciara;

		_local_den = _global_den;
		_local_spol_cast = _global_opt[OPT_3_SPOLOCNA_CAST]; // 2014-09-03: uchovanie prípadne zmenenej spoločnej časti
		_local_modl_prve_vespery = _global_modl_prve_vespery;
		_local_modl_prve_kompletorium = _global_modl_prve_kompletorium;
		_local_modl_vespery = _global_modl_vespery;
		_local_modl_kompletorium = _global_modl_kompletorium;
		// Log("_local_modl_vespery obsahuje:\n"); Log(_local_modl_vespery);
		// pridane 2003-10-07 kvoli debugovaniu, co prve vespery nediel ocr nemali prosby
			Log("_local_modl_prve_vespery obsahuje:\n"); Log(_local_modl_prve_vespery);
		//

		// Log("_global_modl_kompletorium obsahuje:\n"); Log(_global_modl_kompletorium);
		// Log("_global_modl_prve_kompletorium obsahuje:\n"); Log(_global_modl_prve_kompletorium);
		// Log("_local_modl_prve_kompletorium obsahuje:\n"); Log(_local_modl_prve_kompletorium);

		mystrcpy(_local_string, _global_string, MAX_GLOBAL_STR); // veľkosť 2011-09-27 opravená podľa _global_string
	}// kompletorium alebo vespery

	// teraz analyzujem dnesny den
	Log("teraz analyzujem dnesny (ten vyziadany) den...\n");
	datum.den = den;
	datum.mesiac = mesiac;
	if(_local_rok != rok){
		Log("spustam analyzu roka (rok %d)...\n", rok);
		analyzuj_rok(rok); // výsledok dá do _global_r
	}
	Log("spustam analyzu tohto dna (%d. %s %d)...\n", datum.den, nazov_mesiaca(datum.mesiac - 1), rok);
	ret = _rozbor_dna_s_modlitbou(datum, rok, modlitba, poradie_svaty);
	if(ret == FAILURE){
		Log("_rozbor_dna_s_modlitbou() returned FAILURE, so...\n");
		Log("-- rozbor_dna_s_modlitbou(int, int, int, int): uncomplete end\n");
		goto LABEL_s_modlitbou_DEALLOCATE;
	}// ret == FAILURE
	Log("analyza tohto dna (%d. %s %d) skoncila.\n", datum.den, nazov_mesiaca(datum.mesiac - 1), rok);
	LOG_ciara;
	// teraz mam vsetky data v _global_den, _global_modl_...
	Log("teraz mam vsetky data v _global_den, _global_modl_...\n");
/*
 * 2003-08-13: tu bolo kedysi toto:
 * kontrola 2003-10-07; uz na tomto mieste chybali prosby pre 1. vespery;
   chyba bola v dbzaltar.cpp::_SET_SPOLOCNE_VECI_NEDELA - opravene.
	Log("_local_modl_prve_vespery:\n"); Log(_local_modl_prve_vespery);
	Log("_local_modl_vespery:\n"); Log(_local_modl_vespery);
	Log("(2) _global_modl_prve_vespery:\n"); Log(_global_modl_prve_vespery);
	Log("_global_modl_vespery:\n"); Log(_global_modl_vespery);
 */
	// 2009-03-19: debugovanie kvôli kompletóriu po prvých vešperách 18. marca - sv. Jozefa
	// Log("(2) _global_modl_prve_kompletorium:\n"); Log(_global_modl_prve_kompletorium);

	Log("nastavujem _global_string_modlitba...\n");
	init_global_string_modlitba(modlitba);
	Log("nastavujem _global_string_podnadpis...\n");
	init_global_string_podnadpis(modlitba);
	Log("nastavujem _global_string_spol_cast...\n");
	ret_sc = init_global_string_spol_cast(((modlitba == MODL_DETAILY) || (modlitba == MODL_NEURCENA))? MODL_SPOL_CAST_NULL: _global_opt[OPT_3_SPOLOCNA_CAST], poradie_svaty);

	// 2011-03-22: doplnené; boli explicitne vyžiadané prvé vešpery resp. kompletórium po prvých vešperách
	if((modlitba == MODL_PRVE_VESPERY) || (modlitba == MODL_PRVE_KOMPLETORIUM)){
		Log("-- explicitne vyžiadané MODL_PRVE_VESPERY || MODL_PRVE_KOMPLETORIUM\n");
	}// if((modlitba == MODL_PRVE_VESPERY) || (modlitba == MODL_PRVE_KOMPLETORIUM))

	// ak ma nasledujuci den prioritu pred dnesnym dnom
	if((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)){
		Log("teraz uvidime, ci vespery/kompletorium nasledovneho dna nemaju nahodou prioritu...\n");

		// netyka sa to zeleneho stvrtka, velkeho tyzdna, velkonocneho trojdnia
		if(_global_den.denvr == (_global_r._VELKONOCNA_NEDELA.denvr - 3)){
			Log("netyka sa to zeleneho stvrtka\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		else if((_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) && (_global_den.denvt != DEN_NEDELA)){
			Log("netyka sa to velkeho tyzdna (okrem druhych vespier kvetnej nedele)\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		else if(_global_den.litobd == OBD_VELKONOCNE_TROJDNIE){
			Log("netyka sa to velkonocneho trojdnia\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		// ...a tiez sa to netyka popolcovej stredy, 09/03/2000A.D.
		if((_global_den.denvr == _global_r._POPOLCOVA_STREDA.denvr) || ((_global_den.denvr == (_global_r._POPOLCOVA_STREDA.denvr - 1)))){
			// preto aj POPOLCOVA_STREDA aj POPOLCOVA_STREDA - 1, lebo prve aj druhe vespery
			Log("netyka sa to popolcovej stredy\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		// ...a tiez sa to netyka dni velkonocnej oktavy okrem nedele
		if((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) && (_global_den.denvt != DEN_SOBOTA) && (_global_den.denvt != DEN_NEDELA)){
			// sobota kvoli prvym vesperam
			Log("netyka sa to vsednych dni velkonocnej oktavy\n");
			goto LABEL_NIE_INE_VESPERY;
		}

		Log("ďalší deň (%d.%d.): _local_den.smer == %d, _local_den.denvt == %s, _local_den.litobd == %s (%d)\n",
			_local_den.den, _local_den.mesiac,
			_local_den.smer, nazov_dna(_local_den.denvt), nazov_obdobia_ext(_local_den.litobd), _local_den.smer);
		// Log(_local_den);
		// Log("_local_modl_prve_vespery obsahuje:\n"); Log(_local_modl_prve_vespery);
		// Log("_local_modl_prve_kompletorium obsahuje:\n"); Log(_local_modl_prve_kompletorium);
		
		Log("tento deň (%d.%d.): _global_den.smer == %d, _global_den.denvt == %s, _global_den.litobd == %s (%d)\n",
			_global_den.den, _global_den.mesiac,
			_global_den.smer, nazov_dna(_global_den.denvt), nazov_obdobia_ext(_global_den.litobd), _global_den.smer);
		// 2003-06-30
		// Log(_global_den);
		// Log("(3) _global_modl_prve_vespery obsahuje:\n"); Log(_global_modl_prve_vespery);
		// Log("(3) _global_modl_prve_kompletorium obsahuje:\n"); Log(_global_modl_prve_kompletorium);

		// if VYNIMKY: porov. nizsie. 14/03/2000A.D.
		if((_global_den.smer > _local_den.smer) ||
			((_global_den.smer == _local_den.smer) && 
				(
					((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) && (_global_den.denvt == DEN_SOBOTA)) || // 2. velkonocna nedela
					((_local_den.mesiac - 1 == MES_DEC) && (_local_den.den == 25)) // ked narodenie pana pripadne na pondelok, tak prve vespery maju prednost pred 4. adventnou nedelou; napr. rok 2000
				)
			)
		){
			Log("jumping to LABEL_ZMENA...\n");
			goto LABEL_ZMENA;
		}

		if((_global_den.smer < 5) ||
			// cl. 11: slavnosti su zvlast vyznacnymi dnami. ich slavenie sa zacina prvymi vesperami v predchadzajuci den.
			((_global_den.smer == 5) && (_global_den.denvt == DEN_NEDELA) && ((_global_den.litobd == OBD_CEZ_ROK) || je_vianocne(_global_den.litobd))) ||
			// cl. 13: sviatky sa slavia v rozsahu jedneho dna, a preto nemaju prve vespery, ak len nejde o sviatky pana, ktore pripadaju na nedelu v obdobi ,,cez rok" a na nedelu vo vianocnom obdobi
			// a nahradzuju nedelnajsiu liturgiu hodin.
			(_global_den.denvt == DEN_NEDELA)
			// nedeľa
		){
			// cl. 61: ak na ten isty den pripadnu vespery bezneho dna a prve vespery nasledujuceho dna, maju prednost vespery slavenia,
			// ktore ma v tabulke liturgickych dni vyssi stupen. v pripade rovnosti sa beru vespery bezneho dna.

			if(modlitba == MODL_VESPERY){
				_global_modlitba = MODL_DRUHE_VESPERY;
				Log("-- MODL_DRUHE_VESPERY\n");
			}
			else if(modlitba == MODL_KOMPLETORIUM){
				_global_modlitba = MODL_DRUHE_KOMPLETORIUM;
				Log("-- MODL_DRUHE_KOMPLETORIUM\n");
			}
			// Spomienka vsetkych vernych zosnulych -- nevypisem, ze su druhe vespery -- zapracované do init_global_string_modlitba()

			Log("nastavujem _global_string_modlitba... if((_global_den.smer < 5) || ...\n");
			init_global_string_modlitba(modlitba);

			Log("nastavujem _global_string_podnadpis... if((_global_den.smer < 5) || ...\n");
			init_global_string_podnadpis(modlitba);

			Log("kontrolujem _global_opt[OPT_3_SPOLOCNA_CAST]... if((_global_den.smer < 5) || : ");
			if(_local_spol_cast != MODL_SPOL_CAST_NEURCENA){
				_global_opt[OPT_3_SPOLOCNA_CAST] = _local_spol_cast;
				Log("upravené podľa _local_spol_cast na %s (%d)\n", nazov_spolc(_local_spol_cast), _local_spol_cast);
			}
			else{
				Log("bez úpravy.\n");
			}

			Log("nastavujem _global_string_spol_cast... if((_global_den.smer < 5) || ...\n");
			ret_sc = init_global_string_spol_cast(((modlitba == MODL_DETAILY) || (modlitba == MODL_NEURCENA))? MODL_SPOL_CAST_NULL: _global_opt[OPT_3_SPOLOCNA_CAST], poradie_svaty);
		}// _global_den ma dvoje vespery/kompletorium, teda musime brat DRUHE

		else
LABEL_ZMENA:
			if((_local_den.smer < 5) ||
			// cl. 11: slavnosti su zvlast vyznacnymi dnami. ich slavenie sa zacina prvymi vesperami v predchadzajuci den.
			((_local_den.smer == 5) && (_local_den.denvt == DEN_NEDELA) && ((_local_den.litobd == OBD_CEZ_ROK) || je_vianocne(_local_den.litobd))) ||
			// cl. 13: sviatky sa slavia v rozsahu jedneho dna, a preto nemaju prve vespery, ak len nejde o sviatky Pana, ktore pripadaju na nedelu v obdobi ,,cez rok" a na nedelu vo vianocnom obdobi
			// a nahradzuju nedelnajsiu liturgiu hodin.
			(_local_den.denvt == DEN_NEDELA)
			// nedeľa
		){
			Log("LABEL_ZMENA:...\n");
			// cl. 61: ak na ten isty den pripadnu vespery bezneho dna a prve vespery nasledujuceho dna, maju prednost vespery slavenia,
			// ktore ma v tabulke liturgickych dni vyssi stupen. v pripade rovnosti sa beru vespery bezneho dna.
			// tento if je kopirovany z vyssieho, VYNIMKY
			if((_global_den.smer > _local_den.smer) ||
				((_global_den.smer == _local_den.smer) && 
					(
						((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) && (_global_den.denvt == DEN_SOBOTA)) ||// 2. velkonocna nedela, pridane 09/03/2000A.D.
						((_local_den.mesiac - 1 == MES_DEC) && (_local_den.den == 25)) // ked narodenie pana pripadne na pondelok, tak prve vespery maju prednost pred 4. adventnou nedelou; napr. rok 2000, pridane 14/03/2000A.D.
					)
				)
			){
				Log("čl. 61 VSLH: beriem vešpery z nasledujúceho dňa...\n");

				_global_den = _local_den;

				if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY) || (modlitba == MODL_DRUHE_VESPERY)){
					Log("priraďujem %s z ďalšieho dňa:\n", nazov_modlitby(modlitba));
					_global_modl_prve_vespery = _local_modl_prve_vespery;
					_global_modl_vespery = _local_modl_prve_vespery;
				}

				if(je_kompletorium12(modlitba)){
					Log("priraďujem %s z ďalšieho dňa, ale iba ak ide o slávnosť!\n", nazov_modlitby(modlitba));
					if(_local_den.smer < 5){
						_global_modl_prve_kompletorium = _local_modl_prve_kompletorium;
						_global_modl_kompletorium = _local_modl_prve_kompletorium;
					}
				}

				// 2012-11-20: doplnené priradenie, lebo sa zmenila premenná _global_den
				_global_poradie_svaty = svaty_dalsi_den;

				// 2012-11-08: pretože slávnosť alebo nedeľa má pre prvé vešpery nastvené vlastné prosby, je potrebné opätovne nastaviť pre vešpery, ak je zvolená táto možnosť, kratšie prosby z dodatku (možno ich použiť v ktorýkoľvek deň v roku)
				if((_global_opt[OPT_1_CASTI_MODLITBY] & BIT_OPT_1_VESP_KRATSIE_PROSBY) == BIT_OPT_1_VESP_KRATSIE_PROSBY){
					Log("(kvôli prvým vešperám) pre vešpery nastavujem kratšie prosby z dodatku -- možno ich použiť v ktorýkoľvek deň v roku (je zvolená táto možnosť)\n");
					_set_prosby_dodatok(_global_den.denvt, ANO);
				}

				Log("CURRENT: prvé vešpery:\n");
				Log(_global_modl_prve_vespery);
				Log("CURRENT: vešpery:\n");
				Log(_global_modl_vespery);
				
				if(modlitba == MODL_VESPERY){
					_global_modlitba = MODL_PRVE_VESPERY;
					Log("-- MODL_PRVE_VESPERY\n");
					_global_modl_vespery = _global_modl_prve_vespery;
					_global_modl_kompletorium = _global_modl_prve_kompletorium;
				}
				else if(modlitba == MODL_KOMPLETORIUM){
					_global_modlitba = MODL_PRVE_KOMPLETORIUM;
					Log("-- MODL_PRVE_KOMPLETORIUM\n");
					_global_modl_vespery = _global_modl_prve_vespery;
					_global_modl_kompletorium = _global_modl_prve_kompletorium;
				}

				Log("v časti LABEL_ZMENA nastavujem _global_string...\n");
				mystrcpy(_global_string, _local_string, MAX_GLOBAL_STR); // veľkosť 2011-09-27 opravená podľa _global_string

				Log("v časti LABEL_ZMENA nastavujem _global_string_modlitba...\n");
				init_global_string_modlitba(modlitba);

				Log("v časti LABEL_ZMENA nastavujem _global_string_podnadpis...\n");
				init_global_string_podnadpis(modlitba);

				Log("v časti LABEL_ZMENA kontrolujem _global_opt[OPT_3_SPOLOCNA_CAST]: ");
				if(_local_spol_cast != MODL_SPOL_CAST_NEURCENA){
					_global_opt[OPT_3_SPOLOCNA_CAST] = _local_spol_cast;
					Log("upravené podľa _local_spol_cast na %s (%d)\n", nazov_spolc(_local_spol_cast), _local_spol_cast);
				}
				else{
					Log("bez úpravy.\n");
				}

				Log("v časti LABEL_ZMENA nastavujem _global_string_spol_cast...\n"); // potrebné použiť svaty_dalsi_den
				ret_sc = init_global_string_spol_cast(((modlitba == MODL_DETAILY) || (modlitba == MODL_NEURCENA))? MODL_SPOL_CAST_NULL: _global_opt[OPT_3_SPOLOCNA_CAST], _global_poradie_svaty /* svaty_dalsi_den */);
			}
			else{
				Log("nič sa nedeje...\n");
			}
		}// _local_den ma dvoje vespery/kompletorium, teda musime brat PRVE
	}// vespery alebo kompletorium, zistovanie priority

	// predosla pasaz, kedy sa kontroluje priorita nasledujuceho dna, preskakujeme pre ostatne modlitby okrem vespier a kompletoria; poznamka pridana 2003-08-13

LABEL_NIE_INE_VESPERY: // 08/03/2000A.D.

	LOG_ciara;
	Log("/* vypisanie udajov, podla ktorych vlastne budem generovat modlitbu */\n");
	Log("/* datum bol vypisany uz predtym, preto teraz (pri prvych vesperach) \n");
	Log(" * moze byt iny - o jeden den vacsi */\n");
	Log("_global_string: %s\n", _global_string);
	Log("modlitba = `%s' (%d)\n", nazov_modlitby(modlitba), modlitba);
	switch(modlitba){
		// dalsie case pridane 2003-08-13
		case MODL_RANNE_CHVALY:
			Log(_global_modl_ranne_chvaly);
			break;
		case MODL_POSV_CITANIE:
			Log(_global_modl_posv_citanie);
			break;
		case MODL_PREDPOLUDNIM:
			Log(_global_modl_predpol);
			break;
		case MODL_NAPOLUDNIE:
			Log(_global_modl_napol);
			break;
		case MODL_POPOLUDNI:
			Log(_global_modl_popol);
			break;
		case MODL_VESPERY:
			Log(_global_modl_vespery);
			break;
		case MODL_PRVE_VESPERY: // 2011-03-22: doplnené
			Log(_global_modl_prve_vespery);
			break;
		case MODL_INVITATORIUM: // invitatórium a kompletórium pridané 2006-10-13
			Log(_global_modl_invitatorium);
			break;
		case MODL_KOMPLETORIUM: // invitatórium a kompletórium pridané 2006-10-13
			Log(_global_modl_kompletorium);
			break;
		case MODL_PRVE_KOMPLETORIUM: // 2011-07-09: doplnené
			Log(_global_modl_prve_kompletorium);
			break;
	}
//	Log("_global_den:\n");	Log(_global_den);

	// 2006-10-18: pridané | 2011-07-09: rozšírené | 2013-03-11: vyčlenené do samostatnej funkcie (aby sa dalo použiť aj inde)
	Log("nastavujem do _global_pocet_zalmov_kompletorium počet žalmov...\n");
	_nastav_global_pocet_zalmov_kompletorium(modlitba);
	Log("_global_pocet_zalmov_kompletorium == %d...\n", _global_pocet_zalmov_kompletorium);

	_export_heading_center(_global_string);

	// 2014-10-20: úprava aj_navigacia pre blind-friendly
	if(((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_BLIND_FRIENDLY) == BIT_OPT_0_BLIND_FRIENDLY) && (modlitba != MODL_NEURCENA)){
		Log("pre blind-friendly verziu upravujem aj_navigacia na NIE (lebo modlitba == %d)...\n", modlitba);
		aj_navigacia = CIASTOCNE;
	}
/*
	if(_global_modlitba == MODL_VSETKY){
		Log("spustam showAllPrayers(%d, %s, %d, %d) z funkcie rozbor_dna_s_modlitbou():\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
		LOG_ciara;
		showAllPrayers(den, mesiac, rok, poradie_svaty);
		LOG_ciara;
		Log("...po návrate zo showAllPrayers(%d, %s, %d, %d) vo funkcii rozbor_dna_s_modlitbou().\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
	}// _global_modlitba == MODL_VSETKY
	else 
*/
	if(_global_modlitba == MODL_DETAILY){
		Log("spustam showDetails(%d, %s, %d, %d) z funkcie rozbor_dna_s_modlitbou():\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
		LOG_ciara;
		showDetails(den, mesiac, rok, poradie_svaty);
		LOG_ciara;
		Log("...po návrate zo showDetails(%d, %s, %d, %d) vo funkcii rozbor_dna_s_modlitbou().\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
	}// _global_modlitba == MODL_DETAILY
	else{
		Log("spustam showPrayer(%s) z funkcie rozbor_dna_s_modlitbou()...\n", nazov_modlitby(_global_modlitba));
		// predpokladam, ze aj _global_modlitba je prve/druhe vespery, v _global_prve_vespery su spravne udaje (podobne kompletorium)
		LOG_ciara;
		showPrayer(modlitba, SHOW_TEMPLAT_MODLITBA, aj_navigacia);
		LOG_ciara;
		Log("...po návrate zo showPrayer(%s) vo funkcii rozbor_dna_s_modlitbou().\n", nazov_modlitby(_global_modlitba));
	}// pre konkrétnu modlitbu

LABEL_s_modlitbou_DEALLOCATE:
	Log("Deallocating memory...\n");
	Log("_local_modl_prve_vespery_ptr\n"); free(_local_modl_prve_vespery_ptr);
	Log("_local_modl_1kompletorium_ptr\n"); free(_local_modl_1kompletorium_ptr);
	Log("_local_modl_vespery_ptr\n"); free(_local_modl_vespery_ptr);
	Log("_local_modl_kompletorium_ptr\n"); free(_local_modl_kompletorium_ptr);
	Log("...done.\n");
	Log("-- rozbor_dna_s_modlitbou(int, int, int, int): ret == %d\n", ret);
}// rozbor_dna_s_modlitbou()

void showAllPrayers(short int den, short int mesiac, short int rok, short int poradie_svaty){
	// 2011-10-03: doplnené; v cykle volám showPrayer() pre všetky modlitby
	short int modlitba, _local_modlitba = _global_modlitba, _local_linky = _global_linky;
	_struct_den_mesiac datum;
	datum.den = den;
	datum.mesiac = mesiac;
	short int opt_3 = _global_opt[OPT_3_SPOLOCNA_CAST];
	static short int opt_1 = _global_opt[OPT_1_CASTI_MODLITBY]; // backup pôvodnej hodnoty; parameter o1 (_global_opt 1) pre modlitbu cez deň (doplnková psalmódia)
	short int modlitba_max = MODL_KOMPLETORIUM; // až po ktorú modlitbu zobraziť

	Log("showAllPrayers(%d, %s, %d, %d) -- začiatok...\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
	Log("_global_den: \n");
	Log(_global_den);

	// top stránky
	Export("\n<a name=\"top\"></a>");

	// úvodná navigácia
	if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_NAVIGATION) == BIT_OPT_2_NAVIGATION){
		Export("<!-- navigácia začiatok -->\n");
		_export_rozbor_dna_buttons_dni(EXPORT_DNA_JEDEN_DEN_LOCAL, NIE);
		// najprv dni, potom modlitby
		Export("<table "HTML_ALIGN_CENTER">\n<tr><td>\n");
		_global_linky = NIE;
		_export_rozbor_dna_buttons(EXPORT_DNA_JEDEN_DEN_LOCAL, _global_poradie_svaty, NIE, ANO);
		_global_linky = _local_linky;
		Export("</td></tr>\n</table>\n");
	}

	// pre sobotnú spomienku panny márie nezobrazuj vešpery ani kompletórium -- ináč to hádzalo chybu v _rozbor_dna_s_modlitbou(); if((poradie_svateho == PORADIE_PM_SOBOTA) && (_global_den.denvt == DEN_SOBOTA) && ((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)))
	if(poradie_svaty == PORADIE_PM_SOBOTA){
		modlitba_max = MODL_POPOLUDNI;
	}

	// cyklus pre všetky modlitby
	for(modlitba = MODL_INVITATORIUM; modlitba <= modlitba_max; modlitba++){
		_global_modlitba = modlitba;

		_global_opt[OPT_3_SPOLOCNA_CAST] = opt_3; // potrebné nastaviť pôvodnú hodnotu, lebo sa niekde v rozbor_dna_s_modlitbou() upravuje

		if(je_modlitba_cez_den(modlitba)){
			Log("<!-- MCD (%d, %d) -->", modlitba, opt_1);
			if(((opt_1 & BIT_OPT_1_MCD_DOPLNKOVA) != BIT_OPT_1_MCD_DOPLNKOVA) && /* delenie trojkou so zvyškom */ (((_global_den.denvr + rok + modlitba) MOD 3) != 0)){
				Log("<!-- MCD (%d): doplnková psalmódia -->", modlitba);
				Log("Pre option 1 nastavujem bit pre 'doplnkovú psalmódiu'\n");
				_global_opt[OPT_1_CASTI_MODLITBY] += BIT_OPT_1_MCD_DOPLNKOVA;
			}// zmena: použitie doplnkovej psalmódie
		}// mcd

		Log("spúšťam showPrayer(%s)->rozbor_dna_s_modlitbou() z funkcie showAllPrayers()...\n", nazov_modlitby(_global_modlitba));

		LOG_ciara;

		if(modlitba > MODL_INVITATORIUM){
			// odkaz na vrch stránky
			Export("<p "HTML_ALIGN_CENTER">");
			Export("<a href=\"#top\" "HTML_CLASS_BUTTON">");
			Export((char *)html_text_batch_Back[_global_jazyk]);
			Export("</a>");
			Export("</p>");
			// oddelenie
			Export("\n<hr>\n");
		}

		rozbor_dna_s_modlitbou(den, mesiac, rok, modlitba, poradie_svaty, /* aj_navigacia */ NIE);

		LOG_ciara;

		Log("...po návrate zo showPrayer(%s)->rozbor_dna_s_modlitbou() vo funkcii showAllPrayers().\n", nazov_modlitby(_global_modlitba));

		if(_global_opt[OPT_1_CASTI_MODLITBY] != opt_1){
			_global_opt[OPT_1_CASTI_MODLITBY] = opt_1; // restore pôvodnej hodnoty
		}// obnovenie opt_1
	}// for(modlitba)

	// záverečná navigácia
	if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_NAVIGATION) == BIT_OPT_2_NAVIGATION){
		Export("<!-- navigácia koniec -->\n");

		Export("<table "HTML_ALIGN_CENTER">\n<tr><td>\n");
		_global_linky = NIE;
		_export_rozbor_dna_buttons(EXPORT_DNA_JEDEN_DEN_LOCAL, _global_poradie_svaty, NIE, ANO);
		_global_linky = _local_linky;
		Export("</td></tr>\n</table>\n");
		// najprv modlitby, potom dni
		_export_rozbor_dna_buttons_dni(EXPORT_DNA_JEDEN_DEN_LOCAL, NIE);
	}

	_global_modlitba = _local_modlitba;
	Log("showAllPrayers(%d, %s, %d, %d) -- koniec\n", den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
}// showAllPrayers();

//---------------------------------------------------------------------
// rozbor_dna(int, int, int)
//
// dostane 3 inty, spusti analyzuj_rok(); potom spusti _export_rozbor_dna();
void rozbor_dna(short int den, short int mesiac, short int rok){
	short int ret;
	Log("-- rozbor_dna(int, int, int): begin (%d. %d. %d)\n", den, mesiac, rok);
	_struct_den_mesiac datum;
	datum.den = den;
	datum.mesiac = mesiac;
	Log("-- rozbor_dna(): spúšťam analyzuj_rok()...\n");
	analyzuj_rok(rok); // výsledok dá do _global_r
	Log("-- rozbor_dna(): analyzuj_rok() skončila.\n");

	Log("-- rozbor_dna(): spúšťam _rozbor_dna(s dvoma parametrami)...\n");
	ret = _rozbor_dna(datum, rok);
	if(ret == FAILURE){
		Log("_rozbor_dna() returned FAILURE, so...\n");
		Log("-- rozbor_dna(int, int, int): uncomplete end\n");
		return;
	}
	Log("-- rozbor_dna(): _rozbor_dna(s dvoma parametrami) skončila.\n");

	Log("-- rozbor_dna(): spúšťam _export_rozbor_dna(EXPORT_DNA_JEDEN_DEN)...\n");
	_export_rozbor_dna(EXPORT_DNA_JEDEN_DEN);
	Log("-- rozbor_dna(): _export_rozbor_dna(EXPORT_DNA_JEDEN_DEN) skončila.\n");

	Log("-- rozbor_dna(int, int, int): end (%d. %d. %d)\n", den, mesiac, rok);
}// rozbor_dna()

//---------------------------------------------------------------------
// rozbor_mesiaca(int, int)
//
// dostane cislo mesiaca (1--12) a rok, spusti analyzuj_rok(); potom pre vsetky dni spusti _rozbor_dna();
void rozbor_mesiaca(short int mesiac, short int rok, short int typ_exportu = EXPORT_DNA_VIAC_DNI){
	Log("-- rozbor_mesiaca(%d/%d): začiatok\n", mesiac, rok);
	_struct_den_mesiac datum;
	datum.mesiac = mesiac;
	short int som_v_tabulke = ANO; // 2009-08-26: či sa používa tabuľka; bežne pre web áno, pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku
	short int typ;

	if((typ_exportu != EXPORT_DNA_VIAC_DNI_TXT) && (typ_exportu != EXPORT_DNA_XML)){
		if((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_MESIAC_RIADOK) != BIT_OPT_4_MESIAC_RIADOK){
			Log("-- EXPORT_DNA_VIAC_DNI --\n");
			typ = EXPORT_DNA_VIAC_DNI;
		}
		else{ // ((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_MESIAC_RIADOK) == BIT_OPT_4_MESIAC_RIADOK)
			Log("-- EXPORT_DNA_VIAC_DNI_SIMPLE --\n");
			typ = EXPORT_DNA_VIAC_DNI_SIMPLE;
		}
	}
	else{
		typ = typ_exportu;
	}

	if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2){
		som_v_tabulke = NIE;
		Log("-- rozbor_mesiaca: keďže sme v _global_opt_batch_monthly == ANO a export_monthly_druh (%d) > 2, nebudeme exportovať tabuľku...\n", export_monthly_druh);
	}
	if((typ == EXPORT_DNA_VIAC_DNI_TXT) || (typ == EXPORT_DNA_XML)){
		som_v_tabulke = NIE;
		Log("-- _export_rozbor_dna_buttons(typ == %d): kvôli typu nebudeme exportovať tabuľku...\n", typ);
	}

	analyzuj_rok(rok); // výsledok dá do _global_r
	if(som_v_tabulke == ANO){
		Export("\n"HTML_LINE_BREAK"<table>\n");
	}
	for(datum.den = 1; datum.den <= pocet_dni[mesiac - 1]; datum.den++){
		Log("-- rozbor_mesiaca: volám _rozbor_dna() pre deň %d...\n", datum.den);
		if(typ == EXPORT_DNA_VIAC_DNI_TXT){
			Export("\n");
#ifdef NIELEN_PRE_PETA_ZIMENA
			Export((char *)html_text_mesiac[_global_jazyk]);
			Export(" == %d, ", mesiac);
			Export((char *)html_text_den[_global_jazyk]);
			Export(" == %d ", datum.den);
#endif
			Export("expt"); // PZ: $rkc // 2011-02-03
			Export("[%02d%02d]", datum.den, mesiac);
			Export("=");
		}
		_rozbor_dna(datum, rok);
		Log("-- rozbor_mesiaca: nasleduje _export_rozbor_dna() pre deň %d...\n", datum.den);
		// 2005-03-21: Pridany dalsi typ exportu; 2007-06-01 upravené, aby sa neriadilo opt_1, ale opt6 
		// 2011-02-02: pridaný ďalší typ exportu; EXPORT_DNA_VIAC_DNI_TXT
		// 2011-02-02: nastavenie typu exportu presunuté vyššie 
		_export_rozbor_dna(typ);
		Log("-- rozbor_mesiaca: deň %d skončil.\n", datum.den);
	}// for datum.den
	if(som_v_tabulke == ANO){
		Export("\n</table>\n\n");
	}
	Log("-- rozbor_mesiaca(%d/%d): koniec\n", mesiac, rok);
}// rozbor_mesiaca();

void log_pom_MODL_OPT(void){
	short int i;
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		Log("opt %d == `%s' (%d)\n", i, pom_MODL_OPT[i], _global_opt[i]);
	}
}// log_pom_MODL_OPT()
void log_pom_MODL_OPTF(void){
	short int i;
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		Log("optf %d == `%s' (%d)\n", i, pom_MODL_OPTF[i], _global_optf[i]);
	}
	for(i = 0; i < POCET_OPT_0_SPECIALNE; i++){
		Log("optf[%d] %d == `%s'\n", OPT_0_SPECIALNE, i, pom_MODL_OPTF_SPECIALNE[i]);
	}
	for(i = 0; i < POCET_OPT_1_CASTI_MODLITBY; i++){
		Log("optf[%d] %d == `%s'\n", OPT_1_CASTI_MODLITBY, i, pom_MODL_OPTF_CASTI_MODLITBY[i]);
	}
}// log_pom_MODL_OPTF()

void _rozparsuj_parametre_OPT_force(short int option_opt, char pom_MODL_OPTF_opt[MAX_POCET_OPT][SMALL], short int _global_option_opt[MAX_POCET_OPT]){
	short int i;
	short int aspon_jedna_nenulova;
	short int bit_value;
	Log("_rozparsuj_parametre_OPT_force() -- začiatok...\n");
	// option_opt force j (0, 1, 2, 4, 5)
	// option_opt force j -- jednotlivé komponenty
	_global_optf[option_opt] = GLOBAL_OPTION_NULL;
	aspon_jedna_nenulova = NIE;
	for(i = 0; i < pocet_opt[option_opt]; i++){
		if((pom_MODL_OPTF_opt[i] == NULL) || (strlen(pom_MODL_OPTF_opt[i]) < 1)){
			_global_option_opt[i] = GLOBAL_OPTION_NULL;
		}
		else{
			_global_option_opt[i] = atoi(pom_MODL_OPTF_opt[i]);
			aspon_jedna_nenulova = ANO;
		}
		Log("optf[%d][%d] == `%s' (%d)\n", option_opt, i, pom_MODL_OPTF_opt[i], _global_option_opt[i]);
	}// for i
	if(aspon_jedna_nenulova == ANO){
		_global_optf[option_opt] = 0;
		// nastavenie _global_optf[option_opt] podľa jednotlivých bit-komponentov, ktoré sú nastavené v _global_option_opt[]
		for(i = 0; i < pocet_opt[option_opt]; i++){
			bit_value = (int)pow(2.0, i);
			Log("option_opt %d, i == %d; bit_value == %d...\n", option_opt, i, bit_value);
			if(_global_option_opt[i] != GLOBAL_OPTION_NULL){
				_global_optf[option_opt] += bit_value * _global_option_opt[i];
			}
			else if((_global_opt[option_opt] & bit_value) == bit_value){
				// ináč použi nastavenie z _global_opt (nie force)
				Log("použijem nastavenie z _global_opt[%d] (nie force)...\n", option_opt);
				_global_optf[option_opt] += bit_value;
			}
		}// for i
		Log("optf[%d] vyskladaná == %d\n", option_opt, _global_optf[option_opt]);
	}
	Log("optf %d == `%s' (%d)\n", option_opt, pom_MODL_OPTF[option_opt], _global_optf[option_opt]);
	Log("_rozparsuj_parametre_OPT_force() -- koniec.\n");
}// _rozparsuj_parametre_OPT_force()

// 2006-02-10: nový define; používa premennú int i 
// 2011-04-11: prerobené na funkciu
// 2013-03-07: pre force 0, 1, 2, 4, 5 použitá funkcia _rozparsuj_parametre_OPT_force()
void _rozparsuj_parametre_OPT(void){
	// rozparsovanie option parametrov
	short int i, opt_2_fn /* font name chooser */, opt_2_fs /* font size chooser */;

	Log("_rozparsuj_parametre_OPT() -- začiatok...\n");

	Log("options...\n");

	// option 0
	if((pom_MODL_OPT[OPT_0_SPECIALNE] == NULL) || (strlen(pom_MODL_OPT[OPT_0_SPECIALNE]) < 1)){
		_global_opt[OPT_0_SPECIALNE] = GLOBAL_OPTION_NULL;
	}
	else{
		_global_opt[OPT_0_SPECIALNE] = atoi(pom_MODL_OPT[OPT_0_SPECIALNE]);
	}
	Log("opt %d == `%s' (%d)\n", OPT_0_SPECIALNE, pom_MODL_OPT[OPT_0_SPECIALNE], _global_opt[OPT_0_SPECIALNE]);

	// option 1
	if((pom_MODL_OPT[OPT_1_CASTI_MODLITBY] == NULL) || (strlen(pom_MODL_OPT[OPT_1_CASTI_MODLITBY]) < 1)){
		_global_opt[OPT_1_CASTI_MODLITBY] = GLOBAL_OPTION_NULL;
	}
	else{
		_global_opt[OPT_1_CASTI_MODLITBY] = atoi(pom_MODL_OPT[OPT_1_CASTI_MODLITBY]);
	}
	Log("opt %d == `%s' (%d)\n", OPT_1_CASTI_MODLITBY, pom_MODL_OPT[OPT_1_CASTI_MODLITBY], _global_opt[OPT_1_CASTI_MODLITBY]);

	// option 2
	if((pom_MODL_OPT[OPT_2_HTML_EXPORT] == NULL) || (strlen(pom_MODL_OPT[OPT_2_HTML_EXPORT]) < 1)){
		_global_opt[OPT_2_HTML_EXPORT] = GLOBAL_OPTION_NULL;
	}
	else{
		_global_opt[OPT_2_HTML_EXPORT] = atoi(pom_MODL_OPT[OPT_2_HTML_EXPORT]);
	}
	Log("opt %d == `%s' (%d)\n", OPT_2_HTML_EXPORT, pom_MODL_OPT[OPT_2_HTML_EXPORT], _global_opt[OPT_2_HTML_EXPORT]);

	// option 3
	i = atoi(pom_MODL_OPT[OPT_3_SPOLOCNA_CAST]);
	// predpokladam, ze tento parameter moze byt zadany eventualne cislom (teda retazcom, kt. hodnota pri konverzii na int je int, urcujuci opt_3
	if((i > MODL_SPOL_CAST_NEBRAT) || (i <= 0)){
		i = 0;
		// ide o znakovy retazec nekonvertovatelny na cislo
	}
	else{
		mystrcpy(pom_MODL_OPT[OPT_3_SPOLOCNA_CAST], nazov_spolc(i), SMALL);
		// ak je zadane cislo spravne, tak i bude spravny int a pom_MODL_OPT[OPT_3_SPOLOCNA_CAST] bude spravny char*
	}
	Log("opt %d: i == %d\n", OPT_3_SPOLOCNA_CAST, i);
	while(i <= MODL_SPOL_CAST_NEBRAT){
		if(equals(pom_MODL_OPT[OPT_3_SPOLOCNA_CAST], nazov_spolc(i))){
			_global_opt[OPT_3_SPOLOCNA_CAST] = i;
			break;
		}
		i++;
	}
	if(i > MODL_SPOL_CAST_NEBRAT){
		_global_opt[OPT_3_SPOLOCNA_CAST] = MODL_SPOL_CAST_NEURCENA;
	}
	Log("opt %d == `%s' (%d)\n", OPT_3_SPOLOCNA_CAST, pom_MODL_OPT[OPT_3_SPOLOCNA_CAST], _global_opt[OPT_3_SPOLOCNA_CAST]);

	// option 4
	if((pom_MODL_OPT[OPT_4_OFFLINE_EXPORT] == NULL) || (strlen(pom_MODL_OPT[OPT_4_OFFLINE_EXPORT]) < 1)){
		_global_opt[OPT_4_OFFLINE_EXPORT] = GLOBAL_OPTION_NULL;
	}
	else{
		_global_opt[OPT_4_OFFLINE_EXPORT] = atoi(pom_MODL_OPT[OPT_4_OFFLINE_EXPORT]);
	}
	Log("opt %d == `%s' (%d)\n", OPT_4_OFFLINE_EXPORT, pom_MODL_OPT[OPT_4_OFFLINE_EXPORT], _global_opt[OPT_4_OFFLINE_EXPORT]);

	// option 5
	if((pom_MODL_OPT[OPT_5_ALTERNATIVES] == NULL) || (strlen(pom_MODL_OPT[OPT_5_ALTERNATIVES]) < 1)){
		_global_opt[OPT_5_ALTERNATIVES] = GLOBAL_OPTION_NULL;
	}
	else{
		_global_opt[OPT_5_ALTERNATIVES] = atoi(pom_MODL_OPT[OPT_5_ALTERNATIVES]);
	}
	Log("opt %d == `%s' (%d)\n", OPT_5_ALTERNATIVES, pom_MODL_OPT[OPT_5_ALTERNATIVES], _global_opt[OPT_5_ALTERNATIVES]);

	// force options
	Log("force options...\n");
	// postupne prechádzam jednotlivé bitové komponenty force a vyskladávam z nich celkovú jednu hodnotu; ak daná bitová hodnota nie je naplnená, použijem hodnotu z ne-force option-bitového komponentu

	// option force 0
	_rozparsuj_parametre_OPT_force(OPT_0_SPECIALNE, pom_MODL_OPTF_SPECIALNE, _global_opt_specialne);

	// option force 1
	_rozparsuj_parametre_OPT_force(OPT_1_CASTI_MODLITBY, pom_MODL_OPTF_CASTI_MODLITBY, _global_opt_casti_modlitby);

	// option force 2
	_rozparsuj_parametre_OPT_force(OPT_2_HTML_EXPORT, pom_MODL_OPTF_HTML_EXPORT, _global_opt_html_export);

	// option force 3
	i = atoi(pom_MODL_OPTF[OPT_3_SPOLOCNA_CAST]);
	// predpokladam, ze tento parameter moze byt zadany eventualne cislom (teda retazcom, kt. hodnota pri konverzii na int je int, urcujuci opt_3
	if((i > MODL_SPOL_CAST_NEBRAT) || (i <= 0)){
		i = 0;
		// ide o znakovy retazec nekonvertovatelny na cislo
	}
	else{
		mystrcpy(pom_MODL_OPTF[OPT_3_SPOLOCNA_CAST], nazov_spolc(i), SMALL);
		// ak je zadane cislo spravne, tak i bude spravny int a pom_MODL_OPTF[OPT_3_SPOLOCNA_CAST] bude spravny char*
	}
	Log("optf_3: i == %d\n", i);
	while(i <= MODL_SPOL_CAST_NEBRAT){
		if(equals(pom_MODL_OPTF[OPT_3_SPOLOCNA_CAST], nazov_spolc(i))){
			_global_optf[OPT_3_SPOLOCNA_CAST] = i;
			break;
		}
		i++;
	}
	if(i > MODL_SPOL_CAST_NEBRAT){
		_global_optf[OPT_3_SPOLOCNA_CAST] = GLOBAL_OPTION_NULL /* MODL_SPOL_CAST_NEURCENA */;
	}
	Log("optf %d == `%s' (%d)\n", OPT_3_SPOLOCNA_CAST, pom_MODL_OPTF[OPT_3_SPOLOCNA_CAST], _global_optf[OPT_3_SPOLOCNA_CAST]);

	// option force 4
	_rozparsuj_parametre_OPT_force(OPT_4_OFFLINE_EXPORT, pom_MODL_OPTF_OFFLINE_EXPORT, _global_opt_offline_export);

	// option force 5
	_rozparsuj_parametre_OPT_force(OPT_5_ALTERNATIVES, pom_MODL_OPTF_ALTERNATIVES, _global_opt_alternatives);

	// 2007-06-01: nasledovná pasáž kontroluje, či niektoré z options nie sú GLOBAL_OPTION_NULL a zároveň prípadne nastaví na default podľa jazyka
	// 2011-01-26: doplnené opt_0 až opt_4 force (okrem opt_3); default sa nastavuje podľa "ne-force" verzií
	// 2011-01-27: CFG_OPTION1_DEFAULT..CFG_OPTION5_DEFAULT doplnené v myconf.h; opravené ich použitie :) 2011-02-01
	// 2011-04-07: upravené
	// 2012-08-27: aj pre hodnotu 3 sa vykonáva
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		Log("i == %d...\n", i);
		if(_global_opt[i] == GLOBAL_OPTION_NULL){
			_global_opt[i] = CFG_OPTION_DEFAULT(i);
			Log("Keďže bolo _global_opt[%d] == GLOBAL_OPTION_NULL, nastavujem na `%d'...\n", i, _global_opt[i]);
		}
	}// for i

	// 2012-08-27: aj pre hodnotu 3 sa vykonáva
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		Log("i == %d...\n", i);
		if(_global_optf[i] == GLOBAL_OPTION_NULL){
			_global_optf[i] = _global_opt[i];
			Log("Keďže bolo _global_optf[%d] == GLOBAL_OPTION_NULL, nastavujem na _global_opt[%d] == `%d'...\n", i, i, _global_optf[i]);
		}
		else{
			_global_opt[i] = _global_optf[i];
			Log("Force; do _global_opt[%d] priraďujem _global_optf[%d] (`%d')...\n", i, i, _global_optf[i]);
		}
		// 2011-05-06: špeciálna úprava: zohľadnenie defaultu z config súboru pre 4. bit (BIT_OPT_2_FONT_NAME_CHOOSER)
		if(i == OPT_2_HTML_EXPORT){
			// teraz platí, že _global_opt[i] == _global_optf[i], takže stačí testovať jednu z nich, ale upraviť treba obe hodnoty

			// špeciálne: pre 4. bit (BIT_OPT_2_FONT_NAME_CHOOSER)
			Log("špeciálna úprava: zohľadnenie defaultu z config súboru pre 4. bit (BIT_OPT_2_FONT_NAME_CHOOSER)\n");
			opt_2_fn = ((CFG_OPTION_DEFAULT(i) & BIT_OPT_2_FONT_NAME_CHOOSER) == BIT_OPT_2_FONT_NAME_CHOOSER)? ANO: NIE;
			if(((_global_optf[i] & BIT_OPT_2_FONT_NAME_CHOOSER) == BIT_OPT_2_FONT_NAME_CHOOSER) && (opt_2_fn == NIE)){
				Log("odstraňujem z _global_opt aj _global_optf[%d] bit pre BIT_OPT_2_FONT_NAME_CHOOSER\n...", i);
				_global_optf[i] -= BIT_OPT_2_FONT_NAME_CHOOSER;
				_global_opt[i] -= BIT_OPT_2_FONT_NAME_CHOOSER;
			}
			else if(((_global_optf[i] & BIT_OPT_2_FONT_NAME_CHOOSER) != BIT_OPT_2_FONT_NAME_CHOOSER) && (opt_2_fn == ANO)){
				Log("pridávam do _global_optf[%d] bit pre BIT_OPT_2_FONT_NAME_CHOOSER\n...", i);
				_global_optf[i] += BIT_OPT_2_FONT_NAME_CHOOSER;
				_global_opt[i] += BIT_OPT_2_FONT_NAME_CHOOSER;
			}
			else{
				Log("nie je potrebné upravovať ani _global_opt ani _global_optf[%d].\n", i);
			}
			Log("po potenciálnej úprave: _global_opt aj _global_optf[%d] == `%d'...\n", i, _global_optf[i]);

			// špeciálne: pre 5. bit (BIT_OPT_2_FONT_SIZE_CHOOSER)
			Log("špeciálna úprava: zohľadnenie defaultu z config súboru pre 5. bit (BIT_OPT_2_FONT_SIZE_CHOOSER)\n");
			opt_2_fs = ((CFG_OPTION_DEFAULT(i) & BIT_OPT_2_FONT_SIZE_CHOOSER) == BIT_OPT_2_FONT_SIZE_CHOOSER)? ANO: NIE;
			if(((_global_optf[i] & BIT_OPT_2_FONT_SIZE_CHOOSER) == BIT_OPT_2_FONT_SIZE_CHOOSER) && (opt_2_fs == NIE)){
				Log("odstraňujem z _global_opt aj _global_optf[%d] bit pre BIT_OPT_2_FONT_SIZE_CHOOSER\n...", i);
				_global_optf[i] -= BIT_OPT_2_FONT_SIZE_CHOOSER;
				_global_opt[i] -= BIT_OPT_2_FONT_SIZE_CHOOSER;
			}
			else if(((_global_optf[i] & BIT_OPT_2_FONT_SIZE_CHOOSER) != BIT_OPT_2_FONT_SIZE_CHOOSER) && (opt_2_fs == ANO)){
				Log("pridávam do _global_optf[%d] bit pre BIT_OPT_2_FONT_SIZE_CHOOSER\n...", i);
				_global_optf[i] += BIT_OPT_2_FONT_SIZE_CHOOSER;
				_global_opt[i] += BIT_OPT_2_FONT_SIZE_CHOOSER;
			}
			else{
				Log("nie je potrebné upravovať ani _global_opt ani _global_optf[%d].\n", i);
			}
			Log("po potenciálnej úprave: _global_opt aj _global_optf[%d] == `%d'...\n", i, _global_optf[i]);

		}// (i == OPT_2_HTML_EXPORT)
	}// for i

	Log("=== Po potenciálnych úpravách (nastavenie default hodnôt podľa jazyka) ===\n");
	log_pom_MODL_OPT();
	log_pom_MODL_OPTF();
	Log("_rozparsuj_parametre_OPT() -- koniec.\n");
}// _rozparsuj_parametre_OPT()

//---------------------------------------------------------------------
// _main_rozbor_dna(char *, char *, char *, char *, char *)
//
// dostane 3 stringy (datum) + mozno 2 striny (modlitba, dalsi_svaty), prekonvertuje ich a skontroluje ak je vsetko ok, 
// vykona _main_rozbor_dna(int, int, int) resp. _main_rozbor_mesiaca(int) resp. cely rok, 12krat rozbor_mesiaca(int)
#define ExportUDAJE	result = FAILURE; if(!heading_written){_export_heading("Rozbor dňa"); heading_written = 1;} Log("error: Nevhodne udaje\n"); Export("Nevhodné údaje: "); Export
void _main_rozbor_dna(char *den, char *mesiac, char *rok, char *modlitba, char *poradie_svaty){
	short int heading_written = 0;
	char pom[MAX_STR];
	Log("-- _main_rozbor_dna(char *, char *, char *, char *, char *): begin (%s, %s, %s, %s, %s)\n",
		den, mesiac, rok, modlitba, poradie_svaty);
	short int d, m, r, p, s;
	short int pm, pr; // pomocny mesiac, pomocny rok

	char pom2[MAX_STR]; // 2006-08-01: pridané kvôli transferu údajov o jazyku
	mystrcpy(pom, STR_EMPTY, MAX_STR);
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	char pom3[MAX_STR]; // 2008-08-08: pridané kvôli css
	mystrcpy(pom3, STR_EMPTY, MAX_STR);
	char str_month[SMALL] = STR_EMPTY; // 2009-08-12: pridané

	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);

	short int som_v_tabulke = ANO; // 2009-08-26: či sa používa tabuľka; bežne pre web áno, pre export pre mobilné zariadenia [export_monthly_druh >= 3] netreba tabuľku

	if(_global_opt_batch_monthly == ANO && export_monthly_druh > 2){
		som_v_tabulke = NIE;
		Log("-- _main_rozbor_dna: keďže sme v _global_opt_batch_monthly == ANO a export_monthly_druh (%d) > 2, nebudeme exportovať tabuľku...\n", export_monthly_druh);
	}

	prilep_request_options(pom2, pom3);

	// rozparsovanie parametrov den, mesiac, rok, svaty
	Log("/* rozparsovanie parametrov den, mesiac, rok, svaty */\n");
	d = atoden(den); // vrati VSETKY_DNI, resp. atoi(den)
	Log("den == `%s' (%d)\n", den, d);
	m = atomes(mesiac); // bude to 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC
	Log("mes == `%s' (%d)\n", mesiac, m);
	r = atoi(rok); // vrati 0 v pripade chyby; alebo int
	Log("rok == `%s' (%d)\n", rok, r);
	s = atoi(poradie_svaty); // ak je viac svatych, ktory z nich (1--MAX_POCET_SVATY)
	// 2009-03-27: doplnené - neznámy je konštanta; zmysel majú len vstupy 1--MAX_POCET_SVATY
	if(s < 1){
		s = UNKNOWN_PORADIE_SVATEHO;
	}
	if(s > PORADIE_PM_SOBOTA){
		s = UNKNOWN_PORADIE_SVATEHO;
	}
	Log("sv == `%s' (upravené na %d)\n", poradie_svaty, s);

	// rozparsovanie parametra modlitba
	Log("volanie atomodlitba() z _main_rozbor_dna()...\n");
	p = atomodlitba(modlitba);

	_global_modlitba = p;
	Log("modl == %s (%d, %s) -- priradene do _global_modlitba\n", modlitba, p, nazov_modlitby(p));

	// option a (append), pridana 2003-07-08 - nastavi sa v getArgv();

	// kontrola údajov
	short int result = SUCCESS;
	// deň
	if(equals(den, STR_EMPTY)){
		ExportUDAJE("chýba údaj o dni."HTML_LINE_BREAK"\n");
	}
	else if(d == 0){
		ExportUDAJE("deň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"."HTML_LINE_BREAK"\n", den);
	}
	// mesiac
	if(equals(mesiac, STR_EMPTY)){
		ExportUDAJE("chýba údaj o mesiaci."HTML_LINE_BREAK"\n");
	}
	else if(m == UNKNOWN_MESIAC){
		ExportUDAJE("taký mesiac nepoznám (%s)."HTML_LINE_BREAK"\n", mesiac);
	}
	// rok
	if(equals(rok, STR_EMPTY)){
		ExportUDAJE("chýba údaj o roku."HTML_LINE_BREAK"\n");
	}
	else if(r == 0){
		ExportUDAJE("rok = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"."HTML_LINE_BREAK"\n", rok);
	}

	// kontrola údajov ukončená, podľa nej pokračujeme ďalej
	if(result == FAILURE){
		Log("/* teraz result == FAILURE */\n");
		ALERT;
		return;
	}

	Log("/* teraz result == SUCCESS */\n");
	if(m == VSETKY_MESIACE){
		if(p != MODL_NEURCENA){
			ExportUDAJE("pre viacej mesiacov zobrazenie modlitby nie je podporované\n");
			return;
		}// p != MODL_NEURCENA
		if((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_MESIAC_RIADOK) != BIT_OPT_4_MESIAC_RIADOK){
			// 2011-04-13: podmienka sa riadi jedným z bitov option 4
			Log("/* teraz vypisujem heading, rok %d */\n", r);
			sprintf(pom, (char *)html_text_Rok_x[_global_jazyk], r);
			_export_heading_center(pom);
			// nezobrazovalo sa korektne; pridane </a>, 2003-07-02
			Export("<a name=\"rok\"></a>\n");
			Export("<center>\n");
			// najprv vygenerujem zoznam liniek (mesiace)
			for(m = MES_JAN; m <= MES_DEC; m++){
				Export("<a href=\"#mesiac%d\">%s</a>"HTML_NONBREAKING_SPACE"\n", m, nazov_MESIACA(m));
			}
			// teraz linku na #explain -- vysvetlivky

			Export(HTML_LINE_BREAK"<"HTML_SPAN_SMALL"><a href=\"#explain\">%s</a>"HTML_SPAN_END"\n", html_text_Vysvetlivky[_global_jazyk]);
			// napokon ciaru (kedysi tu bol element hr)
			Export("</center>\n<p>\n");
		}

		// teraz generujem jednotlive mesiace so vsetkymi dnami
		for(m = MES_JAN; m <= MES_DEC; m++){
			/*
				Vytvor_global_link(VSETKY_DNI, m + 1, r, NIE);
				// nezobrazovalo sa korektne; pridane </a>, 2003-07-02
				Export("\n\n<a name=\"mesiac%d\"></a>", m);
				Export("\n<p><center><"HTML_SPAN_BOLD">%s"HTML_SPAN_END" (<a href=\"#rok\">zoznam mesiacov</a>)</center>\n", _global_link);
				rozbor_mesiaca(m + 1, r);
			*/
			if((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_MESIAC_RIADOK) != BIT_OPT_4_MESIAC_RIADOK){
				// 2005-03-22: Toto zobrazujeme len pre isty typ exportu
				// 2011-04-13: podmienka sa riadi jedným z bitov option 4
				Export("\n\n<a name=\"mesiac%d\"></a>", m);
				Export("\n<p><center><"HTML_SPAN_RED_BOLD">%s"HTML_SPAN_END, nazov_MESIACA(m));
				Export(" (<a href=\"#rok\">%s</a>)</center>\n", html_text_zoznam_mesiacov[_global_jazyk]);
			}
			rozbor_mesiaca(m + 1, r);
		}// for(m)

		vysvetlivky();

		if((_global_linky == ANO) && ((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_MESIAC_RIADOK) != BIT_OPT_4_MESIAC_RIADOK)){
			// 2005-03-22: Upravene; podmienka zosilnena (and _global_opt[OPT_1_CASTI_MODLITBY] == NIE)
			Export("\n");
			Export(HTML_LINE_BREAK"\n");
			Export("<center><table>\n");
			// predošlý rok -- button
			Export("<td "HTML_ALIGN_RIGHT">");
			sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d%s",
			// Export("<td "HTML_ALIGN_RIGHT"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, STR_VSETKY_DNI,
				STR_MESIAC, STR_VSETKY_MESIACE,
				STR_ROK, r - 1,
				pom2);
			Export_HtmlForm(action);
			// 2003-07-16; << zmenene na &lt;&lt; 2007-03-19: zmenené na HTML_LEFT_ARROW
			Export("<"HTML_FORM_INPUT_SUBMIT0" value=\""HTML_LEFT_ARROW" %d (", r - 1);
			Export((char *)html_button_predchadzajuci_[_global_jazyk]);
			Export(" ");
			Export((char *)html_text_rok[_global_jazyk]);
			Export(" )\">\n");
			Export("</form></td>\n");

			// nasledujúci rok -- button
			Export("<td "HTML_ALIGN_LEFT">");
			sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d%s",
			// Export("<td "HTML_ALIGN_RIGHT"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, STR_VSETKY_DNI,
				STR_MESIAC, STR_VSETKY_MESIACE,
				STR_ROK, r + 1,
				pom2);
			Export_HtmlForm(action);
			// 2003-07-16; >> zmenene na &gt;&gt; 2007-03-19: zmenené na HTML_RIGHT_ARROW
			Export("<"HTML_FORM_INPUT_SUBMIT0" value=\"(");
			Export((char *)html_button_nasledujuci_[_global_jazyk]);
			Export(" ");
			Export((char *)html_text_rok[_global_jazyk]);
			Export(" ) %d "HTML_RIGHT_ARROW"\">\n", r + 1);
			Export("</form></td>\n");
			// koniec buttonov
			Export("</table></center>\n");
		}// if(_global_linky == ANO)
	}// m == VSETKY_MESIACE
	else{// m != VSETKY_MESIACE
		// nesmiem zabudnut, ze m je 0--11
		m++;
		if(d == VSETKY_DNI){
			if(p != MODL_NEURCENA){
				ExportUDAJE("pre viacej dní zobrazenie modlitby nie je podporované\n");
				return;
			}
			Log("/* teraz vypisujem heading 1, mesiac %s, rok %d */\n", nazov_mesiaca(m - 1), r);

			if(prestupny(r)){
				pocet_dni[MES_FEB] = 29;
			}
			else{
				pocet_dni[MES_FEB] = 28;
			}

			if(_global_opt_batch_monthly == NIE){
				vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, r, LINK_DEN_MESIAC_ROK, NIE);
			}// if(_global_opt_batch_monthly == NIE)
			else{
				// 2009-08-12: pre batch mód export vytlačíme len rok bez linku
				sprintf(_global_link, "%d", r);
			}// else if(_global_opt_batch_monthly == NIE)
			if(format_datumu[_global_jazyk] == FORMAT_DATUMU_ROK_MESIAC_DEN){
				sprintf(pom, "%s. %s", _global_link, nazov_mesiaca(m - 1));
			}
			else{
				sprintf(pom, "%s %s", nazov_Mesiaca(m - 1), _global_link);
			}
			_export_heading_center(pom);

			// Name of the month in the monthly page.
			// Disabled, because the year and the month have been
			// already printed above this.
			//Export("<center><"HTML_SPAN_RED_BOLD">%s"HTML_SPAN_END"</center>\n", nazov_MESIACA(m - 1));

			rozbor_mesiaca(m, r);

			vysvetlivky();

			// 2009-08-12: podmienka upravená; export aj pre batch mód mesačný
			if(((_global_linky == ANO) && ((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_MESIAC_RIADOK) != BIT_OPT_4_MESIAC_RIADOK)) || ((_global_opt_batch_monthly == ANO) && (export_monthly_druh >= 2))){
			// 2005-03-22: Upravene; podmienka zosilnena (and _global_opt[OPT_1_CASTI_MODLITBY] == NIE)
			// 2011-04-13: podmienka sa riadi jedným z bitov option 4
				if(som_v_tabulke == ANO)
					Export("\n<table "HTML_ALIGN_CENTER">\n");
				else{
					Export("\n<p><center>\n");
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}

				// 2008-02-27: nasledujú tlačidlá; doplnený "ten istý mesiac pred rokom", "ten istý mesiac o rok"
				if(som_v_tabulke == ANO){
					Export("<tr>\n");
				}

				// predosly mesiac -- button
				pm = m; pr = r;
				if(m == 1){
					pm = 12;
					pr = r - 1;
				}
				else{
					pm = m - 1;
				}
				if(_global_opt_batch_monthly == NIE){
					sprintf(pom, HTML_LINK_CALL2,
						script_name,
						STR_QUERY_TYPE, STR_PRM_DATUM,
						STR_DEN, STR_VSETKY_DNI,
						STR_MESIAC, pm,
						STR_ROK, pr,
						pom2);
				}// if(_global_opt_batch_monthly == NIE)
				else{
					// najprv treba predlepiť adresár...
					if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
						sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_SIMPLE""STR_PATH_SEPARATOR_HTML, pr % 100, pm, nazov_mes[pm - 1]);
					else // EXPORT_DATE_FULL
						sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_FULL""STR_PATH_SEPARATOR_HTML, pr, pm, nazov_mesiaca_asci(pm - 1));
					// ... a potom celý reťazec s názvom súboru pre daný mesiac
					if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
						sprintf(pom, "%s"FILENAME_EXPORT_MONTH_SIMPLE".htm", str_month, pr % 100, pm);
					else
						sprintf(pom, "%s"FILENAME_EXPORT_MONTH_FULL".htm", str_month, pr, pm);
				}
				Log("\treťazec pom == %s\n", pom);
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_RIGHT">");
					Export_HtmlForm(pom);
					// 2007-03-19: << zmenené na HTML_LEFT_ARROW
					if(_global_jazyk == JAZYK_HU){
						Export("<"HTML_FORM_INPUT_SUBMIT0" value=\""HTML_LEFT_ARROW" %d. %s\">\n", pr, nazov_mesiaca(pm - 1));
					}
					else{
						Export("<"HTML_FORM_INPUT_SUBMIT0" value=\""HTML_LEFT_ARROW" %s %d\">\n", nazov_Mesiaca(pm - 1), pr);
					}
					Export("</form></td>\n");
				}			
				else{
					if(_global_jazyk == JAZYK_HU){
						Export("<a href=\"%s\">"HTML_LEFT_ARROW" %d. %s</a>\n", pom, pr, nazov_mesiaca(pm - 1));
					}
					else{
						Export("<a href=\"%s\">"HTML_LEFT_ARROW" %s %d</a>\n", pom, nazov_Mesiaca(pm - 1), pr);
					}
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}

				// nasledujuci mesiac -- button
				pm = m; pr = r;
				if(m == 12){
					pm = 1;
					pr = r + 1;
				}
				else{
					pm = m + 1;
				}
				if(_global_opt_batch_monthly == NIE){
					sprintf(pom, HTML_LINK_CALL2,
						script_name,
						STR_QUERY_TYPE, STR_PRM_DATUM,
						STR_DEN, STR_VSETKY_DNI,
						STR_MESIAC, pm,
						STR_ROK, pr,
						pom2);
				}// if(_global_opt_batch_monthly == NIE)
				else{
					// najprv treba predlepiť adresár...
					if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
						sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_SIMPLE""STR_PATH_SEPARATOR_HTML, pr % 100, pm, nazov_mes[pm - 1]);
					else // EXPORT_DATE_FULL
						sprintf(str_month, ".."STR_PATH_SEPARATOR_HTML""DIRNAME_EXPORT_MONTH_FULL""STR_PATH_SEPARATOR_HTML, pr, pm, nazov_mesiaca_asci(pm - 1));
					// ... a potom celý reťazec s názvom súboru pre daný mesiac
					if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE)
						sprintf(pom, "%s"FILENAME_EXPORT_MONTH_SIMPLE".htm", str_month, pr % 100, pm);
					else
						sprintf(pom, "%s"FILENAME_EXPORT_MONTH_FULL".htm", str_month, pr, pm);
				}
				Log("\treťazec pom == %s\n", pom);
				if(som_v_tabulke == ANO){
					Export("<td "HTML_ALIGN_LEFT">");
					Export_HtmlForm(pom);
					// 2007-03-19: >> zmenené na HTML_RIGHT_ARROW
					if(_global_jazyk == JAZYK_HU){
						Export("<"HTML_FORM_INPUT_SUBMIT0" value=\"%d. %s "HTML_RIGHT_ARROW"\">\n", pr, nazov_mesiaca(pm - 1));
					}
					else{
						Export("<"HTML_FORM_INPUT_SUBMIT0" value=\"%s %d "HTML_RIGHT_ARROW"\">\n", nazov_Mesiaca(pm - 1), pr);
					}
					Export("</form></td>\n");
				}
				else{
					if(_global_jazyk == JAZYK_HU){
						Export("<a href=\"%s\">%d. %s "HTML_RIGHT_ARROW"</a>\n", pom, pr, nazov_mesiaca(pm - 1));
					}
					else{
						Export("<a href=\"%s\">%s %d "HTML_RIGHT_ARROW"</a>\n", pom, nazov_Mesiaca(pm - 1), pr);
					}
					Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
				}

				if(som_v_tabulke == ANO){
					Export("</tr>\n");
					// odtiaľto export <tr> presunutý až do samotného exportu...
				}
				else{
					Export("</center>"HTML_LINE_BREAK);
				}

				// ten istý mesiac pred rokom -- button
				pm = m; 
				pr = r - 1;
				if(_global_opt_batch_monthly == NIE){
					sprintf(pom, HTML_LINK_CALL2,
						script_name,
						STR_QUERY_TYPE, STR_PRM_DATUM,
						STR_DEN, STR_VSETKY_DNI,
						STR_MESIAC, pm,
						STR_ROK, pr,
						pom2);
				}// if(_global_opt_batch_monthly == NIE)
				else{
					mystrcpy(pom, STR_EMPTY, MAX_STR);
					// 2009-08-12: možno v budúcnosti by sa mohol dať odkaz na adresár s mesiacom predošlého roka
				}
				if(_global_opt_batch_monthly == NIE){
					if(som_v_tabulke == ANO){
						Export("<tr>\n");
						// ...sem
						Export("<td "HTML_ALIGN_RIGHT">");
						Export_HtmlForm(pom);
						Export("<"HTML_FORM_INPUT_SUBMIT0" value=\""HTML_LEFT_ARROW" %s %d\">\n", nazov_Mesiaca(pm - 1), pr);
						Export("</form></td>\n");
					}
					else{
						Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
						//
						Export("<a href=\"%s\">"HTML_LEFT_ARROW" %s %d</a>\n", pom, nazov_Mesiaca(pm - 1), pr);
						Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
					}
				}

				// ten istý mesiac o rok -- button
				pm = m; 
				pr = r + 1;
				if(_global_opt_batch_monthly == NIE){
					sprintf(pom, HTML_LINK_CALL2,
						script_name,
						STR_QUERY_TYPE, STR_PRM_DATUM,
						STR_DEN, STR_VSETKY_DNI,
						STR_MESIAC, pm,
						STR_ROK, pr,
						pom2);
				}// if(_global_opt_batch_monthly == NIE)
				else{
					mystrcpy(pom, STR_EMPTY, MAX_STR);
					// 2009-08-12: možno v budúcnosti by sa mohol dať odkaz na adresár s mesiacom nasledovného roka
				}
				if(_global_opt_batch_monthly == NIE){
					if(som_v_tabulke == ANO){
						Export("<td "HTML_ALIGN_LEFT">");
						Export_HtmlForm(pom);
						Export("<"HTML_FORM_INPUT_SUBMIT0" value=\"%s %d "HTML_RIGHT_ARROW"\">\n", nazov_Mesiaca(pm - 1), pr);
						Export("</form></td>\n");
					}
					else{
						Export("<a href=\"%s\">%s %d "HTML_RIGHT_ARROW"</a>\n", pom, nazov_Mesiaca(pm - 1), pr);
						Export(HTML_NONBREAKING_SPACE); Export(HTML_VERTICAL_BAR); Export(HTML_NONBREAKING_SPACE); Export("\n");
					}
				}

				if(som_v_tabulke == ANO){
					Export("</tr>\n");
				}

				// koniec buttonov
				if(som_v_tabulke == ANO){
					Export("</table>\n");
				}
			}// _global_linky == ANO
		}// d == VSETKY_DNI
		else{// d != VSETKY_DNI
			if(!kontrola_den_mesiac_rok(d, m, r)){
				Log("/* teraz vypisujem heading 1, datum %d. %s %d */\n", d, nazov_mesiaca(m - 1), r);
				// 2007-03-20: spôsob výpisu dátumu podľa jazyka 
				// 2011-05-12: doplnené nové konštanty
				// 2011-11-12: použitie funkcie _vytvor_string_z_datumu()
				strcpy(pom, _vytvor_string_z_datumu(d, m, r, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
				/*
				if(format_datumu[_global_jazyk] == FORMAT_DATUMU_ROK_MESIAC_DEN){
					// 2011-05-12: pôvodne bolo: 2010-05-21: doplnené pre maďarčinu: 1999. augusztus 1. -- http://en.wikipedia.org/wiki/Date_and_time_notation_by_country#Hungary [2010-05-24]
					if(_global_jazyk == JAZYK_HU){
						sprintf(pom, "%d. %s %d.", r, nazov_mesiaca(m - 1), d);
					}
				}// FORMAT_DATUMU_ROK_MESIAC_DEN
				else if(format_datumu[_global_jazyk] == FORMAT_DATUMU_MESIAC_DEN_ROK){
					if(_global_jazyk == JAZYK_EN){
						sprintf(pom, "%s %d, %d", nazov_Mesiaca(m - 1), d, r);
					}
				}// FORMAT_DATUMU_MESIAC_DEN_ROK
				else{
					// format_datumu[_global_jazyk] == FORMAT_DATUMU_DEN_MESIAC_ROK
					// latinčina používa genitív
					sprintf(pom, "%d. %s %d", d, (_global_jazyk == JAZYK_LA)? nazov_Mesiaca_gen(m - 1): nazov_mesiaca(m - 1), r);
				}// FORMAT_DATUMU_DEN_MESIAC_ROK
				*/
				_export_heading_center(pom);
				// 2003-06-30: podla toho, ci je alebo nie je urcena modlitba
				if(p == MODL_NEURCENA){
					rozbor_dna(d, m, r);
					// 2007-08-15: volanie _export_main_formular() presunuté do _export_rozbor_dna()
					// _export_main_formular(d, m, r, den_v_tyzdni(d, m, r));
				}
				else if(p == MODL_VSETKY){
					_global_vstup_den = d;
					_global_vstup_mesiac = m;
					_global_vstup_rok = r;
					_global_poradie_svaty = s;
					Log("_global_poradie_svaty = %d\n", _global_poradie_svaty);
					showAllPrayers(d, m, r, s);
				}
				else{
					_global_vstup_den = d;
					_global_vstup_mesiac = m;
					_global_vstup_rok = r;
					_global_poradie_svaty = s;
					Log("_global_poradie_svaty = %d\n", _global_poradie_svaty);
					// Export("<!-- den %d | mesiac %d | rok %d -->\n", _global_vstup_den, _global_vstup_mesiac, _global_vstup_rok);
					rozbor_dna_s_modlitbou(d, m, r, p, s);
				}
			}
		}// d != VSETKY_DNI
	}// m != VSETKY_MESIACE

	Log("-- _main_rozbor_dna(char *, char *, char *, char *, char *): end\n");
}// _main_rozbor_dna()

// 2011-02-02: pridaná funkcia pre jednoduchý TXT export konkrétneho roka, mesiaca
// 2012-10-16: pridaný parameter typ (určuje, či ide o TXT alebo XML export)
void _main_rozbor_dna_txt(short int typ, char *den, char *mesiac, char *rok){
	// na základe _main_rozbor_dna; textový export len pre RKC; XML napr. pre iOS
	short int heading_written = 0;
	char pom[MAX_STR];
	Log("-- _main_rozbor_dna_txt(short int, char *, char *, char *): begin (%d, %s, %s, %s)\n", typ, den, mesiac, rok);
	short int d, m, mi, r, t;

	char pom2[MAX_STR]; // 2006-08-01: pridané kvôli transferu údajov o jazyku
	mystrcpy(pom, STR_EMPTY, MAX_STR); // 2006-08-01: pridaná inicializácia
	mystrcpy(pom2, STR_EMPTY, MAX_STR); // 2006-08-01: pridané
	char pom3[MAX_STR]; // 2008-08-08: pridané kvôli css
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	// rozparsovanie parametrov den, mesiac, rok
	Log("/* rozparsovanie parametrov den, mesiac, rok */\n");
	d = atoden(den); // vrati VSETKY_DNI, resp. atoi(den)
	Log("den == `%s' (%d)\n", den, d);
	m = atomes(mesiac); // bude to 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC
	Log("mes == `%s' (%d)\n", mesiac, m);
	r = atoi(rok); // vrati 0 v pripade chyby; alebo int
	Log("rok == `%s' (%d)\n", rok, r);

	// kontrola údajov
	short int result = SUCCESS;
	// deň
	if(equals(den, STR_EMPTY)){
		ExportUDAJE("chýba údaj o dni.\n");
	}
	else if(d == 0){
		ExportUDAJE("deň = %s.\n", den);
	}
	// mesiac
	if(equals(mesiac, STR_EMPTY)){
		ExportUDAJE("chýba údaj o mesiaci.\n");
	}
	else if(m == UNKNOWN_MESIAC){
		ExportUDAJE("taký mesiac nepoznám (%s).\n", mesiac);
	}
	// rok
	if(equals(rok, STR_EMPTY)){
		ExportUDAJE("chýba údaj o roku.\n");
	}
	else if(r == 0){
		ExportUDAJE("rok = %s.\n", rok);
	}
	// modlitba -> typ exportu
	if(typ == PRM_TXT){
		t = EXPORT_DNA_VIAC_DNI_TXT;
	}
	else if(typ == PRM_XML){
		t = EXPORT_DNA_XML;
	}

	// kontrola udajov ukoncena, podla nej pokracujeme dalej
	if(result == FAILURE){
		Log("/* teraz result == FAILURE */\n");
		ALERT;
		return;
	}

	Log("/* teraz result == SUCCESS */\n");
	if(m != UNKNOWN_MESIAC){
		// 2012-10-16: pre XML export sa hlavička neexportuje
		if(t != EXPORT_DNA_XML){
			Export("<h2>");
			Export((char *)html_text_txt_export[_global_jazyk]);
			Export((char *)html_text_lit_kalendar[_global_jazyk]);
			Export(" ");
			if(m == VSETKY_MESIACE){
				Export((char *)html_text_rok[_global_jazyk]);
				Export(" %d", r);
			}// if(m == VSETKY_MESIACE)
			else{
				if(d == VSETKY_DNI){
					Export((char *)html_text_mesiac[_global_jazyk]);
				}
				else{
					Export((char *)html_text_den[_global_jazyk]);
					Export(" %d.", d);
					if((t != EXPORT_DNA_JEDEN_DEN) || (t != EXPORT_DNA_XML)){
						t = EXPORT_DNA_JEDEN_DEN;
					}
				}
				Export(" %s", nazov_mesiaca(m));
				Export(" %d", r);
			}// else (m != VSETKY_MESIACE)
			Export("</h2>");
		}

		Export("\n");

		if(t == EXPORT_DNA_VIAC_DNI_TXT){
			Export("<pre>");
		}

		// teraz generujem jednotlivé mesiace so všetkými dňami
		if(m == VSETKY_MESIACE){
			for(mi = MES_JAN; mi <= MES_DEC; mi++){
#ifdef NIELEN_PRE_PETA_ZIMENA
				Export("\n\n");
				Export((char *)html_text_mesiac[_global_jazyk]);
				Export(" == %d ", mi + 1);
				Export("(%s)\n", nazov_mesiaca(m));
#endif
				rozbor_mesiaca(mi + 1, r, t); // tam sa volá _rozbor_dna() a potom _export_rozbor_dna()
			}// for mi
		}// if(m == VSETKY_MESIACE)
		else{
			if(d == VSETKY_DNI){
				rozbor_mesiaca(m + 1, r, t); // tam sa volá _rozbor_dna() a potom _export_rozbor_dna()
			}
			else{
				_struct_den_mesiac datum;
				datum.den = d;
				datum.mesiac = m + 1;
				// najprv, kopírujúc rozbor_dna(), musíme predplniť údaje o roku...
				analyzuj_rok(r); // výsledok dá do _global_r
				// teraz rozbor samotného dňa...
				_rozbor_dna(datum, r);
				Log("-- _main_rozbor_dna_txt(): nasleduje _export_rozbor_dna() pre deň %d...\n", datum.den);
				_export_rozbor_dna(t);
				Log("-- _main_rozbor_dna_txt(): deň %d skončil.\n", datum.den);
			}
		}
		// XML export -- export options
		if(t == EXPORT_DNA_XML){
			xml_export_options();
		}
		else{
			Export("\n");
		}
		if(t == EXPORT_DNA_VIAC_DNI_TXT){
			Export("</pre>\n");
		}
	}// m != UNKNOWN_MESIAC
	else{// m == UNKNOWN_MESIAC
		// nesmiem zabudnut, ze m je 0--11
		Export("Číslo mesiaca: nezadaný alebo nepodporovaný vstup.\n");
	}// m != VSETKY_MESIACE

	Log("-- _main_rozbor_dna_txt(short int, char *, char *, char *): end\n");
}// _main_rozbor_dna_txt()

struct tm _get_dnes(void){
	time_t timer;
	struct tm dnes;

	// zisti denny cas
	// 2009-05-22: pôvodne tu bolo: timer = time(NULL); 
	// Pavel Kučera <teni@volny.cz> však poprosil, aby aj po polnoci ešte chvíľu bolo možné modliť sa kompletórium
	// posunuté na pol tretiu: má to hlbokú logiku: pravdepodobne nik sa -- hoci aj po polnoci -- nemodlí ofícium z nasledovného dňa... 
	// invitatórium by malo byť prvou rannou modlitbou po zobudení. 
	// myslím, že sú výnimočné prípady, že ľuda regulérne modliaci sa breviár vstávajú o jednej, o druhej v noci (čím začne ich nový deň).
	timer = time(NULL)-(time_t)(2.5*60*60);

	// konvertuje date/time na strukturu
	dnes = *localtime(&timer);

	// upravenie time_check structure with the data
	dnes.tm_mon  = dnes.tm_mon + 1;
	dnes.tm_year = dnes.tm_year + 1900;
	dnes.tm_yday = dnes.tm_yday + 1;

	return dnes;
}

//---------------------------------------------------------------------
//
// _main_dnes();
//
// vypluje cely objednavaci formular, ktory obsahuje dnesny den, udaje o nom, linku nan, okienka pre den, mesiac, rok; okienko pre (analyzu) rok; okienko pre sviatok, ... a tak.
// historicka poznamka: kedysi sa volala dnes(); potom prazdny_formular();
// 2006-02-10: pridaná možnosť priamo generovať modlitbu, preto sú vstupom aj dve premenné podobne ako je to v _main_rozbor_dna
void _main_dnes(char *modlitba, char *poradie_svaty){
	short int s, p;
	// time_t timer;
	struct tm dnes;
	long jd_dnes;
	char pom[MAX_STR];

	Log("-- _main_dnes(char *, char *): begin (%s, %s)\n", modlitba, poradie_svaty);
/*
	// zisti denny cas
	// 2009-05-22: pôvodne tu bolo: timer = time(NULL); 
	// Pavel Kučera <teni@volny.cz> však poprosil, aby aj po polnoci ešte chvíľu bolo možné modliť sa kompletórium
	// posunuté na pol tretiu: má to hlbokú logiku: pravdepodobne nik sa -- hoci aj po polnoci -- nemodlí ofícium z nasledovného dňa... 
	// invitatórium by malo byť prvou rannou modlitbou po zobudení. 
	// myslím, že sú výnimočné prípady, že ľuda regulérne modliaci sa breviár vstávajú o jednej, o druhej v noci (čím začne ich nový deň).
	timer = time(NULL)-(time_t)(2.5*60*60);

	// konvertuje date/time na strukturu
	dnes = *localtime(&timer);

	// upravenie time_check structure with the data
	dnes.tm_mon  = dnes.tm_mon + 1;
	dnes.tm_year = dnes.tm_year + 1900;
	dnes.tm_yday = dnes.tm_yday + 1;
*/
	dnes = _get_dnes();

	// juliansky datum
	jd_dnes = JD(dnes.tm_mday, dnes.tm_mon, dnes.tm_year);

	// dnes.tm_wday == 0--6 (0==sunday, nedela)

	// dalej rozoberiem den a vypisem vysledok
	_struct_den_mesiac datum;
	datum.den = dnes.tm_mday;
	datum.mesiac = dnes.tm_mon;
	analyzuj_rok(dnes.tm_year); // výsledok dá do _global_r

	s = atoi(poradie_svaty); // ak je viac svatych, ktory z nich (1--MAX_POCET_SVATY)
	// 2009-03-27: doplnené - neznámy je konštanta; zmysel majú len vstupy 1--MAX_POCET_SVATY
	if(s < 1){
		s = UNKNOWN_PORADIE_SVATEHO;
	}
	if(s > PORADIE_PM_SOBOTA){
		s = UNKNOWN_PORADIE_SVATEHO;
	}
	Log("sv == `%s' (upravené na %d)\n", poradie_svaty, s);

	// rozparsovanie parametra modlitba
	Log("volanie atomodlitba() z _main_dnes()...\n");
	p = atomodlitba(modlitba);

	_global_modlitba = p;
	Log("modl == %s (%d, %s) -- priradene do _global_modlitba\n", modlitba, p, nazov_modlitby(p));

	// vypis
	Log("/* teraz vypisujem heading 1, datum %d. %s %d */\n", dnes.tm_mday, nazov_mesiaca(dnes.tm_mon - 1), dnes.tm_year);
	// 2007-03-20: spôsob výpisu dátumu podľa jazyka 
	// 2011-05-12: použitá funkcia _vytvor_string_z_datumu()
	strcpy(pom, _vytvor_string_z_datumu(dnes.tm_mday, dnes.tm_mon, dnes.tm_year, ((_global_jazyk == JAZYK_LA) || (_global_jazyk == JAZYK_EN))? CASE_Case : CASE_case, LINK_DEN_MESIAC_ROK, NIE));
/*
	if(_global_jazyk == JAZYK_LA){
		sprintf(pom, "%d. %s %d", dnes.tm_mday, nazov_Mesiaca_gen(dnes.tm_mon - 1), dnes.tm_year);
	}
	else if(_global_jazyk == JAZYK_EN){
		sprintf(pom, "%s %d, %d", nazov_Mesiaca(dnes.tm_mon - 1), dnes.tm_mday, dnes.tm_year);
	}
	else if(_global_jazyk == JAZYK_HU){
		sprintf(pom, "%d. %s %d.", dnes.tm_year, nazov_mesiaca(dnes.tm_mon - 1), dnes.tm_mday);
	}
	else{
		sprintf(pom, "%d. %s %d", dnes.tm_mday, nazov_mesiaca(dnes.tm_mon - 1), dnes.tm_year);
	}
*/
	_export_heading_center(pom);

	// 2006-02-10: výpis juliánskeho dátumu, len ak nie je určená modlitba 
	// 2007-03-19: výpis "Dnes je..." sa zobrazí len pri nastavení HTML_ZOBRAZIT_DNES_JE == 1
	if(_global_modlitba == MODL_NEURCENA){
		if(HTML_ZOBRAZIT_DNES_JE == ANO){
			Export((char *)html_text_dnes_je_atd[_global_jazyk],
				dnes.tm_yday,
#undef ZOBRAZ_JULIANSKY_DATUM
#ifdef ZOBRAZ_JULIANSKY_DATUM
				(char *)STR_EMPTY,
#else
				(char *)HTML_COMMENT_BEGIN,
#endif
				(_global_linky == ANO)? cfg_http_address_default[_global_jazyk]: MESSAGE_FOLDER,
				FILE_JULIANSKY_DATUM,
				jd_dnes,
#ifdef ZOBRAZ_JULIANSKY_DATUM
				(char *)STR_EMPTY
#else
				(char *)HTML_COMMENT_END
#endif
				);
		}
		_rozbor_dna(datum, dnes.tm_year);

		/* 2007-08-16: inicializácia _global_den sa realizuje v _rozbor_dna(); jej čiastočné inicializovanie - porov. nižšie - spôsobovalo problémy. 
		 *  // 2007-08-16: pokus, ktorý nič neriešil: doplnená inicializácia ostatných hodnôt - Segmentation fault pri volaní init_global_string() - podľa _rozbor_dna()
		 * 	// _INIT_DM(_global_den);
		 * 	// 2007-08-15: doplnené nastavenie _global_den, aspoň niektorých hodnôt
		 * 	_global_den.den = datum.den;
		 * 	_global_den.mesiac = datum.mesiac;
		 * 	_global_den.rok = dnes.tm_year;
		 * 	// _global_den.denvt = dnes.tm_year; // tu bola základná príčina Segmentation fault :) to je tak, keď niekto zmieša jabĺčka s hruškami :)
		 *	// malo by byť: 
		 *	_global_den.denvt = den_v_tyzdni(datum.den, datum.mesiac, dnes.tm_year);
		 */

		_export_rozbor_dna(EXPORT_DNA_DNES);

		// 2006-02-02: celý zvyšný formulár presunutý do samostatnej funkcie
		// 2007-08-15: volanie _export_main_formular() presunuté do _export_rozbor_dna() | _export_main_formular(datum.den, datum.mesiac, dnes.tm_year, dnes.tm_wday);
	}
	else if(p == MODL_VSETKY){
		_global_vstup_den = datum.den;
		_global_vstup_mesiac = datum.mesiac;
		_global_vstup_rok = dnes.tm_year;
		_global_poradie_svaty = s;
		Log("_global_poradie_svaty = %d\n", _global_poradie_svaty);
		showAllPrayers(datum.den, datum.mesiac, dnes.tm_year, s);
	}
	else{
		// ak je určená modlitba, postupujeme rovnako ako v _main_rozbor_dna
		_global_vstup_den = datum.den;
		_global_vstup_mesiac = datum.mesiac;
		_global_vstup_rok = dnes.tm_year;
		_global_poradie_svaty = s;
		Log("_global_poradie_svaty = %d\n", _global_poradie_svaty);
		// Export("<!-- den %d | mesiac %d | rok %d -->\n", _global_vstup_den, _global_vstup_mesiac, _global_vstup_rok);
		rozbor_dna_s_modlitbou(datum.den, datum.mesiac, dnes.tm_year, p, s);
	}

	Log("-- _main_dnes(char *, char *): end\n");

}// _main_dnes();

//---------------------------------------------------------------------
// _main_zaltar()
void _main_zaltar(char *den, char *tyzden, char *modlitba){
	short int d, t, p;
	d = atodenvt(den);
	t = atoi(tyzden);
	if((d < 0) || (d > 6) || (t < 1) || (t > 4)){
		ALERT;
		Export("Nevhodné údaje:"HTML_LINE_BREAK"\n<ul>");
		// den
		if(equals(den, STR_EMPTY))
			Export("<li>chýba údaj o dni</li>\n");
		else if(d == DEN_UNKNOWN)
			Export("<li>deň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"</li>\n", den);
		// tyzden
		if(equals(tyzden, STR_EMPTY))
			Export("<li>chýba údaj o týždni</li>\n");
		else if((t < 1) || (t > 4))
			Export("<li>týždeň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"</li>\n", tyzden);
		Export("</ul>\n");
		return;
	}
	p = atomodlitba(modlitba);
	if((p == MODL_NEURCENA) || (p < MODL_INVITATORIUM) || (p > MODL_DRUHE_KOMPLETORIUM)){
		Export("Nevhodné údaje: nie je určená modlitba (%s).\n", modlitba);
		return;
	}
	_global_modlitba = p;
	// vstupom pre showPrayer() je iba zakladny typ modlitby; zvysna informacia (ci ide o prve/druhe vespery/kompl.) sa uchova v premennej _global_modlitba
	if((p == MODL_PRVE_VESPERY) || (p == MODL_DRUHE_VESPERY)){
		p = MODL_VESPERY;
	}
	if((p == MODL_PRVE_KOMPLETORIUM) || (p == MODL_DRUHE_KOMPLETORIUM)){
		p = MODL_KOMPLETORIUM;
	}
	// ked nejde o nedelu, nema zmysel rozlisovat prve/druhe vespery/kompl.
	if(d != DEN_NEDELA){
		if(p == MODL_VESPERY){
			_global_modlitba = MODL_VESPERY;
		}
		if(p == MODL_KOMPLETORIUM){
			_global_modlitba = MODL_KOMPLETORIUM;
		}
	}// nie je to nedela

	zaltar(d, t);
	// 2003-08-13: neviem preco tu bola poznamka "unfinished - este nejde uplne spravne"

	Log("spustam showPrayer(%s)...\n", nazov_modlitby(_global_modlitba));

	// predpokladam, ze aj _global_modlitba je prve/druhe vespery, v _global_prve_vespery su spravne udaje (podobne kompletorium)
	showPrayer(p);
}// _main_zaltar()

//---------------------------------------------------------------------
// _main_liturgicke_obdobie() podľa _main_zaltar()
short int _main_liturgicke_obdobie(char *den, char *tyzden, char *modlitba, char *litobd, char *litrok){
	short int d, t, p, lo, tz, poradie_svateho = 0, ret;
	char lr;
	// char pom[MAX_STR];
	Log("_main_liturgicke_obdobie(): začiatok...\n");

	lr = litrok[0];
	lo = atolitobd(litobd);
	d = atodenvt(den);
	t = atoi(tyzden);
	tz = TYZZAL(t); // ((t + 3) MOD 4) + 1;
	Log("lr == %c, lo == %d, d == %d, t == %d, tz == %d...\n", lr, lo, d, t, tz);

	// do budúcnosti treba riešiť niektoré špeciality, napr. adv. obd. II alebo vian. obd. II (dni určené dátumom); triduum a pod.

	if(lr > 'C' || lr < 'A'){
		ALERT;
		Export("Nevhodné údaje:"HTML_LINE_BREAK"\n<ul>");
		// tyzden
		if(equals(tyzden, STR_EMPTY)){
			Export("<li>taký liturgický rok nemožno žiadať</li>\n");
		}
		else if((t < 1) || (t > 4)){
			Export("<li>týždeň = <"HTML_SPAN_BOLD">%c"HTML_SPAN_END"</li>\n", lr);
		}
		Export("</ul>\n");
		return FAILURE;
	}

	Log("nastavenie p (modlitba == %s)...\n", modlitba);
	p = atomodlitba(modlitba);
	if((p == MODL_NEURCENA) || (p < MODL_INVITATORIUM) || (p > MODL_DRUHE_KOMPLETORIUM)){
		Export("Nevhodné údaje: nie je určená modlitba (%s).\n", modlitba);
		return FAILURE;
	}

	Log("nastavenie do _global_modlitba I. ...\n");
	_global_modlitba = p;
	// vstupom pre showPrayer() je iba zakladny typ modlitby; zvysna informacia (ci ide o prve/druhe vespery/kompl.) sa uchova v premennej _global_modlitba
	if((p == MODL_PRVE_VESPERY) || (p == MODL_DRUHE_VESPERY)){
		p = MODL_VESPERY;
	}
	if((p == MODL_PRVE_KOMPLETORIUM) || (p == MODL_DRUHE_KOMPLETORIUM)){
		p = MODL_KOMPLETORIUM;
	}

	// ak je to sobota a požadujú sa vešpery alebo kompletórium, zmeň nastavenia na nedeľu, prvé vešpery resp. prvé kompletórium (2013-02-03)
	if((d == DEN_SOBOTA) && ((p == MODL_VESPERY) || (p == MODL_KOMPLETORIUM))){
		Log("ak je to sobota a požadujú sa vešpery alebo kompletórium, zmeň nastavenia na nedeľu, prvé vešpery resp. prvé kompletórium...\n");
		d = DEN_NEDELA;
		p = (p == MODL_VESPERY)? MODL_PRVE_VESPERY: MODL_PRVE_KOMPLETORIUM;
		Log("nastavenie do _global_modlitba II. ...\n");
		_global_modlitba = p;
		t += 1;
		tz = TYZZAL(t); // ((t + 3) MOD 4) + 1;
	}

	// ked nejde o nedelu, nema zmysel rozlisovat prve/druhe vespery/kompl. | ToDo: slávnosti, sviatky Pána
	if(d != DEN_NEDELA){
		if(p == MODL_VESPERY){
			Log("nastavenie do _global_modlitba III. ...\n");
			_global_modlitba = MODL_VESPERY;
		}
		if(p == MODL_KOMPLETORIUM){
			Log("nastavenie do _global_modlitba IV. ...\n");
			_global_modlitba = MODL_KOMPLETORIUM;
		}
	}// nie je to nedela

	Log("p == %d (%s); _global_modlitba == %d (%s)...\n", p, nazov_modlitby(p), _global_modlitba, nazov_modlitby(_global_modlitba));

	// kontrola, či týždeň daného liturgického obdobia neprekračuje počet týždňov daného obdobia | 2013-02-03: presunutá sem
	Log("kontrola, či týždeň daného liturgického obdobia neprekračuje počet týždňov daného obdobia...\n");
	// 2013-05-17: pre OBD_VELKONOCNE_II je týždeň 6 resp. 7, preto treba samostatne kontrolovať, ale neupravovať premennú t
	if(((lo != OBD_VELKONOCNE_II) && (lo != OBD_POSTNE_II_VELKY_TYZDEN) && (lo != OBD_VELKONOCNE_TROJDNIE) && (lo != OBD_VIANOCNE_II) && (lo != OBD_ADVENTNE_II) && (t > lit_obd_pocet_tyzdnov[lo])) 
			|| ((lo == OBD_VELKONOCNE_II) && (t - 5 > lit_obd_pocet_tyzdnov[lo]))
			|| (((lo == OBD_POSTNE_II_VELKY_TYZDEN) || (lo == OBD_VELKONOCNE_TROJDNIE)) && (t - 6 > lit_obd_pocet_tyzdnov[lo]))
			|| ((lo == OBD_VIANOCNE_II) && (t - 1 > lit_obd_pocet_tyzdnov[lo]))
			|| ((lo == OBD_ADVENTNE_II) && (t - 3 > lit_obd_pocet_tyzdnov[lo]))
		){
		ALERT;
		Export("Nevhodné údaje:"HTML_LINE_BREAK"\n<ul>");
		// tyzden
		if(equals(tyzden, STR_EMPTY)){
			Export("<li>taký týždeň nemožno žiadať</li>\n");
		}
		else{
			Export("<li>týždeň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"; taký týždeň nemožno žiadať pre dané liturgické obdobie: %s</li>\n", tyzden, nazov_obdobia_ext(lo));
		}
		Export("</ul>\n");
		return FAILURE;
	}

	// pôstne obdobie nezačína nedeľou, ale popolcovou stredou; technicky ide o 0. týždeň pôstneho obdobia
	if((d < DEN_NEDELA) || (d > DEN_SOBOTA) || ((t < 0) || ((t == 0) && ((lo != OBD_POSTNE_I) && (d < DEN_STREDA)))) || (t > POCET_NEDIEL_CEZ_ROK)){
		ALERT;
		Export("Nevhodné údaje:"HTML_LINE_BREAK"\n<ul>");
		// deň
		if(equals(den, STR_EMPTY)){
			Export("<li>chýba údaj o dni</li>\n");
		}
		else if(d == DEN_UNKNOWN){
			Export("<li>deň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END" (neznámy)</li>\n", den);
		}
		else{
			Export("<li>deň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"</li>\n", den);
		}
		// tyzden
		if(equals(tyzden, STR_EMPTY))
			Export("<li>chýba údaj o týždni</li>\n");
		else if((t < 0) || ((t == 0) && ((lo != OBD_POSTNE_I) && (d < DEN_STREDA)))){
			Export("<li>týždeň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"</li>\n", tyzden);
		}
		else{
			Export("<li>týždeň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"</li>\n", tyzden);
		}
		Export("</ul>\n");
		return FAILURE;
	}

	// 2011-01-26: nastavenie niektorých atribútov pre _global_den
	_global_den.denvt = d;
	_global_den.litobd = lo;
	_global_den.tyzzal = tz;
	_global_den.tyzden = t;
	_global_den.litrok = lr; // default: litrok  = (char)('A' + nedelny_cyklus(den, mesiac, rok));
	mystrcpy(_global_den.meno, STR_EMPTY, MENO_SVIATKU);
	// špeciálne nastavenie hodnoty smer
	Log("špeciálne nastavenie hodnoty smer... switch(%d | %s):\n", lo, nazov_obdobia_ext(lo));
	switch(lo){
		case OBD_VELKONOCNE_TROJDNIE:
			_global_den.smer = 1; // trojdnie
			_global_den.farba = LIT_FARBA_BIELA;
			break;
		case OBD_ADVENTNE_I:
			if(d == DEN_NEDELA){
				_global_den.smer = 2; // nedele adventné
			}
			else{
				_global_den.smer = 13; // všedné dni adventné
			}
			_global_den.farba = LIT_FARBA_FIALOVA;
			break;
		case OBD_ADVENTNE_II:
			if(d == DEN_NEDELA){
				_global_den.smer = 2; // nedele adventné
			}
			else{
				_global_den.smer = 9; // všedné dni od 17. do 24. decembra
			}
			_global_den.farba = LIT_FARBA_FIALOVA;
			break;
		case OBD_VELKONOCNA_OKTAVA:
			_global_den.smer = 2; // veľkonočná oktáva
			break;
		case OBD_POSTNE_I:
			if(d == DEN_NEDELA){
				_global_den.smer = 2; // nedele pôstne
			}
			else{
				if((d == DEN_STREDA) && (t == 0)){
					_global_den.smer = 2; // popolcová streda
				}
				else{
					_global_den.smer = 9; // všedné dni v pôste
				}
			}
			_global_den.farba = LIT_FARBA_FIALOVA;
			break;
		case OBD_POSTNE_II_VELKY_TYZDEN:
			_global_den.smer = 2;
			_global_den.farba = LIT_FARBA_FIALOVA;
			break;
		case OBD_VELKONOCNE_I:
			if(d == DEN_NEDELA){
				_global_den.smer = 2; // nedele veľkonočné
			}
			else{
				_global_den.smer = 13; // všedné dni veľkonočné od pondelka po veľkonočnej oktáve až do soboty pred Zoslaním Ducha Svätého včítane
			}
			_global_den.farba = LIT_FARBA_BIELA;
			break;
		case OBD_VELKONOCNE_II:
			if(d == DEN_NEDELA){
				_global_den.smer = 2; // nedele veľkonočné
			}
			else{
				_global_den.smer = 13; // všedné dni veľkonočné od pondelka po veľkonočnej oktáve až do soboty pred Zoslaním Ducha Svätého včítane
			}
			_global_den.farba = LIT_FARBA_BIELA;
			break;
		case OBD_VIANOCNE_I:
			if(d == DEN_NEDELA){
				_global_den.smer = 6; // nedele vianočné
			}
			else{
				_global_den.smer = 13; // všedné dni vianočné
			}
			_global_den.farba = LIT_FARBA_BIELA;
			break;
		case OBD_VIANOCNE_II:
			if(d == DEN_NEDELA){
				_global_den.smer = 6; // nedele vianočné
			}
			else{
				_global_den.smer = 13; // všedné dni vianočné
			}
			_global_den.farba = LIT_FARBA_BIELA;
			break;
		case OBD_OKTAVA_NARODENIA:
			_global_den.smer = 9; // vianočná oktáva
			_global_den.farba = LIT_FARBA_BIELA;
			break;
		case OBD_CEZ_ROK:
			if(d == DEN_NEDELA){
				_global_den.smer = 6; // nedele cezročné
			}
			else{
				_global_den.smer = 13; // všedné dni cezročné
			}
			_global_den.farba = LIT_FARBA_ZELENA;
			break;
		default:
			_global_den.smer = 13;
			_global_den.farba = LIT_FARBA_ZELENA;
			break;
	}// switch(lo)

	// treba nejako hack-ovať a nastaviť aj tieto: _global_den.den pre adv2 a vian1 (25, 26 atd.) | denvr pre špeciality cezročného
	liturgicke_obdobie(lo, t, d, tz, poradie_svateho);

	// 2011-01-26: skopírované podľa funkcie _rozbor_dna_s_modlitbou(); ukladá heading do stringu _global_string
	Log("2:spustam init_global_string(EXPORT_DNA_JEDEN_DEN, svaty == %d, modlitba == %s)...\n", poradie_svateho, nazov_modlitby(_global_modlitba));
	ret = init_global_string(EXPORT_DNA_JEDEN_DEN, poradie_svateho, _global_modlitba, /* aj_citanie */ NIE);

	if(ret == FAILURE){
		Log("init_global_string() returned FAILURE, so returning FAILURE...\n");
		Log("_main_liturgicke_obdobie(): koniec (%d)\n", ret);
		return ret;
	}

	Log("nastavujem _global_string_modlitba...\n");
	init_global_string_modlitba(_global_modlitba);
	Log("nastavujem _global_string_podnadpis...\n");
	init_global_string_podnadpis(_global_modlitba);
	Log("nastavujem _global_string_spol_cast...\n");
	ret_sc = init_global_string_spol_cast(((_global_modlitba == MODL_DETAILY) || (_global_modlitba == MODL_NEURCENA))? MODL_SPOL_CAST_NULL: _global_opt[OPT_3_SPOLOCNA_CAST], poradie_svateho);

	// 2013-03-11: doplnené; bolo len v rozbor_dna_s_modlitbou()
	Log("nastavujem do _global_pocet_zalmov_kompletorium počet žalmov...\n");
	_nastav_global_pocet_zalmov_kompletorium(p);
	Log("_global_pocet_zalmov_kompletorium == %d...\n", _global_pocet_zalmov_kompletorium);
	_export_heading_center(_global_string);

	Log("spustam showPrayer(%s) z funkcie _main_liturgicke_obdobie()...\n", nazov_modlitby(_global_modlitba));
	// predpokladam, ze aj _global_modlitba je prve/druhe vespery, v _global_prve_vespery su spravne udaje (podobne kompletorium)
	LOG_ciara;
	showPrayer(p);
	LOG_ciara;
	Log("...po návrate zo showPrayer(%s) vo funkcii _main_liturgicke_obdobie().\n", nazov_modlitby(_global_modlitba));

	Log("_main_liturgicke_obdobie(): koniec (%d)\n", SUCCESS);
	return SUCCESS;
}// _main_liturgicke_obdobie()

//---------------------------------------------------------------------
// _main_static_text()
short int _main_static_text(char *static_text, char *modlitba){

	short int st, ret = FAILURE;
	_struct_anchor_and_file af;
	_INIT_ANCHOR_AND_FILE(af);
	mystrcpy(_global_include_static_text.anchor, STR_EMPTY, MAX_STR_AF_ANCHOR);
	mystrcpy(_global_include_static_text.file, STR_EMPTY, MAX_STR_AF_FILE);

	short int p;

	char pom[MAX_STR];
	char pom2[MAX_STR];
	mystrcpy(pom, STR_EMPTY, MAX_STR);
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	char pom3[MAX_STR];
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);

	Log("-- _main_static_text(): začiatok\n");

	if(equals(static_text, STR_EMPTY)){
		ALERT;
		Export("Nevhodné údaje: chýba údaj o statickom texte");
		return ret;
	}
	_global_modlitba = MODL_NEURCENA;

	// rozparsovanie parametra static_text
	Log("volanie atoStaticText() z _main_static_text()...\n");
	st = atoStaticText(static_text);
	Log("st == `%s' (%d)\n", static_text, st);

	// rozparsovanie parametra modlitba
	Log("volanie atomodlitba() z _main_static_text()...\n");
	p = atomodlitba(modlitba);
	Log("p == `%s' (%d)\n", modlitba, p);
	_global_modlitba = p;

	if(st <= STATIC_TEXT_UNDEF || st > POCET_STATIC_TEXTOV){
		ALERT;
		_export_heading("Statické texty");
		Export("Nevhodný údaj: ");
		Export("chybné číslo %d (%s).\n", st, static_text);
		return ret;
	}

	// treba nastaviť premennú _global_include_static_text

	// ToDo (enhancement): use array instead of if-else for multiple texts
	if(st == STATIC_TEXT_MARIANSKE_ANTIFONY){
		_main_LOG_to_Export("STATIC_TEXT_MARIANSKE_ANTIFONY...\n");
		init_marianske_anfifony_file(_global_include_static_text);
		_global_modlitba = p = MODL_NEURCENA; // ak aj bola určená, vymažeme ju
	}
	else if(st == STATIC_TEXT_ORDINARIUM){
		_main_LOG_to_Export("STATIC_TEXT_ORDINARIUM...\n");
		init_ordinarium_file(_global_include_static_text, p);
	}

	_main_LOG_to_Export("\t_global_include_static_text: \n");
	Log_filename_anchor(_global_include_static_text);

	LOG_ciara;
	showPrayer(_global_modlitba, SHOW_TEMPLAT_STATIC_TEXT);
	LOG_ciara;

	ret = SUCCESS;

	Log("_main_static_text(): koniec (%d)\n", ret);
	return ret;
}// _main_static_text()

//---------------------------------------------------------------------
// _main_sviatok()
void _main_sviatok(char *sviatok){
	// [ToDo]
	if(equals(sviatok, STR_EMPTY)){
		ALERT;
		Export("Nevhodné údaje: chýba údaj o sviatku");
		return;
	}
	// unfinished
	Export("Chces %s? Este nejde...\n", sviatok);
}// _main_sviatok()

#define LOG  Log("analyza_roku(): "); Log

#define NewlineExport	Export(HTML_LINE_BREAK); Export

//---------------------------------------------------------------------
// _main_analyza_roku()
//
// dostane char *, najprv ho skontroluje a potom ak je vsetko v poriadku, exportuje stranku s jednotlivymi vyznacnymi dnami roka a linkami na vsetky mesiace
//
void _main_analyza_roku(char *rok){
	_struct_den_mesiac datum;
	short int i;
	short int year;
	char pom[MAX_STR];

	char pom2[MAX_STR]; // 2006-08-01: pridané kvôli transferu údajov o jazyku
	mystrcpy(pom, STR_EMPTY, MAX_STR);
	mystrcpy(pom2, STR_EMPTY, MAX_STR);
	char pom3[MAX_STR]; // 2008-08-08: pridané kvôli css
	mystrcpy(pom3, STR_EMPTY, MAX_STR);

	char action[MAX_STR];
	mystrcpy(action, STR_EMPTY, MAX_STR);

	Log("-- _main_analyza_roku(): zaciatok\n");

	year = atoi(rok);
	if(year <= 0){
		ALERT;
		_export_heading("Analýza roku");
		Export("Nevhodný údaj: ");
		if(equals(rok, STR_EMPTY)){
			Export("nezadaný rok.\n");
		}
		else if(equals(rok, STR_VALUE_ZERO)){
			Export("nepoznám rok <"HTML_SPAN_BOLD">"STR_VALUE_ZERO""HTML_SPAN_END".\n");
		}
		else{
			Export("chybné číslo (%s).\n", rok);
		}
		return;
	}

	prilep_request_options(pom2, pom3);

	sprintf(pom, (char *)html_text_Rok_x[_global_jazyk], year);
	_export_heading_center(pom);

	LOG("vchadzam do analyzuj_rok()...\n");
	analyzuj_rok(year); // výsledok dá do _global_r
	LOG("analyzuj_rok() ukoncena.\n");

	// zmenene <font color> na <span>, 2003-07-02
	Export("<"HTML_SPAN_RED">");
	Export((char *)html_text_zakladne_info[_global_jazyk]);
	Export(":"HTML_SPAN_END"\n");
	Export(HTML_LINE_BREAK);

	// jazyk
	Export("<"HTML_SPAN_BOLD_IT">");
	Export((char *)html_text_jazyk[_global_jazyk]);
	Export(":"HTML_SPAN_END"\n");
	Export((char *)nazov_jazyka[_global_jazyk]);
	Export(HTML_LINE_BREAK);

	// rítus
	Export("<"HTML_SPAN_BOLD_IT">");
	Export((char *)html_text_ritus[_global_jazyk]);
	Export(":"HTML_SPAN_END"\n");
	Export((char *)nazov_ritu(_global_ritus));
	Export(HTML_LINE_BREAK);

	// kalendár
	Export("<"HTML_SPAN_BOLD_IT">");
	Export((char *)html_text_kalendar[_global_jazyk]);
	Export(":"HTML_SPAN_END"\n");
	Export((char *)nazov_kalendara(_global_kalendar));
	Export(HTML_LINE_BREAK);

	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK, NIE);

	// 13/04/2000A.D.: pridane rozhodovanie podla _global_linky
	if(_global_linky == ANO)
		mystrcpy(pom, cfg_http_address_default[_global_jazyk], MAX_STR);
	else // _global_linky == NIE
		mystrcpy(pom, MESSAGE_FOLDER, MAX_STR);

	if(_global_jazyk != JAZYK_HU){
		// 2011-05-16: v maďarčine sa tam slovo 'rok' (év) vôbec nehodí. Ak by si ho tam chcel mať, tak by muselo byť  za číslovkou a k číslovke by bolo treba pridať ešte koncovku. (mamedv)
		NewlineExport((char *)html_text_Rok[_global_jazyk]);
	}
	else{
		Export(HTML_LINE_BREAK);
	}
	Export(" %s <"HTML_SPAN_BOLD">", _global_link);
	if(_global_r.prestupny == YES){
		Export((char *)html_text_je[_global_jazyk]);
	}
	else{
		Export((char *)html_text_nie_je[_global_jazyk]);
	}
	Export(HTML_SPAN_END" <a href=\"%s%s\">", pom, FILE_PRESTUPNY_ROK);
	Export((char *)html_text_prestupny[_global_jazyk]);
	Export("</a>.\n");

	NewlineExport("<a href=\"%s%s\">", pom, FILE_NEDELNE_PISMENO);
	if(_global_r.prestupny == YES){
		Export((char *)html_text_Nedelne_pismena[_global_jazyk]);
		Export("</a>: <"HTML_SPAN_BOLD">%c %c"HTML_SPAN_END"\n", _global_r.p1, _global_r.p2);
	}
	else{
		Export((char *)html_text_Nedelne_pismeno[_global_jazyk]);
		Export("</a>: <"HTML_SPAN_BOLD">%c"HTML_SPAN_END"\n", _global_r.p1);
	}

	datum = prva_adventna_nedela(year - 1);
	vytvor_global_link(datum.den, datum.mesiac, year - 1, LINK_DEN_MESIAC, NIE);
	// vytvor_global_link nastavi _global_link
	Export(HTML_NEW_PARAGRAPH);
	if(_global_jazyk == JAZYK_HU){
		// 2011-05-09: iné poradie vypisovaných reťazcov
		Export((char *)html_text_Od_prvej_adv_atd[_global_jazyk],
			year - 1,
			_global_link,
			'A' + nedelny_cyklus(datum.den, datum.mesiac, year - 1),
			pom,
			FILE_LITURGICKY_ROK);
	}
	else{
		Export((char *)html_text_Od_prvej_adv_atd[_global_jazyk],
			year - 1,
			_global_link,
			pom,
			FILE_LITURGICKY_ROK,
			'A' + nedelny_cyklus(datum.den, datum.mesiac, year - 1));
	}

	Export(HTML_LINE_BREAK);

	Export("\n<table>\n");
	for(i = 0; i < POCET_ALIASOV; i++){
		vytvor_global_link(_global_r._den[i].den, _global_r._den[i].mesiac, _global_r._den[i].rok, LINK_DEN_MESIAC, NIE);
		// 2008-09-09: spoločná časť výpisu presunutá vyššie
		if(i == VELKONOCNA_NEDELA){
			mystrcpy(_global_r._den[i].meno, text_VELKONOCNA_NEDELA[_global_jazyk], MENO_SVIATKU);
		}
		Export("<tr "HTML_VALIGN_MIDDLE"><td>%s</td><td>%s</td><td>(%s, ", _global_r._den[i].meno, _global_link, nazov_dna(_global_r._den[i].denvt));
		// 2011-05-11: kvôli inému poradia vypisovaných reťazcov (HU) presunuté "%d" do konštanty
		Export((char *)html_text_den_v_roku[_global_jazyk], _global_r._den[i].denvr);
		Export(")");
		if(i == PRVA_ADVENTNA_NEDELA){
			Export(", ");
			Export((char *)html_text_zacina[_global_jazyk]);
			Export(" <a href=\"%s%s\">", pom, FILE_LITURGICKY_ROK);
			Export((char *)html_text_liturgicky_rok[_global_jazyk]);
			Export("</a> <"HTML_SPAN_BOLD">%c"HTML_SPAN_END".", _global_r._den[i].litrok);
		}
		Export("\n</td></tr>\n");
	}
	Export("</table>\n");

	NewlineExport((char *)html_text_Po_Velkej_noci_atd[_global_jazyk], _global_r.tyzden_ocr_po_vn + 1, nazov_dna(DEN_NEDELA));

	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK, NIE);

	Export(HTML_NEW_PARAGRAPH);
	Export("<"HTML_SPAN_RED">");
	Export((char *)html_text_Prikazane_sviatky_v_roku[_global_jazyk], _global_link);
	Export(":"HTML_SPAN_END"\n");
	Export(HTML_LINE_BREAK);

	Export("\n<table>\n");

	// 1. januara
	vytvor_global_link(1, 1, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_JAN_01[_global_jazyk]);

	// 6. januara
	vytvor_global_link(6, 1, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_JAN_06[_global_jazyk]);

	// nanebovstúpenie pana
	vytvor_global_link(_global_r._NANEBOVSTUPENIE_PANA.den, _global_r._NANEBOVSTUPENIE_PANA.mesiac, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NANEBOVSTUPENIE_PANA[_global_jazyk]);

	// najsv. kristovho tela a krvi; odvetvené 2011-11-07
	// kedze nie je v strukture _global_r, treba ho spocitat podla zoslania ducha sv. ide vlastne o datum (cislo v roku) pre ZOSLANIE_DUCHA_SV + 11, ako je definovany TELAKRVI, vyuzijeme parameter datum na zistenie dna a mesiaca
	if((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_TELAKRVI_NEDELA) != BIT_OPT_0_TELAKRVI_NEDELA){
		datum = por_den_mesiac((ZOSLANIE_DUCHA_SV + 11), year);
		vytvor_global_link(datum.den, datum.mesiac, year, LINK_DEN_MESIAC, NIE);
		Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NAJSV_KRISTOVHO_TELA_A_KRVI[_global_jazyk]);
	}// BIT_OPT_0_TELAKRVI_NEDELA

	// 29. juna
	vytvor_global_link(29, 6, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_JUN_29[_global_jazyk]);

	// 15. augusta
	vytvor_global_link(15, 8, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_AUG_15[_global_jazyk]);

	// 1. novembra
	vytvor_global_link(1, 11, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NOV_01[_global_jazyk]);

	// 8. decembra
	vytvor_global_link(8, 12, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_DEC_08[_global_jazyk]);

	// 25. decembra
	vytvor_global_link(25, 12, year, LINK_DEN_MESIAC, NIE);
	Export("<tr "HTML_VALIGN_BASE">\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NARODENIE_PANA[_global_jazyk]);

	Export("</table>\n");

	// teraz nasleduju jednotlive mesiace roku s linkami na ne
	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK, NIE);

	Export(HTML_NEW_PARAGRAPH);
	Export("<"HTML_SPAN_RED">");
	Export((char *)html_text_Jednotlive_mesiace_roku[_global_jazyk], _global_link);
	Export(":"HTML_SPAN_END"\n");
	Export(HTML_LINE_BREAK);

#ifdef RICH_JEDNOTLIVE_MESIACE
	Export("<ul>\n");
	for(i = MES_JAN; i <= MES_DEC; i++){
		Vytvor_global_link(VSETKY_DNI, i + 1, year, LINK_DEN_MESIAC_ROK, NIE);
		Export("\n<li>%s</li>", _global_link);
	}
	Export("</ul>\n");
#else
	Export(HTML_LINE_BREAK"\n<p><center>\n");
	// teraz zoznam mesiacov -- podla casti pre analyzu dna
	for(i = 1; i <= 12; i++){
		Vytvor_global_link(VSETKY_DNI, i, year, LINK_DEN_MESIAC, NIE);
		Export("%s ", _global_link);
	}
	Export("\n</center>\n");
#endif
	if((_global_linky == ANO) && ((_global_opt[OPT_4_OFFLINE_EXPORT] & BIT_OPT_4_MESIAC_RIADOK) != BIT_OPT_4_MESIAC_RIADOK)){
		// 2005-03-22: Upravene; podmienka zosilnena (and _global_opt[OPT_1_CASTI_MODLITBY] == NIE); 2007-06-01 upravené, aby sa neriadilo opt_1, ale opt6 
		// 2011-04-13: podmienka sa riadi jedným z bitov option 4
		NewlineExport("<table "HTML_ALIGN_CENTER">\n");
		
		// predošlý rok -- button
		Export("<td "HTML_ALIGN_RIGHT">");
		sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d%s",
		// Export("<td "HTML_ALIGN_RIGHT"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU,
			STR_ANALYZA_ROKU, year - 1,
			pom2);
		Export_HtmlForm(action);
		// 2003-07-16; << zmenene na &lt;&lt; 2007-03-19: zmenené na HTML_LEFT_ARROW
		Export("<"HTML_FORM_INPUT_SUBMIT0" value=\""HTML_LEFT_ARROW" %d (", year - 1);
		Export((char *)html_button_predchadzajuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_rok[_global_jazyk]);
		Export(")\">\n");
		Export("</form></td>\n");

		// nasledujúci rok -- button
		Export("<td "HTML_ALIGN_LEFT">");
		sprintf(action, "%s?%s=%s"HTML_AMPERSAND"%s=%d%s",
		// Export("<td "HTML_ALIGN_RIGHT"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU,
			STR_ANALYZA_ROKU, year + 1,
			pom2);
		Export_HtmlForm(action);
		// 2003-07-16; >> zmenene na &gt;&gt; 2007-03-19: zmenené na HTML_RIGHT_ARROW
		Export("<"HTML_FORM_INPUT_SUBMIT0" value=\"(");
		Export((char *)html_button_nasledujuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_rok[_global_jazyk]);
		Export(") %d "HTML_RIGHT_ARROW"\">\n", year + 1);
		Export("</form></td>\n");
		Export("</form></td>\n");
		// koniec buttonov
		Export("</table>\n");
	}

	Log("-- _main_analyza_roku(): koniec\n");
}// _main_analyza_roku()

//---------------------------------------------------------------------
// _main_tabulka(); 15/03/2000A.D.
//
// dostane char *, char * (a pripadne char *); najprv ich skontroluje a potom
// ak je vsetko v poriadku, exportuje stranku s tabulkou datumov pohyblivych slaveni
// rokov FROM -- TO a pripadne linkami na vsetky slavenia (podla TABULKA_LINKY)
//
void _main_tabulka(char *rok_from, char *rok_to, char *tab_linky){
	_struct_den_mesiac datum;
	short int i;
	short int rfrom, rto, year, linky;

	Log("-- _main_tabulka(): zaciatok\n");

	rfrom = atoi(rok_from);
	rto = atoi(rok_to);
	linky = atoi(tab_linky);
	if((rfrom <= 0) || (rto <= 0) || (rfrom > rto)){
		ALERT;
		_export_heading("Analýza rokov");
		Export("Nevhodný údaj: ");
		if(equals(rok_from, STR_EMPTY))
			Export("nezadaný východzí rok.\n");
		if(equals(rok_to, STR_EMPTY))
			Export("nezadaný koncový rok.\n");
		else if((equals(rok_from, STR_VALUE_ZERO)) || (equals(rok_to, "0")))
			Export("nepoznám rok <"HTML_SPAN_BOLD">"STR_VALUE_ZERO""HTML_SPAN_END".\n");
		else
			Export("chybné číslo (%s, %s).\n", rok_from, rok_to);
		return;
	}

	_export_heading_center((char *)html_text_datumy_pohyblivych_slaveni[_global_jazyk]);

	Export("<center><table border CELLSPACING=1>\n");
	Export("<tr>\n");
	// 2008-08-15: doplnené; 2008-09-11: prepracované na jazykové mutácie
	for(short int i = 0; i <= POCET_HTML_TEXT_POHYBLIVE; i++){
		if((i == HTML_TEXT_POHYBLIVE_ZJAVENIE_PANA) && ((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_ZJAVENIE_PANA_NEDELA) != BIT_OPT_0_ZJAVENIE_PANA_NEDELA)){
			continue;
		}// nezobrazuj pre krajiny, kde NIE JE Zjavenie Pána pohyblivé
		Export("<td "HTML_ALIGN_CENTER">");
		Export((char *)html_text_pohyblive[i][_global_jazyk]);
		Export("</td>\n");
	}
	Export("<tr>\n");
	
	for(year = rfrom; year <= rto; year++){
		LOG("-- _main_tabulka(): vchadzam do analyzuj_rok()...\n");
		analyzuj_rok(year); // výsledok dá do _global_r
		LOG("-- _main_tabulka(): analyzuj_rok() ukoncena.\n");

		Export("<tr>\n");

		// rok
		Export("<td>\n");
		if(linky == ANO){
			// aj linka musi obsahovat 'prestupnost', podla toho ma farbu
			if(_global_r.prestupny == YES){
				vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK_PRESTUP, NIE);
			}
			else{
				vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK, NIE);
			}
		}
		else{
			sprintf(_global_link, "%d", year);
		}
		// 2003-07-02: kedze <font color=#ff0000> neprebil nastavenia css-ka, 
		// 1. pridal som globalnu definiciu .red { color: #ff0000; } kt. sa da menit;
		// 2. pri prestupnom roku sa voli iny parameter ().
		if(_global_r.prestupny == YES)
			Export("<"HTML_SPAN_RED">%s"HTML_SPAN_END, _global_link);
		else
			Export("%s", _global_link);
		Export("</td>\n");

		// nedeľné litery
		Export("<td "HTML_ALIGN_CENTER">\n");
		if(_global_r.prestupny == YES)
			Export("%c %c", _global_r.p1, _global_r.p2);
		else
			Export("%c", _global_r.p1);
		Export("</td>\n");
	
		// nedeľný cyklus
		Export("<td>\n");
		datum = prva_adventna_nedela(year - 1);
		i = nedelny_cyklus(datum.den, datum.mesiac, year - 1);
		Export("%c-%c", 'A' + i, 'A' + ((i + 1) MOD 3));
		Export("</td>\n");
	
		// aliasy -- význačné dni liturgického roka
		for(i = 0; i < POCET_ALIASOV; i++){
			if((i == idx_KRST_KRISTA_PANA) && (((_global_opt[OPT_0_SPECIALNE] & BIT_OPT_0_ZJAVENIE_PANA_NEDELA) == BIT_OPT_0_ZJAVENIE_PANA_NEDELA))){
				// pre krajiny, kde je Zjavenie Pána pohyblivé: pred Krstom Pána ešte dátum Zjavenia Pána
				if(linky == ANO){
					vytvor_global_link(zjavenie_pana(_global_r._den[i].rok), MES_JAN + 1, _global_r._den[i].rok, LINK_DEN_MESIAC, ANO);
				}
				else{
					strcpy(_global_link, _vytvor_string_z_datumu(zjavenie_pana(_global_r._den[i].rok), MES_JAN + 1, _global_r._den[i].rok, CASE_case, LINK_DEN_MESIAC, ANO));
				}
				Export("<td>%s</td>", _global_link);
			}
			if(i == idx_PRVA_ADVENTNA_NEDELA){
				// pred prvou adv. nedelou, po zoslani ducha sv. ide vypis, aky tyzden obdobia cez rok ide po velkej noci
				Export("<td "HTML_ALIGN_RIGHT">%d.</td>", _global_r.tyzden_ocr_po_vn);
			}
			else if(i == idx_POPOLCOVA_STREDA){
				// pred popolcovou stredou, aky tyzden obdobia cez rok ide pred pôstom
				Export("<td "HTML_ALIGN_CENTER">%d</td>", _global_r.tyzden_ocr_pred_po);
			}
			Export("<td>");
			// 2011-05-11: pôvodný export medzery pre jednociferné čísla dní presunutý do _vytvor_string_z_datumu() | if((_global_r._den[i].den < 10) && (_global_jazyk == JAZYK_SK)) Export(HTML_NONBREAKING_SPACE);
			if(linky == ANO){
				vytvor_global_link(_global_r._den[i].den, _global_r._den[i].mesiac, _global_r._den[i].rok, LINK_DEN_MESIAC, ANO);
			}
			else{
				strcpy(_global_link, _vytvor_string_z_datumu(_global_r._den[i].den, _global_r._den[i].mesiac, _global_r._den[i].rok, CASE_case, LINK_DEN_MESIAC, ANO));
				// sprintf(_global_link, "%d. %s", _global_r._den[i].den, nazov_mesiaca(_global_r._den[i].mesiac - 1));
			}
			Export("%s</td>\n", _global_link);
		}// for -- pre aliasy

		Export("</tr>\n");
	}// for
	Export("</table></center>\n");

	vysvetlivky_tabulka();

	Log("-- _main_tabulka(): koniec\n");
}// _main_tabulka()

void dumpFile(char *fname, FILE *expt){
	short int c;
	FILE *input_file = fopen(fname, "rb");
	if(input_file != NULL){
		while((c = fgetc(input_file)) != EOF)
			fputc(c, expt);
	}
}// dumpFile()

//---------------------------------------------------------------------
// _main_batch_mode(); 2003-07-04
//
// dostane vela char *; najprv ich skontroluje a potom ak je vsetko v poriadku, do export fajlu generuje command-line prikazy pre vytvorenie modlitby na jednotlive dni dane obdobim
//
// 2009-08-05: veľká úprava tejto funkcie, nový batch mód po mesiacoch
//
void _main_batch_mode(
	char *den_from, char *mesiac_from, char *rok_from, 
	char *den_to, char *mesiac_to, char *rok_to, 
	char *nieco, char *tab_linky){

	short int heading_written = 0; // je tu kvoli ExportUDAJE definovane pred _main_rozbor_dna
	Log("-- _main_batch_mode(char * -- 7x): begin (%s, %s, %s, %s, %s, %s, %s, %s)\n",
		den_from, mesiac_from, rok_from, den_to, mesiac_to, rok_to, nieco, tab_linky);
	short int d_from, m_from, r_from, d_to, m_to, r_to;
	long jd_from, jd_to;
	short int i; // 2007-06-01: doplnené kvôli presunutiu čítania opt_0...opt_4 do _rozparsuj_parametre_OPT
	short int som_dnu = NIE; // 2009-08-02: či som "cd" príkazom vnútri adresára jednotlivého mesiaca pre 'M' -- mesačný export v batch móde
	_struct_den_mesiac d_a_m;
	short int d, m, r, p, pocet_dni_v_mes;
	short int prveho_v_mesiaci = NIE;

	// rozparsovanie parametrov den, mesiac, rok
	Log("--start(from)--\n");
	// --from--
	Log("/* rozparsovanie parametrov den, mesiac, rok FROM */\n");
	d_from = atoden(den_from); // vrati VSETKY_DNI, resp. atoi(den_from)
	Log("den_from == `%s' (%d)\n", den_from, d_from);
	m_from = atomes(mesiac_from); // bude to 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC
	Log("mes_from == `%s' (%d)\n", mesiac_from, m_from);
	r_from = atoi(rok_from); // vrati 0 v pripade chyby; alebo int
	Log("rok_from == `%s' (%d)\n", rok_from, r_from);

	Log("--end(to)--\n");
	// --to--
	Log("/* rozparsovanie parametrov den, mesiac, rok TO */\n");
	d_to = atoden(den_to); // vrati VSETKY_DNI, resp. atoi(den_to)
	Log("den_to == `%s' (%d)\n", den_to, d_to);
	m_to = atomes(mesiac_to); // bude to 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC
	Log("mes_to == `%s' (%d)\n", mesiac_to, m_to);
	r_to = atoi(rok_to); // vrati 0 v pripade chyby; alebo int
	Log("rok_to == `%s' (%d)\n", rok_to, r_to);

	// option a (append), pridana 2003-07-08 - nastavi sa v getArgv();

	// 2006-12-08: neviem prečo je tu _global_modlitba = 0, asi nebola pre batch mode inicializovaná
	Log("Ruším nastavenie pre parameter _global_modlitba (doteraz == %d/%s)...\n", _global_modlitba, nazov_modlitby(_global_modlitba));
	_global_modlitba = MODL_NEURCENA;

	// kontrola udajov
	short int result = SUCCESS;

	// ExportUDAJE definovane pred _main_rozbor_dna()

	// --from--

	// deň
	if(equals(den_from, STR_EMPTY)){
		ExportUDAJE("chýba údaj o počiatočnom dni."HTML_LINE_BREAK"\n");
	}
	else if(d_from == 0){
		ExportUDAJE("deň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"."HTML_LINE_BREAK"\n", den_from);
	}
	// mesiac
	if(equals(mesiac_from, STR_EMPTY)){
		ExportUDAJE("chýba údaj o počiatočnom mesiaci."HTML_LINE_BREAK"\n");
	}
	else if(m_from == UNKNOWN_MESIAC){
		ExportUDAJE("taký mesiac nepoznám (%s)."HTML_LINE_BREAK"\n", mesiac_from);
	}
	// rok
	if(equals(rok_from, STR_EMPTY)){
		ExportUDAJE("chýba údaj o počiatočnom roku."HTML_LINE_BREAK"\n");
	}
	else if(r_from == 0){
		ExportUDAJE("rok = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"."HTML_LINE_BREAK"\n", rok_from);
	}

	// --to--

	// deň
	if(equals(den_to, STR_EMPTY)){
		ExportUDAJE("chýba údaj o koncovom dni."HTML_LINE_BREAK"\n");
	}
	else if(d_to == 0){
		ExportUDAJE("deň = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"."HTML_LINE_BREAK"\n", den_to);
	}
	// mesiac
	if(equals(mesiac_to, STR_EMPTY)){
		ExportUDAJE("chýba údaj o koncovom mesiaci."HTML_LINE_BREAK"\n");
	}
	else if(m_to == UNKNOWN_MESIAC){
		ExportUDAJE("taký mesiac nepoznám (%s)."HTML_LINE_BREAK"\n", mesiac_to);
	}
	// rok
	if(equals(rok_to, STR_EMPTY)){
		ExportUDAJE("chýba údaj o koncovom roku."HTML_LINE_BREAK"\n");
	}
	else if(r_to == 0){
		ExportUDAJE("rok = <"HTML_SPAN_BOLD">%s"HTML_SPAN_END"."HTML_LINE_BREAK"\n", rok_to);
	}

	// juliansky datum dna _from musi byt <= ako dna _to
	// mesiac (int) je 0-11! juliansky_datum() ocakava 1-12
	jd_from = JD(d_from, m_from + 1, r_from);
	jd_to = JD(d_to, m_to + 1, r_to);
	if(jd_from > jd_to){
		Log("JD_from = %ld > JD_to = %ld\n", jd_from, jd_to);
		ExportUDAJE("Zlé časové obdobie (dátum `od' (%s.%s.%s) nasleduje po dátume `do' (%s.%s.%s))."HTML_LINE_BREAK"\n", den_from, mesiac_from, rok_from, den_to, mesiac_to, rok_to);
	}// datum _to je casovo _pred_ datumom _from!
	else{
		Log("julianske datumy: v poriadku\n");
	}// datumy su v spravnom vztahu

	// 2009-08-12: tu pôvodne bolo rozparsovanie premennej pom_EXPORT_MONTHLY, nastavenej v getArgv(); presunuté inde

	// skontrolovat `name_binary_executable', ktore mame v globalnej premennej, nie je potrebne (jednoducho to napastujeme do exportu), name_batch_mode skontrolujeme v dalsom

	// udaje su skontrolovane
	if(result == FAILURE){
		Log("/* teraz result == FAILURE */\n");
		ALERT;
		return;
	}
	else{
		Log("/* teraz result == SUCCESS */\n");
		// kontrola name_batch_file - ci sa do suboru da zapisovat
		// na zapisovanie do batch_file nevyuzivame Export()
		if(strcmp(name_batch_file, STR_EMPTY) != 0){
			batch_file = fopen(name_batch_file, "wt");
			if(batch_file != NULL){
				Log("batch mode: File `%s' opened for writing... (batch_file)\n", name_batch_file);
				// teraz zacina cela sranda :)) ...
				// 2004-03-16: vystupny zoznam sa pripadne zapisuje aj ako HTML do suboru na zapisovanie do batch_html_file nevyuzivame Export()
				if(strcmp(name_batch_html_file, STR_EMPTY) == 0){
					mystrcpy(name_batch_html_file, DEFAULT_HTML_EXPORT, MAX_STR);
				}
				batch_html_file = fopen(name_batch_html_file, "wt");
				if(batch_html_file != NULL){
					Log("batch mode: File `%s' opened for writing... (batch_html_file)\n", name_batch_html_file);
					// 2011-08-02: doplnené vynulovanie
					_global_hlavicka_Export = 0;
					_global_patka_Export = 0;
					myhpage_init_globals();
					hlavicka((char *)html_title_batch_mode[_global_jazyk], batch_html_file, -1 /* t. j. bez úprav linky */, _global_opt_batch_monthly /* element <body> špeciálne */);
					// 2010-02-15: doplnené "zrýchlené voľby" 
					// 2010-12-03: opravené, nakoľko na niektorých mobilných zariadeniach JavaScript funkcie 
					if(_global_opt_batch_monthly == ANO){
						fprintf(batch_html_file, "<center><h1>%s</h1></center>\n", (char *)html_text_batch_mode_h1[_global_jazyk]);
						if((_global_jazyk == JAZYK_SK) && ((_global_kalendar != KALENDAR_NEURCENY) && (_global_kalendar != KALENDAR_VSEOBECNY) && (_global_kalendar != KALENDAR_VSEOBECNY_SK))){
							fprintf(batch_html_file, "<p "HTML_ALIGN_CENTER">%s: \n", (char *)html_text_Kalendar[_global_jazyk]);
							fprintf(batch_html_file, "<"HTML_SPAN_RED">%s"HTML_SPAN_END"\n", (char *)nazov_kalendara_long[_global_kalendar]);
							fprintf(batch_html_file, "</p>\n");
						}
						fprintf(batch_html_file, "<center><h2>%s</h2></center>\n", (char *)html_text_Breviar_dnes[_global_jazyk]);
						fprintf(batch_html_file, "<!-- SK: Odkazy na dnešný deň (Dnešné modlitby) a Prehľad mesiaca vyžadujú JavaScript. JavaScript funkcia (c) 2009 Peter Sahajda; upravil (c) 2010 Juraj Vidéky -->\n");
						fprintf(batch_html_file, "\n");
						fprintf(batch_html_file, "<script language=\"javascript\" type=\"text/javascript\">\n");
						fprintf(batch_html_file, "var dnes=new Date();\n");
						fprintf(batch_html_file, "var den=dnes.getDate();\n");
						fprintf(batch_html_file, "var mesiac_text = [\"jan\",\"feb\",\"mar\",\"apr\",\"maj\",\"jun\",\"jul\",\"aug\",\"sep\",\"okt\",\"nov\",\"dec\"]; \n");
						fprintf(batch_html_file, "var mesiac=dnes.getMonth() + 1;\n"); // mesiac je od 0 po 11
						fprintf(batch_html_file, "var mesiac_text1=mesiac_text[dnes.getMonth()];\n");
						fprintf(batch_html_file, "// var rok=dnes.getFullYear();\n");
						fprintf(batch_html_file, "var rok = dnes.getYear();\n");
						fprintf(batch_html_file, "if(rok < 2000) { rok = rok + 1900; }\n");
						fprintf(batch_html_file, "rok = rok.toString().slice(2);\n");
						fprintf(batch_html_file, "\n");
						fprintf(batch_html_file, "if(mesiac <= 9) {mesiac = '0' + mesiac;}\n");
						fprintf(batch_html_file, "if(den <= 9 ) {den = '0' + den;}\n");
						fprintf(batch_html_file, "\n");
						// 2010-12-03: cesty k súborom podľa -M3 natvrdo ukazujú na RRMM.htm (rok+mesiac, napr. 1012 pre december 2010); prípadne prerobiť, aby pre -M1 export ukazovali na index.htm...
						fprintf(batch_html_file, "var cestax = rok.toString()+mesiac.toString()+'-'+mesiac_text1+'/'+rok.toString()+''+mesiac.toString()+''+den.toString()+'.htm';\n");
						fprintf(batch_html_file, "var cesta_mesiac = rok.toString()+mesiac.toString()+'-'+mesiac_text1+'/'+rok.toString()+''+mesiac.toString()+'.htm';\n");
						fprintf(batch_html_file, "\n");
						fprintf(batch_html_file, "var tag1 = '<a href=./';\n");
						fprintf(batch_html_file, "\n");
						fprintf(batch_html_file, "var tag2 = '</a>';\n");
						fprintf(batch_html_file, "tag2+='"HTML_LINE_BREAK"';\n");
						fprintf(batch_html_file, "\n");
						fprintf(batch_html_file, "var output='';\n");
						fprintf(batch_html_file, "\n");
						if(_global_jazyk == JAZYK_HU){
							fprintf(batch_html_file, "output = output + '<ul><li> '+tag1+cestax+'>%s (20'+rok+'. '+mesiac+'. '+den+'.)'+tag2+'"HTML_LINE_BREAK"</li>';\n", (char *)html_text_Dnesne_modlitby[_global_jazyk]);
						}
						else {
							fprintf(batch_html_file, "output = output + '<ul><li> '+tag1+cestax+'>%s ('+den+'. '+mesiac+'. 20'+rok+')'+tag2+'"HTML_LINE_BREAK"</li>';\n", (char *)html_text_Dnesne_modlitby[_global_jazyk]);
						}
						fprintf(batch_html_file, "\n");
						if(_global_jazyk == JAZYK_HU){
							fprintf(batch_html_file, "output = output + '<li>'+tag1+cesta_mesiac+'>%s (20'+rok+'/'+mesiac+')'+tag2+'</li></ul>';\n", (char *)html_text_Prehlad_mesiaca[_global_jazyk]);
						}
						else {
							fprintf(batch_html_file, "output = output + '<li>'+tag1+cesta_mesiac+'>%s ('+mesiac+'/20'+rok+')'+tag2+'</li></ul>';\n", (char *)html_text_Prehlad_mesiaca[_global_jazyk]);
						}
						fprintf(batch_html_file, "\n");
						fprintf(batch_html_file, "document.write(output);\n");
						fprintf(batch_html_file, "</script>\n");
					}

					fprintf(batch_html_file, "\n");
					fprintf(batch_html_file, "<center><h2>");
					if(_global_opt_batch_monthly == ANO){
						fprintf(batch_html_file, "%s", (char *)html_text_batch_Zoznam1m[_global_jazyk]);
					}
					else{
						fprintf(batch_html_file, "%s", (char *)html_text_batch_Zoznam1[_global_jazyk]);
					}
					fprintf(batch_html_file, "</h2></center>\n");

					if(_global_opt_batch_monthly == ANO){
						fprintf(batch_html_file, "<center><h4>");
						if(_global_jazyk == JAZYK_HU){
							fprintf(batch_html_file, (const char *)html_text_batch_obdobie1m[_global_jazyk], r_from, nazov_mesiaca_gen(m_from), d_from, r_to, nazov_mesiaca_gen(m_to), d_to);
						}
						else{
							fprintf(batch_html_file, (const char *)html_text_batch_obdobie1m[_global_jazyk], d_from, nazov_mesiaca_gen(m_from), r_from, d_to, nazov_mesiaca_gen(m_to), r_to);
						}
						fprintf(batch_html_file, "</h4></center>\n");
					}
					fprintf(batch_html_file, "<ul>\n");
					LOG_ciara;
					Log("batch mode: teraz začínam prechádzať celé zadané obdobie...\n");

					// 2004-03-16: toto su uz minule poznamky o tom, ako to bude (teda je) spravene (2003-07-04)
					// 1. ak r_from < r_to:
					//    (i)   od poradie(d_from, m_from, r_from) do poradie(31, MES_DEC, r_from);
					//    (ii)  pre roky i = (r_from + 1) do (r_to - 1):
					//          od poradie(1, MES_JAN, i) do poradie(31, MES_DEC, i);
					//    (iii) pre posledny rok: od poradie(1, MES_JAN, r_to) do poradie(d_to, m_to, r_to);
					// 2. ak je to r_from == r_to, tak len
					//    pre poradie(d_from, m_from, r_from) do poradie(d_to, m_to, r_from==r_to)
					//
					// co sa tam vlastne bude robit?
					// 1. analyzuj_rok() daneho roku (r_from, i, r_to) -- ale len 1x!
					// 2. pre vsetky potrebne dni: rozbor_dna() -- ale printovat to  nie Exportom do `export.htm', ale printf(name_batch_file)!
					// 3. that's all
					//
					// popritom pri prepínači _global_opt_batch_monthly == ANO je potrebné vždy vytvoriť adresár pre daný mesiac,
					// prepnúť sa doňho a následne (pre ďalší nový mesiac) z neho vyjsť a zas vytvoriť adresár (2009-08-02)

					// 2003-07-08: _global_string vyuzijeme na to, aby sme si medzi jednotlivymi dnami posielali nazov suboru v pripade, ze chce vsetky modlitby do 1 suboru (pouzil "-a1" = append)
					if(_global_opt_append == YES){
						mystrcpy(_global_string, STR_EMPTY, MAX_GLOBAL_STR); // inicializacia
						mystrcpy(_global_string_modlitba, STR_EMPTY, SMALL);
						mystrcpy(_global_string_podnadpis, STR_EMPTY, SMALL);
						mystrcpy(_global_string_spol_cast, STR_EMPTY, SMALL);
						// 2008-11-29: rozličný export
						if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
							sprintf(_global_string, FILENAME_EXPORT_DATE_SIMPLE"_"FILENAME_EXPORT_DATE_SIMPLE, r_from % 100, m_from + 1, d_from, r_to % 100, m_to + 1, d_to);
						}
						else{ // EXPORT_DATE_FULL
							sprintf(_global_string, FILENAME_EXPORT_DATE_FULL"_"FILENAME_EXPORT_DATE_FULL, r_from, m_from + 1, d_from, r_to, m_to + 1, d_to);
						}
						// m_to resp. m_from: sú hodnoty 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC
					}

					export_month_zaciatok = ANO;
					export_month_nova_modlitba = ANO;

					Log("podľa týchto dvoch sa bude rozhodovať o type exportu...\n");
					Log("_global_opt_batch_monthly == %d\n", _global_opt_batch_monthly);
					Log("export_monthly_druh == %d\n", export_monthly_druh);

					// 2009-08-04: nový druh exportu po mesiacoch -- aby jednotlivé mesiace mali sekcie podľa modlitieb; deň je len číslo
					if((_global_opt_batch_monthly == ANO) && (export_monthly_druh >= 1)){
						Log("batch mode: iný druh exportu pre mesiace\n"); 
						if(export_monthly_druh < 2){
							Log("\tv rámci jednoho mesiaca pôjdeme v hlavnom cykle po modlitbách, nie po dňoch\n");
						}
						// iný druh exportu pre mesiace; v rámci jednoho mesiaca pôjdeme v hlavnom cykle po modlitbách, nie po dňoch
						for(r = r_from; r <= r_to; r++){
							Log("batch mode: rok %d...\n", r);
							analyzuj_rok(r);
							// m je 0--11 čiže MES_JAN až MES_DEC
							for(m = (r == r_from? m_from : MES_JAN); m <= (r == r_to? m_to : MES_DEC); m++){
								Log("batch mode: rok %d, mesiac %d [%s]...\n", r, m + 1, nazov_mesiaca_asci(m));
								// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
								if(_global_opt_append != YES){
									if(som_dnu == ANO){
										fprintf(batch_file, "cd ..\n");
										Log("cd ..\n");
										som_dnu = NIE;
									}
									if(/* r != r_from && m != m_from && */ index_pre_mesiac_otvoreny == ANO){
										fprintf(batch_month_file, "</ul>\n");
										patka(batch_month_file);
										fclose(batch_month_file);
										Log("batch mode: export pre mesiac `%d' skončený, súbor %s zatvorený.\n", m, name_batch_month_file);
										index_pre_mesiac_otvoreny = NIE;
									}
									// názov executable resp. include dir sme zmenili hneď v getArgv() (lebo budeme meniť adresár)
									if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
										sprintf(dir_name, DIRNAME_EXPORT_MONTH_SIMPLE, r % 100, m + 1, nazov_mes[m]);
									}
									else{
										// EXPORT_DATE_FULL
										sprintf(dir_name, DIRNAME_EXPORT_MONTH_FULL, r, m + 1, nazov_mesiaca_asci(m));
									}
									sprintf(system_command, "mkdir \"%s\"\n", dir_name);
									Log("mkdir \"%s\"\n", dir_name);
									// fprintf(batch_file, system_command);
									system(system_command);
									fprintf(batch_file, "cd \"%s\"\n", dir_name);
									Log("cd \"%s\"\n", dir_name);
								}// if(_global_opt_append != YES) -- nie pre append
								som_dnu = ANO;
								if(export_monthly_druh >= 2){
									Log("rozbor mesiaca pre export (%s %d)...\n", nazov_mesiaca(m), r);
									// bez ohľadu na to, čo pre tento typ exportu bolo nastavené, použije sa z mesiaca vytvorený súbor; až teraz, keď je vygenerovaný príkaz pre vytvorenie mesiaca
									if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
										sprintf(_global_export_navig_hore_month, FILENAME_EXPORT_MONTH_SIMPLE".htm", r % 100, m + 1);
									}
									else{
										// EXPORT_DATE_FULL
										sprintf(_global_export_navig_hore_month, FILENAME_EXPORT_MONTH_FULL".htm", r, m + 1);
									}
									_export_rozbor_dna_mesiaca_batch(VSETKY_DNI, m + 1, r);
									// vytvorenie názvu súboru pre mesiac
									mystrcpy(name_batch_month_file, dir_name, MAX_STR);
									strcat(name_batch_month_file, STR_PATH_SEPARATOR);
									strcat(name_batch_month_file, _global_export_navig_hore_month);
									Log("rozbor mesiaca pre export (súbor %s)...\n", name_batch_month_file);
								}// if(export_monthly_druh >= 2)
								else{
									// vytvorenie názvu súboru pre mesiac
									mystrcpy(name_batch_month_file, dir_name, MAX_STR);
									strcat(name_batch_month_file, STR_PATH_SEPARATOR);
									strcat(name_batch_month_file, _global_export_navig_hore /* DEFAULT_MONTH_EXPORT */);
									// 2009-08-03: otvorím aj súbor pre jednotlivý mesiac
									batch_month_file = fopen(name_batch_month_file, "wt");
									if(batch_month_file != NULL){
										Log("batch mode: File `%s' opened for writing... (batch_month_file/1)\n", name_batch_month_file);
										// môžeme upraviť názov tak, ako ho budeme printovať do dokumentov -- aby obsahoval STR_PATH_SEPARATOR_HTML namiesto STR_PATH_SEPARATOR
										// pre použitie vo funkcii execute_batch_command()
										mystrcpy(name_batch_month_file, dir_name, MAX_STR);
										strcat(name_batch_month_file, STR_PATH_SEPARATOR_HTML);
										strcat(name_batch_month_file, _global_export_navig_hore /* DEFAULT_MONTH_EXPORT */);
										Log("batch mode: názov súboru upravený na '%s' (súbor je už otvorený)...\n", name_batch_month_file);
										// volanie funkcie halvicka()
										// 2011-09-30: doplnené vynulovanie podľa vynulovania pred batch_html_file
										_global_hlavicka_Export = 0;
										_global_patka_Export = 0;
										myhpage_init_globals();
										hlavicka((char *)html_title_batch_mode[_global_jazyk], batch_month_file, 1);
										fprintf(batch_month_file, "\n");
										// začiatok hlavičky
										fprintf(batch_month_file, "<center><h2>");
										fprintf(batch_month_file, (char *)html_text_batch_Zoznam2[_global_jazyk], nazov_mesiaca(m), r_from);
										fprintf(batch_month_file, "</h2>");
										// ^ hore
										fprintf(batch_month_file, "<p><a href=\"..%s%s\" "HTML_CLASS_BUTTON">", STR_PATH_SEPARATOR_HTML, name_batch_html_file);
										fprintf(batch_month_file, "%s", (char *)html_text_batch_Back[_global_jazyk]);
										fprintf(batch_month_file, "</a></p>");
										// koniec hlavičky
										fprintf(batch_month_file, "</center>\n");
										// začiatok zoznamu
										fprintf(batch_month_file, "<ul>\n");
										index_pre_mesiac_otvoreny = ANO;
									}
								}// else if(export_monthly_druh >= 2)
								if(export_monthly_druh >= 2){
									// v rámci daného mesiaca ideme podľa dní, vnútri podľa modlitieb
									// d je číslo 1 až max
									d_a_m.mesiac = m + 1; // totiž _struct_den_mesiac má mesiace 1--12, zatiaľ čo m je 0--11
									pocet_dni_v_mes = pocet_dni[m];
									if(prestupny(r) && m == MES_FEB)
										pocet_dni_v_mes = 29;
									for(d = ((r == r_from && m == m_from)? d_from : 1); d <= ((r == r_to && m == m_to)? d_to : pocet_dni_v_mes); d++){
										d_a_m.den = d;
										Log("batch mode: rok %d, mesiac %d [%s], den %d...\n", r, m + 1, nazov_mesiaca_asci(m), d);
										// bez ohľadu na to, čo pre tento typ exportu bolo nastavené, použije sa zo dňa a mesiaca vytvorený súbor; až teraz, keď je vygenerovaný príkaz pre vytvorenie dňa
										if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
											sprintf(_global_export_navig_hore_day, FILENAME_EXPORT_DATE_SIMPLE".htm", r % 100, m + 1, d);
										}
										else{
											// EXPORT_DATE_FULL
											sprintf(_global_export_navig_hore_day, FILENAME_EXPORT_DATE_FULL".htm", r, m + 1, d);
										}
										_export_rozbor_dna_mesiaca_batch(d, m + 1, r);
										_rozbor_dna(d_a_m, r);
										for(p = MODL_INVITATORIUM; p <= MODL_KOMPLETORIUM; p++){
											Log("batch mode: rok %d, mesiac %d [%s], modlitba %s (%d), den %d...\n", r, m + 1, nazov_mesiaca_asci(m), nazov_modlitby(p), p, d);
											_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN, p, (r == r_from && m == m_from && d == d_from)? 1: 0);
										} // for p
									}// for d
								}// if(export_monthly_druh >= 2)
								else{
									// v rámci daného mesiaca ideme podľa modlitieb, až vnútri podľa dní
									for(p = MODL_INVITATORIUM; p <= MODL_KOMPLETORIUM; p++){
										Log("batch mode: rok %d, mesiac %d [%s], modlitba %s (%d)...\n", r, m + 1, nazov_mesiaca_asci(m), nazov_modlitby(p), p);
										export_month_nova_modlitba = ANO; // toto je potrebné kvôli zmene podmienky vo funkcii execute_batch_command()
										// d je číslo 1 až max
										d_a_m.mesiac = m + 1; // totiž _struct_den_mesiac má mesiace 1--12, zatiaľ čo m je 0--11
										pocet_dni_v_mes = pocet_dni[m];
										if(prestupny(r) && m == MES_FEB){
											pocet_dni_v_mes = 29;
										}
										for(d = ((r == r_from && m == m_from)? d_from : 1); d <= ((r == r_to && m == m_to)? d_to : pocet_dni_v_mes); d++){
											d_a_m.den = d;
											Log("batch mode: rok %d, mesiac %d [%s], modlitba %s (%d), den %d...\n", r, m + 1, nazov_mesiaca_asci(m), nazov_modlitby(p), p, d);
											_rozbor_dna(d_a_m, r);
											_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN, p, (r == r_from && m == m_from && d == d_from)? 1: 0);
										}// for d
									}
								}// else if(export_monthly_druh >= 2)
							}// for m
						}// for r
						Log("batch mode: iný druh exportu pre mesiace: koniec\n");
					}// if(_global_opt_batch_monthly == ANO && export_monthly_druh >= 1)
					else{
						Log("batch mode: klasický export 'zaradom' alebo po mesiacoch s tým, že hlavný cyklus ide po dňoch (čo deň, to riadok s odkazom na modlitby)\n");
						// klasický export 'zaradom' alebo po mesiacoch s tým, že hlavný cyklus ide po dňoch (čo deň, to riadok s odkazom na modlitby)
						// 2009-08-02: exportovanie do adresárov po mesiacoch
						if(_global_opt_batch_monthly == ANO){
							// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
							if(_global_opt_append != YES){
								// názov executable resp. include dir sme zmenili hneď v getArgv() (lebo budeme meniť adresár)
								if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
									sprintf(dir_name, DIRNAME_EXPORT_MONTH_SIMPLE, r_from % 100, m_from + 1, nazov_mes[m_from]);
								}
								else{
									// EXPORT_DATE_FULL
									sprintf(dir_name, DIRNAME_EXPORT_MONTH_FULL, r_from, m_from + 1, nazov_mesiaca_asci(m_from));
								}
								// m_to resp. m_from: sú hodnoty 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC
								Log("začínam pre adresár %s...\n", dir_name);
								sprintf(system_command, "mkdir \"%s\"\n", dir_name);
								Log("mkdir \"%s\"\n", dir_name);
								// fprintf(batch_file, system_command);
								system(system_command);
								fprintf(batch_file, "cd \"%s\"\n", dir_name);
								Log("cd \"%s\"\n", dir_name);
							}// if(_global_opt_append != YES) -- nie pre append
							som_dnu = ANO;
							// 2011-09-30: ak je začiatok obdobia prvého v mesiaci, nastavím
							if(d_from == 1){
								prveho_v_mesiaci = ANO;
							}
							// 2009-08-03: otvorím aj súbor pre jednotlivý mesiac
							mystrcpy(name_batch_month_file, dir_name, MAX_STR);
							strcat(name_batch_month_file, STR_PATH_SEPARATOR);
							strcat(name_batch_month_file, _global_export_navig_hore /* DEFAULT_MONTH_EXPORT */);
							batch_month_file = fopen(name_batch_month_file, "wt");
							if(batch_month_file != NULL){
								Log("batch mode: File `%s' opened for writing... (batch_month_file/2)\n", name_batch_month_file);
								// 2011-09-30: doplnené vynulovanie podľa vynulovania pred batch_html_file
								_global_hlavicka_Export = 0;
								_global_patka_Export = 0;
								myhpage_init_globals();
								hlavicka((char *)html_title_batch_mode[_global_jazyk], batch_month_file, 1);
								fprintf(batch_month_file, "\n");
								fprintf(batch_month_file, "<center><h2>");
								fprintf(batch_month_file, (char *)html_text_batch_Zoznam2[_global_jazyk], nazov_mesiaca(m_from), r_from);
								fprintf(batch_month_file, "</h2>");
								// ^ hore
								fprintf(batch_month_file, "<p><a href=\"..%s%s\" "HTML_CLASS_BUTTON">", STR_PATH_SEPARATOR_HTML, name_batch_html_file);
								fprintf(batch_month_file, "%s", (char *)html_text_batch_Back[_global_jazyk]);
								fprintf(batch_month_file, "</a></p>");
								// koniec hlavičky
								fprintf(batch_month_file, "</center>\n");
								// začiatok zoznamu
								fprintf(batch_month_file, "<ul>\n");
								index_pre_mesiac_otvoreny = ANO;
							}
						}
						if(r_from < r_to){
							Log("batch mode: viacero rokov (%d-%d)...\n", r_from, r_to);
							// analyzujem prvy rok (r_from). potom pre jednotlive dni az do konca roka robim: _rozbor_dna a _export_rozbor_dna_batch
							Log("rok %d...\n", r_from);
							analyzuj_rok(r_from);
							for(i = poradie(d_from, m_from + 1, r_from); i <= poradie(31, MES_DEC + 1, r_from); i++){
								Log("%d. den v roku %d...\n", i, r_from);
								// 2006-02-06: doplnenie nastavenia premenných kvôli tomu, že v batch móde používame viackrát
								_global_opt[OPT_3_SPOLOCNA_CAST] = MODL_SPOL_CAST_NEURCENA;
								d_a_m = por_den_mesiac(i, r_from);
								d = d_a_m.den;
								m = d_a_m.mesiac;
								if(_global_opt_batch_monthly == ANO && d == 1){ // ak je prvého, treba vytvoriť nový adresár
									LOG_ciara;
									Log("batch mode (viacero rokov): nový mesiac -- %s %d...\n", nazov_mesiaca(m - 1), r_from);
									// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
									if(_global_opt_append != YES){
										// 2009-08-02: exportovanie do adresárov po mesiacoch
										if(som_dnu == ANO){
											fprintf(batch_file, "cd ..\n");
											Log("cd ..\n");
											som_dnu = NIE;
										}
										// 2009-08-03: zatvorenie súboru (index.htm) pre jednotlivý mesiac
										if(index_pre_mesiac_otvoreny == ANO){
											fprintf(batch_month_file, "</ul>\n");
											patka(batch_month_file);
											fclose(batch_month_file);
											Log("batch mode: export pre predošlý mesiac skončený, súbor %s zatvorený.\n", name_batch_month_file);
											index_pre_mesiac_otvoreny = NIE;
										}
										// názov executable resp. include dir sme zmenili hneď v getArgv() (lebo budeme meniť adresár)
										if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
											sprintf(dir_name, DIRNAME_EXPORT_MONTH_SIMPLE, r_from % 100, m, nazov_mes[m - 1]);
										}
										else{
											// EXPORT_DATE_FULL
											sprintf(dir_name, DIRNAME_EXPORT_MONTH_FULL, r_from, m, nazov_mesiaca_asci(m - 1));
										}
										sprintf(system_command, "mkdir \"%s\"\n", dir_name);
										Log("mkdir \"%s\"\n", dir_name);
										// fprintf(batch_file, system_command);
										system(system_command);
										fprintf(batch_file, "cd \"%s\"\n", dir_name);
										Log("cd \"%s\"\n", dir_name);
									}// if(_global_opt_append != YES) -- nie pre append
									som_dnu = ANO;
									// 2009-08-03: otvorím aj súbor pre jednotlivý mesiac
									mystrcpy(name_batch_month_file, dir_name, MAX_STR);
									strcat(name_batch_month_file, STR_PATH_SEPARATOR);
									strcat(name_batch_month_file, _global_export_navig_hore /* DEFAULT_MONTH_EXPORT */);
									batch_month_file = fopen(name_batch_month_file, "wt");
									if(batch_month_file != NULL){
										Log("batch mode: File `%s' opened for writing... (batch_month_file/3)\n", name_batch_month_file);
										// 2011-09-30: doplnené vynulovanie podľa vynulovania pred batch_html_file
										_global_hlavicka_Export = 0;
										_global_patka_Export = 0;
										myhpage_init_globals();
										hlavicka((char *)html_title_batch_mode[_global_jazyk], batch_month_file, 1);
										fprintf(batch_month_file, "\n");
										fprintf(batch_month_file, "<center><h2>");
										fprintf(batch_month_file, (char *)html_text_batch_Zoznam2[_global_jazyk], nazov_mesiaca(m - 1), r_from);
										fprintf(batch_month_file, "</h2>");
										// ^ hore
										fprintf(batch_month_file, "<p><a href=\"..%s%s\" "HTML_CLASS_BUTTON">", STR_PATH_SEPARATOR_HTML, name_batch_html_file);
										fprintf(batch_month_file, "%s", (char *)html_text_batch_Back[_global_jazyk]);
										fprintf(batch_month_file, "</a></p>");
										// koniec hlavičky
										fprintf(batch_month_file, "</center>\n");
										// začiatok zoznamu
										fprintf(batch_month_file, "<ul>\n");
										index_pre_mesiac_otvoreny = ANO;
									}
								}// if(_global_opt_batch_monthly == ANO && d == 1)
								// 2003-07-07: _struct_den_mesiac je typ, ktory vrati _rozbor_dna();
								_rozbor_dna(d_a_m, r_from);
								_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
							}// for i
							
							// teraz pre roky (r_from + 1) az (r_to - 1) robim to, co predtym, cize analyzujem rok a pre vsetky dni - tentokrat pre cele roky, 
							// od 1.1. do 31.12. - robim _rozbor_dna a _export_rozbor_dna_batch
							for(short int y = (r_from + 1); y < r_to; y++){
								Log("rok %d...\n", y);
								analyzuj_rok(y);
								for(i = poradie(1, MES_JAN + 1, y); i <= poradie(31, MES_DEC + 1, y); i++){
									Log("%d. den v roku %d...\n", i, y);
									// 2006-02-06: doplnenie nastavenia premenných kvôli tomu, že v batch móde používame viackrát
									_global_opt[OPT_3_SPOLOCNA_CAST] = MODL_SPOL_CAST_NEURCENA;
									d_a_m = por_den_mesiac(i, y);
									d = d_a_m.den;
									m = d_a_m.mesiac;
									if(_global_opt_batch_monthly == ANO && d == 1){ // ak je prvého, treba vytvoriť nový adresár
										LOG_ciara;
										Log("batch mode (vnútorné celé roky): nový mesiac -- %s %d...\n", nazov_mesiaca(m - 1), y);
										// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
										if(_global_opt_append != YES){
											// 2009-08-02: exportovanie do adresárov po mesiacoch
											if(som_dnu == ANO){
												fprintf(batch_file, "cd ..\n");
												Log("cd ..\n");
												som_dnu = NIE;
											}
											// 2009-08-03: zatvorenie súboru (index.htm) pre jednotlivý mesiac
											if(index_pre_mesiac_otvoreny == ANO){
												fprintf(batch_month_file, "</ul>\n");
												patka(batch_month_file);
												fclose(batch_month_file);
												Log("batch mode: export pre predošlý mesiac skončený, súbor %s zatvorený.\n", name_batch_month_file);
												index_pre_mesiac_otvoreny = NIE;
											}
											// názov executable resp. include dir sme zmenili hneď v getArgv() (lebo budeme meniť adresár)
											if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
												sprintf(dir_name, DIRNAME_EXPORT_MONTH_SIMPLE, y % 100, m, nazov_mes[m - 1]);
											}
											else{
												// EXPORT_DATE_FULL
												sprintf(dir_name, DIRNAME_EXPORT_MONTH_FULL, y, m, nazov_mesiaca_asci(m - 1));
											}
											sprintf(system_command, "mkdir \"%s\"\n", dir_name);
											Log("mkdir \"%s\"\n", dir_name);
											// fprintf(batch_file, system_command);
											system(system_command);
											fprintf(batch_file, "cd \"%s\"\n", dir_name);
											Log("cd \"%s\"\n", dir_name);
										}// if(_global_opt_append != YES) -- nie pre append
										som_dnu = ANO;
										// 2009-08-03: otvorím aj súbor pre jednotlivý mesiac
										mystrcpy(name_batch_month_file, dir_name, MAX_STR);
										strcat(name_batch_month_file, STR_PATH_SEPARATOR);
										strcat(name_batch_month_file, _global_export_navig_hore /* DEFAULT_MONTH_EXPORT */);
										batch_month_file = fopen(name_batch_month_file, "wt");
										if(batch_month_file != NULL){
											Log("batch mode: File `%s' opened for writing... (batch_month_file/4)\n", name_batch_month_file);
											// 2011-09-30: doplnené vynulovanie podľa vynulovania pred batch_html_file
											_global_hlavicka_Export = 0;
											_global_patka_Export = 0;
											myhpage_init_globals();
											hlavicka((char *)html_title_batch_mode[_global_jazyk], batch_month_file, 1);
											fprintf(batch_month_file, "\n");
											fprintf(batch_month_file, "<center><h2>");
											fprintf(batch_month_file, (char *)html_text_batch_Zoznam2[_global_jazyk], nazov_mesiaca(m - 1), y);
											fprintf(batch_month_file, "</h2>");
											// ^ hore
											fprintf(batch_month_file, "<p><a href=\"..%s%s\" "HTML_CLASS_BUTTON">", STR_PATH_SEPARATOR_HTML, name_batch_html_file);
											fprintf(batch_month_file, "%s", (char *)html_text_batch_Back[_global_jazyk]);
											fprintf(batch_month_file, "</a></p>");
											// koniec hlavičky
											fprintf(batch_month_file, "</center>\n");
											// začiatok zoznamu
											fprintf(batch_month_file, "<ul>\n");
											index_pre_mesiac_otvoreny = ANO;
										}
									}
									_rozbor_dna(d_a_m, y);
									_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
								}// for i
								Log("...(rok %d) skoncil.\n", y);
							}// for y

							// napokon analyzujem posledny rok (r_to). pre jednotlive dni az do dna (d_to, m_to) robim: _rozbor_dna a _export_rozbor_dna_batch
							Log("rok %d...\n", r_to);
							analyzuj_rok(r_to);
							for(i = poradie(1, MES_JAN + 1, r_to); i <= poradie(d_to, m_to + 1, r_to); i++){
								Log("%d. den v roku %d...\n", i, r_to);
								// 2006-02-06: doplnenie nastavenia premenných kvôli tomu, že v batch móde používame viackrát
								_global_opt[OPT_3_SPOLOCNA_CAST] = MODL_SPOL_CAST_NEURCENA;
								d_a_m = por_den_mesiac(i, r_to);
								d = d_a_m.den;
								m = d_a_m.mesiac;
								if(_global_opt_batch_monthly == ANO && d == 1){ // ak je prvého, treba vytvoriť nový adresár
									LOG_ciara;
									Log("batch mode (od začiatku roka): nový mesiac -- %s %d...\n", nazov_mesiaca(m - 1), r_to);
									// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
									if(_global_opt_append != YES){
										// 2009-08-02: exportovanie do adresárov po mesiacoch
										if(som_dnu == ANO){
											fprintf(batch_file, "cd ..\n");
											Log("cd ..\n");
											som_dnu = NIE;
										}
										// 2009-08-03: zatvorenie súboru (index.htm) pre jednotlivý mesiac
										if(index_pre_mesiac_otvoreny == ANO){
											fprintf(batch_month_file, "</ul>\n");
											patka(batch_month_file);
											fclose(batch_month_file);
											Log("batch mode: export pre predošlý mesiac skončený, súbor %s zatvorený.\n", name_batch_month_file);
											index_pre_mesiac_otvoreny = NIE;
										}
										// názov executable resp. include dir sme zmenili hneď v getArgv() (lebo budeme meniť adresár)
										if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
											sprintf(dir_name, DIRNAME_EXPORT_MONTH_SIMPLE, r_to % 100, m, nazov_mes[m - 1]);
										}
										else{
											// EXPORT_DATE_FULL
											sprintf(dir_name, DIRNAME_EXPORT_MONTH_FULL, r_to, m, nazov_mesiaca_asci(m - 1));
										}
										sprintf(system_command, "mkdir \"%s\"\n", dir_name);
										Log("mkdir \"%s\"\n", dir_name);
										// fprintf(batch_file, system_command);
										system(system_command);
										fprintf(batch_file, "cd \"%s\"\n", dir_name);
										Log("cd \"%s\"\n", dir_name);
									}// if(_global_opt_append != YES) -- nie pre append
									som_dnu = ANO;
									// 2009-08-03: otvorím aj súbor pre jednotlivý mesiac
									mystrcpy(name_batch_month_file, dir_name, MAX_STR);
									strcat(name_batch_month_file, STR_PATH_SEPARATOR);
									strcat(name_batch_month_file, DEFAULT_MONTH_EXPORT);
									batch_month_file = fopen(name_batch_month_file, "wt");
									if(batch_month_file != NULL){
										Log("batch mode: File `%s' opened for writing... (batch_month_file/5)\n", name_batch_month_file);
										// 2011-09-30: doplnené vynulovanie podľa vynulovania pred batch_html_file
										_global_hlavicka_Export = 0;
										_global_patka_Export = 0;
										myhpage_init_globals();
										hlavicka((char *)html_title_batch_mode[_global_jazyk], batch_month_file, 1);
										fprintf(batch_month_file, "\n");
										fprintf(batch_month_file, "<center><h2>");
										fprintf(batch_month_file, (char *)html_text_batch_Zoznam2[_global_jazyk], nazov_mesiaca(m - 1), r_to);
										fprintf(batch_month_file, "</h2>");
										// ^ hore
										fprintf(batch_month_file, "<p><a href=\"..%s%s\" "HTML_CLASS_BUTTON">", STR_PATH_SEPARATOR_HTML, name_batch_html_file);
										fprintf(batch_month_file, "%s", (char *)html_text_batch_Back[_global_jazyk]);
										fprintf(batch_month_file, "</a></p>");
										// koniec hlavičky
										fprintf(batch_month_file, "</center>\n");
										// začiatok zoznamu
										fprintf(batch_month_file, "<ul>\n");
										index_pre_mesiac_otvoreny = ANO;
									}
								}
								_rozbor_dna(d_a_m, r_to);
								_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
							}// for i
						}// r_from < r_to -- viacero rokov
						else{
							Log("batch mode: v rámci jedného roka (%d)...\n", r_from);
							// analyzujem ten jeden rok. potom pre jednotlive dni robim: _rozbor_dna a _export_rozbor_dna_batch
							analyzuj_rok(r_from);
							for(i = poradie(d_from, m_from + 1, r_from); i <= poradie(d_to, m_to + 1, r_to); i++){
								Log("%d. den v roku %d...\n", i, r_from);
								// 2006-02-06: doplnenie nastavenia premenných kvôli tomu, že v batch móde používame viackrát
								_global_opt[OPT_3_SPOLOCNA_CAST] = MODL_SPOL_CAST_NEURCENA;
								d_a_m = por_den_mesiac(i, r_from);
								d = d_a_m.den;
								m = d_a_m.mesiac;
								if(_global_opt_batch_monthly == ANO && d == 1 && prveho_v_mesiaci == NIE){ // ak je prvého, treba vytvoriť nový adresár; 2011-09-30: nevytvárame vtedy, ak už bol vyššie vytvorený
									LOG_ciara;
									Log("batch mode (v rámci jedného roka): nový mesiac -- %s %d...\n", nazov_mesiaca(m - 1), r_from /* == r_to */);
									// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
									if(_global_opt_append != YES){
										// 2009-08-02: exportovanie do adresárov po mesiacoch
										if(som_dnu == ANO){
											fprintf(batch_file, "cd ..\n");
											Log("cd ..\n");
											som_dnu = NIE;
										}
										// 2009-08-03: zatvorenie súboru (index.htm) pre jednotlivý mesiac
										if(index_pre_mesiac_otvoreny == ANO){
											fprintf(batch_month_file, "</ul>\n");
											patka(batch_month_file);
											fclose(batch_month_file);
											Log("batch mode: export pre predošlý mesiac skončený, súbor %s zatvorený.\n", name_batch_month_file);
											index_pre_mesiac_otvoreny = NIE;
										}
										// názov executable resp. include dir sme zmenili hneď v getArgv() (lebo budeme meniť adresár)
										if(_global_opt_export_date_format == EXPORT_DATE_SIMPLE){
											sprintf(dir_name, DIRNAME_EXPORT_MONTH_SIMPLE, r_from % 100, m, nazov_mes[m - 1]);
										}
										else{
											// EXPORT_DATE_FULL
											sprintf(dir_name, DIRNAME_EXPORT_MONTH_FULL, r_from, m, nazov_mesiaca_asci(m - 1));
										}
										sprintf(system_command, "mkdir \"%s\"\n", dir_name);
										Log("mkdir \"%s\"\n", dir_name);
										// fprintf(batch_file, system_command);
										system(system_command);
										fprintf(batch_file, "cd \"%s\"\n", dir_name);
										Log("cd \"%s\"\n", dir_name);
									}// if(_global_opt_append != YES) -- nie pre append
									som_dnu = ANO;
									// 2009-08-03: otvorím aj súbor pre jednotlivý mesiac
									mystrcpy(name_batch_month_file, dir_name, MAX_STR);
									strcat(name_batch_month_file, STR_PATH_SEPARATOR);
									strcat(name_batch_month_file, _global_export_navig_hore /* DEFAULT_MONTH_EXPORT */);
									batch_month_file = fopen(name_batch_month_file, "wt");
									if(batch_month_file != NULL){
										Log("batch mode: File `%s' opened for writing... (batch_month_file/6)\n", name_batch_month_file);
										// 2011-09-30: doplnené vynulovanie podľa vynulovania pred batch_html_file
										_global_hlavicka_Export = 0;
										_global_patka_Export = 0;
										myhpage_init_globals();
										hlavicka((char *)html_title_batch_mode[_global_jazyk], batch_month_file, 1);
										fprintf(batch_month_file, "\n");
										fprintf(batch_month_file, "<center><h2>");
										fprintf(batch_month_file, (char *)html_text_batch_Zoznam2[_global_jazyk], nazov_mesiaca(m - 1), r_from);
										fprintf(batch_month_file, "</h2>");
										// ^ hore
										fprintf(batch_month_file, "<p><a href=\"..%s%s\" "HTML_CLASS_BUTTON">", STR_PATH_SEPARATOR_HTML, name_batch_html_file);
										fprintf(batch_month_file, "%s", (char *)html_text_batch_Back[_global_jazyk]);
										fprintf(batch_month_file, "</a></p>");
										// koniec hlavičky
										fprintf(batch_month_file, "</center>\n");
										// začiatok zoznamu
										fprintf(batch_month_file, "<ul>\n");
										index_pre_mesiac_otvoreny = ANO;
									}
								}// _global_opt_batch_monthly == ANO && d == 1 && prveho_v_mesiaci == NIE
								prveho_v_mesiaci = NIE;
								_rozbor_dna(d_a_m, r_from);
								_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
							}// for i
						}// r_from == r_to
					}// else if(_global_opt_batch_monthly == ANO && export_monthly_druh >= 1)
					if(_global_opt_batch_monthly == ANO){
						// 2009-08-03: zatvorenie súboru (index.htm) pre jednotlivý mesiac
						if(index_pre_mesiac_otvoreny == ANO){
							fprintf(batch_month_file, "</ul>\n");
							patka(batch_month_file);
							fclose(batch_month_file);
							Log("batch mode: export pre posledný mesiac skončený, súbor zatvorený; toto bol posledný súbor %s.\n", _global_export_navig_hore /* DEFAULT_MONTH_EXPORT */);
							index_pre_mesiac_otvoreny = NIE;
						}
						// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
						if(_global_opt_append != YES){
							// 2009-08-02: exportovanie do adresárov po mesiacoch -- vrátime sa späť
							if(som_dnu == ANO){
								fprintf(batch_file, "cd ..\n");
								Log("cd ..\n");
								som_dnu = NIE;
							}
						}// if(_global_opt_append != YES) -- nie pre append
					}// if(_global_opt_batch_monthly == ANO)
					// koniec zoznamu
					fprintf(batch_html_file, "</ul>\n");
					// prilepenie pätky
					patka(batch_html_file);
					// zatvorenie súboru
					fclose(batch_html_file);
					Log("batch mode: ...celé zadané obdobie je spracované; súbor %s zatvorený.\n", name_batch_html_file);
					LOG_ciara;
				}// batch_html_file != NULL
				else{
					Export("Nemôžem písať do súboru `%s'.\n", name_batch_html_file);
					Log("batch mode: Cannot open file `%s' for writing.\n", name_batch_html_file);
				}// batch_html_file == NULL)
				// ...a sranda skoncila
				fclose(batch_file);
			}// ok, batch_file != NULL
			else{
				Export("Nemôžem písať do súboru `%s'.\n", name_batch_file);
				Log("Cannot open file `%s' for writing.\n", name_batch_file);
			}// batch_file == NULL
		}// name_batch_file != STR_EMPTY
		else{
			Export("Nezadané meno batch súboru (použite parameter `%s').\n", STR_PRM_BATCH_MODE);
			Log("Batch filename empty (use `%s' parameter).\n", STR_PRM_BATCH_MODE);
		}
	}// result == SUCCESS
}// _main_batch_mode()

//---------------------------------------------------------------------
// debugovacia funkcia vypisujuca systemove premenne WWW_ a query v linuxe treba definovat extern char **environ;

#ifdef OS_linux
extern char **environ;
#endif
void write(void){
	short int i = 0;
	while (environ[i]){
//		if(strstr(environ[i], "WWW_") != NULL)
			Log("<p>%d: %s"HTML_LINE_BREAK"__________"HTML_LINE_BREAK"\n", i, environ[i]);
		i++;
	}
}

//---------------------------------------------------------------------
// popis: zisti, ktory z parametrov je pouzity; ostatne sa zisti z WWW_...
// vracia: on error, returns PRM_NONE or PRM_UNKNOWN
//         on success, returns PRM_DATUM, PRM_SVIATOK or PRM_CEZ_ROK | (09/02/2000A.D.: pridane PRM_DETAILY) | 2011-01-25: pridane PRM_LIT_OBD
// return values #define'd in mydefs.h
short int getQueryTypeFrom_QS(char *qs){
	Log("getQueryTypeFrom_QS() -- begin\n");
	Log("  qs == %s\n", qs);

	if(strstr(qs, STR_PRM_DATUM) != NULL){
		// parameter STR_PRM_DATUM
		Log("getQueryTypeFrom_QS() -- end, returning PRM_DATUM\n");
		return PRM_DATUM;
	}
	else if(strstr(qs, STR_PRM_DETAILY) != NULL){
		// parameter STR_PRM_DETAILY
		Log("getQueryTypeFrom_QS() -- end, returning PRM_DETAILY\n");
		return PRM_DETAILY; // pridane kvoli formularu 'Detaily...'
	}
	else if(strstr(qs, STR_PRM_CEZ_ROK) != NULL){
		// parameter STR_PRM_CEZ_ROK
		Log("getQueryTypeFrom_QS() -- end, returning PRM_CEZ_ROK\n");
		return PRM_CEZ_ROK;
	}
	else if(strstr(qs, STR_PRM_LIT_OBD) != NULL){
		// parameter STR_PRM_LIT_OBD
		Log("getQueryTypeFrom_QS() -- end, returning PRM_LIT_OBD\n");
		return PRM_LIT_OBD;
	}
	else if(strstr(qs, STR_PRM_SVIATOK) != NULL){
		// parameter STR_PRM_SVIATOK
		Log("getQueryTypeFrom_QS() -- end, returning PRM_SVIATOK\n");
		return PRM_SVIATOK;
	}
	else if(strstr(qs, STR_PRM_ANALYZA_ROKU) != NULL){
		// parameter STR_PRM_ANALYZA_ROKU
		Log("getQueryTypeFrom_QS() -- end, returning PRM_ANALYZA_ROKU\n");
		return PRM_ANALYZA_ROKU;
	}
	else if(strstr(qs, STR_PRM_DNES) != NULL){
		// parameter STR_PRM_DNES
		Log("getQueryTypeFrom_QS() -- end, returning PRM_DNES\n");
		return PRM_DNES;
	}
	else if(strstr(qs, STR_PRM_MESIAC_ROKA) != NULL){
		// parameter STR_PRM_MESIAC_ROKA
		Log("getQueryTypeFrom_QS() -- end, returning PRM_MESIAC_ROKA\n");
		return PRM_MESIAC_ROKA;
	}
	else if(strstr(qs, STR_PRM_TABULKA) != NULL){
		// parameter STR_PRM_TABULKA
		Log("getQueryTypeFrom_QS() -- end, returning PRM_TABULKA\n");
		return PRM_TABULKA;
	}
	else if(strstr(qs, STR_PRM_BATCH_MODE) != NULL){
		// parameter STR_PRM_BATCH_MODE
		Log("getQueryTypeFrom_QS() -- end, returning PRM_BATCH_MODE\n");
		return PRM_BATCH_MODE;
	}
	else{
		Log("getQueryTypeFrom_QS() -- end, returning PRM_UNKNOWN\n");
		return PRM_UNKNOWN; // argumenty neobsahuju STR_PRM_...
	}
}// getQueryTypeFrom_QS()

//---------------------------------------------------------------------
short int getQueryTypeFrom_WWW(void){
	// 2011-01-25: doplnené PRM_LIT_OBD
	char *ptr;
	short int ret;

	Log("getQueryTypeFrom_WWW() -- begin\n");
	ptr = getenv(ADD_WWW_PREFIX_(STR_QUERY_TYPE)); // zistim, ci je to z formulara

	if(ptr == NULL){
		// nie, dotaz nie je spusteny z formulara
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_NONE\n");
		ret = PRM_NONE; // aj bez parametrov WWW_...
	}
	// v tomto pripade existuje premenna WWW_QUERY_TYPE
	else if(equals(ptr, STR_PRM_DATUM)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DATUM\n");
		ret = PRM_DATUM;
	}
	// toto tu nemusi byt, lebo PRM_DETAILY sa pouziva len pre tlacidlo 'Detaily...', aby sa dalo odlisit od uvodneho formulara 
	// -- kedysi sa tam miesala modlitba (pole WWW_MODLITBA) z option 'PRM_CEZ_ROK', ktora sa aplikovala aj na option 'PRM_DATUM'
	else if(equals(ptr, STR_PRM_DETAILY)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DETAILY\n");
		ret = PRM_DETAILY;
	}
	else if(equals(ptr, STR_PRM_CEZ_ROK)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_CEZ_ROK\n");
		ret = PRM_CEZ_ROK;
	}
	else if(equals(ptr, STR_PRM_LIT_OBD)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_LIT_OBD\n");
		ret = PRM_LIT_OBD;
	}
	else if(equals(ptr, STR_PRM_SVIATOK)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_SVIATOK\n");
		ret = PRM_SVIATOK;
	}
	else if(equals(ptr, STR_PRM_ANALYZA_ROKU)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_ANALYZA_ROKU\n");
		ret = PRM_ANALYZA_ROKU;
	}
	else if(equals(ptr, STR_PRM_DNES)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DNES\n");
		ret = PRM_DNES;
	}
	else if(equals(ptr, STR_PRM_MESIAC_ROKA)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_MESIAC_ROKA\n");
		ret = PRM_MESIAC_ROKA;
	}
	else if(equals(ptr, STR_PRM_TABULKA)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_TABULKA\n");
		ret = PRM_TABULKA;
	}
	// nie je tu PRM_BATCH_MODE, pretoze batch mode nie je urceny pre web, 2003-07-04
	else{
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_UNKNOWN\n");
		ret = PRM_UNKNOWN; // failure
	}
	return ret;
}// getQueryTypeFrom_WWW();

//---------------------------------------------------------------------
// popis: naplni premenne pom_... hodnotami, ktore boli dodane ako sucast argumentu
//        napriklad "-q PRM_DATUM -1 7 -2 5 -3 1976" vrati query_type == PRM_DATUM; pom_DEN == 7; pom_MESIAC == 5; pom_ROK == 1976
// vracia: on success, returns SUCCESS
//         on error,   returns FAILURE
// popritom: nastavi do query_type to, co by malo byt po switchi -q
short int getArgv(int argc, char **argv){
	short int c;
	optind = 0; // pokial tu toto nebolo, tak getopt sa neinicializovala pri dalsich volaniach
	// short int digit_optind = 0;
	char *option_string;
	// short int this_option_optind;
	char pom_name_binary_executable[MAX_STR] = STR_EMPTY; // 2009-08-02: doplnené pre prilepenie ..\ pred názov name_binary_executable
	char pom_include_dir[MAX_STR] = STR_EMPTY; // 2009-08-02: doplnené pre prilepenie ..\ pred názov include_dir

	Log("allocating memory for option_string...\n");
	// allocate memory for string
	if((option_string = (char *) malloc(MAX_STR)) == NULL){
		Log("Not enough memory to allocate buffer, so returning FAILURE\n");
		//printf("Not enough memory to allocate buffer (getArgv(), char *option_string)\n");
		// exit(1); -- terminate program if out of memory
		return FAILURE;
	}

	// option_string obsahuje options (case sensitive)
	// 24/02/2000A.D.: odstranil som `e' switch -- sposoboval problemy;
	// pismeno `s' je pouzite na debuggovacie ucely pre zadanie uplneho query stringu;
	// 13/03/2000A.D.: znova som pridal `e' switch; tentokrat uz prirobene closeExport() a initExport(char*) v myexpt.[h|cpp]
	// 15/03/2000A.D.: pridal som parametre
	//  `f' (rok from), `g' (rok to), `l' (hyperlinky) pre -qptab
	// 05/06/2000A.D.: pridany parameter `i' (include directory)
	// 2003-07-04: pridane nasledovne parametre:
	//            `n' (name of binary executable) -> name_binary_executable
	//            `b' (name of generated batch file, analogia exportu, `e') -> name_batch_file
	// 2003-07-08: pridany nasledovny parameter:
	//            `a' (append) aby pri exportovani do suboru (-e) appendoval, nie prepisal subor
	// 2004-03-16: pridany nasledovny parameter:
	//            `k' (hyperteKst) aby pri exportovani v batch mode pisal do HTML suboru zoznam modlitieb
	// 2010-08-04: význam parametra `k' zmenený; pre pôvodný význam sa používa `o' (Output)
	// 2006-07-12: pridaný nasledovný parameter:
	//            `j' (Jazyk) jazyková mutácia, zatiaľ sk, cz
	// 2008-08-08: pridaný nasledovný parameter:
	//            `c' (css) použité css
	// 2008-11-29: pridaný nasledovný parameter:
	//            `u' (dátUm) spôsob zapisovania dátumu pre súbory v batch móde
	// 2009-08-02: pridaný nasledovný parameter:
	//            `M' (Monthly) spôsob zapisovania v batch móde do adresárov po mesiacoch
	// 2010-08-04: pridaný nasledovný parameter:
	//            `k' (Kalendár) špecifikácia prípadného lokálneho (rehoľného) kalendára, súvisí s parametrom 'j' (jazyk)
	// 2010-11-29: pridané nasledovné parametre:
	//            `H' (header) špeciálne správanie pre 2. až predposledný súbor generovaný append režimom (-a1): includovanie hlavičky
	//            `F' (footer) špeciálne správanie pre 2. až predposledný súbor generovaný append režimom (-a1): includovanie pätky
	// 2011-04-13: upravené (pridaná option 0 a odstránené od čísla 5 až po 9)
	// 2011-05-06: upravené (hodnota `F' ani `H' sa nepoužívali)
	//            `F' (font): možnosť zvoliť font pre override CSS
	// 2012-09-07: 'H' (header) disables header and footer
	mystrcpy(option_string, "?q::d::m::r::p::x::s::t::0::1::2::3::4::a::h::e::f::g::l::i::\?::b::n::o::k::j::c::u::M::I::H::F::S::", MAX_STR);
	// tie options, ktore maju za sebou : maju povinny argument; ak maju :: tak maju volitelny

	Log("-- getArgv(): begin\n");
	DEBUG_GET_ARGV("argc == %d\n", argc);

	if(argc == 1){
		// bud nie su zadane ziadne hodnoty alebo cerpam z premennych WWW_
		// sem sa to nemalo dostat, pretoze najprv sme pouzili get_query_type()

		// keby sa to sem vsak predsalen dostalo, dame sem nasledujucu pasaz, aby sme mohli exportovat, pretoze pred pouzitim getArgv nie je otvoreny fajl FILE_EXPORT
		DEBUG_GET_ARGV("Nezadane ziadne argumenty (argc == 1).\n");
		ALERT;
		Export("Obslužnému programu neboli zadané žiadne argumenty.\n");
		Export("<p>getArgv();\n");
		return FAILURE; // nie su argumenty
	}
	else{
		Log("option_string == %s\n", option_string);
		for(c = 0; c < argc; c++)
			Log("argv[%d] == %s\n", c, argv[c]);
		// hodnoty su v dialogovom riadku
		// zistujeme ich cez standardne mygetopt.c
		while(1){
			// this_option_optind = optind ? optind : 1;
			c = getopt(argc, argv, option_string);
			if (c == -1) // uz nie je option, vyskoc z while(1)
				break;
			switch (c){ // podla option urob nieco
				case 'c': // parameter pridaný 2008-08-08, ovplyvňuje použité css-ko; bude v _global_css
					if(optarg != NULL){
						mystrcpy(pom_CSS, optarg, SMALL);
					}
					Log("option %c with value `%s' -- `%s' used for css\n", c, optarg, optarg); break;

				case 'j': // 2006-07-11: Pridané kvôli jazykovým mutáciám
					if(optarg != NULL){
						mystrcpy(pom_JAZYK, optarg, SMALL);
					}
					Log("option %c with value `%s' -- `%s' used for language mutation\n", c, optarg, optarg); break;
				case 'k': // 2010-08-04: Pridané kvôli jazykovým mutáciám -- kalendár (rehoľný, lokálny)
					if(optarg != NULL){
						mystrcpy(pom_KALENDAR, optarg, SMALL);
					}
					Log("option %c with value `%s' -- `%s' used for calendar mutation\n", c, optarg, optarg); break;
				case 'o': // pridane 2004-03-16, name_batch_html_file; 2010-08-04: upravené 'k' -> 'o'
					if(optarg != NULL){
						mystrcpy(name_batch_html_file, optarg, SMALL);
					}
					Log("option %c with value `%s' -- batch file HTML name `%s' used for batch mode\n", c, optarg, optarg); break;
				case 'b': // pridane 2003-07-04, name_batch_file
					if(optarg != NULL){
						mystrcpy(name_batch_file, optarg, SMALL);
					}
					Log("option %c with value `%s' -- batch file name `%s' used for batch mode\n", c, optarg, optarg); break;
				case 'n': // pridane 2003-07-04, name_binary_executable
					if(optarg != NULL){
						mystrcpy(name_binary_executable, optarg, SMALL);
					}
					Log("option %c with value `%s' -- binary executable name `%s' used for batch mode\n", c, optarg, optarg); break;
				case 'i': // pridane 05/06/2000A.D., include_dir
					if(optarg != NULL){
						mystrcpy(include_dir, optarg, MAX_STR); // 2012-09-08: This string can be quite long on iOS
					}
					Log("option %c with value `%s' -- including files from `%s'\n", c, optarg, optarg /* 2004-03-17 zapoznamkovane FILE_PATH */); break;
				case 'f': // tabulka - rok from; pre batch mode je to DEN DO
					if(optarg != NULL){
						mystrcpy(pom_ROK_FROM, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'F': // font, pridané 2011-05-06
					if(optarg != NULL){
						mystrcpy(pom_FONT, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'S': // font size, pridané 2011-05-13
					if(optarg != NULL){
						mystrcpy(pom_FONT_SIZE, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'g': // tabulka - rok to; pre batch mode je to MESIAC DO
					if(optarg != NULL){
						mystrcpy(pom_ROK_TO, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'l': // tabulka - [hyper]linky
					if(optarg != NULL){
						mystrcpy(pom_LINKY, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'e': // export filename
					if(optarg != NULL){
						mystrcpy(file_export, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				// zmenene: povodne tu boli pri kazdom parametri aj '1' -- '5'; teraz: vyhodene case '1' -- '5', ktorezto '1' -- '4' su pre options, vid dalej
				case 's': // debuggovanie, query string
					if(optarg != NULL){
						Log("--copying `%s' to query_string...", optarg);
						mystrcpy(query_string, optarg, MAX_QUERY_STR);
						// to mozeme urobit; predtym, ked sme este nealokovali pre query_string miesto, bolo by lepsie urobit nejaku lokalnu premennu, na ktoru by potom query_string ukazoval
						mystrcpy(pom_QUERY_TYPE, STR_PRM_SIMULACIA_QS, MAX_POM_QUERY_TYPE);
						query_type = PRM_SIMULACIA_QS;
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'd': // deň
					if(optarg != NULL){
						mystrcpy(pom_DEN, optarg, SMALL);
					}
					Log("option %c with value `%s' -- den\n", c, optarg); break;
				case 'm': // mesiac
				case 't': // TYZDEN
					if(optarg != NULL){
						mystrcpy(pom_MESIAC, optarg, SMALL);
					}
					Log("option %c with value `%s' -- mesiac/tyzden\n", c, optarg); break;
				case 'r': // ROK, ANALYZA_ROKU
					if(optarg != NULL){
						mystrcpy(pom_ROK, optarg, SMALL);
					}
					Log("option %c with value `%s' -- rok\n", c, optarg); break;
				case 'p': // modlitba
					if(optarg != NULL){
						mystrcpy(pom_MODLITBA, optarg, SMALL);
					}
					Log("option %c with value `%s' -- modlitba\n", c, optarg); break;
				case 'x': // DALSI_SVATY
					if(optarg != NULL){
						mystrcpy(pom_DALSI_SVATY, optarg, SMALL);
					}
					Log("option %c with value `%s' -- poradie svateho\n", c, optarg); break;

				// nasledovne case'y sa tykaju MODL_OPT...
				case '0':
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT[OPT_0_SPECIALNE], optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '1':
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT[OPT_1_CASTI_MODLITBY], optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '2':
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT[OPT_2_HTML_EXPORT], optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '3':
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT[OPT_3_SPOLOCNA_CAST], optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '4':
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT[OPT_4_OFFLINE_EXPORT], optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;

				// append pridany 2003-07-08, bude v _global_opt_append
				case 'a': // MODL_OPT_APPEND
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT_APPEND, optarg, SMALL);
					}
					// option a (append), pridana 2003-07-08
					if(equals(pom_MODL_OPT_APPEND, STR_ANO) || equals(pom_MODL_OPT_APPEND, STR_VALUE_TRUE)){
						_global_opt_append = ANO;
					}
					else if(equals(pom_MODL_OPT_APPEND, STR_NIE) || equals(pom_MODL_OPT_APPEND, STR_VALUE_FALSE)){
						_global_opt_append = NIE;
					}// inak ostane _global_opt_APPEND default
					Log("opt_append == `%s' (%d)\n", pom_MODL_OPT_APPEND, _global_opt_append);
					Log("option %c with value `%s'\n", c, optarg); break;

				// 2008-11-29: pridaný parameter `u' (dátUm) spôsob zapisovania dátumu pre súbory v batch móde
				case 'u': // MODL_OPT_APPEND
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT_DATE_FORMAT, optarg, SMALL);
					}
					if(equals(pom_MODL_OPT_DATE_FORMAT, STR_FULL) || equals(pom_MODL_OPT_DATE_FORMAT, STR_VALUE_TRUE)){
						_global_opt_export_date_format = EXPORT_DATE_FULL;
					}
					else if(equals(pom_MODL_OPT_DATE_FORMAT, STR_SIMPLE) || equals(pom_MODL_OPT_DATE_FORMAT, STR_VALUE_FALSE)){
						_global_opt_export_date_format = EXPORT_DATE_SIMPLE;
					}// inak ostane _global_opt_export_date_format default
					Log("opt_append == `%s' (%d)\n", pom_MODL_OPT_DATE_FORMAT, _global_opt_export_date_format);
					Log("option %c with value `%s'\n", c, optarg); break;

				case 'q': // QUERY_TYPE
					if(optarg != NULL){
						mystrcpy(pom_QUERY_TYPE, optarg, MAX_POM_QUERY_TYPE);
					}
					Log("option %c with value `%s'\n", c, optarg); break;

				case 'M': // typ exportu pre batch mód; 2009-08-02
					if(optarg != NULL){
						mystrcpy(pom_EXPORT_MONTHLY, optarg, SMALL); // premenná pom_EXPORT_MONTHLY sa parsuje priamo v _main()
					}
					_global_opt_batch_monthly = ANO;
					Log("option %c with value `%s'\n", c, optarg); break;

				case 'I': // odkaz "^ hore" / index.htm (pre batch mód); 2009-08-12
					if(optarg != NULL){
						mystrcpy(_global_export_navig_hore, optarg, SMALL);
					}
					else{
						mystrcpy(_global_export_navig_hore, DEFAULT_MONTH_EXPORT, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;

				case 'H':
					_global_hlavicka_Export = 1;
					_global_patka_Export = 1;
					Log("option '%c'\n", c); break;

				case '?':
				case 'h':
					// 2003-06-26 -- pridane -s (query string), -q psqs
					printf("\n");
					printf("lh - command-line verzia on-line breviara (http://breviar.sk)\n");
					// pridane 2003-07-17
					printf("\tProgram vytvara stranky (HTML vystup) pre Liturgiu hodin.\n");
					// build pridany 2003-07-04
					printf("\tBuild: %s\n", BUILD_DATE);
					printf("\t"TEXT_COPYRIGHT" <"TEXT_EMAIL">\n");
					printf("\n");
					printf("\npouzitie:\n");
					printf("\tlh [prepinac [hodnota]...]\n");
					printf("\nprepinace:\n");
					printf("\tq  query type (napr. %s, %s, %s, %s, %s, %s...)\n",
						STR_PRM_DNES, STR_PRM_DATUM, STR_PRM_DETAILY, STR_PRM_TABULKA, STR_PRM_SIMULACIA_QS, STR_PRM_BATCH_MODE);
					printf("\ts  query string (tak ako je na webe)\n");
					printf("\td  den (%s|%s) (1--31, po--ne)\n", STR_DEN, STR_DEN_V_TYZDNI);
					// printf("\ts  SVIATOK \n");
					printf("\tm  mesiac (%s) (1--12, jan--dec)\n", STR_MESIAC);
					printf("\tt  tyzden zaltara (1--4) \n");
					printf("\tr  rok (napr. 2000)\n");
					printf("\tp  modlitba (%s): %s, %s, %s, %s, %s, %s, %s, %s, %s...) \n", 
						STR_MODLITBA, STR_MODL_RANNE_CHVALY, STR_MODL_VESPERY, STR_MODL_POSV_CITANIE, STR_MODL_PREDPOLUDNIM, STR_MODL_NAPOLUDNIE, STR_MODL_POPOLUDNI, STR_MODL_DETAILY, STR_MODL_INVITATORIUM, STR_MODL_KOMPLETORIUM);
					printf("\t\t resp. rok do pre davkove spracovanie\n");
					printf("\tx  dalsi svaty (%s): 1--%d resp. %d pre lubovolnu spomienku PM v sobotu\n", STR_DALSI_SVATY, MAX_POCET_SVATY, PORADIE_PM_SOBOTA);
					printf("\t0  specialne casti modlitby (verse, referencie)\n");
					printf("\t1  prepinace pre zobrazovanie casti modlitby\n");
					printf("\t2  prepinace pre html export\n");
					printf("\t3  ktoru spolocnu cast brat, ak je ich viac (0, 1, 2, 3) \n");
					printf("\t4  prepinace pre offline export\n");
					printf("\tf  rok from (resp. den do pre davkove spracovanie)\n");
					printf("\tg  rok to (resp. mesiac do pre davkove spracovanie)\n");
					printf("\tl  ci zobrazovat linky \n");
					printf("\te  export filename (default: export.htm)\n");
					printf("\ti  include folder\n");
					printf("\tb  batch mode (davkove spracovanie), nazov vystupneho davkoveho suboru\n");
					printf("\tn  nazov binarky (tohto suboru, napr. breviar.exe) pre batch mode\n");
					printf("\to  nazov (HTML) suboru pre vysledny zoznam modlitieb, batch mode\n");
					printf("\ta  (append) pri exportovani do suboru (-e) neprepisuje subor\n");
					printf("\tj  jazyk (jazykova mutacia), zatial: sk, cz\n");
					printf("\tk  kalendar (napr. reholny)\n");
					printf("\tc  css filename (pouzite CSS)\n");
					printf("\tu  batch mode dates in file name format (0 = simple, 1 = full)\n");
					printf("\tM  pre batch mode: jednotlive mesiace su v samostatnych suboroch\n");
					printf("\t   M0 = v mesiaci dni pod sebou, modlitby pre kazdy den v riadku\n");
					printf("\t   M1 = v mesiaci podla modlitieb su dni len ako cislice\n");
					printf("\t   M2 = generovanie funkcnej offline verzie (kopie) webu\n");
					printf("\t   M3 = ako M2, ale prisposobene pre mobilne zariadenia\n");
					printf("\tI  pre batch mode: subor, kam ma odkazovat link '^ hore'\n");
					printf("\n\t   pri prepinacoch ano = 1, nie = 0\n");
					printf("\npriklady pouzitia:\n\n");
					printf("breviar.exe -i..\\..\\..\\ -qpsqs -s\"qt=pdt&d=12&m=7&r=2003\"\n");
					printf("breviar -qpdt -d30 -m4 -r2002 -pmrch -ic:\\temp\\breviar\\ -emoja.htm\n");
					printf("breviar.exe -i..\\..\\..\\ -d28 -m6 -r2003 -qpdt -pmrch -x1\n");
					printf("breviar -qpbm -d1 -m1 -r2000 -f2 -g2 -p2000 -ba.bat -nbrev.exe -ic:\\breviar\\\n");
					printf("breviar.exe -qpbm -d1 -m8 -r2009 -f30 -g9 -p2009 -11 -brob.bat -jsk -nbreviar.exe -i..\\..\\www.breviar.sk\\include\\ -ufull -M3\n");
					printf("\nviac informacii:\n");
					printf("\thttp://breviar.sk - hlavna stranka\n");
					printf("\thttp://breviar.sk/info/parametre.htm - o parametroch\n");
					printf("\thttp://breviar.sk/info/batchmode.htm - o davkovom mode (batch mode)\n");

					Log("option %c (without value)\n", c, optarg);
					break;
				default:
				// znamena option uvedenu v optionstringu, pre ktoru nebolo definovane case vyssie
					Log("?? getopt returned character `%c' ??\n", c);
					break;
			}// switch
		}// while
		if(optind < argc){
			Log("non-option ARGV-elements: ");
			while(optind < argc)
			Log("%s ", argv[optind++]);
			Log("\n");
		}

		// dokoncili sme parsovanie options (switchov apod), a teraz rozoberieme, co sme zistili

		// najprv nakopirujeme chybovu hlasku do bad_param_str
		if(equals(pom_QUERY_TYPE, STR_EMPTY)){
			mystrcpy(bad_param_str, "<"HTML_SPAN_BOLD">nijaký parameter PRM_..."HTML_SPAN_END, MAX_STR);
		}
		else{
			mystrcpy(bad_param_str, pom_QUERY_TYPE, MAX_STR);
			strcat(bad_param_str, " (switch <"HTML_SPAN_BOLD">-q"HTML_SPAN_END")");
		}
		// a teraz vydolujeme typ dotazu
		// vynecham to v pripade, ze pom_QUERY_TYPE == STR_PRM_SIMULACIA_QS, t.j. query_type == PRM_SIMULACIA_QS
		if(query_type != PRM_SIMULACIA_QS){
			Log("query_type != PRM_SIMULACIA_QS, so running getQueryTypeFrom_QS(%s)...\n", pom_QUERY_TYPE);
			query_type = getQueryTypeFrom_QS(pom_QUERY_TYPE);
		}

		// 2013-09-30: ak je query type OK, tak vymažeme chybový oznam
		if(query_type != PRM_UNKNOWN){
			Log("query_type OK, čistím bad_param_str...\n");
			mystrcpy(bad_param_str, STR_EMPTY, MAX_STR);
		}

		// 2009-08-02: pri exportovaní do adresárov po mesiacoch je potrebné upraviť name_binary_executable resp. include_dir 
		// 2009-08-03: ale len v batch móde (teda nie pre jednotlivú generovanú modlitbu) -- preto presunuté až sem, za zistenie query_type
		if(query_type == PRM_BATCH_MODE && _global_opt_batch_monthly == ANO){
			mystrcpy(pom_name_binary_executable, STR_EMPTY, MAX_STR);
			mystrcpy(pom_include_dir, STR_EMPTY, MAX_STR);
			// 2012-12-12: nie pre append (netreba vytvárať adresáre [mkdir] ani po nich chodiť [cd])
			if(_global_opt_append != YES){
				// musíme upraviť názov executable, lebo budeme meniť adresár v _main_batch_mode()
				mystrcpy(pom_name_binary_executable, ".."STR_PATH_SEPARATOR, MAX_STR);
				// musíme upraviť názov adresára s include, lebo budeme meniť adresár v _main_batch_mode()
				mystrcpy(pom_include_dir, ".."STR_PATH_SEPARATOR, MAX_STR);
			}
			strcat(pom_name_binary_executable, name_binary_executable);
			mystrcpy(name_binary_executable, pom_name_binary_executable, MAX_STR);
			strcat(pom_include_dir, include_dir);
			mystrcpy(include_dir, pom_include_dir, MAX_STR);
		}// len pre batch mód, mesačne
	}// else vetva podmienky if(argc == 1)

	Log("deallocating memory for option_string...\n");
	free(option_string);

	Log("-- getArgv(): end, query_type == %d, query_string == %s, bad_param_str == %s\n", query_type, query_string, bad_param_str);

	return SUCCESS;
}// getArgv();

//---------------------------------------------------------------------
// popis: naplni premenne pom_... hodnotami z environmentu, t.j. premennymi WWW_ ktore vrati uncgi.c
// vracia: on success, returns SUCCESS
//         on error,   returns FAILURE
// 2005-03-30: Upravene. 
// Ak hodnoty su v pom_ premennych, nepotrebujem citat z WWW_ premennych.
// V opacnom pripade to na linux::apache vypisovalo pre tlacidla (Dalsi den >>) ze nie su vytvorene premenne WWW_d a podobne, hoci boli v query stringu.
// Mozno je to cele nejak dosachovane tym, ze som preniesol uncgi sem do kodu. Ale hlavne ze to chodi :))
short int getForm(void){
	char *ptr;
	short int i = 0;
	char local_str[SMALL] = STR_EMPTY;
	short int ret; // návratová hodnota
	char errmsg[SMALL] = STR_EMPTY;

	Log("getForm() -- begin\n");
	//DEBUG_GET_FORM("argc == %d\n", argc);

	// malo by byt argc == 1

	// ak nie je premenná vytvorená, t. j. ak ptr == NULL, tak nás to netrápi, lebo pom_... su inicializované na STR_EMPTY

	// premenná WWW_JAZYK pridaná 2006-07-11 kvôli jazykovým mutáciám
	ptr = getenv(ADD_WWW_PREFIX_(STR_JAZYK));
	if(ptr != NULL){
		if(strcmp(ptr, STR_EMPTY) != 0){
			mystrcpy(pom_JAZYK, ptr, SMALL);
		}
	}

	// premenná STR_KALENDAR pridaná 2010-08-04 kvôli jazykovým mutáciám
	ptr = getenv(ADD_WWW_PREFIX_(STR_KALENDAR));
	if(ptr != NULL){
		if(strcmp(ptr, STR_EMPTY) != 0){
			mystrcpy(pom_KALENDAR, ptr, SMALL);
		}
	}

	// premenná WWW_CSS pridaná 2008-08-08 kvôli rôznym css
	ptr = getenv(ADD_WWW_PREFIX_(STR_CSS));
	if(ptr != NULL){
		if(strcmp(ptr, STR_EMPTY) != 0){
			mystrcpy(pom_CSS, ptr, SMALL);
		}
	}

	// premenná WWW_FONT_NAME pridaná 2011-05-06 kvôli rôznym fontom
	ptr = getenv(ADD_WWW_PREFIX_(STR_FONT_NAME));
	if(ptr != NULL){
		if(strcmp(ptr, STR_EMPTY) != 0){
			mystrcpy(pom_FONT, ptr, SMALL);
		}
	}

	// premenná WWW_FONT_SIZE pridaná 2011-05-13 kvôli rôznym veľkostiam fontov
	ptr = getenv(ADD_WWW_PREFIX_(STR_FONT_SIZE));
	if(ptr != NULL){
		if(strcmp(ptr, STR_EMPTY) != 0){
			mystrcpy(pom_FONT_SIZE, ptr, SMALL);
		}
	}

	// premenné WWW_MODL_OPT... presunuté sem, aby sa čítali vždy (2011-01-26); tiež doplnené force verzie (opt_0 až opt_4); niektoré sa používali aj v PRM_MESIAC_ROKA

	// 2011-04-07: options premenné
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		// premenná WWW_MODL_OPTi
		mystrcpy(local_str, WWW_PREFIX, SMALL);
		switch(i){
			case OPT_0_SPECIALNE:		strcat(local_str, STR_MODL_OPT_0); break;
			case OPT_1_CASTI_MODLITBY:	strcat(local_str, STR_MODL_OPT_1); break;
			case OPT_2_HTML_EXPORT:		strcat(local_str, STR_MODL_OPT_2); break;
			case OPT_3_SPOLOCNA_CAST:	strcat(local_str, STR_MODL_OPT_3); break;
			case OPT_4_OFFLINE_EXPORT:	strcat(local_str, STR_MODL_OPT_4); break;
			case OPT_5_ALTERNATIVES:	strcat(local_str, STR_MODL_OPT_5); break;
		}// switch(i)
		ptr = getenv(local_str);
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODL_OPT[i], ptr, SMALL);
			}
		}
	}// for i

	// 2011-04-07: force options premenné
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		// premenná WWW_MODL_OPTFi
		mystrcpy(local_str, WWW_PREFIX, SMALL);
		switch(i){
			case OPT_0_SPECIALNE:		strcat(local_str, STR_MODL_OPTF_0); break;
			case OPT_1_CASTI_MODLITBY:	strcat(local_str, STR_MODL_OPTF_1); break;
			case OPT_2_HTML_EXPORT:		strcat(local_str, STR_MODL_OPTF_2); break;
			case OPT_3_SPOLOCNA_CAST:	strcat(local_str, STR_MODL_OPTF_3); break;
			case OPT_4_OFFLINE_EXPORT:	strcat(local_str, STR_MODL_OPTF_4); break;
			case OPT_5_ALTERNATIVES:	strcat(local_str, STR_MODL_OPTF_5); break;
		}// switch(i)
		ptr = getenv(local_str);
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODL_OPTF[i], ptr, SMALL);
			}
		}
	}// for i

	// 2011-04-13: force option 0 premenné -- jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(getForm)\n", OPT_0_SPECIALNE);
	for(i = 0; i < POCET_OPT_0_SPECIALNE; i++){
		// premenná WWW_MODL_OPTF_0_...
		mystrcpy(local_str, WWW_PREFIX, SMALL);
		switch(i){
			case 0: strcat(local_str, STR_MODL_OPTF_0_VERSE); break; // BIT_OPT_0_VERSE
			case 1: strcat(local_str, STR_MODL_OPTF_0_REF); break; // BIT_OPT_0_REFERENCIE
			case 2: strcat(local_str, STR_MODL_OPTF_0_CIT); break; // BIT_OPT_0_CITANIA
			case 3: strcat(local_str, STR_MODL_OPTF_0_ZJAV_NED); break; // BIT_OPT_0_ZJAVENIE_PANA_NEDELA
			case 4: strcat(local_str, STR_MODL_OPTF_0_NAN_NED); break; // BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA
			case 5: strcat(local_str, STR_MODL_OPTF_0_TK_NED); break; // BIT_OPT_0_TELAKRVI_NEDELA
			case 6: strcat(local_str, STR_MODL_OPTF_0_FONT_NORMAL); break; // BIT_OPT_0_FONT_NORMAL
			case 7: strcat(local_str, STR_MODL_OPTF_0_BUTTONS_ORDER); break; // BIT_OPT_0_BUTTONS_ORDER
			case 8: strcat(local_str, STR_MODL_OPTF_0_BLIND_FRIENDLY); break; // BIT_OPT_0_BLIND_FRIENDLY
		}// switch(i)
		ptr = getenv(local_str);
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODL_OPTF_SPECIALNE[i], ptr, SMALL);
			}
		}
	}// for i

	// 2011-04-11: force option 1 premenné -- jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(getForm)\n", OPT_1_CASTI_MODLITBY);
	for(i = 0; i < POCET_OPT_1_CASTI_MODLITBY; i++){
		// premenná WWW_MODL_OPTF_1_...
		mystrcpy(local_str, WWW_PREFIX, SMALL);
		switch(i){
			case 0: strcat(local_str, STR_MODL_OPTF_1_TD); break; // BIT_OPT_1_TEDEUM
			case 1: strcat(local_str, STR_MODL_OPTF_1_RUB); break; // BIT_OPT_1_RUBRIKY
			case 2: strcat(local_str, STR_MODL_OPTF_1_CHV); break; // BIT_OPT_1_CHVALOSPEVY
			case 3: strcat(local_str, STR_MODL_OPTF_1_SL); break; // BIT_OPT_1_SLAVA_OTCU
			case 4: strcat(local_str, STR_MODL_OPTF_1_OT); break; // BIT_OPT_1_OTCENAS
			case 5: strcat(local_str, STR_MODL_OPTF_1_MCD_DOPLNKOVA); break; // BIT_OPT_1_MCD_DOPLNKOVA
			case 6: strcat(local_str, STR_MODL_OPTF_1_VIGILIA); break; // BIT_OPT_1_PC_VIGILIA
			case 7: strcat(local_str, STR_MODL_OPTF_1_SPOMIENKA_SPOL_CAST); break; // BIT_OPT_1_SPOMIENKA_SPOL_CAST
			case 8: strcat(local_str, STR_MODL_OPTF_1_PLNE_RESP); break; // BIT_OPT_1_PLNE_RESP
			case 9: strcat(local_str, STR_MODL_OPTF_1_ZALM95); break; // BIT_OPT_1_ZALM95
			case 10: strcat(local_str, STR_MODL_OPTF_1_PROSBY_ZVOLANIE); break; // BIT_OPT_1_PROSBY_ZVOLANIE
			case 11: strcat(local_str, STR_MODL_OPTF_1_SKRY_POPIS); break; // BIT_OPT_1_SKRY_POPIS
			case 12: strcat(local_str, STR_MODL_OPTF_1_ZOBRAZ_SPOL_CAST); break; // BIT_OPT_1_ZOBRAZ_SPOL_CAST
			case 13: strcat(local_str, STR_MODL_OPTF_1_VESP_KRATSIE_PROSBY); break; // BIT_OPT_1_VESP_KRATSIE_PROSBY
			case 14: strcat(local_str, STR_MODL_OPTF_1_MCD_ZALTAR_TRI); break; // BIT_OPT_1_MCD_ZALTAR_TRI
		}// switch(i)
		ptr = getenv(local_str);
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODL_OPTF_CASTI_MODLITBY[i], ptr, SMALL);
			}
		}
	}// for i

	// 2011-04-20: doplené; force option 2, jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(getForm)\n", OPT_2_HTML_EXPORT);
	for(i = 0; i < POCET_OPT_2_HTML_EXPORT; i++){
		// premenná WWW_MODL_OPTF_2_...
		mystrcpy(local_str, WWW_PREFIX, SMALL);
		switch(i){
			case 0: strcat(local_str, STR_MODL_OPTF_2_ISO_DATUM); break; // BIT_OPT_2_ISO_DATUM
			case 1: strcat(local_str, STR_MODL_OPTF_2_PRVE_VESPERY); break; // BIT_OPT_2_BUTTON_PRVE_VESPERY
			case 2: strcat(local_str, STR_MODL_OPTF_2_FONT_FAMILY); break; // BIT_OPT_2_FONT_FAMILY
			case 3: strcat(local_str, STR_MODL_OPTF_2_FONT_NAME_CHOOSER); break; // BIT_OPT_2_FONT_NAME_CHOOSER
			// case 4: strcat(local_str, STR_MODL_OPTF_2_FONT_SIZE); break; // BIT_OPT_2_FONT_SIZE_CHOOSER
			case 5: strcat(local_str, STR_MODL_OPTF_2_NAVIGATION); break; // BIT_OPT_2_NAVIGATION
			case 6: strcat(local_str, STR_MODL_OPTF_2_TEXT_WRAP); break; // BIT_OPT_2_TEXT_WRAP
			case 7: strcat(local_str, STR_MODL_OPTF_2_BUTTONY_USPORNE); break; // BIT_OPT_2_BUTTONY_USPORNE
			case 8: strcat(local_str, STR_MODL_OPTF_2_NOCNY_REZIM); break; // BIT_OPT_2_NOCNY_REZIM
			case 9: strcat(local_str, STR_MODL_OPTF_2_ROZNE_MOZNOSTI); break; // BIT_OPT_2_ROZNE_MOZNOSTI
			case 10: strcat(local_str, STR_MODL_OPTF_2_HIDE_NAVIG_BUTTONS); break; // BIT_OPT_2_HIDE_NAVIG_BUTTONS
			case 11: strcat(local_str, STR_MODL_OPTF_2_HIDE_KALENDAR); break; // BIT_OPT_2_HIDE_KALENDAR
			case 12: strcat(local_str, STR_MODL_OPTF_2_HIDE_OPTIONS1); break; // BIT_OPT_2_HIDE_OPTIONS1
			case 13: strcat(local_str, STR_MODL_OPTF_2_HIDE_OPTIONS2); break; // BIT_OPT_2_HIDE_OPTIONS2
			case 14: strcat(local_str, STR_MODL_OPTF_2_ALTERNATIVES); break; // BIT_OPT_2_ALTERNATIVES
		}// switch(i)
		ptr = getenv(local_str);
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODL_OPTF_HTML_EXPORT[i], ptr, SMALL);
			}
		}
	}// for i

	// 2013-01-29: doplené; force option 5, jednotlivé bit-komponenty
	Log("force option %d, jednotlivé bit-komponenty...(getForm)\n", OPT_5_ALTERNATIVES);
	for(i = 0; i < POCET_OPT_5_ALTERNATIVES; i++){
		// premenná WWW_MODL_OPTF_5_...
		mystrcpy(local_str, WWW_PREFIX, SMALL);
		switch(i){
			case 0: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_KOMPL); break; // BIT_OPT_5_HYMNUS_KOMPL
			case 1: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_PC); break; // BIT_OPT_5_HYMNUS_PC
			case 2: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_PREDPOL); break; // BIT_OPT_5_HYMNUS_MCD_PREDPOL
			case 3: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_NAPOL); break; // BIT_OPT_5_HYMNUS_MCD_NAPOL
			case 4: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_POPOL); break; // BIT_OPT_5_HYMNUS_MCD_POPOL
			case 5: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_122_129); break; // BIT_OPT_5_DOPLNK_PSALM_122_129
			case 6: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_127_131); break; // BIT_OPT_5_DOPLNK_PSALM_127_131
			case 7: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_126_129); break; // BIT_OPT_5_DOPLNK_PSALM_126_129
			case 8: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_PC); break; // BIT_OPT_5_HYMNUS_VN_PC
			case 9: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_RCH); break; // BIT_OPT_5_HYMNUS_VN_RCH
			case 10: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_VESP); break; // BIT_OPT_5_HYMNUS_VN_VESP
			case 11: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_1VESP); break; // BIT_OPT_5_HYMNUS_1VESP
		}// switch(i)
		ptr = getenv(local_str);
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODL_OPTF_ALTERNATIVES[i], ptr, SMALL);
			}
		}
	}// for i

	if((query_type == PRM_DATUM) || (query_type == PRM_DETAILY) || (query_type == PRM_TXT) || (query_type == PRM_XML)){
		// datum: treba nacitat den, mesiac a rok

		// premenna WWW_DEN
		// ak je naplnena pom_DEN, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_DEN, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_DEN));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_DEN));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_DEN));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_DEN, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_DEN je už naplnená (%s). Nečítam z %s...\n", pom_DEN, ADD_WWW_PREFIX_(STR_DEN));
		}

		// premenna WWW_MESIAC
		// ak je naplnena pom_MESIAC, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_MESIAC, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MESIAC));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_MESIAC));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_MESIAC));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MESIAC, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_MESIAC je už naplnená (%s). Nečítam z %s...\n", pom_MESIAC, ADD_WWW_PREFIX_(STR_MESIAC));
		}

		// premenna WWW_ROK
		// ak je naplnena pom_ROK, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_ROK, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_ROK));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_ROK, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_ROK je už naplnená (%s). Nečítam z %s...\n", pom_ROK, ADD_WWW_PREFIX_(STR_ROK));
		}

		// nasledujuce sa zistuju kvoli 'Detaily...', formular vytvorila funckia showDetails(); v normalnom formulari (vytvori ho _main_dnes();) nie su

		// premenna WWW_MODLITBA
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODLITBA));
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODLITBA, ptr, SMALL);
			}
		}
		// treba otestovat, ci (v pripade, ze sa jedna o prvy vstupny formular, t.j. PRM_DATUM) je modlitba nastavena -- v takom pripade treba nastavit modlitbu na MODL_NEURCENA;
		// ak je druhy formular -- Detaily (t.j. PRM_DETAILY), tak modlitba ostane ponechana
		// je to tu kvoli tomu, ze v prvom formulari sa da napr. oznacit
		//          (o) datum 22. februar 2000
		//          ( ) cezrocne obdobie, utorok v 3. tyzdni zaltara, ranne chvaly
		//          ( ) ... atd,
		// a po odoslani sa _vytvori_ premenna WWW_... (modlitba) s hodnotou 'ranne chvaly' -- takze ju treba znicit
		// zistime to tak, ze ci je nastavena napr. premenna WWW_MESIAC_ROKA | 22/02/2000A.D.

		// premenna WWW_MESIAC_ROKA -- len testovo, aby sme odlisili prvy od druheho formulara
		ptr = getenv(ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
		if(ptr != NULL){ // povodne if(query_type == PRM_DATUM)
			// nie je NULL, ide teda o prvy vstupny formular
			mystrcpy(pom_MODLITBA, STR_EMPTY, SMALL);
		}

		// premenna WWW_DALSI_SVATY
		ptr = getenv(ADD_WWW_PREFIX_(STR_DALSI_SVATY));
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_DALSI_SVATY, ptr, SMALL);
			}
		}
	}// (query_type == PRM_DATUM) || (query_type == PRM_DETAILY) || (query_type == PRM_TXT) || (query_type == PRM_XML)

	else if(query_type == PRM_CEZ_ROK){
		// cez rok: treba nacitat den v tyzdni a cislo tyzdna

		// premenna WWW_DEN_V_TYZDNI
		// ak je naplnena pom_DEN_V_TYZDNI, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_DEN_V_TYZDNI, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_DEN_V_TYZDNI, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_DEN_V_TYZDNI je už naplnená (%s). Nečítam z %s...\n", pom_DEN_V_TYZDNI, ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
		}

		// premenna WWW_TYZDEN
		// ak je naplnena pom_TYZDEN, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_TYZDEN, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_TYZDEN));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_TYZDEN));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_TYZDEN));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_TYZDEN, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_TYZDEN je už naplnená (%s). Nečítam z %s...\n", pom_TYZDEN, ADD_WWW_PREFIX_(STR_TYZDEN));
		}

		// premenna WWW_MODLITBA
		// ak je naplnena pom_MODLITBA, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_MODLITBA, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MODLITBA));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_MODLITBA));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_MODLITBA));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODLITBA, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_MODLITBA je už naplnená (%s). Nečítam z %s...\n", pom_MODLITBA, ADD_WWW_PREFIX_(STR_MODLITBA));
		}
	}// query_type == PRM_CEZ_ROK

	else if(query_type == PRM_LIT_OBD){
		// 2011-01-25: doplnené | liturgické obdobie: treba načítať liturgické obdobie, deň v týždni a číslo týždňa v danom liturgickom období 

		// premenna WWW_DEN_V_TYZDNI
		// ak je naplnena pom_DEN_V_TYZDNI, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_DEN_V_TYZDNI, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_DEN_V_TYZDNI, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_DEN_V_TYZDNI je už naplnená (%s). Nečítam z %s...\n", pom_DEN_V_TYZDNI, ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
		}

		// premenna WWW_TYZDEN
		// ak je naplnena pom_TYZDEN, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_TYZDEN, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_TYZDEN));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_TYZDEN));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_TYZDEN));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_TYZDEN, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_TYZDEN je už naplnená (%s). Nečítam z %s...\n", pom_TYZDEN, ADD_WWW_PREFIX_(STR_TYZDEN));
		}

		// premenna WWW_MODLITBA
		// ak je naplnena pom_MODLITBA, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_MODLITBA, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MODLITBA));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_MODLITBA));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_MODLITBA));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MODLITBA, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_MODLITBA je už naplnená (%s). Nečítam z %s...\n", pom_MODLITBA, ADD_WWW_PREFIX_(STR_MODLITBA));
		}

		// premenna WWW_LIT_OBD
		// ak je naplnena pom_LIT_OBD, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_LIT_OBD, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_LIT_OBD));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_LIT_OBD));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_LIT_OBD));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_LIT_OBD, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_LIT_OBD je už naplnená (%s). Nečítam z %s...\n", pom_LIT_OBD, ADD_WWW_PREFIX_(STR_LIT_OBD));
		}

		// premenna WWW_LIT_ROK
		// ak je naplnena pom_LIT_ROK, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_LIT_ROK, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_LIT_ROK));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_LIT_ROK));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_LIT_ROK));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_LIT_ROK, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_LIT_ROK je už naplnená (%s). Nečítam z %s...\n", pom_LIT_ROK, ADD_WWW_PREFIX_(STR_LIT_ROK));
		}
	}// query_type == PRM_LIT_OBD

	else if(query_type == PRM_SVIATOK){
		// cez rok: treba nacitat nazov sviatku

		// premenna WWW_NAZOV_SVIATOK
		// ak je naplnena pom_SVIATOK, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_SVIATOK, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_SVIATOK, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_SVIATOK je už naplnená (%s). Nečítam z %s...\n", pom_SVIATOK, ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
		}
	}// query_type == PRM_SVIATOK

	else if(query_type == PRM_STATIC_TEXT){
		// premenna WWW_STATIC_TEXT
		// ak je naplnena pom_STATIC_TEXT, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_STATIC_TEXT, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_STATIC_TEXT));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_STATIC_TEXT));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_STATIC_TEXT));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_STATIC_TEXT, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_STATIC_TEXT je už naplnená (%s). Nečítam z %s...\n", pom_STATIC_TEXT, ADD_WWW_PREFIX_(STR_STATIC_TEXT));
		}

		// premenna WWW_MODL_ORDINARIUM
		// ak je naplnena MODL_ORDINARIUM, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_MODL_ORDINARIUM, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_ORDINARIUM));
			if(ptr != NULL){
				if(strcmp(ptr, STR_EMPTY) != 0){
					mystrcpy(pom_MODL_ORDINARIUM, ptr, SMALL);
				}
			}
		}
		else{
			Log("Premenná pom_MODL_ORDINARIUM je už naplnená (%s). Nečítam z %s...\n", pom_MODL_ORDINARIUM, ADD_WWW_PREFIX_(STR_MODL_ORDINARIUM));
		}
}// query_type == PRM_STATIC_TEXT

	else if(query_type == PRM_ANALYZA_ROKU){
		// cez rok: treba nacitat nazov sviatku

		// premenna WWW_ANALYZA_ROKU
		// ak je naplnena pom_ANALYZA_ROKU, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_ANALYZA_ROKU, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_ANALYZA_ROKU, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_ANALYZA_ROKU je už naplnená (%s). Nečítam z %s...\n", pom_ANALYZA_ROKU, ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
		}
	}// query_type == PRM_ANALYZA_ROKU

	else if(query_type == PRM_MESIAC_ROKA){
		// 2005-03-21: novy typ exportu liturgickeho kalendara: 
		// ak je hodnota premennej option "1" = 0 (default), tak klasicky pre web, inak rozlicny sposob vystupu ("1" = 1 pre www.kbs.sk liturgicky kalendar)
		// 2005-03-22: novy typ exportu liturgickeho kalendara: ak je hodnota premennej option "2" = 1 (default), tak datum ako ISO-8601, inak len datum

		// treba nacitat mesiac a rok
		// premenna WWW_MESIAC_ROKA
		// ak je naplnena pom_MESIAC (vynimocne nie pom_MESIAC_ROKA), znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_MESIAC, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_MESIAC, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_MESIAC je už naplnená (%s). Nečítam z %s...\n", pom_MESIAC, ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
		}

		// premenna WWW_ROK
		// ak je naplnena pom_ROK (vynimocne nie pom_ROK_ROKA), znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_ROK, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK_ROKA));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK_ROKA));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_ROK_ROKA));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_ROK, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_ROK je už naplnená (%s). Nečítam z %s...\n", pom_ROK, ADD_WWW_PREFIX_(STR_ROK_ROKA));
		}
	}// query_type == PRM_MESIAC_ROKA

	else if(query_type == PRM_TABULKA){
		// PRM_TABULKA: treba nacitat from a to; ak chyba linka, tak automaticky == NIE

		// premenna WWW_ROK_FROM
		// ak je naplnena pom_ROK_FROM, znamena to, ze uz bola naplnena, preto nemusi existovat
		if(equals(pom_ROK_FROM, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK_FROM));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK_FROM));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_ROK_FROM));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_ROK_FROM, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_ROK_FROM je už naplnená (%s). Nečítam z %s...\n", pom_ROK_FROM, ADD_WWW_PREFIX_(STR_ROK_FROM));
		}

		// premenna WWW_ROK_TO
		// ak je naplnena pom_ROK_TO, znamena to, ze uz bola naplnena, preto nemusi existovat
		// 2005-05-24 Opravena copy-paste chyba: bolo mylne if(equals(pom_ROK_FROM, STR_EMPTY))
		if(equals(pom_ROK_TO, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK_TO));
			if(ptr == NULL){
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK_TO));
				// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola vytvorená systémová premenná %s.\n", ADD_WWW_PREFIX_(STR_ROK_TO));
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_getForm;
			}
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_ROK_TO, ptr, SMALL);
			}
		}
		else{
			Log("Premenná pom_ROK_TO je už naplnená (%s). Nečítam z %s...\n", pom_ROK_TO, ADD_WWW_PREFIX_(STR_ROK_TO));
		}

		// premenna WWW_TABULKA_LINKY
		ptr = getenv(ADD_WWW_PREFIX_(STR_TABULKA_LINKY));
		if(ptr != NULL){
			if(strcmp(ptr, STR_EMPTY) != 0){
				mystrcpy(pom_LINKY, ptr, SMALL);
			}
		}
	}// query_type == PRM_TABULKA

	else if(query_type == PRM_DNES){
		// 2005-03-28: Pridane, aby nevracalo FAILURE
		Log("getForm() -- nie je potrebne nic nacitavat :)) \n");
	}

	else{
		Log("getForm() -- end, returning FAILURE (neznamy typ dotazu qt)\n");
		// neznamy typ dotazu
		// 2013-08-04: samotné vypísanie niečoho presunuté do hlavnej funkcie
		sprintf(errmsg, "Neznámy typ dotazu (qt).\n");
		strcat(bad_param_str, errmsg);
		ret = FAILURE;
		goto END_getForm;
	}
	ret = SUCCESS;

END_getForm:
	Log("getForm() -- end, returning %d.\n", ret);
	return ret;
}// getForm();

//---------------------------------------------------------------------
// popis: naplni premenne pom_... hodnotami z environmentu, t.j. premennymi zo stringu QUERY_STRING (systemova premenna)
// napriklad retazec "QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976"
// vracia: on success, returns SUCCESS
//         on error,   returns FAILURE
// historia: 
//        2005-03-22 Upravene, natvrdo sa predpokladalo urcite poradie parametrov.
//        Umoznujeme aj odlisne poradie (prip. vynechanie niektorych parametrov) v query stringu.
short int parseQueryString(void){
// totiz spustenie skriptu
// /cgi-bin/script_name?QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976
// funguje tak, ze vytvori systemovu premennu QUERY_STRING takze vlastne treba simulovat uncgi (parsovanie QUERY_STRING systemovej premennej)
// (keby sme to este prehnali cez uncgi, teda spustili /cgi-bin/uncgi.cgi/script_name?QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976 
// tak to funguje ako POST hodnoty z formulara - urobi systemove premenne WWW_QUERY_TYPE=PRM_DATUM, WWW_DATUM, WWW_MESIAC, WWW_ROK)

	short int i, pocet, ok;
	char local_str[SMALL] = STR_EMPTY;
	short int j; // kvôli prilep_request_options
	short int ret; // návratová hodnota
	char errmsg[SMALL] = STR_EMPTY;

	Log("parseQueryString() -- begin\n");
	if(query_string != NULL)
		Log("query_string == %s, lenght == %d\n", query_string, strlen(query_string));
	else
		Log("query_string is NULL, something is wrong...\n");

	// get parameters
	i = 0;
	while((strlen(query_string) > 0) && (i < MAX_VARIABLES)){ // 2006-08-01: doplnená podmienka, aby nepretieklo napĺňanie premenných, ak je ich viac
		mystrcpy(param[i].name, STR_EMPTY, MAX_NAME_CGI_UTILS);
		mystrcpy(param[i].val, STR_EMPTY, MAX_VAL_CGI_UTILS);
		splitword(param[i].val, query_string, '&');
		unescape_url(param[i].val);
		splitword(param[i].name, param[i].val, '=');
		Log("--- param[%d].name == %s, .val == %s\n", i, param[i].name, param[i].val);
		i++;
	}
	pocet = i; // od 0 po i - 1
	Log("pocet == %d\n", pocet);

	// 2006-08-01: doplnená podmienka, aby nepretieklo napĺňanie premenných, ak je ich viac
	if((strlen(query_string) > 0) && (pocet >= MAX_VARIABLES)){
		ALERT;
		Export("Program nedokáže obslúžiť viac parametrov (maximum: %d). Ostatné budú ignorované.\n", MAX_VARIABLES);
	}

	// 2006-07-12: pridané kvôli jazykovým mutáciám
	// 2012-07-23: Pre POST query sa tam jazyk priliepa aj na začiatok (Ruby), aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards)
	//             ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	//             pôvodná poznámka pre while cyklus resp. inicializáciu i: param[0] by mal síce obsahovať typ akcie, ale radšej kontrolujeme aj 0
	i = pocet;
	Log("pokúšam sa zistiť jazyk (od posledného parametra k prvému, t. j. odzadu)...\n");
	while((equalsi(pom_JAZYK, STR_EMPTY)) && (i > 0)){
		--i;
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_JAZYK)){
			// ide o parameter STR_JAZYK
			mystrcpy(pom_JAZYK, param[i].val, SMALL);
			Log("jazyk zistený (%s).\n", pom_JAZYK);
		}
	}

	// 2010-08-04: pridané kvôli jazykovým mutáciám -- kalendár 
	//             pôvodná poznámka pre while cyklus resp. inicializáciu i: param[0] by mal síce obsahovať typ akcie, ale radšej kontrolujeme aj 0
	// 2010-10-11: Pre POST query sa tam kalendár priliepa aj na začiatok, aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards)
	//             ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	// 2011-04-07: keďže počet parametrov je "pocet", indexované sú 0 až pocet - 1, a preto opravené: najprv znížime --i;
	i = pocet;
	Log("pokúšam sa zistiť kalendár (od posledného parametra k prvému, t. j. odzadu)...\n");
	while((equalsi(pom_KALENDAR, STR_EMPTY)) && (i > 0)){
		--i;
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_KALENDAR)){
			// ide o parameter STR_KALENDAR
			mystrcpy(pom_KALENDAR, param[i].val, SMALL);
			Log("kalendár zistený (%s).\n", pom_KALENDAR);
		}
	}

	// 2008-08-08: pridané kvôli rôznym css
	i = 0; // param[0] by mal síce obsahovať typ akcie, ale radšej kontrolujeme od 0
	Log("pokúšam sa zistiť css...\n");
	while((equalsi(pom_CSS, STR_EMPTY)) && (i < pocet)){
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_CSS)){
			// ide o parameter STR_CSS
			mystrcpy(pom_CSS, param[i].val, SMALL);
			Log("css zistené (%s).\n", pom_CSS);
		}
		i++;
	}
	// 2012-07-23: doplnené (snáď nebude robiť problémy)
	if((i >= pocet) && (equalsi(pom_CSS, STR_EMPTY))){
		mystrcpy(pom_CSS, nazov_css[CSS_breviar_sk], SMALL);
		Log("css zistené (%s) (i >= pocet).\n", pom_CSS);
	}

	// 2011-05-05: pridané kvôli rôznym fontom 
	// 2011-05-06: Pre POST query sa tam font priliepa aj na začiatok (rovnako ako kalendár), aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards) (rovnako ako kalendár), ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), 
	//             nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	i = pocet;
	Log("pokúšam sa zistiť font (od posledného parametra k prvému, t. j. odzadu)...\n");
	while((equalsi(pom_FONT, STR_EMPTY)) && (i > 0)){
		--i;
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_FONT_NAME)){
			// ide o parameter STR_FONT_NAME
			mystrcpy(pom_FONT, param[i].val, SMALL);
			Log("font zistený (%s).\n", pom_FONT);
		}
	}

	// 2011-05-13: pridané kvôli rôznym veľkostiam fontom 
	//             Pre POST query sa tam font priliepa aj na začiatok (rovnako ako kalendár), aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards) (rovnako ako kalendár), ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), 
	//             nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	i = pocet;
	Log("pokúšam sa zistiť font size (od posledného parametra k prvému, t. j. odzadu)...\n");
	while((equalsi(pom_FONT_SIZE, STR_EMPTY)) && (i > 0)){
		--i;
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_FONT_SIZE)){
			// ide o parameter STR_FONT_SIZE
			mystrcpy(pom_FONT_SIZE, param[i].val, SMALL);
			Log("font size zistená (%s).\n", pom_FONT_SIZE);
		}
	}

	// 2006-08-01: pôvodne sme predpokladali, že param[0] by mal obsahovať typ akcie; odteraz ho hľadáme v celom zozname parametrov
	// 2011-01-25: doplnené PRM_LIT_OBD
	ok = NIE;
	query_type = PRM_UNKNOWN;
	i = 0; // od param[0]
	Log("pokúšam sa zistiť query type...\n");
	while((ok != ANO) && (i < pocet)){
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_QUERY_TYPE)){ // zistíme typ akcie, lebo ide o dobrý parameter
			if(equals(param[i].val, STR_PRM_DATUM)){
				// ide o parameter STR_PRM_DATUM
				query_type = PRM_DATUM;
			}
			else if(equals(param[i].val, STR_PRM_TXT)){
				// ide o parameter STR_PRM_TXT; pridané 2011-02-02
				query_type = PRM_TXT;
			}
			else if(equals(param[i].val, STR_PRM_XML)){
				// ide o parameter STR_PRM_XML; pridané 2012-10-16
				query_type = PRM_XML;
			}
			else if(equals(param[i].val, STR_PRM_STATIC_TEXT)){
				// ide o parameter STR_PRM_STATIC_TEXT; pridané 2014-10-09
				query_type = PRM_STATIC_TEXT;
			}
			else if(equals(param[i].val, STR_PRM_DETAILY)){
				// ide o parameter STR_PRM_DETAILY | alternativa k PRM_DATUM
				query_type = PRM_DETAILY;
			}
			else if(equals(param[i].val, STR_PRM_CEZ_ROK)){
				// ide o parameter STR_PRM_CEZ_ROK
				query_type = PRM_CEZ_ROK;
			}
			else if(equals(param[i].val, STR_PRM_LIT_OBD)){
				// ide o parameter STR_PRM_LIT_OBD
				query_type = PRM_LIT_OBD;
			}
			else if(equals(param[i].val, STR_PRM_SVIATOK)){
				// ide o parameter STR_PRM_SVIATOK
				query_type = PRM_SVIATOK;
			}
			else if(equals(param[i].val, STR_PRM_DNES)){
				// ide o parameter STR_PRM_DNES
				query_type = PRM_DNES;
			}
			else if(equals(param[i].val, STR_PRM_ANALYZA_ROKU)){
				// ide o parameter STR_PRM_ANALYZA_ROKU
				query_type = PRM_ANALYZA_ROKU;
			}
			else if(equals(param[i].val, STR_PRM_MESIAC_ROKA)){
				// ide o parameter STR_PRM_MESIAC_ROKA
				query_type = PRM_MESIAC_ROKA;
			}
			else if(equals(param[i].val, STR_PRM_TABULKA)){
				// ide o parameter STR_PRM_TABULKA
				query_type = PRM_TABULKA;
			}
			else{
				// názov parametra je OK, ale neurčuje žiadnu správnu akciu
				Export("Chybná hodnota parametra %s: %s\n", param[i].name, param[i].val);
				query_type = PRM_UNKNOWN;
			}
			Log("query type parameter prítomný (%s), hodnota zistená (%s).\n", param[i].name, param[i].val);
		}// if(equals(param[i].name, STR_QUERY_TYPE))
		if(query_type != PRM_UNKNOWN)
			ok = ANO;
		i++;
	}// while

	// 2013-07-31: pôvodne tu bola kontrola na "ok"; presunuté až po parsovaní option premenných nižšie

	// 2011-01-26: premenné opt_1 až opt7 sa čítajú vždy; ak nie sú zadané, nevadí
	//             doteraz sa čítali len pre niektoré query_type: PRM_DNES, PRM_DETAILY, PRM_DATUM
	// 2011-01-26: doplnené tiež force opt_0 až opt_4
	// 2011-04-07: prerobené na dve polia premenných
	for(j = 0; j < POCET_GLOBAL_OPT; j++){
		Log("j == %d...\n", j);
		mystrcpy(local_str, STR_EMPTY, SMALL);
		switch(j){
			case OPT_0_SPECIALNE:		strcat(local_str, STR_MODL_OPT_0); break;
			case OPT_1_CASTI_MODLITBY:	strcat(local_str, STR_MODL_OPT_1); break;
			case OPT_2_HTML_EXPORT:		strcat(local_str, STR_MODL_OPT_2); break;
			case OPT_3_SPOLOCNA_CAST:	strcat(local_str, STR_MODL_OPT_3); break;
			case OPT_4_OFFLINE_EXPORT:	strcat(local_str, STR_MODL_OPT_4); break;
			case OPT_5_ALTERNATIVES:	strcat(local_str, STR_MODL_OPT_5); break;
		}// switch(j)
		// premenná MODL_OPTj (nepovinná), j = 0 až POCET_GLOBAL_OPT - 1
		i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
		Log("pokúšam sa zistiť hodnotu parametra %s... parseQueryString()\n", local_str);
		while((equalsi(pom_MODL_OPT[j], STR_EMPTY)) && (i < pocet)){
			// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
			if(equals(param[i].name, local_str)){
				// ide o parameter STR_MODL_OPTj
				mystrcpy(pom_MODL_OPT[j], param[i].val, SMALL);
				Log("hodnota parametra %s je %s.\n", local_str, pom_MODL_OPT[j]);
			}
			i++;
		}
		if(equalsi(pom_MODL_OPT[j], STR_EMPTY)){
			Log("Nebola zadaná premenná %s (nevadí).\n", local_str);
		}
	}// for j

	// FORCE options
	for(j = 0; j < POCET_GLOBAL_OPT; j++){
		Log("j == %d...\n", j);
		mystrcpy(local_str, STR_EMPTY, SMALL);
		switch(j){
			case OPT_0_SPECIALNE:		strcat(local_str, STR_MODL_OPTF_0); break;
			case OPT_1_CASTI_MODLITBY:	strcat(local_str, STR_MODL_OPTF_1); break;
			case OPT_2_HTML_EXPORT:		strcat(local_str, STR_MODL_OPTF_2); break;
			case OPT_3_SPOLOCNA_CAST:	strcat(local_str, STR_MODL_OPTF_3); break;
			case OPT_4_OFFLINE_EXPORT:	strcat(local_str, STR_MODL_OPTF_4); break;
			case OPT_5_ALTERNATIVES:	strcat(local_str, STR_MODL_OPTF_5); break;
		}// switch(j)
		// premenná MODL_OPTFj (nepovinná), j = 0 až 9
		i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
		Log("pokúšam sa zistiť hodnotu parametra %s... parseQueryString(), force\n", local_str);
		while((equalsi(pom_MODL_OPTF[j], STR_EMPTY)) && (i < pocet)){
			// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
			if(equals(param[i].name, local_str)){
				// ide o parameter STR_MODL_OPTFj
				mystrcpy(pom_MODL_OPTF[j], param[i].val, SMALL);
				Log("hodnota parametra %s je %s.\n", local_str, pom_MODL_OPTF[j]);
			}
			i++;
		}
		if(equalsi(pom_MODL_OPTF[j], STR_EMPTY)){
			Log("Nebola zadaná premenná %s (nevadí).\n", local_str);
		}
	}// for j

	// 2011-04-13: force option 0 premenné -- jednotlivé bit-komponenty
	// 2013-11-26: Pre POST query sa tam hodnota priliepa pre jednotlivý check-box zo začiatku (rovnako ako kalendár), aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards) (rovnako ako kalendár), ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), 
	//             nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	Log("force option %d, jednotlivé bit-komponenty...(parseQuery)\n", OPT_0_SPECIALNE);
	for(j = 0; j < POCET_OPT_0_SPECIALNE; j++){
		Log("j == %d...\n", j);
		mystrcpy(local_str, STR_EMPTY, SMALL);
		switch(j){
			case 0: strcat(local_str, STR_MODL_OPTF_0_VERSE); break; // BIT_OPT_0_VERSE
			case 1: strcat(local_str, STR_MODL_OPTF_0_REF); break; // BIT_OPT_0_REFERENCIE
			case 2: strcat(local_str, STR_MODL_OPTF_0_CIT); break; // BIT_OPT_0_CITANIA
			case 3: strcat(local_str, STR_MODL_OPTF_0_ZJAV_NED); break; // BIT_OPT_0_ZJAVENIE_PANA_NEDELA
			case 4: strcat(local_str, STR_MODL_OPTF_0_NAN_NED); break; // BIT_OPT_0_NANEBOVSTUPNENIE_NEDELA
			case 5: strcat(local_str, STR_MODL_OPTF_0_TK_NED); break; // BIT_OPT_0_TELAKRVI_NEDELA
			case 6: strcat(local_str, STR_MODL_OPTF_0_FONT_NORMAL); break; // BIT_OPT_0_FONT_NORMAL
			case 7: strcat(local_str, STR_MODL_OPTF_0_BUTTONS_ORDER); break; // BIT_OPT_0_BUTTONS_ORDER
			case 8: strcat(local_str, STR_MODL_OPTF_0_BLIND_FRIENDLY); break; // BIT_OPT_0_BLIND_FRIENDLY
		}// switch(j)
		// premenná WWW_MODL_OPTF_0_... (nepovinná), j = 0 až POCET_OPT_0_SPECIALNE
		i = pocet; // backwards; param[0] by mal síce obsahovať query type, ale radšej kontrolujeme až po 0
		Log("pokúšam sa zistiť hodnotu parametra %s... parseQueryString(), force, bit-komponenty 0 / pom_MODL_OPTF_SPECIALNE[%d] = %s\n", local_str, j, pom_MODL_OPTF_SPECIALNE[j]);
		while((equalsi(pom_MODL_OPTF_SPECIALNE[j], STR_EMPTY)) && (i > 0)){
			--i;
			// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
			if(equals(param[i].name, local_str)){
				// ide o parameter STR_MODL_OPTFj
				mystrcpy(pom_MODL_OPTF_SPECIALNE[j], param[i].val, SMALL);
				Log("hodnota parametra %s je %s.\n", local_str, pom_MODL_OPTF_SPECIALNE[j]);
			}
		}
		if(equalsi(pom_MODL_OPTF_SPECIALNE[j], STR_EMPTY)){
			Log("Nebola zadaná premenná %s (nevadí).\n", local_str);
		}
	}// for j

	// 2011-04-11: force option 1 premenné -- jednotlivé bit-komponenty
	// 2013-11-26: Pre POST query sa tam hodnota priliepa pre jednotlivý check-box zo začiatku (rovnako ako kalendár), aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards) (rovnako ako kalendár), ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), 
	//             nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	Log("force option %d, jednotlivé bit-komponenty...(parseQuery)\n", OPT_1_CASTI_MODLITBY);
	for(j = 0; j < POCET_OPT_1_CASTI_MODLITBY; j++){
		Log("j == %d...\n", j);
		mystrcpy(local_str, STR_EMPTY, SMALL);
		switch(j){
			case 0: strcat(local_str, STR_MODL_OPTF_1_TD); break; // BIT_OPT_1_TEDEUM
			case 1: strcat(local_str, STR_MODL_OPTF_1_RUB); break; // BIT_OPT_1_RUBRIKY
			case 2: strcat(local_str, STR_MODL_OPTF_1_CHV); break; // BIT_OPT_1_CHVALOSPEVY
			case 3: strcat(local_str, STR_MODL_OPTF_1_SL); break; // BIT_OPT_1_SLAVA_OTCU
			case 4: strcat(local_str, STR_MODL_OPTF_1_OT); break; // BIT_OPT_1_OTCENAS
			case 5: strcat(local_str, STR_MODL_OPTF_1_MCD_DOPLNKOVA); break; // BIT_OPT_1_MCD_DOPLNKOVA
			case 6: strcat(local_str, STR_MODL_OPTF_1_VIGILIA); break; // BIT_OPT_1_PC_VIGILIA
			case 7: strcat(local_str, STR_MODL_OPTF_1_SPOMIENKA_SPOL_CAST); break; // BIT_OPT_1_SPOMIENKA_SPOL_CAST
			case 8: strcat(local_str, STR_MODL_OPTF_1_PLNE_RESP); break; // BIT_OPT_1_PLNE_RESP
			case 9: strcat(local_str, STR_MODL_OPTF_1_ZALM95); break; // BIT_OPT_1_ZALM95
			case 10: strcat(local_str, STR_MODL_OPTF_1_PROSBY_ZVOLANIE); break; // BIT_OPT_1_PROSBY_ZVOLANIE
			case 11: strcat(local_str, STR_MODL_OPTF_1_SKRY_POPIS); break; // BIT_OPT_1_SKRY_POPIS
			case 12: strcat(local_str, STR_MODL_OPTF_1_ZOBRAZ_SPOL_CAST); break; // BIT_OPT_1_ZOBRAZ_SPOL_CAST
			case 13: strcat(local_str, STR_MODL_OPTF_1_VESP_KRATSIE_PROSBY); break; // BIT_OPT_1_VESP_KRATSIE_PROSBY
			case 14: strcat(local_str, STR_MODL_OPTF_1_MCD_ZALTAR_TRI); break; // BIT_OPT_1_MCD_ZALTAR_TRI
		}// switch(j)
		// premenná WWW_MODL_OPTF_1_... (nepovinná), j = 0 až POCET_OPT_1_CASTI_MODLITBY
		i = pocet; // backwards; param[0] by mal síce obsahovať query type, ale radšej kontrolujeme až po 0
		Log("pokúšam sa zistiť hodnotu parametra %s... parseQueryString(), force, bit-komponenty 1 / pom_MODL_OPTF_CASTI_MODLITBY[%d] == %s\n", local_str, j, pom_MODL_OPTF_CASTI_MODLITBY[j]);
		while((equalsi(pom_MODL_OPTF_CASTI_MODLITBY[j], STR_EMPTY)) && (i > 0)){
			--i;
			// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
			if(equals(param[i].name, local_str)){
				// ide o parameter STR_MODL_OPTFj
				mystrcpy(pom_MODL_OPTF_CASTI_MODLITBY[j], param[i].val, SMALL);
				Log("hodnota parametra %s je %s.\n", local_str, pom_MODL_OPTF_CASTI_MODLITBY[j]);
			}
		}
		if(equalsi(pom_MODL_OPTF_CASTI_MODLITBY[j], STR_EMPTY)){
			Log("Nebola zadaná premenná %s (nevadí).\n", local_str);
		}
	}// for j

	// 2011-04-20: force option 2 premenné -- jednotlivé bit-komponenty
	// 2013-11-26: Pre POST query sa tam hodnota priliepa pre jednotlivý check-box zo začiatku (rovnako ako kalendár), aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards) (rovnako ako kalendár), ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), 
	//             nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	Log("force option %d, jednotlivé bit-komponenty...(parseQuery)\n", OPT_2_HTML_EXPORT);
	for(j = 0; j < POCET_OPT_2_HTML_EXPORT; j++){
		Log("j == %d...\n", j);
		mystrcpy(local_str, STR_EMPTY, SMALL);
		switch(j){
			case 0: strcat(local_str, STR_MODL_OPTF_2_ISO_DATUM); break; // BIT_OPT_2_ISO_DATUM
			case 1: strcat(local_str, STR_MODL_OPTF_2_PRVE_VESPERY); break; // BIT_OPT_2_BUTTON_PRVE_VESPERY
			case 2: strcat(local_str, STR_MODL_OPTF_2_FONT_FAMILY); break; // BIT_OPT_2_FONT_FAMILY
			case 3: strcat(local_str, STR_MODL_OPTF_2_FONT_NAME_CHOOSER); break; // BIT_OPT_2_FONT_NAME_CHOOSER
			// case 4: strcat(local_str, STR_MODL_OPTF_2_FONT_SIZE); break; // BIT_OPT_2_FONT_SIZE_CHOOSER
			case 5: strcat(local_str, STR_MODL_OPTF_2_NAVIGATION); break; // BIT_OPT_2_NAVIGATION
			case 6: strcat(local_str, STR_MODL_OPTF_2_TEXT_WRAP); break; // BIT_OPT_2_TEXT_WRAP
			case 7: strcat(local_str, STR_MODL_OPTF_2_BUTTONY_USPORNE); break; // BIT_OPT_2_BUTTONY_USPORNE
			case 8: strcat(local_str, STR_MODL_OPTF_2_NOCNY_REZIM); break; // BIT_OPT_2_NOCNY_REZIM
			case 9: strcat(local_str, STR_MODL_OPTF_2_ROZNE_MOZNOSTI); break; // BIT_OPT_2_ROZNE_MOZNOSTI
			case 10: strcat(local_str, STR_MODL_OPTF_2_HIDE_NAVIG_BUTTONS); break; // BIT_OPT_2_HIDE_NAVIG_BUTTONS
			case 11: strcat(local_str, STR_MODL_OPTF_2_HIDE_KALENDAR); break; // BIT_OPT_2_HIDE_KALENDAR
			case 12: strcat(local_str, STR_MODL_OPTF_2_HIDE_OPTIONS1); break; // BIT_OPT_2_HIDE_OPTIONS1
			case 13: strcat(local_str, STR_MODL_OPTF_2_HIDE_OPTIONS2); break; // BIT_OPT_2_HIDE_OPTIONS2
			case 14: strcat(local_str, STR_MODL_OPTF_2_ALTERNATIVES); break; // BIT_OPT_2_ALTERNATIVES
		}// switch(j)
		// premenná WWW_MODL_OPT_2_... (nepovinná), j = 0 až POCET_OPT_2_HTML_EXPORT
		i = pocet; // backwards; param[0] by mal síce obsahovať query type, ale radšej kontrolujeme až po 0
		Log("pokúšam sa zistiť hodnotu parametra %s... parseQueryString(), force, bit-komponenty 2 / pom_MODL_OPTF_HTML_EXPORT[%d] = %s\n", local_str, j, pom_MODL_OPTF_HTML_EXPORT[j]);
		while((equalsi(pom_MODL_OPTF_HTML_EXPORT[j], STR_EMPTY)) && (i > 0)){
			--i;
			// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
			if(equals(param[i].name, local_str)){
				// ide o parameter STR_MODL_OPTFj
				mystrcpy(pom_MODL_OPTF_HTML_EXPORT[j], param[i].val, SMALL);
				Log("hodnota parametra %s je %s.\n", local_str, pom_MODL_OPTF_HTML_EXPORT[j]);
			}
		}
		if(equalsi(pom_MODL_OPTF_HTML_EXPORT[j], STR_EMPTY)){
			Log("Nebola zadaná premenná %s (nevadí).\n", local_str);
		}
	}// for j

	// 2013-01-29: force option 5 premenné -- jednotlivé bit-komponenty
	// 2013-11-26: Pre POST query sa tam hodnota priliepa pre jednotlivý check-box zo začiatku (rovnako ako kalendár), aj sa číta z form-ulára (t. j. pri výbere z qt=pdnes), 
	//             preto čítam "odzadu", "zozadu" (backwards) (rovnako ako kalendár), ak by sa nešlo smerom "dolu" (t. j. k prvému parametru od konca), 
	//             nefungovalo by "override" z tabuľky "Voľby vybraných detailov", ak už v query stringu nejaká hodnota je
	Log("force option %d, jednotlivé bit-komponenty...(parseQuery)\n", OPT_5_ALTERNATIVES);
	for(j = 0; j < POCET_OPT_5_ALTERNATIVES; j++){
		Log("j == %d...\n", j);
		mystrcpy(local_str, STR_EMPTY, SMALL);
		switch(j){
			case 0: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_KOMPL); break; // BIT_OPT_5_HYMNUS_KOMPL
			case 1: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_PC); break; // BIT_OPT_5_HYMNUS_PC
			case 2: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_PREDPOL); break; // BIT_OPT_5_HYMNUS_MCD_PREDPOL
			case 3: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_NAPOL); break; // BIT_OPT_5_HYMNUS_MCD_NAPOL
			case 4: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_MCD_POPOL); break; // BIT_OPT_5_HYMNUS_MCD_POPOL
			case 5: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_122_129); break; // BIT_OPT_5_DOPLNK_PSALM_122_129
			case 6: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_127_131); break; // BIT_OPT_5_DOPLNK_PSALM_127_131
			case 7: strcat(local_str, STR_MODL_OPTF_5_DOPLNK_PSALM_126_129); break; // BIT_OPT_5_DOPLNK_PSALM_126_129
			case 8: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_PC); break; // BIT_OPT_5_HYMNUS_VN_PC
			case 9: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_RCH); break; // BIT_OPT_5_HYMNUS_VN_RCH
			case 10: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_VN_VESP); break; // BIT_OPT_5_HYMNUS_VN_VESP
			case 11: strcat(local_str, STR_MODL_OPTF_5_HYMNUS_1VESP); break; // BIT_OPT_5_HYMNUS_1VESP
		}// switch(j)
		// premenná WWW_MODL_OPTF_5_... (nepovinná), j = 0 až POCET_OPT_5_ALTERNATIVES
		i = pocet; // backwards; param[0] by mal síce obsahovať query type, ale radšej kontrolujeme až po 0
		Log("pokúšam sa zistiť hodnotu parametra %s... parseQueryString(), force, bit-komponenty 5 / pom_MODL_OPTF_ALTERNATIVES[%d] = %s\n", local_str, j, pom_MODL_OPTF_ALTERNATIVES[j]);
		while((equalsi(pom_MODL_OPTF_ALTERNATIVES[j], STR_EMPTY)) && (i > 0)){
			--i;
			// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
			if(equals(param[i].name, local_str)){
				// ide o parameter STR_MODL_OPTFj
				mystrcpy(pom_MODL_OPTF_ALTERNATIVES[j], param[i].val, SMALL);
				Log("hodnota parametra %s je %s.\n", local_str, pom_MODL_OPTF_ALTERNATIVES[j]);
			}
		}
		if(equalsi(pom_MODL_OPTF_ALTERNATIVES[j], STR_EMPTY)){
			Log("Nebola zadaná premenná %s (nevadí).\n", local_str);
		}
	}// for j

	// 2013-07-31: presunuté sem spred parsovania option premenných
	if(ok != ANO){
		// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
		// ani jeden z parametrov neobsahuje query type alebo obsahuje neznámy qt
		if(i >= pocet)
			mystrcpy(errmsg, "Chýbajúci parameter pre query type.\n", SMALL);
		else // síce bol query type parameter, ale hodnota je chybná
			sprintf(errmsg, "Chybný parameter: %s\n", param[i - 1].name);
		strcat(bad_param_str, errmsg);
		ret = FAILURE;
		goto END_parseQueryString;
	}

	Log("\tswitch(query_type)...\n");
	switch(query_type){
		case PRM_DNES:{
			// 2006-02-10: doplnené kvôli tomu, aby aj pre PRM_DNES mohla byť modlitba resp. svätec
			Log("\tcase PRM_DNES...\n");
			// nasledujúca pasáž prevzatá a upravená podľa PRM_DATUM; opätovne 2006-08-01

			// premenná MODLITBA (nepovinná)
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					// ide o parameter STR_MODLITBA
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				Log("Nebola zadaná premenná %s (nevadí).\n", STR_MODLITBA);
			}

			// premenná DALSI_SVATY (nepovinná)
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_DALSI_SVATY);
			while((equalsi(pom_DALSI_SVATY, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DALSI_SVATY)){
					// ide o parameter STR_DALSI_SVATY
					mystrcpy(pom_DALSI_SVATY, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DALSI_SVATY, pom_DALSI_SVATY);
				}
				i++;
			}
			if(equalsi(pom_DALSI_SVATY, STR_EMPTY)){
				Log("Nebola zadaná premenná %s (nevadí).\n", STR_DALSI_SVATY);
			}

			break; // case
		}// PRM_DNES

		case PRM_STATIC_TEXT:{
			// 2014-10-09: doplnené kvôli možnosti includovať statický text/ordinárium
			Log("\tcase PRM_STATIC_TEXT...\n");

			// premenná STATIC_TEXT
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_STATIC_TEXT);
			while((equalsi(pom_STATIC_TEXT, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_STATIC_TEXT)){
					// ide o parameter STR_NAZOV_SVIATOK
					mystrcpy(pom_STATIC_TEXT, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_STATIC_TEXT, pom_STATIC_TEXT);
				}
				i++;
			}
			if(equalsi(pom_STATIC_TEXT, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_STATIC_TEXT);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná MODL_ORDINARIUM (nepovinná)
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_MODL_ORDINARIUM);
			while((equalsi(pom_MODL_ORDINARIUM, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_ORDINARIUM)){
					// ide o parameter STR_NAZOV_SVIATOK
					mystrcpy(pom_MODL_ORDINARIUM, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_ORDINARIUM, pom_MODL_ORDINARIUM);
				}
				i++;
			}
			if(equalsi(pom_MODL_ORDINARIUM, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s (nevadí).\n", STR_MODL_ORDINARIUM);
			}

			break; // case
		}// PRM_STATIC_TEXT

		case PRM_DETAILY:
			// presne to iste co PRM_DATUM s jedinkym rozdielom: co sa tyka formularov, prvy (uvodny) formular pre PRM_DATUM vycisti modlitbu 
			// (premenna pom_MODLITBA, ktora sa nacita zo systemovej premennej WWW_MODLITBA) -- pretoze z inej casti fomrulara sa tam nieco dostane...
		case PRM_TXT: 
			// 2011-02-02: doplnené
		case PRM_XML: 
			// 2012-10-16: doplnené
		case PRM_DATUM:{
		// pripad, ze ide o datum

		// treba dodrzat presne poradie v query stringu;
		//   '()' znaci optional,
		//   '[]' znaci vyssie uvedeny typ dotazu.
		// ----------------------------------------------
		// 2005-03-22: pridane dalsie vyznamy opt_1 a opt_2
		// ----------------------------------------------
		// 0: [query type]
		// 1: den          / rok from
		// 2: mesiac       / rok to
		// 3: rok          / (linky) -- tieto tri `alternativne' parametre pre typ dotazu case PRM_TABULKA:, vid nizsie
		// 4: (modlitba)
		// 5: (dalsi svaty) - poradie svateho
		// 6 a viac: options
		// ---------------------------------------------
		// 2006-02-10: pridané možnosti vymeneného poradia a nezadania niektorých options
		// ----------------------------------------------
		// na základe dodania case-u pre PRM_DNES
		// ---------------------------------------------
		// 2006-08-01: dynamické zisťovanie hodnôt parametrov
		// ----------------------------------------------

			// premenná DEN
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_DEN);
			while((equalsi(pom_DEN, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DEN)){
					// ide o parameter STR_DEN
					mystrcpy(pom_DEN, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DEN, pom_DEN);
				}
				i++;
			}
			if(equalsi(pom_DEN, STR_EMPTY) && query_type != PRM_XML){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_DEN);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná MESIAC 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_MESIAC);
			while((equalsi(pom_MESIAC, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MESIAC)){
					// ide o parameter STR_MESIAC
					mystrcpy(pom_MESIAC, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MESIAC, pom_MESIAC);
				}
				i++;
			}
			if(equalsi(pom_MESIAC, STR_EMPTY) && query_type != PRM_XML){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_MESIAC);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná ROK
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_ROK);
			while((equalsi(pom_ROK, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK)){
					// ide o parameter STR_ROK
					mystrcpy(pom_ROK, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK, pom_ROK);
				}
				i++;
			}
			if(equalsi(pom_ROK, STR_EMPTY) && query_type != PRM_XML){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_ROK);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná MODLITBA (nepovinná)
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					// ide o parameter STR_MODLITBA
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				Log("Nebola zadaná premenná %s (nevadí).\n", STR_MODLITBA);
			}

			// premenná DALSI_SVATY (nepovinná)
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_DALSI_SVATY);
			while((equalsi(pom_DALSI_SVATY, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DALSI_SVATY)){
					// ide o parameter STR_DALSI_SVATY
					mystrcpy(pom_DALSI_SVATY, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DALSI_SVATY, pom_DALSI_SVATY);
				}
				i++;
			}
			if(equalsi(pom_DALSI_SVATY, STR_EMPTY)){
				Log("Nebola zadaná premenná %s (nevadí).\n", STR_DALSI_SVATY);
			}
			
			// 2013-08-01: pre XML export, ak nie je vyplnený deň, mesiac alebo rok, použije sa dnešný dátum
			if((query_type == PRM_XML) && (equalsi(pom_DEN, STR_EMPTY) || equalsi(pom_MESIAC, STR_EMPTY) || equalsi(pom_ROK, STR_EMPTY))){
				struct tm dnes = _get_dnes();
				sprintf(pom_DEN, "%d", dnes.tm_mday);
				sprintf(pom_MESIAC, "%d", dnes.tm_mon);
				sprintf(pom_ROK, "%d", dnes.tm_year);
			}

			break; // case
		}// PRM_DETAILY | PRM_TXT | PRM_XML | PRM_DATUM

		case PRM_CEZ_ROK:{
		// pripad, ze ide o tyzden cez rok

			// premenná DEN_V_TYZDNI 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_DEN_V_TYZDNI);
			while((equalsi(pom_DEN_V_TYZDNI, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DEN_V_TYZDNI)){
					// ide o parameter STR_DEN_V_TYZDNI
					mystrcpy(pom_DEN_V_TYZDNI, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DEN_V_TYZDNI, pom_DEN_V_TYZDNI);
				}
				i++;
			}
			if(equalsi(pom_DEN_V_TYZDNI, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_DEN_V_TYZDNI);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná TYZDEN 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_TYZDEN);
			while((equalsi(pom_TYZDEN, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_TYZDEN)){
					// ide o parameter STR_TYZDEN
					mystrcpy(pom_TYZDEN, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_TYZDEN, pom_TYZDEN);
				}
				i++;
			}
			if(equalsi(pom_TYZDEN, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_TYZDEN);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná MODLITBA 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					// ide o parameter STR_MODLITBA
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_MODLITBA);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			break; // case
		}// PRM_CEZ_ROK

		case PRM_LIT_OBD:{
			// 2011-01-25: doplnené; prípad, že ide o výber dňa v liturgickom období

			// premenná DEN_V_TYZDNI
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_DEN_V_TYZDNI);
			while((equalsi(pom_DEN_V_TYZDNI, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DEN_V_TYZDNI)){
					// ide o parameter STR_DEN_V_TYZDNI
					mystrcpy(pom_DEN_V_TYZDNI, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DEN_V_TYZDNI, pom_DEN_V_TYZDNI);
				}
				i++;
			}
			if(equalsi(pom_DEN_V_TYZDNI, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_DEN_V_TYZDNI);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná TYZDEN 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_TYZDEN);
			while((equalsi(pom_TYZDEN, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_TYZDEN)){
					// ide o parameter STR_TYZDEN
					mystrcpy(pom_TYZDEN, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_TYZDEN, pom_TYZDEN);
				}
				i++;
			}
			if(equalsi(pom_TYZDEN, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_TYZDEN);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná MODLITBA 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					// ide o parameter STR_MODLITBA
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_MODLITBA);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná LIT_OBD 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_LIT_OBD);
			while((equalsi(pom_LIT_OBD, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_LIT_OBD)){
					// ide o parameter STR_LIT_OBD
					mystrcpy(pom_LIT_OBD, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_LIT_OBD, pom_LIT_OBD);
				}
				i++;
			}
			if(equalsi(pom_LIT_OBD, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_LIT_OBD);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná LIT_ROK
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_LIT_ROK);
			while((equalsi(pom_LIT_ROK, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_LIT_ROK)){
					// ide o parameter STR_LIT_ROK
					mystrcpy(pom_LIT_ROK, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_LIT_ROK, pom_LIT_ROK);
				}
				i++;
			}
			if(equalsi(pom_LIT_ROK, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_LIT_ROK);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			break; // case
		}// PRM_LIT_OBD

		case PRM_SVIATOK:{
		// pripad, ze ide o sviatok

			// premenná NAZOV_SVIATOK 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_NAZOV_SVIATOK);
			while((equalsi(pom_SVIATOK, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_NAZOV_SVIATOK)){
					// ide o parameter STR_NAZOV_SVIATOK
					mystrcpy(pom_SVIATOK, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_NAZOV_SVIATOK, pom_SVIATOK);
				}
				i++;
			}
			if(equalsi(pom_SVIATOK, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_NAZOV_SVIATOK);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			break; // case
		}// PRM_SVIATOK

		case PRM_ANALYZA_ROKU:{
		// prípad, že ide o analýzu roka

			// premenná ANALYZA_ROKU 
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_ANALYZA_ROKU);
			while((equalsi(pom_ANALYZA_ROKU, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ANALYZA_ROKU)){
					// ide o parameter STR_ANALYZA_ROKU
					mystrcpy(pom_ANALYZA_ROKU, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ANALYZA_ROKU, pom_ANALYZA_ROKU);
				}
				i++;
			}
			if(equalsi(pom_ANALYZA_ROKU, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_ANALYZA_ROKU);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			break; // case
		}// PRM_ANALYZA_ROKU

		case PRM_MESIAC_ROKA:{
		// pripad, ze ide o mesiac roka

			// premenná MESIAC
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_MESIAC_ROKA);
			while((equalsi(pom_MESIAC, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MESIAC_ROKA)){
					// ide o parameter STR_MESIAC_ROKA
					mystrcpy(pom_MESIAC, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MESIAC_ROKA, pom_MESIAC);
				}
				i++;
			}
			if(equalsi(pom_MESIAC, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_MESIAC_ROKA);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná ROK
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_ROK_ROKA);
			while((equalsi(pom_ROK, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK_ROKA)){
					// ide o parameter STR_ROK_ROKA
					mystrcpy(pom_ROK, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK_ROKA, pom_ROK);
				}
				i++;
			}
			if(equalsi(pom_ROK, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_ROK_ROKA);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			break; // case
		}// PRM_MESIAC_ROKA

		case PRM_TABULKA:{
		// pripad, ze ide o tabulku pohyblivych slaveni

			// premenná ROK_FROM
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_ROK_FROM);
			while((equalsi(pom_ROK_FROM, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK_FROM)){
					// ide o parameter STR_ROK_FROM
					mystrcpy(pom_ROK_FROM, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK_FROM, pom_ROK_FROM);
				}
				i++;
			}
			if(equalsi(pom_ROK_FROM, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_ROK_FROM);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná ROK_TO
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_ROK_TO);
			while((equalsi(pom_ROK_TO, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK_TO)){
					// ide o parameter STR_ROK_TO
					mystrcpy(pom_ROK_TO, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK_TO, pom_ROK_TO);
				}
				i++;
			}
			if(equalsi(pom_ROK_TO, STR_EMPTY)){
				// 2013-07-31: samotné vypísanie niečoho presunuté do hlavnej funkcie
				sprintf(errmsg, "Nebola zadaná premenná %s.\n", STR_ROK_TO);
				strcat(bad_param_str, errmsg);
				ret = FAILURE;
				goto END_parseQueryString;
			}

			// premenná TABULKA_LINKY (nepovinná)
			i = 0; // param[0] by mal síce obsahovať query type, ale radšej kontrolujeme od 0
			Log("pokúšam sa zistiť hodnotu parametra %s...\n", STR_TABULKA_LINKY);
			while((equalsi(pom_LINKY, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_TABULKA_LINKY)){
					// ide o parameter STR_TABULKA_LINKY
					mystrcpy(pom_LINKY, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_TABULKA_LINKY, pom_LINKY);
				}
				i++;
			}
			if(equalsi(pom_LINKY, STR_EMPTY)){
				Log("Nebola zadaná premenná %s (nevadí).\n", STR_TABULKA_LINKY);
			}

			break; // case
		}// PRM_TABULKA
	}
	ret = SUCCESS;

END_parseQueryString:
	Log("parseQueryString() -- end, returning %d.\n", ret);
	return ret;
}// parseQueryString();

// KOMPILACIA -- idiotuv pruvodce kompilovanim tohoto gigantu

// nezabudni zmenit #define BUILD_DATE v mydefs.h! (2003-07-15)

// 17/02/2000A.D.: Segmentation fault pod linuxom;
// 18/02/2000A.D.:
// preto som prerobil _global_... (typov _struct...) na ..._ptr,
// ktore sa alokuju dynamicky a povodne mena su urobene ako symbolicke mena
// vsetko je to deklarovane v liturgia.h a definovane tu, v dnes.cpp
// 30/03/2000A.D.: pridane myconf.cpp a mydefs.cpp, premenovane dnes.cpp --> breviar.cpp
// 31/03/2000A.D.: pridane mystring.cpp (kvoli buffer overflow na webe)
// 2013-03-11: the following instructions are obsolete; see mysystem.h!!!
// teraz sa kompiluje a linkuje takto:
// DOS: Project --> obsahuje liturgia.cpp, dnes.cpp
// linux: file `urob'
/* ------------------------(begin of file `urob')
	chmod u=rwx *.*
	make
	cp uncgi uncgi.cgi
	g++ breviar.cpp dbzaltar.cpp liturgia.cpp mygetopt.cpp mylog.cpp myhpage.cpp myexpt.cpp cgiutils.cpp myconf.cpp mydefs.cpp mystring.cpp
	mv a.out l.cgi
	chmod u=rw *.c
	chmod u=rw *.cpp
	chmod u=rw *.h
	chmod oa+x *.cgi
 * ------------------------(end of file `urob')
 */
// 21/02/2000A.D.: vsetky inkludy, ktore su .h a .c[pp], som prerobil tak, aby sa inkludovali .h, kde su premenne iba (extern) deklarovane
// 2003-08-11: pouzil som pre g++ option -Wall, ktora pomohla odhalit niektore warningy

// POUCENIE
// z hladania Segmentation fault (segfault), 2003-08-11
// Dovod segfaultu
// -- bol ako obycajne v blbosti: int sa vypisovalo pomocou Export("...%s...");
// Priciny neodhalenia
// -- nespustal som linux-verziu pre Windows (parameter "-l1", ci vytvarat linky)
// Poucenie
// -- aj pod Windows kompilovat/spustat s option presne ako bezi na linuxe
// -- pozor na preklepy
// Zaver
// -- hlavne, ze uz je to za nami :)) duurko, 2003-08-11
// -- O.A.M.D.G.

//---------------------------------------------------------------------
// main();
//    hlavny program -- main routine
#define _main_LOG_to_Export_PARAMS {\
	_main_LOG_to_Export("\tparam1 == %s (pom_DEN/pom_SVIATOK/pom_DEN_V_TYZDNI), param1 == %s (pom_ROK_FROM resp. DEN DO pre batch mode)\n", pom_DEN, pom_ROK_FROM);\
	_main_LOG_to_Export("\tparam2 == %s (pom_MESIAC/pom_TYZDEN), param2 == %s (pom_ROK_TO resp. MESIAC DO pre batch mode)\n", pom_MESIAC, pom_ROK_TO);\
	_main_LOG_to_Export("\tparam3 == %s (pom_ROK/pom_ANALYZA_ROKU), param3 == %s (pom_LINKY)\n", pom_ROK, pom_LINKY);\
	_main_LOG_to_Export("\tparam4 == %s (pom_MODLITBA resp. ROK DO pre batch mode)\n", pom_MODLITBA);\
	_main_LOG_to_Export("\tparam5 == %s (pom_DALSI_SVATY)\n", pom_DALSI_SVATY);\
	_main_LOG_to_Export("\tparam11== %s (pom_MODL_OPT_APPEND)\n", pom_MODL_OPT_APPEND);\
	_main_LOG_to_Export("\tparam12== %s (pom_JAZYK)\n", pom_JAZYK);\
	_main_LOG_to_Export("\tparam  == %s (pom_KALENDAR)\n", pom_KALENDAR);\
	_main_LOG_to_Export("\tparam  == %s (pom_CSS)\n", pom_CSS);\
	_main_LOG_to_Export("\tparam  == %s (pom_FONT)\n", pom_FONT);\
	_main_LOG_to_Export("\tparam  == %s (pom_FONT_SIZE)\n", pom_FONT_SIZE);\
	_main_LOG_to_Export("\tparam  == %s (pom_MODL_OPT_DATE_FORMAT)\n", pom_MODL_OPT_DATE_FORMAT);\
	_main_LOG_to_Export("\tparam  == %s (pom_EXPORT_MONTHLY)\n", pom_EXPORT_MONTHLY);\
	for(i = 0; i < POCET_GLOBAL_OPT; i++){\
		_main_LOG_to_Export("\tparam  == %s (pom_MODL_OPT[%d])\n", pom_MODL_OPT[i], i);\
	}\
	for(i = 0; i < POCET_GLOBAL_OPT; i++){\
		_main_LOG_to_Export("\tparam  == %s (pom_MODL_OPTF[%d])\n", pom_MODL_OPTF[i], i);\
	}\
}

short int counter_setConfigDefaults = 0;

// 2011-04-13: vytvorené kvôli tomu, že config súbor nemusí obsahovať hodnoty pre všetky options
void setConfigDefaults(short int jazyk){
	short int sk_default, i;
	counter_setConfigDefaults++;
	Log("setConfigDefaults(%d) -- začiatok (%d. volanie)...\n", jazyk, counter_setConfigDefaults);
	// 2011-04-13: ak sú niektoré options GLOBAL_OPTION_NULL, je potrebné ich na niečo nastaviť
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		if(jazyk != JAZYK_SK)
			sk_default = cfg_option_default[i][JAZYK_SK];
		else
			sk_default = GLOBAL_OPTION_NULL;
		if(cfg_option_default[i][jazyk] == GLOBAL_OPTION_NULL){
			cfg_option_default[i][jazyk] = (sk_default == GLOBAL_OPTION_NULL)? cfg_option_default_PROG[i]: sk_default;
			Log("keďže cfg_option_default[%d][%d] bolo GLOBAL_OPTION_NULL, nastavujem podľa program defaults na %d...\n", i, jazyk, cfg_option_default[i][jazyk]);
		}
	}// for i
	Log("setConfigDefaults(%d) -- koniec (%d. volanie).\n", jazyk, counter_setConfigDefaults);
}// setConfigDefaults()

int breviar_main(int argc, char **argv){
	short int i;

	// 2011-04-20: naplnenie _global_system
#if defined(OS_linux)
	_global_system = SYSTEM_LINUX;
#elif defined(OS_Windows_Ruby)
	_global_system = SYSTEM_RUBY;
#else
	_global_system = SYSTEM_WINDOWS;
#endif
	// pretoze pocas behu win32-release verzie on-line breviara sa spusta main() viackrat bez zrusenia programu,
	// je potrebne inicializovat globalne premenne pri kazdom pusteni jej behu
	// 2009-08-05: prerobenie čítania jazyka (skopírované ešte na jedno vyššie miesto); už by sa <title> malo vypisovať pri generovaní inojazyčných modlitieb správne
	myhpage_init_globals();
	_global_opt[OPT_0_SPECIALNE] = GLOBAL_OPTION_NULL;
	_global_opt[OPT_1_CASTI_MODLITBY] = GLOBAL_OPTION_NULL;
	_global_opt[OPT_3_SPOLOCNA_CAST] = MODL_SPOL_CAST_NEURCENA;
	_global_opt[OPT_4_OFFLINE_EXPORT] = GLOBAL_OPTION_NULL;
	_global_opt[OPT_2_HTML_EXPORT] = GLOBAL_OPTION_NULL;
	counter_setConfigDefaults = 0;

	_global_opt_append = NIE;
	_global_opt_tedeum = NIE;
	_global_pocet_slava_otcu = 0;
	_global_ant_mcd_rovnake = NIE;
	_global_opt_export_date_format = EXPORT_DATE_SIMPLE;
	_global_opt_batch_monthly = NIE;
	_global_hlavicka_Export = 0;
	_global_patka_Export = 0;
	export_monthly_druh = 0;
	export_month_zaciatok = NIE;
	export_month_nova_modlitba = NIE;

	strcpy(pom_LIT_OBD, STR_EMPTY);
	strcpy(pom_LIT_ROK, STR_EMPTY);

	strcpy(pom_QUERY_TYPE, STR_EMPTY);
	strcpy(pom_DEN, STR_EMPTY);
	strcpy(pom_MESIAC, STR_EMPTY);
	strcpy(pom_ROK, STR_EMPTY);
	strcpy(pom_MODLITBA, STR_EMPTY);
	strcpy(pom_DALSI_SVATY, STR_EMPTY);
	strcpy(pom_ROK_FROM, STR_EMPTY);
	strcpy(pom_ROK_TO, STR_EMPTY);
	strcpy(pom_LINKY, STR_EMPTY);
	strcpy(pom_JAZYK, STR_EMPTY);
	strcpy(pom_CSS, STR_EMPTY);
	strcpy(pom_FONT, STR_EMPTY);
	strcpy(pom_FONT_SIZE, STR_EMPTY);
	strcpy(pom_MODL_OPT_DATE_FORMAT, STR_EMPTY);
	strcpy(pom_EXPORT_MONTHLY, STR_EMPTY); // 2009-08-03: Pridané kvôli rôznym spôsobom exportu po mesiacoch, prepínač -M
    _global_modlitba = MODL_NEURCENA;

    memset(_global_optf, 0, sizeof(_global_optf));
    memset(_global_opt_specialne, 0, sizeof(_global_opt_specialne));
    memset(_global_opt_casti_modlitby, 0, sizeof(_global_opt_casti_modlitby));
    memset(_global_opt_html_export, 0, sizeof(_global_opt_html_export));
    memset(_global_opt_offline_export, 0, sizeof(_global_opt_offline_export));
	memset(_global_opt_alternatives, 0, sizeof(_global_opt_alternatives));

    _global_jazyk = 0;
    _global_kalendar = 0;
	_global_ritus = 0;
    _global_css = 0;
    _global_font = 0;
    _global_font_size = 0;

	_global_pocet_navigacia = 0;
	_global_pocet_volani_interpretTemplate = 0;

    _global_pocet_zalmov_kompletorium = 0;

    strcpy(_global_export_navig_hore, DEFAULT_MONTH_EXPORT);
    strcpy(_global_export_navig_hore_month, DEFAULT_MONTH_EXPORT);
    strcpy(_global_export_navig_hore_day, DEFAULT_MONTH_EXPORT);
    strcpy(_global_css_font_family, DEFAULT_FONT_FAMILY_SERIF);
    strcpy(_global_css_font_size, STR_EMPTY);

    _global_skip_in_prayer = NIE;
    _global_skip_in_prayer_2 = NIE;
    _global_skip_in_prayer_vnpc = NIE;
	_global_som_vo_vigilii = NIE;

    params = 0;

    strcpy(pom_MODL_OPT_APPEND, STR_EMPTY);
    strcpy(pom_KALENDAR, STR_EMPTY);

    memset(pom_MODL_OPT, 0, sizeof(pom_MODL_OPT));
    memset(pom_MODL_OPTF, 0, sizeof(pom_MODL_OPTF));
    memset(pom_MODL_OPTF_SPECIALNE, 0, sizeof(pom_MODL_OPTF_SPECIALNE));
    memset(pom_MODL_OPTF_CASTI_MODLITBY, 0, sizeof(pom_MODL_OPTF_CASTI_MODLITBY));
    memset(pom_MODL_OPTF_HTML_EXPORT, 0, sizeof(pom_MODL_OPTF_HTML_EXPORT));
    memset(pom_MODL_OPTF_OFFLINE_EXPORT, 0, sizeof(pom_MODL_OPTF_OFFLINE_EXPORT));
    memset(pom_MODL_OPTF_ALTERNATIVES, 0, sizeof(pom_MODL_OPTF_ALTERNATIVES));

    strcpy(bad_param_str, STR_EMPTY);
    strcpy(file_export, STR_EMPTY);
    strcpy(include_dir, STR_EMPTY);
    strcpy(name_binary_executable, STR_EMPTY);
    strcpy(name_batch_file, STR_EMPTY);
    strcpy(name_batch_html_file, STR_EMPTY);
    strcpy(dir_name, STR_EMPTY);
    strcpy(name_batch_month_file, STR_EMPTY);
    strcpy(system_command, STR_EMPTY);

    memset(param, 0, sizeof(param));
    batch_file = NULL;
    batch_html_file = NULL;
    batch_month_file = NULL;
    index_pre_mesiac_otvoreny = NIE;

	_INIT_DM(_local_den);

	// koniec inicializacie globalnych premennych; teraz samotna main()

	// 2013-01-22: oprava inicializácie _global_linky
#if defined(BEHAVIOUR_WEB)
	_global_linky = 1; // zobrazovať linky (pre batch mód: použiť URL)
#elif defined(BEHAVIOUR_CMDLINE)
	_global_linky = 0; // nezobrazovať linky (pre batch mód: použiť filenames)
#else
	#error Unsupported behaviour (not defined in mysystem.h/mysysdef.h)
#endif

	short int ret, ret_pom = FAILURE; // návratová hodnota
	short int len; // dĺžka

	initLog(FILE_LOG);

	// 2005-03-29: Pridane kvoli debuggovaniu na obrazovku
	_main_LOG("Content-type: text/html\n");
	_main_LOG("\n");
	
	_main_LOG("-- log file programu pre Liturgiu hodín "TEXT_COPYRIGHT" --\n");

	_main_LOG("inicializácia poľa pom_MODL_OPT[]...\n");
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		mystrcpy(pom_MODL_OPT[i], STR_EMPTY, SMALL);
		// _main_LOG("pom_MODL_OPT[%d] == `%s'...\n", i, pom_MODL_OPT[i]);
	}// nastavenie pom_MODL_OPT[i]

	_main_LOG("inicializácia poľa pom_MODL_OPTF[]...\n");
	for(i = 0; i < POCET_GLOBAL_OPT; i++){
		mystrcpy(pom_MODL_OPTF[i], STR_EMPTY, SMALL);
		// _main_LOG("pom_MODL_OPTF[%d] == `%s'...\n", i, pom_MODL_OPTF[i]);
	}// nastavenie pom_MODL_OPTF[i]

	/*
	_main_LOG("spúšťam log_pom_MODL_OPT();...\n");
	log_pom_MODL_OPT();

	_main_LOG("spúšťam log_pom_MODL_OPTF();...\n");
	log_pom_MODL_OPTF();
	*/

	// config
	_main_LOG("first, reading configuration (file %s)...\n", CONFIG_FILE);

	_main_LOG("spúšťam readConfig();...\n");
	readConfig();
	// 2007-06-01: keďže pribúda mnoho konfiguračných parametrov, presunuli sme ich výpis do funkcie
	_main_LOG("spúšťam printConfig();...\n");
	printConfig();
	// 2004-03-17 na inom mieste sa upravuje include_dir - je to 2004-03-17_TUTOLA

	_main_LOG("spúšťam updateScriptName();...\n");
	updateScriptName();
	_main_LOG("script_name == %s\n", script_name);

	_main_LOG("spúšťam updateUnCGIName();...\n");
	updateUnCGIName();
	_main_LOG("uncgi_name == %s\n", uncgi_name);

	_main_LOG("spúšťam initExport();...\n");
	initExport();

	// pre query_string musime alokovat pamat
	_main_LOG("/* pre query_string musime alokovat pamat */\n");
	_main_LOG("now allocating memory...\n");

	// query_string
	if((query_string = (char*) malloc(MAX_QUERY_STR)) == NULL){
		_main_LOG("  Not enough memory to allocate buffer for `query_string'\n");
		goto _main_end;
	}
	else{
		_main_LOG("  %d bytes for `query_string'\n", MAX_QUERY_STR);
	}
	_main_LOG("...done.\n");

	// pridané 2005-08-01

	// _global_buf
	if((_global_buf = (char*) malloc(MAX_GLOBAL_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_buf'\n");
		goto _main_end;
	}
	else{
		_main_LOG("  %d bytes for `_global_buf'\n", MAX_GLOBAL_STR);
		mystrcpy(_global_buf, STR_EMPTY, MAX_GLOBAL_STR);
	}

	// _global_buf2
	if((_global_buf2 = (char*) malloc(MAX_GLOBAL_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_buf2'\n");
		goto _main_end;
	}
	else{
		_main_LOG("  %d bytes for `_global_buf2'\n", MAX_GLOBAL_STR);
		mystrcpy(_global_buf2, STR_EMPTY, MAX_GLOBAL_STR);
	}

	_main_LOG("spustatm getSrciptParamFrom(argc == %d)...\n", argc);
	params = getSrciptParamFrom(argc);
	// vysledok je, ze sa do params nacita bud
	// SCRIPT_PARAM_FROM_FORM alebo
	// SCRIPT_PARAM_FROM_QS alebo
	// SCRIPT_PARAM_FROM_ARGV;
	// ------------------------------ 01/02/2000A.D. ---
	//
	// ak vsak pouzivam aj query string, aj vysledky z formulara, vysledok bude predsa SCRIPT_PARAM_FROM_QS, lebo QS je neprazdny retazec; 
	// taku strategiu umoznuje uncgi.c:
	//        First, get the query string, wherever it is, and stick its component parts into the environment.
	//        Allow combination GET and POST queries, even though that's a bit strange.
	// takze v pripade, ze query string je neprazdny, treba
	// 1. zistit systemove premenne WWW_...
	// 2. zistit (a rozparsovat) QUERY_STRING

	ret = NO_RESULT;
	ret_pom = FAILURE;
	switch(params){
	// v tomto switch() naplnime premennu query_type a naviac (ak su) premenne pom_...
		case SCRIPT_PARAM_FROM_FORM:{
			_main_LOG_to_Export("params == SCRIPT_PARAM_FROM_FORM\n");
			// neboli zadane ziadne parametre, teda citam z formulara
			
			query_type = getQueryTypeFrom_WWW();
			// zistili sme, aky je typ dotazu
			if(query_type == PRM_NONE){
				// spusteny bez parametrov
				_main_LOG_to_Export("query_type == PRM_NONE\n");
				_main_LOG_to_Export("spustam _main_prazdny_formular();\n");
				_main_prazdny_formular();
				_main_LOG_to_Export("spat po skonceni _main_prazdny_formular()\n");
				goto _main_end;
			}
			else{
				_main_LOG_to_Export("spustam getForm();\n");
				ret_pom = ret = getForm();
				_main_LOG_to_Export("spat po skonceni getForm()\n");
			}
			break;
		}// SCRIPT_PARAM_FROM_FORM
		case SCRIPT_PARAM_FROM_ARGV:{
			_main_LOG("params == SCRIPT_PARAM_FROM_ARGV\n");
			_main_LOG("spustam getArgv();\n");
			// query_type sa nastavi priamo vovnutri
			ret_pom = ret = getArgv(argc, argv);
			if(ret == SUCCESS){ // 13/03/2000A.D. -- aby mohlo exportovat do file_export
				// 2006-07-12: pridané parsovanie jazyka kvôli jazykovým mutáciám 
				// 2009-08-05: predsunuté aj sem vyššie
				_main_LOG_to_Export("zisťujem jazyk (pom_JAZYK == %s)...\n", pom_JAZYK);
				_global_jazyk = atojazyk(pom_JAZYK);
				if(_global_jazyk == JAZYK_UNDEF){
					_global_jazyk = JAZYK_SK;
					_main_LOG_to_Export("\t(vzhľadom k neurčenému jazyku používam default)\n");
				}
				_main_LOG_to_Export("...jazyk (%s) = %i, teda %s (%s)\n", pom_JAZYK, _global_jazyk, nazov_jazyka[_global_jazyk], skratka_jazyka[_global_jazyk]);

				_main_LOG_to_Export("spúšťam setConfigDefaults()...\n");
				setConfigDefaults(_global_jazyk); // 2011-04-13: doplnené

				// 2013-01-08: sem presunuté volanie _rozparsuj_parametre_OPT(); kvôli tomu, že volanie hlavičky potrebuje už nastavené napr. o2 (batch mód, či použiť nočný režim)
				Log("volám _rozparsuj_parametre_OPT()... | case SCRIPT_PARAM_FROM_ARGV\n");
				_rozparsuj_parametre_OPT();

				// 2010-08-04: pridané parsovanie jazyka kvôli jazykovým mutáciám -- kalendár, napr. rehoľný (dané aj nižše, ako jazyk)
				_main_LOG_to_Export("zisťujem kalendár (pom_KALENDAR == %s)...\n", pom_KALENDAR);
				_global_kalendar = atokalendar(pom_KALENDAR);
				if(_global_kalendar == KALENDAR_NEURCENY){
					_global_kalendar = KALENDAR_VSEOBECNY;
					_main_LOG_to_Export("\t(vzhľadom k neurčenému kalendáru používam default -- všeobecný kalendár)\n");
				}
				_main_LOG_to_Export("...kalendár (%s) = %i, teda %s (%s)\n", pom_KALENDAR, _global_kalendar, nazov_kalendara_short[_global_kalendar], skratka_kalendara[_global_kalendar]);

				// 2011-05-06: Pridané načítanie názvu fontu kvôli rôznym fontom
				_main_LOG_to_Export("zisťujem font...\n");
				_global_font = atofont(pom_FONT);
				if(_global_font == FONT_UNDEF){
					_global_font = FONT_CSS;
					_main_LOG_to_Export("\t(vzhľadom k neurčenému fontu používam default -- brať font z CSS)\n");
				}
				_main_LOG_to_Export("...font (%s) = %i, teda %s\n", pom_FONT, _global_font, nazov_fontu[_global_font]);

				// 2011-05-13: Pridané načítanie veľkosti fontu
				_main_LOG_to_Export("zisťujem font size...\n");
				_global_font_size = atofontsize(pom_FONT_SIZE);
				if(_global_font_size == FONT_SIZE_UNDEF){
					_global_font_size = FONT_SIZE_CSS;
					_main_LOG_to_Export("\t(vzhľadom k neurčenej font size používam default -- brať font size z CSS)\n");
				}
				_main_LOG_to_Export("...font size (%s) = %i, teda %s\n", pom_FONT_SIZE, _global_font_size, nazov_font_size(_global_font_size));

				// 2013-12-12: Pridané načítanie css | podľa: 2008-08-08: Pridané načítanie css kvôli rôznym css
				_main_LOG_to_Export("zisťujem css...\n");
				_global_css = atocss(pom_CSS);
				if(_global_css == CSS_UNDEF){
					// 2012-04-03: doplnené default CSS pre daný jazyk
					_global_css = default_css_jazyk[_global_jazyk];
					if(_global_css == CSS_UNDEF){
						_global_css = CSS_breviar_sk;
						_main_LOG_to_Export("\t(vzhľadom k neurčenému CSS používam default)\n");
					}
					else{
						_main_LOG_to_Export("\t(vzhľadom k neurčenému CSS používam default pre daný jazyk)\n");
					}
				}
				_main_LOG_to_Export("...css (%s) = %i, teda %s (%s)\n", pom_CSS, _global_css, nazov_css[_global_css], skratka_css[_global_css]);

				Log("file_export == `%s'...\n", file_export);
				if(equals(file_export, STR_EMPTY) || equals(file_export, "+")){
					// "+" -- error, chce pridavat do nicoho
					Log("continuing to export in FILE_EXPORT (`%s')...\n", FILE_EXPORT);
				}
				else{
					// 2010-02-15, pridané: rozparsovanie parametra modlitba
					Log("volanie atomodlitba() z main()... [1]\n");
					_global_modlitba = atomodlitba(pom_MODLITBA);
					if(_global_opt_append == YES){
						// pridame na koniec nazvu suboru "+" aby to vedel initExport()
						strcat(file_export, "+");
						Log("budem appendovat (_global_opt_append == YES)...\n");
					}
					// a napokon puovodna pasaz pred 2003-07-08
					if(initExport(file_export) == SUCCESS){
						Log("initExport(`%s'): success\n", file_export);
						_main_LOG_to_Export("_global_jazyk == %s\n", nazov_jazyka[_global_jazyk]);
					}
					else{
						Log("initExport(`%s'): failure, \n", file_export);
						Log("continuing to export into DEFAULT_FILE_EXPORT (`%s')\n", DEFAULT_FILE_EXPORT);
						initExport(DEFAULT_FILE_EXPORT);
						_main_LOG_to_Export("_global_jazyk == %s\n", nazov_jazyka[_global_jazyk]);
					}
					_main_LOG_to_Export("volám hlavicka(); ... [case SCRIPT_PARAM_FROM_ARGV]\n");
					hlavicka((char *)html_title[_global_jazyk]);
				}
			}
			_main_LOG("spat po skonceni getArgv(); exporting to file `%s'...\n", FILE_EXPORT);

			if(query_type == PRM_SIMULACIA_QS){
				Log("jumping to _main_SIMULACIA_QS (query_string == %s)...\n", query_string);
				goto _main_SIMULACIA_QS;
			}

			break;
		}// SCRIPT_PARAM_FROM_ARGV
		case SCRIPT_PARAM_FROM_QS:{

			_main_LOG_to_Export("params == SCRIPT_PARAM_FROM_QS\n");
			// nasledujuca pasaz je tu preto, ze mozno bolo pouzite kombinovane aj query string, aj formular (teda treba citat aj systemove premenne WWW_...)

_main_SIMULACIA_QS:
			_main_LOG_to_Export("---getting query type from query string (query_string == %s):\n", query_string);
			query_type = getQueryTypeFrom_QS(query_string);
			_main_LOG_to_Export("---getting query type from query string: finished.\n");

			_main_LOG_to_Export("---parsing query string:\n");
			ret_pom = parseQueryString();
			_main_LOG_to_Export("---parsing query string: finished.\n");

			_main_LOG_to_Export("---query_type == %d\n", query_type);

			_main_LOG_to_Export("---scanning for system variables WWW_...: started...\n");
			// historicka poznamka:                          (01/02/2000A.D.)
			// kedysi tu tato pasaz (podla casti `case SCRIPT_PARAM_FROM_FORM') nebola, avsak pretoze to neumoznovalo `mixovane' dotazy
			// (ked je nieco v QS a navyse, uncgi.c vlozi (aj QS aj) ostatne veci z formulara do systemovych premennych WWW_...),
			// zmenili sme to tak, ze sa tu precitaju WWW_... a potom parsuje qs

			// 2005-03-28: Zmenene poradie. POST dotazy handlovane vyssie sposobom uncgi.
			_main_LOG_to_Export("spustam setForm();\n");
			ret = setForm();
			_main_LOG_to_Export("spat po skonceni setForm()\n");

			// query_type = getQueryTypeFrom_WWW();
			// zistili sme, aky je typ dotazu podla formulara
			if((ret == SUCCESS) && (query_type != PRM_NONE) && (query_type != PRM_UNKNOWN)){
				// znamena to teda, ze existuje systemova premenna, oznacujuca typ dotazu ==> treba nacitat z formulara resp. systemovych premennych WWW_...
				_main_LOG_to_Export("spustam getForm();\n");
				ret = getForm();
				_main_LOG_to_Export("params from system variables WWW_...:\n");
				_main_LOG_to_Export_PARAMS; // 2003-08-13, dane do #define
				_main_LOG_to_Export("spat po skonceni getForm()\n");
				_main_LOG_to_Export("2006-12-14: pom_MODLITBA == `%s'\n", pom_MODLITBA);
			}
			_main_LOG_to_Export("---scanning for system variables WWW_...:finished.\n");

			// 2012-07-23: doplnené; 2012-08-06(riso): Default jazyk chceme nastavit az po volani getForm, WWW_j sa pouziva na prepinanie jazyka v Androide.
			if(equalsi(pom_JAZYK, STR_EMPTY)){
				mystrcpy(pom_JAZYK, nazov_jazyka[JAZYK_SK], SMALL);
				Log("default jazyk (%s).\n", pom_JAZYK);
			}

			break;
		}// SCRIPT_PARAM_FROM_QS
	}// switch(params)

	_main_LOG_to_Export("query_type == ");
	switch(query_type){
		case PRM_UNKNOWN:		_main_LOG_to_Export("PRM_UNKNOWN\n"); break;
		case PRM_TABULKA:		_main_LOG_to_Export("PRM_TABULKA\n"); break;
		case PRM_TXT:			_main_LOG_to_Export("PRM_TXT\n"); break;
		case PRM_XML:			_main_LOG_to_Export("PRM_XML\n"); break;
		case PRM_STATIC_TEXT:	_main_LOG_to_Export("PRM_STATIC_TEXT\n"); break;
		case PRM_NONE:			_main_LOG_to_Export("PRM_NONE\n"); break;
		case PRM_DATUM:			_main_LOG_to_Export("PRM_DATUM\n"); break;
		case PRM_DETAILY:		_main_LOG_to_Export("PRM_DETAILY\n"); break;
		case PRM_CEZ_ROK:		_main_LOG_to_Export("PRM_CEZ_ROK\n"); break;
		case PRM_LIT_OBD:		_main_LOG_to_Export("PRM_LIT_OBD\n"); break;
		case PRM_ANALYZA_ROKU:	_main_LOG_to_Export("PRM_ANALYZA_ROKU\n"); break;
		case PRM_SVIATOK:		_main_LOG_to_Export("PRM_SVIATOK\n"); break;
		case PRM_MESIAC_ROKA:	_main_LOG_to_Export("PRM_MESIAC_ROKA\n"); break;
		case PRM_DNES:			_main_LOG_to_Export("PRM_DNES\n"); break;
		case PRM_BATCH_MODE:	_main_LOG_to_Export("PRM_BATCH_MODE\n"); break;
		default:				_main_LOG_to_Export("(sem by sa to nemalo dostať)\n"); break;
	}

	_main_LOG_to_Export_PARAMS;

	if(query_type == PRM_MESIAC_ROKA){
		mystrcpy(pom_DEN, STR_VSETKY_DNI, SMALL);
		query_type = PRM_DATUM;
	}

// BEGIN_presunutá_časť_2013_07_31
	// 2013-07-31: táto časť bola vnútri, if(query_type != PRM_UNKNOWN) ... if(ret == SUCCESS) | presunuté sem kvôli tomu, aby sa rozparsovali options, aj ak chýba napr. query_type

	// 2006-07-12: pridané parsovanie jazyka kvôli jazykovým mutáciám 
	// 2009-08-05: predsunuté vyššie (aj tu sme to pre istotu ponechali)
	_main_LOG_to_Export("zisťujem jazyk (pom_JAZYK == %s)...\n", pom_JAZYK);
	_global_jazyk = atojazyk(pom_JAZYK);
	if(_global_jazyk == JAZYK_UNDEF){
		_global_jazyk = JAZYK_SK;
		_main_LOG_to_Export("\t(vzhľadom k neurčenému jazyku používam default)\n");
	}
	_main_LOG_to_Export("...jazyk (%s) = %i, teda %s (%s)\n", pom_JAZYK, _global_jazyk, nazov_jazyka[_global_jazyk], skratka_jazyka[_global_jazyk]);

	_global_ritus = ritus_jazyka[_global_jazyk];

	_main_LOG_to_Export("spúšťam setConfigDefaults()...\n");
	setConfigDefaults(_global_jazyk); // 2011-04-13: doplnené
	// 2013-01-08: sem presunuté volanie _rozparsuj_parametre_OPT(); kvôli tomu, že volanie hlavičky potrebuje už nastavené napr. o2 (batch mód, či použiť nočný režim)
	Log("volám _rozparsuj_parametre_OPT()...\n");
	_rozparsuj_parametre_OPT();

	// 2010-08-04: pridané parsovanie jazyka kvôli jazykovým mutáciám -- kalendár, napr. rehoľný (dané aj vyššie, ako jazyk)
	_main_LOG_to_Export("zisťujem kalendár (pom_KALENDAR == %s)...\n", pom_KALENDAR);
	_global_kalendar = atokalendar(pom_KALENDAR);
	if(_global_kalendar == KALENDAR_NEURCENY){
		_global_kalendar = KALENDAR_VSEOBECNY;
		_main_LOG_to_Export("\t(vzhľadom k neurčenému kalendáru používam default -- všeobecný kalendár)\n");
	}
	_main_LOG_to_Export("...kalendár (%s) = %i, teda %s (%s)\n", pom_KALENDAR, _global_kalendar, nazov_kalendara_short[_global_kalendar], skratka_kalendara[_global_kalendar]);

	// 2011-05-06: Pridané načítanie názvu fontu kvôli rôznym fontom
	_main_LOG_to_Export("zisťujem font...\n");
	_global_font = atofont(pom_FONT);
	if(_global_font == FONT_UNDEF){
		_global_font = FONT_CSS;
		_main_LOG_to_Export("\t(vzhľadom k neurčenému fontu používam default -- brať font z CSS)\n");
	}
	_main_LOG_to_Export("...font (%s) = %i, teda %s\n", pom_FONT, _global_font, nazov_fontu[_global_font]);

	// 2011-05-13: Pridané načítanie veľkosti fontu
	_main_LOG_to_Export("zisťujem font size...\n");
	_global_font_size = atofontsize(pom_FONT_SIZE);
	if(_global_font_size == FONT_SIZE_UNDEF){
		_global_font_size = FONT_SIZE_CSS;
		_main_LOG_to_Export("\t(vzhľadom k neurčenej font size používam default -- brať font size z CSS)\n");
	}
	_main_LOG_to_Export("...font size (%s) = %i, teda %s\n", pom_FONT_SIZE, _global_font_size, nazov_font_size(_global_font_size));

	// 2008-08-08: Pridané načítanie css kvôli rôznym css
	_main_LOG_to_Export("zisťujem css...\n");
	_global_css = atocss(pom_CSS);
	if(_global_css == CSS_UNDEF){
		// 2012-04-03: doplnené default CSS pre daný jazyk
		_global_css = default_css_jazyk[_global_jazyk];
		if(_global_css == CSS_UNDEF){
			_global_css = CSS_breviar_sk;
			_main_LOG_to_Export("\t(vzhľadom k neurčenému CSS používam default)\n");
		}
		else{
			_main_LOG_to_Export("\t(vzhľadom k neurčenému CSS používam default pre daný jazyk)\n");
		}
	}
	_main_LOG_to_Export("...css (%s) = %i, teda %s (%s)\n", pom_CSS, _global_css, nazov_css[_global_css], skratka_css[_global_css]);

	LOG_ciara;
// END_presunutá_časť_2013_07_31

	if(ret_pom != SUCCESS){
		ALERT;
		Export("Neboli zadané vhodné parametre (1).\n");
		Export("<p>Chyba: %s\n", bad_param_str);
	}

	if(query_type != PRM_UNKNOWN){

		if(ret == SUCCESS){

			_main_LOG_to_Export("now allocating memory...\n");
			if(_allocate_global_var() == FAILURE){
				goto _main_end;
			}

			// presunutá_časť_2013_07_31 vyššie
			LOG_ciara;

			// 2013-01-22: oprava inicializácie _global_linky
			_main_LOG_to_Export("pom_LINKY == `%s'\n", pom_LINKY);
#if defined(OS_linux) || defined(OS_Windows_Ruby)
#if defined(BEHAVIOUR_WEB)
			_global_linky = 1; // zobrazovať linky (pre batch mód: použiť URL)
#elif defined(BEHAVIOUR_CMDLINE)
			_global_linky = 0; // nezobrazovať linky (pre batch mód: použiť filenames)
#else
			#error Unsupported behaviour (not defined in mysystem.h/mysysdef.h)
#endif
			_main_LOG_to_Export("/* linux resp. Windows/Ruby: teraz som nastavil _global_linky == %d */\n", _global_linky);
#elif defined(OS_Windows) || defined(OS_DOS)
			if((pom_LINKY != NULL) && (!equals(pom_LINKY, STR_EMPTY))){
				_global_linky = atoi(pom_LINKY);
				_main_LOG_to_Export("/* Windows resp. DOS: teraz som nastavil _global_linky == %d */\n", _global_linky);
			}
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif
			// inak ostane default hodnoty nastavene na zaciatku pre kazdy operacny system zvlast

			_main_LOG_to_Export("úprava include adresára...\n");
			// 2006-07-17: dokončenie úpravy include adresára podľa jazyka

			// 2004-03-17 uprava ciest: cfg_INCLUDE_DIR_default a include_dir | tzv. miesto 2004-03-17_TUTOLA
			_main_LOG_to_Export("\tcfg_INCLUDE_DIR_default = `%s'\n\tinclude_dir = `%s'\n", cfg_INCLUDE_DIR_default, include_dir);
			if(strcmp(include_dir, STR_EMPTY) == 0){
				_main_LOG_to_Export("\tberiem cfg_INCLUDE_DIR_default...\n");
				mystrcpy(include_dir, cfg_INCLUDE_DIR_default, MAX_STR);
			}
			else{
				_main_LOG_to_Export("\tberiem include_dir...\n");
			}

			// 2006-07-17: prvá kontrola, či include_dir končí na backslash resp. slash
			len = strlen(include_dir) - 1;
			_main_LOG_to_Export("prvá kontrola include adresára (či končí oddeľovačom `%c' [dĺžka %d])...\n", PATH_SEPARATOR, len);
			if(include_dir[len] != (short int)PATH_SEPARATOR){
				include_dir[len + 1] = PATH_SEPARATOR;
				len++;
				_main_LOG_to_Export("\tupravené (pridané na koniec reťazca): %s\n", include_dir);
			}
			else{
				_main_LOG_to_Export("\tok.\n");
			}

			_main_LOG_to_Export("kontrola, či include adresár končí reťazcom `%s'...\n", postfix_jazyka[_global_jazyk]);
			// 2008-04-09: treba najskôr skontrolovať, či include dir už náhodou neobsahuje aj prilepený postfix jazyka 
			//             include_dir[len] alebo include_dir[len + 1] obsahuje PATH_SEPARATOR
			//             teda znaky jeden a dva pred by mali obsahovať postfix_jazyka[_global_jazyk][0] a [1]
			// 2009-08-05: oprava kontroly, nemožno kontrolovať fixne 2 znaky, pretože postfix_jazyka môže byť dlhší (napr. pre "czop")
			char *include_dir_pom;
			short int len_postfix_jazyka = strlen(postfix_jazyka[_global_jazyk]);
			short int kontrola_prilepenia_postfix_jazyka = NIE;
			include_dir_pom = strstr(include_dir, postfix_jazyka[_global_jazyk]);
			if(include_dir_pom != NULL){
				_main_LOG_to_Export("len_postfix_jazyka = %d; include_dir_pom = %s\n", len_postfix_jazyka, include_dir_pom);
				if(include_dir[len] == (short int)PATH_SEPARATOR){
					_main_LOG_to_Export("include_dir[len] == (short int)PATH_SEPARATOR\n");
					if((short int)strlen(include_dir_pom) == len_postfix_jazyka + 1){
						kontrola_prilepenia_postfix_jazyka = ANO;
					}
				}
				else if(include_dir[len + 1] == (short int)PATH_SEPARATOR){
					_main_LOG_to_Export("include_dir[len + 1] == (short int)PATH_SEPARATOR\n");
					if((short int)strlen(include_dir_pom) == len_postfix_jazyka){
						kontrola_prilepenia_postfix_jazyka = ANO;
					}
				}
				else
					_main_LOG_to_Export("include_dir[len/len + 1] != (short int)PATH_SEPARATOR\n");
			}// if(include_dir_pom != NULL)
			else{
				_main_LOG_to_Export("include_dir_pom == NULL (teda include_dir[] neobsahuje postfix_jazyka (%s))\n", postfix_jazyka[_global_jazyk]);
			}

			if(kontrola_prilepenia_postfix_jazyka == ANO)
			{
				_main_LOG_to_Export("include adresár končí reťazcom `%s' - nie je potrebné pridávať\n", postfix_jazyka[_global_jazyk]);
			}
			else{
				_main_LOG_to_Export("include adresára NEkončí reťazcom `%s' - je potrebné pridávať (aktuálne include_dir == %s; lenght == %d; len == %d): ", postfix_jazyka[_global_jazyk], include_dir, strlen(include_dir), len);
				// 2006-07-13: pridané doplnenie jazyka kvôli jazykovým mutáciám
				_main_LOG_to_Export("upravujem include adresár podľa jazyka (%d - %s)...\n", _global_jazyk, nazov_jazyka[_global_jazyk]);

				// 2006-07-17: dokončenie úpravy include adresára podľa jazyka
				if(strlen(postfix_jazyka[_global_jazyk]) > 0){
					// 2006-07-31: pôvodne sme uvažovali, že include_dir bude napr. include/cz, incluce/en; teraz bude radšej include_cz, include_en t.j. nahraď backslash resp. slash znakom underscore
					include_dir[len] = UNDERSCORE;
					strcat(include_dir, postfix_jazyka[_global_jazyk]);
					_main_LOG_to_Export("\tupravené (pridané na koniec reťazca): %s\n", include_dir); // 2008-04-10: doplnené
				}
			}

			// 2006-07-17: druhá kontrola, či include_dir končí na backslash resp. slash
			len = strlen(include_dir) - 1;
			_main_LOG_to_Export("druhá kontrola include adresára (či končí oddeľovačom `%c' [dĺžka %d])...\n", PATH_SEPARATOR, len);
			if(include_dir[len] != (short int)PATH_SEPARATOR){
				include_dir[len + 1] = PATH_SEPARATOR;
				_main_LOG_to_Export("\tupravené (pridané na koniec reťazca): %s\n", include_dir);
			}
			else{
				_main_LOG_to_Export("\tok.\n");
			}

			_main_LOG_to_Export("include súbory budú z adresára include_dir = `%s'\n", include_dir);

			LOG_ciara;

			Log("_global_opt_batch_monthly == %d\n", _global_opt_batch_monthly);
			// 2009-08-12: rozparsovanie premennej pom_EXPORT_MONTHLY, nastavenej v getArgv() [pôvodne bolo až v _main_batch_mode()]
			if(_global_opt_batch_monthly == ANO){
				// rozparsovanie premennej pom_EXPORT_MONTHLY, nastavenej v getArgv()
				Log("rozparsovanie premennej pom_EXPORT_MONTHLY, nastavenej v getArgv()\n");
				export_monthly_druh = atoi(pom_EXPORT_MONTHLY);
				if(export_monthly_druh <= 0)
					export_monthly_druh = 0; // možno ide o znakový reťazec nekonvertovateľný na číslo; berieme to ako default správanie
				Log("export_monthly_druh == %d\n", export_monthly_druh);
			}// _global_opt_batch_monthly == ANO

			_main_LOG_to_Export("_global_jazyk == %s\n", nazov_jazyka[_global_jazyk]);
			// 2010-02-15, pridané: rozparsovanie parametra modlitba
			Log("volanie atomodlitba() z main()... [2]\n");
			_global_modlitba = atomodlitba(pom_MODLITBA);

			// rozparsovanie parametrov opt...
			// 2007-06-01: upravené tak, aby sa v prípade nenastavenia dala hodnota GLOBAL_OPTION_NULL
			// 2011-05-05: presunuté sem z jednotlivých procedúr: _main_rozbor_dna(), _main_dnes(), _main_liturgicke_obdobie(), _main_analyza_roku(), _main_tabulka(), _main_batch_mode()
			// 2013-01-08: tu sa nachádzalo volanie _rozparsuj_parametre_OPT(); ktoré som presunul vyššie kvôli tomu, že volanie hlavičky potrebuje už nastavené napr. o2 (batch mód, či použiť nočný režim)
			Log("volám _rozparsuj_parametre_OPT z main()...\n");
			_rozparsuj_parametre_OPT();

			Log("export_monthly_druh == %d\n", export_monthly_druh);

			_main_LOG_to_Export("volám hlavicka(); ... [pred volaním _main_... funkcií v switch(query_type)...]\n");
			if(query_type != PRM_XML){
				hlavicka((char *)html_title[_global_jazyk]);
			}
			else{
				xml_hlavicka();
			}

			Log("export_monthly_druh == %d\n", export_monthly_druh);

			_main_LOG_to_Export("/* teraz nasleduje vykonanie jadra programu podla parametrov */\n");
			_main_LOG_to_Export("switch: podla query_type...\n");
			switch(query_type){
				case PRM_DETAILY:
				// presne to iste co PRM_DATUM s jedinkym rozdielom: co sa tyka formularov, prvy (uvodny) formular pre PRM_DATUM vycisti modlitbu 
				// (premenna pom_MODLITBA, ktora sa nacita zo systemovej premennej WWW_MODLITBA) -- pretoze z inej casti fomrulara sa tam nieco dostane...
				case PRM_DATUM:
					_main_LOG_to_Export("spustam _main_rozbor_dna(stringy: pom_DEN = %s, pom_MESIAC = %s, pom_ROK = %s, pom_MODLITBA = %s, pom_DALSI_SVATY = %s);\n", pom_DEN, pom_MESIAC, pom_ROK, pom_MODLITBA, pom_DALSI_SVATY);
					_main_rozbor_dna(pom_DEN, pom_MESIAC, pom_ROK, pom_MODLITBA, pom_DALSI_SVATY);
					_main_LOG_to_Export("spat po skonceni _main_rozbor_dna(%s, %s, %s, %s, %s);\n", pom_DEN, pom_MESIAC, pom_ROK, pom_MODLITBA, pom_DALSI_SVATY);
					break;
				case PRM_TXT: // 2011-02-02: doplnené; export do TXT pre RKC
					_main_LOG_to_Export("spustam _main_rozbor_dna_txt(typ == %d; stringy: pom_DEN = %s, pom_MESIAC = %s, pom_ROK = %s);\n", query_type, pom_DEN, pom_MESIAC, pom_ROK);
					_main_rozbor_dna_txt(query_type, pom_DEN, pom_MESIAC, pom_ROK);
					_main_LOG_to_Export("spat po skonceni _main_rozbor_dna_txt(%s, %s, %s, %s);\n", pom_DEN, pom_MESIAC, pom_ROK);
					break;
				case PRM_XML: // 2012-10-16: doplnené; XML export
					_main_LOG_to_Export("spustam _main_rozbor_dna_txt(typ == %d; stringy: pom_DEN = %s, pom_MESIAC = %s, pom_ROK = %s);\n", query_type, pom_DEN, pom_MESIAC, pom_ROK);
					_main_rozbor_dna_txt(query_type, pom_DEN, pom_MESIAC, pom_ROK);
					_main_LOG_to_Export("spat po skonceni _main_rozbor_dna_txt(%s, %s, %s, %s);\n", pom_DEN, pom_MESIAC, pom_ROK);
					break;
				case PRM_STATIC_TEXT: // 2014-10-09: doplnené; includovanie statického textu
					_main_LOG_to_Export("spustam _main_static_text(pom_STATIC_TEXT = %s, pom_MODL_ORDINARIUM = %s);\n", pom_STATIC_TEXT, pom_MODL_ORDINARIUM);
					_main_static_text(pom_STATIC_TEXT, pom_MODL_ORDINARIUM);
					_main_LOG_to_Export("spat po skonceni _main_static_text(%s, %s);\n", pom_STATIC_TEXT, pom_MODL_ORDINARIUM);
					break;
				case PRM_CEZ_ROK:
					_main_LOG_to_Export("spustam _main_zaltar(%s, %s, %s);\n", pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA);
					_main_zaltar(pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA);
					_main_LOG_to_Export("spat po skonceni _main_zaltar(%s, %s, %s);\n", pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA);
					break;
				case PRM_LIT_OBD: // 2011-01-25: doplnené; prípad, že ide o výber dňa v liturgickom období
					_main_LOG_to_Export("spustam _main_liturgicke_obdobie(%s, %s, %s, %s, %s);\n", pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA, pom_LIT_OBD, pom_LIT_ROK);
					_main_liturgicke_obdobie(pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA, pom_LIT_OBD, pom_LIT_ROK);
					_main_LOG_to_Export("spat po skonceni _main_liturgicke_obdobie(%s, %s, %s, %s, %s);\n", pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA, pom_LIT_OBD, pom_LIT_ROK);
					break;
				case PRM_SVIATOK:
					_main_LOG_to_Export("spustam sviatok(%s);\n", pom_SVIATOK);
					_main_sviatok(pom_SVIATOK);
					_main_LOG_to_Export("spat po skonceni sviatok(%s);\n", pom_SVIATOK);
					break;
				case PRM_ANALYZA_ROKU:
					_main_LOG_to_Export("spustam analyza_roku(%s);\n", pom_ANALYZA_ROKU);
					_main_analyza_roku(pom_ANALYZA_ROKU);
					_main_LOG_to_Export("spat po skonceni analyza_roku(%s);\n", pom_ANALYZA_ROKU);
					break;
				case PRM_DNES:
					_main_LOG_to_Export("spustam _main_dnes(%s, %s);\n", pom_MODLITBA, pom_DALSI_SVATY);
					_main_dnes(pom_MODLITBA, pom_DALSI_SVATY);
					_main_LOG_to_Export("spat po skonceni _main_dnes();\n");
					break;
				case PRM_TABULKA:
					_main_LOG_to_Export("spustam _main_tabulka();\n");
					_main_tabulka(pom_ROK_FROM, pom_ROK_TO, pom_LINKY);
					_main_LOG_to_Export("spat po skonceni _main_tabulka();\n");
					break;
				case PRM_BATCH_MODE: // pridany batch mode; 2003-07-04
					_main_LOG_to_Export("spustam _main_batch_mode();\n");
					Export("<center><h2>Batch mode (dávkové použitie)</h2></center>\n");
					// vyuzivam parametre, ktore boli nastavene
					_main_batch_mode(// vyuzite parametre sa sice volaju haluzne, ale sluzia pre den from (prve tri), den to (dalsie tri), este jedno mam reserved; 2003-07-04
						pom_DEN, pom_MESIAC, pom_ROK,
						pom_ROK_FROM, pom_ROK_TO, pom_MODLITBA, 
						pom_DALSI_SVATY, pom_LINKY);
					_main_LOG_to_Export("spat po skonceni _main_batch_mode();\n");
					Export("<p>Výsledný batch skript (dávkový súbor) sa nachádza v súbore <a href=\"%s\">%s</a>."HTML_LINE_BREAK"\n", name_batch_file, name_batch_file);
					Export("Po spustení tento skript vygeneruje modlitby pre dané obdobie \n");
					Export("do súborov <span "HTML_CLASS_TT">yyyy-mm-dd_xp.htm"HTML_SPAN_END", kde význam \n");
					Export("jednotlivých častí mena súboru je nasledovný:\n");
					Export("<ul "HTML_CLASS_LEVEL1">\n");
					Export("<li><"HTML_SPAN_PARAMETER">yyyy"HTML_SPAN_END" | rok</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">mm"HTML_SPAN_END" | mesiac (napr. <"HTML_SPAN_VALUE">05"HTML_SPAN_END" pre máj)</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">dd"HTML_SPAN_END" | deň (napr. <"HTML_SPAN_VALUE">07"HTML_SPAN_END")</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">x"HTML_SPAN_END" | poradie svätého (<"HTML_SPAN_VALUE">0"HTML_SPAN_END" až <"HTML_SPAN_VALUE">%d"HTML_SPAN_END")</li>\n", PORADIE_PM_SOBOTA);
					Export("<li><"HTML_SPAN_PARAMETER">p"HTML_SPAN_END" | modlitba (<"HTML_SPAN_VALUE">r"HTML_SPAN_END" = ranné chvály, <"HTML_SPAN_VALUE">v"HTML_SPAN_END" = vešpery)</li>\n");
					Export("</ul>\n");
					Export("<p>V prípade, že je použitý parameter <"HTML_SPAN_PARAMETER">a"HTML_SPAN_END" (append), \n");
					Export("bude vytvorený len jeden súbor s nasledovným menom:\n");
					Export("<span "HTML_CLASS_TT">yyyy-mm-dd_YYYY-MM-DD.htm"HTML_SPAN_END", kde význam \n");
					Export("jednotlivých častí mena súboru je nasledovný:\n");
					Export("<ul "HTML_CLASS_LEVEL1">\n");
					Export("<li><"HTML_SPAN_PARAMETER">yyyy"HTML_SPAN_END" | rok počiatočného dátumu</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">mm"HTML_SPAN_END" | mesiac počiatočného dátumu</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">dd"HTML_SPAN_END" | deň počiatočného dátumu</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">YYYY"HTML_SPAN_END" | rok koncového dátumu</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">MM"HTML_SPAN_END" | mesiac koncového dátumu</li>\n");
					Export("<li><"HTML_SPAN_PARAMETER">DD"HTML_SPAN_END" | deň koncového dátumu</li>\n");
					Export("</ul>\n");
					break;
				default:
					ALERT;
					Export("Interná chyba programu.\n");
					Export(HTML_LINE_BREAK"(switch(query_type); case == default)\n");
					break;
			}// switch(query_type)

			_main_LOG_to_Export("volám patka(); ... [po volaní _main_... funkcií v switch(query_type)...]\n");
			if(query_type != PRM_XML){
				patka(); // 2011-07-01: doplnené (ešte pred dealokovanie premenných)
			}
			else{
				xml_patka();
			}

#ifndef MODEL_linux_citania
			_deallocate_global_var();
#endif

		}// if(ret == SUCCESS)
		else if(ret == FAILURE){
			// uz sa vyriesilo vyssie, dufam :-)
			_main_LOG_to_Export("ret == FAILURE\n");
		}
		else if(ret == NO_RESULT){
			// vtedy, ked
			// - case SCRIPT_PARAM_FROM_FORM
			// - query_type == PRM_NONE
			// - historicka poznamka: povodne spustilo sa prazdny_formular();
			// - v skutocnosti _main_prazdny_formular();
			_main_LOG_to_Export("ret == NO_RESULT\n");
		}
	}// if(query_type != PRM_UNKNOWN)
	else{
		if(ret_pom != SUCCESS){
			ALERT;
			Export("Neboli zadané vhodné parametre (2).\n");
			Export("<p>Chyba: %s\n", bad_param_str);
		}
		// else: netreba vypisovať, lebo sa vypísalo už vyššie
	}

	_main_LOG_to_Export("Deallocating memory...\n");
	_main_LOG_to_Export("query_string\n"); free(query_string);
	_main_LOG_to_Export("_global_buf\n"); free(_global_buf);
	_main_LOG_to_Export("_global_buf2\n"); free(_global_buf2);
	_main_LOG_to_Export("...done.\n");

_main_end:

	_main_LOG_to_Export("volám patka(); ... [_main_end:...]\n");
	if(query_type != PRM_XML){
		patka();
	}
	else{
		xml_patka();
	}

	if(closeExport() == EOF)
		Log("closeExport(): error closing file (return == EOF)\n");
	else
		Log("closeExport(): success.\n");
	closeLog();

	return 0;
}// breviar_main()

#ifndef SKIP_MAIN
int main(int argc, char **argv) {
	int ret = breviar_main(argc, argv);

#ifdef EXPORT_TO_STRING
	char *result = getExportedString();
	int resultLength = strlen(result);
	fwrite(result, resultLength, 1, stdout);
#endif

	return ret;
}
#endif

#endif // __BREVIAR_CPP_
