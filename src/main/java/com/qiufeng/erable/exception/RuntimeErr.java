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

package com.qiufeng.erable.exception;

/**
 * @since 2019年4月15日
 * @author Qiufeng54321
 */
public class RuntimeErr extends BaseException{

    public RuntimeErr(String title, String message) {
	super(ErrorType.RUNTIME, title, message, "", -1, -1, -1);
    }
    @Override
    public void throwException(){
	System.err.println("-------------RUNTIME ERROR-------------");
	System.err.println(title + "  :");
	System.err.println("\t"+this.message);
	System.err.println("-------Erable Runtime Terminated-------");
	System.exit(this.errno);
    }

}
