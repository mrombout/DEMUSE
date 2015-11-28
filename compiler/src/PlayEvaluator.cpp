#include <iostream>
#include "PlayEvaluator.h"

namespace dem {
    namespace parser {
        void PlayEvaluator::play(parser::Play &play) {
            play.accept(*this);
        }

        bool PlayEvaluator::visitEnter(parser::Play &play) {
            std::cout << "START - Play" << std::endl;

            return true;
        }

        bool PlayEvaluator::visitLeave(parser::Play &play) {
            std::cout << "LEAVE - Play" << std::endl;

            return true;
        }

        bool PlayEvaluator::visit(parser::Note &note) {


            return true;
        }
    }
}
