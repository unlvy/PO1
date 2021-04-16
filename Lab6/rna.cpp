#include "rna.h"

std::ostream& operator<<(std::ostream& out, const RNA & seq_) {
    for (auto& sq : seq_.chain) {
        out << " " << static_cast<char>(sq);
    }
    out << std::endl;
    return out;
}

RNA& RNA::mutate() {
    chain.push_back(chain.front());
    chain.erase(chain.begin());
    return *this;
}
