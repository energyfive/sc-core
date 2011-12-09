/*
-----------------------------------------------------------------------------
This source file is part of OSTIS (Open Semantic Technology for Intelligent Systems)
For the latest info, see http://www.ostis.net

Copyright (c) 2011 OSTIS

OSTIS is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OSTIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OSTIS.  If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
 */

#include "precompiled_p.h"

namespace scp
{
const char* keynodes_uris[] = {
	"/proc/scp/keynode/processStack_",
};

sc_segment *keynodes_segment;

const int keynodes_count = sizeof(keynodes_uris) / sizeof(const char*);

sc_addr keynodes[keynodes_count];

const sc_addr &processStack_ = keynodes[0];
}
