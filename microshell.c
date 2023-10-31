#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	ft_putstr_fd2(char *str, char *arg);
int	ft_execute(char **av, int i, int fd_tmp, char **env);

int	main (int ac, char **av, char **env)
{
	/* ----- Creation variable ----- */
	int	i; // -->> Index
	int	fd[2]; // -->> Pour les fork
	int	fd_tmp; // 
	(void) ac;

	/* ----- Initialisation ----- */
	i = 0;
	fd_tmp = dup(STDIN_FILENO);
	/* ----- Start ----- */
	while (av[i] && av[i + 1]) // -->> Pour verifier si on a atteitn la fin
	{
		av = &av[i + 1]; // -->> Passer le nom du programme
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|")) // -->> vérifier le nombre d'arguments entre les "|" & ";"
			i++;
		if (strcmp(av[i] , "cd") == 0) // -->> Si cd existe
		{
			if (i != 2) // -->> Si cd a bien un arguments sinon...
				ft_putstr_fd2("error: cd: bad arguments\n, NULL"); // -->> Error
			else if (chmod(av[1]) != 0) // -->> Test si on peut bien changer de dossier sinon...
				ft_putstr_fd2("error: cd: cannot change directory to \n", av[1]); // -->> Error
		}
		else if (i = 0 && (av[i] == NULL || strcmp(av[i], ";") == 0)) // -->> execve in stdout si ";"
		{
			if (fork() == 0) // -->> Si fork se lance correctement...
			{
				if (ft_execut(av, i, fd_tmp, env)) // -->> Lancer l'execution... Et si elle echoue...
					return (1); // -->> quitter. 
			}
			else // -->> Sinon...
			{
				close(fd_tmp); // -->> Fermer le fd temp...
				while (waitpid(-1, NULL, WUNTRACED) != -1); // -->> Attendre la fin des enfants...
				fd_tmp = dup(STDIN_FILENO); // -->> Et recopier le stdin dans le fd temp.
			}
		} 
		else if (i = 0 &&  strcmp(av[i], "|") == 0) // -->> execve in stdout si "|"
		{
			pipe(fd); // -->> creer les pipes...
			if (fork() == 0) // -->> controler si le fork se lance...
			{
				dup2(fd[1], STDOUT_FILENO);  // -->> Dupliquer le stdin dans fd[1]
				close(fd[0]); // -->> Fermer la sortie
				close(fd[1]); // -->> Fermer l'entrée
				if (ft_execute(av, i, fd_tmp, env)) // -->> Lancer l'execution... Et si elle echoue...
					return ; // -->> quitter
			}
			else // -->> Si le fork ne se lance pas...
			{
				close(fd[1]); // -->> fermer l'entrée
				close(fd_tmp); // -->> fermer le fd temp
				fd_tmp = fd[0]; // -->> le fd temp devient la sortie
			}
		}
	}
	close(fd_tmp); // -->> fermer le fd temp
	return (1); // -->> Fin du programme
}

int	ft_putstr_fd2(char *str, char *arg) // -->> Fonction d'erreur
{
	while (*str)  // -->> Afficher la str avec write
		write (2, str++, 1);
	if (arg) // -->> Si arg existe, l'afficher
		while (*arg)
			write (2, arg++, 1);
	write (2, "\n", 1); // -->> Retour a la ligne
	return (1);
}

int	ft_execute(char **av, int i, int fd_tmp, char **env) // -->> Fonction d'execution
{
	av[i] = NULL; // -->> Mettre le ";", le "|" ou le NULL a NULL
	dup2(fd_tmp, STDIN_FILENO); // -->> fd temp est la nouvelle sortie
	close(fd_tmp); // -->> Fermer le fd temp
	execve(av[0],av, env); // -->> executer le programme
	return (ft_putstr_fd2("Error: cannot execute : ", av[0])); // -->> Message d'erreur si execve ne se lance pas
}