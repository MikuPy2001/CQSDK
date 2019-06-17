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
package 事件;

import c.string;

/**
 * 悬浮窗事件.
 * @author MikuPy2001
 */
public abstract class StatusEvent {

    //数据
    public string data;
    //数据单位
    public string dataf;
    // 1 : 绿
    // 2 : 橙
    // 3 : 红
    // 4 : 深红
    // 5 : 黑
    // 6 : 灰
    public int color;

    /**
     * 1 : 绿
     */
    public abstract void color_green();

    /**
     * 2 : 橙
     */
    public abstract void color_orange();

    /**
     * 3 : 红
     */
    public abstract void color_red();

    /**
     * 4 : 深红
     */
    public abstract void color_crimson();

    /**
     * 5 : 黑
     */
    public abstract void color_black();

    /**
     * 6 : 灰
     */
    public abstract void color_gray();
}
