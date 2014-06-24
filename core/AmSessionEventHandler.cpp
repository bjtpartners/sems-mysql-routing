/*
 * Copyright (C) 2002-2003 Fhg Fokus
 *
 * This file is part of SEMS, a free SIP media server.
 *
 * SEMS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version. This program is released under
 * the GPL with the additional exemption that compiling, linking,
 * and/or using OpenSSL is allowed.
 *
 * For a license to use the SEMS software under conditions
 * other than those described here, or to purchase support for this
 * software, please contact iptel.org by e-mail at the following addresses:
 *    info@iptel.org
 *
 * SEMS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "AmSessionEventHandler.h"

// AmSessionEventHandler methods
int AmSessionEventHandler::configure(AmConfigReader& conf)
{
  return 0;
}

bool AmSessionEventHandler::process(AmEvent*)
{
  return false;
}

bool AmSessionEventHandler::onSipRequest(const AmSipRequest&)
{
  return false;
}

bool AmSessionEventHandler::onSipReply(const AmSipReply& reply, AmSipDialog::Status old_dlg_status)
{
  return false;
}

bool AmSessionEventHandler::onSipReqTimeout(const AmSipRequest &)
{
  return false;
}

bool AmSessionEventHandler::onSipRplTimeout(const AmSipRequest &, 
    const AmSipReply &)
{
  return false;
}

bool AmSessionEventHandler::onSendRequest(AmSipRequest& req, int flags)
{
  return false;
}

bool AmSessionEventHandler::onSendReply(AmSipReply& reply, int flags)
{
  return false;
}
