semaphore semaNaviosAEspera = init_sem(0);

//Metodo que devolve um navio usar para criar o navio.
void criarNavio(void){
	alarm(LIFETIME);
	srand(time(NULL));
	for(;;){
		int random=(rand()%61);
		sleep(300+random);
		V(semaNaviosAEspera);
		nmrNaviosAEspera++;
	}	
}

//Metodo para colocar o navio activo
void atracarNavio(void){
	srand(time(NULL));
	P(semaNaviosAEspera);
	nmrNaviosAEspera--;
	Navio navio ={(MAX_SCARGO*0.8+(rand()%(int)(MAX_SCARGO*0.2)+1)), 0};
	ship=&navio;
}

//Metodo que controla as accoes dos navios
void controloNavio{
	alarm(LIFETIME);
	for(;;){
		atracarNavio();
		printf("O navio nº %d atracou.",ship.id);
		descarregarContentorNavio();
		carregarContentorNavio();
		printf("O navio nº %d partiu.",ship.id);
	}
}
