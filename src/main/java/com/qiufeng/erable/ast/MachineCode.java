/*
 * Copyright (C) 2019 Qiufeng54321
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package com.qiufeng.erable.ast;

import com.qiufeng.erable.OpCode;
import com.qiufeng.erable.util.BitUtils;
import java.io.IOException;

/**
 *
 * @author Qiufeng54321
 */
public class MachineCode extends Code {
    public int refid;
    public MachineCode(OpCode op,int refid,Code parent) {
	super("",op,parent);
	this.tag=this.id+"";
	this.sign=Code.FLAG;
	this.refid=refid;
    }
    /**
     * [OP 1B] [TARGET ID 4B]?
     * @throws IOException 
     */
    @Override
    public void write() throws IOException {
	this.writeOpCode(this.op);
	System.out.println("__FLAG "+this);
	if(this.refid!=-1){
	    this.writeId(this.refid);
	}
    }

    @Override
    public String toString() {
	return super.toString() + "  Flag " + this.op + " " + (this.refid==-1?"":this.refid);
    }
    
}
