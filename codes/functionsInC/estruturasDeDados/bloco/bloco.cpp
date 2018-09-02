#include "stdafx.h"
#include "iostream"
#include "bloco.h"

bool bloco::isNull(bloco* blocoAvaliado) {
	if (blocoAvaliado->dado == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}

bool bloco::proxIsNull(bloco* blocoAvaliado) {
	if (blocoAvaliado->proximo == NULL) {
		return true;
	}
	else
	{
		return false;
	}
 }