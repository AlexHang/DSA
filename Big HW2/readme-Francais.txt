Grand devoir 2

Auteurs: Diana Scurtu
	 Alex Hang

Exercice 1:

Input : le nombre d'étudiants, le nombre de projets et les noms des étudiants et des projets sont lus à partir du fichier "txt.in" à l'aide de fstream.

Structures de données utilisées: - 3 structures * proiect
						* elev
 						* camp
- 1 classe * LinkedList (du cours)

Fonctionnalités: * lire les données du fichier et créer la LinkedList des étudiants et des projets
		 * imprimer la liste
		 * suppression d'un étudiant de la liste
		 * remplacement d'un projet par un autre



Exercice 2:

Input: le nombre de rues et d'intersections est lu dans le fichier "streets.in" à l'aide de fstream.

Structures de données utilisées: - 1 Graph représentant la carte des rues

Approche:
	1) lisez les rues et les intersections à partir du fichier et créez le graphique.
	2) vérifiez si le graphique est hamiltonien:
		SI VRAI
			3) Trouver le cycle hamiltonien à travers le graphique
			4) Imprimer la solution
		SI FAUX
			* Imprimer un message


Exercice 3:

Input: les mots sont lus à partir du fichier "streets.in", en utilisant fstream.

Structures de données utilisées: - 1 graphique
- 1 liste
- 1 pile
Approche: topological sort