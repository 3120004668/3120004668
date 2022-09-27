package org.example;

import com.hankcs.hanlp.tokenizer.StandardTokenizer;
import org.apache.commons.lang3.StringUtils;
import org.jsoup.Jsoup;
import org.jsoup.safety.Whitelist;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class calculate {
    public static double cosThetaRes(String origText, String copyText) {
        origText = clearSpecialCharacters(origText);
        copyText = clearSpecialCharacters(copyText);
        List<String> origTextWords = StandardTokenizer.segment(origText).stream().map(a -> a.word).collect(Collectors.toList());
        List<String> copyTextWords = StandardTokenizer.segment(copyText).stream().map(a -> a.word).collect(Collectors.toList());
        List<String> totalWords = new ArrayList<>();
        totalWords.addAll(origTextWords);
        totalWords.addAll(copyTextWords);
        totalWords = totalWords.stream().distinct().collect(Collectors.toList());
        //总词库去重
        int[] origTextVertex = getVertex(origTextWords, totalWords);
        int[] copyTextVertex = getVertex(copyTextWords, totalWords);
        double cosTheta1 = cosTheta(origTextVertex, copyTextVertex);
        return cosTheta1;
    }

    //计算余弦相似度
    private static double cosTheta(int[] a, int[] b) {
        try {
            return aDotB(a, b) / (absoluteA(a) * absoluteA(b));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }


    // 根据总词组，统计每个词在句子中的出现次数，获取每个句子的词组向量
    private static int[] getVertex(List<String> words, List<String> totalWords) {
        int[] a = new int[totalWords.size()];
        for (int i = 0; i < totalWords.size(); i++) {
            int count = 0;
            for (String word : words) {
                if (totalWords.get(i).equals(word)) {
                    count++;
                }
            }
            a[i] = count;
        }
        return a;
    }

    // 计算向量点乘
    private static double aDotB(int[] a, int[] b) throws Exception {
        if (a.length != b.length) {
            throw new Exception("要求向量维度一致");
        }
        double result = 0;
        for (int i = 0; i < a.length; i++) {
            //过滤超频词
            if (a[i] >= 20 || b[i] >= 20) {
                continue;
            }
            result += a[i] * b[i];
        }
        return result;
    }

    //计算向量的模
    private static double absoluteA(int[] a) {
        double tmp = 0;
        for (int i = 0; i < a.length; i++) {
            //过滤超频词
            if (a[i] >= 20) {
                continue;
            }
            tmp += a[i] * a[i];
        }
        return Math.sqrt(tmp);
    }
    private static String clearSpecialCharacters(String topicName) {

        // 将内容转换为小写
        topicName = StringUtils.lowerCase(topicName);

        // 过滤HTML标签
        topicName = Jsoup.clean(topicName, Whitelist.none());

        // 过滤特殊字符
        String[] strings = {" ", "\n", "\r", "\t", "\\r", "\\n", "\\t", "&nbsp;", "&amp;", "&lt;", "&gt;", "&quot;", "&qpos;"};
        for (String string : strings) {
            topicName = topicName.replaceAll(string, "");
        }

        return topicName;
    }
}
