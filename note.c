// c = Caractère
//===================================================================================================
Quand il est utilisé avec les fonctions printf, spécifie un caractère codé sur un octet ; quand il est utilisé avec les fonctions wprintf, spécifie un caractère large.
//===================================================================================================

// s = String
//====================================================================================================
Quand il est utilisé avec les fonctions printf, spécifie une chaîne de caractères codés sur un octet ou multioctets ; quand il est utilisé avec les fonctions wprintf, spécifie une chaîne de caractères larges. Les caractères s’affichent jusqu’au premier caractère Null ou jusqu’à ce que la valeur de precision soit atteinte.
//====================================================================================================

// p = Type de pointeur	
//====================================================================================================
Affichez l’argument en tant qu’adresse en chiffres hexadécimaux.
//====================================================================================================

// d & i = Integer
//====================================================================================================
Entier décimal signé.
//====================================================================================================

// u = Integer
//====================================================================================================
Entier décimal non signé.
//====================================================================================================

// x = Integer
//====================================================================================================
Entier hexadécimal non signé ; utilise « abcdef ».
//====================================================================================================

// X = Integer
//====================================================================================================
Entier hexadécimal non signé ; utilise « ABCDEF ».
//====================================================================================================

//====================================================================================================
c s p d i u x X
//====================================================================================================

//====================================================================================================
% [ indicateurs] [ largeur] [. précision] [ taille] type
//====================================================================================================

//====================================================================================================
Si [largeur] plus grand que largument des espace sont mis juste devant, exemples:
i = [123456789]
s = ["123456789"]
c = ['b']
[%10d] = [ 123456789]
[%15d] = [     123456789]
[%15s] = [     123456789]
[%10c] = [         b]
//====================================================================================================

//====================================================================================================
Si [indicateur = 0 || -] et que [largeur] n'est pas specifier ou [largeur] <= a la taille de largument
il ni a pas d'effet, exemple:
i = [123456789]
s = ["123456789"]
c = ['b']
[%0d] = [123456789]
[%-d] = [123456789]
[%0s] = [123456789] avec "WARNING"
[%-s] = [123456789]
[%0c] = [b] avec "WARNING"
[%-c] = [b]

-----------------------------------------------------------------------------------------------------
Si [indicateur = 0] et que [largeur] est plus grand que largument alors
des 0 sont mis juste devant, exemple:
i = [123456789]
s = ["123456789"]
c = ['b']
[%015d] = [000000123456789]
[%015s] = [000000123456789] avec "WARNING"
[%010c] = [000000000b] avec "WARNING"
-----------------------------------------------------------------------------------------------------
Si [indicateur = -] et que [largeur] est plus grand que largument alors
des espace '' sont mis a la fin, exemple:
i = [123456789]
s = [123456789]
c = ['b']
[%-15d] = [123456789      ]
[%-15s] = [123456789      ]
[%-10c] = [b         ]
----------------------------------------------------------------------------------------------------
Si [indicateur = -0 || 0-] et que [largeur] est plus grand que l'arguement un "WARNING" s'affiche 
es le 0 es annuler et remplacer par [-] donc de espace '' sont mis a la fin, exemple:
i = [123456789]
s = ["123456789"]
c = ['b']
[%-015d] = [123456789      ]
[%0-15d] = [123456789      ]
[%-015s] = [123456789      ]
[%0-15s] = [123456789      ]
[%-010c] = [b         ]
[%0-10c] = [b         ]
----------------------------------------------------------------------------------------------------
Si [indicateur = 0] et que [largeur] plus grand que [.precision] et que [.precision] plus grand que
largument des 0 sont mis devant jusqua la taille de [.precision] et ensuite des espace '' jusqua
la taille de [largeur], exemple:
i = [123456789]
[%020.15d] = [     000000123456789]

Avec une string "" || char '' [largeur] domine [.precision] et des 0 sont mis devant jusqua la taille de
[largeur], exemple:
s = ["123456789"]
[%020.15s] = [00000000000123456789] avec "WARNING"
[%015.10c] = [00000000000000b] avec "WARNING"
----------------------------------------------------------------------------------------------------
Si [indicateur = -] et que [largeur] plus grand que [.precision] et que [.precision] plus grand que
largument des 0 sont mis devant jusqua la taille de [largeur] et ensuite des espace '' a la fin
jusqua la taille de [largeur], exemple:
i = [123456789]
[%-20.15d] = [000000123456789     ]

Avec une string "" || char '' [largeur] domine [.precision] et des espace '' sont mis a la fin
jusqua la taille de [largeur], exemple:
s = ["123456789"] 
[%-20.15s] = [123456789           ]
[%-20.60s] = [123456789           ]
c = ['b']
[%-2.60c] = [b ] avec "WARNING"
[%-20.15c] = [b                    ] avec "WARNING"
//====================================================================================================

//====================================================================================================
Si [.precision] est plus grand que largument et plus grand que [largeur] et que [indicateur = 0 || -]
la [largeur] et [indicateur] n'as aucun effet et donc des 0 sont mis devant jusqua la taille
de [.precision], exemple:
i = [123456789]
[%-5.15d] = [000000123456789]
[%05.15d] = [000000123456789]
[%5.15d]  = [000000123456789]
[%-.15d]  = [000000123456789]
"[.precison] domine toujour si il es plus grand que [largeur] meme si [largeur] plus grand que largument"
"auncun effet si [.precision] plus petit que largument"

Avec une string "" si [.precison] n'est pas plus petit que largument auncun effet, exemple:
s = "123456789"
[%-5.15s] = [123456789]
[%-05.15s] = [123456789]
[%5.15s] = [123456789]
[%-.15s] = [123456789]

Si [.precion] est plus petit que largument alors on affiche jusque la taille de [.precision], exemple:
s = "123456789"
[%.5s] = [12345]
[%.0s] = []


//====================================================================================================
int = "pour des int [.indicateur = 0 || rien] met des espace '' devant jusqua la taille de [largeur]"
	  "parcontre [.precison] domine [largeur] si plus petit et met des 0 jusqua la taille de precision"

//Exemple
//===========================================	
	%0*.*
	%-12.53
	%-0*.53
	%0-12.*
	%-.53
//===========================================	

--------------------------------------------------------------------------------------------------------
[.precision] fonctionne tout seul, pour des char* il tronque et n'ajoute pas de 0 si il es plus grand 
que largument.
[.precision] par contre avec des int il ne tronque jamais mais il ajoute des 0 si il es plus grand
et domine [indicateur] + [largeur]
--------------------------------------------------------------------------------------------------------
[.indicateur] fonctionne uniquement avec la [largeur]
si [largeur] es prefixer d'un 0, pour des int il va mettre des zero si [largeur] est plus grand que la taille
de largument.

