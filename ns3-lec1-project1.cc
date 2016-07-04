/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/core-module.h"

#include <iostream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("HelloSimulator");

static void printHello(std::string word,std::string num,float freq) {
	std::cout<<Simulator::Now()<<" Hello "<<word<<num<<std::endl;
	Simulator::Schedule(Seconds(freq),&printHello,word,num,freq);
}
// ./test arg0 arg1 arg2
// argc=4
// argv[0] -> "test"
// argv[1] -> "arg0"
// argv[2] -> "arg1"
// argv[3] -> "arg2"
// argv[4] -> NULL
int
main (int argc, char *argv[])
{
	CommandLine cmd;


	std::string name;
	std::string number;
	float frequency;
	cmd.AddValue ("name", "my name", name);
	cmd.AddValue ("number","my number",number);
	cmd.AddValue ("frequency","the frequency",frequency);
	cmd.Parse(argc,argv);

	printHello(name,number,frequency);
	std::cout<<"hello commit"<<std::endl;

	Simulator::Stop(Seconds(8));
	Simulator::Run ();
	Simulator::Destroy ();
}
