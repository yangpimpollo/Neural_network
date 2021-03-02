#include <iostream>
#include <string.h>
#include "application.h"

using namespace std;


	Application::Application() {

	}

	void Application::start() {
		running = true;
		header(); 

		while(running) {
			cout << "\n\n\n              </> "; 
			cin >> command; 
			execute(command);
		}
	}

	void Application::execute(string arg) {
		if(arg=="run") {
			cout << "                  run ";
		}else if(arg == "train") {
			cout << "                  train ";
		}else if(arg == "save") {
			cout << "                  save ";
		}else if (arg == "load") { 
			cout << "                  load ";
		}
		else{
			cout << "                  error 1008:  \"" <<arg<<"\" is not a command";
		}
	}

	void Application::header(){
		cout << "\n                                                                            by Bubble-Group    2021.02.26               ";
		cout << "\n          ----------------------------------------------------------------------------------------------------          ";
		cout << "\n                                                                                                                        ";
		cout << "\n                                                                                                                        ";
		cout << "\n                                                                                                                        ";
		cout << "\n                 uniuni  iuniu    uniuni    niuni     uniuni                                                            ";
		cout << "\n                 niuniu  uniun    niuniun   iuniu     niuniu                                                            ";
		cout << "\n                 iuniun  niuni    iuniuniu  uniun     iuniun                                                            ";
		cout << "\n                 uniuni  iuniu    uniuniuni niuni     uniuni                  FACULTAD DE INGENIERIA                    ";
		cout << "\n                 niuniu  uniun    niuniuniu iuniu     niuniu         ECONOMICA ESTADISTICA Y CIENCIAS SOCIALES          ";
		cout << "\n                 iuniun  niuni    iuniuniuniuniun     iuniun                                                            ";
		cout << "\n                 uniuni  iuniu    uniuniuniuniuni     uniuni                                                            ";
		cout << "\n                 niuniu  uniun    niuniu iuniuniu     niuniu                                                            ";
		cout << "\n                 iuniun  niuni    iuniun uniuniun     iuniun           DESARROLLO DE REDES NEURONALES EN C++            ";
		cout << "\n                 uniuni  iuniu    uniuni  iuniuni     uniuni                                                            ";
		cout << "\n                 niuniuniuniun    niuniu   niuniu     niuniu                                                            ";
		cout << "\n                   niuniuniu      iuniun    uniun     iuniun                                                            ";
		cout << "\n                                                                                                                        ";
		cout << "\n                                                                                                                        ";
		cout << "\n                                                                                                                        ";
		cout << "\n          ----------------------------------------------------------------------------------------------------          ";
	}

