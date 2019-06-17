/*
 * Copyright (C) 2018 admin
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
 * 陌生人信息
 *
 * @author MikuPy2001
 */
public abstract class StrangerInfo {

    public long QQID;
    /**
     * 昵称
     */
    public string nick;//昵称
    /**
     * 0/男性 1/女性 255/未知
     */
    public int sex;//0/男性 1/女性 255/未知
    /**
     * 年龄
     */
    public int age;//年龄

    /**
     * 可视化
     *
     * @return 返回本对象的可读格式
     */
    @Override
    public String toString() {
        return super.toString();
    }
}
