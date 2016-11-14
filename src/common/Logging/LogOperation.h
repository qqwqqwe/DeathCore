/*
 * Copyright (C) 2016 DeathCore <http://www.noffearrdeathproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOGOPERATION_H
#define LOGOPERATION_H

#include <memory>
#include "Define.h"

class Logger;
struct LogMessage;

class TC_COMMON_API LogOperation
{
    public:
        LogOperation(Logger const* _logger, std::unique_ptr<LogMessage>&& _msg)
            : logger(_logger), msg(std::forward<std::unique_ptr<LogMessage>>(_msg))
        { }

        ~LogOperation() { }

        int call();

    protected:
        Logger const* logger;
        std::unique_ptr<LogMessage> msg;
};

#endif