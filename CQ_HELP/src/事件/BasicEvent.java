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
package 事件;

/**
 * 事件基类,主要实现事件拦截返回的功能
 * @author MikuPy2001
 */
public interface BasicEvent {

    /**
     * 不对消息做任何动作/
     * <p>
     * 如果之前拦截了消息,这里将重新放行本条消息,函数结束前有效
     */
    void message_ignore();

    /**
     * 拦截本条消息.
     */
    void message_block();

}
