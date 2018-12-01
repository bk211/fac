static int * labyParse(void) {
	char buf[1024], * s;
	int *labyrinthe = NULL, w = 0, h = 0, x, y;
	if(fscanf(stdin, "%d\n", &w) != 1 || fscanf(stdin, "%d\n", &h) != 1)
		return NULL;
	/* ... */
	y = 0;
	/* allouer la m´emoire */
	while(fgets(buf, sizeof buf, stdin)) {
		x = 0;
		for(s = buf, x = 0; *s && *s != ’\n’; s++, x++) {
		/* remplir labyrinthe et fixer le point de d´epart et le point
		* d’arriv´ee */
		}
		y++;
	}
	return labyrinthe;
}