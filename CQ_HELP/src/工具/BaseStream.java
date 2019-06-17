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
package 工具;

import c.size_t;
import c.string;

/**
 *
 * @author MikuPy2001
 */
public abstract class BaseStream {

    /**
     * 检查当前是否对传入的CQ code进行编码
     *
     * @return 不编码返回真
     */
    public abstract boolean isRAW();

    /**
     * 清空缓存区
     */
    public abstract void clear();

    /**
     * 添加字符串到缓存区
     *
     * @param s 要添加的字符串
     * @return 返回自身以方便链式调用
     */
    public abstract BaseStream append(string s);

    /**
     * 添加bool的字符串版本到缓存区
     *
     * @param i 要添加的bool
     * @return 返回自身以方便链式调用
     */
    public abstract BaseStream append(boolean i);

    /**
     * 添加int的字符串版本到缓存区
     *
     * @param i 要添加的int
     * @return 返回自身以方便链式调用
     */
    public abstract BaseStream append(int i);

    /**
     * 添加size_t的字符串版本到缓存区
     *
     * @param i 要添加的size_t
     * @return 返回自身以方便链式调用
     */
    public abstract BaseStream append(size_t i);

    /**
     * 添加double的字符串版本到缓存区
     *
     * @param i 要添加的double
     * @return 返回自身以方便链式调用
     */
    public abstract BaseStream append(double i);

    /**
     * 添加long的字符串版本到缓存区
     *
     * @param l 要添加的long
     * @return 返回自身以方便链式调用
     */
    public abstract BaseStream append(long l);

    public static interface 控制符 {

        /**
         * 发送并清除缓冲区. BaseStream &lt;&lt; send;
         */
        public static void send() {
        }

        /**
         * 只发送,保留缓冲区,下次发送时将发送重复内容. BaseStream &lt;&lt; flush;
         */
        public static void flush() {
        }

        /**
         * 换行. BaseStream &lt;&lt; endl;
         */
        public static void endl() {
        }

        /**
         * 输出原始字符而不是酷Q码. BaseStream &lt;&lt; RAW;
         */
        public static void RAW() {
        }

        /**
         * 输出酷Q码. BaseStream &lt;&lt; CODE;
         */
        public static void CODE() {
        }
    }

}
