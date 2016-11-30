/* `zomboz_demo' is a program for zombie process generation for GNU/Linux
  Copyright (C) 2016 Michael Corvin

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

const short unsigned int number_of_children = 10;

int main(void)
{
	pid_t pids[number_of_children+1];
	int i;

	for (i = number_of_children; i >= 0; --i) {
		pids[i] = fork();
		if (pids[i] == 0) {
		printf("%d: I'm a child. Waiting %d second(s)\n",getpid(),i+1);
			sleep(i+1);
			_exit(0);
		} else {
		printf("%d: For i=%d PID is %d\n",getpid(),i,pids[i]);
		}
	}

	for (i = number_of_children; i >= 0; --i)
		waitpid(pids[i], NULL, 0);

	return 0;
}

/*
 == 1
 >= 2 
 -- 2 
 =  8 
 +  3 
 [] 5

 operands

 number_of_children 4
 pids 5
 i 12
 0 10
 1  3 
 10 1

*/
