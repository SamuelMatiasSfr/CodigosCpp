#include "bola.hpp"

using std::vector;
using std::string;
using std::stringstream;

namespace lp1{

	class Game {

		sf::RenderWindow window;
		lp1::Bola *bola1;
		vector<lp1::Bola*> bolas;

		static const int LARGURA = 800;
		static const int ALTURA = 600;

	public:
		Game();
		void iniciar();
		void atualizar();
		void desenhar();
		~Game();
	};

}
