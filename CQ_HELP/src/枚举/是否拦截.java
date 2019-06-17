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
package 枚举;

/**
 * 用于普通事件返回,EX版事件请查阅
 * @author MikuPy2001
 */
public enum 是否拦截 {
    /**
     * 拦截此条消息，不再传递给其他应用. 
     * <p>
     * 注意：应用优先级设置为最高(10000)时，不得使用本返回值.
     * <p>
     * 本枚举值为:1
     */
    消息_拦截,
    /**
     * 将此消息继续传递给其他应用. 既为忽略本条消息.
     * <p>
     * 本枚举值为:0
     */
    消息_忽略
}
