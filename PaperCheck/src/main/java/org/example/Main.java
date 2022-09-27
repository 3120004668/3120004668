package org.example;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * 分词处理测试
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入原文目录地址：");
        String origAddress = in.nextLine();
        System.out.print("请输入抄袭版目录地址：");
        String copyAddress = in.nextLine();
        String origText = readFile(origAddress);
        String copyText = readFile(copyAddress);
        System.out.printf("相似度：%.2f", calculate.cosThetaRes(origText, copyText));
        String text = "相似度：" + String.format("%.2f", calculate.cosThetaRes(origText, copyText));
        saveFile(text);
    }

    //读取文件
    private static String readFile(String address) {
        Path path = Paths.get(address);
        Stream<String> lines = null;
        try {
            lines = Files.lines(path);
        } catch (
                IOException e) {
            e.printStackTrace();
        }
        return lines.collect(Collectors.joining(System.lineSeparator()));
    }

    //保存文件
    private static void saveFile(String text) {
        File file;
        FileOutputStream stream = null;
        try {
            file = new File("ans.txt");
            stream = new FileOutputStream(file);
            if (!file.exists()) {
                file.createNewFile();
            }
            byte[] contentInBytes = text.getBytes();
            stream.write(contentInBytes); // 写入
            stream.flush();
            stream.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
