/************************************************************/
/*                                                          */
/* hodin.h                                                  */
/* (c)1999-2015 | Juraj Vidéky | videky@breviar.sk          */
/*                                                          */
/* description | originally used for string constants       */
/*                                                          */
/*                                                          */
/*   WARNING: NEVER REMOVE COMMENTS FOR ADDING NEW VALUES   */
/*                                                          */
/*   STRING_1_FOR_NEW_LANGUAGE etc.                         */
/*                                                          */
/************************************************************/

#include "vstudio.h"

#ifndef __HODIN_H_
#define __HODIN_H_

#include "liturgia.h"

const char *TEMPLAT[POCET_MODLITIEB + 1] =
{ TEMPLAT_INVITATORIUM, TEMPLAT_POSV_CITANIE, TEMPLAT_RANNE_CHVALY,
TEMPLAT_CEZ_DEN_9, TEMPLAT_CEZ_DEN_12, TEMPLAT_CEZ_DEN_3,
TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM, TEMPLAT_STATIC_TEXT,
TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM,
TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM, TEMPLAT_EMPTY, TEMPLAT_EMPTY };

const char *ORDINARIUM[POCET_MODLITIEB + 1] =
{ ORDINARIUM_INVITATORIUM, ORDINARIUM_POSV_CITANIE, ORDINARIUM_RANNE_CHVALY,
ORDINARIUM_CEZ_DEN, ORDINARIUM_CEZ_DEN, ORDINARIUM_CEZ_DEN,
ORDINARIUM_VESPERY, ORDINARIUM_KOMPLETORIUM, ORDINARIUM_EMPTY,
ORDINARIUM_VESPERY, ORDINARIUM_KOMPLETORIUM,
ORDINARIUM_VESPERY, ORDINARIUM_KOMPLETORIUM, ORDINARIUM_EMPTY, ORDINARIUM_EMPTY };

// 2008-04-09: doplnené pre batch generovanie modlitieb
const char char_modlitby[POCET_MODLITIEB + 1] =
{ CHAR_MODL_INVITATORIUM, CHAR_MODL_POSV_CITANIE, CHAR_MODL_RANNE_CHVALY,
CHAR_MODL_CEZ_DEN_9, CHAR_MODL_CEZ_DEN_12, CHAR_MODL_CEZ_DEN_3,
CHAR_MODL_VESPERY, CHAR_MODL_KOMPLETORIUM, CHAR_SPACE,
CHAR_MODL_PRVE_VESPERY, CHAR_MODL_PRVE_KOMPLETORIUM,
CHAR_MODL_VESPERY, CHAR_MODL_KOMPLETORIUM, CHAR_MODL_NEURCENA, CHAR_MODL_VSETKY };

const char *str_modlitby[POCET_MODLITIEB + 1] =
{ STR_MODL_INVITATORIUM, STR_MODL_POSV_CITANIE, STR_MODL_RANNE_CHVALY,
STR_MODL_PREDPOLUDNIM, STR_MODL_NAPOLUDNIE, STR_MODL_POPOLUDNI,
STR_MODL_VESPERY, STR_MODL_KOMPLETORIUM, STR_EMPTY,
STR_MODL_PRVE_VESPERY, STR_MODL_PRVE_KOMPLETORIUM,
STR_MODL_VESPERY, STR_MODL_KOMPLETORIUM, STR_MODL_DETAILY, STR_MODL_VSETKY };

