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
/** @file AmRtpReceiver.h */
#ifndef _AmRtpReceiver_h_
#define _AmRtpReceiver_h_

#include "AmThread.h"
#include "atomic_types.h"
#include "singleton.h"

#include <sys/select.h>

#include <map>
using std::greater;

class AmRtpStream;
class _AmRtpReceiver;

/**
 * \brief receiver for RTP for all streams.
 *
 * The RtpReceiver receives RTP packets for all streams 
 * that are registered to it. It places the received packets in 
 * the stream's buffer. 
 */
class AmRtpReceiverThread: public AmThread {

  struct StreamInfo {
    unsigned int index; // index into fds table
    AmRtpStream* stream;

    StreamInfo(unsigned int i, AmRtpStream* s)
      : index(i), stream(s) {}
  };

  typedef std::map<int, StreamInfo, greater<int> > Streams;

  Streams  streams;
  AmMutex  streams_mut;

  struct pollfd* fds;
  unsigned int   nfds;
    
  AmRtpReceiverThread();
  ~AmRtpReceiverThread();
    
  void run();
  void on_stop();
  AmSharedVar<bool> stop_requested;

  void addStream(int sd, AmRtpStream* stream);
  void removeStream(int sd);

  void stop_and_wait();

  friend class _AmRtpReceiver;
};

class _AmRtpReceiver
{
  // static AmRtpReceiver* _instance;

  AmRtpReceiverThread* receivers;
  unsigned int         n_receivers;

  atomic_int next_index;

protected:    
  _AmRtpReceiver();
  ~_AmRtpReceiver();

  void dispose();

public:
  // static AmRtpReceiver* instance();
  // static bool haveInstance();
  // static void dispose();

  void start();

  void addStream(int sd, AmRtpStream* stream);
  void removeStream(int sd);
};

typedef singleton<_AmRtpReceiver> AmRtpReceiver;

#endif

// Local Variables:
// mode:C++
// End:
