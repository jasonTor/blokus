#ifndef USER_INTERFACE_H_INCLUDED
#define USER_INTERFACE_H_INCLUDED

#include <string>

#include "pieces_set.h"

#include "board.h"

class UserInterface
{
public:
	virtual ~UserInterface() = default;
	virtual const Piece* getPiece(const PiecesSet& piecesSet) = 0;
	virtual Coordinate getPosition() = 0;
	virtual Transformation getTransformation(const Piece* piece = nullptr) = 0;
	virtual std::ostream& getMessageOutput() = 0;
	virtual void clearMessages() = 0;
	virtual void displayBoard(const Board& board) = 0;
};

#endif // USER_INTERFACE_H_INCLUDED
