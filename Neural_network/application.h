#pragma once
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

class Application {
	private:
		bool running = false;
		std::string command;
		void header();
		void execute(std::string arg);


	public:
		Application();
		void start();
};

#endif
