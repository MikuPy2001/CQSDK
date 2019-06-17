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

/**
 * 讨论组事件
 * @author MikuPy2001
 */
public abstract class DiscussMsgEvent extends MsgEvent {

    /**
     * 讨论组号
     */
    public long fromDiscuss;//讨论组号

    /**
     * 退出讨论组
     *
     * @return
     */
    abstract public boolean leave();
}