// the names of the prayers, lowercase (sample text)
const char *nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{ { "invitatórium", "uvedení do první modlitby dne", "Invitatory", "invitatorium", "", "Pozvání k modlitbě", "imádságra hívás", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "posvätné čítanie", "modlitba se čtením", "Office of Readings", "officium lectionis", "", "Modlitba se čtením", "olvasmányos imaóra", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "ranné chvály", "ranní chvály", "Laudes", "laudes matutin&#230;", "", "Ranní chvály", "reggeli dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "modlitba predpoludním", "modlitba dopoledne", "Terce", "tertia", "", "Tercie", "délelőtt", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "modlitba napoludnie", "modlitba v poledne", "Sext", "sexta", "", "Sexta", "délben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "modlitba popoludní", "modlitba odpoledne", "None", "nona", "", "Nona", "délután", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "vešpery", "nešpory", "Vesperae", "vesper&#230;", "", "Večerní chvály", "esti dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "kompletórium", "kompletář", "Completary", "completorio", "", "Kompletář", "befejező imaóra", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "neurčená", "neurčena", "not-defined", "no data", "", "neurčena", "nem azonosított", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "prvé vešpery", "první nešpory", "1st Vesperae", "I vesper&#230;", "", "První večerní chvály", "I. esti dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "kompletórium po prvých vešperách", "kompletář po prvních nešporách", "1st Completary", "I completorio", "", "Kompletář po prvních večerních chválách", "befejező imaóra I. e. d. után", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ } // 2007-12-05: zmenené, kedysi bolo: "prvé kompletórium"
, { "druhé vešpery", "druhé nešpory", "2nd Vesperae", "II vesper&#230;", "", "Druhé večerní chvály", "II. esti dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "kompletórium po druhých vešperách", "kompletář po druhých nešporách", "2nd Completary", "II completorio", "", "Kompletář po druhých večerních chválách", "befejező imaóra II. e. d. után", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ } // 2007-12-05: zmenené, kedysi bolo: "druhé kompletórium"
, { "detaily", "detaily", "Details", "details", "", "detaily", "részletek", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "všetky", "všechny", "all", "all", "", "všechny", "összes", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_modlitby(a)	nazov_modlitby_jazyk[a][_global_jazyk]

// the names of the prayers, lowercase (sample text)
const char *nazov_modlitby_short_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{ { "invitatórium", "uvedení do 1. modl. dne", "Invitatory", "invitatorium", "", "Pozvání k modl.", "imádságra hívás", "предначинание", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "posvätné čítanie", "modl. se čtením", "Office of Readings", "officium lectionis", "", "modl. se čtením", "olvasmányos imaóra", "час чтений", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "ranné chvály", "ranní chvály", "Laudes", "laudes matutin&#230;", "", "Ranní chvály", "reggeli dicséret", "утреня", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "modl. predpoludním", "modl. dopoledne", "Terce", "tertia", "", "Tercie", "délelőtt", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "modl. napoludnie", "modl. v poledne", "Sext", "sexta", "", "Sexta", "délben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "modl. popoludní", "modl. odpoledne", "None", "nona", "", "Nona", "délután", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "vešpery", "nešpory", "Vesperae", "vesper&#230;", "", "Večerní chvály", "esti dicséret", "вечерня", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "kompletórium", "kompletář", "Completary", "completorio", "", "Kompletář", "befejező imaóra", "повечерие", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "neurčená", "neurčena", "not-defined", "no data", "", "neurčena", "nem azonosított", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "prvé vešpery", "první nešpory", "1st Vesperae", "I vesper&#230;", "", "První večerní chvály", "I. esti dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "kompletórium po 1. vešp.", "kompletář po 1. nešp.", "1st Completary", "I completorio", "", "Kompletář po 1. v. chv.", "befejező imaóra I. e. d. ut.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ } // 2007-12-05: zmenené, kedysi bolo: "prvé kompletórium"
, { "(druhé) vešpery", "druhé nešpory", "2nd Vesperae", "II vesper&#230;", "", "Druhé večerní chvály", "II. esti dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "kompletórium (po 2. vešp.)", "kompletář po 2. nešp.", "2nd Completary", "II completorio", "", "Kompletář po 2. v. chv.", "befejező imaóra II. e. d. ut.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ } // 2007-12-05: zmenené, kedysi bolo: "druhé kompletórium"
, { "detaily", "detaily", "Details", "details", "", "detaily", "részletek", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "všetky", "všechny", "all", "all", "", "všechny", "összes", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_modlitby_short(a)	nazov_modlitby_short_jazyk[a][_global_jazyk]

// the names of the prayers, sentence case (Sample text)
const char *nazov_Modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{ { "Invitatórium", "Uvedení do první modlitby dne", "Invitatory", "Invitatorium", "", "Pozvání k modlitbě", "Imádságra hívás", "Предначинание", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Posvätné čítanie", "Modlitba se čtením", "Office of Readings", "Officium lectionis", "", "Modlitba se čtením", "Olvasmányos imaóra", "Час чтений", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Ranné chvály", "Ranní chvály", "Laudes", "Laudes matutin&#230;", "", "Ranní chvály", "Reggeli dicséret", "Утреня", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Modlitba predpoludním", "Modlitba dopoledne", "Terce", "Tertia", "", "Tercie", "Délelőtt", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Modlitba napoludnie", "Modlitba v poledne", "Sext", "Sexta", "", "Sexta", "Délben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Modlitba popoludní", "Modlitba odpoledne", "None", "Nona", "", "Nona", "Délután", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Vešpery", "Nešpory", "Vesperae", "Vesper&#230;", "", "Večerní chvály", "Esti dicséret", "Вечерня", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Kompletórium", "Kompletář", "Completary", "Completorio", "", "Kompletář", "Befejező imaóra", "Повечерие", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Neurčená", "Neurčena", "not-defined", "No data", "", "Neurčená", "Nem azonosított", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Prvé vešpery", "První nešpory", "1st Vesperae", "I Vesper&#230;", "", "První večerní chvály", "I. Esti dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Kompletórium po prvých vešperách", "Kompletář po prvních nešporách", "1st Completary", "I Completorio", "", "Kompletář po prvních večerních chválách", "Befejező imaóra I. e. d. után", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Druhé vešpery", "Druhé nešpory", "2nd Vesperae", "II Vesper&#230;", "", "Druhé večerní chvály", "II. Esti dicséret", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Kompletórium po druhých vešperách", "Kompletář po druhých nešporách", "2nd Completary", "II Completorio", "", "Kompletář po druhých večerních chválách", "Befejező imaóra II. e. d. után", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "Detaily", "Detaily", "Details", "Details", "", "Detaily", "Részletek", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "všetky", "všechny", "all", "all", "", "všechny", "összes", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_Modlitby(a)	nazov_Modlitby_jazyk[a][_global_jazyk]

// the names of the prayers, all caps case (SAMPLE TEXT)
const char *nazov_MODLITBY_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{ { "INVITATÓRIUM", "UVEDENÍ DO PRVNÍ MODLITBY DNE", "INVITATORY", "INVITATORIUM", "", "POZVÁNÍ K MODLITBĚ", "IMÁDSÁGRA HÍVÁS", "ПРЕДНАЧИНАНИЕ", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "POSVÄTNÉ ČÍTANIE", "MODLITBA SE ČTENÍM", "OFFICE OF READINGS", "OFFICIUM LECTIONIS", "", "MODLITBA SE ČTENÍM", "OLVASMÁNYOS IMAÓRA", "ЧАС ЧТЕНИЙ", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "RANNÉ CHVÁLY", "RANNÍ CHVÁLY", "LAUDES", "LAUDES MATUTIN&#198;", "", "RANNÍ CHVÁLY", "REGGELI DICSÉRET", "УТРЕНЯ", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "MODLITBA PREDPOLUDNÍM", "MODLITBA DOPOLEDNE", "TERCE", "TERTIA", "", "TERCIE", "DÉLELŐTT", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "MODLITBA NAPOLUDNIE", "MODLITBA V POLEDNE", "SEXT", "SEXTA", "", "SEXTA", "DÉLBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "MODLITBA POPOLUDNÍ", "MODLITBA ODPOLEDNE", "NONE", "NONA", "", "NONA", "DÉLUTÁN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "VEŠPERY", "NEŠPORY", "VESPERAE", "VESPER&#198;", "", "VEČERNÍ CHVÁLY", "ESTI DICSÉRET", "ВЕЧЕРНЯ", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "KOMPLETÓRIUM", "KOMPLETÁŘ", "COMPLETARY", "COMPLETORIO", "", "KOMPLETÁŘ", "BEFEJEZŐ IMAÓRA", "ПОВЕЧЕРИЕ", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "NEURČENÁ", "NEURČENA", "NOT-DEFINED", "NO DATA", "", "NEURČENÁ", "NEM AZONOSÍTOTT", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "PRVÉ VEŠPERY", "PRVNÍ NEŠPORY", "1ST VESPERAE", "I VESPER&#198;", "", "PRVNÍ VEČERNÍ CHVÁLY", "I. ESTI DICSÉRET", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "KOMPLETÓRIUM PO PRVÝCH VEŠPERÁCH", "KOMPLETÁŘ PO PRVNÍCH NEŠPORÁCH", "1ST COMPLETARY", "I COMPLETORIO", "", "KOMPLETÁŘ PO PRVNÍCH VEČERNÍCH CHVÁLÁCH", "BEFEJEZŐ IMAÓRA I. E. D. UTÁN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "DRUHÉ VEŠPERY", "DRUHÉ NEŠPORY", "2ND VESPERAE", "II VESPER&#198;", "", "DRUHÉ VEČERNÍ CHVÁLY", "II. ESTI DICSÉRET", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "KOMPLETÓRIUM PO DRUHÝCH VEŠPERÁCH", "KOMPLETÁŘ PO DRUHÝCH NEŠPORÁCH", "2ND COMPLETARY", "II COMPLETORIO", "", "KOMPLETÁŘ PO DRUHÝCH VEČERNÍCH CHVÁLÁCH", "BEFEJEZŐ IMAÓRA II. E. D. UTÁN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "DETAILY", "DETAILY", "DETAILS", "DETAILS", "", "DETAILY", "RÉSZLETEK", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
, { "VŠETKY", "VŠECHNY", "ALL", "ALL", "", "VŠECHNY", "ÖSSZES", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_MODLITBY(a)	nazov_MODLITBY_jazyk[a][_global_jazyk]

// strings of buttons - abbreviations of prayer names // shortened because of usage on mobile devices (Android)
const char *html_button_nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] =
{
	{ "Inv.", "Inv.", "Inv.", "Inv.", "", "Inv.", "Imád.", "Пред.", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Posv. čít.", "Čtení", "Reading", "Off. lect.", "", "Čtení", "Olvasm. i.", "Ч. чт.", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Ranné chv.", "Ranní chv.", "Morning pr.", "Laudes", "", "Ranní chv.", "Reggeli dics.", "Утреня", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "9h", "9h", "9h", "Tertia", "", "Tercie", "Délelőtt", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "12h", "12h", "12h", "Sexta", "", "Sexta", "Délben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "15h", "15h", "15h", "Nona", "", "Nona", "Délután", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Vešpery", "Nešpory", "Vesperae", "Vesper&#230;", "", "Večerní chv.", "Esti dics.", "Вечерня", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Kompl.", "Kompl.", "Compl.", "Compl.", "", "Kompl.", "Befejező i.", "Повеч.", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "neurčená", "neurčena", "not-defined", "no data", "", "neurčena", "nem azonosított", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ } // táto sa pre HTML buttony nepoužíva
	, { "Prvé vešp.", "První nešp.", "1st Vesperae", "I vesper&#230;", "", "První v. chv.", "I. esti dics.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Prvé kompl.", "První kompl.", "Compl.", "Compl.", "", "První kompl.", "Bef. i. I. e. d. után", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Druhé vešp.", "Druhé nešpory", "2nd Vesperae", "II vesper&#230;", "", "Druhé večerní chv.", "II. esti dics.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Druhé kompl.", "Druhý kompl.", "2nd Completary", "II completorio", "", "Druhý kompl.", "Bef. i. II. e. d. után", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	// JUV: temporarily disabled due to lack of colspan functionality in display: table etc. elements | , { "výber spoločnej časti...", "výběr společné části...", "common texts...", "optiónes...", "", "výběr společné části...", "közös rész kiválasztása...", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "výber...", "výběr...", "common texts...", "optiónes...", "", "výběr...", "közös...", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "všetky", "všechny", "all", "all", "", "všechny", "összes", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		html_button_nazov_modlitby(a)	html_button_nazov_modlitby_jazyk[a][_global_jazyk]

// the prefix for common parts of celebration
const char *nazov_spolc_zospolc_jazyk[POCET_JAZYKOV + 1] =
{ "Zo spoločnej časti", "Společné texty", "", "", "", "Společné texty", "közös zsolozsmája", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *nazov_spolc_oficiumza_jazyk[POCET_JAZYKOV + 1] =
{ "Ofícium za", "Společné texty", "", "", "", "Společné texty", "közös zsolozsmája", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// the --CELEBRATION-- for common parts of celebration
const char *nazov_spolc_sviatky_jazyk[POCET_JAZYKOV + 1] =
{ "na sviatky", "na svátky", "", "", "", "na svátky", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// the --ANNIVERSARY-- for common parts of celebration
const char *nazov_spolc_vyrocie_jazyk[POCET_JAZYKOV + 1] =
{ "na výročie", "na výročí", "", "", "", "na výročí", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// the --OR-- (alternative) for common parts of celebration
const char *nazov_spolc_alebo_jazyk[POCET_JAZYKOV + 1] =
{ "alebo", "nebo", "or", "", "", "nebo", "vagy", "или", /* STRING_1_FOR_NEW_LANGUAGE */ };

// the names of the common texts (e.g.: for bishops, for saint men, for apostles...)
const char *nazov_spolc_jazyk[POCET_SPOL_CASTI + 1][POCET_JAZYKOV + 1] =
{
	{ "neurčená", "neurčena", "not decided", "", "", "", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "duchovných pastierov: pre kňazov", "o duchovních pastýřích (o kněžích)", "", "", "", "O duchovních pastýřích – o kněžích", "lelkipásztorok – papok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "duchovných pastierov: pre biskupov", "o duchovních pastýřích (o biskupech)", "", "", "", "O duchovních pastýřích – o biskupech", "lelkipásztorok – püspökök", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "duchovných pastierov: pre pápežov", "o duchovních pastýřích (o papeži)", "", "", "", "O duchovních pastýřích – o papeži", "pásztorok – pápa", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "učiteľov Cirkvi", "o učitelích církve", "", "", "", "O učitelích Církve", "egyháztanítók", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "apoštolov", "o apoštolech", "", "", "", "O apoštolech", "apostolok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "jedného mučeníka", "o jednom mučedníkovi", "", "", "", "O mučedníkovi", "vértanú", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "viacerých mučeníkov", "o více mučednících", "", "", "", "O více mučednících", "vértanúk", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Panny Márie", "o Panně Marii", "", "", "", "O Panně Marii", "Szűz Mária", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých mužov: pre rehoľníkov", "o svatých mužích (o řeholnících)", "", "", "", "O řeholnících", "szerzetes", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých mužov", "o svatých mužích", "", "", "", "O svatých mužích", "szent férfiak", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "panien", "o pannách", "", "", "", "O pannách", "szűz", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých žien: pre rehoľnice", "o svatých ženách (o řeholnicích)", "", "", "", "O svatých ženách - o řeholnicích", "apáca", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých žien", "o svatých ženách", "", "", "", "O svatých ženách", "szent asszonyok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "duchovných pastierov: pre viacerých", "o duchovních pastýřích", "", "", "", "O duchovních pastýřích", "több lelkipásztor", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "jednej mučenice", "o jedné mučednici", "", "", "", "O mučednici", "vértanú", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých žien: pre vychovávateľky", "o svatých ženách (o vychovatelkách)", "", "", "", "O svatých ženách - o vychovatelkách", "egyháztanító férfiak", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých mužov: pre vychovávateľov", "o svatých mužích (o vychovatelích)", "", "", "", "O svatých mužích – o vychovatelích", "egyháztanító asszonyok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých žien: pre tie, čo konali skutky milosrdenstva", "o svatých ženách (které vynikaly milosrdnými skutky)", "", "", "", "O svatých ženách – o ženě, která vynikala milosrdnými skutky", "jótékonykodó asszonyok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých mužov: pre tých, čo konali skutky milosrdenstva", "o svatých mužích (kterí vynikali milosrdnými skutky)", "", "", "", "O svatých mužích – o muži, který vynikal milosrdnými skutky", "jótékonykodó férfiak", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých žien: pre viaceré", "o svatých ženách (o více ženách)", "", "", "", "O svatých ženách", "több szent asszony", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých mužov: pre viacerých", "o svatých mužích – o více mužích", "", "", "", "O svatých mužích", "több szent férfi", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "viacerých panien", "o pannách", "", "", "", "O pannách", "szüzek", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "posviacky chrámu", "o posvěcení kostela", "", "", "", "Posvěcení kostela", "templomszentelés", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "zosnulých", "za zemřelé", "", "", "", "Za zemřelé", "halottakért", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých žien: pre tie, čo žili v manželstve", "o svatých ženách (které žily v manželství)", "", "", "", "O svatých ženách – o ženě, která žila v manželství", "házas szent asszonyok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "svätých mužov: pre tých, čo žili v manželstve", "o svatých mužích (kterí žili v manželství)", "", "", "", "O svatých mužích – o muži, který žil v manželství", "házas szent férfiak", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "nebrať", "nepoužít", "do not use", "", "", "nepoužít", "mindent sajátból", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_spolc(a)	nazov_spolc_jazyk[a][_global_jazyk]

const char *nazov_bit_opt_1_spomienka_spol_cast_jazyk[POCET_JAZYKOV + 1] =
{
	"bola zvolená možnosť niektoré časti pri slávení spomienky vziať zo dňa podľa Všeobecných smerníc, č. 235 písm. b",
	"byla zvolena možnost vzít při slavení památky některé části ze dne podle Všeobecných pokynů k denní modlitbě církve, č. 235 písm. b",
	"",
	"",
	"",
	"byla zvolena možnost vzít při slavení památky některé části ze dne podle Všeobecných pokynů k denní modlitbě Církve, č. 235 písm. b",
	"az a lehetőség volt választva, hogy az emléknapoknál bizonyos részek vehetők a soros köznapról; Általános Rendelkezések az Imaórák Liturgiájáról, 235 b",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// filenames - language independent (based on Slovak)
const char *nazov_spolc_htm[POCET_SPOL_CASTI + 1] =
{
	"000",
	"sc_dp.htm",
	"sc_dp.htm",
	"sc_dp.htm",
	"sc_uc.htm",
	"sc_ap.htm",
	"sc_jm.htm",
	"sc_vm.htm",
	"sc_pm.htm",
	"sc_rh.htm",
	"sc_sm.htm",
	"sc_pn.htm",
	"sc_rh.htm",
	"sc_sz.htm",
	"sc_dp.htm",
	"sc_jm.htm",
	"sc_vv.htm",
	"sc_vv.htm",
	"sc_skm.htm",
	"sc_skm.htm",
	"sc_sz.htm",
	"sc_sm.htm",
	"sc_pn.htm",
	"vpchr.htm",
	"ozz.htm",
	"sc_sz.htm",
	"sc_sm.htm",
	"000"
};

// anchor names in files - same for all languages (based on Slovak)
const char *nazov_spolc_ANCHOR[POCET_SPOL_CASTI + 1] =
{
	"000",
	"SCDPKN",
	"SCDPBS",
	"SCDPPP",
	"SCUC",
	"SCAP",
	"SCMM",
	"SCVM",
	"SCPM",
	"SCSMRH",
	"SCSM",
	"SCPN",
	"SCSZRH",
	"SCSZ",
	"SCDPVI",
	"SCZM",
	"SCVV",
	"SCVV",
	"SCSKM",
	"SCSKM",
	"SCSZV",
	"SCSMV",
	"SCPNV",
	"VPCHR",
	"OZZ",
	"SCSZM",
	"SCSMM",
	"000"
};

// the names of liturgical periods (usually lowecase) / nazov_obdobia: string pre nazov liturgickeho obdobia
const char *nazov_obdobia_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
	{ "adventné obdobie", "doba adventní", "", "tempus adventus", "", "doba adventní", "adventi idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "adventné obdobie", "doba adventní", "", "tempus adventus", "", "doba adventní", "adventi idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "oktáva Narodenia Pána", "oktáv Narození Páně", "", "octava nativitatis", "", "oktáv Narození Páně", "karácsony nyolcada", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vianočné obdobie", "doba vánoční", "", "tempus nativitatis", "", "doba vánoční", "karácsonyi idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vianočné obdobie", "doba vánoční", "", "tempus nativitatis", "", "doba vánoční", "karácsonyi idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "cezročné obdobie", "mezidobí", "", "tempus per annum", "", "mezidobí", "évközi idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "pôstne obdobie", "doba postní", "", "tempus quadragesim&#230;", "", "doba postní", "nagyböjti idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľký týždeň", "Svatý týden", "", "hebdomada sancta", "", "Svatý týden", "nagyhét", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "veľkonočné trojdnie", "Velikonoční triduum", "", "sacrum triduum paschale", "", "Velikonoční triduum", "szent három nap", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "veľkonočná oktáva", "velikonoční oktáv", "", "octava pasch&#230;", "", "velikonoční oktáv", "húsvét nyolcada", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "veľkonočné obdobie", "doba velikonoční", "", "tempus paschale", "", "doba velikonoční", "húsvéti idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "veľkonočné obdobie", "doba velikonoční", "", "tempus paschale", "", "doba velikonoční", "húsvéti idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};

#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

// the names of liturgical periods (usually lowecase) / nazov_obdobia: string pre názov liturgického obdobia, rozšírený
const char *nazov_obdobia_ext_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
	{ "Adventné obdobie I (do 16. decembra)", "doba adventní I", "", "tempus adventus I", "", "doba adventní I", "adventi idő I (dec. 16-ig)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Adventné obdobie II (po 16. decembri)", "doba adventní II", "", "tempus adventus II", "", "doba adventní II", "adventi idő II (dec. 16 után)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Oktáva Narodenia Pána", "oktáv Narození Páně", "", "octava nativitatis", "", "oktáv Narození Páně", "karácsony nyolcada", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Vianočné obdobie I (do Zjavenia Pána)", "doba vánoční I", "", "tempus nativitatis I", "", "doba vánoční II", "karácsonyi idő I (Urunk megjelenéséig)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Vianočné obdobie II (po Zjavení Pána)", "doba vánoční II", "", "tempus nativitatis II", "", "doba vánoční II", "karácsonyi idő II (Urunk megjelenése után)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Cezročné obdobie", "mezidobí", "", "tempus per annum", "", "mezidobí", "évközi idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Pôstne obdobie I (do Kvetnej nedele)", "doba postní I", "", "tempus quadragesim&#230; I", "", "doba postní I", "nagyböjti idő I (Virágvasárnapig)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Pôstne obdobie II (veľký týždeň)", "Svatý týden", "", "hebdomada sancta", "", "Svatý týden", "nagyböjti idő II (Nagyhét)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočné trojdnie", "Velikonoční triduum", "", "sacrum triduum paschale", "", "Velikonoční triduum", "szent három nap", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočná oktáva", "velikonoční oktáv", "", "octava pasch&#230;", "", "velikonoční oktáv", "húsvét nyolcada", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočné obdobie I (do Nanebovstúpenia Pána)", "doba velikonoční I", "", "tempus paschale I", "", "doba velikonoční I", "húsvéti idő I (Urunk mennybemeneteléig)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočné obdobie II (po Nanebovstúpení Pána)", "doba velikonoční II", "", "tempus paschale II", "", "doba velikonoční II", "húsvéti idő II (Urunk mennybemenetele után)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};

#define		nazov_obdobia_ext(a)	nazov_obdobia_ext_jazyk[a][_global_jazyk]

// the names of liturgical periods (usually lowecase) full-shortened / nazov_obdobia: string pre názov liturgického obdobia, stručný ale plný
const char *nazov_obdobia_short_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
	{ "Adventné obd. I", "doba adventní I", "", "tempus adventus I", "", "doba adventní I", "adventi idő I", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Adventné obd. II", "doba adventní II", "", "tempus adventus II", "", "doba adventní II", "adventi idő II", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Oktáva Narodenia Pána", "oktáv Narození Páně", "", "octava nativitatis", "", "oktáv Narození Páně", "karácsony nyolcada", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Vianočné obd. I", "doba vánoční I", "", "tempus nativitatis I", "", "doba vánoční II", "karácsonyi idő I", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Vianočné obd. II", "doba vánoční II", "", "tempus nativitatis II", "", "doba vánoční II", "karácsonyi idő II", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Cezročné obd.", "mezidobí", "", "tempus per annum", "", "mezidobí", "évközi idő", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Pôstne obd. I", "doba postní I", "", "tempus quadragesim&#230; I", "", "doba postní I", "nagyböjti idő I", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľký týždeň", "Svatý týden", "", "hebdomada sancta", "", "Svatý týden", "Nagyhét", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočné trojdnie", "Velikonoční triduum", "", "sacrum triduum paschale", "", "Velikonoční triduum", "szent három nap", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočná oktáva", "velikonoční oktáv", "", "octava pasch&#230;", "", "velikonoční oktáv", "húsvét nyolcada", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočné obd. I", "doba velikonoční I", "", "tempus paschale I", "", "doba velikonoční I", "húsvéti idő I", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "Veľkonočné obd. II", "doba velikonoční II", "", "tempus paschale II", "", "doba velikonoční II", "húsvéti idő II", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};

#define		nazov_obdobia_short(a)	nazov_obdobia_short_jazyk[a][_global_jazyk]

// the names of liturgical periods for debugging, only in Slovak; no need to translate
const char *nazov_obdobia_[POCET_OBDOBI + 1] = // debuggovacie - preto netreba prekladať; 2006-08-03
{
	"adventné obdobie I", "adventné obdobie II", "oktáva Narodenia Pána",
	"vianočné obdobie I", "vianočné obdobie II", "cezročné obdobie",
	"pôstne obdobie I", "pôstne obdobie II (Veľký týždeň)",
	"veľkonočné trojdnie", "veľkonočná oktáva", "veľkonočné obdobie I", "veľkonočné obdobie II",
};

// the names of liturgical periods in local grammatically 6.th declination? (usually lowecase); in English: "IN liturgical period" or "OF liturgical period" / lokal == 6. pad, v kom/com
const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
	{ "v adventnom období", "v době adventní", "", "", "", "v době adventní", "adventben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "v adventnom období", "v době adventní", "", "", "", "v době adventní", "adventben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "v oktáve Narodenia Pána", "v oktávu Narození Páně", "", "", "", "v oktávu Narození Páně", "Karácsony nyolcadában", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vo vianočnom období", "v době vánoční", "", "", "", "v době vánoční", "a karácsonyi időben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vo vianočnom období", "v době vánoční", "", "", "", "v době vánoční", "a karácsonyi időben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "v cezročnom období", "v mezidobí", "", "per annum", "", "v mezidobí", "az évközi időben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "v pôstnom období", "v době postní", "", "", "", "v době postní", "a nagyböjti időben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vo Veľkom týždni", "ve Svatém týdnu", "", "", "", "ve Svatém týdnu", "a nagyhéten", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vo veľkonočnom trojdní", "ve velikonočním triduu", "", "", "", "ve velikonočním triduu", "a szent három napban", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vo veľkonočnej oktáve", "ve velikonočním oktávu", "", "", "", "ve velikonočním oktávu", "húsvét nyolcadában", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vo veľkonočnom období", "v době velikonoční", "", "", "", "v době velikonoční", "a húsvéti időben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vo veľkonočnom období", "v době velikonoční", "", "", "", "v době velikonoční", "a húsvéti időben", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};

#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

// the names of liturgical periods in local grammatically 6.th declination? (uppercase) / nazov_obdobia: string pre nazov liturgickeho obdobia
const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
	{ "V ADVENTNOM OBDOBÍ", "V DOBĚ ADVENTNÍ", "", "", "", "V DOBĚ ADVENTNÍ", "ADVENTBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "V ADVENTNOM OBDOBÍ", "V DOBĚ ADVENTNÍ", "", "", "", "V DOBĚ ADVENTNÍ", "ADVENTBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "V OKTÁVE NARODENIA PÁNA", "V OKTÁVU NAROZENÍ PÁNĚ", "", "", "", "V OKTÁVU NAROZENÍ PÁNĚ", "A KARÁCSONY NYOLCADÁBAN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VIANOČNOM OBDOBÍ", "V DOBĚ VÁNOČNÍ", "", "", "", "V DOBĚ VÁNOČNÍ", "A KARÁCSONYI IDŐBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VIANOČNOM OBDOBÍ", "V DOBĚ VÁNOČNÍ", "", "", "", "V DOBĚ VÁNOČNÍ", "A KARÁCSONYI IDŐBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "V CEZROČNOM OBDOBÍ", "V MEZIDOBÍ", "", "", "", "BĚHEM ROKU", "AZ ÉVKÖZI IDŐBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "V PÔSTNOM OBDOBÍ", "V DOBĚ POSTNÍ", "", "", "", "V DOBĚ POSTNÍ", "A NAGYBÖJTI IDŐBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VEĽKOM TÝŽDNI", "VE SVATÉM TÝDNU", "", "", "", "VE SVATÉM TÝDNU", "A NAGYHÉTEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VEĽKONOČNOM TROJDNÍ", "VE VELIKONOČNÍM TRIDUU", "", "", "", "VE VELIKONOČNÍM TRIDUU", "A SZENT HÁROM NAPBAN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VEĽKONOČNEJ OKTÁVE", "VE VELIKONOČNÍM OKTÁVU", "", "", "", "V OKTÁVU VELIKONOČNÍM", "HÚSVÉT NYOLCACADÁBAN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VEĽKONOČNOM OBDOBÍ", "V DOBĚ VELIKONOČNÍ", "", "", "", "V DOBĚ VELIKONOČNÍ", "A HÚSVÉTI IDŐBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VEĽKONOČNOM OBDOBÍ", "V DOBĚ VELIKONOČNÍ", "", "", "", "V DOBĚ VELIKONOČNÍ", "A HÚSVÉTI IDŐBEN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};

#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

// used for Sundays - "which" Sunday for some of them, e.g. "dominica V paschae" for 5-th Sunday in that liturgical period (uppercase)
// 2008-12-20: doplnené - používa sa v init_global_string() pre nedele niektorých období [zatiaľ iba v slovenčine]
const char *nazov_OBDOBIA_AKA_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
	{ "ADVENTNÁ", "ADVENTNÍ", "", "", "", "ADVENTNÍ", "ADVENT", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "ADVENTNÁ", "ADVENTNÍ", "", "", "", "ADVENTNÍ", "ADVENT", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "V OKTÁVE NARODENIA PÁNA", "V OKTÁVU NAROZENÍ PÁNĚ", "", "", "", "V OKTÁVU NAROZENÍ PÁNĚ", "A KARÁCSONY NYOLCADÁBAN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }, // not used / nepoužíva sa
	{ "VIANOČNÁ", "VÁNOČNÍ", "", "", "", "VÁNOČNÍ", "KARÁCSONY", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VIANOČNÁ", "VÁNOČNÍ", "", "", "", "VÁNOČNÍ", "KARÁCSONY", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "CEZROČNÁ", "V MEZIDOBÍ", "", "", "", "BĚHEM ROKU", "ÉVKÖZI", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "PÔSTNA", "POSTNÍ", "", "", "", "POSTNÍ", "NAGYBÖJT", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VO VEĽKOM TÝŽDNI", "VE SVATÉM TÝDNU", "", "", "", "VE SVATÉM TÝDNU", "hu_", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }, // not used / nepoužíva sas
	{ "VO VEĽKONOČNOM TROJDNÍ", "VE VELIKONOČNÍM TRIDUU", "", "", "", "VE VELIKONOČNÍM TRIDUU", "hu_", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }, // not used / nepoužíva sa
	{ "VO VEĽKONOČNEJ OKTÁVE", "VE VELIKONOČNÍM OKTÁVU", "", "", "", "V OKTÁVU VELIKONOČNÍM", "HÚSVÉT NYOLCACADÁBAN", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }, // not used / nepoužíva sa
	{ "VEĽKONOČNÁ", "VELIKONOČNÍ", "", "", "", "VELIKONOČNÍ", "HÚSVÉT", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "VEĽKONOČNÁ", "VELIKONOČNÍ", "", "", "", "VELIKONOČNÍ", "HÚSVÉT", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};
#define		nazov_OBDOBIA_AKA(a)	nazov_OBDOBIA_AKA_jazyk[a][_global_jazyk]

// filenames - same for all languages (based on Slovak)
// nazov_obdobia: string pre nazov suboru .htm liturgickeho obdobia
const char *nazov_obd_htm[POCET_OBDOBI + 1] =
{
	"adv1.htm", "adv2.htm", "vian1.htm",
	"vian1.htm", "vian2.htm", "cezrok.htm",
	"post1.htm", "vtyz.htm",
	"vtroj.htm", "vnokt.htm", "vn1.htm", "vn2.htm"
};

// anchor names in files - same for all languages (based on Slovak)
// nazov_obdobia: string pre nazov kotvy v .htm liturgickeho obdobia
const char *nazov_OBD[POCET_OBDOBI + 1] =
{
	"ADV1", "ADV2", "OKTNAR",
	"VIAN1", "VIAN2", "OCR",
	"POST1", "VTYZ",
	"VTROJ", "VNOKT", "VN1", "VN2"
};

// filenames - same for all languages (based on Slovak)
// nazov_obdobia pc: string pre nazov suboru .htm liturgickeho obdobia pre posvatne citania
const char *nazov_obd_htm_pc[POCET_OBDOBI + 1] =
{
	"adv1_pc.htm", "adv2_pc.htm", "vian1_pc.htm",
	"vian1_pc.htm", "vian2_pc.htm", "cezrok_pc.htm",
	"post1_pc.htm", "vtyz_pc.htm",
	"vtroj_pc.htm", "vnokt_pc.htm", "vn1_pc.htm", "vn2_pc.htm"
};

// anchor names in files used for 4 volumes of breviary - same for all languages (based on Slovak)
// 2005-08-05: Pridané. zväzok breviára (LH) pre spoločné časti svätých v kotvách
const char *zvazok_OBD[POCET_OBDOBI + 1] =
{
	"ZVI", "ZVI", "ZVI",
	"ZVI", "ZVI", "OCR", // OCR je ZVIII aj ZVIV
	"ZVII", "ZVII",
	"ZVII", "ZVII", "ZVII", "ZVII"
};

// the name of celebration
const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1] =
{
	{ "féria", "férie", "feria", "feria", "férie", "féria", "féria", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }, // zmenené z "___", 2012-10-12
	{ "slávnosť", "slavnost", "celebration", "sollemnitas", "", "SLAVNOST", "főünnep", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "sviatok", "svátek", "", "festum", "", "Svátek", "ünnep", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "spomienka", "památka", "", "memoria", "", "Památka", "emléknap", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "ľubovoľná spomienka", "nezávazná památka", "", "memoria ad libitum", "", "nezávazná památka", "tetszés szerinti emléknap", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "vlastné slávenie", "z vlastních textů", "", "textus proprius", "", "z vlastních textů", "saját szöveg", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};

#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

// the name of celebration -- for memoria (in privileged days)
const char *nazov_slavenia_na_spomienku_jazyk[POCET_JAZYKOV + 1] =
{ "na spomienku" /* Adam: lepšie by bolo: pripomienka */, "pro připomínku", "", "in memoria", "", "pro připomínku", "megemlékezésül", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// 2010-08-03: pridaný kalendár

// calendar codes; internal usage for HTTP requests
const char *skratka_kalendara[POCET_KALENDAROV + 1] =
{ "??", "la", "sk", "cz", "czop", "cssr", "hu", "svd", "sj", "sdb", "ofm", "op", "cm", "opraem", "ofmcap", "czcssr", "czsdb", "ru", /* ADD_VALUE_FOR_NEW_CALENDAR */ };

// filenames for special calendars / názov súbora pre kalendáre -- "pro" == propriá
const char *nazov_htm_kalendar[POCET_KALENDAROV + 1] =
{ "", "", "", "", "", "pro_cssr.htm", "", "pro_svd.htm", "pro_sj.htm", "pro_sdb.htm", "pro_ofm.htm", "pro_op.htm", "pro_cm.htm", "pro_opraem.htm", "pro_ofmcap.htm", "pro_cssr.htm", "pro_sdb.htm", "", /* ADD_VALUE_FOR_NEW_CALENDAR */ };

const char *nazov_kalendara_short[POCET_KALENDAROV + 1] =
{
	"neurčený"
	, "všeobecný"
	, "všeobecný SK"
	, "všeobecný CZ"
	, "CZOP"
	, "SK CSSR"
	, "všeobecný HU"
	, "SK SVD"
	, "SK SJ"
	, "SK SDB"
	, "SK OFM"
	, "SK OP"
	, "SK CM"
	, "CZ OPRAEM"
	, "CZ OFMCAP"
	, "CZ CSSR"
	, "CZ SDB"
	, "všeobecný RU"
	, /* ADD_VALUE_FOR_NEW_CALENDAR */
};

// doplnené 2010-10-11
const char *nazov_kalendara_long[POCET_KALENDAROV + 1] =
{
	""
	, ""
	, "všeobecný [pre Slovensko]"
	, "obecný [pro Čechy a Moravu]"
	, ""
	, "pre Kongregáciu najsv. Vykupiteľa — redemptoristov (CSsR)" // bol veľmi dlhý combo-box, keď bolo: "pre Kongregáciu najsvätejšieho Vykupiteľa — redemptoristov (CSsR)"
	, "általános [Magyarország]"
	, "pre Spoločnosť Božieho Slova — verbistov (SVD)"
	, "pre Spoločnosť Ježišovu — jezuitov (SJ)"
	, "pre saleziánsku rodinu — SDB, FMA, ASC" // bolo VDB -> ASC; saleziáni spolupracovníci majú skratku ASC - Associazione dei salesiani cooperatori - teda Zdruzenie salezianov spolupravovnikov (upozornil Maťo Linhart, 2012-02-13)
	// ,"pre františkánsku rodinu — františkánov<!-- (OFM)-->, kapucínov<!-- (OFMCap)-->, minoritov<!-- (OFMConv.)-->" // 2011-03-21: nefungovalo porovnanie atokalendar lebo HTML odstránilo poznámky
	// ,"pre františkánsku rodinu — františkánov, kapucínov, minoritov" // 2011-03-22: sú tam aj mnohé ďalšie rehole a kongregácie, takže ma br. Jakub OFM poprosil, aby ostalo iba "pre františkánsku rodinu"
	, "pre františkánsku rodinu"
	, "pre Rehoľu kazateľov — dominikánov (OP)"
	, "pre Misijnú spoločnosť sv. Vincenta de Paul — lazaristov (CM)"
	, "s vlastními texty premonstrátského řádu (OPraem)" // "pro premonstráty (OPraem)"
	, "s vlastními kapucínskými texty (OFMCap)"
	, "s vlastními texty Kongregace nejsv. Vykupitele — redemptoristů (CSsR)"
	, "s vlastními texty pro salesiánskou rodinu" // (SDB, FMA, VDB, ASC)
	, "general [Russia]"
	, /* ADD_VALUE_FOR_NEW_CALENDAR */
};

#define nazov_kalendara(kalendar) ((kalendar == KALENDAR_NEURCENY) || (kalendar == KALENDAR_VSEOBECNY) || (equals(nazov_kalendara_long[kalendar], STR_EMPTY))? nazov_kalendara_long[default_kalendar[_global_jazyk]] : nazov_kalendara_long[kalendar])

// special "local" or "partial" characteristics of various celebrations - each in one language; no need to translate; special strings will be added
// 2007-08-31: upravené TT -> BA-TT
// 2008-06-23: upravené vzhľadom k novému usporiadaniu diecéz (intuitívne)
// 2010-03-16: doplnené BA
// 2011-07-25: doplnené názvy číselných konštánt
const char *nazov_slavenia_lokal[] =
{
 ""                                                                                                             // LOKAL_SLAV_NEURCENE
,"len v rožňavskej katedrále"                                                                                   // LOKAL_SLAV_ROZNAVA_KATEDRALA
,"hlavný patrón Trnavskej arcidiecézy"                                                                          // LOKAL_SLAV_TRNAVA_PATRON
,"v Bratislavskej, Trnavskej a Košickej arcidiecéze "HTML_LINE_BREAK"a v Banskobystrickej, Nitrianskej a Rožňavskej diecéze" // LOKAL_SLAV_TT_BB_KE_NR_RO
,"v Nitrianskej diecéze sviatok hlavných patrónov"                                                              // LOKAL_SLAV_NITRA_PATRON
,"len v Košickej arcidiecéze"                                                                                   // LOKAL_SLAV_KOSICE
,"len v Nitrianskej diecéze"                                                                                    // LOKAL_SLAV_NITRA
,"len v Banskobystrickej diecéze"                                                                               // LOKAL_SLAV_BYSTRICA
,"len v Spišskej diecéze"                                                                                       // LOKAL_SLAV_SPIS
,"len v Rožňavskej diecéze"                                                                                     // LOKAL_SLAV_ROZNAVA
,"len v Trnavskej arcidiecéze"                                                                                  // LOKAL_SLAV_TRNAVA
,"len v Dóme sv. Martina v Bratislave"                                                                          // LOKAL_SLAV_DOM_SV_MARTINA
,"v Spišskej diecéze sviatok hlavného patróna"                                                                  // LOKAL_SLAV_SPIS_PATRON
,"v Banskobystrickej diecéze sviatok hlavného patróna"                                                          // LOKAL_SLAV_BYSTRICA_PATRON
,"v Bratislavskej a Trnavskej arcidiecéze "HTML_LINE_BREAK"a v Banskobystrickej, Nitrianskej a Rožňavskej diecéze" // LOKAL_SLAV_TT_BB_NR_RO
,"v Košickej arcidiecéze sviatok hlavného patróna"                                                              // LOKAL_SLAV_KOSICE_PATRON
,"len v Žilinskej diecéze — sviatok hlavných patrónov; "HTML_LINE_BREAK"v Európe sviatok patrónov Európy"       // LOKAL_SLAV_14_FEB_CYRIL_METOD | odstránený popis "na Slovensku sa slávi 5. júla, slávnosť"
,"v Rožňavskej diecéze sviatok hlavného patróna"                                                                // LOKAL_SLAV_ROZNAVA_PATRON
,"len v konsekrovaných kostoloch"                                                                               // LOKAL_SLAV_KONSEKR_KOSTOLY
,"Druhá veľkonočná nedeľa — Božieho milosrdenstva"                                                              // LOKAL_SLAV_DRUHA_VELK_NEDELA
,"koniec Oktávy narodenia Pána"                                                                                 // LOKAL_SLAV_KONIEC_OKTAVY_NAR
,"konec Oktávu Narození Páně"                                                                                   // LOKAL_SLAV_KONIEC_OKTAVY_NAR_CZ
,"hlavního patrona pražské arcidiecéze"                                                                         // LOKAL_SLAV_PRAHA_PATRON
,"v pražské arcidiecézi"                                                                                        // LOKAL_SLAV_PRAHA
,"v brněnské diecézi"                                                                                           // LOKAL_SLAV_BRNO
,"na Moravě památka"                                                                                            // LOKAL_SLAV_MORAVA_SPOMIENKA
,"Druhá neděle velikonoční – Božího milosrdenství"                                                              // LOKAL_SLAV_DRUHA_VELK_NEDELA_CZ
,"v pražské katedrále slavnost"                                                                                 // LOKAL_SLAV_PRAHA_KATEDRALA
,"v českobudějovické diecézi"                                                                                   // LOKAL_SLAV_CESKE_BUDEJOVICE
,"v olomoucké arcidiecézi"                                                                                      // LOKAL_SLAV_OLOMOUC
,"v Čechách závazná památka"                                                                                    // LOKAL_SLAV_CECHY_SPOMIENKA
,"v plzeňské diecézi svátek hlavního patrona"                                                                   // LOKAL_SLAV_PLZEN_PATRON
,"v ostravsko-opavské diecézi"                                                                                  // LOKAL_SLAV_OSTRAVA_OPAVA
,"v litoměřické diecézi"                                                                                        // LOKAL_SLAV_LITOMERICE
,"v královéhradecké diecézi"                                                                                    // LOKAL_SLAV_HRADEC_KRALOVE
,"jen v posvěcených kostelích"                                                                                  // LOKAL_SLAV_KONSEKR_KOSTOLY_CZ 
,"v plzeňské diecézi"                                                                                           // LOKAL_SLAV_PLZEN 
,"v ostravsko-opavské diecézi slavnost"                                                                         // LOKAL_SLAV_OSTRAVA_OPAVA_SLAVNOST
,"v českobudějovické diecézi památka"                                                                           // LOKAL_SLAV_CESKE_BUDEJOVICE_PAMATKA
,"v Bratislavskej arcidiecéze a v Spišskej diecéze sviatok hlavného patróna"                                    // LOKAL_SLAV_SPIS_BA_PATRON
,"v Bratislavskej arcidiecéze"                                                                                  // LOKAL_SLAV_BRATISLAVA
,"Karácsony nyolcada – Kiskarácsony"                                                                            // LOKAL_SLAV_KONIEC_OKTAVY_NAR_HU
,"len pre Inštitút milosrdných sestier Sv. kríža"                                                               // LOKAL_SLAV_KONGREGACIA_SSK // 2013-08-12: pôvodne bolo: "len pre Kongregáciu milosrdných sestier Sv. kríža"
,"pre OFMCap: spomienka"                                                                                        // LOKAL_SLAV_SPOMIENKA_OFMCAP
,"pre OFM: sviatok"                                                                                             // LOKAL_SLAV_SVIATOK_OFM
,"pre OFM: spomienka"                                                                                           // LOKAL_SLAV_SPOMIENKA_OFM
,"pre OFMCap: sviatok"                                                                                          // LOKAL_SLAV_SVIATOK_OFMCAP
,"pre FMA: spomienka"                                                                                           // LOKAL_SLAV_SPOMIENKA_FMA
,"pre FMA: slávnosť"                                                                                            // LOKAL_SLAV_SLAVNOST_FMA
,"pre SDB: slávnosť"                                                                                            // LOKAL_SLAV_SLAVNOST_SDB
,"pre ASC: sviatok"                                                                                             // LOKAL_SLAV_SVIATOK_VDB // VDB -> ASC
,"pre SCSC: sviatok"                                                                                            // LOKAL_SLAV_SVIATOK_SCSC
,"Húsvét 2. vasárnapja – Az Isteni Irgalmasság vasárnapja"                                                      // LOKAL_SLAV_DRUHA_VELK_NEDELA_HU
,"A Szombathelyi egyházmegyében"                                                                                // LOKAL_SLAV_SZOMBATHELYI_EGYH
,"A Nagyszombati főegyházmegyében: a főegyházmegye fővédőszentje"                                               // LOKAL_SLAV_NAGYSZ_PATRON
,"A Szeged-Csanádi egyházmegye északi részében: az egyházmegye védőszentje; főünnep"                            // LOKAL_SLAV_SZEGED_CSAN_PATRON // 2013-06-27: ??? neviem, odkiaľ sa to tu vzalo
,"A Pécsi egyházmegyében"                                                                                       // LOKAL_SLAV_PECSI_EGYH
,"A Pécsi egyházmegyében: az egyházmegye védőszentje; főünnep"                                                  // LOKAL_SLAV_PECSI_EGYH_PATRON
,"A Szeged-Csanádi egyházmegye északi részében; ünnep"                                                          // LOKAL_SLAV_SZEGED_CSAN_EGYH
,"A Veszprémi főegyházmegyében: Szent Anna, a főegyházmegye védőszentje; ünnep"                                 // LOKAL_SLAV_VESZPREMI_EGYH_PATRON
,"A Győri és Székesfehérvári egyházmegyében: az egyházmegye védőszentje"                                        // LOKAL_SLAV_GYORI_SZEKESFEH_EGYH
,"A Kaposvári egyházmegyében; ünnep"                                                                            // LOKAL_SLAV_KAPORSVAR_FELSZ
,"A Váci egyházmegyében; ünnep"                                                                                 // LOKAL_SLAV_VACI_FELSZ
,"A Kalocsa-Kecskeméti főegyházmegyében: a főegyházmegye védőszentje; főünnep"                                  // LOKAL_SLAV_KAL_KECS_FOEGYH
,"A Esztergom-Budapesti főegyházmegyében: a főszékesegyházban; főünnep"                                         // LOKAL_SLAV_ESZTERGOM_BUDA_FOEGYH
,"A főszékesegyházban; főünnep"                                                                                 // LOKAL_SLAV_KAL_KECS_FELSZ
,"A Győri egyházmegyében: a székesegyház felszentelése; ünnep"                                                  // LOKAL_SLAV_GYORI_SZEKESEGYH_FELSZ
,"A Váci egyházmegyében: Szent Mihály főangyal, az egyházmegye védőszentje"                                     // LOKAL_SLAV_VACI_PATRON
,"A Szeged-Csanádi egyházmegyében: az egyházmegye védőszentje; főünnep"                                         // LOKAL_SLAV_SZEGED_CSAN_PATRON2
,"A Veszprémi főegyházmegyében: a főszékesegyházban; főünnep"													// LOKAL_SLAV_VESZPREM_FOEGYH
,"csak a felszentelt templomokban"                                                                              // LOKAL_SLAV_KONSEKR_KOSTOLY_HU
,"A Szeged-Csanádi egyházmegyében: a székesegyházban; főünnep"                                                  // LOKAL_SLAV_SZEGED_CSAN_EGYH2
,"A Pécsi egyházmegyében: a Pécsi egyházmegye társvédőszentje; főünnep"                                         // LOKAL_SLAV_PECS_PATRON
,"A Szombathelyi egyházmegyébe: az egyházmegye védőszentje; főünnep"                                            // LOKAL_SLAV_SZOMBATHELYI_PATRON
,"Székesfehérvár: a székesegyházban; főünnep"                                                                   // LOKAL_SLAV_SZEKESFEHERVAR_EGYH
,"Az Egri főegyházmegyében: a főegyházmegye védőszentje; ünnep"                                                 // LOKAL_SLAV_EGER_FOEGYH
,"Az Esztergomi főegyházmegyében; emléknap"                                                                     // LOKAL_SLAV_ESZTERGOM_EML
,"A Győri egyházmegyében"                                                                                       // LOKAL_SLAV_GYOR_EGYH
,"Az Esztergomi főegyházmegyében"                                                                               // LOKAL_SLAV_ESZTERGOM_FOEGYH
,"Az Egri főegyházmegyében"                                                                                     // LOKAL_SLAV_EGER_FOEGYH2
,"A Veszprémi főegyházmegyében: a főegyházmegye társvédőszentje; főünnep"                                       // LOKAL_SLAV_VESZPREM_FOEGYH_T
,"A Szatmári egyházmegyében; emléknap"                                                                          // LOKAL_SLAV_SZATMAR
,"v ostatních českých diecézích a v brněnské diecézi: památka; "HTML_LINE_BREAK"na Moravě mimo brněnskou diecézi: nezávazná památka" // LOKAL_SLAV_CESKO_BRNO
,"sviatok hlavnej patrónky "HTML_LINE_BREAK"(slovenskej) Kongregácie sestier dominikánok bl. Imeldy"            // LOKAL_SLAV_SVIATOK_OP_ZENY
,"len v Žilinskej diecéze"                                                                                      // LOKAL_SLAV_ZILINA
,"na Strahově: svátek, Nová Říše: památka"                                                                      // LOKAL_SLAV_OPRAEM_SVIATOK_STRAHOV
,"kanonie Teplá: slavnost"                                                                                      // LOKAL_SLAV_OPRAEM_SLAVNOST_TEPLA
,"jen kanonie Nová Říše"                                                                                        // LOKAL_SLAV_OPRAEM_NOVA_RISE
,"jen kanonie Strahov a Nová Říše"                                                                              // LOKAL_SLAV_OPRAEM_STRAHOV_NOVA_RISE
,"jen kanonie Želiv"                                                                                            // LOKAL_SLAV_OPRAEM_ZELIV
,"jen kanonie Strahov"                                                                                          // LOKAL_SLAV_OPRAEM_STRAHOV
,"Debrecen-Nyíregyháza és Kaposvár: "HTML_LINE_BREAK"Az egyházmegye védőszentje; főünnep"                       // LOKAL_SLAV_SZ_LASZLO
,"pre OSC: slávnosť"                                                                                            // LOKAL_SLAV_SLAVNOST_OSC
,"pre OFMConv.: sviatok"                                                                                        // LOKAL_SLAV_SVIATOK_OFMCONV
,"pre OFS: sviatok"                                                                                             // LOKAL_SLAV_SVIATOK_OFS
,"pre OFMConv., OFMCap: spomienka"                                                                              // LOKAL_SLAV_SPOMIENKA_OFMCONV_OFMCAP
,"pre OSC: slávnosť"                                                                                            // LOKAL_SLAV_SPOMIENKA_OSC
,"pre Slovensko zatiaľ nedovolené slávenie"                                                                     // LOKAL_SLAV_NEDOVOLENE_SK
,"Katonai Ordinariátus: "HTML_LINE_BREAK"Az Ordinariátus védőszentje; főünnep"                                  // LOKAL_SLAV_KATONAI_ORDINARIAT
,"Debrecen-Nyíregyháza: "HTML_LINE_BREAK"A székesegyház felszentelése; főünnep"                                 // LOKAL_SLAV_DEBR_NYIREGY
,"jen kanonie Doksany"                                                                                          // LOKAL_SLAV_OPRAEM_DOKSANY
,"jen kanonie Doksany a Želiv"                                                                                  // LOKAL_SLAV_OPRAEM_DOKSANY_ZELIV
,"jen kanonie Teplá"                                                                                            // LOKAL_SLAV_OPRAEM_TEPLA
,"len pre len pre Kongregáciu sestier Matky Božieho Milosrdenstva"                                              // LOKAL_SLAV_KONGREGACIA_SMBM
,"pro FMA památka"                                                                                              // LOKAL_SLAV_SPOMIENKA_FMA_CZ
,"pro FMA nezávazná památka"                                                                                    // LOKAL_SLAV_LUB_SPOMIENKA_FMA_CZ
,"pro VDB svátek"                                                                                               // LOKAL_SLAV_SVIATOK_VDB_CZ
,"pro FMA slavnost"                                                                                             // LOKAL_SLAV_SLAVNOST_FMA_CZ
};

// names of liturgical colors
const char *nazov_farby_jazyk[POCET_FARIEB_REALNYCH + 1][POCET_JAZYKOV + 1] =
{
	{ "___", "___", "___", "___", "___", "___", "___", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "červená", "červená", "red", "ruber", "", "červená", "piros", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "biela", "bílá", "white", "albus", "", "bílá", "fehér", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "zelená", "zelená", "green", "viridis", "", "zelená", "zöld", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "fialová", "fialová", "purple", "violaceus", "", "fialová", "lila", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "ružová", "růžová", "rose", "rosaceus", "", "růžová", "rózsaszín", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "čierna", "černá", "black", "niger", "", "černá", "fekete", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
};

#define		nazov_farby(a)	nazov_farby_jazyk[a][_global_jazyk]

// 2009-08-26: zmena na štandardné HTML elementy, aby sa dalo používať ako inline CSS style
// codes for colors - HTML specific
const char *html_farba_pozadie[POCET_FARIEB_REALNYCH + 1] =
{ "#000000" /* "black" */, "#ff0000" /* "red" */, "#ffffff" /* "white" */, "#008000" /* "green" */, "#800080" /* "purple" */, "#FF6699" /* "fuchsia" */, "#000000" /* black */ };

// codes for colors - HTML specific
const char *html_farba_popredie[POCET_FARIEB_REALNYCH + 1] =
{ "#ffffff" /* "white" */, "#ffffff" /* "white" */, "#000000" /* "black" */, "#ffffff" /* "white" */, "#ffffff" /* "white" */, "#0000ff" /* "blue" */, "#ffffff" /* "white" */ };

// codes for colors - HTML specific
const char *html_farba_okraj[POCET_FARIEB_REALNYCH + 1] =
{ "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* black */ };

// codes for number of the week from psaltery (psalterium per quattuor hebdomadas distributum)
const char *rimskymi_tyzden_zaltara[ZVAZKY_LH + 1] =
{ "_", "I", "II", "III", "IV" };

// const: ordinal number of the first day in specific month
const short int prvy_den[12] =
{ 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

// const: number (count) of days in specific month
short int pocet_dni[12] =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// const: "the Sunday's letter" A--g
const char char_nedelne_pismeno[POCET_DNI] =
{ 'b', 'c', 'd', 'e', 'f', 'g', 'A' };

// const: the Sunday's cycle A--C
const char char_nedelny_cyklus[POCET_NEDELNY_CYKLUS] =
{ 'A', 'B', 'C' };

// names of the days in week, starting with Sunday (lowercase) / nazov_dna: string pre nazov dna; suhlasi s struct tm.tm_wday; 
// Weekday (0--6; Sunday/nedela = 0)
const char *nazov_dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{
	{ "nedeľa", "neděle", "Sunday", "dominica", "", "neděle", "vasárnap", "воскресенье", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "pondelok", "pondělí", "Monday", "feria secunda", "", "pondělí", "hétfő", "понедельник", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "utorok", "úterý", "Tuesday", "feria tertia", "", "úterý", "kedd", "вторник", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "streda", "středa", "Wednesday", "feria quarta", "", "středa", "szerda", "среда", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "štvrtok", "čtvrtek", "Thursday", "feria quinta", "", "čtvrtek", "csütörtök", "четверг", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "piatok", "pátek", "Friday", "feria sexta", "", "pátek", "péntek", "пятница", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "sobota", "sobota", "Saturday", "sabbatum", "", "sobota", "szombat", "суббота", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "neznámy", "neznámý", "unknown", "???", "", "neznámý", "ismeretlen", "неизвестный", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_dna(a)	nazov_dna_jazyk[a][_global_jazyk]

// names of the days in week, starting with Sunday (sentence case)
const char *nazov_Dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{
	{ "Nedeľa", "Neděle", "Sunday", "Dominica", "", "Neděle", "Vasárnap", "Воскресенье", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Pondelok", "Pondělí", "Monday", "Feria secunda", "", "Pondělí", "Hétfő", "Понедельник", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Utorok", "Úterý", "Tuesday", "Feria tertia", "", "Úterý", "Kedd", "Вторник", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Streda", "Středa", "Wednesday", "Feria quarta", "", "Středa", "Szerda", "Среда", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Štvrtok", "Čtvrtek", "Thursday", "Feria quinta", "", "Čtvrtek", "Csütörtök", "Четверг", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Piatok", "Pátek", "Friday", "Feria sexta", "", "Pátek", "Péntek", "Пятница", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Sobota", "Sobota", "Saturday", "Sabbatum", "", "Sobota", "Szombat", "Суббота", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Neznámy", "Neznámý", "unknown", "???", "", "Neznámý", "Ismeretlen", "Неизвестный", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_Dna(a)	nazov_Dna_jazyk[a][_global_jazyk]

// names of the days in week, starting with Sunday (uppercase)
const char *nazov_DNA_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{
	{ "NEDEĽA", "NEDĚLE", "SUNDAY", "DOMINICA", "", "NEDĚLE", "VASÁRNAP", "ВОСКРЕСЕНЬЕ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "PONDELOK", "PONDĚLÍ", "MONDAY", "FERIA SECUNDA", "", "PONDĚLÍ", "HÉTFŐ", "ПОНЕДЕЛЬНИК", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "UTOROK", "ÚTERÝ", "TUESDAY", "FERIA TERTIA", "", "ÚTERÝ", "KEDD", "вторник", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "STREDA", "STŘEDA", "WEDNESDAY", "FERIA QUARTA", "", "STŘEDA", "SZERDA", "СРЕДА", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "ŠTVRTOK", "ČTVRTEK", "THURSDAY", "FERIA QUINTA", "", "ČTVRTEK", "CSÜTÖRTÖK", "ЧЕТВЕРГ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "PIATOK", "PÁTEK", "FRIDAY", "FERIA SEXTA", "", "PÁTEK", "PÉNTEK", "ПЯТНИЦА", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "SOBOTA", "SOBOTA", "SATURDAY", "SABBATUM", "", "SOBOTA", "SZOMBAT", "СУББОТА", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "NEZNÁMY", "NEZNÁMÝ", "UNKNOWN", "???", "", "NEZNÁMÝ", "ISMERETLEN", "НЕИЗВЕСТНЫЙ", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_DNA(a)	nazov_DNA_jazyk[a][_global_jazyk]

// names of the days in week, starting with Sunday (lowercase without special characters - plain ASCII (0--128) only)
const char *nazov_dna_asci_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] =
{
	{ "nedela", "nedele", "Sunday", "Dominica", "", "nedele", "vasarnap", "Sunday", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "pondelok", "pondeli", "Monday", "Feria secunda", "", "pondeli", "hetfo", "Monday", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "utorok", "utery", "Tuesday", "Feria tertia", "", "utery", "kedd", "Tuesday", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "streda", "streda", "Wednesday", "Feria quarta", "", "streda", "szerda", "Wednesday", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "stvrtok", "ctvrtek", "Thursday", "Feria quinta", "", "ctvrtek", "csutortok", "Thursday", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "piatok", "patek", "Friday", "Feria sexta", "", "patek", "pentek", "Friday", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "sobota", "sobota", "Saturday", "Sabbatum", "", "sobota", "szombat", "Saturday", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "neznamy", "neznamy", "unknown", "???", "", "neznamy", "ismeretlen", "unknown", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_dna_asci(a)	nazov_dna_asci_jazyk[a][_global_jazyk]

// 2011-05-17: doplnené
#define KONCOVKA_DNA_HU "JA" // vasárnapja
#define KONCOVKA_DNA_HU_SMALL "ja"

// two/three-letter abbreviations of the names of the days in week, starting with Sunday (sentence case)
const char *nazov_Dn_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{
	{ "Ne", "Ne", "Sun", "Do", "", "Ne", "V", "Вс", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Po", "Po", "Mon", "F2", "", "Po", "H", "Пн", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Ut", "Út", "Tue", "F3", "", "Út", "K", "Вт", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "St", "St", "Wed", "F4", "", "St", "Sze", "Ср", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Št", "Čt", "Thu", "F5", "", "Čt", "Cs", "Чт", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Pi", "Pá", "Fri", "F6", "", "Pá", "P", "Пт", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "So", "So", "Sat", "S&#225;", "", "So", "Szo", "Сб", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "??", "??", "???", "", "", "??", "??", "??", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_Dn(a)	nazov_Dn_jazyk[a][_global_jazyk]

// two/three-letter abbreviations of the names of the days in week, starting with Sunday used for anchors (uppercase, no need to translate; based on Slovak)
// 2006-08-01: používa sa pre HTML kotvy, ktoré nezávisia od jazykovej mutácie
const char *nazov_DN_asci[POCET_DNI + 1] =
{ "NE", "PO", "UT", "STR", "STV", "PI", "SO", "??" };

// two/three-letter abbreviations of the names of the days in week, starting with Sunday used for debug info (lowercase, no need to translate; based on Slovak)
const char *nazov_dn_asci[POCET_DNI + 1] =
{ "ne", "po", "ut", "str", "stv", "pi", "so", "??" };

// the names of the months (lowecase) / nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
// Month (0--11)
const char *nazov_mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{
	{ "január", "leden", "January", "ianuarius", "", "leden", "január", "январь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "február", "únor", "February", "februarius", "", "únor", "február", "февраль", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "marec", "březen", "March", "martius", "", "březen", "március", "март", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "apríl", "duben", "April", "aprilis", "", "duben", "április", "апреля", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "máj", "květen", "May", "maius", "", "květen", "május", "мая", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "jún", "červen", "June", "iunius", "", "červen", "június", "июнь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "júl", "červenec", "July", "iulius", "", "červenec", "július", "июль", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "august", "srpen", "August", "augustus", "", "srpen", "augusztus", "август", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "september", "září", "September", "september", "", "září", "szeptember", "сентябрь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "október", "říjen", "October", "october", "", "říjen", "október", "октября", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "november", "listopad", "November", "november", "", "listopad", "november", "ноябрь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "december", "prosinec", "December", "december", "", "prosinec", "december", "декабрь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "neznámy", "neznámý", "unknown", "___", "", "neznámý", "ismeretlen", "неизвестный", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_mesiaca(a)	nazov_mesiaca_jazyk[a][_global_jazyk]

// the names of the months (sentence case)
const char *nazov_Mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{
	{ "Január", "Leden", "January", "Ianuarius", "", "Leden", "Január", "Январь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Február", "Únor", "February", "Februarius", "", "Únor", "Február", "Февраль", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Marec", "Březen", "March", "Martius", "", "Březen", "Március", "Март", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Apríl", "Duben", "April", "Aprilis", "", "Duben", "Április", "Апреля", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Máj", "Květen", "May", "Maius", "", "Květen", "Május", "Мая", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Jún", "Červen", "June", "Iunius", "", "Červen", "Június", "Июнь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Júl", "Červenec", "July", "Iulius", "", "Červenec", "Július", "Июль", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "August", "Srpen", "August", "Augustus", "", "Srpen", "Augusztus", "Август", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "September", "Září", "September", "September", "", "Září", "Szeptember", "Сентябрь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Október", "Říjen", "October", "October", "", "Říjen", "Október", "Октября", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "November", "Listopad", "November", "November", "", "Listopad", "November", "Ноябрь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "December", "Prosinec", "December", "December", "", "Prosinec", "December", "Декабрь", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Neznámy", "Neznámý", "unknown", "???", "", "Neznámý", "Ismeretlen", "Неизвестный", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_Mesiaca(a)	nazov_Mesiaca_jazyk[a][_global_jazyk]

// the names of the months (uppercase)
const char *nazov_MESIACA_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{
	{ "JANUÁR", "LEDEN", "JANUARY", "IANUARIUS", "", "LEDEN", "JANUÁR", "ЯНВАРЬ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "FEBRUÁR", "ÚNOR", "FEBRUARY", "FEBRUARIUS", "", "ÚNOR", "FEBRUÁR", "ФЕВРАЛЬ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "MAREC", "BŘEZEN", "MARCH", "MARTIUS", "", "BŘEZEN", "MÁRCIUS", "МАРТ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "APRÍL", "DUBEN", "APRIL", "APRILIS", "", "DUBEN", "ÁPRILIS", "АПРЕЛЯ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "MÁJ", "KVĚTEN", "MAY", "MAIUS", "", "KVĚTEN", "MÁJUS", "МАЯ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "JÚN", "ČERVEN", "JUNE", "IUNIUS", "", "ČERVEN", "JÚNIUS", "ИЮНЬ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "JÚL", "ČERVENEC", "JULY", "IULIUS", "", "ČERVENEC", "JÚLIUS", "ИЮЛЬ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "AUGUST", "SRPEN", "AUGUST", "AUGUSTUS", "", "SRPEN", "AUGUSZTUS", "АВГУСТ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "SEPTEMBER", "ZÁŘÍ", "SEPTEMBER", "SEPTEMBER", "", "ZÁŘÍ", "SZEPTEMBER", "СЕНТЯБРЬ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "OKTÓBER", "ŘÍJEN", "OCTOBER", "OCTOBER", "", "ŘÍJEN", "OKTÓBER", "ОКТЯБРЯ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "NOVEMBER", "LISTOPAD", "NOVEMBER", "NOVEMBER", "", "LISTOPAD", "NOVEMBER", "НОЯБРЬ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "DECEMBER", "PROSINEC", "DECEMBER", "DECEMBER", "", "PROSINEC", "DECEMBER", "ДЕКАБРЬ", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "NEZNÁMY", "NEZNÁMÝ", "UNKNOWN", "???", "", "NEZNÁMÝ", "ISMERETLEN", "НЕИЗВЕСТНЫЙ", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_MESIACA(a)	nazov_MESIACA_jazyk[a][_global_jazyk]

// the names of the months (lowecase without special characters, plain ASCII 0--128)
const char *nazov_mesiaca_asci_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] =
{
	{ "januar", "leden", "January", "Ianuarius", "", "leden", "januar", "January", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "februar", "unor", "February", "Februarius", "", "unor", "februar", "February", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "marec", "brezen", "March", "Martius", "", "brezen", "marcius", "March", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "april", "duben", "April", "Aprilis", "", "duben", "aprilis", "April", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "maj", "kveten", "May", "Maius", "", "kveten", "majus", "May", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "jun", "cerven", "June", "Iunius", "", "cerven", "junius", "June", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "jul", "cervenec", "July", "Iulius", "", "cervenec", "julius", "July", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "august", "srpen", "August", "Augustus", "", "srpen", "augusztus", "August", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "september", "zari", "September", "September", "", "zari", "szeptember", "September", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "oktober", "rijen", "October", "October", "", "rijen", "oktober", "October", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "november", "listopad", "November", "November", "", "listopad", "november", "November", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "december", "prosinec", "December", "December", "", "prosinec", "december", "December", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "neznamy", "neznamy", "unknown", "___", "", "neznamy", "ismeretlen", "unknown", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_mesiaca_asci(a)	nazov_mesiaca_asci_jazyk[a][_global_jazyk]

// the names of the months (lowercase) in genitive grammatically 2.th declination?; in English: "IN that month" or "OF that month" / genitív == 2. pád, koho/čoho
// usage: when generated string for date, e.g. en: "1st January 2000", sk: "1. januára 2000"
// 2007-03-20: pridaný genitív názvu mesiaca kvôli latinčine
const char *nazov_mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{
	{ "januára", "ledna", "January", "ianuarii", "", "ledna", "január", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "februára", "února", "February", "februarii", "", "února", "február", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "marca", "března", "March", "martii", "", "března", "március", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "apríla", "dubna", "April", "aprilis", "", "dubna", "április", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "mája", "května", "May", "maii", "", "května", "május", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "júna", "června", "June", "iunii", "", "června", "június", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "júla", "července", "July", "iulii", "", "července", "július", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "augusta", "srpna", "August", "augusti", "", "srpna", "augusztus", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "septembra", "září", "September", "septembris", "", "září", "szeptember", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "októbra", "října", "October", "octobris", "", "října", "október", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "novembra", "listopadu", "November", "novembris", "", "listopadu", "november", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "decembra", "prosince", "December", "decembris", "", "prosince", "december", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "neznámeho", "neznámého", "unknown", "___", "", "neznámého", "ismeretlen", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_mesiaca_gen(a)	nazov_mesiaca_gen_jazyk[a][_global_jazyk]

// 2007-03-20: pridaný genitív názvu mesiaca kvôli latinčine
const char *nazov_Mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{
	{ "Januára", "Ledna", "January", "Ianuarii", "", "Ledna", "Január", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Februára", "Února", "February", "Februarii", "", "Února", "Február", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Marca", "Března", "March", "Martii", "", "Března", "Március", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Apríla", "Dubna", "April", "Aprilis", "", "Dubna", "Április", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Mája", "Května", "May", "Maii", "", "Května", "Május", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Júna", "Června", "June", "Iunii", "", "Června", "Június", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Júla", "Července", "July", "Iulii", "", "Července", "Július", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Augusta", "Srpna", "August", "Augusti", "", "Srpna", "Augusztus", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Septembra", "Září", "September", "Septembris", "", "Září", "Szeptember", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Októbra", "Října", "October", "Octobris", "", "Října", "Október", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Novembra", "Listopadu", "November", "Novembris", "", "Listopadu", "November", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Decembra", "Prosince", "December", "Decembris", "", "Prosince", "December", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Neznámeho", "Neznámého", "Unknown", "___", "", "Neznámého", "Ismeretlen", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define		nazov_Mesiaca_gen(a)	nazov_Mesiaca_gen_jazyk[a][_global_jazyk]

// three-letter abbreviations of the names of the months used for anchors (uppercase, no need to translate; based on Slovak)
const char *nazov_MES[POCET_MESIACOV + 1] =
{ "JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC", "___" };

// three-letter abbreviations of the names of the months used for anchors (lowercase, no need to translate; based on Slovak)
const char *nazov_mes[POCET_MESIACOV + 1] =
{ "jan", "feb", "mar", "apr", "maj", "jun", "jul", "aug", "sep", "okt", "nov", "dec", "___" };

// ordinal numbers for first few Sundays (sentence case) - used for special occasions currently only in Slovak; no need to change
// 2008-12-20: pridaný reťazec pre poradové číslo - používa sa v init_global_string() pre nedele niektorých období [zatiaľ iba v slovenčine]
const char *poradie_Slovom_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1] = 
{
	{ "Prvá", "První", "", "", "", "První", "1.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Druhá", "Druhá", "", "", "", "Druhá", "2.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Tretia", "Třetí", "", "", "", "Třetí", "3.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Štvrtá", "Čtvrtá", "", "", "", "Čtvrtá", "4.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Piata", "Pátá", "", "", "", "Pátá", "5.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Šiesta", "Šestá", "", "", "", "Šestá", "6.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Siedma", "Sedmá", "", "", "", "Sedmá", "7.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Ôsma", "Osmá", "", "", "", "Osmá", "8.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Deviata", "Devátá", "", "", "", "Devátá", "9.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "Desiata", "Desátá", "", "", "", "Desátá", "10.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "11. ", "11", "11", "11", "11", "11", "11.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "12. ", "12", "12", "12", "12", "12", "12.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "13. ", "13", "13", "13", "13", "13", "13.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "14. ", "14", "14", "14", "14", "14", "14.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "15. ", "15", "15", "15", "15", "15", "15.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "16. ", "16", "16", "16", "16", "16", "16.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "17. ", "17", "17", "17", "17", "17", "17.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "18. ", "18", "18", "18", "18", "18", "18.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "19. ", "19", "19", "19", "19", "19", "19.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "20. ", "20", "20", "20", "20", "20", "20.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "21. ", "21", "21", "21", "21", "21", "21.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "22. ", "22", "22", "22", "22", "22", "22.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "23. ", "23", "23", "23", "23", "23", "23.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "24. ", "24", "24", "24", "24", "24", "24.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "25. ", "25", "25", "25", "25", "25", "25.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "26. ", "26", "26", "26", "26", "26", "26.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "27. ", "27", "27", "27", "27", "27", "27.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "28. ", "28", "28", "28", "28", "28", "28.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "29. ", "29", "29", "29", "29", "29", "29.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "30. ", "30", "30", "30", "30", "30", "30.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "31. ", "31", "31", "31", "31", "31", "31.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "32. ", "32", "32", "32", "32", "32", "32.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "33. ", "33", "33", "33", "33", "33", "33.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "34. ", "34", "34", "34", "34", "34", "34.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

// the same as "poradie_Slovom_jazyk" ordinal numbers for first few Sundays (uppercase) - used for special occasions currently only in Slovak; no need to change
const char *poradie_SLOVOM_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1] = 
{
	{ "PRVÁ", "PRVNÍ", "", "", "", "PRVNÍ", "1.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "DRUHÁ", "DRUHÁ", "", "", "", "DRUHÁ", "2.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "TRETIA", "TŘETÍ", "", "", "", "TŘETÍ", "3.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "ŠTVRTÁ", "ČTVRTÁ", "", "", "", "ČTVRTÁ", "4.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "PIATA", "PÁTÁ", "", "", "", "PÁTÁ", "5.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "ŠIESTA", "ŠESTÁ", "", "", "", "ŠESTÁ", "6.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "SIEDMA", "SEDMÁ", "", "", "", "SEDMÁ", "7.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "OSMA", "OSMÁ", "", "", "", "OSMÁ", "8.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "DEVIATA", "DEVÁTÁ", "", "", "", "DEVÁTÁ", "9.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "DESIATA", "DESÁTÁ", "", "", "", "DESÁTÁ", "10.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "11. ", "11", "11", "11", "11", "11", "11.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "12. ", "12", "12", "12", "12", "12", "12.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "13. ", "13", "13", "13", "13", "13", "13.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "14. ", "14", "14", "14", "14", "14", "14.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "15. ", "15", "15", "15", "15", "15", "15.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "16. ", "16", "16", "16", "16", "16", "16.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "17. ", "17", "17", "17", "17", "17", "17.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "18. ", "18", "18", "18", "18", "18", "18.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "19. ", "19", "19", "19", "19", "19", "19.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "20. ", "20", "20", "20", "20", "20", "20.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "21. ", "21", "21", "21", "21", "21", "21.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "22. ", "22", "22", "22", "22", "22", "22.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "23. ", "23", "23", "23", "23", "23", "23.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "24. ", "24", "24", "24", "24", "24", "24.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "25. ", "25", "25", "25", "25", "25", "25.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "26. ", "26", "26", "26", "26", "26", "26.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "27. ", "27", "27", "27", "27", "27", "27.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "28. ", "28", "28", "28", "28", "28", "28.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "29. ", "29", "29", "29", "29", "29", "29.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "30. ", "30", "30", "30", "30", "30", "30.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "31. ", "31", "31", "31", "31", "31", "31.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "32. ", "32", "32", "32", "32", "32", "32.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "33. ", "33", "33", "33", "33", "33", "33.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
	, { "34. ", "34", "34", "34", "34", "34", "34.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

// the names of rites
const char *nazov_ritu_jazyka[POCET_RITOV + 1][POCET_JAZYKOV + 1] =
{
	{
		"rímskokatolícky",
		"římskokatolický",
		"Roman catholic",
		"Roman catholic",
		"Roman catholic",
		"římskokatolický",
		"római katolikus",
		"ru_text",
		/* STRING_2_FOR_NEW_LANGUAGE */
	},
	{
		"gréckokatolícky",
		"řeckokatolický",
		"Greek catholic",
		"Greek catholic",
		"Greek catholic",
		"řeckokatolický",
		"görög katolikus",
		"ru_text",
		/* STRING_2_FOR_NEW_LANGUAGE */
	},
};
#define nazov_ritu(a) nazov_ritu_jazyka[a][_global_jazyk]

// the names of languages
// 2006-07-11: Pridané kvôli jazykovým mutáciám
const char *nazov_jazyka[POCET_JAZYKOV + 1] =
{ "slovenčina", "čeština", "English", "lingua latina", "(neurčený)", "čeština-dominikáni", "magyar", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// language codes; internal usage for HTTP requests
const char *skratka_jazyka[POCET_JAZYKOV + 1] =
{ "sk", "cz", "en", "la", "??", "c2", "hu", "ru", /* STRING_1_FOR_NEW_LANGUAGE */ };

// language codes; internal usage for include directories (postfix of directory/folder name); postfix MUST NOT contain slash/backslash
// 2006-07-13 a 17: Pridané kvôli jazykovým mutáciám - postfix pre include adresár
const char *postfix_jazyka[POCET_JAZYKOV + 1] =
{ "", "cz", "en", "la", "", "czop", "hu", "ru", /* STRING_1_FOR_NEW_LANGUAGE */ };
// Poznámka: Postfix nesmie obsahovať na začiatku oddeľovač (slash resp. backslash); musí sa jednať o podadresár pod include

const short int format_datumu[POCET_JAZYKOV + 1] = {
	/* sk */ FORMAT_DATUMU_DEN_MESIAC_ROK,
	/* cz */ FORMAT_DATUMU_DEN_MESIAC_ROK,
	/* en */ FORMAT_DATUMU_MESIAC_DEN_ROK,
	/* la */ FORMAT_DATUMU_DEN_MESIAC_ROK,
	/* ?? */ FORMAT_DATUMU_DEN_MESIAC_ROK,
	/* czop */ FORMAT_DATUMU_DEN_MESIAC_ROK,
	/* hu */ FORMAT_DATUMU_ROK_MESIAC_DEN,
	/* ru */ FORMAT_DATUMU_DEN_MESIAC_ROK,
	/* ADD_VALUE_FOR_NEW_LANGUAGE */
};

// filename of CSS file; the number of CSS does not directly correspond to the number of languages
// 2006-08-08: Pridané kvôli rôznym css
// 2013-12-09: Always use "breviar.css" plus override eventually
const char *nazov_css[POCET_CSS + 1] =
{ "(css neurčené)", "breviar.css", "breviar-invert-colors.css", "breviar-kbd.css", "ebreviar-cz.css" };

const char *skratka_css[POCET_CSS + 1] =
{ "__", "def", "invert", "kbd", "cz" };

// 2012-04-03: Pridané kvôli jazykovým mutáciám -- default CSS pre daný jazyk | možno do budúcnosti možnosť default nastavenia v config (konfiguračnom súbore) | use CSS_breviar_sk
const short int default_css_jazyk[POCET_JAZYKOV + 1] =
{ CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_sk, /* ADD_VALUE_FOR_NEW_LANGUAGE */ };

// CSS obsahujuci invertovane farby | CSS for "night mode" (inverted colors) - includes ONLY ammendment to base css (breviar.css)
const char *nazov_css_invert_colors = "breviar-invert-colors.css";

// CSS obsahujuci force normal font weight | CSS for "no-bold mode" (only normal font) - includes ONLY ammendment to base css (breviar.css)
const char *nazov_css_normal_font_weight = "breviar-normal-font.css";

// blind-friendly CSS | includes ONLY ammendment to base css (breviar.css)
const char *nazov_css_blind_friendly = "breviar-blind-friendly.css";

// language charset (encoding); used for HTML heading | use CHARSET_UTF_8
const short int charset_jazyka[POCET_JAZYKOV + 1] =
{ CHARSET_UTF_8, CHARSET_UTF_8, CHARSET_UTF_8, CHARSET_UTF_8, CHARSET_UTF_8, CHARSET_UTF_8, CHARSET_UTF_8, CHARSET_UTF_8, /* ADD_VALUE_FOR_NEW_LANGUAGE */ };

const char *nazov_charset[POCET_CHARSET + 1] =
{ "utf-8", "windows-1250" };

const char *skratka_static_text[POCET_STATIC_TEXTOV + 1] =
{ "", "ma", "ord" };

// 2011-05-06: pridané kvôli možnosti voľby písma
const char *nazov_fontu[POCET_FONTOV + 1] =
{ "", "podľa CSS", "podľa výberu", "Cambria", "Candara", "Georgia", "Tahoma", "Helvetica", "serif", "sans-serif" };

const char *nazov_fontu_CHECKBOX[POCET_JAZYKOV + 1] =
{ "podľa výberu", "podle výběru", "according to checkbox above", "checkbox", "", "podle výběru", "checkbox", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *nazov_fontu_CSS[POCET_FONTOV + 1] =
{ "podľa CSS", "podle CSS", "according to CSS", "CSS", "CSS", "podle CSS", "CSS szerint" };
// 2011-05-13: pridané kvôli možnosti voľby veľkosti písma

const char *nazov_font_size_jazyk[POCET_FONT_SIZE + 1][POCET_JAZYKOV + 1] = 
{
	{ "", "", "", "", "", "", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "podľa CSS", "podle CSS", "according to CSS", "CSS", "", "podle CSS", "CSS szerint", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "malilinké", "malinkaté", "xx-small", "xx-small", "", "malinkaté", "apró", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "veľmi malé", "velmi malé", "extra small", "extra small", "", "velmi malé", "nagyon kicsi", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "malé", "malé", "small", "small", "", "malé", "kicsi", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "stredné", "střední", "medium", "medium", "", "střední", "közepes", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "veľké", "veliké", "large", "large", "", "veliké", "nagy", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "veľmi veľké", "velmi veliké", "extra large", "extra large", "", "velmi veliké", "nagyon nagy", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ },
	{ "obrovské", "obrovské", "xx-large", "xx-large", "", "obrovské", "óriási", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }
};

#define nazov_font_size(a) nazov_font_size_jazyk[a][_global_jazyk]

const char *nazov_font_size_css[POCET_FONT_SIZE + 1] =
{ "", "inherit", "xx-small", "x-small", "small", "medium", "large", "x-large", "xx-large" };

// special button: Details...
#ifndef HTML_BUTTON_DETAILY
#define HTML_BUTTON_DETAILY	html_button_nazov_modlitby_jazyk[MODL_DETAILY][_global_jazyk]
#endif

// special button: Show prayer
const char *html_button_det_show[POCET_JAZYKOV + 1] = 
{ "Zobraz modlitbu", "Ukaž modlitbu", "Show prayer", "Ostendo oratio", "", "Ukaž modlitbu", "Ima megjelenítése", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#ifndef HTML_BUTTON_DET_SHOW
#define HTML_BUTTON_DET_SHOW	html_button_det_show[_global_jazyk]
#endif

// special button: Defaults
const char *html_button_det_defaults[POCET_JAZYKOV + 1] = 
{ "Pôvodné hodnoty", "Původní hodnoty", "Defaults", "___", "", "Původní hodnoty", "Alapértelmezett", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#ifndef HTML_BUTTON_DET_DEFAULTS
#define HTML_BUTTON_DET_DEFAULTS	html_button_det_defaults[_global_jazyk]
#endif

// special button (today): Show
const char *html_button_dnes_show[POCET_JAZYKOV + 1] = 
{ "Zobraziť", "Ukaž", "Show", "___", "", "Ukaž", "Megjelenítés", "Показ", /* STRING_1_FOR_NEW_LANGUAGE */ };
#ifndef HTML_BUTTON_DNES_SHOW
#define HTML_BUTTON_DNES_SHOW	html_button_dnes_show[_global_jazyk]
#endif

// special button (today): Defaults (clear form)
// const char *html_button_dnes_defaults[POCET_JAZYKOV + 1] = 
// { "Vyčisti", "Vyčisti", "Clear", "???", "", "Vyčisti", "Töröl", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#ifndef HTML_BUTTON_DNES_DEFAULTS
#define HTML_BUTTON_DNES_DEFAULTS	HTML_BUTTON_DET_DEFAULTS
#endif

// special button (today): Apply settings/options
const char *html_button_dnes_apply[POCET_JAZYKOV + 1] = 
{ "Potvrdiť", "Potvrdit", "Apply", "___", "", "Potvrdit", "Alkalmaz", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#ifndef HTML_BUTTON_DNES_APPLY_SETTINGS
#define HTML_BUTTON_DNES_APPLY_SETTINGS	html_button_dnes_apply[_global_jazyk]
#endif

// special button (today): Apply options 2 (various choices)
const char *html_button_dnes_apply2[POCET_JAZYKOV + 1] = 
{ "Uložiť", "Uložit", "Save", "___", "", "Uložit", "Alkalmaz", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#ifndef HTML_BUTTON_DNES_APPLY_CHOICES
#define HTML_BUTTON_DNES_APPLY_CHOICES html_button_dnes_apply2[_global_jazyk]
#endif

// html <title> element for generated pages
const char *html_title[POCET_JAZYKOV + 1] = 
{ "Liturgia hodín", "Liturgie hodin", "Liturgy of Hours", "Liturgia horarum", "", "Liturgie hodin", "Az Imaórák Liturgiája", "Литургия часов", /* STRING_1_FOR_NEW_LANGUAGE */ };

// html <title> element for pages generated for batch mode
const char *html_title_batch_mode[POCET_JAZYKOV + 1] = 
{ "Liturgia hodín – statické texty", "Liturgie hodin – statické texty", "Liturgy of Hours – static texts", "la_", "", "Liturgie hodin – statické texty", "Az Imaórák Liturgiája – állandó szövegek", "Литургия часов – статическиe тексты", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_error_template[POCET_JAZYKOV + 1] = 
{ "Šablóna pre modlitbu sa nenašla. Zrejme neexistuje súbor `%s'.", "Šablona pro modlitbu se nenašla. Patrně neexistuje soubor `%s'.", "Template for prayer not found. File `%s' does not exist.", "Template for prayer not found. File `%s' does not exist.", "", "Šablona pro modlitbu se nenašla. Patrně neexistuje soubor `%s'.", "Nem található sablon az imához. %s' fájl nem létezik.", "Template for prayer not found. File `%s' does not exist.", /* STRING_1_FOR_NEW_LANGUAGE */ };

// navigation buttons/texts: previous, next, today
const char *html_button_predchadzajuci_[POCET_JAZYKOV + 1] = { "Predchádzajúci", "Předchozí", "Previous", "Pr&#230;ced&#233;nte", "", "Předchozí", "Előző", "Предыдущий", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_button_nasledujuci_[POCET_JAZYKOV + 1] = { "Nasledujúci", "Následující", "Next", "Success&#237;vo", "", "Následující", "Következő", "Следующий", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_button_dnes[POCET_JAZYKOV + 1] = { "dnes", "dnes", "today", "hodie", "", "dnes", "ma", "сегодня", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_button_Dnes[POCET_JAZYKOV + 1] = { "Dnes", "Dnes", "Today", "Hodie", "", "Dnes", "Ma", "Cегодня", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_button_hore[POCET_JAZYKOV + 1] = { "^ ", "^ ", "^ ", "^ ", "^ ", "^ ", "^ ", "^ ", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_button_tento_den[POCET_JAZYKOV + 1] = { "tento deň", "tento den", "this day", "hodie", "", "tento den", "ez a nap", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// basic words: day, month, year
const char *html_text_den[POCET_JAZYKOV + 1] = { "deň", "den", "day", "die", "", "den", "nap", "день", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_mesiac[POCET_JAZYKOV + 1] = { "mesiac", "měsíc", "month", "mensis", "", "měsíc", "hó", "месяц", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_rok[POCET_JAZYKOV + 1] = { "rok", "rok", "year", "anno", "", "rok", "év", "год", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_Rok[POCET_JAZYKOV + 1] = { "Rok", "Rok", "Year", "Anno", "", "Rok", "Év", "Год", /* STRING_1_FOR_NEW_LANGUAGE */ };
// in the following: you MUST keep all %d, %c, %s etc. variables - these are replaced by numbers, characters, strings, etc. respectively
const char *html_text_Rok_x[POCET_JAZYKOV + 1] = { "Rok %d", "Rok %d", "Year %d", "Anno %d", "%d", "Rok %d", "%.d év", "%d. годa", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_zoznam_mesiacov[POCET_JAZYKOV + 1] = { "zoznam mesiacov", "seznam měsíců", "list of months", "", "", "seznam měsíců", "hónapok listája", "Список месяцев", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_modlitba[POCET_JAZYKOV + 1] = { "modlitba", "modlitba", "prayer", "ora", "", "modlitba", "imádság", "молитва", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_modlitby_pre_den[POCET_JAZYKOV + 1] = { "modlitby pre deň", "modlitby pro den", "prayers for date", "", "", "modlitby pro den", "", "молитвы за день", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_alebo_pre[POCET_JAZYKOV + 1] = { "alebo pre", "anebo pro", "or for", "vel per", "", "anebo pro", "vagy", "или для", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_dnesok[POCET_JAZYKOV + 1] = { "dnešok", "dnešní den", "today", "hodie", "", "dnešní den", "a mai nap imaórái", "сегодня", /* STRING_1_FOR_NEW_LANGUAGE */ };

// 2010-02-15: pridané kvôli "zoznam.htm" batch mode
const char *html_text_Breviar_dnes[POCET_JAZYKOV + 1] = { "Breviár dnes", "Breviář dnes", "Breviary today", "Liturgia horarum hodie", "", "Breviář dnes", "A mai nap imaórája", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_Dnesne_modlitby[POCET_JAZYKOV + 1] = { "Dnešné modlitby", "Dnešní modlitby", "Today's prayers", "la_hodie", "", "Dnešní modlitby", "A mai nap imái", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_Prehlad_mesiaca[POCET_JAZYKOV + 1] = { "Prehľad mesiaca", "Přehled měsíce", "Current month", "la_", "", "Přehled měsíce", "A hónap áttekintése", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// 2011-03-18: pridané do "zoznam.htm" batch mode -- kalendáre a hlavný nadpis
const char *html_text_batch_mode_h1[POCET_JAZYKOV + 1] = { "Liturgia hodín – Predgenerované modlitby", "Liturgie hodin – Předgenerované modlitby", "Liturgy of Hours – Pregenerated prayers", "la_", "", "Liturgie hodin – Předgenerované modlitby", "Az Imaórák Liturgiája – Előre generált imák", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_Kalendar[POCET_JAZYKOV + 1] = { "Kalendár", "Kalendář", "Proprietary calendary", "Propria", "", "Kalendář", "Naptár", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_Vysvetlivky[POCET_JAZYKOV + 1] =
{
	"Vysvetlivky",
	"Vysvětlivky",
	"Legenda",
	"Legenda",
	"",
	"Vysvětlivky",
	"Jelmagyarázat",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */ 
};

const char *html_text_dalsie_moznosti[POCET_JAZYKOV + 1] =
{
	"Výber ďalších možností",
	"Další možnosti výběru ",
	"Choose from above (buttons) or from the following options: ",
	"",
	"",
	"Další možnosti výběru",
	"További lehetőségek választása:",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_dalsie_moznosti_1[POCET_JAZYKOV + 1] =
{
	"Nastavenia",
	"Nastavení",
	"Settings",
	"",
	"",
	"Nastavení",
	"Beállítások",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_dalsie_moznosti_2[POCET_JAZYKOV + 1] =
{
	"Ďalšie zobrazenia",
	"Další zobrazení",
	"Other facilities",
	"",
	"",
	"Další zobrazení",
	"Más megjelenítési lehetőségek",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_prik_sviatky_atd[POCET_JAZYKOV + 1] = { "prikázané sviatky a slávnosti Pána v roku ", "zasvěcené svátky a slavnosti Páně v roce ", "obligatory celebrations in year ", "", "", "zasvěcené svátky a slavnosti Páně v roce", "kötelező ünnepek", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_lit_kalendar[POCET_JAZYKOV + 1] = { "liturgický kalendár pre", "liturgický kalendář pro", "liturgical calendar for", "", "", "liturgický kalendář pro", "liturgikus naptár", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_roku[POCET_JAZYKOV + 1] = { "roku", "roku", "of year", "anno", "", "roku", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_tabulka_pohyblive_od[POCET_JAZYKOV + 1] = { "tabuľka dátumov pohyblivých slávení od roku", "tabulka s daty proměnných slavností od roku", "table with dates of movable celebrations from year", "", "", "tabulka s daty proměnných slavností od roku", "a mozgó (változó) ünnepek táblázata a következő években", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_do_roku[POCET_JAZYKOV + 1] = { "do roku", "po rok", "till year", "", "", "po rok", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_zobrazit_linky[POCET_JAZYKOV + 1] = { "zobraziť tabuľku vrátane hypertextových odkazov na jednotlivé dni", "zobrazit tabulku s hypertextovými odkazy pro jednotlivé dny", "display the table including hypertext links to each date", "", "", "zobrazit tabulku s hypertextovými odkazy pro jednotlivé dny", "A táblázat megjelenítése az egyes napokhoz tartozó hiperhivatkozásokkal együtt.", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_pre_cezrocne_obd[POCET_JAZYKOV + 1] = { "pre cezročné obdobie", "pro mezidobí", "for ...", "per annum", "", "pro dobu během roku", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_tyzden_zaltara_cislo[POCET_JAZYKOV + 1] = { "%d. týždeň žaltára", "%d. týden žaltáře", "%d. week of Psaltary", "hebdomada %d psalterii", "%d", "%d. týden žaltáře", "%d. zsoltáros hét", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_tyzden_cislo[POCET_JAZYKOV + 1] = { "%d. týždeň", "%d. týden", "%d. week", "hebdomada %d", "%d", "%d. týden", "%d. hét", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_tyzden[POCET_JAZYKOV + 1] = { ". týždeň", ". týden", ". week", "hebdomada ", "", ". týden", ". hét", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_v_tyzdni_zaltara[POCET_JAZYKOV + 1] = { ". týždni žaltára", ". týdnu žaltáře", "week of Psaltary", "hebdomada", "", ". týdnu žaltáře", ". zsoltáros hét", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_pre[POCET_JAZYKOV + 1] = { "pre", "pro", "for", "per", "", "pro", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_ordinarium[POCET_JAZYKOV + 1] = { "ordinárium", "uspořádání", "ordinary", "ordinarium", "", "ordinárium", "általános rész:", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
// in the following: you MUST keep all HTML elements, e.g. <a href...>, <br/> etc.
const char *html_text_dnes_je_atd[POCET_JAZYKOV + 1] =
{
	"Dnes je %d. deň v roku%s, <a href=\"%s%s\">juliánsky dátum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
	"Dnes je %d. den v roku%s, <a href=\"%s%s\">juliánské datum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
	"Today is %d. day in the year%s, <a href=\"%s%s\">Julian date</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
	"Hodie est %d. die anno %s, <a href=\"%s%s\">Iulianus datum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
	"%d/%s<a href=\"%s%s\">JD</a> = %ld%s.\n"HTML_LINE_BREAK"\n",
	"Dnes je %d. den v roku%s, <a href=\"%s%s\">juliánské datum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
	"Ma %s %d. napja van, <a href=\"%s%s\">Julián naptár</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_alebo[POCET_JAZYKOV + 1] = { "alebo", "nebo", "or", "", "", "nebo", "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_zakladne_info[POCET_JAZYKOV + 1] = { "Základné informácie", "Základní informace", "Basic info", "__info__", "", "Základní informace", "Alapvető információk", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_je[POCET_JAZYKOV + 1] = { "je", "je", "is", "est", "", "je", /* HU: van, ale nie pre prestupný */ "", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_nie_je[POCET_JAZYKOV + 1] = { "nie je", "není", "is not", "non est", "", "není", /* HU: nincs, ale nie pre prestupný */ "nem", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_prestupny[POCET_JAZYKOV + 1] = { "prestupný", "přestupný", "...", "...", "", "přestupný", "szökőév", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_datumy_pohyblivych_slaveni[POCET_JAZYKOV + 1] = { "Dátumy pohyblivých slávení", "Dáta proměnlivých slávení", "Dates for movable celebrations", "", "", "Data proměnlivých slavení", "A mozgó (változó) ünnepek dátumai", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_ritus[POCET_JAZYKOV + 1] = { "Rítus", "Obřad", "Ritus", "Ritus", "", "Ritus", "Szertartás", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_den_v_roku[POCET_JAZYKOV + 1] = { "%d. deň v roku", "%d. den v roce", "%d. day of the year", "%d. ", "%d. ", "%d. den v roce", "az év %d. napja", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_zacina[POCET_JAZYKOV + 1] = { "začína", "začíná", "starts", "", "", "začíná", "kezdődik", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_liturgicky_rok[POCET_JAZYKOV + 1] = { "liturgický rok", "liturgický rok", "liturgical year", "anno liturgico", "", "liturgický rok", "liturgikus év", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_txt_export[POCET_JAZYKOV + 1] = { "Textový výstup", "Textový výstup", "Text export", "Text export", "", "Textový výstup", "Szöveg exportálása", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

#define POCET_HTML_TEXT_POHYBLIVE 12
#define HTML_TEXT_POHYBLIVE_ZJAVENIE_PANA 3

const char *html_text_pohyblive[POCET_HTML_TEXT_POHYBLIVE + 1][POCET_JAZYKOV + 1] = {
{
	"Rok"HTML_LINE_BREAK"Pána",
	"Léto"HTML_LINE_BREAK"Páně", 
	"Anno"HTML_LINE_BREAK"Domini",
	"Anno"HTML_LINE_BREAK"Domini",
	"",
	"Léto"HTML_LINE_BREAK"Páně",
	"Naptári"HTML_LINE_BREAK"év",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Nedeľná"HTML_LINE_BREAK"litera",
	"Nedělní"HTML_LINE_BREAK"písmeno", 
	"Sunday"HTML_LINE_BREAK"Letter",
	"Let."HTML_LINE_BREAK"Dom.",
	"",
	"Nedělní"HTML_LINE_BREAK"písmeno",
	"Vasár-"HTML_LINE_BREAK"nap"HTML_LINE_BREAK"betűje",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Nedeľný"HTML_LINE_BREAK"cyklus",
	"Nedělní"HTML_LINE_BREAK"cyklus", 
	"Sunday"HTML_LINE_BREAK"cycle",
	"Cycl."HTML_LINE_BREAK"Dom.",
	"",
	"Nedělní"HTML_LINE_BREAK"cyklus",
	"Vasár-"HTML_LINE_BREAK"napi"HTML_LINE_BREAK"ciklus",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Zjavenie"HTML_LINE_BREAK"Pána",
	"Zjevení"HTML_LINE_BREAK"Páně", 
	"Epiphany",
	"Epiphania"HTML_LINE_BREAK"Domini",
	"",
	"Zjevení"HTML_LINE_BREAK"Páně",
	"Urunk"HTML_LINE_BREAK"megjelenése"HTML_LINE_BREAK"(Vízkereszt)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Krst"HTML_LINE_BREAK"Krista"HTML_LINE_BREAK"Pána",
	"Křest"HTML_LINE_BREAK"Krista"HTML_LINE_BREAK"Páně", 
	"Bapt. of"HTML_LINE_BREAK"the Lord",
	"Bapt."HTML_LINE_BREAK"Domini",
	"",
	"Křest"HTML_LINE_BREAK"Krista"HTML_LINE_BREAK"Páně",
	"Urunk"HTML_LINE_BREAK"megkeresztel-"HTML_LINE_BREAK"kedése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"<a href=\"#explain\">OCR"HTML_LINE_BREAK"pred"HTML_LINE_BREAK"PO</a>",
	"<a href=\"#explain\">OCR"HTML_LINE_BREAK"před"HTML_LINE_BREAK"postem</a>", 
	"...",
	"PA fest.",
	"",
	"<a href=\"#explain\">OCR"HTML_LINE_BREAK"před"HTML_LINE_BREAK"postem</a>",
	"EK"HTML_LINE_BREAK"a HSZ"HTML_LINE_BREAK"előtt",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Popolcová"HTML_LINE_BREAK"streda",
	"Popeleční"HTML_LINE_BREAK"středa", 
	"...",
	"...",
	"",
	"Popeleční"HTML_LINE_BREAK"středa",
	"Hamvazó-"HTML_LINE_BREAK"szerda",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Veľká"HTML_LINE_BREAK"noc",
	"Veliko-"HTML_LINE_BREAK"noce", 
	"Easter",
	"Pascha",
	"",
	"Veliko-"HTML_LINE_BREAK"noce",
	"Húsvét",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Nanebo-"HTML_LINE_BREAK"vstúpenie"HTML_LINE_BREAK"Pána",
	"Nanebe-"HTML_LINE_BREAK"vstoupení"HTML_LINE_BREAK"Páně", 
	"...",
	"...",
	"",
	"Nanebe-"HTML_LINE_BREAK"vstoupení"HTML_LINE_BREAK"Páně",
	"Urunk"HTML_LINE_BREAK"menny-"HTML_LINE_BREAK"bemenetele",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Zoslanie"HTML_LINE_BREAK"Ducha"HTML_LINE_BREAK"Svätého",
	"Seslání"HTML_LINE_BREAK"Ducha"HTML_LINE_BREAK"Svatého", 
	"...",
	"...",
	"",
	"Seslání"HTML_LINE_BREAK"Ducha"HTML_LINE_BREAK"Svatého",
	"Pünkösd",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"<a href=\"#explain\">OCR"HTML_LINE_BREAK"po"HTML_LINE_BREAK"VN</a>",
	"<a href=\"#explain\">OCR"HTML_LINE_BREAK"po"HTML_LINE_BREAK"VN</a>", 
	"...",
	"...",
	"",
	"<a href=\"#explain\">OCR"HTML_LINE_BREAK"po"HTML_LINE_BREAK"VN</a>",
	"EK"HTML_LINE_BREAK"a HU"HTML_LINE_BREAK"után",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Prvá"HTML_LINE_BREAK"adventná"HTML_LINE_BREAK"nedeľa",
	"První"HTML_LINE_BREAK"adventní"HTML_LINE_BREAK"neděle", 
	"...",
	"...",
	"",
	"První"HTML_LINE_BREAK"adventní"HTML_LINE_BREAK"neděle",
	"Advent"HTML_LINE_BREAK"első"HTML_LINE_BREAK"vasárnapja",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
},
{
	"Nedeľa"HTML_LINE_BREAK"Svätej"HTML_LINE_BREAK"rodiny",
	"Neděle"HTML_LINE_BREAK"Svaté"HTML_LINE_BREAK"rodiny", 
	"...",
	"...",
	"",
	"Neděle"HTML_LINE_BREAK"Svaté"HTML_LINE_BREAK"rodiny",
	"Szent"HTML_LINE_BREAK"Család"HTML_LINE_BREAK"ünnepe",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
}
};

const char *html_text_Nedelne_pismeno[POCET_JAZYKOV + 1] = { "Nedeľné písmeno", "Nedělní písmeno", "Sunday letter", "", "", "Nedělní písmeno", "A vasárnap betűje", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_Nedelne_pismena[POCET_JAZYKOV + 1] = { "Nedeľné písmená", "Nedělní písmena", "Sunday letters", "", "", "Nedělní písmena", "A vasárnap betűje", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *html_text_Od_prvej_adv_atd[POCET_JAZYKOV + 1] = {
	"Od prvej adventnej nedele v roku %d (%s) pokračuje <a href=\"%s%s\">liturgický rok</a> <"HTML_SPAN_BOLD">%c"HTML_SPAN_END".",
	"Od první neděle adventní v roku %d (%s) pokračuje <a href=\"%s%s\">liturgický rok</a> <"HTML_SPAN_BOLD">%c"HTML_SPAN_END".",
	"From the 1st Advent Sunday in the year %d (%s) continues <a href=\"%s%s\">liturgical year</a> <"HTML_SPAN_BOLD">%c"HTML_SPAN_END".",
	"Od prvej adventnej nedele v roku %d (%s) pokračuje <a href=\"%s%s\">liturgický rok</a> <"HTML_SPAN_BOLD">%c"HTML_SPAN_END".",
	"",
	"Od první neděle adventní v roce %d (%s) pokračuje <a href=\"%s%s\">liturgický rok</a> <"HTML_SPAN_BOLD">%c"HTML_SPAN_END".",
	"%d (%s) advent első vasárnapjától az <"HTML_SPAN_BOLD">%c"HTML_SPAN_END" <a href=\"%s%s\">liturgikus év</a> folytatódik.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_Po_Velkej_noci_atd[POCET_JAZYKOV + 1] = {
	"Po Veľkej noci nasleduje %d. %s v cezročnom období.",
	"Po Velikonocích následuje %d. %s v mezibdobí.",
	"After Easter follows %d. %s per annum.",
	"Po Veľkej noci nasleduje %d. %s per annum.",
	"Po Veľkej noci nasleduje %d. %s v cezročnom období.", // v období „cez rok“
	"Po Velikonocích následuje %d. %s v mezibdobí.",
	"Húsvét után az évközi idő %d. %sja következik.", // vasárnapja, nedeľa = vasárnap
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_Prikazane_sviatky_v_roku[POCET_JAZYKOV + 1] = {
	"Prikázané sviatky v roku %s",
	"Přikázané svátky v roce %s",
	"Obliged celebrations in the year %s",
	"Prikázané sviatky v roku %s",
	"Prikázané sviatky v roku %s",
	"Přikázané svátky v roce %s",
	"%s kötelező ünnepei",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_Jednotlive_mesiace_roku[POCET_JAZYKOV + 1] = {
	"Jednotlivé mesiace roku %s",
	"Jednotlivé měsíce v roce %s",
	"Individual months of the year %s",
	"Jednotlivé mesiace roku %s",
	"Jednotlivé mesiace roku %s",
	"Jednotlivé měsíce v roce %s",
	"Egyes hónapok %s-ben(-ban)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *str_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
{ "doplnková psalmódia", "žalmy z doplňovacího cyklu", "supplementary psalmody", "psalmodia complementaris", "", "doplnková psalmodie", "kiegészítő zsoltárok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

const char *str_modl_cez_den_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
{ "bežnej psalmódie", "běžné psalmodie", "ordinary psalmody", "___", "", "běžné psalmodie", "soros zsoltárösszeállítást", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#define		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA 	str_modl_cez_den_zalmy_zo_dna[_global_jazyk]

const char *str_modl_cez_den_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
{ "doplnkovej psalmódie", "doplňovacího cyklu", "supplementary psalmody", "psalmodia complementaris", "", "doplňkové psalmodie", "kiegészítő zsoltárok", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#define		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA 	str_modl_cez_den_doplnkova_psalmodia[_global_jazyk]

const char *str_modl_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
{ "dňa", "dne", "day", "die", "", "dne", "naptól", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#define		STR_MODL_ZALMY_ZO_DNA 	str_modl_zalmy_zo_dna[_global_jazyk]

const char *str_modl_zalmy_zo_sv[POCET_JAZYKOV + 1] = 
{ "sviatku", "svátku", "celebration", "___", "", "svátku", "ünneptől", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#define		STR_MODL_ZALMY_ZO_SV 	str_modl_zalmy_zo_sv[_global_jazyk]

#define STR_VALUE_TRUE  "1"
#define STR_VALUE_FALSE "0"
#define STR_VALUE_ZERO  "0"

const char *str_ano[POCET_JAZYKOV + 1] = 
{ "áno", "ano", "yes", "sic", "___", "ano", "igen", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#define		STR_ANO		str_ano[_global_jazyk]

const char *str_nie[POCET_JAZYKOV + 1] = 
{ "nie", "ne", "no", "non", "___", "ne", "nem", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
#define		STR_NIE		str_nie[_global_jazyk]

// const char *html_text_jazyk_android = "SK/CZ/HU:";

const char *html_text_jazyk[POCET_JAZYKOV + 1] =
{
	"Jazyk",
	"Jazyk",
	"Language",
	"Lingua",
	"Language",
	"Jazyk",
	"Nyelv",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_jazyk_long[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín v jazyku:",
	"Liturgie hodin pro jazyk:",
	"Liturgy of hours in language:",
	"LH in lingua:",
	"",
	"Liturgie hodin pro jazyk:",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_jazyk_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín pre iný jazyk.",
	"Liturgie hodin pro jiný jazyk.",
	"Liturgy of hours in other languages.",
	"LH in lingua...",
	"",
	"Liturgie hodin pro jiný jazyk.",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_detaily_uvod[POCET_JAZYKOV + 1] =
{
	"Nasledovné možnosti ovplyvnia vzhľad i obsah vygenerovanej modlitby.\nVyberte tie možnosti, podľa ktorých sa má modlitba vygenerovať.",
	"Následující možnosti mají vliv na vzhled i obsah vygenerované modlitby.\nVyberte si možnosti, podle kterých má být modlitba vygenerována.",
	"The following options apply to the resulting generated text of the prayer.\nChoose options which fit your needs to the resulting prayer text.",
	"",
	"",
	"Následující možnosti mají vliv na vzhled i obsah vygenerované modlitby.\nVyberte si možnosti, podle kterých má být modlitba vygenerována.",
	"Ez a választási lehetőség befolyásolja a megszerkesztett ima megjelenítését és tartalmát.\nVálasszon a szerkeszthető lehetőségek közül.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_kalendar[POCET_JAZYKOV + 1] =
{
	"nastavenia pre liturgický kalendár",
	"volby pro liturgický kalendář",
	"options for liturgical calendar",
	"",
	"",
	"volby pro liturgický kalendář",
	"a liturgikus naptár beállításai",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_kalendar_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín ponúka možnosť slávenia niektorých slávení dvojakým spôsobom; závisí od danej krajiny, ako rozhodla príslušná konferencia biskupov.",
	"Volby pro liturgický kalendář ovlivňují datumy některých slavení.",
	"Options for liturgical calendar...",
	"",
	"",
	"Volby pro liturgický kalendář ovlivňují datumy některých slavení.",
	"Az Imaórák liturgiája megadja a lehetőséget, hogy némely ünnepek kétféleképpen legyenek megünnepelve; az adott országtól függ, ahogy az adott püspöki konferencia döntött.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_nemenne_sucasti[POCET_JAZYKOV + 1] =
{
	"zobraziť nasledovné súčasti modlitby?",
	"zobrazit <i>neměnné součásti</i> modlitby?",
	"display <i>non-changeable parts</i> prayer?",
	"",
	"",
	"zobrazit <i>neměnné součásti</i> modlitby?",
	"jelenjenek meg az imaóra következő elemei:",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_nemenne_sucasti_explain[POCET_JAZYKOV + 1] =
{
	"Každé ranné chvály obsahujú Benediktus, vešpery Magnifikat, obe modlitby obsahujú Otčenáš a zakončenie modlitby, a napokon posvätné čítanie obsahuje niekedy hymnus Te Deum; tieto časti modlitby možno zobraziť alebo skryť.",
	"Každé ranní chvály obsahují Zachariášovo kantikum, nešpory Mariin Magnifikat, obě modlitbu Páně a zakončení modlitby, a konečně modlitba se čtením někdy obsahuje hymnus Te Deum; tyto části modliteb je možné zobrazit/skrýt.",
	"Each morning prayer contains Benedictus, vesperae contains Magnificat, both contain the Lord's Prayer and a conclusion of the prayer; finally, the holy reading sometimes contains the Te Deum hymnus; all these parts can be shown/hidden.",
	"",
	"",
	"Každé ranní chvály obsahují Zachariášovo kantikum, večerní chvály kantikum Panny Marie, obě modlitbu Páně a zakončení modlitby, a konečně modlitba se čtením někdy obsahuje hymnus Te Deum; tyto části je možné zobrazit/skrýt.",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_dalsie_prepinace[POCET_JAZYKOV + 1] =
{
	"možnosti pre výsledné modlitby",
	"možnosti pro výsledné modlitby",
	"options for generated prayers",
	"",
	"",
	"možnosti pro výsledné modlitby",
	"egyéb választási lehetőségek:",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// for other language: use ""
const char *html_text_option1_dalsie_prepinace_explain[POCET_JAZYKOV + 1] =
{
	"Rozličné možnosti/výbery pre výsledné modlitby.",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_zalmy_brat_zo[POCET_JAZYKOV + 1] =
{
	"žalmy použiť zo ",
	"žalmy použít ze ",
	"take psalmody from ",
	"",
	"",
	"žalmy použít ze ",
	"zsoltárok a következő helyről:",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_zalmy_brat_zo_okrem_mcd[POCET_JAZYKOV + 1] =
{
	" (okrem modlitby cez deň)\n",
	" (kromě modlitby přes den)\n",
	" (excluding the prayers during the day)\n",
	"",
	"",
	" (kromě modlitby během dne)\n",
	" (a Napközi imát kivéve)\n",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_spol_casti_vziat_zo[POCET_JAZYKOV + 1] =
{
	"časti modlitby zo spoločnej časti ",
	"části modlitby ze společných textů ",
	"parts of prayer from the common part ",
	"",
	"",
	"části modlitby ze společné části ",
	"a közös részből",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_spol_casti_vziat_zo_explain[POCET_JAZYKOV + 1] =
{
	"Na sviatok svätca/svätice sa podľa liturgických pravidiel berú časti, ktoré sa nenachádzajú vo vlastnej časti žaltára, zo spoločnej časti sviatku, niekedy je možnosť vybrať si z viacerých spoločných častí; naviac je možnosť modliť sa tieto časti zo všedného dňa.",
	"Na svátek ke cti světce/světice se podle liturgických pravidel berou části, které se nenachází ve vlastních textech, ze společných textů, někdy je možné vybrat si z více společných textů; navíc je možnost modlit se tyto části ze všedního dne.",
	"",
	"",
	"",
	"O svátku ke cti světce/světice se podle liturgických pravidel berou části, které se nenachází ve vlastních textech, ze společných textů, někdy je možné vybrat si z více společných textů; navíc je možnost modlit se tyto části ze všedního dne.",
	"A szentek ünnepén, a liturgikus előírások szerint, azok az imarészek, amelyek nem találhatók meg a zsolozsma saját részében, tetszés szerint vehetők vagy a közös részből, néha több közös részből lehet választani, vagy a köznapról.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_specialne[POCET_JAZYKOV + 1] =
{
	"v texte modlitieb zobraziť",
	"v textu modliteb zobrazit",
	"in the text of prayers display",
	"",
	"",
	"v textu modliteb zobrazit",
	"az imaóra szövegében jelenjen meg:",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// for other languages use: ""
const char *html_text_option0_specialne_explain[POCET_JAZYKOV + 1] =
{
	"Možnosť zobraziť ďalšie údaje v texte modlitieb (čísla veršov, referencie a pod.).",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_verse[POCET_JAZYKOV + 1] =
{
	"číslovanie (čísla) veršov",
	"číslování veršů",
	"verse numbering",
	"verse numbers",
	"",
	"číslování veršů",
	"a versek száma",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_verse_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín (latinské typické vydanie) zobrazuje číslovanie veršov v rámci žalmu, chválospevu alebo dlhšieho biblického čítania; niektoré vydania tieto čísla veršov neuvádzajú.",
	"Liturgie hodin uvádí jako horní indexy čísla veršů biblických textů (žalmů, chvalozpěvů a prvních čtení), které může program zobrazit.",
	"Printed editions of Liturgy of the Hours shows also verse numbers (in psalms, canticles and long biblical readings). This option forces to display them.",
	"",
	"",
	"Liturgie hodin uvádí jako horní indexy čísla veršů biblických textů (žalmů, chvalozpěvů a prvních čtení), které může program zobrazit.",
	"Az imaórák liturgiája (latin tipikus kiadás) megjeleníti a zsoltárokban, kantikumokban és hosszabb szentírási olvasmányokban a versek számozását. Egyes kiadások e számozást nem tartalmazzák.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_referencie[POCET_JAZYKOV + 1] =
{
	"biblické odkazy na dkc.kbs.sk",
	"biblické odkazy",
	"biblical references",
	"Bible references",
	"",
	"biblické odkazy",
	"Bibliai hivatkozások a szentiras.hu oldalon",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_referencie_explain[POCET_JAZYKOV + 1] =
{
	"Všetky biblické odkazy (napr. Jn 3, 16) v modlitbe budú aktívnymi odkazmi na text katolíckeho prekladu Biblie na adrese dkc.kbs.sk.",
	"",
	"",
	"",
	"",
	"",
	"Az imák szövegében minden bibliai utalás (például Jn 3, 16) aktív linkként a szentiras.hu katolikus bibliafordításának megfelelő részére mutat. (A Szent István Társulat fordítását használjuk.)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_citania[POCET_JAZYKOV + 1] =
{
	"liturgické čítania",
	"liturgická čtení",
	"liturgical readings",
	"liturgical readings",
	"",
	"liturgická čtení",
	"liturgikus olvasmányok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_citania_explain[POCET_JAZYKOV + 1] =
{
	"Zobrazí odkaz na liturgické čítania (lc.kbs.sk).",
	"Zobrazí odkaz na liturgická čtení (katolik.cz).",
	"",
	"",
	"",
	"Zobrazí odkaz na liturgická čtení (katolik.cz).",
	"Liturgikus olvasmányok (katolikus.hu).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_zjv_ne[POCET_JAZYKOV + 1] =
{
	"Zjavenie Pána sláviť v nedeľu medzi 2. a 8. januárom",
	"Zjevení Páně slavit v neděli mezi 2. a 8. lednem",
	"",
	"",
	"",
	"Zjevení Páně slavit v neděli mezi 2. a 8. lednem",
	"Urunk megjelenése (Vízkereszt) megünneplése vasárnap, január 2. és 8. között",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_zjv_ne_explain[POCET_JAZYKOV + 1] =
{
	"Zjavenie Pána sa slávi dňa 6. januára; v niektorých krajinách sa slávi v nedeľu medzi 2. a 8. januárom.",
	"",
	"",
	"",
	"",
	"",
	"Urunk megjelenése (Vízkereszt) január 6-án van; egyes országokban azonban vasárnap, január 2. és 8. között ünneplik.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_nan_ne[POCET_JAZYKOV + 1] =
{
	"Nanebovstúpenie Pána sláviť v nedeľu",
	"Nanebevstoupení Páně slavit v neděli",
	"",
	"",
	"",
	"Nanebevstoupení Páně slavit v neděli",
	"Urunk mennybemenetelét vasárnap ünnepelni",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_nan_ne_explain[POCET_JAZYKOV + 1] =
{
	"Nanebovstúpenie Pána sa slávi 40. deň po Veľkej noci (teda vo štvrtok); v niektorých krajinách sa slávenie prekladá na najbližšiu nedeľu (nahrádza 7. veľkonočnú nedeľu).",
	"",
	"",
	"",
	"",
	"",
	"Urunk mennybemenetele húsvét után a 40. napon van (tehát csütörtökön); egyes országokban azonban a legközelebbi vasárnapon ünneplik (vagyis Húsvét 7. vasárnapján).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_tk_ne[POCET_JAZYKOV + 1] =
{
	"Najsv. Kristovho tela a krvi sláviť v nedeľu",
	"Těla a krve Páně slavit v neděli",
	"",
	"",
	"",
	"Těla a krve Páně slavit v neděli",
	"Krisztus Szent Teste és Vére ünnepe vasárnapra téve",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_tk_ne_explain[POCET_JAZYKOV + 1] =
{
	"Najsv. Kristovho tela a krvi sa slávi 11. deň po Zoslaní Ducha Svätého (teda vo štvrtok po Najsv. Trojici); v niektorých krajinách sa slávenie prekladá na najbližšiu nedeľu.",
	"",
	"",
	"",
	"",
	"",
	"Krisztus Szent Teste és Vére Pünkösd után a 11. napon van (tehát Szentháromság utáni csütörtökön); egyes országokban azonban a legközelebbi vasárnapon ünneplik.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_font_normal[POCET_JAZYKOV + 1] =
{
	"všade použiť obyčajné písmo (nie tučné)",
	"všude použít obyčejné písmo (ne tučné)",
	"force normal font weight (no bold)",
	"",
	"",
	"všude použít obyčejné písmo (ne tučné)",
	"normál betűtípus használata (félkövér helyett)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// for other languages use: ""
const char *html_text_option0_font_normal_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín používa tučné písmo pre texty, ktoré sa priamo čítajú, a tiež aj pre niektoré medzinadpisy. Táto voľba potlačí použitie tučného písma.",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_buttons_order[POCET_JAZYKOV + 1] = 
{
	"dátumové navigačné tlačidlá zobraziť až pod tlačidlami pre modlitby",
	"navigační tlačítka pro datum zobrazit až pod tlačítky pro modlitby",
	"date buttons display after buttons for prayers",
	"",
	"",
	"navigační tlačítka pro datum zobrazit až pod tlačítky pro modlitby",
	"a fejlécben a dátumválasztó gombok legyenek az imaóra választó gombok után",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// for other languages use: ""
const char *html_text_option0_buttons_order_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín používa tučné písmo pre texty, ktoré sa priamo čítajú, a tiež aj pre niektoré medzinadpisy. Táto voľba potlačí použitie tučného písma.",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option0_blind_friendly[POCET_JAZYKOV + 1] =
{
	"zobraziť iba text modlitieb (pre nevidiacich a slabozrakých) bez rubrík",
	"zobrazit jenom text modliteb (pro slepé a slabozraké) bez rubrik",
	"blind-friendly text (without rubrics)",
	"",
	"",
	"zobrazit jenom text modliteb (pro slepé a slabozraké) bez rubrik",
	"megmutatni csak az imaszövegeket (vakok és gyengénlátók részére) rubrikák nélkül",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// for other languages use: ""
const char *html_text_option0_blind_friendly_explain[POCET_JAZYKOV + 1] =
{
	"Vo výslednej modlitbe bude zobrazený len ten text, ktorý sa číta; nebudú zobrazené žiadne rubriky alebo názvy častí modlitieb. Toto je vhodné pre hlasový výstup napr. pre nevidiacich a slabozrakých.",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_chvalospevy[POCET_JAZYKOV + 1] =
{
	"evanjeliové chválospevy (Benediktus, Magnifikat, Nunk dimittis)",
	"evangelijní kantika (Mariino, Zachariášovo, Simeonovo)",
	"Gospel canticles (Benedictus, Magnificat, Nunc dimittis)",
	"",
	"",
	"evangelijní chvalozpěvy (Benedictus, Magnificat, Nunc dimittis)",
	"evangéliumi kantikumok (Benedictus, Magnificat, Nunc dimittis)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_chvalospevy_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín štandardne tieto evanjeliové chválospevy neuvádza.",
	"Liturgie hodin evangelijní kantika v plném znění obvykle neuvádí.",
	"",
	"",
	"",
	"Liturgie hodin evangelijní chvalozpěvy v plném znění obvykle neuvádí.",
	"Az imaórák liturgiája ezeket az evangéliumi kantikumokat alaphelyzetben nem mutatja.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_slava_otcu[POCET_JAZYKOV + 1] =
{
	"Sláva Otcu", // [na konci žalmov a chválospevov]
	"Sláva Otci", // [na konci žalmů a kantik]
	"Glory to the Father", // at the end of psalms and canticles]
	"",
	"",
	"Sláva Otci", // [na konci žalmů a chvalozpěvů]
	"Dicsőség az Atyának", // [a zsoltárok és kantikumok végén]
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_slava_otcu_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín štandardne Sláva Otcu na konci žalmov a chválospevov neuvádza.",
	"Liturgie hodin modlitbu Sláva Otci na konci žalmů a chvalozpěvů neuvádí.",
	"",
	"",
	"",
	"Liturgie hodin modlitbu Sláva Otci na konci žalmů a chvalozpěvů neuvádí.",
	"Az imaórák liturgiája a Dicsőség az Atyának… dicsőítő verset a zsoltárok és kantikumok végén alaphelyzetben nem mutatja.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_rubriky[POCET_JAZYKOV + 1] =
{
	"rubriky", // (napr. záverečné požehnanie)
	"rubriky", // (např. závěrečné požehnání)
	"rubrics",
	"",
	"",
	"rubriky", // (např. závěrečné požehnání)
	"rubrikák", // (pl. záró áldás)
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_rubriky_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín zobrazuje červeným písmom rozličné zvyčajne vysvetľujúce pokyny k modlitbe (podľa Všeobecných smerníc o LH).",
	"Liturgie hodin uvádí červeným písmem rozličné pokyny k modlitbě (často podle Všeobecných pokynů k denní modlitbě církve).",
	"",
	"",
	"",
	"Liturgie hodin uvádí červeným písmem rozličné pokyny k modlitbě (často podle Všeobecných pokynů k denní modlitbě Církve).",
	"Az imaórák liturgiája piros betűvel különböző többnyire magyarázó vagy az imaórát (az „Általános rendelkezések Az imaórák liturgiájáról“ szerint) szabályozó szövegeket jelenít meg. Alaphelyzetben nem mutatja.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_otcenas[POCET_JAZYKOV + 1] =
{
	"modlitba Pána (Otčenáš)",
	"modlitba Páně (Otčenáš)",
	"Lord's Prayer (Our Father)",
	"",
	"",
	"modlitba Páně (Otčenáš)",
	"az Úr imádsága (Miatyánk)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_otcenas_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín štandardne modlitbu Pána (Otčenáš) v ranných chválach a vešperách v plnom znení neuvádza.",
	"Liturgie hodin modlitbu Páně (Otčenáš) na příslušných místech v plném znění neuvádí.",
	"",
	"",
	"",
	"Liturgie hodin modlitbu Páně (Otčenáš) na příslušných místech v plném znění neuvádí.",
	"Az imaórák liturgiája az Úr imádságát (Miatyánkot) a Reggeli és Esti dicséretben alaphelyzetben nem mutatja.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_tedeum[POCET_JAZYKOV + 1] =
{
	"hymnus Te Deum",
	"hymnus Te Deum",
	"hymnus Te Deum",
	"",
	"",
	"hymnus Te Deum",
	"Téged, Isten, dicsérünk… himnusz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_tedeum_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín hymnus Te Deum v posvätnom čítaní v plnom znení neuvádza.",
	"Liturgie hodin hymnus Te Deum na příslušných místech v plném znění neuvádí.",
	"",
	"",
	"",
	"Liturgie hodin hymnus Te Deum na příslušných místech v plném znění neuvádí.",
	"Az imaórák liturgiája a Téged, Isten, dicsérünk… himnuszt az Olvasmányos imaórában alaphelyzetben nem mutatja.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_plne_resp[POCET_JAZYKOV + 1] =
{
	"plné znenie responzórií pre posvätné čítania",
	"plné znění krátkých zpěvů v modlitbě se čtením",
	"",
	"",
	"",
	"plné znění responsorií v modlitbě se čtením",
	"a válaszos énekek teljes szövege",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_plne_resp_explain[POCET_JAZYKOV + 1] =
{
	"Liturgia hodín responzóriá po čítaniach v posvätnom čítaní v plnom znení neuvádza (druhá, opakujúca sa časť, je v tlačenej LH skrátená).",
	"Liturgie hodin responsoria po čteních v modlitbe se čtením neuvádí v druhé, opakující se části, plné znění.",
	"",
	"",
	"",
	"Liturgie hodin responsoria po čteních v modlitbe se čtením neuvádí v druhé, opakující se části, plné znění.",
	"Az Imaórák Liturgiája az olvasmányos imaórák válaszos énekeinek teljes szövegét nem mutatja (a második ismétlődő rész nyomtatott kiadásban rövidített).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option_zobrazit[POCET_JAZYKOV + 1] =
{
	"zobraziť",
	"zobrazit",
	"show",
	"",
	"",
	"zobrazit",
	"megjelenítés",
	"показ",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option_skryt[POCET_JAZYKOV + 1] =
{
	"skryť",
	"skrýt",
	"hide",
	"",
	"",
	"skrýt",
	"elrejtés",
	"скрывать",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_nie_ine_short[POCET_JAZYKOV + 1] =
{
	"použiť psalmódiu zo dňa",
	"použít žalmy z běžného dne",
	"psalmodia from ordinary day",
	"",
	"",
	"použít psalmodii z běžného dne",
	"az adott napi zsoltározást venni",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_nie_ine[POCET_JAZYKOV + 1] =
{
	"pre modlitbu cez deň použiť psalmódiu zo dňa",
	"pro modlitbu uprostřed dne použít žalmy z běžného dne",
	"psalmodia from ordinary day",
	"",
	"",
	"pro modlitbu uprostřed dne použít psalmodii z běžného dne",
	"a Napközi imaórában az adott napi zsoltározást venni",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_ine_short[POCET_JAZYKOV + 1] =
{
	"použiť doplnkovú psalmódiu",
	"použít žalmy z doplňovacího cyklu",
	"supplementary psalmodia",
	"",
	"",
	"dne použít doplňkovou psalmodii",
	"a kiegészítő zsoltárokat venni",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_ine[POCET_JAZYKOV + 1] =
{
	"pre modlitbu cez deň použiť doplnkovú psalmódiu",
	"pro modlitbu uprostřed dne použít žalmy z doplňovacího cyklu",
	"supplementary psalmodia",
	"",
	"",
	"pro modlitbu uprostřed dne použít doplňkovou psalmodii",
	"vegye a napközi imaórákban a kiegészítő zsoltárokat",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_ine_explain[POCET_JAZYKOV + 1] =
{
	"Pokiaľ sa niekto modlí viac modlitieb cez deň, v prvej vezme bežnú psalmódiu; v ostatných sa použije doplnková psalmódia. Zahŕňa 3 série tzv. graduálnych žalmov (Ž 120 – 129).",
	"Doplňovací cyklus žalmů obsahuje 3 série tzv. graduálních žalmů (Ž 120 – 129), které je možno použít místo žalmů ze žaltáře.",
	"",
	"",
	"",
	"Doplňovací cyklus žalmů obsahuje 3 série tzv. graduálních žalmů (Ž 120 – 129), které je možno použít místo žalmů ze žaltáře.",
	"Aki több Napközi imaórát mond, az egyik imaórában a soros zsoltárösszeállítást veszi, a többin a kiegészítőt. Ez az úgynevezett „zarándokzsoltárokból“ vett három-három zsoltárból áll (Zsolt 119 – 127).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_nie_tri_short[POCET_JAZYKOV + 1] =
{
	"použiť psalmódiu z daného týždňa žaltára pre všetky tri modlitby cez deň",
	"použít žalmy daného týdne ze žaltáře pro všechny tři modlitby uprostřed dne",
	"",
	"",
	"",
	"použít psalmodii daného týdne ze žaltáře pro všechny tři modlitby uprostřed dne",
	"az adott hét zsoltározását alkalmazni mindhárom napközi imánál",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_nie_tri[POCET_JAZYKOV + 1] =
{
	"pre modlitbu cez deň použiť psalmódiu z daného týždňa žaltára pre všetky tri modlitby cez deň",
	"pro modlitbu uprostřed dne použít žalmy daného týdne ze žaltáře pro všechny tři modlitby během dne",
	"",
	"",
	"",
	"pro modlitbu uprostřed dne použít psalmodii daného týdne ze žaltáře pro všechny tři modlitby během dne",
	"a Napközi imaórában az adott hét zsoltározását alkalmazni mindhárom napközi imánál",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_tri_short[POCET_JAZYKOV + 1] =
{
	"použiť psalmódiu z troch týždňov žaltára: aktuálny, predchádzajúci, nasledujúci",
	"použít žalmy z tří týdnů ze žaltáře: aktuální, předchozí, následující",
	"",
	"",
	"",
	"použít psalmodii z tří týdnů ze žaltáře: aktuální, předchozí, následující",
	"a három heti [aktuális, előző, következő] zsoltározást alkalmazni",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_tri[POCET_JAZYKOV + 1] =
{
	"pre modlitbu cez deň použiť psalmódiu z troch týždňov žaltára (aktuálny, predchádzajúci, nasledujúci)",
	"pro modlitbu uprostřed dne použít žalmy z tří týdnů ze žaltáře (aktuální, předchozí, následující)",
	"",
	"for prayer during the day use psalmody from three weeks of psalter (current, previous, next)",
	"",
	"pro modlitbu uprostřed dne použít psalmodii z tří týdnů ze žaltáře (aktuální, předchozí, následující)",
	"a napközi imaórákban vegye az aktuális, az előző és a következő heti zsoltározást",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_mcd_zalmy_tri_explain[POCET_JAZYKOV + 1] =
{
	"Pokiaľ sa niekto modlí viac modlitieb cez deň, psalmódia sa používa z troch týždňov žaltára (aktuálny, predchádzajúci, nasledujúci týždeň žaltára).\nNemá účinok, ak je zvolená možnosť použiť doplnkovú psalmódiu.",
	"Pokud se někdo modlí více částí modlitby uprostřed dne, může nejprve použít psalmodii daného dne a potom psalmodii předchozího, nebo následujícího týdne.",
	"",
	"",
	"",
	"Pokud se někdo modlí více částí modlitby uprostřed dne, může nejprve použít psalmodii daného dne a potom psalmodii předchozího, nebo následujícího týdne.",
	"Ha valaki többször naponta mondja a napközi imát, a zsoltározás három hétből (aktuális, előző, következő) van alkalmazva.\nNincs hatása, ha ki van választva a kiegészítő zsoltárok alkalmazása.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_zalm95[POCET_JAZYKOV + 1] =
{
	"namiesto žalmov 24, 67 resp. 100 použiť žalm 95",
	"místo žalmů 24, 67 resp. 100 použít žalm 95",
	"psalm 95",
	"",
	"",
	"místo žalmů 24, 67 resp. 100 použít žalm 95",
	"a 23., 66. illetve a 99.  zsoltár helyett legyen a 94.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_zalm95_explain[POCET_JAZYKOV + 1] =
{
	"Ak sa v ranných chválach, vešperách alebo posvätnom čítaní vyskytne žalm 24, 67 resp. 100, ktorý bol použitý pre invitatórium, nahradí sa v príslušnej modlitbe žalmom 95.",
	"Když se v ranních chválách, modlitbě se čtením nebo nešporách vyskytne žalm 24, 67 resp. 100, který se použil pro uvedení do první modlitby dne, nahradí se v příslušné modlitbě žalmem 95.",
	"If morning prayer, vespers of prayer with readings contains psalms 24, 67, or 100, which was used for invitatory, it is replaced by psalm 95.",
	"",
	"",
	"Když se v ranních chválách, modlitbě se čtením nebo večerních chválách vyskytne žalm 24, 67 resp. 100, který se použil pro invitatorium, nahradí se v příslušné modlitbě žalmem 95.",
	"Ha a reggeli és az esti dicséretben, vagy az olvasmányos imaórában előfordul a 23., 66. illetve 99. zsoltár, amely az Imádságra hívásban már imádkozva volt, akkor az adott imádságban a 94. zsoltár kerül helyébe.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option_zobrazit_zvolania[POCET_JAZYKOV + 1] =
{
	"opakovať zvolanie po každej prosbe",
	"zopakovat zvolání po každé prosbě",
	"repeat invocation after each appeal",
	"",
	"",
	"zopakovat zvolání po každé prosbě",
	"megismételni a választ minden könyörgés után",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option_skryt_zvolania[POCET_JAZYKOV + 1] =
{
	"skryť zvolanie po každej prosbe",
	"skrýt zvolání po každé prosbě",
	"hide invocation after each appeal",
	"",
	"",
	"skrýt zvolání po každé prosbě",
	"elrejteni a választ minden könyörgés után",
};

const char *html_text_option_zobrazit_kratsie_prosby[POCET_JAZYKOV + 1] =
{
	"použiť kratšie prosby z dodatku",
	"zobrazit kratší prosby z dodatku",
	"use shorten prayers",
	"",
	"",
	"zobrazit kratší prosby z dodatku",
	"használja a rövidebb könyörgéseket a függelékből",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option_skryt_kratsie_prosby[POCET_JAZYKOV + 1] =
{
	"nepoužiť kratšie prosby z dodatku",
	"nezobrazit kratší prosby z dodatku",
	"do not use shorten prayers",
	"",
	"",
	"nezobrazit kratší prosby z dodatku",
	"ne használja a rövidebb könyörgéseket a függelékből",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_prosby_zvolanie[POCET_JAZYKOV + 1] =
{
	"zvolanie v prosbách opakovať po každej prosbe",
	"zvolání v prosbách zopakovat po každé prosbě",
	"invocation repeat after each appeal",
	"",
	"",
	"zvolání v prosbách zopakovat po každé prosbě",
	"minden fohász után ismételje a választ",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_prosby_zvolanie_explain[POCET_JAZYKOV + 1] =
{
	"V ranných chválach a vešperách opakovať zvolanie v prosbách po každej prosbe.",
	"V ranních chválách a nešporách opakovat svolání v prosbách po každé prosbě.",
	"In morning and evening prayer repeat invocation after each appeal.",
	"",
	"",
	"V ranních a večerních chválách opakovat svolání v prosbách po každé prosbě.",
	"A reggeli és az esti dicséretben minden fohász után ismételni a választ.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_skryt_popis_svaty[POCET_JAZYKOV + 1] =
{
	"nezobraziť popis k modlitbe svätého",
	"nezobrazit popis při modlitbě ke cti světce",
	"do not display description for prayer for the saints",
	"",
	"",
	"nezobrazit popis při modlitbě ke cti světce",
	"ne mutassa a leírást a szentről az imaórában",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_skryt_popis_svaty_explain[POCET_JAZYKOV + 1] =
{
	"Modlitby zväčša obsahujú pred názvom modlitby životopis svätého, popis sviatku alebo podobnú stručnú charakteristiku, ktorú pre jednoduchosť nazývame popis.",
	"Modlitby ke cti svatých obsahují stručný životopis svatého, při svátku je to stručný popis svátku a podobně. Tyto charakteristiky pro stručnost nazýváme popis.",
	"For saints, rubrics usually contains few sentences about that saint (or celebration). This option forces to display this description.",
	"",
	"",
	"Modlitby ke cti svatých obsahují stručný životopis svatého, u svátku je to stručný popis svátku a podobně. Tyto charakteristiky pro stručnost nazýváme popis.",
	"Többnyire az imák az imaóra elnevezése előtt a szent életrajzát, az ünnep leírását vagy más rövid jegyzetet tartalmaznak, amit az egyszerűség kedvéért leírásnak nevezünk.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_spolc_svaty[POCET_JAZYKOV + 1] =
{
	"zobraziť, odkiaľ sa berú spoločné časti k modlitbe svätého",
	"zobrazit, odkud se berou společné texty",
	"display communia info",
	"",
	"",
	"zobrazit, odkud se berou společné texty",
	"mutassa meg, hogy a közös részek honnan lettek véve a szentek zsolozsmájához",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_spolc_svaty_explain[POCET_JAZYKOV + 1] =
{
	"Rubrika obsahujúca informáciu, odkiaľ sa berú spoločné časti k modlitbe svätého.",
	"Rubrika, která pro modlitby svatých informuje, které společné texty jsou užity.",
	"Displays communia info.",
	"",
	"",
	"Rubrika, která pro modlitby svatých informuje, které společné texty jsou užity.",
	"Rubrika, amely azt az információt tartalmazza, hogy melyik közös részből vannak véve a szentek zsolozsmájához tartozó közös részek.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_vesp_kratsie_prosby[POCET_JAZYKOV + 1] =
{
	"pre vešpery použiť kratšie prosby z dodatku",
	"pro nešpory použít kratší prosby z dodatku",
	"use shorten prayers for vespers",
	"",
	"",
	"pro večerní chvály použít kratší prosby z dodatku",
	"Esti dicséretben használja a függelékből a rövidebb, közbenjáró fohászokat",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_vesp_kratsie_prosby_explain[POCET_JAZYKOV + 1] =
{
	"Pre vešpery použiť kratšie prosby z dodatku namiesto tých, ktoré sú určené pre vešpery daného dňa.",
	"Pro nešpory použít kratší prosby z dodatku místo určených pro příslušný den.",
	"Use shorten prayers for vespers instead of those prescribed for the day.",
	"",
	"",
	"Pro večerní chvály použít kratší prosby z dodatku místo určených pro příslušný den.",
	"Esti dicséretben használja a rövidebb közbenjáró fohászokat a függelékből, a napra meghatározott helyett.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_vigilia[POCET_JAZYKOV + 1] =
{
	"predĺžené slávenie vigílie pre posvätné čítanie", //(na nedele, slávnosti a sviatky)
	"prodloužené slavení vigilie pro modlitbu se čtením", // (pro neděle, slavnosti a svátky)
	"celebrating of vigily for prayer with readings", // (for Sundays, solemnitas and festivus)
	"",
	"",
	"prodloužené slavení vigilie pro modlitbu se čtením", // (pro neděle, slavnosti a svátky)
	"hosszabb vigíliás ünneplés Olvasmányos imaórával", // (vasárnap, főünnep és ünnep előtt)
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_vigilia_explain[POCET_JAZYKOV + 1] =
{
	"Tí, čo chcú podľa tradície predĺžiť vigíliu nedele, slávnosti alebo sviatku, čo sa veľmi odporúča, najprv recitujú posvätné čítanie; po oboch čítaniach, pred hymnom Te Deum, pridávajú sa chválospevy a evanjelium.",
	"Ti, kteří chtějí podle tradice prodloužit vigilii neděle, slavnosti nebo svátku, což se velmi doporučuje, recitují nejprve čtení; po obou čteních, před hymnem Te Deum, se přidávají chvalozpěvy a evangelium.",
	"For Sundays, solemnitas and festivus: celebrating of vigily for prayer with readings.",
	"",
	"",
	"Ti, kteří chtějí podle tradice prodloužit vigilii neděle, slavnosti nebo svátku, což se velmi doporučuje, recitují nejprve čtení; po obou čteních, před hymnem Te Deum, se přidávají chvalozpěvy a evangelium.",
	"Akik a hagyományokhoz híven vasárnap, főünnep és ünnep előtt hosszabb vigíliás ünneplést akarnak tartani, először végezzék el az Olvasmányos imaórát, a két olvasmány után és a Téged, Isten, dicsérünk himnusz előtt vegyék hozzá a kantikumokat és utána az evangéliumot.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_spomienka_spolcast[POCET_JAZYKOV + 1] =
{
	"na spomienky použiť časti zo spoločných častí",
	"na památky použít části ze společných textů",
	"take parts from celebration &#x2013; commmons",
	"",
	"",
	"na památky použít části ze společných částí",
	"emléknapon vegye a jelzett részeket a közös részből",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_spomienka_spolcast_explain[POCET_JAZYKOV + 1] =
{
	"Zvoliť, či sa antifóna na invitatórium, hymnus, krátke čítanie, antifóny na Benediktus a Magnifikat a prosby, ak nie sú vlastné, berú zo spoločnej časti (ináč z bežného všedného dňa); č. 235 b) všeobecných smerníc.",
	"",
	"",
	"",
	"",
	"",
	"Kiválasztani, hogy az imádságra hívás antifónája, himnusz, rövid olvasmány, a Benedictus és a Magnifikat antifónája és a fohászok a közös részből legyenek véve (egyébként a köznapról) a 235 b) általános rendelkezés szerint.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option1_spomienka_spolcast_NIE[POCET_JAZYKOV + 1] =
{
	"na spomienky použiť časti zo dňa, nie zo spoločných častí",
	"na památky použít části z běžného dne, ne ze společných textů",
	"take parts from feria &#x2013; not commmons",
	"",
	"",
	"na památky použít části z běžného dne, ne ze společných částí",
	"emléknapon a jelzett részeket az adott napról vegye, ne a közös részből",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_html_export[POCET_JAZYKOV + 1] =
{
	"možnosti zobrazenia stránok",
	"možnosti zobrazení stránek",
	"display options",
	"",
	"",
	"možnosti zobrazení stránek",
	"az oldalak megjelenítésének lehetőségei:",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_html_export_explain[POCET_JAZYKOV + 1] =
{
	"Tieto možnosti ovplyvnia rozličné zobrazenia, nemajú vplyv na obsah (text) modlitieb.",
	"Možnosti ovlivní rozličná zobrazení, neovlivní obsah (text) modliteb.",
	"These various options have no influence to generated text of prayers, used only for visualization.",
	"",
	"",
	"Možnosti ovlivní rozličná zobrazení, neovlivní obsah (text) modliteb.",
	"Ezek a beállítások hatással vannak a formai megjelenítésre, de az imaszöveg nem változik.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_prve_vespery[POCET_JAZYKOV + 1] =
{
	"zobraziť tlačidlo pre prvé vešpery pre nedele a slávnosti v deň slávenia",
	"zobrazit tlačítko pro první nešpory pro neděle a slavnosti v den slavení",
	"display button for first vesperas for Sundays and solemnitas for the day of celebration",
	"",
	"",
	"zobrazit tlačítko pro první večerní chvály pro neděle a slavnosti v den slavení",
	"vasárnapok és főünnepek esetén az I. Esti dicséret gombja az ünneplés napján jelenjen meg",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_prve_vespery_explain[POCET_JAZYKOV + 1] =
{
	"Keďže základným kritériom pre zobrazovanie modlitieb daného dňa je dátum, formálne prvé vešpery nedieľ a slávností (a tiež kompletórium po nich) nespadajú pod daný dátum, ale pre predošlý deň, kde sa zobrazujú ako bežné vešpery. Pre sobotné slávenie sa nebude tlačidlo pre vešpery (a kompletórium) zobrazovať.",
	"Jelikož základním kritériem pro zobrazování ponuky modliteb daného dne je datum, první nešpory neděl a slavností (a také kompletář po nich) nespadají pod daný datum, nýbrž pro předcházející den, kde jsou zobrazeny jako běžné nešpory. Pro sobotní slavení se tlačítko pro nešpory (a kompletář) nebude zobrazovat.",
	"For Sundays and solemnities, display also button for first vespers. (For Saturdays, vespers button will not be displayed.)",
	"",
	"",
	"Jelikož základním kritériem pro zobrazování ponuky modliteb daného dne je datum, první večerní chvály neděl a slavností (a také kompletář po nich) nespadají pod daný datum, nýbrž pro předcházející den, kde jsou zobrazeny jako běžné první večerní chvály. Pro sobotní slavení se tlačítko pro večerní chvály (a kompletář) nebude zobrazovat.",
	"Mivel az imaórák megjelenítése elsősorban a dátumtól függ, a vasárnapok és főünnepek I. Esti dicsérete (valamint az utánuk következő Befejező imaóra) formálisan nem tartozik az adott dátumhoz, hanem az előző naphoz. Itt mint köznapi Esti dicséret jelenik meg. Az I. Esti dicséret (és Befejező imaóra) gombja nem fog megjelenni szombati végzéshez.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_iso_datum[POCET_JAZYKOV + 1] =
{
	"zobraziť dátum v ISO 8601 formáte (RRRR-MM-DD)",
	"zobrazit datum v ISO 8601 formátu (RRRR-MM-DD)",
	"display date in ISO 8601 format (RRRR-MM-DD)",
	"",
	"",
	"zobrazit datum v ISO 8601 formátu (RRRR-MM-DD)",
	"a dátum ISO 8601 formátumban (ÉÉÉÉ-HH-NN) jelenjen meg",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// for any language: use ""
const char *html_text_option2_iso_datum_explain[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_font_family[POCET_JAZYKOV + 1] =
{
	"použiť bezpätkové písmo? (ináč pätkové)",
	"použít bezpatkové písmo? (jinak patkové)",
	"use Sans Serif font? (otherwise, Serif is used)",
	"",
	"",
	"použít bezpatkové písmo? (jinak patkové)",
	"talp nélküli betűk használata",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_font_family_explain[POCET_JAZYKOV + 1] =
{
	"Zvoľte si pätkové písmo (Serif) resp. bezpätkové písmo (Sans Serif) podľa toho, čo vám viac vyhovuje pre komfort modlitby. Použije sa predvolené písmo prehliadača.",
	"",
	"",
	"",
	"",
	"",
	"Válasszon talpas (Serif) vagy talp nélküli (Sans Serif) betűt, kényelem szerint. A böngészőablakban mutatott betűtípus az alapértelmezett.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// genitive form or word 'navigation'
const char *html_text_navig_buttons[POCET_JAZYKOV + 1] =
{
	"navigáciu",
	"navigaci",
	"navigation buttons",
	"",
	"",
	"navigaci",
	"navigáció",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_navigation[POCET_JAZYKOV + 1] =
{
	"zobraziť navigáciu v textoch modlitieb",
	"zobrazit navigaci v textech modliteb",
	"display navigation buttons in prayer",
	"",
	"",
	"zobrazit navigaci v textech modliteb",
	"a navigáció mutatása az imaszövegben",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_navigation_explain[POCET_JAZYKOV + 1] =
{
	"Či sa majú zobrazovať hypertextové odkazy na ostatné modlitby daného dňa, príp. predošlý/nasledovný deň priamo v texte modlitby.",
	"Zda zobrazit hypertextové odkazy na ostatní modlitby daného dne, resp. předešlý/následující den přímo v textu modlitby.",
	"Whether hypertext links (as buttons) to other prayers of the selected celebration should be displayed.",
	"",
	"",
	"Zda zobrazit hypertextové odkazy na ostatní modlitby daného dne, resp. předešlý/následující den přímo v textu modlitby.",
	"Legyen-e hiperhivatkozás a nap többi imaórájára is,  illetve mutassa-e az előző és következő nap imaóráit is közvetlenül a szövegben.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_moznosti[POCET_JAZYKOV + 1] =
{
	"zobraziť rozličné možnosti priamo v textoch modlitieb",
	"zobrazit rozličné volby v textech modliteb",
	"display various options in prayers",
	"",
	"",
	"zobrazit rozličné volby v textech modliteb",
	"mutassa meg az imák szövegében a különböző lehetőségeket",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_moznosti_explain[POCET_JAZYKOV + 1] =
{
	"Či sa majú zobrazovať hypertextové odkazy na iné zobrazenie tej istej modlitby priamo v texte modlitby (napr. pre modlitbu cez deň na verziu s doplnkovou psalmódiou).", // Vtedy nie je potrebné, aby boli zobrazené prepínače na titulnej stránke.
	"Zda zobrazit hypertextové odkazy na jiné zobrazení modlitby daného dne přímo v textu modlitby (např. pro modlitbu uprostrěd dne verzi se žalmy z doplňujícího cyklu).",
	"Whether various options should be displayed directly in the prayer's texts.",
	"",
	"",
	"Zda zobrazit hypertextové odkazy na jiné zobrazení modlitby daného dne přímo v textu modlitby (např. pro modlitbu uprostrěd dne verzi se žalmy z doplňujícího cyklu).",
	"Megjelenjenek-e közvetlenül különböző lehetőségek az ima szövegében (pl. napközi imaóránál a kiegészítő zsoltár).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_textwrap[POCET_JAZYKOV + 1] =
{
	"zalamovať dlhé riadky ako v tlačenom vydaní (poetické časti)",
	"zalomit dlouhé řádky poetických textů jako v tištěném vydání",
	"wrap long lines according to printed edition",
	"",
	"",
	"zalomit dlouhé řádky poetických textů jako v tištěném vydání",
	"hosszú sorok tördelése, mint a nyomtatott kiadásban (versrészek)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_textwrap_explain[POCET_JAZYKOV + 1] =
{
	"Či sa majú v texte modlitby dlhé riadky žalmov, chválospevov a iných poetických častí zalamovať ako v tlačenom vydaní.",
	"Zda zalomit dlouhé řádky poetických textů jako v tištěném vydání (normálně: nezalamovat).",
	"Whether long lines should be wrapped as in printed edition.",
	"",
	"",
	"Zda zalomit dlouhé řádky poetických textů jako v tištěném vydání (normálně: nezalamovat).",
	"Legyenek-e tördelve az imaórák szövegében a zsoltárok, kantikumok és más versrészek hosszú sorai, mint a nyomtatott kiadásban.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_buttons_usporne[POCET_JAZYKOV + 1] =
{
	"tlačidlá pre modlitby zobraziť úsporne",
	"tlačítka pro modlitby zobrazit úsporně",
	"tight display of buttons for prayers",
	"",
	"",
	"tlačítka pro modlitby zobrazit úsporně",
	"az imaórák gombjainak gazdaságos elhelyezése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_buttons_usporne_explain[POCET_JAZYKOV + 1] =
{
	"Či sa majú tlačidlá pre modlitby zobraziť úsporne, v tabuľke (menšia šírka) kvôli mobilným zariadeniam.",
	"Zda se mají tlačítka pro modlitby zobrazit úsporně, v tabulce (menší šířka) pro mobilní zařízení.",
	"Whether buttons for prayers should be displayed economically for mobile devices.",
	"",
	"",
	"Zda se mají tlačítka pro modlitby zobrazit úsporně, v tabulce (menší šířka) pro mobilní zařízení.",
	"Legyenek-e az imaórák gombjai gazdaságosan elhelyezve, táblázatban (kisebb szélesség) mobilkészülékekhez.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_nocny_rezim[POCET_JAZYKOV + 1] =
{
	"nočný režim",
	"noční režim",
	"night mode",
	"",
	"",
	"noční režim",
	"éjszakai mód",
	"ночной режим",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_nocny_rezim_explain[POCET_JAZYKOV + 1] =
{
	"Zobrazí svetlý text na tmavom pozadí."
	"Zobrazí světlý text na tmavém pozadí.",
	"Displays dark background with light text for night usage.",
	"",
	"",
	"Zobrazí světlý text na tmavém pozadí.",
	"Világos szöveg megjelenítése sötét háttéren.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_alternatives[POCET_JAZYKOV + 1] =
{
	"alternatívy",
	"alternativy",
	"alternatives",
	"",
	"",
	"alternativy",
	"lehetőségek",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_alternatives_explain[POCET_JAZYKOV + 1] =
{
	"Zobrazí v texte modlitieb iba jednu možnosť, napr. hymnus pre kompletórium (dá sa prepínať).",
	"Zobrazí v textu modliteb jenom jednu možnost (je možné přepínat).",
	"In the prayer text, displays only one option (e. g. hymn for compline; user can switch options).",
	"",
	"",
	"Zobrazí v textu modliteb jenom jednu možnost (je možné přepínat).",
	"Megmutatja…",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_show_defalut_calendar[POCET_JAZYKOV + 1] =
{
	"zvýrazniť slávenia v národnom kalendári",
	"zvýraznit slavení v národním kalendáři",
	"show celebrations in national calendar",
	"",
	"",
	"zvýraznit slavení v národním kalendáři",
	"kijelölni az ünnepeket a nemzeti naptárban",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option2_show_defalut_calendar_explain[POCET_JAZYKOV + 1] =
{
	"V podnadpise modlitby zobrazí informáciu, že slávenie je v národnom kalendári (teda nie vo všeobecnom kalendári).",
	"V podnadpisu modlitby zobrazí informaci, že slávení je v národním kalendáři (tedy ne v obecním kalendáři).",
	"",
	"",
	"",
	"V podnadpisu modlitby zobrazí informaci, že slávení je v národním kalendáři (tedy ne v obecním kalendáři).",
	"Az ima felirata alatt megmutatja az információt, hogy az ünnep a nemzeti naptárban van (tehát nem az általánosban).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_KomplHymnusA[POCET_JAZYKOV + 1] =
{
	"hymnus A: Na sklonku dňa ťa úprimne",
	"hymnus A: Na sklonku dne tě upřímně",
	"hymn A",
	"",
	"",
	"hymnus A: Na sklonku dne tě upřímně",
	"himnusz A: Immár a nap leáldozott",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_KomplHymnusB[POCET_JAZYKOV + 1] =
{
	"hymnus B: Kriste, ty svetlo a náš deň",
	"hymnus B: Ty, Kriste, světlo, jasný dni",
	"hymn B",
	"",
	"",
	"hymnus B: Ty, Kriste, světlo, jasný dni",
	"himnusz B: Krisztus, tündöklő nappalunk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_PCHymnusI[POCET_JAZYKOV + 1] =
{
	"hymnus I. [Ak je posvätné čítanie v noci alebo včasráno]",
	"hymnus I. [V noci a časně ráno]",
	"hymn I. [during the night and early in the morning]",
	"",
	"",
	"hymnus I. [V noci a časně ráno]",
	"himnusz I. [Amikor az imaórát éjszaka vagy kora hajnalban mondják]",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_PCHymnusII[POCET_JAZYKOV + 1] =
{
	"hymnus II. [Ak je posvätné čítanie cez deň]",
	"hymnus II. [Během dne]",
	"hymn II. [during the day]",
	"",
	"",
	"hymnus II. [Během dne]",
	"himnusz II. [Amikor az imaórát a nap nem reggeli órájában végzik]",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_PCHymnusVNnedela[POCET_JAZYKOV + 1] =
{
	"hymnus Toto je pravý Boží deň",
	"hymnus nedělní",
	"Sunday's hymn",
	"",
	"",
	"hymnus nedělní",
	"himnusz Urunknak áldott napja ez",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_PCHymnusVNferia[POCET_JAZYKOV + 1] =
{
	"hymnus Nech z výšin neba radosť znie",
	"hymnus z férie",
	"hymnus férie",
	"",
	"",
	"hymnus z férie",
	"himnusz Örvendj, ég, messzi csillagok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_RChHymnusVNnedela[POCET_JAZYKOV + 1] =
{
	"hymnus Bronie sa zora na nebi",
	"hymnus nedělní",
	"hymnus NE",
	"",
	"",
	"hymnus nedělní",
	"himnusz Rózsálló hajnalfény ragyog",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_RChHymnusVNferia[POCET_JAZYKOV + 1] =
{
	"hymnus Nech novým Jeruzalemom",
	"hymnus z férie",
	"hymnus férie",
	"",
	"",
	"hymnus z férie",
	"himnusz Az új Sionnak kórusa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_VespHymnusVNnedela[POCET_JAZYKOV + 1] =
{
	"hymnus Pri Baránkovej večeri",
	"hymnus nedělní",
	"hymnus NE",
	"",
	"",
	"hymnus nedělní",
	"himnusz Ím, vár a Bárány asztala",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_VespHymnusVNferia[POCET_JAZYKOV + 1] =
{
	"hymnus Kráľ vekov, Pane, Boží Syn",
	"hymnus z férie",
	"hymnus férie",
	"",
	"",
	"hymnus z férie",
	"himnusz Örök Királyunk, szent Urunk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_MCDPredHymnus1[POCET_JAZYKOV + 1] = 
{
	"hymnus Príď, Duchu Svätý",
 "hymnus K nám, Duchu Svatý, nyní spěj",
 "hymn 1",
 "",
 "",
 "hymnus K nám, Duchu Svatý, nyní spěj",
 "himnusz Most jöjj, Szentlélek, szállj közénk",
};

const char *html_text_option5_MCDPredHymnus2[POCET_JAZYKOV + 1] =
{
	"hymnus Deviata je už hodina",
	"hymnus Je třetí denní hodina",
	"hymn 2",
	"",
	"",
	"hymnus Je třetí denní hodina",
	"himnusz Idők rendjét megtartva most",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_MCDNaHymnus1[POCET_JAZYKOV + 1] = 
{
	"hymnus Mocný Vládca, verný Bože",
 "hymnus Jsi mocný Vládce, věrný Bůh",
 "hymn 1",
 "",
 "",
 "hymnus Jsi mocný Vládce, věrný Bůh",
 "himnusz Urunk, felséges Istenünk",
};

const char *html_text_option5_MCDNaHymnus2[POCET_JAZYKOV + 1] =
{
	"hymnus Na nebi slnko vrcholí",
	"hymnus Teď Pánu chvály zpívejme",
	"hymn 2",
	"",
	"",
	"hymnus Teď Pánu chvály zpívejme",
	"himnusz Dicsérjük dallal az Urat",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_MCDPoHymnus1[POCET_JAZYKOV + 1] = 
{
	"hymnus Celý svet v pohyb uvádzaš",
 "hymnus Svět celý v pohyb uvádíš",
 "hymn 1",
 "",
 "",
 "hymnus Svět celý v pohyb uvádíš",
 "himnusz Világfenntartó Istenünk",
};

const char *html_text_option5_MCDPoHymnus2[POCET_JAZYKOV + 1] =
{
	"hymnus Z Božej milosti tretí raz",
	"hymnus Hodina třetí z poledne",
	"hymn 2",
	"",
	"",
	"hymnus Hodina třetí z poledne",
	"himnusz Háromszor három óra már",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_1VHymnusNe[POCET_JAZYKOV + 1] =
{
	"hymnus pre prvé vešpery",
	"hymnus pro první nešpory",
	"hymn for first vespers",
	"",
	"",
	"hymnus pro první večerní chvály",
	"I. Esti dicséret himnusza",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_1VHymnusPC[POCET_JAZYKOV + 1] =
{
	"hymnus ako je pre posvätné čítanie [cez deň]",
	"hymnus pro čtení [během dne]",
	"hymn from readings [during the day]",
	"",
	"",
	"hymnus pro čtení [během dne]",
	"Olvasmányos imaóra himnusza [napközben]",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_PopolStrPsalm_4STR[POCET_JAZYKOV + 1] =
{
	"psalmódia pre Popolcovú stredu zo stredy 4. týždňa žaltára",
	"žalmy pro Popeleční středu ze středy 4. týdne žaltáře",
	"for Ash Wednesday take psalmody from Wednesday, 4th week of Psalter",
	"",
	"",
	"žalmy pro Popeleční středu ze středy 4. týdne žaltáře",
	"Hamvazószerdán vegye a zsoltározást a 4. zsoltáros hét szerdájáról",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_PopolStrPsalm_3PI[POCET_JAZYKOV + 1] =
{
	"psalmódia pre Popolcovú stredu z piatka 3. týždňa žaltára",
	"žalmy pro Popeleční středu z pátku 3. týdne žaltáře",
	"for Ash Wednesday take psalmody from Friday, 3rd week of Psalter",
	"",
	"",
	"žalmy pro Popeleční středu z pátku 3. týdne žaltáře",
	"Hamvazószerdán vegye a zsoltározást a 3. zsoltáros hét péntekjéről",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_CZhymny[POCET_JAZYKOV + 1] =
{
	"",
	"hymny",
	"",
	"",
	"",
	"",
	"",
	"",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_CZhymny_explain[POCET_JAZYKOV + 1] =
{
	"",
	"Zobrazí v textu modliteb hymny z breviáře nebo k volnému výběru (je možné přepínat).",
	"",
	"",
	"",
	"",
	"",
	"",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_CZhymnyNORMAL[POCET_JAZYKOV + 1] =
{
	"",
	"hymny z breviáře",
	"",
	"",
	"",
	"",
	"",
	"",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_CZhymnyRENC[POCET_JAZYKOV + 1] =
{
	"",
	"hymny k volnému výběru (Renč)",
	"",
	"",
	"",
	"",
	"",
	"",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_DPsalmZ122_129[POCET_JAZYKOV + 1] =
{
	"namiesto žalmu 122 brať žalm 129",
 "místo žalmu 122 vzít žalm 129",
 "instead of psalm 122 use 129",
 "",
 "",
 "místo žalmu 122 vzít žalm 129",
 "a 121. helyett vehető a 128. zsoltár",
};

const char *html_text_option5_DPsalmZ126_129[POCET_JAZYKOV + 1] =
{
	"namiesto žalmu 126 brať žalm 129",
	"místo žalmu 126 vzít žalm 129",
	"instead of psalm 126 use 129",
	"",
	"",
	"místo žalmu 126 vzít žalm 129",
	"a 125. helyett vehető a 128. zsoltár",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_DPsalmZ127_131[POCET_JAZYKOV + 1] = 
{
	"namiesto žalmu 127 brať žalm 131",
 "místo žalmu 127 vzít žalm 131",
 "instead of psalm 127 use 131",
 "",
 "",
 "místo žalmu 127 vzít žalm 131",
 "a 126. helyett vehető a 130. zsoltár",
};

const char *html_text_option5_DPsalmZ122_NORMAL[POCET_JAZYKOV + 1] =
{
	"brať žalm 122 z doplnkovej psalmódie",
	"vzít žalm 122 z doplňovacího cyklu",
	"use psalm 122 from complementary psalmody",
	"",
	"",
	"vzít žalm 122 z doplňovacího cyklu",
	"hu_take 121. zsoltár from kiegészítő zsoltároknál",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_DPsalmZ126_NORMAL[POCET_JAZYKOV + 1] =
{
	"brať žalm 126 z doplnkovej psalmódie",
	"vzít žalm 126 z doplňovacího cyklu",
	"use psalm 126 from complementary psalmody",
	"",
	"",
	"vzít žalm 126 z doplňovacího cyklu",
	"hu_take 125. zsoltár from kiegészítő zsoltároknál",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_DPsalmZ127_NORMAL[POCET_JAZYKOV + 1] =
{
	"brať žalm 127 z doplnkovej psalmódie",
	"vzít žalm 127 z doplňovacího cyklu",
	"use psalm 127 from complementary psalmody",
	"",
	"",
	"vzít žalm 127 z doplňovacího cyklu",
	"hu_take 126. zsoltár from kiegészítő zsoltároknál",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_DPsalmZ122_129_explain[POCET_JAZYKOV + 1] =
{
	"V doplnkovej psalmódii namiesto žalmu 122 možno brať žalm 129.",
	"Pro doplňovací cyklus žalmů místo žalmu 122 (121) vzít žalm 129 (128).",
	"",
	"",
	"",
	"Pro doplňovací cyklus žalmů místo žalmu 122 (121) vzít žalm 129 (128).",
	"A kiegészítő zsoltároknál a 121. helyett vehető a 128. zsoltár.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_DPsalmZ126_129_explain[POCET_JAZYKOV + 1] =
{
	"V doplnkovej psalmódii namiesto žalmu 126 možno brať žalm 129.",
	"Pro doplňovací cyklus žalmů místo žalmu 126 (125) vzít žalm 129 (128).",
	"",
	"",
	"",
	"Pro doplňovací cyklus žalmů místo žalmu 126 (125) vzít žalm 129 (128).",
	"A kiegészítő zsoltároknál a 125. helyett vehető a 128. zsoltár.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_option5_DPsalmZ127_131_explain[POCET_JAZYKOV + 1] =
{
	"V doplnkovej psalmódii namiesto žalmu 127 možno brať žalm 131.",
	"Pro doplňovací cyklus žalmů místo žalmu 127 (126) vzít žalm 131 (130).",
	"",
	"",
	"",
	"Pro doplňovací cyklus žalmů místo žalmu 127 (126) vzít žalm 131 (130).",
	"A kiegészítő zsoltároknál a 126. helyett vehető a 130. zsoltár.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_font_name[POCET_JAZYKOV + 1] =
{
	"alebo použi písmo",
	"nebo použij písmo",
	"or use font",
	"vel font",
	"",
	"nebo použij písmo",
	"betűtípus kiválasztása",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_font_name_explain[POCET_JAZYKOV + 1] =
{
	"Ak nie je zvolené konkrétne písmo, použije sa predvolené písmo prehliadača (pätkové alebo bezpätkové podľa predchádzajúcej voľby zaškrtávacieho políčka).",
	"",
	"",
	"",
	"",
	"",
	"Ha nem választunk betűtípust, akkor a böngészőablakban látható az alapértelmezett (talpas vagy talpatlan az előző kiválasztás szerint).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_font_size[POCET_JAZYKOV + 1] =
{
	"veľkosť písma",
	"velikost písma",
	"font size",
	"font size",
	"",
	"velikost písma",
	"betűméret",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_font_size_explain[POCET_JAZYKOV + 1] =
{
	"Veľkosť písma",
	"",
	"",
	"",
	"",
	"",
	"betűméret",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// HTML option selected
const char *html_option_selected = " selected";

// HTML option checked (pre checkboxy)
const char *html_option_checked = " checked";

const char *html_text_kalendar[POCET_JAZYKOV + 1] =
{
	"kalendár",
	"kalendář",
	"calendar",
	"calendario",
	"",
	"kalendář",
	"a naptárat",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_kalendar_miestny[POCET_JAZYKOV + 1] = 
{
	"Kalendár Liturgie hodín",
 "Kalendář Liturgie hodin",
 "Local or general calendar", 
 "Calendario per Liturgia horarum",
 "",
 "Kalendář Liturgie hodin",
 "Az imaórák liturgiája"
};
const char *html_text_kalendar_miestny_post[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"naptárát használják",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_kalendar_miestny_explain[POCET_JAZYKOV + 1] =
{
	"Je možné zvoliť miestny kalendár (propriá) rehoľnej rodiny, rádu, kongregácie, inštitútu...",
	"Je možné vzít místní kalendář řeholní rodiny, řádu, kongregace, institutu...",
	"",
	"",
	"",
	"", // not applicable for CZOP
	"Lehetséges a helyi naptárt választani, szerzetesrendét, kongregációét, intézményét...",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *html_text_detaily_explain[POCET_JAZYKOV + 1] =
{
	"Ostatné nastavenia sa použijú z predchádzajúcej (hlavnej) stránky. <p>Pokiaľ sú niektoré parametre pre vybranú modlitbu nepoužiteľné, neberú sa do úvahy (môžu byť teda nastavené ľubovoľne).",
	"Když jsou některé výše uvedené volby nepoužitelné pro nějakou modlitbu, neberou se v úvahu (mohou být nastaveny dle libovůle).",
	"If any of described options are not applicable for a chosen prayer, they can be set anyhow.",
	"",
	"",
	"Když jsou některé výše uvedené volby nepoužitelné pro nějakou modlitbu, neberou se v úvahu (mohou být nastaveny dle libovůle).",
	"A többi beállítási lehetőség a főoldalon található. <p>Amennyiben valamelyik kiválasztott paraméter nem működik, figyelmen kívül kell hagyni (vagyis tetszőlegesen állíthatók).",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// descriptive text for Invitatory prayer
const char *html_text_inv_slavaotcu[POCET_JAZYKOV + 1] =
{
	"<p><"HTML_SPAN_RED_SMALL">Nasleduje"HTML_SPAN_END" <span class=\"small\">Sláva Otcu"HTML_SPAN_END" <"HTML_SPAN_RED_SMALL">a opakuje sa antifóna."HTML_SPAN_END,
	"<p><"HTML_SPAN_RED_SMALL">Následuje"HTML_SPAN_END" <span class=\"small\">Sláva Otci"HTML_SPAN_END" <"HTML_SPAN_RED_SMALL">a opakuje se antifona."HTML_SPAN_END,
	"<p><"HTML_SPAN_RED_SMALL">Follows"HTML_SPAN_END" <span class=\"small\">Glory..."HTML_SPAN_END" <"HTML_SPAN_RED_SMALL">a opakuje sa antifóna."HTML_SPAN_END,
	"<p><"HTML_SPAN_RED_SMALL">Nasleduje"HTML_SPAN_END" <span class=\"small\">Gloria Patri"HTML_SPAN_END" <"HTML_SPAN_RED_SMALL">a opakuje sa antifóna."HTML_SPAN_END,
	"<p><"HTML_SPAN_RED_SMALL">Nasleduje"HTML_SPAN_END" <span class=\"small\">Sláva Otcu"HTML_SPAN_END" <"HTML_SPAN_RED_SMALL">a opakuje sa antifóna."HTML_SPAN_END,
	"<p><"HTML_SPAN_RED_SMALL">Následuje"HTML_SPAN_END" <span class=\"small\">Sláva Otci"HTML_SPAN_END" <"HTML_SPAN_RED_SMALL">a opakuje se antifona."HTML_SPAN_END,
	"<p><"HTML_SPAN_RED_SMALL">Következik a"HTML_SPAN_END" <span class=\"small\">Dicsőség az Atyának"HTML_SPAN_END" <"HTML_SPAN_RED_SMALL">és megismételjük az antifónát."HTML_SPAN_END,
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// page navigation (top, bottom)
const char *html_text_top[POCET_JAZYKOV + 1] = { "&uarr; navrch", "&uarr; nahoru", "&uarr; top", "", "", "&uarr; nahoru", "&uarr; fel", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }; // HU: to up -> felfelé | up -> fel | Andy: fent | top -> eleje | to top -> elejére
const char *html_text_bottom[POCET_JAZYKOV + 1] = { "&darr; naspodok", "&darr; dolů", "&darr; bottom", "", "", "&darr; dolů", "&darr; le", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ }; // HU: to down -> lefelé | down -> le | Andy: lent | bottom -> vége | to bottom -> végére

// titles & navigation for batch mode
const char *html_text_batch_Zoznam1[POCET_JAZYKOV + 1] = { "Zoznam modlitieb", "Seznam modliteb", "List of prayers", "", "", "Seznam modliteb", "Az imák jegyzéke", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_batch_Zoznam1m[POCET_JAZYKOV + 1] = { "Zoznam modlitieb po mesiacoch", "Seznam modliteb dle měsíců", "List of prayers by months", "", "", "Seznam modliteb dle měsíců", "Az imák jegyzéke hónapok szerint", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_batch_obdobie1m[POCET_JAZYKOV + 1] = { "("/*obdobie */"od %d. %s %d do %d. %s %d)", "(pro období od %d. %s %d do %d. %s %d)", "(%d. %s %d &#x2013; %d. %s %d)", "(%d. %s %d &#x2013; %d. %s %d)", "(%d. %s %d &#x2013; %d. %s %d)", "(pro období od %d. %s %d do %d. %s %d)", "(%d. %s %d &#x2013; %d. %s %d)", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_batch_Zoznam2[POCET_JAZYKOV + 1] = {/* Zoznam modlitieb pre */"%s %d", "%s %d", "%s %d", "%s %d", "%s %d", "%s %d", "%s %d", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_batch_Back[POCET_JAZYKOV + 1] = { "&uarr; hore", "&uarr; nahoru", "&uarr; up", "", "", "&uarr; nahoru", "&uarr; felfelé", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_batch_Prev[POCET_JAZYKOV + 1] = { "&larr;", "&larr;", "&larr;", "&larr;", "&larr;", "&larr;", "&larr;", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };
const char *html_text_batch_Next[POCET_JAZYKOV + 1] = { "&rarr;", "&rarr;", "&rarr;", "&rarr;", "&rarr;", "&rarr;", "&rarr;", "ru_text", /* STRING_1_FOR_NEW_LANGUAGE */ };

// zakončenie modlitby trojaké, krátke resp. dlhé | triple prayer ending (short, long)
const char *text_ZAKONCENIE_SKRZE_dlhe[POCET_JAZYKOV + 1] =
{
	"Skrze nášho Pána Ježiša Krista, tvojho Syna, ktorý je Boh a_s_tebou žije a_kraľuje v_jednote s_Duchom Svätým po všetky veky vekov.",
	"Skrze tvého Syna Ježíše Krista, našeho Pána, neboť on s_tebou v_jednotě Ducha svatého žije a_kraluje po všechny věky věků.",
	"",
	"Per D&#243;minum nostrum Iesum Christum, F&#237;lium tuum, qui tecum vivit et regnat in unit&#225;te Sp&#237;ritus Sancti, Deus, per &#243;mnia s&#509;cula s&#230;cul&#243;rum.",
	"",
	"Skrze tvého Syna Ježíše Krista, našeho Pána, neboť on s tebou v jednotě Ducha Svatého žije a kraluje po všechny věky věků.",
	"A mi Urunk, Jézus Krisztus, a te Fiad által, aki veled él és uralkodik a Szentlélekkel egységben, Isten mindörökkön-örökké.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *text_ZAKONCENIE_SKRZE_kratke[POCET_JAZYKOV + 1] =
{
	"Skrze Krista, nášho Pána.",
	"Skrze Krista, našeho Pána.",
	"",
	"Per Christum Dóminum nostrum.",
	"",
	"Skrze Krista, našeho Pána.",
	"Krisztus, a mi Urunk által.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *text_ZAKONCENIE_LEBO_ON_dlhe[POCET_JAZYKOV + 1] =
{
	"Lebo on je Boh a_s_tebou žije a_kraľuje v_jednote s_Duchom Svätým po všetky veky vekov.",
	"Neboť on s_tebou v_jednotě Ducha svatého žije a_kraluje po všechny věky věků.",
	"",
	"Qui tecum vivit et regnat in unit&#225;te Sp&#237;ritus Sancti, Deus, per &#243;mnia s&#509;cula s&#230;cul&#243;rum.",
	"",
	"Neboť on s tebou v jednotě Ducha Svatého žije a kraluje po všechny věky věků.",
	"Aki veled él és uralkodik a Szentlélekkel egységben, Isten mindörökkön-örökké.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *text_ZAKONCENIE_LEBO_ON_kratke[POCET_JAZYKOV + 1] =
{
	"Lebo on žije a_kraľuje na veky vekov.",
	"Neboť on s_tebou žije a_kraluje na věky věků.",
	"",
	"Qui vivit et regnat in s&#509;cula s&#230;cul&#243;rum.",
	"",
	"Neboť on s tebou žije a kraluje na věky věků.",
	"Aki él és uralkodik mindörökkön-örökké.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *text_ZAKONCENIE_LEBO_TY_dlhe[POCET_JAZYKOV + 1] =
{
	"Lebo ty si Boh a_žiješ a_kraľuješ s Bohom Otcom v_jednote s_Duchom Svätým po všetky veky vekov.",
	"Neboť ty žiješ a_kraluješ s_Bohem Otcem v_jednotě Ducha svatého po všechny věky věků.",
	"",
	"Qui vivis et regnas cum Deo Patre in unit&#225;te Sp&#237;ritus Sancti, Deus, per &#243;mnia s&#509;cula s&#230;culórum.",
	"",
	"Neboť ty žiješ a kraluješ s Bohem Otcem v jednotě Ducha Svatého po všechny věky věků.",
	"Aki élsz és uralkodol az Atyaistennel és a Szentlélek­kel egységben, Isten mindörökkön-örökké.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *text_ZAKONCENIE_LEBO_TY_kratke[POCET_JAZYKOV + 1] =
{
	"Lebo ty žiješ a_kraľuješ na veky vekov.",
	"Neboť ty žiješ a_kraluješ na věky věků.",
	"",
	"Qui vivis et regnas in s&#509;cula s&#230;culórum.",
	"",
	"Neboť ty žiješ a kraluješ na věky věků.",
	"Aki élsz és uralkodol mindörökkön-örökké.",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// SK only (POST1_MODLITBA5NE)
const char *text_ZAKONCENIE_ON_JE_dlhe = "On je Boh a_s_tebou žije a_kraľuje v_jednote s_Duchom Svätým po všetky veky vekov.";
const char *text_ZAKONCENIE_ON_JE_kratke = "On žije a_kraľuje na veky vekov.";
const char *text_ZAKONCENIE_KTORY_JE_dlhe = "ktorý je Boh a_s_tebou žije a_kraľuje v_jednote s_Duchom Svätým po všetky veky vekov.";
const char *text_ZAKONCENIE_KTORY_JE_kratke = "ktorý žije a_kraľuje na veky vekov.";

const char *text_ZAKONCENIE_O_TO_TA_PROSIME[POCET_JAZYKOV + 1] =
{
	"O_to ťa prosíme",
	"Prosíme o_to",
	"",
	"",
	"",
	"Prosíme o_to",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// pre dominikánov | for CZOP label
const char *text_PRO_OP[POCET_JAZYKOV + 1] =
{
	"Pre dominikánov (CZ_OP): ",
	"Pro dominikány (OP CZ): ",
	"",
	"",
	"",
	"Pro OP CZ: ",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// nasledujú názvy liturgických dní -- follow the names of special liturgical celebrations

// --------------- 00 pohyblivé slávenia | celebrations with moving dates ---------------

const char *text_DRUHA_NEDELA_PO_NAR_PANA[POCET_JAZYKOV + 1] =
{
	"2. nedeľa po Narodení Pána",
	"2. neděle po Narození Páně",
	"",
	"",
	"",
	"2. neděle po Narození Páně",
	"Karácsony Utáni 2. Vasárnap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 01 január | january ---------------

const char *text_JAN_01[POCET_JAZYKOV + 1] =
{
	"Panny Márie Bohorodičky",
	"Matky Boží, Panny Marie",
	"",
	"Sanct&#230; Dei Genetricis Mari&#230;",
	"",
	"Matky Boží, Panny Marie",
	"Szűz Mária, Isten Anyja (újév)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_01_SJ[POCET_JAZYKOV + 1] =
{
	"Panny Márie Bohorodičky a Mena Ježiš "HTML_LINE_BREAK"(Titulárny sviatok Spoločnosti Ježišovej)", // titulárny sviatok Spoločnosti Ježišovej
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_02[POCET_JAZYKOV + 1] =
{
	"Sv. Bazila Veľkého a Gregora Nazianzského, "HTML_LINE_BREAK"biskupov a učiteľov Cirkvi",
	"Sv. Basila Velikého a Řehoře Naziánského, "HTML_LINE_BREAK"biskupů a učitelů církve",
	"",
	"Ss. Basilii Magni et Gregorii Nazianzeni, ep. et Eccl. doct.",
	"",
	"Sv. Basila Velikého a Řehoře Naziánského, "HTML_LINE_BREAK"biskupů a učitelů Církve",
	"Nagy Szent Vazul és Nazianzi Szent Gergely püspökök és egyháztanítók",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_03[POCET_JAZYKOV + 1] =
{
	"Najsvätejšieho mena Ježiš",
	"Nejsvětějšího jména Ježíš",
	"",
	"",
	"",
	"Nejsvětějšího Jména Ježíš",
	"Jézus szent neve",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_04_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Angely z Foligna, rehoľníčky, členky 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_05_CSSR[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Nepomuckého Neumanna, biskupa",
	"", // CZ (aj CZ CSsR): 19JUN
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_05_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Didaka Jozefa z Cádizu, kňaza, člena 1. rádu",
	"Bl. Diega Josefa z Cádizu, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_06[POCET_JAZYKOV + 1] = // 6. januára | alebo nedeľu medzi 2. a 8. januárom
{
	"Zjavenie Pána",
	"Zjevení Páně",
	"",
	"In Epiphania Domini",
	"",
	"Zjevení Páně",
	"Urunk megjelenése (Vízkereszt)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_07[POCET_JAZYKOV + 1] =
{
	"Sv. Rajmunda z Peňafortu, kňaza",
	"Sv. Rajmunda z Penafortu, kněze",
	"",
	"S. Raimundi de Penyafort, presb.",
	"",
	"Sv. Rajmunda z Peňafortu, kněze",
	"Penyaforti Szent Rajmund áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_10_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Gundislava z Amarante, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_10_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Anny Monteagudovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_11_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Bernarda Scammaccu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_KRST[POCET_JAZYKOV + 1] = // v nedeľu po 6. januári | (v nedeľu po Zjavení Pána) alebo: ak však táto nedeľa (zrejme Zjavenia Pána) padne na deň 7. alebo 8. januára, ofícium sa slávi v nasledujúci deň
{
	"Krst Krista Pána",
	"Křtu Páně",
	"",
	"In Baptismate Domini",
	"",
	"Křtu Páně",
	"Urunk megkeresztelkedése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_12_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Bernarda z Corleone, rehoľníka, člena 1. rádu",
	"Sv. Bernarda z Corleone, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_13[POCET_JAZYKOV + 1] =
{
	"Sv. Hilára, biskupa a učiteľa Cirkvi",
	"Sv. Hilaria, biskupa a učitele církve",
	"",
	"S. Hilarii, ep. et Eccl. doct.",
	"",
	"Sv. Hilaria, biskupa a učitele Církve",
	"Szent Hiláriusz (Vidor) püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_14_CSSR[POCET_JAZYKOV + 1] =
{
	"Bl. Petra Dondersa, kňaza",
	"Bl. Petra Donderse, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_14_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Odorika z Pordenone, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_14_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Gotfrída, řeholníka z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_15_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Remete Szent Pál szerzetes",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_15_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Fernándeza de Capillas, kňaza, "HTML_LINE_BREAK"sv. Petra Sansa, biskupa, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"Sv. Františka Fernándeze de Capillas, kněze, "HTML_LINE_BREAK"Petra Sanse, biskupa, a druhů, čínských mučedníků",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_15_SVD[POCET_JAZYKOV + 1] =
{
	"Sv. Arnolda Janssena, kňaza a zakladateľa troch misijných rehoľných spoločností",
	"",
	"",
	"la_",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_15_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Alojza Variaru, kňaza",
	"Bl. Aloise Variary, kněze",
	"",
	"la_",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_16_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Berarda, kňaza, a spoločníkov, prvých františkánskych mučeníkov",
	"Sv. Berarda, kněze, a druhů, mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_17[POCET_JAZYKOV + 1] =
{
	"Sv. Antona, opáta",
	"Sv. Antonína, opata",
	"",
	"S. Antonii, abbatis",
	"",
	"Sv. Antonína, opata",
	"Szent Antal apát",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_18_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Panny Marie, Matky jednoty křesťanů",
	"",
	"",
	"",
	"Panny Marie, Matky jednoty křesťanů",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_18[POCET_JAZYKOV + 1] =
{
	"Sv. Margity Uhorskej, panny",
	"",
	"",
	"la_",
	"",
	"Sv. Markéty Uherské, panny, mnišky", // CZOP 19. januára kvôli text_JAN_18_CZ
	"Árpád-házi Szent Margit szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_19_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Andreja z Peschiera, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_19_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Jakuba Sal&#232;sa a Viliama Saultemouchea, Ignáca de Azevedo a spoločníkov, "HTML_LINE_BREAK"Jakuba Bonnauda a spoločníkov, mučeníkov", // &egrave;
	"",
	"",
	"",
	"",
	"_",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_20_1[POCET_JAZYKOV + 1] =
{
	"Sv. Fabiána, pápeža a mučeníka",
	"Sv. Fabiána, papeže a mučedníka",
	"",
	"S. Fabiani, pap&#230; et mart.",
	"",
	"Sv. Fabiána, papeže a mučedníka",
	"Szent Fábián pápa és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_20_2[POCET_JAZYKOV + 1] =
{
	"Sv. Šebastiána, mučeníka",
	"Sv. Šebestiána, mučedníka",
	"",
	"S. Sebastiani, mart.",
	"",
	"Sv. Šebestiána, mučedníka",
	"Szent Sebestyén vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_20_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Jána Krstiteľa Triquerie, kňaza a mučeníka, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_20_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Esztergomi Boldog Özséb áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_21[POCET_JAZYKOV + 1] =
{
	"Sv. Agnesy, panny a mučenice",
	"Sv. Anežky, panny a mučednice",
	"",
	"S. Agnetis, virg. et mart.",
	"",
	"Sv. Anežky, panny a mučednice",
	"Szent Ágnes szűz és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_22[POCET_JAZYKOV + 1] =
{
	"Sv. Vincenta, diakona a mučeníka",
	"Sv. Vincence, jáhna a mučedníka",
	"",
	"S. Vincentii, diaconi et mart.",
	"",
	"Sv. Vincence, jáhna a mučedníka",
	"Szent Vince diakónus és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_22_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Antona della Chiesa, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_22_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Boldog Batthyány-Stratmann László családapa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_22_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Laury Vicuňovej, panny a mučenice",
	"Bl. Laury Vicuňi, panny a mučednice",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_23_SK[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Almužníka, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_23_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Henricha Suzu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_24[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Saleského, biskupa a učiteľa Cirkvi",
	"Sv. Františka Saleského, biskupa a učitele církve",
	"",
	"S. Francisci de Sales, ep. et Eccl. doct.",
	"",
	"Sv. Františka Saleského, biskupa a učitele Církve",
	"Szalézi Szent Ferenc püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_24_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Saleského, biskupa a učiteľa Cirkvi, "HTML_LINE_BREAK"titulárneho patróna saleziánskej rodiny",
	"Sv. Františka Saleského, biskupa a učitele církve, "HTML_LINE_BREAK"titulárního patrona Společnosti sv. Františka Saleského",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_25[POCET_JAZYKOV + 1] =
{
	"Obrátenie svätého Pavla, apoštola",
	"Obrácení svatého Pavla, apoštola",
	"",
	"In Conversione S. Pauli, Apostoli",
	"",
	"Obrácení svatého Pavla, apoštola",
	"Szent Pál apostol megtérése (Pál fordulása)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_26[POCET_JAZYKOV + 1] =
{
	"Sv. Timoteja a Títa, biskupov",
	"Sv. Timoteje a Tita, biskupů",
	"",
	"Ss. Timothei et Titi, ep.",
	"",
	"Sv. Timoteje a Tita, biskupů",
	"Szent Timóteus és Szent Titusz püspökök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_27[POCET_JAZYKOV + 1] =
{
	"Sv. Angely Merici, panny",
	"Sv. Anděly Mericiové, panny",
	"",
	"S. Angel&#230; Merici, virg.",
	"",
	"Sv. Anděly Mericiové, panny",
	"Merici Szent Angéla szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_27_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Markolína z Forl&#236;, kňaza", // &igrave;
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_28[POCET_JAZYKOV + 1] =
{
	"Sv. Tomáša Akvinského, kňaza a učiteľa Cirkvi",
	"Sv. Tomáše Akvinského, kněze a učitele církve",
	"",
	"S. Thom&#230; de Aquino, presb. et Eccl. doct.",
	"",
	"Sv. Tomáše Akvinského, kněze a učitele Církve",
	"Aquinói Szent Tamás áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_29_SVD[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa Freinademetza, kňaza",
	"",
	"",
	"la_",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_29_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Villany delle Botti, matky rodiny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_30_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Bronislava Markiewicza, kňaza",
	"Bl. Bronislava Markiewicze, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_30_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Hyacinty Mariscottiovej, panny, členky 3. rádu",
	"Sv. Hyacinty Mariscotti, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_31[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Boska, kňaza", // Direktórium 2012, str. 72, má: 'Bosca'
	"Sv. Jana Boska, kněze",
	"",
	"S. Ioannis Bosco, presb.",
	"",
	"Sv. Jana Boska, kněze",
	"Bosco Szent János áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JAN_31_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Boska, kňaza, otca a učiteľa mládeže, "HTML_LINE_BREAK"zakladateľa Spoločnosti svätého Františka Saleského, "HTML_LINE_BREAK"Inštitútu dcér Márie Pomocnice "HTML_LINE_BREAK"a saleziánov spolupracovníkov",
	"Sv. Jana Boska, kněze, otce a učitele mládeže, "HTML_LINE_BREAK"zakladatele Společnosti sv. Františka Saleského, "HTML_LINE_BREAK"Institutu Dcer Panny Marie Pomocnice "HTML_LINE_BREAK"a Salesiánů spolupracovníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 02 február | february ---------------

const char *text_FEB_01_SDB[POCET_JAZYKOV + 1] =
{
	"Všetkých nebohých členov Spoločnosti svätého Františka Saleského",
	"Připomínka zemřelých salesiánů",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_02[POCET_JAZYKOV + 1] =
{
	"Obetovanie Pána",
	"Uvedení Páně do chrámu",
	"",
	"In Pr&#230;sentatione Domini",
	"",
	"Uvedení Páně do chrámu",
	"Urunk bemutatása (Gyertyaszentelő Boldogasszony)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_03_1[POCET_JAZYKOV + 1] =
{
	"Sv. Blažeja, biskupa a mučeníka",
	"Sv. Blažeje, biskupa a mučedníka",
	"",
	"S. Blasii, ep. et mart.",
	"",
	"Sv. Blažeje, biskupa a mučedníka",
	"Szent Balázs püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_03_2[POCET_JAZYKOV + 1] =
{
	"Sv. Oskára, biskupa",
	"Sv. Ansgara, biskupa",
	"",
	"S. Ansgarii, ep.",
	"",
	"Sv. Ansgara, biskupa",
	"Szent Anszgár (Oszkár) püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_03_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Petra z Ruff&#236;a, kňaza a mučeníka", // &igrave;
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_03_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Antona Pavoniho, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_03_3_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Bartolomeja Cerveriho, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_04_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Kataríny de’ Ricci, panny",
	"",
	"",
	"",
	"",
	"Sv. Kateřiny z Ricci, panny, řeholnice",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_04_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Jána de Brito, kňaza, bl. Rudolfa Acquavivu, kňaza a jeho spoločníkov; "HTML_LINE_BREAK"bl. Františka Pacheca, Karola Spinolu, kňazov a spoločníkov, mučeníkov; "HTML_LINE_BREAK"bl. Jakuba Berthieu, kňaza, Leva Mangina, kňaza a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_04_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa z Leonissy, kňaza, člena 1. rádu",
	"Sv. Josefa z Leonessy, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_04_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Bedřicha, opata z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_05[POCET_JAZYKOV + 1] =
{
	"Sv. Agáty, panny a mučenice", // direktóriá uvádzajú Agáta s dlhým "á"; LH s krátkym "a" Agata
	"Sv. Agáty, panny a mučednice",
	"",
	"S. Agath&#230;, virg. et mart.",
	"",
	"Sv. Agáty, panny a mučednice",
	"Szent Ágota szűz és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_06[POCET_JAZYKOV + 1] =
{
	"Sv. Pavla Mikiho a spoločníkov, mučeníkov",
	"Sv. Pavla Mikiho a druhů, mučedníků",
	"",
	"Ss. Pauli Miki et sociorum, mart.",
	"",
	"Sv. Pavla Mikiho a druhů, mučedníků",
	"Miki Szent Pál és társai vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_06_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Pavla Mikiho, rehoľníka, a jeho spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_06_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Baptistu, kňaza, a spoločníkov, františkánskych mučeníkov",
	"Sv. Petra Křtitele, Pavla Mikiho a druhů, mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_07_OP[POCET_JAZYKOV + 1] =
{
	"Spomienka na zosnulých otcov a matky členov rehole",
	"",
	"",
	"",
	"",
	"Výroční památka zemřelých otců a matek",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_07_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Pia IX., pápeža",
	"Bl. Pia IX., papeže",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_07_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Kolety z Corbie, panny, členky 2. rádu",
	"Sv. Kolety z Corbie, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_08_1[POCET_JAZYKOV + 1] =
{
	"Sv. Hieronyma Emilianiho",
	"Sv. Jeronýma Emilianiho",
	"",
	"S. Hieronymi Emiliani",
	"",
	"Sv. Jeronýma Emilianiho",
	"Emiliáni Szent Jeromos",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_08_2[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefíny Bakhity, panny",
	"Sv. Josefiny Bakhity, panny",
	"",
	"",
	"",
	"Sv. Josefiny Bakhity, panny",
	"Bakhita Szent Jozefina szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_09_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Euzébie Palominovej Yenes, panny",
	"Bl. Eusebie Palomino, řeholnice",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_09_OFMCAP[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Leopolda z Alpandeire, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_10[POCET_JAZYKOV + 1] =
{
	"Sv. Školastiky, panny",
	"Sv. Scholastiky, panny",
	"",
	"S. Scholastic&#230;, virg.",
	"",
	"Sv. Scholastiky, panny",
	"Szent Skolasztika szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_10_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Huga, opata z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_11[POCET_JAZYKOV + 1] =
{
	"Prebl. Panny Márie Lurdskej",
	"Panny Marie Lurdské",
	"",
	"B. Mari&#230; Virg. de Lourdes",
	"",
	"Panny Marie Lurdské",
	"A Lourdes-i Boldogságos Szűz Mária",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_12_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Reginalda Orleánskeho, kňaza",
	"",
	"",
	"",
	"",
	"Bl. Reginalda z Orléansu, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_13_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jordána Saského, kňaza",
	"",
	"",
	"",
	"",
	"Bl. Jordána Saského, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_14[POCET_JAZYKOV + 1] =
{
	"Sv. Cyrila, mnícha, a sv. Metoda, biskupa", // (na Slovensku sa slávi 5. júla) | odstránený popis "patrónov Európy"
	"(slaví se 5. června)",
	"",
	"Ss. Cyrilli, monachi, et Methodii, ep.",
	"",
	"",
	"Szent Cirill szerzetes és Szent Metód püspök, "HTML_LINE_BREAK"Európa társvédőszentjei",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_15_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Klaudia La Colombi&#232;ra, kňaza", // &egrave;
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_15_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Bedřicha Bachsteina a druhů, mučedníků",
	"",
	"",
	"",
	"Bl. Bedřicha Bachsteina a druhů, mučedníků",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_16_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Mikuláša Pagliu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_17[POCET_JAZYKOV + 1] =
{
	"Siedmich svätých zakladateľov "HTML_LINE_BREAK"rehole Služobníkov Panny Márie",
	"Sv. Alexia a druhů, řeholníků",
	"",
	"Ss. Septem Fundatorum Ordinis Servorum B. Mari&#230; Virg.",
	"",
	"Sv. Alexia a druhů, řeholníků",
	"A szervita rend hét szent alapítója",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_17_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Evermoda, biskupa z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_18_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. sedmi zakladatelů řádu servitů",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_18_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jána (Angelika) z Fiesole, kňaza",
	"",
	"",
	"",
	"",
	"Bl. Jana z Fiesole neboli fra Angelica, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_19_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Alvara z Kordovy, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_20_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Krištofa z Milána, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_21[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Damianiho, biskupa a učiteľa Cirkvi",
	"Sv. Petra Damianiho, biskupa a učitele církve",
	"",
	"S. Petri Damiani, ep. et Eccl. doct.",
	"",
	"Sv. Petra Damianiho, biskupa a učitele Církve",
	"Damiáni Szent Péter püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_22[POCET_JAZYKOV + 1] =
{
	"Katedra sv. Petra, apoštola",
	"Stolce svatého Petra, apoštola",
	"",
	"Cathedr&#230; S. Petri, Apostoli",
	"",
	"Stolce svatého Petra, apoštola",
	"Szent Péter apostol székfoglalása",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_23[POCET_JAZYKOV + 1] =
{
	"Sv. Polykarpa, biskupa a mučeníka",
	"Sv. Polykarpa, biskupa a mučedníka",
	"",
	"S. Polycarpi, ep. et mart.",
	"",
	"Sv. Polykarpa, biskupa a mučedníka",
	"Szent Polikárp püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_24_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Konštanca z Fabriana, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_FEB_25_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Alojza Versigliu, biskupa, a Kalixta Caravaria, kňaza, "HTML_LINE_BREAK"prvých saleziánskych mučeníkov",
	"Sv. Aloise Versiglii, biskupa, a Kalista Caravaria, kněze, "HTML_LINE_BREAK"prvních salesiánských mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 00 pohyblivé slávenia ---------------

const char *text_POPOLCOVA_STREDA[POCET_JAZYKOV + 1] =
{
	"Popolcová streda",
	"Popeleční středa",
	"",
	"",
	"",
	"Popeleční středa",
	"Hamvazószerda",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 03 marec | march ---------------

const char *text_MAR_02_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Anežky Českej, panny, členky 2. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_04[POCET_JAZYKOV + 1] =
{
	"Sv. Kazimíra",
	"Sv. Kazimíra",
	"",
	"S. Casimiri",
	"",
	"Sv. Kazimíra",
	"Szent Kázmér",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_04_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Boldog Meszlényi Zoltán püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_07[POCET_JAZYKOV + 1] =
{
	"Sv. Perpetuy a Felicity, mučeníc",
	"Sv. Perpetuy a Felicity, mučednic",
	"",
	"Ss. Perpetu&#230; et Felicitatis, mart.",
	"",
	"Sv. Perpetuy a Felicity, mučednic",
	"Szent Perpétua és Felicitász vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_08[POCET_JAZYKOV + 1] =
{
	"Sv. Jána z Boha, rehoľníka",
	"Sv. Jana z Boha, řeholníka",
	"",
	"S. Ioannis a Deo, relig.",
	"",
	"Sv. Jana z Boha, řeholníka",
	"Istenes Szent János szerzetes",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_09[POCET_JAZYKOV + 1] =
{
	"Sv. Františky Rímskej, rehoľníčky",
	"Sv. Františky Římské, řeholnice",
	"",
	"S. Francisc&#230; Roman&#230;, relig.",
	"",
	"Sv. Františky Římské, řeholnice",
	"Római Szent Franciska szerzetesnő",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_10_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Bratislave", // ToDo: 'sv. Martina z Tours', podľa Direktória 2012, str. 93
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_10_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Jana Ogilvie, kněze a mučedníka",
	"",
	"",
	"",
	"Sv. Jana Ogilvie, kněze a mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_12_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Angely Salawovej, panny, členky 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_15_CSSR[POCET_JAZYKOV + 1] =
{
	"Sv. Klementa Márie Hofbauera, kňaza",
	"Sv. Klementa Marie Hofbauera (Dvořáka), kněze", // CZ CSsR: 20MAJ
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_17[POCET_JAZYKOV + 1] =
{
	"Sv. Patrika, biskupa",
	"Sv. Patrika, biskupa",
	"",
	"S. Patricii, ep.",
	"",
	"Sv. Patrika, biskupa",
	"Szent Patrik püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_17_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"A Győri könnyező Szűz Mária",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_18[POCET_JAZYKOV + 1] =
{
	"Sv. Cyrila Jeruzalemského, biskupa a učiteľa Cirkvi",
	"Sv. Cyrila Jeruzalémského, biskupa a učitele církve",
	"",
	"S. Cyrilli Hierosolymitani, ep. et Eccl. doct.",
	"",
	"Sv. Cyrila Jeruzalémského, biskupa a učitele Církve",
	"Jeruzsálemi Szent Cirill püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_18_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Salvatora z Horty, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_19[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa, ženícha Panny Márie",
	"Sv. Josefa, Snoubence Panny Marie",
	"",
	"S. Ioseph, Sponsi B. Mari&#230; V.",
	"",
	"Sv. Josefa, Snoubence Panny Marie",
	"Szent József, a Boldogságos Szűz Mária jegyese",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_23[POCET_JAZYKOV + 1] =
{
	"Sv. Turibia de Mongrovejo, biskupa",
	"Sv. Turibia z Mongroveja, biskupa",
	"",
	"S. Turibii de Mogrovejo, ep.",
	"",
	"Sv. Turibia z Mongroveja, biskupa",
	"Mongrovejói Szent Turibiusz püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAR_25[POCET_JAZYKOV + 1] =
{
	"Zvestovanie Pána",
	"Zvěstování Páně",
	"",
	"In Annuntiatione Domini",
	"",
	"Zvěstování Páně",
	"Urunk születésének hírüladása (Gyümölcsoltó Boldogasszony)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 04 apríl | april ---------------

const char *text_APR_02[POCET_JAZYKOV + 1] =
{
	"Sv. Františka z Paoly, pustovníka",
	"Sv. Františka z Pauly, poustevníka",
	"",
	"S. Francisci de Paola, eremitai",
	"",
	"Sv. Františka z Pauly, poustevníka",
	"Paolai Szent Ferenc remete",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_04[POCET_JAZYKOV + 1] =
{
	"Sv. Izidora, biskupa a učiteľa Cirkvi",
	"Sv. Izidora, biskupa a učitele církve",
	"",
	"S. Isidori, ep. et Eccl. doct.",
	"",
	"Sv. Izidora, biskupa a učitele Církve",
	"Szent Izidor püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_05[POCET_JAZYKOV + 1] =
{
	"Sv. Vincenta Ferrera, kňaza",
	"Sv. Vincence Ferrerského, kněze",
	"",
	"S. Vincentii Ferrer, presb.",
	"",
	"Sv. Vincence Ferrerského, kněze",
	"Ferrer Szent Vince áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_07[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Krstiteľa de la Salle, kňaza",
	"Sv. Jana Křtitele de la Salle, kněze",
	"",
	"S. Ioannis Baptist&#230; de la Salle, presb.",
	"",
	"Sv. Jana Křtitele de la Salle, kněze",
	"De la Salle Szent János áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_10_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Antona Neyrota, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_11[POCET_JAZYKOV + 1] =
{
	"Sv. Stanislava, biskupa a mučeníka",
	"Sv. Stanislava, biskupa a mučedníka",
	"",
	"S. Stanislai, ep. et mart.",
	"",
	"Sv. Stanislava, biskupa a mučedníka",
	"Szent Szaniszló püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_13[POCET_JAZYKOV + 1] =
{
	"Sv. Martina I., pápeža a mučeníka",
	"Sv. Martina I., papeže a mučedníka",
	"",
	"S. Martini I, pap&#230; et mart.",
	"",
	"Sv. Martina I., papeže a mučedníka",
	"Szent I. Márton pápa és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_13_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Margity z Citt&#224; di Castello, panny", // &agrave;
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_14_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Petra Gonzáleza, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_16[POCET_JAZYKOV + 1] =
{
	"Sv. Márie Bernadety Soubirousovej, panny",
	"Sv. Marie Bernadetty Soubirous, panny",
	"",
	"S. Marii Bernadette Soubirous, virg.",
	"",
	"Sv. Marie Bernadetty Soubirous, panny",
	"Soubirous Szent Mária Bernadett szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_17_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Kláry Gambacortovej, rehoľníčky",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_17_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Manciniovej, rehoľníčky",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_19_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Isnarda z Chiampa, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_19_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Sybiliny Biscossiovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_20_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Agnesy z Montepulciana, panny",
	"",
	"",
	"",
	"",
	"Sv. Anežky z Montepulciana, panny, mnišky",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_21[POCET_JAZYKOV + 1] =
{
	"Sv. Anzelma, biskupa a učiteľa Cirkvi",
	"Sv. Anselma, biskupa a učitele církve",
	"",
	"S. Anselmi, ep. et Eccl. doct.",
	"",
	"Sv. Anselma, biskupa a učitele Církve",
	"Szent Anzelm püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_21_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Konráda z Parzhamu, rehoľníka, člena 1. rádu",
	"Sv. Konráda z Parzhamu, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_22_SJ[POCET_JAZYKOV + 1] =
{
	"Prebl. Panny Márie, Matky Spoločnosti Ježišovej",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_23[POCET_JAZYKOV + 1] =
{
	"Sv. Vojtecha, biskupa a mučeníka",
	"Sv. Vojtěcha, biskupa a mučedníka",
	"",
	"S. Adalberti, ep. et mart.",
	"",
	"Sv. Vojtěcha, biskupa a mučedníka",
	"Szent Adalbert (Béla) püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_23_HU[POCET_JAZYKOV + 1] =
{
	"Sv. Vojtecha, biskupa a mučeníka",
	"Sv. Vojtěcha, biskupa a mučedníka",
	"",
	"S. Adalberti, ep. et mart.",
	"",
	"Sv. Vojtěcha, biskupa a mučedníka",
	"Szent Adalbert (Béla) püspök és vértanú, az Esztergomi főegyházmegye védőszentje",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_23_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Egida z Assisi, rehoľníka, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_24_1[POCET_JAZYKOV + 1] =
{
	"Sv. Juraja, mučeníka",
	"Sv. Jiří, mučedníka",
	"",
	"S. Georgii, mart.",
	"",
	"Sv. Jiří, mučedníka",
	"Szent György vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_24_2[POCET_JAZYKOV + 1] =
{
	"Sv. Fidéla zo Sigmaringenu, kňaza a mučeníka",
	"Sv. Fidela ze Sigmaringy, kněze a mučedníka",
	"",
	"S. Fidelis a Sigmaringen, presb. et mart.",
	"",
	"Sv. Fidela ze Sigmaringy, kněze a mučedníka",
	"Sigmaringeni Szent Fidél áldozópap és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_24_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Fidela zo Sigmaringenu, kňaza a mučeníka, člena 1. rádu",
	"Sv. Fidela ze Sigmaringy, kněze a mučedníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_24_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Obrácení našeho otce svatého Augustina, "HTML_LINE_BREAK"biskupa a učitele církve",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_25[POCET_JAZYKOV + 1] =
{
	"Sv. Marka, evanjelistu",
	"Sv. Marka, evangelisty",
	"",
	"S. Marci, evangelist&#230;",
	"",
	"Sv. Marka, evangelisty",
	"Szent Márk evangélista",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_26_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Ludolfa, biskupa a mučedníka "HTML_LINE_BREAK"z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_27_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Kanízia, kňaza a učiteľa Cirkvi",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_27_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Hosanny Kotorskej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_28_1[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Chanela, kňaza a mučeníka",
	"Sv. Petra Chanela, kněze a mučedníka",
	"",
	"S. Petri Chanel, presb. et mart.",
	"",
	"Sv. Petra Chanela, kněze a mučedníka",
	"Chanel Szent Péter áldozópap és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_28_2[POCET_JAZYKOV + 1] =
{
	"Sv. Ľudovíta Márie Grignion de Montfort, kňaza",
	"Sv. Ludvíka Marie Grignona z Montfortu, kněze",
	"",
	"S. Ludovici M. Grignion de Montfort, presb.",
	"",
	"Sv. Ludvíka Marie Grignona z Montfortu, kněze, terciáře",
	"Montforti Grignion Szent Lajos Mária áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_29[POCET_JAZYKOV + 1] =
{
	"Sv. Kataríny Sienskej, panny a učiteľky Cirkvi, "HTML_LINE_BREAK"patrónky Európy",
	"Sv. Kateřiny Sienské, panny a učitelky církve, "HTML_LINE_BREAK"patronky Evropy",
	"",
	"S. Catharin&#230; Senensis, virg. et Eccl. doct.",
	"",
	"Sv. Kateřiny Sienské, panny a učitelky Církve, "HTML_LINE_BREAK"patronky Evropy, terciářky",
	"Sienai Szent Katalin szűz és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_30[POCET_JAZYKOV + 1] =
{
	"Sv. Pia V., pápeža",
	"Sv. Pia V., papeže",
	"",
	"S. Pii V, pap&#230;",
	"",
	"Sv. Pia V., papeže",
	"Szent V. Piusz pápa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_30_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Zikmunda, mučedníka",
	"",
	"",
	"",
	"Sv. Zikmunda, mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_APR_30_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Benedikta z Urbina, kňaza, člena 1. rádu",
	"Bl. Benedikta z Urbina, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 05 máj | may ---------------

const char *text_MAJ_01[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa, robotníka",
	"Sv. Josefa, Dělníka",
	"",
	"S. loseph Opificis",
	"",
	"Sv. Josefa, Dělníka",
	"Munkás Szent József",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_02[POCET_JAZYKOV + 1] =
{
	"Sv. Atanáza, biskupa a učiteľa Cirkvi",
	"Sv. Atanáše, biskupa a učitele církve",
	"",
	"S. Athanasii, ep. et Eccl. doct.",
	"",
	"Sv. Atanáše, biskupa a učitele Církve",
	"Szent Atanáz püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_02_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Přenesení sv. Norberta, našeho otce", // iba na Stahove
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_03[POCET_JAZYKOV + 1] =
{
	"Sv. Filipa a Jakuba, apoštolov",
	"Sv. Filipa a Jakuba, apoštolů",
	"",
	"Ss. Philippi et Iacobi, apostolorum",
	"",
	"Sv. Filipa a Jakuba, apoštolů",
	"Szent Fülöp és Szent Jakab apostol",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_04_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Szent Flórián vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_04_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Jozefa Márie Rubia, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_04_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Emílie Bicchieriovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_06_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Jana Sarkandra, kněze a mučedníka",
	"",
	"",
	"",
	"Sv. Jana Sarkandra, kněze a mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_06_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Dominika Savia, mladíka",
	"Sv. Dominika Savia, chlapce",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_07_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Alberta z Bergama, otca rodiny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_07_HU_1[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Boldog Gizella királyné",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_07_HU_2[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Az Egri bazilika-főszékesegyház",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_08_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Panny Marie, Prostřednice všech milostí",
	"",
	"",
	"",
	"Panny Marie, Prostřednice všech milostí",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_08_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Panny Márie, patrónky Rehole kazateľov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_08_OFM[POCET_JAZYKOV + 1] =
{
	"Preblahoslavenej Panny Márie, Matky a Sprostredkovateľky milostí",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_08_2_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Ulriky Nischovej, panny, rehoľníčky, členky 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_08_3_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Jeremiáša z Valašska, rehoľníka, člena 1. rádu",
	"Bl. Jeremiáše z Valachie, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_09_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Kataríny z Bologne, panny, členky 2. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_10_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Antonína Florentského, biskupa",
	"",
	"",
	"",
	"",
	"Sv. Antonína Pierozziho neboli Florentského, biskupa",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_11_SK[POCET_JAZYKOV + 1] =
{
	"Bl. Sáry Salkaháziovej, panny a mučenice",
	"",
	"",
	"",
	"",
	"",
	"Boldog Salkaházi Sára szűz és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_11_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Ignáca z Laconie, rehoľníka, člena 1. rádu",
	"Sv. Ignáce z Laconi, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_11_OP[POCET_JAZYKOV + 1] = // vo všeobecnom kalendári pre OP sa slávi 13. mája
{
	"Bl. Imeldy Lambertiniovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_12_1[POCET_JAZYKOV + 1] =
{
	"Sv. Nerea a Achila, mučeníkov",
	"Sv. Nerea a Achillea, mučedníků",
	"",
	"Ss. Nerei et Achillei, mart.",
	"",
	"Sv. Nerea a Achillea, mučedníků",
	"Szent Néreusz és Szent Achilleusz vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_12_2[POCET_JAZYKOV + 1] =
{
	"Sv. Pankráca, mučeníka",
	"Sv. Pankráce, mučedníka",
	"",
	"S. Pancratii, mart.",
	"",
	"Sv. Pankráce, mučedníka",
	"Szent Pongrác vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_12_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály sv. Víta",
	"",
	"",
	"",
	"Výročí posvěcení katedrály sv. Víta",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_12_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Leopolda Mandića, kňaza, člena 1. rádu",
	"Sv. Leopolda Mandiče, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_12_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jany Portugalskej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_13[POCET_JAZYKOV + 1] =
{
	"Panny Márie Fatimskej",
	"Panny Marie Fatimské",
	"",
	"",
	"",
	"Panny Marie Fatimské",
	"A Fatimai Boldogságos Szűz Mária",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_13_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Márie Dominiky Mazzarellovej, panny, "HTML_LINE_BREAK"spoluzakladateľky Inštitútu dcér Márie Pomocnice",
	"Sv. Marie Dominiky Mazzarellové, panny "HTML_LINE_BREAK"a spoluzakladatelky Institutu Dcer Panny Marie Pomocnice",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_13_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Regalada, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_14[POCET_JAZYKOV + 1] =
{
	"Sv. Mateja, apoštola",
	"Sv. Matěje, apoštola",
	"",
	"S. Matthi&#230;, apostoli",
	"",
	"Sv. Matěje, apoštola",
	"Szent Mátyás apostol", // v HU sa slávi 24.2.
};
const char *text_MAJ_15_CZOP[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"Panny Marie, ochránkyně Řádu bratří kazatelů",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_15_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Egída z Vauzela, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_15_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Andreja Abellona, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_16_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Andreja Bobolu, kňaza a mučeníka", // text_MAJ_15_SJ: na Slovensku sa slávi 15. mája
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_16[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Nepomuckého, kňaza a mučeníka",
	"Sv. Jana Nepomuckého, kněze a mučedníka, "HTML_LINE_BREAK"hlavního patrona Čech",
	"",
	"",
	"",
	"Sv. Jana Nepomuckého, kněze a mučedníka, "HTML_LINE_BREAK"hlavního patrona Čech",
	"Nepomuki Szent János áldozópap és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_16_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Alojza Orioneho, kňaza",
	"Sv. Aloise Orione, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_16_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Margity z Cortony, kajúcnice, členky 3. rádu",
	"Sv. Markéty z Cortony, kajícnice 3. řádu", // CZ OFM: slávi sa 15MAJ
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_17_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Paschala Baylona, rehoľníka, člena 1. rádu",
	"Sv. Paskala Baylóna, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_17_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Boldog Scheffler János püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_18[POCET_JAZYKOV + 1] =
{
	"Sv. Jána I., pápeža a mučeníka",
	"Sv. Jana I., papeže a mučedníka",
	"",
	"S. Ioannis I, pap&#230; et mart.",
	"",
	"Sv. Jana I., papeže a mučedníka",
	"Szent I. János pápa és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_18_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Leonarda Murialda, kňaza",
	"Sv. Leonarda Murialda, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_18_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Felixa z Cantalicie, rehoľníka, člena 1. rádu",
	"Sv. Felixe z Cantalice, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_19_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Krišpína z Viterba, rehoľníka, člena 1. rádu",
	"Sv. Kryšpína z Viterba, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_19_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Františka Colla Guitarta, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_20_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Klementa Marie Hofbauera, kněze",
	"",
	"",
	"",
	"Sv. Klementa Marie Hofbauera, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_20[POCET_JAZYKOV + 1] =
{
	"Sv. Bernardína Sienského, kňaza",
	"Sv. Bernardina Sienského, kněze",
	"",
	"S. Bernardini Senensis, presb.",
	"",
	"Sv. Bernardina Sienského, kněze",
	"Sienai Szent Bernardin áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_20_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Bernardína Sienského, kňaza, člena 1. rádu",
	"Sv. Bernardina ze Sieny, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_20_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Kolumby z Rieti, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_21_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály sv. Petra a Pavla",
	"",
	"",
	"",
	"Výročí posvěcení katedrály sv. Petra a Pavla",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_21[POCET_JAZYKOV + 1] =
{
	"Sv. Krištofa Magallanesa, kňaza, a spoločníkov, mučeníkov",
	"Sv. Kryštofa Magallanese, kněze a druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Kryštofa Magallanese, kněze a druhů, mučedníků",
	"Magallán Szent Kristóf áldozópap és társai, mexikói vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_21_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Hyacinta Márie Cormiera, kňaza",
	"",
	"",
	"",
	"",
	"Bl. Hyacinta Marie Cormiera, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_22[POCET_JAZYKOV + 1] =
{
	"Sv. Rity z Kassie, rehoľníčky",
	"Sv. Rity z Cascie, řeholnice",
	"",
	"",
	"",
	"Sv. Rity z Cascie, řeholnice",
	"Szent Rita szerzetesnő",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_23_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Boldog Apor Vilmos püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_24_OP[POCET_JAZYKOV + 1] =
{
	"Prenesenie pozostatkov sv. otca Dominika",
	"",
	"",
	"",
	"",
	"Přenesení ostatků sv. Otce Dominika",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_24_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Heřmana Josefa, kněze z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_24_OFM[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky Baziliky sv. Františka v Assisi",
	"Posvěcení baziliky sv. Františka v Assisi",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_24[POCET_JAZYKOV + 1] = // ToDo rozdeliť pre všeobecný kalendár a pre SDB
{
	"Panny Márie, Pomocnice kresťanov, "HTML_LINE_BREAK"hlavnej patrónky Inštitútu dcér Márie Pomocnice "HTML_LINE_BREAK"a celej saleziánskej rodiny",
	"Panny Marie Pomocnice křesťanů, "HTML_LINE_BREAK"hlavní patronky Společnosti sv. Františka Saleského, "HTML_LINE_BREAK"Institutu Dcer Panny Marie "HTML_LINE_BREAK"a Sekulárního institutu Volontárií Dona Boska",
	"",
	"",
	"",
	"",
	"Szűz Mária, a keresztények segítsége",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_25_1[POCET_JAZYKOV + 1] =
{
	"Sv. Bédu Ctihodného, kňaza a učiteľa Cirkvi",
	"Sv. Bedy Ctihodného, kněze a učitele církve",
	"",
	"S. Bed&#230; Venerdbilis, presb. et Ecci. doct.",
	"",
	"Sv. Bedy Ctihodného, kněze a učitele Církve",
	"Tiszteletreméltó Szent Béda áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_25_2[POCET_JAZYKOV + 1] =
{
	"Sv. Gregora VII., pápeža",
	"Sv. Řehoře VII., papeže",
	"",
	"S. Gregorii VII, pap&#230;",
	"",
	"Sv. Řehoře VII., papeže",
	"Szent VII. Gergely pápa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_25_3[POCET_JAZYKOV + 1] =
{
	"Sv. Márie Magdalény de’ Pazzi, panny",
	"Sv. Marie Magdalény de’ Pazzi, panny",
	"",
	"S. Mari&#230; Magdalen&#230; de’ Pazzi, virg.",
	"",
	"Sv. Marie Magdalény de’ Pazzi, panny",
	"Pazzi Szent Mária Magdolna szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_26[POCET_JAZYKOV + 1] =
{
	"Sv. Filipa Neriho, kňaza",
	"Sv. Filipa Neriho, kněze",
	"",
	"S. Philippi Neri, presb.",
	"",
	"Sv. Filipa Neriho, kněze",
	"Néri Szent Fülöp áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_27[POCET_JAZYKOV + 1] =
{
	"Sv. Augustína z Canterbury, biskupa",
	"Sv. Augustina z Canterbury, biskupa",
	"",
	"S. Augustini Cantuariensis, ep.",
	"",
	"Sv. Augustina z Canterbury, biskupa",
	"Canterbury Szent Ágoston püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_27_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Andreja Franchiho, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_28_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Bartolomey Bagnesiovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_29_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Viliama Arnauda, kňaza, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_29_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Jozefa Kowalského, mučeníka",
	"Bl. Josefa Kowalského, kněze, mučedníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_30_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jakuba Salomoniho, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_30_CZ[POCET_JAZYKOV + 1] =
{
	"Sv. Zdislavy, matky rodiny", // SK OP
	"Sv. Zdislavy",
	"",
	"",
	"",
	"Sv. Zdislavy z Lemberka, matky rodiny, terciářky, "HTML_LINE_BREAK"spolupatronky provincie",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_30_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Szent István király ereklyéinek átvitele",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_MAJ_31[POCET_JAZYKOV + 1] =
{
	"Navštívenie prebl. Panny Márie",
	"Navštívení Panny Marie",
	"",
	"",
	"",
	"Navštívení Panny Marie",
	"Szűz Mária látogatása Erzsébetnél "HTML_LINE_BREAK"(Sarlós Boldogasszony)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 00 pohyblivé slávenia ---------------

const char *text_NANEBOVSTUPENIE_PANA[POCET_JAZYKOV + 1] =
{
	"Nanebovstúpenie Pána",
	"Nanebevstoupení Páně",
	"",
	"",
	"",
	"Nanebevstoupení Páně",
	"Urunk mennybemenetele",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_VELKONOCNA_NEDELA[POCET_JAZYKOV + 1] =
{
	"Veľkonočná nedeľa",
	"Neděle Zmrtvýchvstání Páně",
	"",
	"",
	"",
	"Neděle Zmrtvýchvstání Páně",
	"Húsvétvasárnap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[POCET_JAZYKOV + 1] = // 2012-12-13: XML nepodporuje &mdash; -- použitý číselný kód &#8212; http://en.wikipedia.org/wiki/List_of_XML_and_HTML_character_entity_references
{
	HTML_LINE_BREAK" &#8212; Nedeľa Pánovho zmŕtvychvstania",
	"",
	"",
	"",
	"",
	"",
	", Krisztus feltámadása",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1] =
{
	"Nedeľa vo Veľkonočnej oktáve",
	"Neděle v oktávu velikonočním",
	"",
	"",
	"",
	"Neděle v oktávu velikonočním",
	"Vasárnap Húsvét nyolcadában",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1] =
{
	"Veľkonočn%s %s",
	"%s velikonoční",
	"",
	"",
	"",
	"%s velikonoční",
	"%s Húsvét nyolcadában",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

const char *text_HU_VELKONOCNY_PONDELOK = "Húsvéthétfő"; // pre HU špeciálny názov veľkonočného pondelka

const char *text_HU_VELKY_TYZDEN_PREFIX = "Nagy"; // pre HU špeciálne názvy dní veľkného týždňa (pondelok až streda)

const char *text_NPJK_NAJ_KNAZA[POCET_JAZYKOV + 1] =
{
	"Nášho Pána Ježiša Krista,"HTML_NONBREAKING_SPACE"najvyššieho a večného kňaza",
	"Ježíše Krista, nejvyššího a věčného kněze",
	"",
	"",
	"",
	"Našeho Pána Ježíše Krista, nejvyššího a věčného kněze",
	"hu_XXX",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NAJSVATEJSEJ_TROJICE[POCET_JAZYKOV + 1] =
{
	"Najsvätejšej Trojice",
	"Nejsvětější Trojice",
	"",
	"",
	"",
	"Nejsvětější Trojice",
	"Szentháromságvasárnap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_KRISTA_KRALA[POCET_JAZYKOV + 1] =
{
	"Krista Kráľa",
	"Ježíše Krista Krále",
	"",
	"",
	"",
	"Ježíše Krista Krále",
	"Krisztus Király",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[POCET_JAZYKOV + 1] =
{
	"Najsvätejšieho Kristovho tela a krvi",
	"Těla a krve Páně",
	"",
	"",
	"",
	"Těla a krve Páně",
	"Krisztus Szent Teste és Vére",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NAJSV_SRDCA_JEZISOVHO[POCET_JAZYKOV + 1] =
{
	"Najsvätejšieho Srdca Ježišovho",
	"Nejsvětějšího Srdce Ježíšova",
	"",
	"",
	"",
	"Nejsvětějšího Srdce Ježíšova",
	"Jézus Szent Szíve",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NEPOSKVRNENEHO_SRDCA_PM[POCET_JAZYKOV + 1] =
{
	"Nepoškvrneného Srdca Panny Márie", // 2010-06-16: opravený názov podľa breviára i direktória
	"Neposkvrněného Srdce Panny Marie",
	"",
	"",
	"",
	"Neposkvrněného Srdce Panny Marie",
	"A Boldogságos Szűz Mária Szeplőtelen Szíve",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NEPOSKVRNENEHO_SRDCA_PM_OFM[POCET_JAZYKOV + 1] =
{
	"Nepoškvrneného Srdca Panny Márie, "HTML_LINE_BREAK"patrónky slovenskej provincie Rádu menších bratov kapucínov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NARODENIE_PANA[POCET_JAZYKOV + 1] =
{
	"Narodenie Pána",
	"Narození Páně",
	"",
	"",
	"",
	"Narození Páně",
	"Urunk születése (Karácsony)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_ZOSLANIE_DUCHA_SVATEHO[POCET_JAZYKOV + 1] =
{
	"Zoslanie Ducha Svätého",
	"Seslání Ducha svatého",
	"",
	"",
	"",
	"Seslání Ducha Svatého",
	"Pünkösd",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_PRVA_ADVENTNA_NEDELA[POCET_JAZYKOV + 1] =
{
	"Prvá adventná nedeľa",
	"První neděle adventní",
	"",
	"",
	"",
	"První neděle adventní",
	"Advent első vasárnapja",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NEDELA_SV_RODINY[POCET_JAZYKOV + 1] =
{
	"Svätej rodiny Ježiša, Márie a Jozefa",
	"Sv. Rodiny Ježíše, Marie a Josefa",
	"",
	"",
	"",
	"Sv. Rodiny Ježíše, Marie a Josefa",
	"A Szent Család: Jézus, Mária és József", // "Szent Család ünnepe"
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SPOMIENKA_PM_V_SOBOTU[POCET_JAZYKOV + 1] =
{
	"Spomienka Panny Márie v sobotu",
	"Sobotní památka Panny Marie",
	"",
	"Memoria S. Mari&#230; in sabbato",
	"",
	"Sobotní památka Panny Marie",
	"Szűz Mária szombati emléknapja",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 06 jún | june ---------------

const char *text_JUN_01[POCET_JAZYKOV + 1] =
{
	"Sv. Justína, mučeníka",
	"Sv. Justina, mučedníka",
	"",
	"",
	"",
	"Sv. Justina, mučedníka",
	"Szent Jusztínusz vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_02[POCET_JAZYKOV + 1] =
{
	"Sv. Marcelína a Petra, mučeníkov",
	"Sv. Marcelina a Petra, mučedníků",
	"",
	"",
	"",
	"Sv. Marcelina a Petra, mučedníků",
	"Szent Marcellínusz és Szent Péter vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_02_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Felixa z Nikózie, rehoľníka, člena 1. rádu",
	"Sv. Felixe z Nicosie, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_02_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Sadoka, kňaza, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_03[POCET_JAZYKOV + 1] =
{
	"Sv. Karola Lwangu a spoločníkov, mučeníkov",
	"Sv. Karla Lwangy a druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Karla Lwangy a druhů, mučedníků",
	"Lwanga Szent Károly és társai, vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_04_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Veronského, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"Sv. Petra Veronského, kněze a mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_04_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Szent Quirinus (Kerény) püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_05[POCET_JAZYKOV + 1] =
{
	"Sv. Bonifáca, biskupa a mučeníka",
	"Sv. Bonifáce, biskupa a mučedníka",
	"",
	"",
	"",
	"Sv. Bonifáce, biskupa a mučedníka",
	"Szent Bonifác püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_06[POCET_JAZYKOV + 1] =
{
	"Sv. Norberta, biskupa",
	"Sv. Norberta, biskupa",
	"",
	"",
	"",
	"Sv. Norberta, biskupa",
	"Szent Norbert püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_06_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Našeho otce sv. Norberta, biskupa "HTML_LINE_BREAK"a zakladatele premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_08_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Prágai Szent Ágnes szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_08_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Mikuláša z Gesturi, rehoľníka, člena 1. rádu",
	"Bl. Mikuláše z Gesturi, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_08_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Istvána Sándora, mučeníka",
	"Bl. Istvána Sándora, mučedníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_08_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Diany a Cecílie, panien",
	"",
	"",
	"",
	"",
	"Bl. Diany Andalo a Cecílie, panen, mnišek",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_09[POCET_JAZYKOV + 1] =
{
	"Sv. Efréma, diakona a učiteľa Cirkvi",
	"Sv. Efréma Syrského, jáhna a učitele církve",
	"",
	"",
	"",
	"Sv. Efréma Syrského, jáhna a učitele Církve",
	"Szent Efrém diakónus és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_09_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Jozefa de Anchieta, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_10_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jána Dominiciho, biskupa",
	"",
	"",
	"",
	"",
	"Bl. Jana Dominiciho, biskupa",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_11[POCET_JAZYKOV + 1] =
{
	"Sv. Barnabáša, apoštola",
	"Sv. Barnabáše, apoštola",
	"",
	"",
	"",
	"Sv. Barnabáše, apoštola",
	"Szent Barnabás apostol",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_12_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Marie Antoníny Kratochvílové, panny, a druhů mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_12_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Františka K&#281;syho a spoločníkov, mučeníkov", // Bl. Františka Kesyho a spoločníkov, mučeníkov (small latin letter e with ogonek)
	"Bl. Františka K&#281;syho a druhů, mučedníků ",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_12_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Štefana Bandelliho, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_12_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Jolandy Uhorskej, rehoľníčky, členky 2. rádu",
	"Bl. Jolanty Uherské, řeholnice",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_12_2_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Floridy Cevoliovej, panny, členky 2. rádu",
	"Bl. Floridy Cevoli, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_12_3_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Antona Bajewského a spoločníkov, mučeníkov: "HTML_LINE_BREAK"Pia Bartošika, Inocenta Guza, Achilla Puchalu, Hermana St&#281;npie&nacute;a, kňazov; "HTML_LINE_BREAK"Timoteja Trojanowského, Bonifáca &#379;ukowského, rehoľníkov, členov 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_13_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Antona Paduánskeho, kňaza a učiteľa Cirkvi, člena 1. rádu",
	"Sv. Antonína z Padovy, kněze a učitele církve",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_13[POCET_JAZYKOV + 1] =
{
	"Sv. Antona Paduánskeho, kňaza a učiteľa Cirkvi",
	"Sv. Antonína z Padovy, kněze a učitele církve",
	"",
	"",
	"",
	"Sv. Antonína z Padovy, kněze a učitele Církve",
	"Páduai Szent Antal áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_14_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"A Szombathelyi székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_15_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Víta, mučedníka",
	"",
	"",
	"",
	"Sv. Víta, mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_15_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Árpád-házi Boldog Jolán szerzetesnő",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_16_SK[POCET_JAZYKOV + 1] =
{
	"Sv. Neita, mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_16_1_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Terézie Schererovej, panny, rehoľníčky, členky 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_16_2_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Aniceta Koplina, kňaza, a spoločníkov, mučeníkov, členov 1. rádu",
	"Bl. Aniceta Koplińského a druhů, mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_16_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Isfrída, biskupa z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_16_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Tours-i Szent Márton püspök ereklyéinek átvitele",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_17_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Alberta Chmielowského, rehoľníka, člena 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_18_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Hosanny z Mantovy, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_19[POCET_JAZYKOV + 1] =
{
	"Sv. Romualda, opáta",
	"Sv. Romualda, opata",
	"",
	"",
	"",
	"Sv. Romualda, opata",
	"Szent Romuald apát",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_19_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Jana Nepomuckého Neumanna, biskupa",
	"",
	"",
	"",
	"Sv. Jana Nepomuckého Neumanna, biskupa",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_21[POCET_JAZYKOV + 1] =
{
	"Sv. Alojza Gonzágu, rehoľníka",
	"Sv. Aloise Gonzagy, řeholníka",
	"",
	"",
	"",
	"Sv. Aloise Gonzagy, řeholníka",
	"Gonzága Szent Alajos szerzetes",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_21_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Alojza Gonzagu, rehoľníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_22_2[POCET_JAZYKOV + 1] =
{
	"Sv. Pavlína z Noly, biskupa",
	"Sv. Paulina Nolánského, biskupa",
	"",
	"",
	"",
	"Sv. Paulina Nolánského, biskupa",
	"Nolai Szent Paulínusz püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_22_1[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Fishera, biskupa, "HTML_LINE_BREAK"a sv. Tomáša Morusa, mučeníkov", // kedysi: Mórusa; Direktórium 2012, str. 156, uvádza už iba s krátkym "o"
	"Sv. Jana Fishera, biskupa, "HTML_LINE_BREAK"a Tomáše Mora, mučedníků",
	"",
	"",
	"",
	"Sv. Jana Fishera, biskupa, "HTML_LINE_BREAK"a Tomáše Mora, mučedníků",
	"Fisher Szent János püspök "HTML_LINE_BREAK"és Morus Szent Tamás vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_22_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"A Pécsi székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_23_SDB[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa Cafassa, kňaza",
	"Sv. Josefa Cafassa, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_23_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Inocenta V., pápeža",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_24[POCET_JAZYKOV + 1] =
{
	"Narodenie sv. Jána Krstiteľa",
	"Narození svatého Jana Křtitele",
	"",
	"",
	"",
	"Narození svatého Jana Křtitele",
	"Keresztelő Szent János születése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_26_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Andreja Hyacinta Longina, biskupa, člena 1. rádu",
	"Bl. Ondřeje Hyacinta Longhina, biskupa",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_27[POCET_JAZYKOV + 1] =
{
	"Sv. Cyrila Alexandrijského, biskupa a učiteľa Cirkvi",
	"Sv. Cyrila Alexandrijského, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Cyrila Alexandrijského, biskupa a učitele církve",
	"Alexandriai Szent Cirill püspök és egyháztanító", // HU: 26JUN
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_27_SK_HU[POCET_JAZYKOV + 1] =
{
	"Sv. Ladislava",
	"",
	"",
	"",
	"",
	"",
	"Szent László király",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_27_CSSR[POCET_JAZYKOV + 1] =
{
	"Panny Márie, Matky ustavičnej pomoci",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_28[POCET_JAZYKOV + 1] =
{
	"Sv. Ireneja, biskupa a mučeníka",
	"Sv. Ireneje, biskupa a mučedníka",
	"",
	"",
	"",
	"Sv. Ireneje, biskupa a mučedníka",
	"Szent Iréneusz püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_29[POCET_JAZYKOV + 1] =
{
	"Sv. Petra a Pavla, apoštolov",
	"Sv. Petra a Pavla, apoštolů",
	"",
	"",
	"",
	"Sv. Petra a Pavla, apoštolů",
	"Szent Péter és Szent Pál apostolok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_29_OPRAEM[POCET_JAZYKOV + 1] =
{
	"Sv. Petra a Pavla, apoštolov",
	"Sv. Petra a Pavla, apoštolů, titulární slavnost opatského kostela",
	"",
	"",
	"",
	"Sv. Petra a Pavla, apoštolů",
	"Szent Péter és Szent Pál apostolok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_30[POCET_JAZYKOV + 1] =
{
	"Prvých svätých mučeníkov Cirkvi v Ríme",
	"Svatých prvomučedníků římských",
	"",
	"",
	"",
	"Svatých prvomučedníků římských",
	"A római Egyház első szent vértanúi",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_30_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály sv. Václava",
	"",
	"",
	"",
	"Výročí posvěcení katedrály sv. Václava",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUN_30_CSSR[POCET_JAZYKOV + 1] =
{
	"Bl. Januára Márie Sarnelliho, kňaza",
	"Bl. Geranno Marie Sarnelliho, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 07 júl |july ---------------

const char *text_JUL_02_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Bernardína Realina, sv. Jána Františka Régisa, sv. Františka de Geronimo, "HTML_LINE_BREAK"bl. Juliána Maunoira, bl. Antona Baldinucciho, kňazov", // text_JUL_01_SJ: na Slovensku sa slávi 1. júla
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_03[POCET_JAZYKOV + 1] =
{
	"Sv. Tomáša, apoštola",
	"Sv. Tomáše, apoštola",
	"",
	"",
	"",
	"Sv. Tomáše, apoštola",
	"Szent Tamás apostol",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_04[POCET_JAZYKOV + 1] =
{
	"Sv. Alžbety Portugalskej",
	"Sv. Alžběty Portugalské",
	"",
	"",
	"",
	"Sv. Alžběty Portugalské",
	"Portugáliai Szent Erzsébet",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_04_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Prokopa, opata",
	"",
	"",
	"",
	"Sv. Prokopa, opata",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_04_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Kataríny Jarrigeovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_04_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Petra Juraja Frassatiho, laika",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_05[POCET_JAZYKOV + 1] =
{
	"Sv. Cyrila a Metoda, slovanských vierozvestov",
	"Sv. Cyrila, mnicha, a Metoděje, biskupa, "HTML_LINE_BREAK"patronů Evropy, hlavních patronů Moravy",
	"",
	"",
	"",
	"Sv. Cyrila, mnicha, a Metoděje, biskupa, "HTML_LINE_BREAK"patronů Evropy, hlavních patronů Moravy",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_06[POCET_JAZYKOV + 1] =
{
	"Sv. Márie Goretti, panny a mučenice",
	"Sv. Marie Gorettiové, panny a mučednice",
	"",
	"",
	"",
	"Sv. Marie Gorettiové, panny a mučednice",
	"Goretti Szent Mária szűz és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_06_CZOP[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"Blaholaveného Pier Giorgio Frassatiho, laika OP",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_07_SK[POCET_JAZYKOV + 1] = // vo všeobecnom kalendári sa slávi 5. júla
{
	"Sv. Antona Márie Zaccariu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"Zaccaria Szent Antal Mária áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_07_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Romerovej Meneses, panny",
	"Bl. Marie Romero Meneses, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_07_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Benedikta XI., pápeža",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_08_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Hadriána Fortescuea, otca rodiny a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_08_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"A székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_09[POCET_JAZYKOV + 1] =
{
	"Sv. Augustína Zhao Rong, kňaza, "HTML_LINE_BREAK"a spoločníkov, mučeníkov",
	"Sv. Augustina Žao Ronga, kněze "HTML_LINE_BREAK"a jeho druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Augustina Žao Ronga, kněze "HTML_LINE_BREAK"a jeho druhů, mučedníků",
	"Szent Zhao Rong Ágoston áldozópap és társai, kínai vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_09_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Kolínskeho, kňaza, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"Sv. Jana Kolínského, kněze, a druhů, mučedníků",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_09_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Mikuláša Picka, Antona von Willehada a spoločníkov, "HTML_LINE_BREAK"mučeníkov v Holandsku, členov 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_09_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Adriána a Jakuba, kněží premonstrátského řádu, "HTML_LINE_BREAK"a jejich druhů, mučedníků Gorkumských",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_10_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Veroniky Giulianiovej, panny, členky 2. rádu",
	"Sv. Veroniky Giuliani, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_11[POCET_JAZYKOV + 1] =
{
	"Sv. Benedikta, opáta, "HTML_LINE_BREAK"patróna Európy",
	"Sv. Benedikta, opata, "HTML_LINE_BREAK"patrona Evropy",
	"",
	"",
	"",
	"Sv. Benedikta, opata, "HTML_LINE_BREAK"patrona Evropy",
	"Szent Benedek apát, "HTML_LINE_BREAK"Európa fővédőszentje",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_13[POCET_JAZYKOV + 1] =
{
	"Sv. Henricha",
	"Sv. Jindřicha",
	"",
	"",
	"",
	"Sv. Jindřicha",
	"Szent Henrik",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_13_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jakuba z Varazze, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_14[POCET_JAZYKOV + 1] =
{
	"Sv. Kamila de Lellis, kňaza",
	"Sv. Kamila de Lellis, kněze",
	"",
	"",
	"",
	"Sv. Kamila de Lellis, kněze",
	"Lellisi Szent Kamill áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_14_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Solanského, kňaza, člena 1. rádu",
	"Sv. Františka Solana, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_14_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Hroznaty, mučedníka",
	"",
	"",
	"",
	"Bl. Hroznaty, mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_14_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Hroznaty, mučedníka z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_15[POCET_JAZYKOV + 1] =
{
	"Sv. Bonaventúru, biskupa a učiteľa Cirkvi",
	"Sv. Bonaventury, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Bonaventury, biskupa a učitele Církve",
	"Szent Bonaventura püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_15_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Bonaventúru z Bagnoregia, biskupa a učiteľa Cirkvi, člena 1. rádu",
	"Sv. Bonaventury z Bagnoregia, biskupa a učitele církve",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_16[POCET_JAZYKOV + 1] =
{
	"Prebl. Panny Márie Karmelskej",
	"Panny Marie Karmelské",
	"",
	"",
	"",
	"Panny Marie Karmelské",
	"Kármel-hegyi Boldogasszony",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_16_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály Božského Spasitele",
	"",
	"",
	"",
	"Výročí posvěcení katedrály Božského Spasitele",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_17_SK[POCET_JAZYKOV + 1] =
{
	"Sv. Andreja-Svorada a Benedikta, pustovníkov",
	"",
	"",
	"",
	"",
	"",
	"Szent Zoerárd-András és Benedek remeték",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_17_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Česlava a sv. Hyacinta, kněží",
	"",
	"",
	"",
	"Bl. Česlava a sv. Hyacinta, kněží",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_17_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Česlava Poľského, kňaza",
	"",
	"",
	"",
	"",
	"Bl. Česlava z Polska, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_18_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Szent Hedvig királyné",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_18_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Bartolomeja od Mučeníkov, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_18_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Šimona z Lipnice, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_19_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Jána z Dukly, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_20[POCET_JAZYKOV + 1] =
{
	"Sv. Apolinára, biskupa a mučeníka",
	"Sv. Apolináře, biskupa a mučedníka",
	"",
	"",
	"",
	"Sv. Apolináře, biskupa a mučedníka",
	"Szent Apollinaris püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_21[POCET_JAZYKOV + 1] =
{
	"Sv. Vavrinca z Brindisi, kňaza a učiteľa Cirkvi",
	"Sv. Vavřince z Brindisi, kněze a učitele církve",
	"",
	"",
	"",
	"Sv. Vavřince z Brindisi, kněze a učitele Církve",
	"Brindisi Szent Lőrinc áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_21_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Vavrinca z Brindisi, kňaza a učiteľa Cirkvi, člena 1. rádu",
	"Sv. Vavřince z Brindisi, kněze a učitele církve",
	"",
	"",
	"",
	"Sv. Vavřince z Brindisi, kněze a učitele Církve, člena 1. řádu",
	"Brindisi Szent Lőrinc áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_22[POCET_JAZYKOV + 1] =
{
	"Sv. Márie Magdalény",
	"Sv. Marie Magdalény",
	"",
	"",
	"",
	"Sv. Marie Magdalény",
	"Szent Mária Magdolna",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_23[POCET_JAZYKOV + 1] =
{
	"Sv. Brigity, rehoľníčky, "HTML_LINE_BREAK"patrónky Európy",
	"Sv. Brigity, řeholnice, "HTML_LINE_BREAK"patronky Evropy",
	"",
	"",
	"",
	"Sv. Brigity, řeholnice, "HTML_LINE_BREAK"patronky Evropy",
	"Szent Brigitta szerzetesnő",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_24[POCET_JAZYKOV + 1] =
{
	"Sv. Sarbela Makhlufa, kňaza", // 2009-07-15: direktórium (2012, str. 171) má "Sarbel", predtým bolo "Charbel" a zrejme sa číta "Šarbel"
	"Sv. Šarbela Makhlúfa, kněze",
	"",
	"",
	"",
	"Sv. Šarbela Makhlúfa, kněze",
	"Szent Charbel Makhlouf áldozópap", // HU: 27JUL
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_24_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Árpád-házi Szent Kinga szűz", // 2011-07-05: sv. Sarbela v HU: 27JUL
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_24_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Antona Lucciho, biskupa, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_24_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jany z Orvieta, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_24_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Augustína z Biella, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_25[POCET_JAZYKOV + 1] =
{
	"Sv. Jakuba, apoštola",
	"Sv. Jakuba, apoštola",
	"",
	"",
	"",
	"Sv. Jakuba, apoštola",
	"Szent Jakab apostol",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_26[POCET_JAZYKOV + 1] =
{
	"Sv. Joachima a Anny, rodičov Panny Márie",
	"Sv. Jáchyma a Anny, rodičů Panny Marie",
	"",
	"",
	"",
	"Sv. Jáchyma a Anny, rodičů Panny Marie",
	"Szent Joakim és Szent Anna, a Boldogságos Szűz Mária szülei",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_27[POCET_JAZYKOV + 1] =
{
	"Sv. Gorazda a spoločníkov",
	"Sv. Gorazda a druhů",
	"",
	"",
	"",
	"Sv. Gorazda a druhů",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_27_OP[POCET_JAZYKOV + 1] = // SK OP: 28JUL
{
	"Bl. Róberta Nuttera, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_27_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Magdalény Martinengovej, panny, členky 2. rádu",
	"Bl. Marie Magdalény Martinengo, panny", // CZ OFMCap: 28JUL
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_28_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Terézie Kowalskej, panny a mučenice, členky 2. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_29[POCET_JAZYKOV + 1] =
{
	"Sv. Marty",
	"Sv. Marty",
	"",
	"",
	"",
	"Sv. Marty",
	"Szent Márta",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_30[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Chryzológa, biskupa a učiteľa Cirkvi",
	"Sv. Petra Chryzologa, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Petra Chryzologa, biskupa a učitele církve",
	"Aranyszavú (Krizologosz) Szent Péter püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_30_SK[POCET_JAZYKOV + 1] =
{
	"Bl. Zdenky, panny a mučenice", // Direktórium 2012, str. 173, neuvádza priezvisko ('Schelingovej')
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_30_SK_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Zdenky Schelingovej, panny a mučenice, "HTML_LINE_BREAK"rehoľníčky, členky 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_31[POCET_JAZYKOV + 1] =
{
	"Sv. Ignáca z Loyoly, kňaza",
	"Sv. Ignáce z Loyoly, kněze",
	"",
	"",
	"",
	"Sv. Ignáce z Loyoly, kněze",
	"Loyolai Szent Ignác áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_JUL_31_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Ignáca Loyolského, kňaza a zakladateľa Spoločnosti Ježišovej",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 00 pohyblivé slávenia ---------------

const char *text_CSSR_TITUL_KONGREGACIE[POCET_JAZYKOV + 1] =
{
	"Najsvätejšieho Vykupiteľa, titul Kongregácie", // 3. nedeľa v júli
	"Nejsvětějšího Vykupitele, titul kongregace", // v každém roce 3. neděle v červenci
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 08 august ---------------

const char *text_AUG_01[POCET_JAZYKOV + 1] =
{
	"Sv. Alfonza Márie de’ Liguori, biskupa a učiteľa Cirkvi",
	"Sv. Alfonsa z Liguori, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Alfonsa z Liguori, biskupa a učitele Církve",
	"Liguori Szent Alfonz Mária püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_01_CSSR[POCET_JAZYKOV + 1] =
{
	"Sv. Alfonza Márie de’ Liguori, biskupa a učiteľa Cirkvi, zakladateľa kongregácie",
	"Sv. Alfonsa z Liguori, biskupa a učitele církve, zakladatele kongregace",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_02_1[POCET_JAZYKOV + 1] =
{
	"Sv. Euzébia Vercellského, biskupa",
	"Sv. Eusebia z Vercelli, biskupa",
	"",
	"",
	"",
	"Sv. Eusebia z Vercelli, biskupa",
	"Vercelli Szent Özséb püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_02_2[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Juliána Eymarda, kňaza",
	"Sv. Petra Juliána Eymarda, kněze",
	"",
	"",
	"",
	"Sv. Petra Juliána Eymarda, kněze",
	"Szent Eymard Julián Péter áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_02_OFM[POCET_JAZYKOV + 1] =
{
	"Preblahoslavenej Panny Márie Anjelskej v Porciunkule",
	"Panny Marie Královny andělů",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_02_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jany z Azy, matky sv. otca Dominika",
	"",
	"",
	"",
	"",
	"Bl. Jany, matky sv. Otce Dominika",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_03_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Augustína Kazotića, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_02_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Augustína Czartoryského, kňaza",
	"Bl. Augustina Czartoryského, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_02_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Petra Favra, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_04[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Márie Vianneyho, kňaza", // 'Vianneyho' podľa Direktória 2012, str. 176
	"Sv. Jana Marie Vianneye, kněze",
	"",
	"",
	"",
	"Sv. Jana Marie Vianneye, kněze",
	"Vianney Szent János Mária áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_05[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky Hlavnej mariánskej baziliky v Ríme",
	"Posvěcení římské baziliky Panny Marie",
	"",
	"",
	"",
	"Posvěcení římské baziliky Panny Marie",
	"Szűz Mária római főtemplomának felszentelése (Havas Boldogasszony)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_06[POCET_JAZYKOV + 1] =
{
	"Premenenie Pána",
	"Proměnění Páně",
	"",
	"",
	"",
	"Proměnění Páně",
	"Urunk színeváltozása",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_07_1[POCET_JAZYKOV + 1] =
{
	"Sv. Sixta II., pápeža, a jeho spoločníkov, mučeníkov",
	"Sv. Sixta II., papeže, a druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Sixta II., papeže, a druhů, mučedníků",
	"Szent II. Szixtusz pápa és társai vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_07_2[POCET_JAZYKOV + 1] =
{
	"Sv. Kajetána, kňaza",
	"Sv. Kajetána, kněze",
	"",
	"",
	"",
	"Sv. Kajetána, kněze",
	"Szent Kajetán áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_07_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Agatangela a Kasiána, kňazov a mučeníkov, "HTML_LINE_BREAK"členov 1. rádu",
	"Bl. Agathangela a Kassiána, kněží a mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_08[POCET_JAZYKOV + 1] =
{
	"Sv. Dominika, kňaza",
	"Sv. Dominika, kněze",
	"",
	"",
	"",
	"Sv. Otce Dominika, kněze",
	"Szent Domonkos áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_08_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Dominika, kňaza, zakladateľa rehole",
	"Sv. Dominika, kněze",
	"",
	"",
	"",
	"Sv. Otce Dominika, kněze",
	"Szent Domonkos áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_08_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Dominika, kňaza, "HTML_LINE_BREAK"zakladateľa Rádu dominikánov",
	"Sv. Dominika, kněze",
	"",
	"",
	"",
	"Sv. Otce Dominika, kněze",
	"Szent Domonkos áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_09[POCET_JAZYKOV + 1] =
{
	"Sv. Terézie Benedikty z Kríža "HTML_LINE_BREAK"(Edity Steinovej), panny a mučenice, "HTML_LINE_BREAK"patrónky Európy", // podľa Direktória 2012, str. 178
	"Sv. Terezie Benedikty, panny a mučednice, "HTML_LINE_BREAK"patronky Evropy",
	"",
	"",
	"",
	"Sv. Terezie Benedikty, panny a mučednice, "HTML_LINE_BREAK"patronky Evropy",
	"A keresztről nevezett Szent Teréz Benedikta (Edith Stein) "HTML_LINE_BREAK"szűz és vértanú, Európa társvédőszentje",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_10[POCET_JAZYKOV + 1] =
{
	"Sv. Vavrinca, diakona a mučeníka",
	"Sv. Vavřince, mučedníka",
	"",
	"",
	"",
	"Sv. Vavřince, mučedníka",
	"Szent Lőrinc diakónus és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_11[POCET_JAZYKOV + 1] =
{
	"Sv. Kláry, panny",
	"Sv. Kláry, panny",
	"",
	"",
	"",
	"Sv. Kláry, panny",
	"Szent Klára szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_11_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Kláry z Assisi, panny, členky 2. rádu",
	"Sv. Kláry z Assisi, panny",
	"",
	"",
	"",
	"Sv. Kláry, panny",
	"Szent Klára szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_12[POCET_JAZYKOV + 1] =
{
	"Sv. Jany Františky de Chantal, rehoľníčky", // kedysi sa slávil 12. decembra
	"Sv. Jany Františky de Chantal, řeholnice",
	"",
	"",
	"",
	"Sv. Jany Františky de Chantal, řeholnice",
	"Chantal Szent Johanna Franciska szerzetesnő",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_12_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jána zo Salerna, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_12_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Aimona Taparelliho, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_12_3_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jána Juraja Rehma, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_13[POCET_JAZYKOV + 1] =
{
	"Sv. Ponciána, pápeža, a sv. Hypolita, kňaza, mučeníkov",
	"Sv. Ponciána, papeže, a Hippolyta, kněze, mučedníků",
	"",
	"",
	"",
	"Sv. Ponciána, papeže, a Hippolyta, kněze, mučedníků",
	"Szent Ponciánusz pápa és Szent Hippolitusz áldozópap és vértanúk", // HU: 16AUG
};
const char *text_AUG_13_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Boldog XI. Ince pápa", // HU
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_13_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Gertrudy, panny z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_13_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Marka z Aviana, kňaza, člena 1. rádu",
	"Bl. Marka z Aviana, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_14[POCET_JAZYKOV + 1] =
{
	"Sv. Maximiliána Márie Kolbeho, kňaza a mučeníka", // podľa Direktória 2012, str. 180
	"Sv. Maxmiliána Marie Kolbeho, kněze a mučedníka",
	"",
	"",
	"",
	"Sv. Maxmiliána Marie Kolbeho, kněze a mučedníka",
	"Szent Maximilián Mária Kolbe áldozópap és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_14_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Maximiliána Márie Kolbeho, "HTML_LINE_BREAK"kňaza a mučeníka, člena 1. rádu",
	"Sv. Maxmiliána Marie Kolbeho, kněze a mučedníka",
	"",
	"",
	"",
	"Sv. Maxmiliána Marie Kolbeho, kněze a mučedníka",
	"Szent Maximilián Mária Kolbe áldozópap és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_15[POCET_JAZYKOV + 1] =
{
	"Nanebovzatie prebl. Panny Márie",
	"Nanebevzetí Panny Marie",
	"",
	"",
	"",
	"Nanebevzetí Panny Marie",
	"Szűz Mária mennybevétele (Nagyboldogasszony)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_16[POCET_JAZYKOV + 1] =
{
	"Sv. Štefana Uhorského",
	"Sv. Štěpána Uherského",
	"",
	"",
	"",
	"Sv. Štěpána Uherského",
	"Szent István király, Magyarország fővédőszentje",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_16_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Rocha",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_17_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Hyacinta Poľského, kňaza",
	"",
	"",
	"",
	"",
	"Sv. Hyacinta z Polska, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_17_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Beatrix de Silva, panny, zakladateľky "HTML_LINE_BREAK"koncepcionistiek, členky 2. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_17_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Kaposvár: A székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_18_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Vác: A székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_18_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Alberta Hurtada Cruchagu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_18_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Manesa, kňaza, brata sv. otca Dominika",
	"",
	"",
	"",
	"",
	"Bl. Mannesa neboli Mamesa, kněze, bratra sv. Otce Dominika",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_18_1_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Alojza Adama a Mikuláša Savoureta, "HTML_LINE_BREAK"kňazov a mučeníkov, členov 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_18_2_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Jána, Protáza a Sebastiána, kňazov, "HTML_LINE_BREAK"členov 1. rádu, a spoločníkov, mučeníkov",
	"Bl. Jana Ludvíka, Protasia a Sebastiana, kněží a mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_19[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Eudes, kňaza",
	"Sv. Jana Eudese, kněze",
	"",
	"",
	"",
	"Sv. Jana Eudese, kněze",
	"Eudes Szent János áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_19_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jordána z Pisy, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_19_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Ľudovíta, biskupa, člena 1. rádu",
	"Sv. Ludvíka z Anjou, biskupa",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_20[POCET_JAZYKOV + 1] =
{
	"Sv. Bernarda, opáta a učiteľa Cirkvi",
	"Sv. Bernarda, opata a učitele církve",
	"",
	"",
	"",
	"Sv. Bernarda, opata a učitele Církve",
	"Szent Bernát apát és egyháztanító", // HU 19AUG
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_21[POCET_JAZYKOV + 1] =
{
	"Sv. Pia X., pápeža",
	"Sv. Pia X., papeže",
	"",
	"",
	"",
	"Sv. Pia X., papeže",
	"Szent X. Piusz pápa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OPATSKY_KOSTOL_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení opatského kostela",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_22[POCET_JAZYKOV + 1] =
{
	"Panny Márie Kráľovnej", // podľa Direktória 2012, str. 183, tam nie je 'Prebl.'
	"Panny Marie Královny",
	"",
	"",
	"",
	"Panny Marie Královny",
	"Boldogságos Szűz Mária Királynő",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_23[POCET_JAZYKOV + 1] =
{
	"Sv. Ruženy Limskej, panny",
	"Sv. Růženy z Limy, panny",
	"",
	"",
	"",
	"Sv. Růženy Floresové neboli z Limy, panny, terciářky",
	"Limai Szent Róza szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_23_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Bernarda z Offidy, rehoľníka, člena 1. rádu",
	"Bl. Bernarda z Offidy, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_24[POCET_JAZYKOV + 1] =
{
	"Sv. Bartolomeja, apoštola",
	"Sv. Bartoloměje, apoštola",
	"",
	"",
	"",
	"Sv. Bartoloměje, apoštola",
	"Szent Bertalan apostol",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_25_1[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa de Calasanz, kňaza",
	"Sv. Josefa Kalasanského, kněze",
	"",
	"",
	"",
	"Sv. Josefa Kalasanského, kněze",
	"Kalazanci Szent József áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_25_2[POCET_JAZYKOV + 1] =
{
	"Sv. Ľudovíta",
	"Sv. Ludvíka",
	"",
	"",
	"",
	"Sv. Ludvíka",
	"Szent Lajos",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_25_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Ľudovíta IX., kráľa, člena 3. rádu",
	"Sv. Ludvíka IX., krále, patrona 3. řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_25_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Benedikta, Jana, Matouše, Izáka a Kristina, mučedníků",
	"",
	"",
	"",
	"Sv. Benedikta, Jana, Matouše, Izáka a Kristina, mučedníků",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_25_2_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Metoděje Dominika Trčky, mučedníka",
	"",
	"",
	"",
	"Bl. Metoděje Dominika Trčky, mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_25_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Kalocsa-Kecskemét: A főszékesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_25_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Troncatti, panny",
	"Bl. Marie Troncatti, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_26_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Zefirína Namuncurá, mladíka",
	"Bl. Zefyrina Namuncurá, chlapce",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_26_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jakuba z Bevagna, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_27[POCET_JAZYKOV + 1] =
{
	"Sv. Moniky",
	"Sv. Moniky",
	"",
	"",
	"",
	"Sv. Moniky",
	"Szent Mónika",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_27_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Moniky, matky našeho otce sv. Augustina",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_28_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Našeho otce sv. Augustina, biskupa a učitele církve",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_28[POCET_JAZYKOV + 1] =
{
	"Sv. Augustína, biskupa a učiteľa Cirkvi",
	"Sv. Augustina, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Augustina, biskupa a učitele Církve",
	"Szent Ágoston püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_29[POCET_JAZYKOV + 1] =
{
	"Mučenícka smrť sv. Jána Krstiteľa",
	"Umučení svatého Jana Křtitele",
	"",
	"",
	"",
	"Umučení svatého Jana Křtitele",
	"Keresztelő Szent János vértanúsága",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_30_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Trnave", // ToDo: 'sv. Jána Krstiteľa', podľa Direktória 2012, str. 186
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_31_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Esztergom-Budapest: A prímási bazilika-"HTML_LINE_BREAK"főszékesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_AUG_30_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Bronislavy, panny z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 09 september ---------------

const char *text_SEP_02_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Gualu z Bergama, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_02_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Ingridy zo Skänninge, rehoľníčky",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_02_1_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Jána Františka Burtého, kňaza a mučeníka, "HTML_LINE_BREAK"člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_02_2_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Apolinára z Posatu, kňaza, člena 1. rádu, "HTML_LINE_BREAK"a spoločníkov, mučeníkov",
	"Bl. Apolináře z Posaty a druhů, mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_03[POCET_JAZYKOV + 1] =
{
	"Sv. Gregora Veľkého, pápeža a učiteľa Cirkvi",
	"Sv. Řehoře Velikého, papeže a učitele církve",
	"",
	"",
	"",
	"Sv. Řehoře Velikého, papeže a učitele Církve",
	"Nagy Szent Gergely pápa és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_04_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Kataríny z Racconigi, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_04_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Ruženy z Viterba, panny, členky 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_05[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Kalkuttai Boldog Teréz szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_06_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Košiciach", // ToDo: 'sv. Alžbety', podľa Direktória 2012, str. 190
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_06_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Bertranda z Garrigue, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_06_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Michala (Jána Františka) Czartoryského, kňaza, "HTML_LINE_BREAK"a bl. Júlie (Stanislavy) Rodzińskej, panny a rehoľníčky, "HTML_LINE_BREAK"mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_07[POCET_JAZYKOV + 1] =
{
	"Sv. Marka Križina, Melichara Grodzieckého "HTML_LINE_BREAK"a Štefana Pongrácza, kňazov a mučeníkov",
	"Sv. Melichara Grodeckého, kněze a mučedníka",
	"",
	"",
	"",
	"Sv. Melichara Grodeckého, kněze a mučedníka",
	"Szent Márk, István és Menyhért áldozópapok, kassai vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_07_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. košických mučeníkov: Štefana Pongrácza a Melichara Grodzieckého, kňazov Spoločnosti Ježišovej; "HTML_LINE_BREAK"Marka Križina, ostrihomského kanonika, patrónov Slovenskej provincie Spoločnosti Ježišovej",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_08[POCET_JAZYKOV + 1] =
{
	"Narodenie Panny Márie", // podľa Direktória 2012, str. 191, tam nie je 'prebl.'
	"Narození Panny Marie",
	"",
	"",
	"",
	"Narození Panny Marie",
	"Szűz Mária születése (Kisboldogasszony)",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_09[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Clavera, kňaza",
	"Sv. Petra Klavera, kněze",
	"",
	"",
	"",
	"Sv. Petra Klavera, kněze",
	"Claver Szent Péter áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_09_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Clavera, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_10_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Františka Gárateho, rehoľníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_10_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Karla Spinoly, kněze a mučedníka",
	"",
	"",
	"",
	"Bl. Karla Spinoly, kněze a mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_12[POCET_JAZYKOV + 1] =
{
	"Najsv. mena Panny Márie", // podľa Direktória 2012, str. 192; pôvodne bolo: 'Mena prebl. Panny Márie'
	"Jména Panny Marie",
	"",
	"",
	"",
	"Jména Panny Marie",
	"Szűz Mária Szent Neve",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_12_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Nejsvětějšího jména Panny Marie",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_13[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Zlatoústeho, biskupa a učiteľa Cirkvi",
	"Sv. Jana Zlatoústého, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Jana Zlatoústého, biskupa a učitele církve",
	"Aranyszájú (Krizosztomosz) Szent János püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_13_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Győr: A székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_14[POCET_JAZYKOV + 1] =
{
	"Povýšenie svätého kríža",
	"Povýšení svatého kříže",
	"",
	"",
	"",
	"Povýšení svatého kříže",
	"A Szent Kereszt felmagasztalása",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_15[POCET_JAZYKOV + 1] =
{
	"Sedembolestnej Panny Márie, patrónky Slovenska",
	"Panny Marie Bolestné",
	"",
	"",
	"",
	"Panny Marie Bolestné",
	"A Fájdalmas Szűzanya",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_16_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Ludmily, mučednice",
	"",
	"",
	"",
	"Sv. Ludmily, mučednice",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_16[POCET_JAZYKOV + 1] =
{
	"Sv. Kornélia, pápeža, a sv. Cypriána, biskupa, mučeníkov",
	"Sv. Kornélia, papeže, a Cypriána, biskupa, mučedníků",
	"",
	"",
	"",
	"Sv. Kornélia, papeže, a Cypriána, biskupa, mučedníků",
	"Szent Kornél pápa és Szent Ciprián püspök és vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_17[POCET_JAZYKOV + 1] =
{
	"Sv. Róberta Bellarmína, biskupa a učiteľa Cirkvi",
	"Sv. Roberta Bellarmina, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Roberta Bellarmina, biskupa a učitele Církve",
	"Bellarmin Szent Róbert püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_17_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Róberta Bellarmina, biskupa a učiteľa Cirkvi",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_17_OFM[POCET_JAZYKOV + 1] =
{
	"Stigmatizácia nášho otca sv. Františka",
	"Vtisknutí stigmat našemu sv. Otci Františkovi",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_18_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa Kupertínskeho, kňaza, člena 1. rádu",
	"Sv. Josefa z Kupertina, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_18_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Macíasa, rehoľníka",
	"",
	"",
	"",
	"",
	"Sv. Jana Maciase, řeholníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_18_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení kostela",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_19[POCET_JAZYKOV + 1] =
{
	"Sv. Januára, biskupa a mučeníka",
	"Sv. Januária, biskupa a mučedníka",
	"",
	"",
	"",
	"Sv. Januária, biskupa a mučedníka",
	"Szent Januáriusz püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_19_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Márie z Camporossa, "HTML_LINE_BREAK"rehoľníka, člena 1. rádu",
	"Sv. Františka Marie z Camporossa, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_20[POCET_JAZYKOV + 1] =
{
	"Sv. Andreja Kim Taegona, kňaza, "HTML_LINE_BREAK"a sv. Pavla Chong Hasanga a spoločníkov, mučeníkov",
	"Sv. Ondřeje Kim Taegona, kněze, Pavla Chong Hasanga a druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Ondřeje Kim Taegona, kněze, Pavla Chong Hasanga a druhů, mučedníků",
	"Kim Taegon Szent András áldozópap, Csong Haszang Szent Pál és társaik, vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_20_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály sv. Štěpána",
	"",
	"",
	"",
	"Výročí posvěcení katedrály sv. Štěpána",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_21[POCET_JAZYKOV + 1] =
{
	"Sv. Matúša, apoštola a evanjelistu",
	"Sv. Matouše, apoštola a evangelisty",
	"",
	"",
	"",
	"Sv. Matouše, apoštola a evangelisty",
	"Szent Máté apostol és evangélista",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_22[POCET_JAZYKOV + 1] =
{
	"Sv. Emeráma, biskupa a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_22_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Františka de Posadas, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_22_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Hyacinta Serrana Lópeza, kňaza, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_22_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Ignáca zo Santhie, kňaza, člena 1. rádu",
	"Sv. Ignáce ze Santhi&#224;, kněze", // &agrave;
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_22_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Jozefa Calasanza a Enrica Saiz Aparicio, kňazov, "HTML_LINE_BREAK"a 93 spoločníkov, mučeníkov",
	"Bl. Josefa Calasanz Marqués "HTML_LINE_BREAK"a Enrica Saiz Aparicio, kněží, a 93 druhů",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_23[POCET_JAZYKOV + 1] =
{
	"Sv. Pia z Pietrelčiny, kňaza",
	"Sv. Pia z Pietrelciny, kněze",
	"",
	"",
	"",
	"Sv. Pia z Pietrelciny, kněze",
	"Pietrelcinai Szent Pio áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_23_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Pia z Pietrelciny, kňaza, člena 1. rádu",
	"Sv. Pia z Pietrelciny, kněze",
	"",
	"",
	"",
	"Sv. Pia z Pietrelciny, kněze",
	"Pietrelcinai Szent Pio áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_24_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Banskej Bystrici", // ToDo: 'sv. Františka Xaverského', podľa Direktória 2012, str. 198
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_24_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Dalmáca Monera, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_24_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Szent Gellért püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_25_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Dalmáca Monera, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_25_OFM[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Inocence z Berza, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_26[POCET_JAZYKOV + 1] =
{
	"Sv. Kozmu a Damiána, mučeníkov",
	"Sv. Kosmy a Damiána, mučedníků",
	"",
	"",
	"",
	"Sv. Kosmy a Damiána, mučedníků",
	"Szent Kozma és Damján vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_26_CSSR[POCET_JAZYKOV + 1] =
{
	"Bl. Gašpara Stanggassingera, kňaza",
	"Bl. Kašpara Stanggassingera, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_26_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Vavrinca z Ripafratta, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_26_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Aurélia z Vinalesy, kňaza, a spoločníkov, "HTML_LINE_BREAK"mučeníkov, členov 1. rádu",
	"Bl. Aurela z Vinalesy, kněze, a druhů, mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_27[POCET_JAZYKOV + 1] =
{
	"Sv. Vincenta de Paul, kňaza",
	"Sv. Vincence z Paula, kněze",
	"",
	"",
	"",
	"Sv. Vincence z Paula, kněze",
	"Páli Szent Vince áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_28[POCET_JAZYKOV + 1] =
{
	"Sv. Václava, mučeníka",
	"Sv. Václava, mučedníka, hlavního patrona českého národa",
	"",
	"",
	"",
	"Sv. Václava, mučedníka, hlavního patrona českého národa, "HTML_LINE_BREAK"hlavního patrona provincie",
	"Szent Vencel vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_28_2[POCET_JAZYKOV + 1] =
{
	"Sv. Vavrinca Ruiza a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"Ruiz Szent Lőrinc és társai, Fülöp-szigeteki vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_28_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Vavrinca Ruiza z Manily, laika, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"Sv. Dominika Ibaněze z Erquicia, Jakuba Kyušei Tomonagy, kněží, "HTML_LINE_BREAK"Vavřince Ruize, otce rodiny, a druhů, japonských mučedníků", // CZOP kvôli sv. Václavovi slávia 26SEP
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_28_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Inocenta z Berza, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_29[POCET_JAZYKOV + 1] =
{
	"Sv. Michala, Gabriela a Rafaela, archanjelov",
	"Sv. Michaela, Gabriela a Rafaela, archandělů",
	"",
	"",
	"",
	"Sv. Michaela, Gabriela a Rafaela, archandělů",
	"Szent Mihály, Szent Gábor és Szent Rafael főangyalok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_SEP_30[POCET_JAZYKOV + 1] =
{
	"Sv. Hieronyma, kňaza a učiteľa Cirkvi",
	"Sv. Jeronýma, kněze a učitele církve",
	"",
	"",
	"",
	"Sv. Jeronýma, kněze a učitele Církve",
	"Szent Jeromos áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 10 október | october ---------------

const char *text_OKT_01[POCET_JAZYKOV + 1] =
{
	"Sv. Terézie z Lisieux, panny a učiteľky Cirkvi",
	"Sv. Terezie od Dítěte Ježíše, panny",
	"",
	"",
	"",
	"Sv. Terezie od Dítěte Ježíše, panny",
	"A Gyermek Jézusról nevezett (Lisieux-i) Szent Teréz szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_02[POCET_JAZYKOV + 1] =
{
	"Svätých anjelov strážcov",
	"Svatých andělů strážných",
	"",
	"",
	"",
	"Svatých andělů strážných",
	"Szent Őrzőangyalok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_03_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Františka de Borja, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_03_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Dominika Spadaforu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_04[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Assiského",
	"Sv. Františka z Assisi",
	"",
	"",
	"",
	"Sv. Františka z Assisi, jáhna",
	"Assisi Szent Ferenc",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_04_OFM[POCET_JAZYKOV + 1] =
{
	"Nášho otca sv. Františka, diakona, "HTML_LINE_BREAK"zakladateľa troch rádov",
	"Sv. Františka, jáhna, zakladatele tří řádů",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_04_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Assiského, diakona",
	"",
	"",
	"",
	"",
	"Sv. Františka z Assisi, jáhna",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_05_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Alberta Marvelliho",
	"Bl. Alberta Marvelliho",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_05_CSSR[POCET_JAZYKOV + 1] =
{
	"Bl. Františka Xaverského Seelosa, kňaza",
	"Bl. Františka Xavera Seelose, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_05_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Veszprém: A bazilika-főszékesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_05_SK[POCET_JAZYKOV + 1] =
{
	"Sv. Faustíny Kowalskej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_05_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Rajmunda z Kapuy, kňaza",
	"",
	"",
	"",
	"",
	"Bl. Rajmunda delle Vigne neboli z Kapuy, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_06[POCET_JAZYKOV + 1] =
{
	"Sv. Bruna, kňaza",
	"Sv. Bruna, kněze",
	"",
	"",
	"",
	"Sv. Bruna, kněze",
	"Szent Brúnó áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_06_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Diega Alojza de san Vitores, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_06_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Bartolomeja Longu, laika",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_07[POCET_JAZYKOV + 1] =
{
	"Ružencovej Panny Márie", // podľa Direktória 2012, str. 206, nie je 'prebl.'
	"Panny Marie Růžencové",
	"",
	"",
	"",
	"Panny Marie Růžencové",
	"Rózsafüzér Királynője",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_08_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Szűz Mária, Magyarok Nagyasszonya, Magyarország főpátronája",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_08_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Ambróza Sansedoniho, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_08_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Matúša Carreriho, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_09_1[POCET_JAZYKOV + 1] =
{
	"Sv. Dionýza, biskupa, a spoločníkov, mučeníkov",
	"Sv. Dionýsia, biskupa, a druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Dionýsia, biskupa, a druhů, mučedníků",
	"Szent Dénes püspök és társai vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_09_2[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Leonardiho, kňaza",
	"Sv. Jana Leonardiho, kněze",
	"",
	"",
	"",
	"Sv. Jana Leonardiho, kněze",
	"Leonardi Szent János áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_09_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Ľudovíta Bertrána, kňaza",
	"",
	"",
	"",
	"",
	"Sv. Ludvíka Bertrána, kněze",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_10_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Gereona a druhů, mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_11[POCET_JAZYKOV + 1] =
{
	"Sv. Jána XXIII., pápeža",
	"Sv. Jana XXIII., papeže",
	"",
	"",
	"",
	"Sv. Jana XXIII., papeže",
	"Szent XXIII. János pápa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_11_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Jána XXIII., pápeža, člena 3. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_11_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Žiline", // ToDo: 'Najsvätejšej Trojice', podľa Direktória 2012, str. 207
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_11_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jakuba z Ulmu, rehoľníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_12_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Radima, biskupa",
	"",
	"",
	"",
	"Sv. Radima, biskupa",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_12_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Serafína z Montegranara, rehoľníka, člena 1. rádu",
	"Sv. Serafína z Montegranara, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_13_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Honoráta Kożmińského, kňaza, člena 1. rádu",
	"Bl. Honoráta Kožmiňského, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_13_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Magdalény Panatieriovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_13_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Alexandry Márie da Costovej, panny", // podľa CZ SDB doplnené: "panny"
	"Bl. Alexandry Marie da Costa, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_13_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Petra Adriána Toulorge, kněze a mučedníka "HTML_LINE_BREAK"z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_14[POCET_JAZYKOV + 1] =
{
	"Sv. Kalixta I., pápeža a mučeníka",
	"Sv. Kalista I., papeže a mučedníka",
	"",
	"",
	"",
	"Sv. Kalista I., papeže a mučedníka",
	"Szent I. Kallixtusz pápa és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_14_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Ogilvieho, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_14_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Márie Poussepinovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_15[POCET_JAZYKOV + 1] =
{
	"Sv. Terézie od Ježiša, panny a učiteľky Cirkvi", // 'z Avily' upravené podľa Direktória 2012, str. 209
	"Sv. Terezie od Ježíše, panny a učitelky církve",
	"",
	"",
	"",
	"Sv. Terezie od Ježíše, panny a učitelky Církve",
	"A Jézusról nevezett (Avilai) Szent Teréz szűz és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_16_1[POCET_JAZYKOV + 1] =
{
	"Sv. Margity Márie Alacoque, panny",
	"Sv. Markéty Marie Alacoque, panny",
	"",
	"",
	"",
	"Sv. Markéty Marie Alacoque, panny",
	"Alacoque Szent Margit Mária szűz",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_16_2[POCET_JAZYKOV + 1] =
{
	"Sv. Hedvigy, rehoľníčky",
	"Sv. Hedviky, řeholnice, hlavní patronky Slezska",
	"",
	"",
	"",
	"Sv. Hedviky, řeholnice, hlavní patronky Slezska",
	"Szent Hedvig szerzetesnő",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_16_CSSR[POCET_JAZYKOV + 1] =
{
	"Sv. Gerarda Majellu, rehoľníka",
	"Sv. Gerarda Majelly, řeholníka",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_17[POCET_JAZYKOV + 1] =
{
	"Sv. Ignáca Antiochijského, biskupa a mučeníka",
	"Sv. Ignáce Antiochijského, biskupa a mučedníka",
	"",
	"",
	"",
	"Sv. Ignáce Antiochijského, biskupa a mučedníka",
	"Antiochiai Szent Ignác püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_18[POCET_JAZYKOV + 1] =
{
	"Sv. Lukáša, evanjelistu",
	"Sv. Lukáše, evangelisty",
	"",
	"",
	"",
	"Sv. Lukáše, evangelisty",
	"Szent Lukács evangélista",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_19_1[POCET_JAZYKOV + 1] =
{
	"Sv. Jána de Brébeuf a Izáka Jogues, kňazov, "HTML_LINE_BREAK"a spoločníkov, mučeníkov", //  // 'sv. Izáka', podľa Direktória 2012, str. 210 nie je 'sv.'
	"Sv. Jana de Brébeuf a Izáka Joguese, kněží, a druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Jana de Brébeuf a Izáka Joguese, kněží, a druhů, mučedníků",
	"De Brébeuf Szent János és Jogues Szent Izsák áldozópap és társaik vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_19_2[POCET_JAZYKOV + 1] =
{
	"Sv. Pavla z Kríža, kňaza",
	"Sv. Pavla od Kříže, kněze",
	"",
	"",
	"",
	"Sv. Pavla od Kříže, kněze",
	"Keresztes Szent Pál áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_19_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Jána de Brébeuf, Izáka Joguesa, kňazov, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_19_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Agnesy Galandovej de Langeac, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_19_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Petra z Alcantary, kňaza, člena 1. rádu",
	"Sv. Petra z Alkantary, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_20_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Jakuba Strepu, biskupa, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_20_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Jakuba Kerna, kněze z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_21_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Karla Rakouského",
	"",
	"",
	"",
	"Bl. Karla Rakouského",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_21_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Petra z Citt&#224; di Castello, kňaza", // &agrave;
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_21_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Voršily a jejich družek, mučednic",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_22_OP[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky konventného kostola, "HTML_LINE_BREAK"ktorého deň posviacky nie je známy",
	"",
	"",
	"",
	"",
	"Výročí posvěcení klášterního kostela",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_22[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Pavla II., pápeža",
	"Sv. Jana Pavla II., papeže",
	"",
	"",
	"",
	"Sv. Jana Pavla II., papeže",
	"Szent II. János Pál pápa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_23[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Kapistránskeho, kňaza",
	"Sv. Jana Kapistránského, kněze",
	"",
	"",
	"",
	"Sv. Jana Kapistránského, kněze",
	"Kapisztrán Szent János áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_23_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Kapistránskeho, kňaza, člena 1. rádu",
	"Sv. Jana z Capestrana, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_24[POCET_JAZYKOV + 1] =
{
	"Sv. Antona Márie Clareta, biskupa",
	"Sv. Antonína Marie Klareta, biskupa",
	"",
	"",
	"",
	"Sv. Antonína Marie Klareta, biskupa",
	"Claret Szent Antal Mária püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_24_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Alojza Guanellu, kňaza",
	"Bl. Aloise Guanelly, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_24_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"A székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_25_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Spišskom Podhradí", // ToDo: 'sv. Martina z Tours', podľa Direktória 2012, str. 213
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_25_SDB[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky vlastného chrámu (keď sa nepozná dátum posviacky)",
	"Výročí posvěcení vlastního kostela", // OFMCap.
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_25_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Petra Geremiu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_25_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Márie od Ježiša Masie Ferragutovej a spoločníc, "HTML_LINE_BREAK"panien a mučeníc, členiek 2. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_25_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Szent Mór püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_26[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky chrámov, "HTML_LINE_BREAK"ktorých deň posviacky nie je známy",  // 'je neznámy' opravené podľa Direktória 2012, str. 214
	"Výročí posvěcení chrámu, "HTML_LINE_BREAK"jejichž den dedikace není známý",
	"",
	"",
	"",
	"Výročí posvěcení chrámu, "HTML_LINE_BREAK"jejichž den dedikace není známý",
	"A saját templom felszentelése "HTML_LINE_BREAK"(amennyiben annak napja nem ismeretes)", // A felszentelt templomokban: A saját templom felszentelése
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_26_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Damiána z Finale, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_26_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Gilberta, opata z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_26_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Bonaventúru z Potenzy, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_27_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Rožňave", // ToDo: 'Nanebovzatia Panny Márie', podľa Direktória 2012, str. 214
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_27_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Bartolomeja z Vicenze, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_28[POCET_JAZYKOV + 1] =
{
	"Sv. Šimona a Júdu, apoštolov",
	"Sv. Šimona a Judy, apoštolů",
	"",
	"",
	"",
	"Sv. Šimona a Judy, apoštolů",
	"Szent Simon és Szent Júdás apostol",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_29_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Michala Ruu, kňaza",
	"Bl. Michala Ruy, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_29_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Bl. Marie Restituty Kafkové, panny a mučednice",
	"",
	"",
	"",
	"Bl. Marie Restituty Kafkové, panny a mučednice",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_30_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Dominika Collinsa, mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_30_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Benvenuty Boianiovej, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_30_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Terenca Alberta O’Brien, biskupa, "HTML_LINE_BREAK"a bl. Petra Higginsa, kňaza, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_30_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály Svatého Ducha",
	"",
	"",
	"",
	"Výročí posvěcení katedrály Svatého Ducha",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_31_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Alfonza Rodrígueza, rehoľníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_31_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Angela z Acri, kňaza, člena 1. rádu",
	"Bl. Anděla z Acri, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_OKT_31_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Wolfganga, biskupa",
	"",
	"",
	"",
	"Sv. Wolfganga, biskupa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
	"",
};
const char *text_OKT_31_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Boldog Romzsa Tódor püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 11 november ---------------

const char *text_NOV_01[POCET_JAZYKOV + 1] =
{
	"Všetkých svätých",
	"Všech svatých",
	"",
	"",
	"",
	"Všech svatých",
	"Mindenszentek",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_02[POCET_JAZYKOV + 1] =
{
	"Spomienka na všetkých verných zosnulých", // podľa Direktória 2012, str. 218
	"Vzpomínka na všechny věrné zemřelé",
	"",
	"",
	"",
	"Vzpomínka na všechny věrné zemřelé",
	"Halottak napja",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_03[POCET_JAZYKOV + 1] =
{
	"Sv. Martina Porres, rehoľníka", // 'de Porres': podľa Direktória 2012, str. 218, nie je 'de'
	"Sv. Martina de Porres, řeholníka",
	"",
	"",
	"",
	"Sv. Martina de Porres, řeholníka",
	"Porres Szent Márton szerzetes",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_03_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Ruperta Mayera, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_03_OFM[POCET_JAZYKOV + 1] =
{
	"Spomienka na všetkých zosnulých "HTML_LINE_BREAK"troch františkánskych rádov",
	"Vzpomínka na všechny zemřelé serafínského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_04[POCET_JAZYKOV + 1] =
{
	"Sv. Karola Borromea, biskupa",
	"Sv. Karla Boromejského, biskupa",
	"",
	"",
	"",
	"Sv. Karla Boromejského, biskupa",
	"Borromeo Szent Károly püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_05_SK[POCET_JAZYKOV + 1] =
{
	"Sv. Imricha",
	"",
	"",
	"",
	"",
	"",
	"Szent Imre herceg",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_05_SJ[POCET_JAZYKOV + 1] =
{
	"Všetkých svätých a blahoslavených zo Spoločnosti Ježišovej",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_05_SDB[POCET_JAZYKOV + 1] =
{
	"Všetkých zomrelých dobrodincov Saleziánskej rodiny",
	"Připomínka zemřelých dobrodinců a členů salesiánské rodiny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_05_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Šimona Ballacchiho, rehoľníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_06_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Alfonza de Navarrete, kňaza, a spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"Sv. Alfonse Navarrety, kněze a druhů, japonských mučedníků",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_06_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Alfonza Lopeza a spoločníkov, mučeníkov, členov 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_07_OP[POCET_JAZYKOV + 1] =
{
	"Všetkých svätých Rehole kazateľov",
	"",
	"",
	"",
	"",
	"Všech svatých Řádu bratří kazatelů",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_08_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Jána Dunsa Scota, kňaza, člena 1. rádu",
	"Bl. Jana z Dunsu, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_08_OP[POCET_JAZYKOV + 1] =
{
	"Spomienka na všetkých zosnulých "HTML_LINE_BREAK"bratov a sestry Rehole kazateľov",
	"",
	"",
	"",
	"",
	"Všech zemřelých bratří a sester "HTML_LINE_BREAK"Řádu bratří kazatelů",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_08_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Všech svatých premonstrátského řádu "HTML_LINE_BREAK"a všech svatých z řádů řeholních kanovníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_09[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky Lateránskej baziliky",
	"Posvěcení lateránské baziliky",
	"",
	"",
	"",
	"Posvěcení lateránské baziliky",
	"A lateráni-bazilika felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_10[POCET_JAZYKOV + 1] =
{
	"Sv. Leva Veľkého, pápeža a učiteľa Cirkvi",
	"Sv. Lva Velikého, papeže a učitele církve",
	"",
	"",
	"",
	"Sv. Lva Velikého, papeže a učitele církve",
	"Nagy Szent Leó pápa és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_11[POCET_JAZYKOV + 1] =
{
	"Sv. Martina z Tours, biskupa",
	"Sv. Martina, biskupa",
	"",
	"",
	"",
	"Sv. Martina, biskupa",
	"Tours-i Szent Márton püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_12[POCET_JAZYKOV + 1] =
{
	"Sv. Jozafáta, biskupa a mučeníka",
	"Sv. Josafata, biskupa a mučedníka",
	"",
	"",
	"",
	"Sv. Josafata, biskupa a mučedníka",
	"Szent Jozafát püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_13_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Artemida Zattiho",
	"Bl. Artemide Zattiho, koadjutora",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_13_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Stanislava Kostku, rehoľníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_13_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Didaka z Alcaly, rehoľníka, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_13_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Anežky České, panny",
	"",
	"",
	"",
	"Sv. Anežky České, panny",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_13_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"Magyar szentek és boldogok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_14_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Jozefa Pignatelliho, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_14_OPRAEM[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Siarda, opata z premonstrátského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_14_1_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jána Licciu, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_14_2_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Lucie z Narni, panny",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_14_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Mikuláša Tavelića a spoločníkov, "HTML_LINE_BREAK"kňazov a mučeníkov, členov 1. rádu",
	"Sv. Mikuláše Taveliče, kněze, a druhů, mučedníků",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_15[POCET_JAZYKOV + 1] =
{
	"Sv. Alberta Veľkého, biskupa a učiteľa Cirkvi",
	"Sv. Alberta Velikého, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Alberta Velikého, biskupa a učitele Církve",
	"Nagy Szent Albert püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_15_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Magdalény Moranovej, panny",
	"Bl. Magdalény Morano, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_16_1[POCET_JAZYKOV + 1] =
{
	"Sv. Margity Škótskej",
	"Sv. Markéty Skotské",
	"",
	"",
	"",
	"Sv. Markéty Skotské",
	"Skóciai Szent Margit",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_16_2[POCET_JAZYKOV + 1] =
{
	"Sv. Gertrúdy, panny",
	"Sv. Gertrudy, panny",
	"",
	"",
	"",
	"Sv. Gertrudy, panny",
	"Nagy Szent Gertrúd szűz", // HU 17NOV
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_16_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Rocha Gonzáleza, Alfonza Rodrígueza "HTML_LINE_BREAK"a Jána del Castillo, kňazov a mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_17[POCET_JAZYKOV + 1] =
{
	"Sv. Alžbety Uhorskej, rehoľníčky",
	"Sv. Alžběty Uherské, řeholnice",
	"",
	"",
	"",
	"Sv. Alžběty Uherské, řeholnice",
	"Árpád-házi Szent Erzsébet", // HU 19NOV
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_17_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Alžbety Uhorskej, rehoľníčky, "HTML_LINE_BREAK"patrónky františkánskeho svetského rádu",
	"Sv. Alžběty Uherské, patronky 3. řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_18[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky bazilík sv. Petra a sv. Pavla, apoštolov",
	"Posvěcení římských bazilik svatých apoštolů Petra a Pavla",
	"",
	"",
	"",
	"Posvěcení římských bazilik svatých apoštolů Petra a Pavla",
	"Szent Péter- és Szent Pál-bazilikák felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_18_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Salome z Krakova, panny, členky 2. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_19_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Agnesy z Assisi, panny, členky 2. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_19_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jakuba Benfattiho, biskupa",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_20_SK[POCET_JAZYKOV + 1] =
{
	"Výročie posviacky katedrálneho chrámu v Nitre", // ToDo: 'sv. Emeráma', podľa Direktória 2012, str. 226
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_21[POCET_JAZYKOV + 1] =
{
	"Obetovanie Panny Márie", // podľa Direktória 2012, str. 226, nie je 'prebl.'
	"Zasvěcení Panny Marie v Jeruzalémě",
	"",
	"",
	"",
	"Zasvěcení Panny Marie v Jeruzalémě",
	"A Boldogságos Szűz Mária bemutatása a templomban",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_22[POCET_JAZYKOV + 1] =
{
	"Sv. Cecílie, panny a mučenice",
	"Sv. Cecilie, panny a mučednice",
	"",
	"",
	"",
	"Sv. Cecilie, panny a mučednice",
	"Szent Cecília szűz és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_23_1[POCET_JAZYKOV + 1] =
{
	"Sv. Klementa I. pápeža a mučeníka",
	"Sv. Klementa I., papeže a mučedníka",
	"",
	"",
	"",
	"Sv. Klementa I., papeže a mučedníka",
	"Szent I. Kelemen pápa és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_23_2[POCET_JAZYKOV + 1] =
{
	"Sv. Kolumbána, opáta",
	"Sv. Kolumbána, opata",
	"",
	"",
	"",
	"Sv. Kolumbána, opata",
	"Szent Kolumbán apát",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_23_SJ[POCET_JAZYKOV + 1] =
{
	"Bl. Michala Augustína Pro, kňaza a mučeníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_24[POCET_JAZYKOV + 1] =
{
	"Sv. Ondreja Dung-Laka, kňaza, "HTML_LINE_BREAK"a spoločníkov, mučeníkov",
	"Sv. Ondřeje Dung-Laca, kněze, a druhů, mučedníků",
	"",
	"",
	"",
	"Sv. Ignáce Delgada, biskupa, Vincence Liema, kněze, "HTML_LINE_BREAK"Dominika An-Khama, otce rodiny, a druhů, vietnamských mučedníků",
	"Dung-Lac Szent András áldozópap és társai vértanúk",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_24_OP[POCET_JAZYKOV + 1] =
{
	"Sv. Ignáca Klementa Delgadu, biskupa, "HTML_LINE_BREAK"Vincenta Le Quang Liem a Pace, kňaza, "HTML_LINE_BREAK"Dominika Pham Trong (An) Khama, laika, "HTML_LINE_BREAK"a spoločníkov, mučeníkov",
	"Sv. Ignáce Delgada, biskupa, Vincence Liema, kněze, "HTML_LINE_BREAK"Dominika An-Khama, otce rodiny, a druhů, vietnamských mučedníků",
	"",
	"",
	"",
	"Sv. Ignáce Delgada, biskupa, Vincence Liema, kněze, "HTML_LINE_BREAK"Dominika An-Khama, otce rodiny, a druhů, vietnamských mučedníků",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_25[POCET_JAZYKOV + 1] =
{
	"Sv. Kataríny Alexandrijskej, panny a mučenice",
	"Sv. Kateřiny Alexandrijské, panny a mučednice",
	"",
	"",
	"",
	"Sv. Kateřiny Alexandrijské, panny a mučednice",
	"Alexandriai Szent Katalin szűz és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_25_HU[POCET_JAZYKOV + 1] =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"A bazilika-székesegyház felszentelése",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_25_SDB[POCET_JAZYKOV + 1] =
{
	"Všetkých zomrelých rodičov saleziánov",
	"Připomínka zemřelých rodičů salesiánů",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_26_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Berchmansa, rehoľníka",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_26_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Leonarda z Porto Mauricia, kňaza, člena 1. rádu",
	"Sv. Leonarda z Porta Mauritia, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_27_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Antona Fasaniho, kňaza, člena 1. rádu",
	"Sv. Františka Antonína Fasaniho, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_27_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Margity Savojskej, matky rodiny a rehoľníčky",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_28_OFM[POCET_JAZYKOV + 1] =
{
	"Sv. Jakuba z Marky, kňaza, člena 1. rádu",
	"Sv. Jakuba z Marky, kněze",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_29_OFM[POCET_JAZYKOV + 1] =
{
	"Všetkých svätých troch františkánskych rádov",
	"Všech svatých serafínského řádu",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_NOV_30[POCET_JAZYKOV + 1] =
{
	"Sv. Ondreja, apoštola",
	"Sv. Ondřeje, apoštola",
	"",
	"",
	"",
	"Sv. Ondřeje, apoštola",
	"Szent András apostol",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 12 december ---------------

const char *text_DEC_01_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Edmunda Campiona, Róberta Southwella a ich spoločníkov, mučeníkov",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_01_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Jána Vercellského, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_01_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Sv. Edmunda Kampiána, kněze a mučedníka",
	"",
	"",
	"",
	"Sv. Edmunda Kampiána, kněze a mučedníka",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_02_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály sv. Bartoloměje",
	"",
	"",
	"",
	"Výročí posvěcení katedrály sv. Bartoloměje",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_02_1_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Rafaela Chylińského, kňaza, člena 1. rádu",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_02_2_OFM[POCET_JAZYKOV + 1] =
{
	"Bl. Angely Márie Astorchovej, panny, členky 2. rádu",
	"Bl. Marie Anděly Astorch, panny",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_03[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Xaverského, kňaza",
	"Sv. Františka Xaverského, kněze",
	"",
	"",
	"",
	"Sv. Františka Xaverského, kněze",
	"Xavéri Szent Ferenc áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_03_SJ[POCET_JAZYKOV + 1] =
{
	"Sv. Františka Xavérskeho, misionára",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_04[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Damascénskeho, kňaza a učiteľa Cirkvi",
	"Sv. Jana Damašského, kněze a učitele církve",
	"",
	"",
	"",
	"Sv. Jana Damašského, kněze a učitele Církve",
	"Damaszkuszi Szent János áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_05_SDB[POCET_JAZYKOV + 1] =
{
	"Bl. Filipa Rinaldiho, kňaza, "HTML_LINE_BREAK"zakladateľa Sekulárneho inštitútu dobrovoľníčok dona Bosca",
	"Bl. Filipa Rinaldiho, kněze, "HTML_LINE_BREAK"zakladatele Sekulárního institutu Volontárií Dona Boska",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_06[POCET_JAZYKOV + 1] =
{
	"Sv. Mikuláša, biskupa",
	"Sv. Mikuláše, biskupa",
	"",
	"",
	"",
	"Sv. Mikuláše, biskupa",
	"Szent Miklós püspök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_07[POCET_JAZYKOV + 1] =
{
	"Sv. Ambróza, biskupa a učiteľa Cirkvi",
	"Sv. Ambrože, biskupa a učitele církve",
	"",
	"",
	"",
	"Sv. Ambrože, biskupa a učitele Církve",
	"Szent Ambrus püspök és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_08[POCET_JAZYKOV + 1] =
{
	"Nepoškvrnené počatie Panny Márie",
	"Panny Marie, počaté bez poskvrny prvotního hříchu",
	"",
	"",
	"",
	"Neposkvrněného početí Panny Marie",
	"A Boldogságos Szűz Mária szeplőtelen fogantatása",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_09[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Didaka Cuauhtlatoatzin",
	"Sv. Jana Didaka Cuauhtlatoatzina",
	"",
	"",
	"",
	"Sv. Jana Didaka Cuauhtlatoatzina",
	"Szent Juan Diego Cuauhtlatoatzin, Guadalupei látnok",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_11[POCET_JAZYKOV + 1] =
{
	"Sv. Damaza I., pápeža",
	"Sv. Damasa I., papeže",
	"",
	"",
	"",
	"Sv. Damasa I., papeže",
	"Szent I. Damazusz pápa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_12[POCET_JAZYKOV + 1] =
{
	"Panny Márie Guadalupskej", // podľa Direktória 2012, str. 232, nie je 'Prebl.'
	"Panny Marie Guadalupské",
	"",
	"",
	"",
	"Panny Marie Guadalupské",
	"A Guadalupei Boldogságos Szűz Mária",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_13[POCET_JAZYKOV + 1] =
{
	"Sv. Lucie, panny a mučenice",
	"Sv. Lucie, panny a mučednice",
	"",
	"",
	"",
	"Sv. Lucie, panny a mučednice",
	"Szent Lúcia szűz és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_14[POCET_JAZYKOV + 1] =
{
	"Sv. Jána z Kríža, kňaza a učiteľa Cirkvi",
	"Sv. Jana od Kříže, kněze a učitele církve",
	"",
	"",
	"",
	"Sv. Jana od Kříže, kněze a učitele Církve",
	"Keresztes Szent János áldozópap és egyháztanító",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_16_OP[POCET_JAZYKOV + 1] =
{
	"Bl. Šebastiána Maggiho, kňaza",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_21[POCET_JAZYKOV + 1] =
{
	"Sv. Petra Kanízia, kňaza a učiteľa Cirkvi",
	"Sv. Petra Kanisia, kněze a učitele církve",
	"",
	"",
	"",
	"Sv. Petra Kanisia, kněze a učitele Církve",
	"Kaníziusz Szent Péter áldozópap és egyháztaíntó",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_22_CZ[POCET_JAZYKOV + 1] =
{
	"",
	"Výročí posvěcení katedrály Sv. Mikuláše",
	"",
	"",
	"",
	"Výročí posvěcení katedrály Sv. Mikuláše",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_22_OP[POCET_JAZYKOV + 1] =
{
	"Výročie potvrdenia Rehole kazateľov (1216)",
	"",
	"",
	"",
	"",
	"",
	"",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_23[POCET_JAZYKOV + 1] =
{
	"Sv. Jána Kentského, kňaza",
	"Sv. Jana Kentského, kněze",
	"",
	"",
	"",
	"Sv. Jana Kentského, kněze",
	"K&#281;ty Szent János áldozópap",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_26[POCET_JAZYKOV + 1] =
{
	"Sv. Štefana, prvého mučeníka",
	"Sv. Štěpána, prvomučedníka",
	"",
	"",
	"",
	"Sv. Štěpána, prvomučedníka",
	"Szent István első vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_27[POCET_JAZYKOV + 1] =
{
	"Sv. Jána, apoštola a evanjelistu",
	"Sv. Jana, apoštola a evangelisty",
	"",
	"",
	"",
	"Sv. Jana, apoštola a evangelisty",
	"Szent János apostol és evangélista",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_28[POCET_JAZYKOV + 1] =
{
	"Svätých Neviniatok, mučeníkov",
	"Svatých Mláďátek, mučedníků",
	"",
	"",
	"",
	"Svatých Mláďátek, mučedníků",
	"Aprószentek",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_29[POCET_JAZYKOV + 1] =
{
	"Sv. Tomáša Becketa, biskupa a mučeníka",
	"Sv. Tomáše Becketa, biskupa a mučedníka",
	"",
	"",
	"",
	"Sv. Tomáše Becketa, biskupa a mučedníka",
	"Becket Szent Tamás püspök és vértanú",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_DEC_31[POCET_JAZYKOV + 1] =
{
	"Sv. Silvestra I., pápeža",
	"Sv. Silvestra I., papeže",
	"",
	"",
	"",
	"Sv. Silvestra I., papeže",
	"Szent I. Szilveszter pápa",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

// --------------- 00 pohyblivé slávenia | celebrations with moving date ---------------

const char *text_ZELENY_STVRTOK[POCET_JAZYKOV + 1] =
{
	"Zelený (veľký) štvrtok – Pamiatka Pánovej večere",
	"Zelený čtvrtek - Památka Večeře Páně",
	"",
	"",
	"",
	"Zelený čtvrtek - Památka Večeře Páně",
	"Nagycsütörtök",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_VELKY_PIATOK[POCET_JAZYKOV + 1] =
{
	"Veľký piatok",
	"Velký pátek",
	"",
	"",
	"",
	"Velký pátek",
	"Nagypéntek",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_BIELA_SOBOTA[POCET_JAZYKOV + 1] =
{
	"Biela (veľká) sobota",
	"Bílá sobota",
	"",
	"",
	"",
	"Bílá sobota",
	"Nagyszombat",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_KVETNA_NEDELA[POCET_JAZYKOV + 1] =
{
	"Kvetná nedeľa",
	"Květná neděle",
	"",
	"",
	"",
	"Květná neděle",
	"Virágvasárnap, vagyis az Úr szenvedésének vasárnapja",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_PO_POPOLCOVEJ_STREDE[POCET_JAZYKOV + 1] =
{
	"po Popolcovej strede",
	"po Popeleční středě",
	"",
	"",
	"",
	"po Popeleční středě",
	"Hamvazószerda után",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};
const char *text_V_OKTAVE_NARODENIA[POCET_JAZYKOV + 1] =
{
	"v oktáve Narodenia Pána",
	"v oktávu Narození Páně",
	"",
	"",
	"",
	"v oktávu Narození Páně",
	"Karácsony nyolcada",
	"ru_text",
	/* STRING_2_FOR_NEW_LANGUAGE */
};

#endif // __HODIN_H_
