# Projet-Plagiat
La d ́etection de plagiat consiste `a identifier les sections de textes qui ont  ́et ́e
copi ́ees d’autres sources sans cr ́edit. Il existe diff ́erentes m ́ethodes pour d ́etecter
le plagiat, notamment l’utilisation de logiciels de d ́etection de plagiat, l’analyse
de similarit ́e de textes et la comparaison manuelle de textes. Pour  ́ecrire un
programme de d ́etection de plagiat en C, Nous devons utiliser des algorithmes
de traitement de texte pour analyser les documents et d ́etecter les sections de
texte similaire. Nous avons vu sur internet que plusieurs programmes utilis ́es la
technique du hashage mais n’ayant pas compris la technique utilis ́ee nous avons
opt ́e pour une maniere de faire un peu plus basique et simple .
Ce programme compare deux fichiers.txt et a pour but de detecter des mots
et puis des phrases qui se trouvent en communs dans les deux fichiers et dans
le meme ordre puis afficher le pourcentage de plagiat par fichiers pour ensuite
supprimer ces sections de textes qui sont en communs pour avoir deux fichiers
propre nettoy ́e du plagiat avec 0 compatibilit ́e .
*explication du script :
Ce code source est  ́ecrit en C et utilise des structures de donn ́ees pour stocker
des informations sur les mots et les phrases d’un fichier. Il y a deux structures
de donn ́ees d ́efinies : Word et Sentence. Chacune de ces structures a un champ
de texte, un champ de comptage pour le nombre de fois o`u un mot est utilis ́e
(uniquement en txt) et un champ suivant pour cr ́eer une liste li ́ee.
On a d ́efinies plusieurs fonctions pour manipuler ces structures de donn ́ees,
telles que :
initword, initsentence,addword, addsentence.
Ces fonctions sont utilis ́ees pour cr ́eer des instances de Word et Sentence,
ajouter des instances `a des listes li ́ees, etc.
Il existe  ́egalement une fonction removepunctuationquiretirelaponctuationd′unmot,
une fonction comparewordsquicomparelesmotspouruntri.
une fonction readsentencequilitunephrased′unf ichier.
une fonction printcommonwords()quiimprimelesmotscommunsentredeuxlistesdemots.
En gros, le code lit un fichier et utilise les fonctions d ́efinies pour stocker les
informations sur les mots et les phrases dans des structures de donn ́ees, puis il
utilise ces informations pour afficher les mots en communs entre les deux fichiers. 
Durant ce projet nous avons utilis ́e trois biblioth`eques diff ́erentes.
La premi`ere est stdio.h , cette biblioth`eque contient les constantes,les va-
riables et les d ́efinitions de fonctions utilis ́ees dans les op ́erations d’entr ́ee/sortie.
La deuxi`eme est stdlib.h , elle d ́efinit quatre types de variables, plusieurs
macros et diverses fonctions pour ex ́ecuter des fonctions g ́en ́erales.
La troisi`eme est poppler.h , c’est une biblioth`eque d’utilitaires logiciels gra-
tuits pour le rendu de documents au format PDF (Portable Document Format).
La quatrieme est string.h , c’est la bibliotheque qui contient les d ́efinitions
des macros, des constantes et les d ́eclarations de fonctions et de types utilis ́ees
non seulement pour la manipulation de chaˆınes de caracteres.
Nous avons trouv ́e la majorit ́e des d ́efinitons utilis ́ees sur le site Wikipedia
Le travail a  ́et ́e fait en groupe `a la biblioth ́eque de Nanterre . chacun de
nous a propos ́e des id ́ees pour am ́eliorer le programme . Nous avons utilis ́e des
structures de donn ́ees avanc ́es car nous avons besoin de structure dynamique
c’est pour cela que nous avons opt ́e pour l’utilisation de liste chainn ́ees apr`es
avoir essayer plusieurs autres structures.Nous avons  ́egalement demand ́e conseils
a quelques amis qui nous ont bien aid ́e avec quelques notions tel que les doubles
pointeurs essentiel pour modifier le contenu de la liste chainées.
Nous voulons au d ́ebut de la creation de ce porgramme de detection de
plagiat de presenter les resultats d’occurence sur des grpahes , nous avons alors
cherch ́e sur plusieurs sources comment faire cela . Nous avons donc trouv ́e sur
Chatgpt un code mais nous n’avons pas su l’utiliser .
La Partie qui a le plus solicit ́e d’efforts et de reflexions est celle dans la-
quelle on doit d ́efinir la start ́egie d’approche et de comparaison mais aussi des
differentes conditions et criteres a evalu ́e pour faire fonctionner le programme
comme par exemple comment faire pour trouver si les mots sont les memes
dans les deux fichiers en utilisant certes des pointeurs mais de quelle maniere ?
des videos youtube et quelques recherches googles nous ont aid ́es a trouver la
solution .
Le programme ne compile plus a cause de quelques fonctionnalit ́es qu’on
a essaye d’ajouter a la fin pour ameliorer notre programme comme trouver
le poyrcentage de ressemblance et nous n’avons pas eu le temps d’ajouter la
fonctionnalit ́e pour supprimer les mots plagi ́e en plus . Mais vers la fin durapport nous avons mis un extrait du resultat de l’execution lors du d ́ebut du
programme qui trouve l’occurence de chaque mots et phrases dans les deux
fichiers du moment ou ils sont en txt .
L’autre probleme rencontr ́e est lors de l’execution . Dans notre execution ca
nous affiche la phrase en commun deux fois si elle se trouve deux fois dans les
deux fichiers .

##Bilan personnel
Les difficult ́es que nous avons rencontr ́e en d ́ebut du projet nous  ́etaient
pratiquement insurmontables mais elles nous ont paru beaucoup plus simples
apr`es diff ́erents essais mais aussi grace a quelques notions apprises en cours cette
ann ́ee . c’est vrai que moi BOUDINAR Lounes , j'avais
jamais fait de programmation en langage C donc c’etait pour moi une
premiere et donc l’adaptation a pris un tout petit peu de temps mais j'ai
tout de meme reussit a faire ce projet qui est comme une fierté pour moi .
