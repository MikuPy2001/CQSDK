/*
 * Copyright (C) 2018 qq794
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
package 信息;

import c.string;

/**
 * 群匿名信息
 *
 * @author MikuPy2001
 */
public class AnonymousInfo {

    public long AID = 0;
    /**
     * 匿名者在群里的代号
     */
    public string 代号 = string.VOID;

    /**
     * 传入事件参数fromAnonymousToken即可构造
     *
     * @param fromAnonymousToken
     *
     */
    public AnonymousInfo(string fromAnonymousToken) {
    }
;
}
