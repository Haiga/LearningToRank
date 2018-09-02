#include "stdafx.h"
#include "iostream"
#include "blocoDuplo.h"

bool blocoDuplo::isNull(blocoDuplo* blocoAvaliado)
{
	if (blocoAvaliado->dado == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}

bool blocoDuplo::proxIsNull(blocoDuplo*  blocoAvaliado)
{
	if (blocoAvaliado->proximo == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}

bool blocoDuplo::antIsNull(blocoDuplo*  blocoAvaliado)
{
	if (blocoAvaliado->anterior == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}
