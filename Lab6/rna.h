#pragma once

// *** DO NOT MODIFY THIS FILE ***

#include <vector>
#include <ostream>


//-------------------------------------------------------------
enum Nukleotyp { 
	A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
};


//-------------------------------------------------------------
class RNA {

	friend std::ostream& operator<<(std::ostream& out, const RNA & seq_);

 public:	

	std::vector< Nukleotyp > get_RNA() const { return chain; }

	RNA( const std::vector< Nukleotyp > seq_ ): chain(seq_) { }
	
	RNA & mutate ();

 protected:
	
	std::vector< Nukleotyp > chain;

};
