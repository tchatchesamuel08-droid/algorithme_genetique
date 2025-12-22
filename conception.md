
La conception vise à :
•	Clarifier les responsabilités de chaque composant,
•	Assurer une architecture logicielle propre et modulaire,
•	Faciliter l’implémentation progressive du projet,
•	Éviter les incohérences et le bricolage lors du développement.
2. Vue globale du système
L’application est conçue comme un outil interactif de visualisation reposant sur trois grandes parties :
1.	Le cœur algorithmique
Il implémente l’algorithme génétique appliqué au problème du sac à dos. Cette partie est indépendante de toute interface graphique.
2.	La gestion de l’application
Elle coordonne l’exécution de l’algorithme, la gestion du temps, des générations et des paramètres.
3.	L’interface graphique et la visualisation
Elle permet à l’utilisateur d’interagir avec l’algorithme, de modifier les paramètres et d’observer les résultats en temps réel.
Cette séparation garantit une bonne lisibilité du code et facilite les évolutions futures.
3. Modélisation des entités principales
3.1 Objet 
Un objet représente un élément pouvant être placé dans le sac à dos.
Chaque objet est caractérisé par :
•	Un poids,
•	Une valeur.
Les objets sont communs à toutes les solutions et constituent les données d’entrée du problème.
3.2 Individu 
Un individu représente une solution candidate au problème du sac à dos.
Il est défini par :
•	Un chromosome binaire, où chaque gène correspond à un objet,
•	Une valeur de fitness associée.
Responsabilités principales :
•	Représenter une combinaison d’objets,
•	Calculer son propre fitness en fonction des contraintes du problème,
•	Servir de base aux opérations génétiques (sélection, croisement, mutation).
3.3 Population 
La population est un ensemble d’individus représentant les solutions présentes à une génération donnée.
Responsabilités principales :
•	Stocker les individus,
•	Permettre l’accès au meilleur individu,
•	Servir de base à la génération suivante.
La population évolue au fil des générations grâce à l’algorithme génétique.
3.4 Algorithme Génétique
L’algorithme génétique constitue le cœur logique du projet.
Il est responsable de :
•	L’initialisation de la population,
•	L’évaluation des individus,
•	L’application des opérateurs génétiques :
o	Sélection (par tournoi),
o	Croisement (à un point),
o	Mutation (inversion de bits),
o	Élitisme,
•	La création des générations successives,
•	La gestion du critère d’arrêt.
Cette partie est totalement indépendante de l’interface graphique.
4. Paramètres de l’algorithme
Les paramètres suivants sont considérés comme variables et modifiables par l’utilisateur :
•	Taille de la population,
•	taux de mutation,
•	taux de croisement,
•	nombre maximal de générations,
•	taille du tournoi pour la sélection,
•	capacité du sac à dos.
Ces paramètres influencent directement le comportement et la performance de l’algorithme.
5. Flux général de fonctionnement
Le fonctionnement global de l’application suit les étapes suivantes :
1.	Chargement des objets du problème du sac à dos.
2.	Initialisation de la population de manière aléatoire.
3.	Évaluation de la fitness de chaque individu.
4.	Sélection des individus parents.
5.	Application du croisement et de la mutation.
6.	Conservation des meilleurs individus (élitisme).
7.	Création de la nouvelle génération.
8.	Mise à jour de la visualisation.
9.	Vérification du critère d’arrêt.
10.	Répétition du processus jusqu’à la fin de l’exécution.
6. Interface utilisateur et visualisation
L’interface graphique permet :
•	de lancer, arrêter et réinitialiser l’algorithme,
•	de modifier les paramètres en temps réel,
•	d’observer :
o	la génération actuelle,
o	le meilleur individu,
o	la valeur et le poids du sac,
o	l’évolution du fitness sous forme graphique.
L’interface n’intervient jamais directement dans la logique de l’algorithme, mais agit uniquement comme un outil de contrôle et de visualisation.
7. Évolutivité et extensions futures
L’architecture choisie permet :
•	d’ajouter facilement d’autres méthodes de sélection,
•	de comparer plusieurs algorithmes d’optimisation,
•	d’adapter l’outil à d’autres problèmes combinatoires,
•	d’enrichir la visualisation sans modifier le cœur algorithmique.
8. Conclusion de la conception
Cette phase de conception permet de poser des bases solides pour l’implémentation du projet.
Elle assure une séparation claire des responsabilités, facilite le développement progressif et garantit la cohérence globale de l’application.