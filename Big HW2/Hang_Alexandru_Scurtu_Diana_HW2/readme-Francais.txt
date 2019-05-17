Grand devoir 2

Auteurs: Diana Scurtu
	 Alex Hang

Exercice 1:

Input : le nombre d'�tudiants, le nombre de projets et les noms des �tudiants et des projets sont lus � partir du fichier "txt.in" � l'aide de fstream.

Structures de donn�es utilis�es: - 3 structures * proiect
						* elev
�						* camp
- 1 classe * LinkedList (du cours)

Fonctionnalit�s: * lire les donn�es du fichier et cr�er la LinkedList des �tudiants et des projets
		 * imprimer la liste
		 * suppression d'un �tudiant de la liste
		 * remplacement d'un projet par un autre



Exercice 2:

Input: le nombre de rues et d'intersections est lu dans le fichier "streets.in" � l'aide de fstream.

Structures de donn�es utilis�es: - 1 Graph repr�sentant la carte des rues

Approche:
	1) lisez les rues et les intersections � partir du fichier et cr�ez le graphique.
	2) v�rifiez si le graphique est hamiltonien:
		SI VRAI
			3) Trouver le cycle hamiltonien � travers le graphique
			4) Imprimer la solution
		SI FAUX
			* Imprimer un message


Exercice 3:

Input: les mots sont lus � partir du fichier "streets.in", en utilisant fstream.

Structures de donn�es utilis�es: - 1 graphique
- 1 liste
- 1 pile
Approche: topological sort